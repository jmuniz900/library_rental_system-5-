# library_rental_system-5-

Description

A local public library currently utilizes a rental system that is outdated and no longer fulfills their growing needs. Aside from improving their existing functionalities, there are new features they would like in the final product. The system will be implemented from scratch as the library only has the executable for the old system. The customer requirements for the new system are outlined below.

The system will work with the following files:
checkout.cpp
book.h
book.cpp
person.h
person.cpp
books.txt
persons.txt
Rentals.txt

where books.txt is in the format:
<bookID>
<title>
<author>
<category>

persons.txt is in the format:
<cardID> <active> <firstName> <lastName>

rentals.txt is in the format:
<bookID> <cardID>

Note that the card IDs are sequential. When you read persons.txt in some function, you will need to keep track of the largest card ID number. Return the largest ID + 1 from the function for later use. This will be needed when you open a new card and need to issue a unique card ID.

Data Structures

In main you will create the following:
	vector<Book *> books;
vector<Person *> cardholders;
The books vector holds pointers of type Book and the cardholders vector holds pointers of type Person.


Option Descriptions

Menu Option
Description
Sample Output

1. Book checkout
Asks for the card ID. Confirms that the card ID is valid. Asks for the book ID to check out the book. If the card ID is not active, handle the same as an invalid card ID.

Please enter the card ID: 1017
Cardholder: Max Chapman
Please enter the book ID: 88590
Title: A Brief History of Time
Rental Completed

Please enter the card ID: 8855
Card ID not found

Please enter the card ID: 1017
Cardholder: Max Chapman
Please enter the book ID: 99999
Book ID not found

Please enter the card ID: 1017
Cardholder: Max Chapman
Please enter the book ID: 88590
Book already checked out
2. Book return
Asks for the book ID to perform a return. Confirms that the book ID is valid. Updates the book object.
Please enter the book ID to return: 88590
Title: A Brief History of Time
Return Completed

Please enter the book ID to return: 99999
Book ID not found
3. View all available books
Searches the books vector and outputs all books that are available, if any.
Book ID: 88590
Title: A Brief History of Time
Author: Stephen Hawking
Category: Science
Book ID: ...

No available books
4. View all outstanding rentals
Searches the cardholders vector and outputs a status report of the books that are currently checked out, if any.
Book ID: 88590
Title: A Brief History of Time
Author: Stephen Hawking
Cardholder: Max Chapman
Card ID: 1017
Book ID: ...

No outstanding rentals
5. View outstanding rentals for a cardholder
Asks for the card ID. Confirms that the card ID is valid and active. Displays a list of books they currently have checked out.
Please enter the card ID: 1017
Cardholder: Max Chapman
No books currently checked out

Please enter the card ID: 1017
Cardholder: Max Chapman
Book ID: 88590
Title: A Brief History of Time
Author: Stephen Hawking
Book ID: ...
6. Open new library card
Asks for the person’s name. Creates a Person object using the new operator and inserts into the cardholders vector (use push_back).

XXXX is the next sequential card number if this is their first time opening a card. Otherwise the old card is reactivated.
Assumptions: There are no duplicate names
Please enter the first name: Mark
Please enter the last name: Green
Card ID XXXX active
Cardholder: Mark Green
7. Close library card
Asks for the card ID. Confirms that the card ID is valid and that it is not already inactive. Asks for confirmation and proceeds to deactivate the card ID.
Please enter the card ID: 1017
Cardholder: Max Chapman
Are you sure you want to deactivate card (y/n)? y
Card ID deactivated

Please enter the card ID: 8855
Card ID not found

Please enter the card ID: 1001
Cardholder: Reilly Wright
Card ID is already inactive

Additional Comments
When the program ends, the modified data must be written back to persons.txt and rentals.txt
Do not change class declarations/names/types, etc. for the provided files
Helper functions are encouraged
If the same thing is being done in multiple places, make it a function to minimize lines of code: DRY
When user input is not found - display message given in the table and return to the main menu
Do not forget to appropriately cleanup/handle dynamic memory and pointer variables
The program output should be identical to the output in the table provided
If an option has multiple records to display, there should be a space between records for easy reading on the screen (add an extra endl or ‘\n’ between records)
Submission
Create a repository for your program on Github
Upload all .cpp and .h files to Titanium
Do not upload .txt files
Add the link to your repository on Github in the comments section
Future Enhancements (optional)
Add ability to search by different fields such as author’s last name
Note that this would require storing the author name as firstName and lastName
Add rental dates and/or due dates
Asks the employee to enter today’s date for a new rental
Determine due date (e.g. 2 weeks from today’s date)
Store dates in the format of your choice
Add a menu option (use different #) to view books that are past due
You may implement a separate Date class to manage dates, but not necessary
Implement a feature to add a new book to the inventory
Consider how to handle the creation of new book IDs
Create a class named Rental that includes and uses Person and Book
This would simplify many aspects of the main program as we would hide/handle many of the details in the Rental class
Add the ability to handle books with multiple authors
