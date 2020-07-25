// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Project 2 - Problem 13

/*
1. Write a function that gives a user 13 options
2. Loop the menu and operations until option 13 is selected
3. If the user runs option 1 then run readBooks
4. If the user picks option 2 then run readRatings
5. If the user picks option 3 then run printAllBooks
6. If the user picks option 4 then run printBooksByAuthor
7. If the user picks option 5 then run getRatings
8. If the user picks option 6 then run getCountReadBooks
9. If the user picks option 7 then run viewRatings
10. If the user picks option 8 then run calcAvgRating
11. If the user picks option 9 then run calcAvgRatingsByAuthor
12. If the user picks option 10 then run addUser
13. If the user picks option 11 then run checkOutBook
14. If the user picks option 12 then run getRecommendations
15. If the user picks option 13 then quit
16. If the user enters an invalid option then output invalid option
Input: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, or 13; as well as any usernames, author names, books titles, or ratings needed for the corresponding programs (string and int types)
Output: the values that each respective function returns
Return: the values that each function returns

//Algorithm for new functions
viewRatings:
1. Write a function that take a minimum rating and a username 
2. Have it search through the users array to find where in the array that user is and store the index
3. If the user is not found, tell the user
4. If the user is found but none of the ratings are high enough then tell the user that 
5. Once those checks have been passed, then loop through every rating for that user and check that is above the minimum and not 0
6. For every one of those ratings, print title of the book and its rating
Input: username, rating (string, int)
Output: title, rating (string)
Return: nothing

calcAvgRatingsByAuthor:
1. This function works the same as the previous calcAvgRatings except that it takes an author's name and gets the average rating for every book by that author
2. Once it has an author name, search through the books array to find what index the author is at and store it
3. Once it is found, search through every rating that the author has made that isn't 0 and add them and count the number of times that happens
4. Then calculate the average
5. If the username is not found, return -3
6. If the user has not rating anything, return 0
Input: author (string)
Output: average rating (double)
Return: average rating (double), -3 or 0 for edge cases

addUser:
1. Write a function that takes a username and adds it to the array
2. Check that the user doesn't already exist
3. Then check that there is space in the array
4 If there is, go to the end of the array and add the username there and update the number of users
Input: username (string)
Output: nothing
Return: 1, 0, or -2 

checkOutBook:
1. Write a function that takes a username, book title, and a rating
2. First check if the rating is valid, if not return -4
3. Then check to see if the username exists and if so, store that index 
    a. If not, return -3
4. Then check if the title exists and if so, store that index
    a. If not, return -3
5. If the tests are passed, then add the new rating to that username and title
Input: username, title, rating (string, int)
Output: nothing
Return: 1, -4, or -3

getRecommendations:
1. Write a function that takes a username and recommends books for that username based off of a calculated similarity score
2. First check that the username exists and store that index
    a. If it doesn't then tell the user
3. If the user does exist, then start at the first user and subtract their rating from the rating of the user we entered at their respective index and square the difference
4. Add up all those to get the ssd
5. Repeat for all users and compare to get the lowest
    a. Ignore a ssd score of 0
6. Store the lowest ssd and the user who had it
7. Then loop through every rating for that user and look for scores 3 and above
8. At the same time, loop through the user we were given and look for scores that are 0 at the same index that the lowest ssd user had scores of 3 or above
9. Print the title and author at those points
10. If not, the say there are no recommendations
Input: username (string)
Output: title, author (string)
Return: nothing
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <iomanip>
#include <math.h>
#include "User.h"
#include "Book.h"
#include "Library.h"
using namespace std;

void project2()
{
    Library aLibrary;
    string n = "9";
    
    string bookFile;
    int fr = 0;
    
    string userFile;
    int ur = 0;
    
    string authorName;
    
    string userName;
    string title;
    int c = 0;
    
    string userN;
    int d = 0;
    
    string username;
    string minRating;
    
    string btitle;
    double e = 0;
    
    string authorN;
    double f = 0;
    
    string newUser;
    int g = 0;
    
    string user;
    string newTitle;
    string newRating;
    int h = 0;
    
    string anotherUser;
    
    while(stoi(n) != 13)
    {
        cout << "Select a numerical option:" << endl;
        cout << "======Main Menu=====" << endl;
        cout << "1. Read books" << endl;
        cout << "2. Read ratings" << endl;
        cout << "3. Print all books" << endl;
        cout << "4. Print books by author" << endl;
        cout << "5. Get rating" << endl;
        cout << "6. Find number of books user rated" << endl;
        cout << "7. View ratings" << endl;
        cout << "8. Get average rating" << endl;
        cout << "9. Get average rating by author" << endl;
        cout << "10. Add a user" << endl;
        cout << "11. Checkout a book" << endl;
        cout << "12. Get recommendations" << endl;
        cout << "13. Quit" << endl;
        
        getline(cin, n);                                                                            //so we can cin and ignore spaces
        
        switch(stoi(n))                                                                             //converts what we entered to int
        {
            case 1:
                cout << "Enter a book file name:" << endl;
                getline(cin, bookFile);                                                             //prompts for a username
                
                fr = aLibrary.readBooks(bookFile);                                                  //sets fr to the number of books returned by readBooks
                    
                if(fr == -1)                                                                        //if we get a -1 from the function
                {
                    cout << "No books saved to the database." << endl;
                }
                
                else if(fr == -2)                                                                   //checks if we got a -2 from the function
                {
                    cout << "Database is already full. No books were added." << endl;
                }
                
                else if(fr == 50)                                                                   //if the array is filled to exactly 50
                {                                                                                   //sets numBooksStored to 50 so we can keep track of the full array
                    cout << "Database is full. Some books may have not been added." << endl;
                }
                    
                else
                {                                                                                   //sets numBookStored to numBookStored so we can keep track of the number of books stored in the array
                    cout << "Total books in the database: " << fr << endl;
                }
                break;
            
            case 2:
                cout << "Enter a user file name:" << endl;
                getline(cin, userFile);
                
                ur = aLibrary.readRatings(userFile);                                                //same deal as fr just with a different function
                
                if(ur == -1)
                {
                    cout << "No users saved to the database." << endl;
                    break;
                }
                
                else if(ur == -2)
                {
                    cout << "Database is already full. No users were added." << endl;
                    break;
                }
                
                else if(ur == 100)
                {
                    cout << "Database is full. Some users may have not been added." << endl;
                    break;
                }
                
                else
                {
                    cout << "Total users in the database: " << ur << endl;
                }
                break;
                
            case 3:
                if(aLibrary.getNumBooks() == 0 || aLibrary.getNumUsers() == 0)                      //checks to see if the arrays are empty
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                
                else
                {
                    aLibrary.printAllBooks();
                    cout << endl;
                }
                break;
                
            case 4:
                if(aLibrary.getNumBooks() == 0 || aLibrary.getNumUsers() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                
                else
                {
                    cout << "Enter an author name: " << endl;
                    getline(cin, authorName);
                    
                    aLibrary.printBooksByAuthor(authorName);
                }
                break;
                
            case 5:
                if(aLibrary.getNumBooks() == 0 || aLibrary.getNumUsers() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                
                else
                {
                    cout<< "Enter a user name:" << endl;
                    getline(cin, userName);
                    
                    cout << "Enter a book title:" << endl;
                    getline(cin, title);
                    
                    c = aLibrary.getRating(userName, title);
                    
                    if(c == 0)
                    {
                        cout << userName << " has not rated " << title << endl;
                    }
                    
                    else if(c == -3)
                    {
                        cout << userName << " or " << title << " does not exist." << endl;
                    }
                    
                    else
                    {
                        cout << userName << " rated " << title << " with " << c << endl;
                    }
                }
                break;
                
            case 6:
                if(aLibrary.getNumBooks() == 0 || aLibrary.getNumUsers() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                
                else
                {
                    cout << "Enter a user name:" << endl;
                    getline(cin, userN);
                    
                    d = aLibrary.getCountReadBooks(userN);
                    
                    if(d == 0)
                    {
                        cout << userN << " has not rated any books." << endl;
                    }
                    
                    else if(d == -3)
                    {
                        cout << userN << " does not exist." << endl;
                    }
                    
                    else 
                    {
                        cout << userN << " rated " << d << " books." << endl;
                    }
                }
                break;
            
            case 7:
                if(aLibrary.getNumBooks() == 0 || aLibrary.getNumUsers() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                
                else
                {
                    cout << "Enter a user name:" << endl;
                    getline(cin, username);
                    
                    cout << "Enter a minimum rating:" << endl;
                    getline(cin, minRating);
                    
                    aLibrary.viewRatings(username, stoi(minRating));
                }
                break;
            
            case 8:
                if(aLibrary.getNumBooks() == 0 || aLibrary.getNumUsers() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                
                else
                {
                    cout << "Enter a book title:" << endl;
                    getline(cin, btitle);
                    
                    e = aLibrary.calcAvgRating(btitle);
                    
                    if(e == -3)
                    {
                        cout << btitle << " does not exist." << endl;
                    }
                    
                    else
                    {
                        cout << setprecision(5);
                        cout << "The average rating for " << btitle << " is " << (double) e << endl;
                    }
                }
                break;
                
            case 9:
                if(aLibrary.getNumBooks() == 0 || aLibrary.getNumUsers() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                
                else
                {
                    cout << "Enter an author name:" << endl;
                    getline(cin, authorN);
                    
                    f = aLibrary.calcAvgRatingByAuthor(authorN);
                    
                    if(f == -3)
                    {
                        cout << authorN << " does not exist." << endl;
                    }
                    
                    else
                    {
                        cout << "The average rating by " << authorN << " is " << f << endl;
                    }
                }
                break;
                
            case 10:
                cout << "Enter a user name:" << endl;
                getline(cin, newUser);
                    
                g = aLibrary.addUser(newUser);
                    
                if(g == -2)
                {
                    cout << "Database is already full. " << newUser << " was not added." << endl;
                }
                
                else if(g == 0)
                {
                    cout << newUser << " already exists in the database." << endl;
                }
                
                else if(g == 1)
                {
                    cout << "Welcome to the library " << newUser << endl;
                }
                break;
                
            case 11:
                if(aLibrary.getNumBooks() == 0 || aLibrary.getNumUsers() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                
                else
                {
                    cout << "Enter a user name:" << endl;
                    getline(cin, user);
                    
                    cout << "Enter a book title:" << endl;
                    getline(cin, newTitle);
                    
                    cout << "Enter a new rating:" << endl;
                    getline(cin, newRating);
                    
                    int nRate = stoi(newRating);
                    
                    f = aLibrary.checkOutBook(user, newTitle, nRate);
                    
                    if(f == -3)
                    {
                        cout << user << " or " << newTitle << " does not exist." << endl;
                    }
                    
                    else if(f == -4)
                    {
                        cout << newRating << " is not valid." << endl;
                    }
                    
                    else if(f == 1)
                    {
                        cout << "We hope you enjoyed your book. The rating has been updated." << endl;
                    }
                }
                break;
            
            case 12:
                if(aLibrary.getNumBooks() == 0 || aLibrary.getNumUsers() == 0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                
                else
                {
                    cout << "Enter a user name:" << endl;
                    getline(cin, anotherUser);
                    
                    aLibrary.getRecommendations(anotherUser);
                }
                break;
            
            case 13:
                cout << "Good bye!" << endl;
                break;
            
            default:
                cout << "Invalid input." << endl;
                break;
        }
        cout << endl;
    }
}

int main()
{
    project2();
}