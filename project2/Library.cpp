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
#include "Library.h"
using namespace std;

Library::Library()
{
    numBooks = 0;
    numUsers = 0;
}

int Library::getSizeBook()
{
    return sizeBook;
}

int Library::getSizeUser()
{
    return sizeUser;
}

int Library::getNumBooks()
{
    return numBooks;
}

int Library::getNumUsers()
{
    return numUsers;
}

int Library::split(string temp[], char delimiter, int length, string line)
{
    int count = 0;
    string word = "";
	
	if(line == "")									    	                    //checks for a blank sentence
	{
	    return 0;
	}
	
	else
	{
	    line = line + delimiter;	        				                    //adds the delimiter to the end of the sentence so that the code can count the last word
	    
	    for(int i = 0; i < line.length(); i++)		    	                    //loops through the sentence
	    {
		    if(count >= length)								                    //checks if the sentence is broken up into more chunks than the array size
			{
			   	return -1;
			}
			
			if(line[i] == delimiter)				    	                    //checks if the sentence character is equal to the delimiter 
			{
			    if(word != "")								                    //checks if the word is blank
			    {
    			    temp[count] = word;				    	                    //assigns the word to an index in the array
        			count++;								                    //counts to move to the next array
        			word = "";							                    	//resets word to a blank string
			    }
			}
			  
    	  	else										                    	//if a sentence character doesn't equal the delimiter then it adds the character to the string word, as the loop goes through each character it builds the word again until it sees the delimiter
    		{
    		    word = word + line[i];
    		}
	    }
	    return count;
	}
}

string Library::convertToLower(string word)
{
    string newWord = "";
	string a;
	
	for(int i = 0; i < word.length(); i++)                                      //loops through the length of the word
	{
		a = tolower(word[i]);                                                   //gets each character and converts it to lowercase
		newWord += a;                                                           //rebuilds the word
	}
	return newWord;
}

int Library::readBooks(string fileName)
{
    string line = "";
    int i = numBooks;
        
    ifstream in_file(fileName);                                                 //open files
    
    if(i >= sizeBook)                                                           //checks if the number of books is already larger than the array size
    {
        return -2;
    }
        
    else if(in_file.is_open())                                                  //checks if the file opened properly
    {
        while(getline(in_file, line))                                           //goes line by line through the file
        {
            if(line != "")                                                      //checks if the line is empty
            {
                if(i == sizeBook)                                               //i is the counter for the number of lines and this checks if it becomes equal to the size of the array
                {
                    numBooks = i;
                    return i;
                }
                    
                string temp[2];                                                 //declares variables used for the split function
                int length = 2;
                char delimiter = ',';
                    
                split(temp, delimiter, length, line);                           //calls the split function
                    
                books[i].setAuthor(temp[0]);									//sets the author and title stored in the temp array into an index of the books array (which is a Books object)
                books[i].setTitle(temp[1]);
                i++;
            }
        }
        numBooks = i;
        return i;
    }
        
    else                                                                        //if the file fails to open
    {
        return -1;
    }
}

void Library::printAllBooks()
{
    if(numBooks <= 0)                                                           //checks if the number of books is 0 or less
    {
        cout << "No books are stored" << endl;        
    }
        
    else
    {
        cout << "Here is a list of books" << endl;                  
        
        for(int j = 0; j < numBooks; j++)                                       //loops through the books array (the number of books time) and prints the title and author at that index 
        {
            cout << books[j].getTitle() << " by ";
            cout << books[j].getAuthor() << endl;
    
        }
    }
}

void Library::printBooksByAuthor(string authorName)
{
    int counter = 0;
    
    if(numBooks <= 0)                                                               //checks if the number of books is under 0
    {
        cout << "No books are stored" << endl;
        return;
    }
    
    for(int i = 0; i < numBooks; i++)                                               //loops through the authors array to check if there are any matches
    {
        if(convertToLower(books[i].getAuthor()) == convertToLower(authorName)) 
        counter++;
    }
    
    if(counter < 1)                                                                 //checks to see if there are no matches
    {   
        cout << "There are no books by " << authorName << endl;
    }
    
    else
    {
        cout << "Here is a list of books by " << authorName << endl;
        
        for(int i = 0; i < numBooks; i++)                                           //loops through the authors array to check for matches and prints the titles that match with the index of the authors array
        {
            if(convertToLower(books[i].getAuthor()) == convertToLower(authorName))  //checks if the author at that array is the same as the user entered author name
            {
                cout << books[i].getTitle() << endl;                                //this prints the titles by that author
            }
        }
    }
}

int Library::readRatings(string fileName)
{
    int j = numUsers;
    int counter = 0;
    string line = "";
    ifstream inFile(fileName);													    //open file and declares it
    
    if(j >= sizeUser)														        //checks if the number of users is equal to or greater than the maximum number of spaces in the array
    {
   		return -2;
   	}
    
    else if(inFile.is_open())													    //check if the file opens properly
    {
        while(getline(inFile, line))											    //goes line by line
        {
        	if(line != "")														    //checks for an empty line
        	{
        		string temp[51];
	            char delimiter = ',';
	            int length = 51;
	            
	            counter = split(temp, delimiter, length, line);;				    //calls the split function
	            
	            users[j].setUsername(temp[0]);									    //since names will always be the index 0 set the users[] array at whatever index equal to temp at 0
	           
	            for(int i = 1; i < counter; i++)								    //the for loop goes through each column and sets it equal to the split array (starting at index 1 and going from there)
	            {
	            	users[j].setRatingAt(i-1, stoi(temp[i]));					    //at users[j] where j is counted only everytime we get a new line from the file, we set the rating starting at position 0 of the array and take the value from the temp array
	            }
	            j++;															    //counts users who rated
	            
	            if(j == sizeUser)											        //checks if the array is maxed out
			    {
			        numUsers = j;                                                   //sets the number of stored users to whatever j is so that the numUsers variable can be updated 
			    	return j;
			    }
        	}
        }
        numUsers = j;                                                           
        return j;
    }
    
    else
    {
        return -1;
    }
}

int Library::getRating(string username, string title)
{
    int id1 = 0;
	int foundUser = 0; // user found
	int id2 = 0;
	int foundBook = 0;
	
	for(int i = 0; i < numUsers; i++)											//goes through the entire users array in the Users class
	{
		if(convertToLower(users[i].getUsername()) == convertToLower(username))	//calls the convertToLower function while also checking if the username stored in the users array is the same as the username we're looking for
		{
			id1 = i;															//marks what index it's at
			foundUser++;														//my weird version of a bool
			break;
		}
	}
	
	for(int j = 0; j < numBooks; j++)											//loops through the stored books array
	{
		if(convertToLower(books[j].getTitle()) == convertToLower(title))		//converts titles to lowercase while checking if it matches our search query
		{
			id2 = j;															//marks the index where title was found
			foundBook++;														//my weird version of a bool
			break;
		}
	}
	
	if(foundUser == 0 || foundBook == 0)										// user or book not in the list if the counter increments to 1
	{
		return -3;
	}
	
	else
	{
		users[id1].setNumRatings(50);											//sets the number of ratings
		return users[id1].getRatingAt(id2);										//gets the user and their rating
	}
}

int Library::getCountReadBooks(string userName)
{
    int count = 0;
	int id1 = 0;
	int counter1 = 0; // user found
	int id2 = 0;
	int counter2 = 0;
	
	for(int i = 0; i < numUsers; i++)											//loops through all the users
	{
		if(convertToLower(users[i].getUsername()) == convertToLower(userName))	//converts to lowercase and then compares to see if the username matches
		{
			id1 = i;															//keeps track of the index
			counter1++;															//stays at 0 if there are no matches
			break;
		}
	}
	
	if(counter1 == 0 || numBooks == 0)                                          // user or book not in the list
	{
		return -3;
	}
	
	else
	{
		for(int k = 0; k < numBooks; k++)										//goes through all the book ratings stored in the array (uses stored books since that directly correlates with the number of book ratings)
		{
			if(users[id1].getRatingAt(k) != 0)									//checks if the rating for that user at that point isn't 0
			{
				count++;
			}
		}
		return count;
	}
}

void Library::viewRatings(string userName, int minRating)
{
    int id = 0;
    int count = 0;
    int count2 = 0;
    
    for(int i = 0; i < numUsers; i++)                                                           //loops through all the users and checks each username in that array to see if it matches up with the username we're looking for
    {
        if(convertToLower(users[i].getUsername()) == convertToLower(userName))  
        {
            id = i;                                                                             //stores the array index for that username when found 
            count++;
        }
    }
    
    if(count == 0)                                                                              //if counter doesn't increment, that means that no username was found
    {
        cout << userName << " does not exist." << endl; 
    }
    
    else                                                                                        //loops through all the ratings in the book array for the user we were looking for and sees if the ratings are greater than 0 and the minimum rating
    {
        for(int j = 0; j < numBooks; j++)
        {
            if(users[id].getRatingAt(j) >= minRating && users[id].getRatingAt(j) != 0)
            {
                count2++;                                                                       //if there is a valid rating, it counts it
                
                if(count2 == 1)                                                                 //executes if there are more than 0 matches
                {
                    cout << "Here are the books that " << userName << " rated" << endl;
                }
                
                if(users[id].getRatingAt(j) >= minRating && users[id].getRatingAt(j) != 0)      //loops through and prints the books and ratings we are looking for
                {
                    cout << "Title : " << books[j].getTitle() << endl;
                    cout << "Rating : " << users[id].getRatingAt(j) << endl;
                    cout << "-----" << endl;
                }
            }
        }
         
        if(count2 == 0)                                                                         //if there are no valid ratings
        {
            cout << userName << " has not rated any books yet." << endl;
        }
    }
}

double Library::calcAvgRating(string title)
{
    int checkTitle = 0;
    int arrayId = 0;
    int sum = 0;
    int counter = 0;
    double average = 0;
    
    for(int i = 0; i < numBooks; i++)
    {
        if(convertToLower(books[i].getTitle()) == convertToLower(title))        //loops through all the book titles to see if they match
        {
            arrayId = i;                                                        //stores the index where the book was found
            checkTitle++;                                                       
        }
    }
    
    if(checkTitle == 0 || numUsers <= 0)                                        //checks if there are no users or books found
    {
        return -3;
    }
    
    for(int j = 0; j < numUsers; j++)
    {
        if(users[j].getRatingAt(arrayId) != 0)                                  //loops through all the users but gets the book rating at the same index for every user and checks if it isn't 0
        {
            sum += users[j].getRatingAt(arrayId);                               //sums up the ratings
            counter++;                                                          //counts the number of ratings
        }
    }
    
    if(counter == 0)
    {
        return 0;
    }
    
    else
    {
        average = ((double)sum / (double)counter);                              //calculates the average
    }
    
    return average;
}

double Library::calcAvgRatingByAuthor(string author)
{
    double sum = 0;
    double counter = 0;
    double count = 0;
    double average;
    for(int i = 0; i < numBooks; i++)
    {
        if(convertToLower(books[i].getAuthor()) == convertToLower(author))      //loops through the author names to see if they match the one we are looking for
        {                    
            counter++;                                                          //counts when it finds one and stays at that author index

            for(int j = 0; j < numUsers; j++)                                   //loops through the users and gets the ratings for that author
            {
                if(users[j].getRatingAt(i) != 0)                                //if ratings aren't 0 then it adds them up and counts the number that it adds up
                {
                    sum += users[j].getRatingAt(i);
                    count++;
                }
            }
        }
    }
    
    if(counter == 0 || numUsers == 0)                                           //if there are no users or no ratings
    {
        return -3;
    }
    
    else if(sum == 0)                                                           //if all ratings sum to 0 so no users have rated the book
    {
        return 0;
    }
    
    else
    {
        average = ((double)sum / (double)count);                                //calculates the average
    }
    
    return average;
}

int Library::addUser(string username)
{
    for(int i = 0; i < sizeUser; i++)                                           //loops through the user array the number of users times and sees if any username matches the ones we are looking for
    {
        if(convertToLower(users[i].getUsername()) == convertToLower(username))
        {
            return 0;                                                           //returns 0 if the user is already present in the array
        }
    }
    
    if(numUsers >= sizeUser)                                                    //checks of the number of users stored is larger than the size of the array
    {
        return -2;
    }
    
    else
    {
        users[numUsers].setUsername(username);                                  //adds the username to the end of the array             
        numUsers++;                                                             //adds one to the total number of users
        return 1;
    }
}

int Library::checkOutBook(string userName, string title, int nrating)
{
    int uid = 0;
    int bid = 0;
    int check1 = 0;
    int check2 = 0;
    
    if(nrating > 5 || nrating < 0)                                              //checks if the rating is valid
    {
        return -4;
    }
    
    for(int i = 0; i < numUsers; i++)
    {
        if(convertToLower(users[i].getUsername()) == convertToLower(userName))  //goes through all the stored users to see if the username we are looking for exists in the array
        {
            uid = i;                                                            //stores the array index
            check1++;                                                           //adds one 
        }
    }
    
    for(int j = 0; j < numBooks; j++)
    {
        if(convertToLower(books[j].getTitle()) == convertToLower(title))        //goes through all the stored books to see if the title we are looking for exists
        {
            bid = j;                                                            //stores that array index
            check2++;                                                           //adds one
        }
    }
    
    if(check1 == 0 || check2 == 0)                                              //checks if no books or usernames were found
    {
        return -3;
    }
    
    else
    {
        users[uid].setRatingAt(bid, nrating);                                   //sets the new rating for the entered username and title
        return 1;
    }
}

void Library::getRecommendations(string username)
{
    int uid = 0;
    int bid = 0;
    int simUser = 0;
    double x = 0;
    double ssd = 0;
    int m = 50000;
    bool check1 = false;
    bool check2 = false;
    int counter = 0;
    int count = 0;
    
    for(int i = 0; i < numUsers; i++)
    {
        if(convertToLower(users[i].getUsername()) == convertToLower(username))          //checks if the username exits in the array
        {
            uid = i;                                                                    //stores the index where it was found
            check1 = true;
        }
    }
    
    if(check1 == false)                                                                 //checks to see if the username exists
    {
        cout << username << " does not exist." << endl;
    }
    
    else
    {
        for(int j = 0; j < numUsers; j++)                                               //loops through all the usernames 
        {
            ssd = 0;                                                                    //resets ssd to 0 for every user
            
            for(int k = 0; k < numBooks; k++)                                           //loops through the ratings for each individual user
            {
                x = pow((users[uid].getRatingAt(k) - users[j].getRatingAt(k)), 2.0);    //goes through each rating from every user and subtracts from each corresponding rating from the user we entered to search for then squares the difference
                ssd += x;                                                               //adds the values
            }
            
            if(ssd < m && ssd != 0)                                                     //checks for the smallest value excluding 0
            {
                simUser = j;                                                            //stores the index of that user with the smallest one
                m = ssd;                                                                //stores the smallest ssd
            }
        }
            
        for(int l = 0; l < numBooks; l++)                                               //loops through all the book ratings to find the first 5 0 ratings  
        {
            if(counter == 5)                                                            //stops this for loop if we print 5 times
            {
                return;
            }
            
            if(users[simUser].getRatingAt(l) >=3 && users[uid].getRatingAt(l) == 0)     //checks the user that has the lowest sim score for ratings greater than 3 and if the user entered username has a score at 0 at the same index
            {
                count++;
                counter++;                                                              //one counter keeps track of the times we print and the other checks to see if the if statement was fulfilled
                
                if(count == 1)                                                          //checks to see if one match was found
                {
                    cout << "Here is the list of recommendations" << endl;
                }
                
                cout << books[l].getTitle() << " by " << books[l].getAuthor() << endl;  //for every match print out the title and it's author
            }
        }
        
        if(count == 0)                                                                  //if no matches were found
        {
            cout << "There are no recommendations for " << username << " at present." << endl;
        }
    }
}