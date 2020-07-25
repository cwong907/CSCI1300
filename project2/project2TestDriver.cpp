#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include "User.h"
#include "Book.h"
#include "Library.h"
using namespace std;

int main()
{
    Library aLibrary;
    
    cout << aLibrary.getSizeBook() << endl;
    
    cout << aLibrary.getSizeUser() << endl;
    
    cout << "# of books in file: " << aLibrary.readBooks("books.txt") << endl;
    
    cout << "Gets numBooks: " << aLibrary.getNumBooks() << endl;
    
    aLibrary.printAllBooks();
    cout << endl;
    
    aLibrary.printBooksByAuthor("Douglas Adams");
    cout << endl;
    
    cout << "# of users in file: " << aLibrary.readRatings("ratings.txt") << endl;
    
    cout << aLibrary.getRating("joan", "The Golden Compass") << endl;
    
    cout << "Gets number of users: " << aLibrary.getNumUsers() << endl;
    
    cout << "# of books rated " << aLibrary.getCountReadBooks("joan") << endl;
    
    aLibrary.viewRatings("joan", 4);
    
    cout << aLibrary.calcAvgRating("The Golden Compass") << endl;
    
    cout << aLibrary.calcAvgRatingByAuthor("Douglas Adams") << endl;
    
    cout << aLibrary.addUser("joan") << endl;
    
    cout << aLibrary.checkOutBook("joan", "The Golden Compass", 5) << endl;
    
    aLibrary.getRecommendations("joan");
}