  /*         
   *         Name: Josh Woolbright
   *         Date: 3/27/2018
   *       Course: CS2560.01
   *  Description: This file contains the code for the book header
   *               file. 
   *
   */

  #include "book.h"

  string strData;

  istream& operator >> (istream& is, Book& book) {

    getline(is, book.title);
    getline(is, strData);
    book.authorCount = atoi(strData.c_str());

    for (int i =0; i < book.authorCount; i++) {
      getline(is, book.authors[i]);
    }
    getline(is, book.publisher);
    getline(is, strData);
    book.yearPublish = atoi(strData.c_str());

    getline(is, strData);
    book.hardcover = atoi(strData.c_str());

    getline(is, strData);
    book.price = stof(strData.c_str());

    getline(is, book.isbn);

    getline(is, strData);
    book.copies = stol(strData.c_str());    
    return is;    
  }

  ostream& operator << (ostream& os, const Book& book) {

    os << "Title: " << book.title << endl << "Author Count: " << 
          book.authorCount << endl;

    for (int index = 0; index < book.authorCount;index++) {
      os << "Author: " << book.authors[index] << endl;
    }

    os << "Publisher: " << book.publisher << endl << "Year: " << book.yearPublish
       << endl << "Cover: ";

    if (book.hardcover == 1) {
      os << "Hardcover" << endl;
    }
    else {
      os << "Paperback" << endl;
    }

    os << "Price: " << book.price << endl << "ISBN: " << book.isbn << endl <<
        "Copies: " << book.copies << endl;
    return os;
  }

  Book::Book() {
    title = "";
    authorCount = 0;
    for (int index; index < MAX_AUTHORS; index++) {
      authors[index] = "";
    }
    publisher = "";
    yearPublish = 0;
    hardcover = 0;
    price = 0.0;
    isbn = "";
    copies = 0;
  }

  string Book::getISBN() {
    return isbn;
  }
