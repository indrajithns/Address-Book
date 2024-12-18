/*
 * File: search.c
 * Description: Functions for searching and retrieving contact information 
 *              from an address book. Searches can be performed by name, email, 
 *              phone number, and city.
 * Functions:
 *   - search_by_name: Searches for a contact by name in the address book.
 *   - search_by_email: Searches for a contact by email in the address book.
 *   - search_by_phone: Searches for a contact by phone number in the address book.
 *   - search_by_city: Searches for contacts by city and returns all matching results.
 *   - print_search_data: Prints the details of a contact found during a search.
 *   - search_data: Manages the search operation based on user input and calls 
 *                  the corresponding search functions.
 *   - read_search_data: Reads the data from a file, stores it in the address book, 
 *                       and performs the search based on user input.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "search.h"
#include "read.h"  // For read_information

// Search by name
int search_by_name(add_book *array, read_info *read, int count)
{
    for (int index = 0; index < count; index++)
    {
        if (strcmp(array[index].name, read->newdata) == 0)
        {
            return index;
        }
    }
    return -1;  // Not found
}

// Search by email
int search_by_email(add_book *array, read_info *read, int count)
{
    for (int index = 0; index < count; index++)
    {
        if (strcmp(array[index].email, read->newdata) == 0)
        {
            return index;
        }
    }
    return -1;  // Not found
}

// Search by phone number
int search_by_phone(add_book *array, read_info *read, int count)
{
    for (int index = 0; index < count; index++)
    {
        if (strcmp(array[index].phone, read->newdata) == 0)
        {
            return index;
        }
    }
    return -1;  // Not found
}

// Search by city
int search_by_city(add_book *array, read_info *read, int count, int *index_array, int *j_index)
{
    for (int index = 0; index < count; index++)
    {
        if (strcmp(array[index].city, read->newdata) == 0)
        {
            index_array[*j_index] = index;
            (*j_index)++;
        }
    }
    return *j_index > 0 ? 0 : -1;  // If matches found, return 0, else -1
}

// Print the searched data
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
int search_data(add_book *array, read_info *read, int count)
{
    int j_index = 0, index[20], kdx, i_count = 0;

    switch (read->option)
    {
        case 1:
            // Searching by name
            j_index = search_by_name(array, read, count);

            if (j_index < 0)
            {
                printf("Name Not Found\n");
                return -1;
            }
            
            print_search_data(array, j_index);
            break;

        case 2:
            // Searching by email
            j_index = search_by_email(array, read, count);

            if (j_index < 0)
            {
                printf("Email Not Found\n");
                return -1;
            }
            
            print_search_data(array, j_index);
            break;

        case 3:
            // Searching by phone number
            j_index = search_by_phone(array, read, count);

            if (j_index < 0)
            {
                printf("Phone Number Not Found\n");
                return -1;
            }

            print_search_data(array, j_index);
            break;

        case 4:
            // Searching by city
            j_index = search_by_city(array, read, count, index, &i_count);

            if (j_index < 0)
            {
                printf("City Not Found\n");
                return -1;
            }

            for (kdx = 0; kdx < i_count; kdx++)
            {
                print_search_data(array, index[kdx]);
            }
            break;
    }
    return 0;
}

// Read the data to be searched
int read_search_data(read_info *read, add_book *addbook, int option)
{
    int bytes, index, count = 0;
    char buff[32];
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
    while (fgets(buff, sizeof(buff), read->fptr) != NULL)
    {
        count++;

        // Store name
        array[index].name = strdup(buff);  // Use strdup to copy the string

        // Store email
        if (fgets(buff, sizeof(buff), read->fptr) != NULL)
        {
            array[index].email = strdup(buff);
        }

        // Store phone
        if (fgets(buff, sizeof(buff), read->fptr) != NULL)
        {
            array[index].phone = strdup(buff);
        }

        // Store city
        if (fgets(buff, sizeof(buff), read->fptr) != NULL)
        {
            array[index].city = strdup(buff);
        }
        index++;
    }

    // Search by option
    search_data(array, read, count);

    // Close the file
    fclose(read->fptr);
    return 0;
}

