  /*
   *         Name: Josh Woolbright
   *         Date: 3/27/2019
   *  Description: This program reads from a file conaining a list
   *               of books and stores them. It allows the user to print
   *               the whole list or search for a specific book by isbn.
   *
   */

  #include "warehouse.h"

  int main (int argc, char* argv[]) {
   
    Warehouse warehouse;
    Book book;

    if (argc > 1) {

      string filename = argv[1];

      if (argc > 2) {

        string command = argv[2];

        if (command == "list" && argc == 3) {

          warehouse.list(filename, warehouse);
          return 0;
        }
        else if (command == "find" && argc == 4) {

          string isbn = argv[3];
          warehouse.find(filename, isbn, book);
        }
        else {
          cout << "Error: Unrecognized Command Line Statement" << endl;
        }
      }

      else {
        cout << "Error: Unrecognized Command Line Statement" << endl;
      }
    }

    else {
       cout << "Error: Unrecognized Command Line Statement" << endl;
    }
  }


