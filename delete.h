/*
 * File: delete.h
 * Description: Header file for deletion operations in the address book program.
 *              Provides declarations for functions related to deleting records.
*/

#ifndef DELETE_H
#define DELETE_H

#include "read.h"  // Ensure that read.h is included for required data structures

int delete_data(add_book *addbook, read_info *read, int option);

#endif

