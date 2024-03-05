//  Encryption.c
//
//  Created by : Stunkz ( https://github.com/Stunkz )
//

#include "Encryption.h"

EVP_PKEY * publicKey;
EVP_PKEY * privateKey;

EVP_PKEY * loadPublicKey(const char * publicKeyStr) {
    EVP_PKEY * rsa = NULL;
    BIO * keyBio = BIO_new_mem_buf(publicKeyStr, -1);

    if ( keyBio == NULL ) {
        unsigned long error = ERR_get_error();
        error("Failed to create BIO, error: %ld", error);
        return NULL;
    }

    rsa = PEM_read_bio_PUBKEY(keyBio, NULL, NULL, NULL);

    if ( rsa == NULL ) {
        unsigned long error = ERR_get_error();
        error("Failed to get RSA Key, error: %ld", error);
        return NULL;
    }

    BIO_free(keyBio);
    return rsa;
}

EVP_PKEY * loadPrivateKey(const char * privateKeyStr) {
    EVP_PKEY * rsa = NULL;
    BIO * keyBio = BIO_new_mem_buf(privateKeyStr, -1);

    if ( keyBio == NULL ) {
        unsigned long error = ERR_get_error();
        error("Failed to create BIO, error: %ld", error);
        return NULL;
    }

    rsa = PEM_read_bio_PrivateKey(keyBio, NULL, NULL, NULL);

    if ( rsa == NULL ) {
        unsigned long error = ERR_get_error();
        error("Failed to get RSA Key, error: %ld", error);
        return NULL;
    }

    BIO_free(keyBio);
    return rsa;
}

void loadRsaKeys(const char * publicKeyChar, const char * privateKeyChar) {
    publicKey = loadPublicKey(publicKeyChar);
    privateKey = loadPrivateKey(privateKeyChar);
    if ( publicKey == NULL || privateKey == NULL ) {
        error("Failed to load RSA keys !");
        raise(SIGABRT);
    }
    okay("Loaded RSA keys successfully !");
}


size_t rsaEncrypt(unsigned char * messageToEncrypt, unsigned char * encryptedMessage, int len) {

    EVP_PKEY_CTX * ctx = EVP_PKEY_CTX_new(publicKey, NULL);

    if ( ctx == NULL || EVP_PKEY_encrypt_init(ctx) <= 0 ) {
        unsigned long error = ERR_get_error();
        warn("Failed to initialize encryption, error: %ld", error);
        return 0;
    }

    size_t encryptedLength;
    EVP_PKEY_encrypt(ctx, encryptedMessage, &encryptedLength, messageToEncrypt, len);

    if ( encryptedLength == -1 ) {
        unsigned long error = ERR_get_error();
        warn("Failed to encrypt data, error: %ld", error);
        return 0;
    }

    EVP_PKEY_CTX_free(ctx);
    return encryptedLength;
}

size_t rsaDecrypt(unsigned char * messageToDecrypt, unsigned char * decryptedMessage, int len) {

    EVP_PKEY_CTX * ctx = EVP_PKEY_CTX_new(privateKey, NULL);

    if ( ctx == NULL || EVP_PKEY_decrypt_init(ctx) <= 0 ) {
        unsigned long error = ERR_get_error();
        warn("Failed to initialize decryption, error: %ld", error);
        return 0;
    }

    size_t decryptedLength;
    EVP_PKEY_decrypt(ctx, decryptedMessage, &decryptedLength, messageToDecrypt, len);

    if ( decryptedLength == -1 ) {
        unsigned long error = ERR_get_error();
        warn("Failed to decrypt data, error: %ld", error);
        return 0;
    }

    EVP_PKEY_CTX_free(ctx);
    return decryptedLength;
}
