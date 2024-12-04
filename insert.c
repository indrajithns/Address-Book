#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "insert.h"
#include "read.h"  // For read_information


// Inserting data to address book
int insert_data_to_addbook(add_book *addbook, read_info *read, int option)
{
	char delimeter[5] = "//"; 
	char newline = '\n';

	// Open the file in append mode
	read->fptr = fopen(read->fname, "a+");

	if (read->fptr == NULL)
	{
		perror("fopen");
		fprintf(stderr, "ERROR: Unable To Open The File %s\n", read->fname);

		return 1;
	}

	// Read information 
	if ((read_information(addbook, read,  option)) < 0)
			return -1;

	else
	{
		// Write name
		fwrite(addbook->name, 1, 32, read->fptr);
		fwrite(delimeter, 1, 2, read->fptr);
		
		// Write email
		fwrite(addbook->email, 1, 32, read->fptr);
		fwrite(delimeter, 1, 2, read->fptr);
	
		// Write mobile number
		fwrite(addbook->phone, 1, 32, read->fptr);
		fwrite(delimeter, 1, 2, read->fptr);
		
		// Write city
		fwrite(addbook->city, 1, 32, read->fptr);
		fwrite(&newline, 1, 1, read->fptr);
		fclose (read->fptr);
	}

	return 0;
}
