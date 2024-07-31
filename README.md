# Library-Rental-System
Library Rental System Project Instruction📙

### Overview

The Library Rental System is a console-based application that allows users to manage book rentals in a library. The system supports three types of books (Children's Books, Computer Books, Novels) and two groups of people (Teachers and Students).

### Input Files

Before running the program, you need to prepare two input files: `books.txt` and `persons.txt`.

1. **books.txt** - This file contains information about the books available in the library. Each line in the file represents a book and has the following format:
   ```
   book_code book_title attribute available_copies rented_copies
   ```
   - `book_code`: Unique identifier for the book (e.g., 1001 for Children's Books, 2001 for Computer Books, 3001 for Novels).
   - `book_title`: Title of the book (use underscores `_` instead of spaces).
   - `attribute`: Age (for Children's Books), Publisher (for Computer Books), or Publish Date (for Novels).
   - `available_copies`: Number of copies available for rent.
   - `rented_copies`: Number of copies currently rented out.

   Example:
   ```
   1001 Harry_Potter 8 5 2
   2001 Introduction_to_Algorithms MIT_Press 10 3
   3001 The_Great_Gatsby 1925 7 1
   ```

2. **persons.txt** - This file contains information about the persons (Teachers and Students) who rent books. Each line in the file represents a person and has the following format:
   ```
   person_id person_name number_of_books_rented book_code1 book_code2 (for students)
   person_id person_name number_of_books_rented book_code1 book_code2 book_code3 (for teachers)
   ```
   - `person_id`: Unique identifier for the person (1-100 for Teachers, 101-300 for Students).
   - `person_name`: Name of the person (use underscores `_` instead of spaces).
   - `number_of_books_rented`: Number of books currently rented by the person.
   - `book_code1`, `book_code2`, `book_code3`: Codes of the books rented by the person (up to 2 for Students, up to 3 for Teachers).

   Example:
   ```
   1 Alice 3 1001 2001 3001
   101 Bob 2 1001 2001
   ```

### Running the Program

1. **Provide Input File Names:**
   When prompted, enter the names of the input files:
   ```
   Enter Book filename : books.txt
   Enter Person filename : persons.txt
   ```

### Using the Menu

The program provides a menu with several options:

1. **Search for a Book:**
   - Enter the book code and title when prompted.
   - Example:
     ```
     Enter code: 1001
     Enter title: Harry_Potter
     ```

2. **Rent a Book:**
   - Enter your ID and the title of the book you want to rent.
   - Example:
     ```
     Enter your id: 101
     Enter book title: Harry_Potter
     ```

3. **Return a Book:**
   - Enter your ID and the code of the book you want to return.
   - Example:
     ```
     Enter your id: 101
     Enter the book code to return: 1001
     ```

4. **Show My Information:**
   - Enter your ID and name to display your rented books.
   - Example:
     ```
     Enter your id: 101
     Enter your name: Bob
     ```

5. **Show All Books:**
   - Displays a list of all books in the library, categorized by type.

6. **Exit:**
   - Exits the program.

### Example Interaction

Here is an example of interaction with the program:

```
Enter Book filename : books.txt
Enter Person filename : persons.txt

***** Menu *****
1. Search for a book
2. Rent a book
3. Return a book
4. Show my information
5. Show all books
6. Exit

Select (1-6): 1
Enter code: 1001
Enter title: Harry_Potter

Harry Potter(1001) exists.
Category: Children Book 
Age: 8
5 available, 2 rented

Select (1-6): 2
Enter your id: 101
Enter book title: Harry_Potter
Do you want to rent ‘Harry_Potter’ (y/n)? y
***** Rent succeed. Check your info!

Select (1-6): 4
Enter your id: 101
Enter your name: Bob
Bob, you rented 3 book(s).
Rented books:
* Harry Potter(1001) - age 8
```

### Error Handling

The program includes error handling for various scenarios:
- If a person or book is not found.
- If a person has already rented the maximum allowed books.
- If a book is not available for rent.

### Conclusion

This Library Rental System allows users to manage book rentals efficiently. By following the instructions above, you can easily set up and use the system. Feel free to explore all the features and enjoy managing your library rentals!

