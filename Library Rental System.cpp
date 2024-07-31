/*
Name: Rosey
Date: 12/13/23
Title: Library Rental System
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Book class: Abstract
class Book
{
private:
    int code;      // Unique identifier for the book
    string title;  // Title of the book
    int available; // Number of available copies
    int rented;    // Number of rented copies

public:
    // Constructors
    Book() {}
    Book(int c, const string &t, int av, int r) : code(c), title(t), available(av), rented(r) {}

    // Getters
    int getCode() { return code; }
    string getTitle() { return title; }
    int getAvailable() { return available; }
    int getRented() { return rented; }

    // Pure virtual functions
    virtual int getAge() = 0;
    virtual string getPublisher() = 0;
    virtual int getPublishDate() = 0;
    virtual string getPublishDetails() = 0;

    // Setters
    virtual void setAvailable(int av) { available = av; }
    virtual void setRented(int r) { rented = r; }

    virtual string getCategory() = 0;
    // Display book information
    virtual void displayInfo()
    {
        cout << getTitle() << "(" << getCode() << ") exists." << endl;
        cout << getAvailable() << "available, " << getRented() << "rented" << endl;
    }
};

// ChildrenBook class
class ChildrenBook : public Book
{
private:
    int age; // Age for ChildrenBook

public:
    // Constructors
    ChildrenBook() {}
    ChildrenBook(int c, const string &t, int a, int av, int r) : Book(c, t, av, r), age(a) {}

    // Getters
    int getAge() { return age; }
    string getPublisher() { return ""; }
    int getPublishDate() { return 0; }
    string getPublishDetails() { return ""; }
    string getCategory() { return "Children Book"; }

    // Display children book's info
    void displayInfo()
    {
        cout << getTitle() << "(" << getCode() << ") exists." << endl;
        cout << "Category: Children Book " << endl;
        cout << "Age: " << getAge() << endl;
        cout << getAvailable() << " available, " << getRented() << " rented" << endl;
    }
};

// ComputerBook class
class ComputerBook : public Book
{
private:
    string publisher; // Publisher for ComputerBook

public:
    // Constructors
    ComputerBook() {}
    ComputerBook(int c, const string &t, const string &pub, int av, int r)
        : Book(c, t, av, r), publisher(pub) {}

    // Getters
    int getAge() { return 0; }
    string getPublisher() { return publisher; }
    int getPublishDate() { return 0; }
    string getPublishDetails() { return ""; }
    string getCategory() { return "Computer Book"; }

    // Display computer book's info
    void displayInfo()
    {
        cout << getTitle() << "(" << getCode() << ") exists." << endl;
        cout << "Category: Computer Book" << endl;
        cout << "Publisher: " << getPublisher() << endl;
        cout << getAvailable() << " available, " << getRented() << " rented" << endl;
    }
};

// Novel class
class Novel : public Book
{
private:
    int publish_date; // Publish Date for Novel

public:
    // Constructors
    Novel() {}
    Novel(int c, const string &t, int pd, int av, int r)
        : Book(c, t, av, r), publish_date(pd) {}

    // Getters
    int getAge() { return 0; }
    string getPublisher() { return ""; }
    int getPublishDate() { return publish_date; }
    string getPublishDetails() { return ""; }
    string getCategory() { return "Novel"; }

    // Display novel's info
    void displayInfo()
    {
        cout << getTitle() << "(" << getCode() << ") exists." << endl;
        cout << "Category: " << endl;
        cout << "Publish Date: " << getPublishDate() << endl;
        cout << getAvailable() << " available, " << getRented() << " rented" << endl;
    }
};

// Person class: Abstract
class Person
{
private:
    int id;      // ID of a person
    string name; // name of a person
    int count;   // Number of books currently rented by the person

public:
    // Constructors
    Person() {}
    Person(int i, const string &n, int c) : id(i), name(n), count(c) {}

    // Getters
    int getId() { return id; }
    string getName() { return name; }
    int getCount() { return count; }

    // Setters
    void setId(int i) { id = i; }
    void setName(const string &n) { name = n; }
    void setCount(int c) { count = c; }

    // Pure virtual functions
    virtual int getCode() = 0;
    virtual int getCode(int i) = 0;
    virtual void setCode(int newCode) = 0;
    virtual void setCode(int index, int newCode) = 0;
};

// Student class
class Student : public Person
{
private:
    int code[2]; // Array to store codes of books rented by the student

public:
    // Constructors
    Student() {}
    Student(int i, const string &n, int c1, int c2) : Person(i, n, 2)
    {
        code[0] = c1;
        code[1] = c2;
    }

    // Getters & setter for book codes
    int getCode() { return code[0]; }
    void setCode(int newCode) { code[0] = newCode; }

    int getCode(int index) { return code[index]; }

    // Check that the index is within the bounds of the array
    void setCode(int index, int newCode)
    {
        if (index < sizeof(code) / sizeof(code[0]))
        { // Ensure the index is within the array bounds
            code[index] = newCode;
        }
    }
};

// Teacher class
class Teacher : public Person
{
private:
    int code[3]; // Array to store codes of books rented by the teacher

public:
    // Constructors
    Teacher() {}
    Teacher(int i, const string &n, int c1, int c2, int c3) : Person(i, n, 3)
    {
        code[0] = c1;
        code[1] = c2;
        code[2] = c3;
    }

    // Getters and settersfor book codes
    int getCode() { return code[0]; }
    void setCode(int newCode) { code[0] = newCode; }
    int getCode(int index) { return code[index]; }

    // Check that the index is within the bounds of the array
    void setCode(int index, int newCode)
    {
        if (index < sizeof(code) / sizeof(code[0]))
        { // Ensure the index is within the array bounds
            code[index] = newCode;
        }
    }
};

// BookNode struct: a node in a linked list of books
struct BookNode
{
    Book *data;                                                // Pointer to a Book object
    struct BookNode *link;                                     // Pointer to the next node in the list
    string category;                                           // Category of the book
    BookNode() : data(nullptr), link(nullptr), category("") {} // Constructor for initializing the node
};

// PersonNode struct: a node in a linked list of persons
struct PersonNode
{
    Person *data;                                  // Pointer to a Person object
    struct PersonNode *link;                       // Pointer to the next node in the list
    PersonNode() : data(nullptr), link(nullptr) {} // Constructor for initializing the node
};

// Function to search for a book by code and title
void searchBook(BookNode *library[], int code, const string &title)
{
    try
    {
        bool bookFound = false;
        // Iterate over all library sections to find the book
        for (int i = 0; i < 3; ++i)
        {
            BookNode *current = library[i];
            while (current != nullptr)
            {
                if (current->data->getCode() == code && current->data->getTitle() == title)
                {
                    current->data->displayInfo(); // Display book information
                    bookFound = true;
                    break;
                }
                current = current->link;
            }
        }
        // Inform if no match is found
        if (!bookFound)
        {
            throw string("No match found (code and title do not match)");
        }
    }
    catch (const string &errorMessage)
    {
        cout << "Exception: " << errorMessage << endl;
    }
}

// Function to rent a book if it is available
void rentBook(BookNode *library[], PersonNode *person[], int personId, string &bookTitle)
{
    try
    {
        // Find the person in the list
        PersonNode *foundP = nullptr;
        bool isTeacher = false;
        for (int i = 0; i < 2; i++)
        {
            for (PersonNode *temp = person[i]; temp != nullptr; temp = temp->link)
            {
                if (temp->data->getId() == personId)
                {
                    foundP = temp;
                    isTeacher = (i == 0); // Teachers are in person[0]
                    break;
                }
            }
            if (foundP != nullptr)
            {
                break;
            }
        }
        // exception handling if the person is not found
        if (foundP == nullptr)
        {
            throw "Person not found.";
        }
        // Check if the person has already rented the maximum allowed books
        if (isTeacher && foundP->data->getCount() >= 3)
        {
            throw 1;
        }
        else if (!isTeacher && foundP->data->getCount() >= 2)
        {
            throw 2;
        }

        // Find the book in the library
        BookNode *foundB = nullptr;
        for (int j = 0; j < 3; ++j)
        {
            for (BookNode *temp = library[j]; temp != nullptr; temp = temp->link)
            {
                if (bookTitle == temp->data->getTitle())
                {
                    foundB = temp;
                    break;
                }
            }
            if (foundB != nullptr)
            {
                break;
            }
        }
        // exception handling if the book is not found
        if (foundB == nullptr)
        {
            throw "Book not found.";
        }

        // Check if the book is available for rent
        if (foundB->data->getAvailable() <= 0)
        {
            throw "The book is not available (all rented out).";
        }

        cout << endl;
        cout << "You are " << foundP->data->getName() << ". You rented " << foundP->data->getCount() << " book(s)." << endl;

        char response;
        cout << "Do you want to rent ‘" << bookTitle << "’ (y/n)? ";
        cin >> response;

        if (response == 'y' || response == 'Y')
        {
            // Update the book's availability and rented status
            foundB->data->setAvailable(foundB->data->getAvailable() - 1);
            foundB->data->setRented(foundB->data->getRented() + 1);

            // Update the person's rented book information
            foundP->data->setCode(foundP->data->getCount(), foundB->data->getCode());
            foundP->data->setCount(foundP->data->getCount() + 1);

            cout << "***** Rent succeed. Check your info!" << endl;
        }
        else
        {
            cout << "Rent cancelled." << endl;
        }
    }
    catch (const char *errorMessage)
    {
        cout << errorMessage << endl;
    }
    catch (int errorCode)
    {
        if (errorCode == 1)
        {
            cout << "You can only rent 3 books" << endl;
        }
        else if (errorCode == 2)
        {
            cout << "You can only rent 2 books" << endl;
        }
    }
}

// Function to return a rented book
void returnBook(PersonNode *headPerson, BookNode *library[], int personId, int code)
{
    try
    {
        // Find the person who rented the book
        bool personFound = false;
        PersonNode *currentPerson = headPerson;
        while (currentPerson != NULL)
        {
            if (currentPerson->data->getId() == personId)
            {
                personFound = true;
                break;
            }
            currentPerson = currentPerson->link;
        }
        // exception handling if the person is not found
        if (!personFound)
        {
            throw "The 'id' did not rent the book.";
        }
        // Find the rented book in the library
        bool bookFound = false;
        for (int i = 0; i < 3; i++)
        {
            BookNode *current = library[i];
            while (current != NULL)
            {
                if (current->data->getCode() == code)
                {
                    // Check if the book is rented by this person
                    bool rentedByThisPerson = false;
                    int rentedBookIndex = -1;
                    for (int j = 0; j < currentPerson->data->getCount(); ++j)
                    {
                        if (currentPerson->data->getCode(j) == code)
                        {
                            rentedByThisPerson = true;
                            rentedBookIndex = j;
                            break;
                        }
                    }
                    // exception handling if the person did not rent this book
                    if (!rentedByThisPerson)
                    {
                        throw "Person has not rented this book.";
                    }

                    char returnChoice;
                    cout << "Do you want to return ‘" << current->data->getTitle() << "’ (y/n)? ";
                    cin >> returnChoice;

                    if (returnChoice == 'y' || returnChoice == 'Y')
                    {
                        // Update the book's availability and rented status
                        current->data->setAvailable(current->data->getAvailable() + 1);
                        current->data->setRented(current->data->getRented() - 1);

                        // Update the person's book rental information
                        for (int k = rentedBookIndex; k < currentPerson->data->getCount() - 1; ++k)
                        {
                            currentPerson->data->setCode(k, currentPerson->data->getCode(k + 1));
                        }
                        currentPerson->data->setCode(currentPerson->data->getCount() - 1, 0); // Reset the last code
                        currentPerson->data->setCount(currentPerson->data->getCount() - 1);

                        cout << "***** Return succeed. Check your info!" << endl;
                        bookFound = true;
                    }
                    else
                    {
                        cout << "Return canceled." << endl;
                    }

                    break;
                }
                current = current->link;
            }
            if (bookFound)
            {
                break;
            }
        }
        // exception handling if the book is not found
        if (!bookFound)
        {
            throw "Book not found.";
        }
    }
    catch (const char *message)
    {
        cout << "Exception handling for Menu 3: " << message << endl;
    }
}

// Function to display information of a person's rented books
void showPersonInfo(PersonNode *head, BookNode *library[], int personId, const string &personName)
{
    PersonNode *currentPerson = head;
    // Iterate through the list of persons to find the matching person by ID
    while (currentPerson != NULL)
    {
        if (currentPerson->data->getId() == personId)
        {
            int validBookCount = 0; // Count only valid book codes
            int rentedBooksCount = currentPerson->data->getCount();
            cout << personName << ", you rented ";

            // Iterate over rented book codes to count valid ones
            for (int i = 0; i < rentedBooksCount; ++i)
            {
                int bookCode = currentPerson->data->getCode(i);
                if (bookCode != 0) // Check if the book code is valid
                {
                    validBookCount++;
                }
            }

            cout << validBookCount << " book(s)." << endl; // Display the count of valid rented books

            // If there are valid rented books, display their details
            if (validBookCount > 0)
            {
                cout << "Rented books:" << endl;

                for (int i = 0; i < rentedBooksCount; ++i)
                {
                    int bookCode = currentPerson->data->getCode(i);
                    if (bookCode != 0) // Check if the book code is valid
                    {
                        // Search for the book in the library and display its details
                        for (int j = 0; j < 3; ++j)
                        {
                            BookNode *currentBook = library[j];
                            while (currentBook != nullptr)
                            {
                                if (currentBook->data->getCode() == bookCode)
                                {
                                    cout << "* " << currentBook->data->getTitle() << "(" << bookCode << ")";
                                    if (currentBook->data->getCategory() == "Children Book")
                                    {
                                        cout << " - age " << currentBook->data->getAge() << endl;
                                    }
                                    cout << endl;
                                    break;
                                }
                                currentBook = currentBook->link;
                            }
                        }
                    }
                }
            }

            break;
        }

        currentPerson = currentPerson->link;
    }

    // Outputs if no valid rented books or the person is not found
    if (currentPerson == nullptr)
    {
        cout << personName << ", you haven't rented any books." << endl;
    }
}

// Function to display all books in the library
void showAllBooks(BookNode *head)
{
    BookNode *current = head;
    string lastCategory = "";

    // Iterate through each book in the linked list
    while (current != nullptr)
    {
        // Print the header only when the category changes
        if (current->data->getCategory() != lastCategory)
        {
            cout << endl;
            cout << "========================================================================================\n"
                 << "\t\t" << current->data->getCategory() << "\n"
                 << "========================================================================================\n";
            cout << setw(8) << "Code" << setw(35) << "Title";

            // Print information based on the category of the book
            if (current->data->getCategory() == "Children Book")
            {
                cout << setw(8) << "Age";
            }
            else if (current->data->getCategory() == "Computer Book")
            {
                cout << setw(20) << "Publisher";
            }
            else if (current->data->getCategory() == "Novel")
            {
                cout << setw(15) << "Publish Date";
            }
            cout << setw(12) << "Available" << setw(8) << "Rented" << endl;
            lastCategory = current->data->getCategory();
            cout << "----------------------------------------------------------------------------------------\n";
        }
        cout << setw(8) << current->data->getCode();
        string title = current->data->getTitle();
        // Replace underscores with spaces
        for (int i = 0; i < title.length(); i++)
        {
            if (title[i] == '_')
            {
                title[i] = ' ';
            }
        }
        cout << setw(35) << title;

        if (current->data->getCategory() == "Children Book")
        {
            cout << setw(8) << current->data->getAge();
        }
        else if (current->data->getCategory() == "Computer Book")
        {
            string publisher = current->data->getPublisher();
            // Replace underscores with spaces
            for (int i = 0; i < publisher.length(); i++)
            {
                if (publisher[i] == '_')
                {
                    publisher[i] = ' ';
                }
                else if (publisher[i] == '-')
                {
                    publisher[i] = ' ';
                }
            }
            cout << setw(20) << publisher;
        }
        else if (current->data->getCategory() == "Novel")
        {
            cout << setw(15) << current->data->getPublishDate();
        }
        cout << setw(12) << current->data->getAvailable() << setw(8) << current->data->getRented() << endl;

        current = current->link;
    }
}

// Function to insert a new book into the linked list of books in sorted order based on the book code
void insertBook(BookNode *&head, Book *newBook, const string &category)
{
    BookNode *newNode = new BookNode; // Create a new node for the book
    newNode->data = newBook;          // Assign the book to the new node
    newNode->link = nullptr;          // Set the next link to null
    newNode->category = category;     // Set the category of the book

    // Insert the new node at the beginning or in sorting
    if (head == nullptr || head->data->getCode() > newBook->getCode())
    {
        newNode->link = head; // Link the new node to the head of the list
        head = newNode;       // Update the head to the new node
    }
    else
    {
        BookNode *current = head;
        // Find the insertion point
        while (current->link != nullptr && current->link->data->getCode() < newBook->getCode())
        {
            current = current->link;
        }
        newNode->link = current->link; // Link the new node to the next node in the list
        current->link = newNode;       // Update the current node's link to the new node
    }
}

// Function to insert a new person into the linked list of persons in sorted order based on the person ID
void insertPerson(PersonNode *&head, Person *newPerson)
{
    PersonNode *newNode = new PersonNode; // Create a new node for the person
    newNode->data = newPerson;            // Assign the person to the new node
    newNode->link = nullptr;              // Set the next link to null

    // Insert the new node at the beginning or in sorting
    if (head == nullptr || head->data->getId() > newPerson->getId())
    {
        newNode->link = head; // Link the new node to the head of the list
        head = newNode;       // Update the head to the new node
    }
    else
    {
        PersonNode *current = head;
        // Find the insertion point
        while (current->link != nullptr && current->link->data->getId() < newPerson->getId())
        {
            current = current->link;
        }
        newNode->link = current->link; // Link the new node to the next node in the list
        current->link = newNode;       // Update the current node's link to the new node
    }
}

// Function to delete the linked list of books
void deleteBooks(BookNode *&head)
{
    BookNode *current = head; // Start from the head of the list
    BookNode *next;

    // Iterate through the list and delete each node
    while (current != nullptr)
    {
        next = current->link; // Keep track of the next node
        delete current;       // Delete the current node
        current = next;       // Move to the next node
    }

    head = nullptr; // Set the head of the list to null
}

// Function to delete the linked list of persons
void deletePersons(PersonNode *&head)
{
    PersonNode *current = head; // Start from the head of the list
    PersonNode *next;

    // Iterate through the list and delete each node
    while (current != nullptr)
    {
        next = current->link; // Keep track of the next node
        delete current;       // Delete the current node
        current = next;       // Move to the next node
    }

    head = nullptr; // Set the head of the list to null
}

// Function to print the details of all persons in the linked list
void printPersons(PersonNode *head)
{
    PersonNode *current = head; // Start from the head of the list
    // Iterate through the list and print each person's details
    while (current != nullptr)
    {
        cout << "Person ID: " << current->data->getId() << ", Name: " << current->data->getName() << endl;
        current = current->link; // Move to the next node
    }
}

int main()
{
    // Get user input file names for books and persons
    string filename1, filename2;
    cout << "Enter Book filename : ";
    cin >> filename1;
    cout << "Enter Person filename : ";
    cin >> filename2;

    // Open the files for reading
    ifstream infile1;
    ifstream infile2;
    infile1.open(filename1);
    infile2.open(filename2);

    // Check for file opening fail
    if (infile1.fail() || infile2.fail())
    {
        cout << "Input file opening failed." << endl;
        exit(1);
    }

    // Initialize head pointers for book and person linked lists
    BookNode *headChB = nullptr; // Head for Children's Books
    BookNode *headCB = nullptr;  // Head for Computer Books
    BookNode *headNB = nullptr;  // Head for Novels

    PersonNode *headTeacher = nullptr; // Head for Teachers
    PersonNode *headStudent = nullptr; // Head for Students

    // Variables for reading book and person data
    int bookCode, bookAge, bookAvailable, bookRented, bookPublishDate;
    string bookTitle, bookPublisher, bookPublishDetails;
    int p_count1 = 0, p_count2 = 0, p_count3 = 0;

    BookNode *library[3] = {nullptr, nullptr, nullptr};

    // Read book data from file and connect linked lists
    while (infile1 >> bookCode)
    {
        if (bookCode >= 1001 && bookCode <= 2000) // Children's Books
        {
            infile1 >> bookTitle >> bookAge >> bookAvailable >> bookRented;
            ChildrenBook *newBook = new ChildrenBook(bookCode, bookTitle, bookAge, bookAvailable, bookRented);
            insertBook(headChB, newBook, "Children Book");
        }
        else if (bookCode >= 2001 && bookCode <= 3000) // Computer Books
        {
            infile1 >> bookTitle >> bookPublisher >> bookAvailable >> bookRented;
            ComputerBook *newBook = new ComputerBook(bookCode, bookTitle, bookPublisher, bookAvailable, bookRented);
            insertBook(headCB, newBook, "Computer Book");
        }
        else if (bookCode >= 3001 && bookCode <= 4000) // Novels
        {
            infile1 >> bookTitle >> bookPublishDate >> bookAvailable >> bookRented;
            Novel *newBook = new Novel(bookCode, bookTitle, bookPublishDate, bookAvailable, bookRented);
            insertBook(headNB, newBook, "Novel");
        }
    }

    library[0] = headChB;
    library[1] = headCB;
    library[2] = headNB;

    int p_id;
    string p_name;
    int numOfBooks = 0;

    // Set person array with the heads of each person category
    PersonNode *person[2] = {headTeacher, headStudent};

    // Reading from person.txt and go through the person linked lists
    while (infile2 >> p_id)
    {
        infile2 >> p_name >> numOfBooks; // Read name and number of books

        if (p_id >= 1 && p_id <= 100) // Teacher
        {
            int codes[3] = {0, 0, 0};
            for (int i = 0; i < numOfBooks; ++i)
            {
                infile2 >> codes[i]; // Read each book code
            }
            Teacher *newPerson = new Teacher(p_id, p_name, codes[0], codes[1], codes[2]);
            newPerson->setCount(numOfBooks);
            insertPerson(headTeacher, newPerson);
        }
        else if (p_id >= 101 && p_id <= 300) // Student
        {
            int codes[2] = {0, 0};
            for (int i = 0; i < numOfBooks; ++i)
            {
                infile2 >> codes[i]; // Read each book code
            }
            Student *newPerson = new Student(p_id, p_name, codes[0], codes[1]);
            newPerson->setCount(numOfBooks);
            insertPerson(headStudent, newPerson);
        }
    }
    person[0] = headTeacher;
    person[1] = headStudent;

    int choice;
    do
    {
        // Display menu options to the user
        cout << "\n***** Menu *****\n";
        cout << "1. Search for a book" << endl;
        cout << "2. Rent a book" << endl;
        cout << "3. Return a book" << endl;
        cout << "4. Show my information" << endl;
        cout << "5. Show all books" << endl;
        cout << "6. Exit" << endl;
        cout << endl;
        cout << "Select (1-6): ";
        cin >> choice;
        cout << endl;

        int code;
        string title;

        int personId;
        string personName, bookTitle;

        string returnPersonName, returnBookTitle;
        int personInfoId;

        switch (choice)
        {
        case 1: // Search for a book
            cout << "Enter code: ";
            cin >> code;
            cout << "Enter title: ";
            cin >> title;
            cout << endl;
            searchBook(library, code, title);
            break;

        case 2: // Rent a book
            cout << "Enter your id: ";
            cin >> personId;
            cout << "Enter book title: ";
            cin >> bookTitle;
            rentBook(library, person, personId, bookTitle);
            break;

        case 3: // Return a book
            int returnPersonId, returnBookCode;
            cout << "Enter your id: ";
            cin >> returnPersonId;
            cout << "Enter the book code to return: ";
            cin >> returnBookCode;

            if (returnPersonId >= 1 && returnPersonId <= 100)
            {
                returnBook(headTeacher, library, returnPersonId, returnBookCode);
            }
            else if (returnPersonId >= 101 && returnPersonId <= 300)
            {
                returnBook(headStudent, library, returnPersonId, returnBookCode);
            }
            else
            {
                cout << "Invalid ID. Please enter a valid ID." << endl;
            }
            break;

        case 4: // Show person information
            cout << "Enter your id: ";
            cin >> personInfoId;
            cout << "Enter your name: ";
            cin >> personName;

            if (personInfoId >= 1 && personInfoId <= 100)
            {
                showPersonInfo(headTeacher, library, personInfoId, personName);
            }
            else if (personInfoId >= 101 && personInfoId <= 300)
            {
                showPersonInfo(headStudent, library, personInfoId, personName);
            }
            else
            {
                cout << "Invalid ID. Please enter a valid ID." << endl;
            }
            break;

        case 5:                    // Show all books
            showAllBooks(headChB); // Display Children Books
            showAllBooks(headCB);  // Display Computer Books
            showAllBooks(headNB);  // Display Novels
            break;

        case 6: // Exit the program
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
        }
    } while (choice != 6);

    // Deallocate memory
    deleteBooks(headChB);
    deleteBooks(headCB);
    deleteBooks(headNB);
    deletePersons(headTeacher);
    deletePersons(headStudent);

    return 0;
}
