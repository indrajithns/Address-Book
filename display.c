/*
 * File: display.c
 * Description: Provides functions to display the contents of an address book. 
 *              Reads data from a file, stores it in an array, and prints it in a 
 *              formatted manner.
 * Functions:
 *   - print_add_book: Prints the formatted details of all address book entries.
 *   - display_add_book: Reads address book data from a file and displays it.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read.h"


// Print data function
void print_add_book(add_book *array, int count)
{
	int index;
	
	printf("\n**********************************************************\n");
	for (index = 0; index < count; index++)
	{
		printf("Name  : %s\n", array[index].name);
		printf("Email : %s\n", array[index].email);
		printf("Phone : %s\n", array[index].phone);
		printf("City  : %s\n", array[index].city);
		printf("**********************************************************\n\n");
	}
}

// Display address book function
int display_add_book(read_info *read)
{
	int bytes, index, count = 0;
	char buff[32], temp[2];
 	add_book array[DATA_SIZE];

	// Open the file in read mode
	read->fptr = fopen(read->fname, "r");

	if (read->fptr == NULL)
	{
		perror("fopen");
		fprintf(stderr, "ERROR: Unable To Open The File %s\n", read->fname);

		return 1;

	}

	// Store the file content in array
	for (index = 0; feof(read->fptr) == 0; index++)
	{
		count++;

		// Store name
		fread(buff, 1, 32, read->fptr);
		array[index].name = malloc(strlen(buff));
		strcpy(array[index].name, buff);

		// Store email
		fread(temp, 1, 2, read->fptr);
		fread(buff, 1, 32, read->fptr);
		array[index].email = malloc(strlen(buff));
		strcpy(array[index].email, buff);

		// Store phone
		fread(temp, 1, 2, read->fptr);
		fread(buff, 1, 32, read->fptr);
		array[index].phone = malloc(strlen(buff));
		strcpy(array[index].phone, buff);

		// Store city
		fread(temp, 1, 2, read->fptr);
		fread(buff, 1, 32, read->fptr);
		array[index].city = malloc(strlen(buff));
		strcpy(array[index].city, buff);
		fread(temp, 1, 1, read->fptr);
	}
	
	// Print the array content
	print_add_book(array, count - 1);

	// Close the file
	fclose(read->fptr);
}
