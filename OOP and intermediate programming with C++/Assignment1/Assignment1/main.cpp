/*
 Lab 1 - Program that reads a text file containing a list of movies, stores the movie titles into vectors then prints them out.
 Name - Arvind Kumar
 Date - 01/07/2020
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

void print(vector<string> movieTitles);


/* Main opens and stores all the movie titles into a vector using a while loop. Then it uses the sort method to sort the movie titles alphabetically, then it calls the print function with the vectors as a parameter to print everything out.
 
    Returns- nothing.*/
int main(int argc, const char * argv[]) {
    string title;
    string line; //used to collect the lines from the file which can be later separated to get titles
    
    string filename;
    ifstream inFile; //input file that carries movie details
    
    bool truth = false;
    
    vector<string> movieTitles;

    while(truth == false)
    {
        cout << "Please enter your file name: " << endl;
        cin >> filename;
        inFile.open(filename);
        if(inFile.fail() == 1)
        {
            cout << "No Such File" << endl << endl;
        }
        
        else {
            truth = true;
            while(!inFile.eof())
            {
                getline(inFile, line);
                stringstream ss(line);
                getline(ss, title, ',');
                movieTitles.push_back(title);
            }
        }
    }
    
    
    sort(movieTitles.begin(), movieTitles.end());
    print(movieTitles);
    inFile.close();
    return 0;
}

/* Void method that prints the movie titles stored in the vector
 
    Returns- nothing, prints the movie titles.*/
void print(vector<string> movieTitles) {
    //
    for(auto i = movieTitles.begin(); i != movieTitles.end(); ++i)
    {
        cout << *i << endl;
    }
}

/*
 Please enter your file name:
 enter
 No Such File

 Please enter your file name:
 Movie_entries.txt

 A Thousand Words
 Avengers: Age of Ultron
 Captain America: The Winter Soldier
 Chungking Express
 Earthlings
 Ghost in the Shell
 Gone Girl
 Guardians of the Galaxy
 Happy Feet
 Inglourious Basterds
 Interstellar
 Kung Fu Hustle
 Limitless
 Mean Girls
 Saving Private Ryan
 Superbad
 Surf's Up
 The Great Escape
 The Matrix
 Under the Tuscan Sun
 Whiplash
 Zoolander
 Program ended with exit code: 0
 */
