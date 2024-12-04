# Address Book
Address Book is a small application written in C language. It keeps track of names and telephone/mobile numbers and e-mail addresses. It is a console based application which uses standard I/O for adding and deleting contact names, phone numbers and e-mail addresses, searching names and associated numbers and email addresses, updating numbers and email addresses, and deleting contacts.

ALGORITHM

Step 1: Start
Step 2: Read the file name 
Step 3: Read option:
1. Insert 
2. Edit
3. Search
4. Delete
5. Display

INSERT

Step 1: Open the file in append mode
Step 2: Read information from the user like name, email, phone number and city
Step 3: Add spaces after each data upto 32 characters for each
Step 4: Write the data into the file
Step 5: Close the fileS

EDIT

Step 1: Open the file in read write mode
Step 2: Store all the data in array of stuctures
Step 3: Read the name which is to be edited
Step 4: Read option to edit by:
Name
Email
Phone
City
Step 4: Read the new data
Step 5: Compare the new data with the name entered
Step 6: If matched return the index value of the array in which the previous content is stored and repalce it by writing the new content to the file in that postion 
Step 7: Close the file

DELETE

Step 1: Open the file in read mode
Step 2: Store all the datas in array of structures and close the file
Step 3: Open the file in write mode 
Step 4: Read the name whose contact is to be deleted
Step 5: Compare the name with all the array names
Step 6: If the found skip that index and write the reamaining array elemnts back to the file
Step 7: Close the file

SEARCH

Step 1: Open the file in read mode
Step 2: Store  all the datas in array of sturctures
Step 3: Read the the option to search by:
Name
Email
Phone
City
Step 4: Compare the read content with the content in the array 
Step 5: If found print index of the array and print the contents of the array with that index
Step 6: Close the file

Usage: 

gcc delete.c display.c edit.c insert.c main.c read.c search.c
./a.out
