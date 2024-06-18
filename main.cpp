#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Book {
    public:
        int bookID;
        string bookTitle;
        string author;
        string ISBN;
        bool available = true;
        Book(int bookID, string bookTitle, string author, string ISBN) : bookID(bookID),bookTitle(bookTitle),author(author),ISBN(ISBN) {}
        bool checkout() {
            if(available) {
                available = false;
                return true;
            }
                return false;
        }
        
        void returnbook() {
            available = true;
        }
    
};

class Member {
    public:
        int memberID;
        string name;
        string phone;
        string email;
        // creates a vector of pointers (Book*) 
        // this helps us keep track of no. of books borrowed by the member;
        vector<Book*> borrowedBooks;
        Member(int memberID, string name, string phone, string email) : memberID(memberID), name(name), phone(phone), email(email) {}
        bool borrowbook(Book &book) {
            // check if book can be borrowed 
            if(book.checkout()) {
                // add it in to the vector of Book* pointers 
                borrowedBooks.push_back(&book);
                return true;
            }
            return false;
        }
        
        void returnbook(Book &book) {
            for(auto it = borrowedBooks.begin(); it!=borrowedBooks.end(); it++) {
                //checks if given book is borrowed by the member
                // it is already a pointer and we dereference it as *it 
                // this helps in pointing to the borrowedBooks vector
                if(*it == &book) {
                    // make the book available again 
                    book.returnbook();
                    borrowedBooks.erase(it);
                    return;
                }
            }
        }
            
};

int main() {
  return 0;
}
