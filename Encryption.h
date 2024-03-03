//  Encryption.h
//
//  Created by : Stunkz ( https://github.com/Stunkz )
//

#ifndef WHISPERCHAT_ENCRYPTION_H
#define WHISPERCHAT_ENCRYPTION_H

#include "Macro.h"
#include <stdio.h>
#include <signal.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/aes.h>

/**
 * The public key.
 */
extern EVP_PKEY * publicKey;
/**
 * The private key.
 */
extern EVP_PKEY * privateKey;


/**
 * Load a public key from a string.
 *
 * @param publicKey : A string representation of the public key.
 * @return An EVP_PKEY structure representing the public key, or NULL if an error occurred.
 */
EVP_PKEY * loadPublicKey(const char * publicKey);


/**
 * Load a private key from a string.
 *
 * @param privateKey : A string representation of the private key.
 * @return An EVP_PKEY structure representing the private key, or NULL if an error occurred.
 */
EVP_PKEY * loadPrivateKey(const char * privateKey);


/**
 * Load the RSA keys from strings.
 *
 * @param publicKeyChar : A string representation of the public key.
 * @param privateKeyChar : A string representation of the private key.
 */
void loadRsaKeys(const char * publicKeyChar, const char * privateKeyChar);


/**
 * Encrypt a message using the RSA public key.
 *
 * @param messageToEncrypt : The message to encrypt.
 * @param encryptedMessage : The buffer to store the encrypted message.
 * @param len : The length of the message to encrypt.
 * @return The length of the encrypted message.
 */
size_t rsaEncrypt(unsigned char * messageToEncrypt, unsigned char * encryptedMessage, int len);


/**
 * Decrypt a message using the RSA private key.
 *
 * @param messageToDecrypt : The message to decrypt.
 * @param decryptedMessage : The buffer to store the decrypted message.
 * @param len : The length of the message to decrypt.
 * @return The length of the decrypted message.
 */
size_t rsaDecrypt(unsigned char * messageToDecrypt, unsigned char * decryptedMessage, int len);

#endif //WHISPERCHAT_ENCRYPTION_H
