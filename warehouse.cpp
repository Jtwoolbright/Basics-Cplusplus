  /*
   *         Name: Josh Woolbright
   *         Date: 3/27/2019
   *  Description: This file contains the code for the warehouse
   *               header file.
   *
   */

  #include "warehouse.h"
  #include <fstream>

  istream& operator >> (istream& is, Warehouse& warehouse) {
 
    int i = 0;
    Book book;
    while (is >> book) {
      warehouse.books[i] = book;
      i++;
    }
    warehouse.bookCount = i;
    return is;   
  }

  ostream& operator << (ostream& os, const Warehouse& warehouse) {

    for ( int i = 0; i < warehouse.bookCount; i++) {
      os << warehouse.books[i] << endl;
    }
    return os;
  }

  Warehouse::Warehouse() {
    bookCount = 0;
  }

  bool Warehouse::find (string filename, string isbn, Book& book) const {

    ifstream inputFile;
    inputFile.open(filename);

    if (inputFile.fail()) {
      cout << "File Not Found" << endl;
      return false;
    }
    if (inputFile.eof()) {
      cout << "File is empty" << endl;
      return false;
    }

    while(inputFile >> book) {
      if (book.getISBN().compare(isbn) == 0) {
        cout << "ISBN: " << book.getISBN() << " -- FOUND" << endl << book
             << endl;
        return true;
      }
    }
    inputFile.close();
    cout << "ISBN Not Found" << endl;
    return false;
  }

  void Warehouse::list(string filename, Warehouse& warehouse) const {

    ifstream inputFile;
    inputFile.open(filename);

    if (inputFile.fail()) {
      cout << "File Not Found" << endl;
      return;
    }
    if (inputFile.eof()) {
      cout << "File Is Empty" << endl;
      return;
    }

    inputFile >> warehouse;
    cout << warehouse;
    inputFile.close();
  }
