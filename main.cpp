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
        bool available;
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

int main() {
  return 0;
}
