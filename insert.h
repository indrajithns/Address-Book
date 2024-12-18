/*
 * File: insert.h
 * Description: Header file for inserting new entries into the address book.
 *              Declares the function for inserting data into the address book file.
*/

#ifndef INSERT_H
#define INSERT_H

#include "read.h"  // Ensure that read.h is included

int insert_data_to_addbook(add_book *addbook, read_info *read, int option);

#endif
