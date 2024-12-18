# Address Book Management System

## Project Description

This project is a simple **Address Book Management System** implemented in C. It allows users to perform various operations on an address book, such as adding, editing, displaying, deleting, and searching for contacts. The system supports storing information such as **Name**, **Email**, **Phone Number**, and **City**. The data is managed using simple file operations, allowing users to search and manipulate address book entries.


The following operations are supported:
- **Insert**: Add new contacts to the address book.
- **Edit**: Modify existing contacts.
- **Display**: View all contacts in the address book.
- **Delete**: Remove a contact from the address book.
- **Search**: Search for contacts by name, email, phone, or city.

---

### File Descriptions

- **delete.c**: Contains functions to delete contacts based on different criteria (e.g., name, email, phone, city).
- **delete.h**: Declares the functions provided in `delete.c` for use in other files.
- **display.c**: Functions for displaying all the contacts stored in the address book.
- **display.h**: Declares display-related functions.
- **edit.c**: Functions for editing existing contacts in the address book.
- **edit.h**: Declares the functions related to editing contacts.
- **insert.c**: Functions for inserting new contacts into the address book.
- **insert.h**: Declares the functions related to inserting contacts.
- **main.c**: Main entry point of the program that integrates all functionalities, including reading user input, calling corresponding operations, and managing the flow.
- **read.c**: Handles user input and file reading. It processes the user’s input for search and other operations and interacts with files.
- **read.h**: Declares the functions in `read.c`, including file reading and input handling.
- **search.c**: Contains search-related functions to find contacts based on name, email, phone number, or city.
- **search.h**: Declares search-related functions.

---

## Usage

1. Compile the program using `Makefile` or manually using a C compiler:

    ```bash
    gcc *.c -o address_book
    ```

2. After compiling, you can run the program:

    ```bash
    ./address_book
    ```

---

When the program runs, it will present the user with a menu of options:

1. **Insert a new contact**
2. **Edit an existing contact**
3. **Search for a contact**
4. **Delete a contact**
5. **Display all contacts**
6. **Exit**

### Example Workflow

#### Inserting a New Contact

- Select option **1** to insert a new contact.
- Enter the name, email, phone, and city when prompted.
- The new contact will be added to the address book.

#### Editing a Contact

- Select option **2** to edit an existing contact.
- You will be prompted to enter the name or other identifying information.
- Modify the contact details as needed.

#### Searching for a Contact

- Select option **3** to search by name, email, phone, or city.
- You will be prompted to enter the relevant information to search for a contact.

#### Deleting a Contact

- Select option **4** to delete a contact.
- You will be asked to choose the criterion (name, email, phone, or city) and enter the corresponding data to identify the contact to delete.

#### Displaying All Contacts

- Select option **5** to display all contacts stored in the address book.

#### Exiting the Program

- Select option **6** to exit the program.

---

## Functionality Breakdown

1. **Insert**: The `insert.c` file allows the user to add new contacts to the address book.
2. **Edit**: The `edit.c` file provides functionality for editing the details of an existing contact.
3. **Display**: The `display.c` file contains functions to display all stored contacts in the address book.
4. **Delete**: The `delete.c` file provides functionality for deleting a contact based on name, email, phone, or city.
5. **Search**: The `search.c` file allows the user to search contacts based on name, email, phone, or city.

Each feature is modularized into separate functions and files for better readability and maintainability.

---

