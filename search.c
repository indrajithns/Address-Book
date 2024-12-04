#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "search.h"
#include "read.h"  // For read_information


// Search by name
int search_by_name(add_book *array, read_info *read, int count)
{
	int index, flag = 1;

	for (index = 0; index < count; index++)
	{
		// Compare the array name with the name you are searching
		if (strcmp(array[index].name, read->newdata) == 0)
		{
			// If found reset the flag and return index
			flag = 0;
			return index;
		}
	}

	// If not found
	if (flag)
		return -1;
}

// Search by email
int search_by_email(add_book *array, read_info *read, int count)
{
	int index, flag = 1;

	for (index = 0; index < count; index++)
	{
		// Compare the array email with the email you are searching
		if (strcmp(array[index].email, read->newdata) == 0)
		{
			// If found reset the flag and return index
			flag = 0;
			return index;
		}
	}

	// If not found
	if (flag)
		return -1;
}

// Search by phone number
int search_by_phone(add_book *array, read_info *read, int count)
{
	int index, flag = 1;

	for (index = 0; index < count; index++)
	{
		// Compare the array email with the email you are searching
		if (strcmp(array[index].phone, read->newdata) == 0)
		{
			// If found reset the flag and return index
			flag = 0;
			return index;
		}
	}

	// If not found
	if (flag)
		return -1;
}

// Search by city
int search_by_city(add_book *array, read_info *read, int count, int *index_array, int *j_index)
{
	int index, flag = 1;
	
	for (index = 0; index < count; index++)
	{

		// Compare the array email with the email you are searching
		if (strcmp(array[index].city, read->newdata) == 0)
		{
			// If found reset the flag 
			flag = 0;
			
			// Store the index values in an array 
			index_array[(*j_index)] = index;
			(*j_index)++;
		}
	}

	// If not found
	if (flag)
		return -1;
}

// Print the serached data
void print_search_data(add_book *array, int index)
{
	printf("\n********************************************************\n");
	printf("Name  : %s\n", array[index].name);
	printf("Email : %s\n", array[index].email);
	printf("Phone : %s\n", array[index].phone);
	printf("City  : %s\n", array[index].city);
	printf("********************************************************\n\n");
}

// Search the data from the address book
int search_data(add_book *array,read_info *read, int count)
{
	int j_index, index[20], kdx, i_count = 0;

	switch (read->option)
	{
		case 1:
	
			// Searching by name 
			j_index = search_by_name(array, read, count);

			// If name not found
			if (j_index < 0)
			{
				printf("Name Not Found\n");
				return -1;
			}
			
			// Print the data
			print_search_data(array, j_index);
			break;

		case 2:

			// Searching by email
			j_index = search_by_email(array, read, count);

			// If email is not found
			if (j_index < 0)
			{
				printf("Email Not Found\n");
				return -1;
			}
			
			// Print the data related to the email
			print_search_data(array, j_index);
			break;

		case 3:

			// Searching by phone number
			j_index = search_by_phone(array, read, count);

			// If number is not found
			if (j_index < 0)
			{
				printf("Phone Number Not Found\n");
				return -1;
			}
		
			// Print the data relating to the phone number
			print_search_data(array, j_index);
			break;

		case 4:

			// Searching by city
			j_index	= search_by_city(array, read, count, index, &i_count);

			// If city is not found
			if (j_index < 0)
			{
				printf("City Not Found\n");
				return -1;
			}
	
			// Print all the data relating to the city
			for (kdx = 0; kdx < i_count; kdx++)
			{
				print_search_data(array, index[kdx]);

			}

			break;
	}
}

// Read the data to be searched
int read_search_data(read_info *read, add_book *addbook, int option)
{
	int bytes, index, count = 0;
	char buff[32], temp[2];
 	add_book array[DATA_SIZE];

	// Read the information from the user
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

	// Store the file contents in array
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

	// Search by option
	search_data(array, read, (count - 1));	

	// Close the file
	fclose(read->fptr);
}
