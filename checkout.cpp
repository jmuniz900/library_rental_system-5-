// Name
// Section #
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include "person.cpp"
#include "book.cpp"

using namespace std;

void printMenu() {
    cout << "----------Library Book Rental System----------" << endl;
    cout << "1.  Book checkout" << endl;
    cout << "2.  Book return" << endl;
    cout << "3.  View all available books" << endl;
    cout << "4.  View all outstanding rentals" << endl;
    cout << "5.  View outstanding rentals for a cardholder" << endl;
    cout << "6.  Open new library card" << endl;
    cout << "7.  Close library card" << endl;
    cout << "8.  Exit system" << endl;
    cout << "Please enter a choice: ";
}

// You are not obligated to use these function declarations - they're just given as examples
void readBooks(vector<Book *> & myBooks) {
    fstream bookFile;
    int     id;
    string  titleN;
    string  authorN;
    string  categN;
    string whitespace;

    bookFile.open("books.txt");
    if(bookFile.is_open()){
      cout << "Successfully opened books.txt" << endl;
      while(!bookFile.eof()){
        getline(bookFile, id);      //Isn't taking in the int from getline for some strange reason.
        getline(bookFile, titleN);
        getline(bookFile, authorN);
        getline(bookFile, categN);
        getline(bookFile, whitespace);

        Book * bookPtr = new Book(id, titleN, authorN, categN);
        myBooks.push_back(bookPtr);
        delete bookPtr;

    //    bookPtr = Book(id, titleN, authorN, categN);
    //    bookPtr->Book(id, titleN, authorN, categN);
        }
      }
  //    cout << myBooks[0]->getTitle();
    }

void readPersons(vector<Person *> & myCardholders) {
    fstream personFile;
    int cardID;
    bool active;
    string firstName;
    string lastName;
    string name;

    personFile.open("persons.txt");
    if(personFile.is_open()){
      cout << "Successfully opened persons.txt";
      while(!personFile.eof()){
        personFile >> cardID >> active >> firstName >> lastName;
        name = firstName + " " + lastName;
        Person *personptr = new Person(cardID, active, firstName, lastName);
        myCardholders.push_back(personptr);
        delete personptr;
      }
    }
    else
      cout << "Error: Couldn't open file!";
}

/*void readRentals(vector<Book *> & myBooks, vector<Person *> myCardholders) {
    return;
}
*/
void openCard(vector<Person *> & myCardholders, int nextID) {
  string firName;
  string lasName;

  cout << "Please enter your first name: ";
  cin >> firName;
  cout << endl;
  cout << "Please enter your last name: ";
  cin >> lasName;
  cout << endl;

  Person *tmpPerson = new Person(nextID, 1, firName, lasName);
  myCardholders.push_back(tmpPerson);

}

Book * searchBook(vector<Book *> myBooks, int id) {
    return nullptr;
}


int main()
{
    vector<Book *> books;
    vector<Person *> cardholders;
    int cardID;
    int bookID;

    int choice;
    int amountOfCardholders;
    int newID;

    readBooks(books);

    do
    {
        // If you use cin anywhere, don't forget that you have to handle the <ENTER> key that
        // the user pressed when entering a menu option. This is still in the input stream.
        printMenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                // Book checkout
                cout << "Please enter the card ID: ";
                cin >> cardID;
                cout << endl;

                for(int i = 0; i < cardholders.size(); i++){
                  if(cardID == cardholders[i]->getId())
                    cout << "Cardholder: " << cardholders[i]->fullName() << endl;
                  else
                    cout << "Card ID not found" << endl;
                }

                cout << "Please enter the book ID: ";
                cin >> bookID;
                cout << endl;

                for(int j = 0; j < books.size(); j++){
                  if(bookID == books[j]->getId())
                    cout << "Title: " << books[j]->getTitle() << endl;
                  else
                    cout << "Book ID not found" << endl;
                }

                for(int i = 0; i < cardholders.size(); i++){
                  for(int j = 0; j < books.size(); j++){
                    if(bookID == books[j]->getId() || cardID == cardholders[i]->getId()){
                      books[j]->setPersonPtr(cardholders[i]);
                    }
                  }
                }
                cout << "Rental Completed" << endl;
                break;

            case 2:
                // Book return
                break;

            case 3:
                // View all available books
                break;

            case 4:
                // View all outstanding rentals
                break;

            case 5:
                // View outstanding rentals for a cardholder
                break;

            case 6:
              amountOfCardholders = cardholders.size();
              newID = cardholders[amountOfCardholders].getId() + 1;
              openCard(cardholders, newID);
                // Open new library card
                break;

            case 7:
                // Close library card
                break;

            case 8:
                // Must update records in files here before exiting the program
                break;

            default:
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
   } while(choice != 8);
      return 0;
}
