//  Macro.h
//
//  Created by : Stunkz ( https://github.com/Stunkz )
//

#ifndef WHISPERCHAT_MACRO_H
#define WHISPERCHAT_MACRO_H

#include <stdio.h>
#include <time.h>
#include <windows.h>

/*-------------------------[                  DE LA MERDE                  ]-------------------------*/
#define okay(msg, ...) do { \
    SetConsoleOutputCP(65001); \
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); \
    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN); \
    printf("[+] " msg "\n", ##__VA_ARGS__); \
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN); \
} while (0)

#define info(msg, ...) do { \
    SetConsoleOutputCP(65001); \
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); \
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY); \
    printf("[*] " msg "\n", ##__VA_ARGS__); \
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN); \
} while (0)

#define warn(msg, ...) do { \
    SetConsoleOutputCP(65001); \
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); \
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY); \
    printf("[-] " msg "\n", ##__VA_ARGS__); \
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN); \
} while (0)

#define error(msg, ...) do { \
    SetConsoleOutputCP(65001); \
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); \
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY); \
    printf("[-] " msg "\n", ##__VA_ARGS__); \
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN); \
} while (0)

#define space() printf("\n")

#endif //WHISPERCHAT_MACRO_H
