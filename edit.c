#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "edit.h"
#include "read.h"  // For read_information


// Read data to edit 
int read_edit_data (add_book *array, read_info *read)
{
	int bytes, index, count = 0;
	char buff[32], temp[2];

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

	// Set the file pointer to initial position
	fseek(read->fptr, 0L, SEEK_SET);
}

// Get the position of the content in the file
void get_array_position(add_book *array, read_info *read)
{
	int index;
	
	for (index = 0; index < DATA_SIZE; index++)
	{
		// Compare the entered name with the name in the array
		if (strcmp(read->edata, array[index].name) == 0)
			break;
		
	}

	// Store the index value
	read->array_pos = index;
}

// Write the new data back to the file
void write_edit_data(add_book *array, read_info *read)
{
	long position;
	char delimeter[5] = "//"; 
	char newline = '\n';

	// Get the position
	get_array_position(array, read);

	switch (read->option)
	{
		case 1:

			// Write the new name to the file
			position = (read->array_pos * 134) + read->array_pos;
			fseek(read->fptr, position, SEEK_SET);
			fwrite(read->newdata, 1, 32, read->fptr);
			break;

		case 2:
			
			// Write the new email to the file
			position = (read->array_pos * 134) + 32 + read->array_pos;
			fseek(read->fptr, position, SEEK_SET);
			fwrite(delimeter, 1, 2, read->fptr);
			fwrite(read->newdata, 1, 32, read->fptr);
			break;

		case 3:

			// Write the new phone number to the file
			position = (read->array_pos * 134) + 66 + read->array_pos;
			fseek(read->fptr, position, SEEK_SET);
			fwrite(delimeter, 1, 2, read->fptr);
			fwrite(read->newdata, 1, 32, read->fptr);
			break;

		case 4:

			// Write the new city to the file
			position = (read->array_pos * 134) + 100 + read->array_pos;
			fseek(read->fptr, position, SEEK_SET);
			fwrite(delimeter, 1, 2, read->fptr);
			fwrite(read->newdata, 1, 32, read->fptr);
			fwrite(&newline, 1, 1, read->fptr);
			break;
	}
}

// Edit he contents from address book
int edit_data(add_book *addbook, read_info *read, int option)
{
	add_book array[DATA_SIZE];

	// Read name from the user
	if (read_information(addbook, read, option) < 0)
		return -1;
	
	// Open the file in read and write mode
	read->fptr = fopen(read->fname, "r+");

	if (read->fptr == NULL)
	{
		perror("fopen");
		fprintf(stderr, "ERROR: Unable To Open The File %s\n", read->fname);

		return 1;
	}

	// Read the new data
	read_edit_data(array, read);
	
	// Write the new data
	write_edit_data(array, read);

	// Close the file
	fclose(read->fptr);

}
