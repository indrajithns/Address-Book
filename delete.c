#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "delete.h"
#include "read.h"  // For read_information

// Read data to delete
void read_delete_data (add_book *array, read_info *read, int *count)
{
	int bytes, index;
	char buff[32], temp[2];

	// Store the file contents in an array
	for (index = 0; feof(read->fptr) == 0; index++)
	{
		(*count)++;

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
	
	// Close the file
	fclose(read->fptr);
}

// Skip array index
int skip_array_index(add_book *array, read_info *read, int count)
{
	int index;
	char delimeter[5] = "//";
	char newline = '\n';
	
	// Open the file in write mode
	read->fptr = fopen(read->fname, "w");

	if (read->fptr == NULL)
	{
		perror("fopen");
		fprintf(stderr, "ERROR: Unable To Open The File %s\n", read->fname);

		return 1;
	}

	for (index = 0; index < (count - 1); index++)
	{
		// If the edata matches with array name skip that array index 
		if (strcmp(read->edata, array[index].name) == 0)
			continue;

		// Write the contents from array back to the file
		// Write name
		fwrite(array[index].name, 1, 32, read->fptr);
		fwrite(delimeter, 1, 2, read->fptr);
	
		// Write email
		fwrite(array[index].email, 1, 32, read->fptr);
		fwrite(delimeter, 1, 2, read->fptr);

		// Write phone
		fwrite(array[index].phone, 1, 32, read->fptr);
		fwrite(delimeter, 1, 2, read->fptr);

		// Write city
		fwrite(array[index].city, 1, 32, read->fptr);
		fwrite(&newline, 1, 1, read->fptr);
	}

	// Close the file
	fclose(read->fptr);
}

// Delete information from the address book
int delete_data(add_book *addbook, read_info *read, int option)
{
	add_book array[DATA_SIZE];
	int count = 0;

	// Read data from the user
	if (read_information(addbook, read, option) < 0)
		return -1;

	// Open the file in read mode
	read->fptr = fopen(read->fname, "r");

	if (read->fptr == NULL)
	{
		perror("fopen");
		fprintf(stderr, "ERROR: Unable To Open The File %s\n", read->fname);

		return 1;
	}

	// Read data to delete
	read_delete_data(array, read, &count);

	// Delete the data
	skip_array_index(array, read, count);
}

