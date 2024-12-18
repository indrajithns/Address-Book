/*
 * File: read.c
 * Description: Provides functions to read and process user input for managing 
 *              address book entries. Includes functionality to insert, edit, 
 *              search, and delete contact information. Also includes helper 
 *              functions for formatting and validating data.
 * Functions:
 *   - add_space: Adds spaces to a string to ensure it is 32 characters long.
 *   - read_by: Reads data based on a selected field (name, email, phone, city) 
 *              and prepares it for further operations like editing or searching.
 *   - read_information: Reads the user's input for different operations (insert, 
 *                        edit, search, delete) and stores it in appropriate 
 *                        structures.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

// Add space function 
void add_space(char *string)
{
	int index;

	for (index = strlen(string); index < 32; index++)
		string[index] = ' ';

	string[index] = '\0';

}

// Read the content by options for serching and editing
int read_by(add_book *addbook, read_info *read)
{
	int index, size;
	char buff[50];
	
	// Read the option and store it
	printf("1. Name\n2. Email\n3. Phone\n4. City\nEnter the option: ");
	scanf("%d", &read->option);

	switch (read->option)
	{

		case 1:

			// Store the name in a buffer
			printf("Enter The Name: ");
			scanf("\n%[^\n]", buff);

			// Adding spaces after the name
			add_space(buff);
			size = strlen(buff + 1);
		
			// Allocating memory for the name
			read->newdata = malloc(sizeof(char *) * size);

			// Copy the  buff content to newdata
			strcpy(read->newdata, buff);
			break;

		case 2:

			// Store the email in a buffer
			printf("Enter The Email Id: ");
			scanf("%s", buff);

			// Adding spaces after the email
			add_space(buff);
			size = strlen(buff + 1);

			// Allocating memory for the email
			read->newdata = malloc(sizeof(char *) * size);

			// Copy the  buff content to newdata
			strcpy(read->newdata, buff);
			break;

		case 3:
			
			// Store the phone number in a buffer
			printf("Enter The Mobile Number: ");
			scanf("%s", buff);
			
			// Check for number of digits
			if ((strlen(buff)) != 10)
			{
				printf("Invalid Mobile Number\n");
				return -1;
			}

			else
			{
				index = 0;
				while (buff[index] >= '0' && buff[index] <= '9')
					index++;
			}

			// Adding spaces after the number
			add_space(buff);
			size = strlen(buff + 1);

			// Allocating memory for the number
			read->newdata = malloc(sizeof(char *) * size);

			// Copy the  buff content to newdata
			strcpy(read->newdata, buff);
			break;

		case 4:

			// Store the city in the buffer
			printf("Enter The City: ");
			scanf("%s", buff);

			// Adding spaces after the city
			add_space(buff);
			size = strlen(buff + 1);

			// Allocating memory for the city
			read->newdata = malloc(sizeof(char *) * size);

			// Copy the buff content to newdata
			strcpy(read->newdata, buff);
			break;
	}
}

// Read the information from user
int read_information(add_book *addbook, read_info *read, int option)
{
	int size, index, opt2;

	char buff[50];
	printf("Option: %d\n", option);
	switch (option)
	{
		// Reading informaton for inserting
		case 1:

			// Read the name
			printf("Enter The Name: ");
			scanf("\n%[^\n]", buff);
			add_space(buff);
			size = strlen(buff);
			addbook->name = malloc(sizeof(char *) * size);
			strcpy(addbook->name, buff);

			// Read the email id
			printf("Enter The Email Id: ");
			scanf("%s", buff);
			add_space(buff);
			size = strlen(buff);
			addbook->email = malloc(sizeof(char *) * size);
			strcpy(addbook->email, buff);

			// Read the mobile number
			printf("Enter The Mobile Number: ");
			scanf("%s", buff);
			if ((strlen(buff)) != 10)
			{
				printf("Invalid Mobile Number\n");
				return -1;
			}
			else
			{
				index = 0;
				while (buff[index] >= '0' && buff[index] <= '9')
					index++;
			}
			add_space(buff);
			size = strlen(buff);
			addbook->phone = malloc(sizeof(char *) * size);
			strcpy(addbook->phone, buff);

			// Read the city
			printf("Enter The City: ");
			scanf("%s", buff);
			add_space(buff);
			size = strlen(buff);
			addbook->city = malloc(sizeof(char *) * size);
			strcpy(addbook->city, buff);
			break;

		// Read information to edit data	
		case 2:

			// Store the name in a buffer
			printf("Enter The Name Whose Data You Want To Edit: ");
			scanf("\n%[^\n]", buff);

			// Adding spaces after the name
			add_space(buff);
			size = strlen(buff + 1);

			// Allocate memory and store in edata
			read->edata = malloc(sizeof(char *) * size); 
			strcpy(read->edata, buff);
			
			// Get the new data to edit
			printf("Edit By:\n");

			if (read_by(addbook, read) < 0)
				return -1;
			
			break;

		// Read information to search data	
		case 3:

			printf("Search By:\n");
			if (read_by(addbook, read) < 0)
				return -1;

			break;

		// Read information to delete data
		case 4:

			// Store the name in a buffer
			printf("Enter The Name Whose Data You Want To Delete: ");
			scanf("\n%[^\n]", buff);

			// Adding spaces after the name
			add_space(buff);
			size = strlen(buff + 1);

			// Allocate memory and store in edata
			read->edata = malloc(sizeof(char *) * size); 
			strcpy(read->edata, buff);
			
			break;
	}
}
