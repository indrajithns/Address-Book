/*
 * File: edit.h
 * Description: Header file for editing operations in the address book application.
 *              Declares the primary function for editing address book entries.
*/

#ifndef EDIT_H
#define EDIT_H

#include "read.h"  // Ensure that read.h is included

int edit_data(add_book *addbook, read_info *read, int option);

#endif
