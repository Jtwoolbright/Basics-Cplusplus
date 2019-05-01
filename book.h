  /*        
   *         Name: Josh Woolbright
   *         Date: 3/27/2019
   *       Course: CS2560.01
   *  Description: This is a header file for a class called Book.
   *       
   */

  // @file book.h

  #ifndef BOOK_H
  #define BOOK_H

  #include <iostream>
  #include <string>
  using namespace std;

  class Book {

    /**
     * @param is the input stream
     * @param book the book object to be filled
     * @return the input stream
     */
    friend istream& operator >> (istream& is, Book& book);
     
    /**
     * @param os the output stream
     * @param book the book object reference * @return the output stream
     */
    friend ostream& operator << (ostream& os, const Book& book);

    public:
      static const int MAX_AUTHORS = 35;

      Book();

      string getISBN();

    private:
      string title;
      string authors[Book::MAX_AUTHORS];
      int authorCount;
      string publisher;
      short yearPublish;
      bool hardcover; 
      float price;
      string isbn;
      long copies;
  };

  #endif /* BOOK_H */
