// CSCI 1300 Fall 2019
// Author: Weige Wong
// Recitation: 203 - Soumyajyoti Bhattacharya
// Project 2 - Problem 0-12

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include "Book.h"
#include "User.h"
#ifndef LIBRARY_H
#define LIBRARY_H
using namespace std;

class Library
{
  private:
  int sizeBook = 50;
  int sizeUser = 100;
  Book books[50];
  User users[100];
  int numBooks;
  int numUsers;
  
  public:
  Library();
  
  int getSizeBook();                                      
  int getSizeUser();
  int getNumBooks();
  int getNumUsers();
  int readBooks(string);                            //
  void printAllBooks();                             //                   
  void printBooksByAuthor(string);                  //
  int readRatings(string);                          //
  int getRating(string, string);                    //
  int getCountReadBooks(string);                    //
  void viewRatings(string, int);                    //
  double calcAvgRating(string);                     //
  double calcAvgRatingByAuthor(string);             //
  int addUser(string);                              //
  int checkOutBook(string, string, int);            //
  void getRecommendations(string);                  //
  
  int split(string temp[], char, int, string);
  string convertToLower(string);
  
  
};
#endif