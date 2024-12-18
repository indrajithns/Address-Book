/*
 * File: read.h
 * Description: 
 *      This header file defines structures and function prototypes for reading and managing 
 *      the address book data. The `add_book` structure is used to store individual contact 
 *      information (name, email, phone, city). The `read_info` structure is used to handle 
 *      operations such as insertion, editing, searching, and deletion of contacts. 
 *      This file also includes the `read_information` function prototype, which handles 
 *      reading user input for various operations (insert, edit, search, delete).
*/

#ifndef READ_H
#define READ_H

#define DATA_SIZE 25

/* Structure to store information in the address book */
typedef struct _Addressbook {
    char *name;
    char *email;
    char *phone;
    char *city;
} add_book;

/* Structure to read information to perform operations */
typedef struct _ReadInfo {
    FILE *fptr;
    char *fname;
    int option;
    char *edata;
    char *newdata;
    int array_pos;
} read_info;

int read_information(add_book *addbook, read_info *read, int option);

#endif
