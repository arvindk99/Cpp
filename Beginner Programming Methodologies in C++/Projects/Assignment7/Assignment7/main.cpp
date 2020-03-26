/*
 NAME: Arvind Kumar
 EMAIL: arvindskumar01@gmail.com
 LAB: 7
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;
#define MAX 1000



int getData(ifstream& inFile, string uni[], string state[], string city[], int tuition[], int enrollment[], double retention[], double gradRate[]);
void output(ofstream& outFile, string uni[], string state[], string city[], int tuition[], int enrollment[], double retention[], double gradRate[], int numUnis);
double avgTuition(int tuition[], int numUnis);
void affordableSchools(string uni[], int tuition[], int numUnis);
void searchByState(ofstream& outFile, string uni[], string state[],int numUnis);
int lowestTuition(int tuition[], int numUnis);
void sortSelect(ofstream& outFile, string uni[], string state[], string city[], int tuition[], int enrollment[], double retention[], double gradRate[], int numUnis);

int main() {
    string uni[MAX];
    string state[MAX];
    string city[MAX];
    int tuition[MAX];
    int enrollment[MAX];
    double retention[MAX];
    double gradRate[MAX];
    
    int numUnis;
    double avg;
    int subscript;
    
    ifstream inFile;
    ofstream outFile;
    
    
    inFile.open("universities.txt");
    outFile.open("Lab7.txt");

    if(inFile.fail())
    {
        cout << "No such file." << endl;
    }
    
    numUnis = getData(inFile, uni, state, city, tuition, enrollment, retention, gradRate);

    outFile << "****************************************BEFORE SORTING************************************" << endl;
    output(outFile, uni, state, city, tuition, enrollment, retention, gradRate, numUnis);
    
    
    avg = avgTuition(tuition, numUnis);
    cout << setprecision(2) << fixed << endl;
    cout << "The average tuition prices for all of these are: $" << avg << endl;
    
    
    affordableSchools(uni, tuition, numUnis);

    
    searchByState(outFile, uni, state, numUnis);
    
    cout << "\n\nHere are the college(s) with the lowest tuition on file." << endl;
    subscript = lowestTuition(tuition, numUnis);
    cout << "Lowest tuition: " << tuition[subscript] << endl;
    for(int i = 0; i < numUnis; i++)
    {
        if(tuition[i] == tuition[subscript])
        {
            cout << uni[i] << endl;
        }
    }
    
    
    sortSelect( outFile, uni, state, city, tuition, enrollment, retention, gradRate, numUnis);
    outFile << "****************************************AFTER SORTING************************************" << endl;
    output(outFile, uni, state, city, tuition, enrollment, retention, gradRate, numUnis);
    
    inFile.close();
    outFile.close();
    return 0;
}// MAIN



int getData(ifstream& inFile, string uni[], string state[], string city[], int tuition[], int enrollment[], double retention[], double gradRate[])
{
    /*
      PRE - inFile - input file
            uni[] - array of university names
            state[] - array of university states
            city[] - array of city states
            tuition[] - array of university tuitions
            enrollment[] - array of university enrollment rate
            retention[] - array of university retention rate
            gradRate[] - array of university graduation in 6 years rate
    POST - return number of universities
    PURPOSE - count the number of universities
     */
    int count = 0;
    char ch = '\n';
    double acceptRate[MAX];
    while( count < MAX && !inFile.eof())
    {
    
        //Uni name
        getline(inFile, uni[count], ch);
        
        inFile >> state[count];
        inFile.get(ch);
        
        
        getline(inFile, city[count]);


        inFile >> tuition[count] >> enrollment[count] >> acceptRate[count] >> retention[count] >> gradRate[count];
        inFile.get(ch);
        inFile.ignore();
        
        retention[count] *= 100;
        gradRate[count] *= 100;
        
        count++;

    }
    
    return count;
}

void output(ofstream& outFile, string uni[], string state[], string city[], int tuition[], int enrollment[], double retention[], double gradRate[], int numUnis)
{
    /*
      PRE - outFile - output file
            uni[] - array of university names
            state[] - array of university states
            city[] - array of city states
            tuition[] - array of university tuitions
            enrollment[] - array of university enrollment rate
            retention[] - array of university retention rate
            gradRate[] - array of university graduation in 6 years rate
            numUnis - number of universities
    POST - nothing
    PURPOSE - output to a file the data of universities
     */
    outFile << setprecision(2) << fixed << endl;
    outFile << setw(37) << left << "University" << setw(5) << right << "State" << setw(9) << right << "Tuition" << setw(8) << right << " Enrollment" << setw(9) << right << "%Fresh"<<setw(13) << right << "%Gradeuate" << endl << setw(72) << right << "Succeed" << setw(15) << right << "in six years" << endl;
    
    for(int i = 0; i < numUnis; i++)
    {
        outFile << setw(37) << left << uni[i];
        outFile << setw(5) << right << state[i];
        outFile << setw(9) << right << tuition[i];
        outFile << setw(11) << right << enrollment[i];
        outFile << setw(9) << right <<  retention[i] << "%";
        outFile << setw(9) << right << gradRate[i] << "%" << endl;
    }
    
}

double avgTuition(int tuition[], int numUnis)
{
    /*
      PRE - tuition[] - array of university tuitions
            numUnis - number of universities
    POST - returns the avg tuition rate
    PURPOSE - find the average tuition rate
     */
    double sum = 0.0;
    double avg;
    for(int i = 0; i < numUnis; i++)
    {
        sum += tuition[i];
    }
    avg  = sum/numUnis;
    return avg;
}

void affordableSchools(string uni[], int tuition[], int numUnis)
{
    /*
      PRE - uni[] - array of university names
            tuition[] - array of university tuitions
            numUnis - number of universities
    POST - nothing
    PURPOSE - find the affordable schools under one's budget
     */
    int affordable;
    cout << "\n\nEnter the tuition amount you can afford: ";
    cin >> affordable;
    cout << "\nThe schools you can afford are the following: " << endl;
    for(int i = 0; i < numUnis; i++)
    {
        if(tuition[i] <= affordable)
        {
            cout << uni[i] << endl;
        }
    }
}

void searchByState(ofstream& outFile, string uni[], string state[],int numUnis)
{
    /*
    PRE -   outFile - output file
            uni[] - array of university names
            state[] - array of university states
            numUnis - number of universities
    POST - nothing
    PURPOSE - find all the universities in a particular state
    */
    string stateSearch;
    cout <<"\n\nEnter a state to look at colleges from there: ";
    cin >> stateSearch;
    outFile << "\n\n****************************************SEARCHING BY STATE************************************" << endl;
    outFile << "\nTHESE ARE THE COLLEGES IN THE STATE YOU LOOKED UP" << endl;
    int count = 0;
    
    for(int i = 0; i < numUnis; i++)
    {
        if(state[i] == stateSearch)
        {
            outFile << uni[i] << endl;
            count++;
        }
    }
    
    if (count == 0)
    {
        outFile << "\nNo schools were found in " << stateSearch << "state" << endl;
    }
    
}


int lowestTuition(int tuition[], int numUnis)
{
    /*
      PRE - tuition[] - array of university tuitions
            numUnis - number of universities
    POST - subscript for the lowest tuition
    PURPOSE - find the subscript of the lowest tuition
     */
    int subscript = 0;
    int lowest = 1000000000;
    for(int i =0; i < numUnis; i++)
    {
        if(tuition[i] < lowest)
        {
            lowest = tuition[i];
            subscript = i;
        }
    }
    
    return subscript;
}


void sortSelect(ofstream& outFile, string uni[], string state[], string city[], int tuition[], int enrollment[], double retention[], double gradRate[], int numUnis)
{
    /*
      PRE - outFile - output file
            uni[] - array of university names
            state[] - array of university states
            city[] - array of city states
            tuition[] - array of university tuitions
            enrollment[] - array of university enrollment rate
            retention[] - array of university retention rate
            gradRate[] - array of university graduation in 6 years rate
            numUnis - number of universities
    POST - nothing
    PURPOSE - sort by enrollment
     */
    int current; int walker;
    int smallestIndex;
    int tempInt;
    double tempDouble;
    string tempStr;
   
    for (current = 0; current < numUnis - 1; current++)
    {
        smallestIndex = current;
        for (walker = current; walker < numUnis; walker ++)
          {
                if (enrollment[walker] < enrollment[smallestIndex])
                  smallestIndex = walker;
          }//for walker
       
        //Swap to position smallest at what is the current position
        
        tempStr = uni[current];
        uni[current] = uni[smallestIndex];
        uni[smallestIndex] = tempStr;
        
        tempStr = state[current];
        state[current] = state[smallestIndex];
        state[smallestIndex] = tempStr;
        
        tempStr = city[current];
        city[current] = city[smallestIndex];
        city[smallestIndex] = tempStr;
        
        tempInt = enrollment[current];
        enrollment[current] = enrollment[smallestIndex];
        enrollment[smallestIndex] = tempInt;
        
        tempInt = tuition[current];
        tuition[current] = tuition[smallestIndex];
        tuition[smallestIndex] = tempInt;
        
        tempDouble = retention[current];
        retention[current] = retention[smallestIndex];
        retention[smallestIndex] = tempDouble;
        
        tempDouble = gradRate[current];
        gradRate[current] = gradRate[smallestIndex];
        gradRate[smallestIndex] = tempDouble;
    }//for current
  return;
}


/*

 The average tuition prices for all of these are: $44399.50


 Enter the tuition amount you can afford: 40000

 The schools you can afford are the following:
 University of California-Berkeley
 University of California-Los Angeles


 Enter a state to look at colleges from there: CA


 Here are the college(s) with the lowest tuition on file.
 Lowest tuition: 25064
 University of California-Berkeley
 University of California-Los Angeles
 Program ended with exit code: 0
 
 */
