//
//  main.cpp
//  Assignment3
//
//  Created by Arvind Kumar on 1/28/20.
//  Copyright © 2020 Arvind Kumar. All rights reserved.
//

#include <iostream>
#include "Question.h"
using namespace std;

int main() {
    //character that will collect the user input
    unsigned short int answer;
    //Counter for the number of questions correct
    int total = 0;
    
    //Initializing an array of size 10 full of Question objects
    Question arrayOfQuestions[10];
    
    
    //Giving all the array indexes an object to store
    arrayOfQuestions[0] = {"#1.) What's 9+10", "1.) 21", "2.) 19", "3.) 5", "4.) -1", 2};
    arrayOfQuestions[1] = {"#2.) What's the biggest planet in our solar system.", "1.) Pluto", "2.) Mars", "3.) Earth", "4.) Jupiter", 4};
    arrayOfQuestions[2] = {"#3.) What is the term for a nine sided object?", "1.) Octagon", "2.) Septagon", "3.) Nonagon", "4.) Decagon", 3};
    arrayOfQuestions[3] = {"#4.) What is the smallest island country?", "1.) Naura", "2.) Palau", "3.) Malta", "4.) Tuvalu", 1};
    arrayOfQuestions[4] = {"#5.) What is the official language of Cambodia?", "1.) Khmer", "2.) Burmese", "3.) Thai", "4.) English", 1};
    arrayOfQuestions[5] = {"#6.) What is Mario's brother's name?", "1.) Antonio", "2.) Waluigi", "3.) Lucas", "4.) Luigi", 4};
    arrayOfQuestions[6] = {"#7.) Michael Jordan played for which team?", "1.) Spurs", "2.) Bulls", "3.) Celtics", "4.) Lakers", 2};
    arrayOfQuestions[7] = {"#8.) What is the square root of 144?", "1.) 14", "2.) 13", "3.) 12", "4.) 11", 3};
    arrayOfQuestions[8] = {"#9.) Summer officially starts on which day?", "1.) February 21st", "2.) June 20th", "3.) July 20th", "4.) Today", 2};
    arrayOfQuestions[9] = {"#10.) What year was Google Founded?", "1.) 1996", "2.) 2010", "3.) 1998", "4.) 1976", 3};
    

    /*Iterating through and calling getter methods to display
     questions and answer choices for the trivia, then collecting
     the input and comparing them to the right answer.*/
    for(int i = 0; i < 10; i++)
    {
        cout << arrayOfQuestions[i].getQuestion() << endl
        << arrayOfQuestions[i].getAnswer1() << endl
        << arrayOfQuestions[i].getAnswer2() << endl
        << arrayOfQuestions[i].getAnswer3() << endl
        << arrayOfQuestions[i].getAnswer4() << endl
        << "Enter your answer: ";
        
        cin >> answer;
        
        if(answer == arrayOfQuestions[i].getCorrectAnswer())
        {
            total+=1;
        }
        else
        {
            cout << "INCORRECT! Correct answer is: " << arrayOfQuestions[i].getCorrectAnswer() << endl;
        }
    }

    //returning the number of questions correct
    cout <<"You got a total of " << total << " questions correct." << endl;
    
    return 0;
}


/*
 #1.) What's 9+10
 1.) 21
 2.) 19
 3.) 5
 4.) -1
 Enter your answer: 2
 #2.) What's the biggest planet in our solar system.
 1.) Pluto
 2.) Mars
 3.) Earth
 4.) Jupiter
 Enter your answer: 1
 INCORRECT! Correct answer is: 4
 #3.) What is the term for a nine sided object?
 1.) Octagon
 2.) Septagon
 3.) Nonagon
 4.) Decagon
 Enter your answer: 3
 #4.) What is the smallest island country?
 1.) Naura
 2.) Palau
 3.) Malta
 4.) Tuvalu
 Enter your answer: 1
 #5.) What is the official language of Cambodia?
 1.) Khmer
 2.) Burmese
 3.) Thai
 4.) English
 Enter your answer: 1
 #6.) What is Mario's brother's name?
 1.) Antonio
 2.) Waluigi
 3.) Lucas
 4.) Luigi
 Enter your answer: 2
 INCORRECT! Correct answer is: 4
 #7.) Michael Jordan played for which team?
 1.) Spurs
 2.) Bulls
 3.) Celtics
 4.) Lakers
 Enter your answer: 3
 INCORRECT! Correct answer is: 2
 #8.) What is the square root of 144?
 1.) 14
 2.) 13
 3.) 12
 4.) 11
 Enter your answer: 3
 #9.) Summer officially starts on which day?
 1.) February 21st
 2.) June 20th
 3.) July 20th
 4.) Today
 Enter your answer: 1
 INCORRECT! Correct answer is: 2
 #10.) What year was Google Founded?
 1.) 1996
 2.) 2010
 3.) 1998
 4.) 1976
 Enter your answer: 1
 INCORRECT! Correct answer is: 3
 You got a total of 5 questions correct.
 Program ended with exit code: 0
 */
