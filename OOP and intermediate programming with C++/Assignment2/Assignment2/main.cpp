/*
Lab 2 - Program that reads a text file containing a list of movies and their information, stores the movie informtion into vectors then prints them out depending on the way the user wants to sort the structures.
Name - Arvind Kumar
Date - 01/22/2020
*/

#include<iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

void input(ifstream&, vector<struct Movies>&);
void print(vector<Movies> cinema);
bool compareByTitle( Movies movie1,  Movies movie2);
bool compareByGenre( Movies movie1,  Movies movie2);
bool compareByDirector( Movies movie1,  Movies movie2);
void sortByDirector(Movies movie1, Movies movie2, bool compareByDirector);

struct Movies {
    string title;
    string director;
    string genre;
    int releaseYear;
    int runTime;
};

/*
 Main is in charge of the UI aspect and calls the necessary methods to collect input, sort, and print out the vector full of structures containing movie information.
 
 Returns- nothing.
 */
int main(int argc, const char * argv[]) {
    vector<Movies> cinema;
    ifstream inFile; //input file
    string sortType;
    
    input(inFile, cinema);
    
    cout << "Would you like the movies sorted by Genre, Director, or Title?" << endl;
    cin >> sortType;
    
    if(sortType == "director" || sortType == "Director")
    {
        sort(cinema.begin(), cinema.end(), compareByDirector);
    }
    else if (sortType == "genre" || sortType == "Genre")
    {
        sort(cinema.begin(), cinema.end(), compareByGenre);
    }
    else if(sortType == "title" || sortType == "Title")
    {
        sort(cinema.begin(), cinema.end(), compareByTitle);
    }
    
    print(cinema);

    return 0;
}

/*
 void method that collects the input from the file and populates the values
 of the structures and pushes them into the vector
 
 returns - nothing, just loads the vector with values
 */
void input(ifstream& inFile, vector<Movies>& cinema)
{
    bool truth = false;
    string filename;
    string line;//used to collect the lines from the file which can be later separated to get titles
    string year;
    string time;
    Movies movie;

    while(truth == false)
    {
        cout << "Please enter your file name: " << endl;
        cin >> filename;
        inFile.open(filename);
        if(inFile.fail() == 1)
        {
            cout << "No Such File" << endl << endl;
        }
        else
        {
            truth = true;
            cout << "File Found!" << endl;
            
            while(!inFile.eof())
            {
                //Collecting input and populating specific variables of the structure
                getline(inFile, line);
                stringstream ss(line);
                getline(ss, movie.title, ',');
                getline(ss, movie.director, ',');
                getline(ss, movie.genre, ',');
                getline(ss, year, ',');
                getline(ss, time, ',');
                
                //Stoi methods convert from string to int after collecting in string format
                movie.releaseYear = stoi(year);
                movie.runTime = stoi(time);
                
                cinema.push_back(movie);
            }
        }
    }
}
/* Bool method that compares the movie titles of two structures

Returns - True or false
*/
bool compareByTitle(Movies movie1, Movies movie2)
{ return movie1.title < movie2.title; }

/* Bool method that compares the Genre of two structures

Returns - True or false
*/
bool compareByGenre(Movies movie1, Movies movie2)
{ return movie1.genre < movie2.genre; }

/* Bool method that compares the directors of two structures
 
 Returns - True or false
 */
bool compareByDirector(Movies movie1, Movies movie2)
{ return movie1.director < movie2.director; }

/* Void method that prints the movie information stored in the vector

   Returns- nothing, prints the movie information.*/
void print(vector<Movies> cinema) {
    cout << endl;
    for (auto &element : cinema)
    {
        cout << element.title << ", " << element.director << ", " << element.genre << ", " << element.releaseYear << ", " << element.runTime << endl;
    }
    
    cout << endl;

}


/*
 ****************TEST 1: SORTING BY TITLE****************
 Please enter your file name:
 Movie_entries.txt
 File Found!
 Would you like the movies sorted by Genre, Director, or Title?
 Title

 , Steven Spielberg, drama, 1998, 120
 A Thousand Words, Brian Robbins, comedy, 2012, 91
 Avengers: Age of Ultron, Joss Whedon, science fiction, 2015, 120
 Captain America: The Winter Soldier, Russo, science fiction, 2014, 120
 Chungking Express, Kai Wai Wong, drama, 1994, 98
 Earthlings, Shaun Monson, documentary, 2005, 95
 Ghost in the Shell, Mamoru Oshii, manga, 1995, 82
 Gone Girl, David Fincher, mystery, 2014, 129
 Guardians of the Galaxy, James Gunn, fantasy, 2014, 120
 Happy Feet, George Miller, comedy, 2006, 108
 Inglourious Basterds, Quentin Tarantino, drama, 2009, 120
 Interstellar, Christopher Nollan, science fiction, 2014, 160
 Kung Fu Hustle, Stephen Chow, fantasy, 2004, 99
 Limitless, Neil Burger, thriller, 2011, 105
 Mean Girls, Mark Waters, comedy, 2004, 97
 Saving Private Ryan, Steven Spielberg, drama, 1998, 120
 Superbad, Gret Mottola, comedy, 2007, 113
 Surf's Up, Chris Buck, adventure, 2007, 85
 The Great Escape, John Sturges, thriller, 1963, 172
 The Matrix, Andy Wachowski, fantasy, 1999, 136
 Under the Tuscan Sun, Audrey Wells, drama, 2003, 113
 Whiplash, Damien Chazelle, drama, 2014, 106
 Zoolander, Ben Stiller, comedy, 2001, 105

 Program ended with exit code: 0
 
 
 ****************TEST 2: SORTING BY Genre****************
 Please enter your file name:
 Movie_entries.txt
 File Found!
 Would you like the movies sorted by Genre, Director, or Title?
 Genre

 Surf's Up, Chris Buck, adventure, 2007, 85
 Mean Girls, Mark Waters, comedy, 2004, 97
 Happy Feet, George Miller, comedy, 2006, 108
 Zoolander, Ben Stiller, comedy, 2001, 105
 A Thousand Words, Brian Robbins, comedy, 2012, 91
 Superbad, Gret Mottola, comedy, 2007, 113
 Earthlings, Shaun Monson, documentary, 2005, 95
 , Steven Spielberg, drama, 1998, 120
 Inglourious Basterds, Quentin Tarantino, drama, 2009, 120
 Saving Private Ryan, Steven Spielberg, drama, 1998, 120
 Whiplash, Damien Chazelle, drama, 2014, 106
 Chungking Express, Kai Wai Wong, drama, 1994, 98
 Under the Tuscan Sun, Audrey Wells, drama, 2003, 113
 The Matrix, Andy Wachowski, fantasy, 1999, 136
 Kung Fu Hustle, Stephen Chow, fantasy, 2004, 99
 Guardians of the Galaxy, James Gunn, fantasy, 2014, 120
 Ghost in the Shell, Mamoru Oshii, manga, 1995, 82
 Gone Girl, David Fincher, mystery, 2014, 129
 Captain America: The Winter Soldier, Russo, science fiction, 2014, 120
 Interstellar, Christopher Nollan, science fiction, 2014, 160
 Avengers: Age of Ultron, Joss Whedon, science fiction, 2015, 120
 Limitless, Neil Burger, thriller, 2011, 105
 The Great Escape, John Sturges, thriller, 1963, 172

 Program ended with exit code: 0
 
 
 ****************TEST 3: SORTING BY Director****************
 Please enter your file name:
 Movie_entries.txt
 File Found!
 Would you like the movies sorted by Genre, Director, or Title?
 Director

 The Matrix, Andy Wachowski, fantasy, 1999, 136
 Under the Tuscan Sun, Audrey Wells, drama, 2003, 113
 Zoolander, Ben Stiller, comedy, 2001, 105
 A Thousand Words, Brian Robbins, comedy, 2012, 91
 Surf's Up, Chris Buck, adventure, 2007, 85
 Interstellar, Christopher Nollan, science fiction, 2014, 160
 Whiplash, Damien Chazelle, drama, 2014, 106
 Gone Girl, David Fincher, mystery, 2014, 129
 Happy Feet, George Miller, comedy, 2006, 108
 Superbad, Gret Mottola, comedy, 2007, 113
 Guardians of the Galaxy, James Gunn, fantasy, 2014, 120
 The Great Escape, John Sturges, thriller, 1963, 172
 Avengers: Age of Ultron, Joss Whedon, science fiction, 2015, 120
 Chungking Express, Kai Wai Wong, drama, 1994, 98
 Ghost in the Shell, Mamoru Oshii, manga, 1995, 82
 Mean Girls, Mark Waters, comedy, 2004, 97
 Limitless, Neil Burger, thriller, 2011, 105
 Inglourious Basterds, Quentin Tarantino, drama, 2009, 120
 Captain America: The Winter Soldier, Russo, science fiction, 2014, 120
 Earthlings, Shaun Monson, documentary, 2005, 95
 Kung Fu Hustle, Stephen Chow, fantasy, 2004, 99
 Saving Private Ryan, Steven Spielberg, drama, 1998, 120
 , Steven Spielberg, drama, 1998, 120

 Program ended with exit code: 0
 
 
 
 */
