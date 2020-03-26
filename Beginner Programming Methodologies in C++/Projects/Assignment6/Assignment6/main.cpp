/*
 NAME: Arvind Kumar
 ID: 20372024
 EMAIL: arvindskumar01@gmail.com
 LAB: 6
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

double calculations(double, double, double, double, double, double);

int main(int argc, const char * argv[]) {
    
    double groceries, housing, utilities, transportation, health, misc;
    double cIndex;
    double max = 0.0;
    double min = 255.0;
    string city, maxCity, minCity;
    char ch = '\n';
    
    //Initializing and opening input file
    ifstream inFile;
    inFile.open("costIndex.txt");
    //initializing and opening output file
    ofstream outFile;
    outFile.open("lab6.txt");
    
    //To catch error if file doesn't exist
    if(inFile.fail() == 1)
    {
        cout << "No Such File" << endl;
        exit(100);
    }
    //Else, collect input from the file, and output to output file
    else{
        //While it is not yet the end of the file
        while(!inFile.eof())
        {
            //We collect the names of the city with getline
            getline(inFile, city);
            //The rest is just inFile or the nickname we gave to the input file
            inFile >> groceries >> housing >> utilities >> transportation >> health >> misc;
            //To count for the white spaces between each input
            inFile.get(ch);
            
            //calculates the composite index for all the cities
            cIndex = calculations(groceries, housing, utilities, transportation, health, misc);
            
            //Prints data to the output file
            outFile << setprecision(1) << fixed << endl;
            outFile << city << endl;
            outFile << "composite Index: " << setw(10) << right << cIndex << endl;
            //Telling the loop to ignore the white spaces and continue reading through
            inFile.ignore();
            
            //Looks for highest composite index
            if(cIndex >= max)
            {
                max = cIndex;
                maxCity = city;
            }
            //Looks for lowest composite index
            if(cIndex <= min)
            {
                min = cIndex;
                minCity = city;

            }
            
        }
        //Closes input file because no longer needed
        inFile.close();
        cout << setprecision(1) << fixed << endl;
        //Output highest and lowest composite indeces to screen
        cout << "\n\nHIGHEST composite Index: " << maxCity << setw(10) << right << max << endl;
        cout << "\nLOWEST composite Index: " << minCity << setw(10) << right << min << "\n" <<endl;
        
        //Output highest and lowest composite indeces to output file
        outFile << "\n\nHIGHEST composite Index: " << maxCity << setw(10) << right << max << endl;
        outFile << "\nLOWEST composite Index: " << minCity << setw(10) << right << min << "\n" <<endl;
        
        //Signature
        cout << "Created by Arvind Kumar" << endl;
        
        //Closes output file
        outFile.close();
        
        return 0;
    }
    
    
    
    
}

double calculations(double groceries, double housing, double utilities, double transportation, double health, double misc)
{
    /*
     PRE -  groceries- income spent on groceries
            housing- income spent on housing
            utilities- income spent on utilities
            transportation- income spent on transportation
            health- income spent on health
            misc- income spent on miscellaneous items
     POST - returns the composite Index
     PURPOSE- calculate the composite Index
     */
    double cIndex;
    
    cIndex = (groceries*.13)+(housing*.29)+(utilities*.10)+(transportation*.12)+(health*.12)+(misc*.24);
    
    return cIndex;
}


/*
 HIGHEST composite Index: New, York, (Manhattan), NY
     214.19

 LOWEST composite Index: Pryor, Creek, OK
     84.027
 
 Created by Arvind Kumar
 Program ended with exit code: 0
 */
