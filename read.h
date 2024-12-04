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
