//
//  question.cpp
//  Assignment3
//
//  Created by Arvind Kumar on 1/28/20.
//  Copyright © 2020 Arvind Kumar. All rights reserved.
//

#include <stdio.h>
#include "Question.h"
#include <iostream>
#include <string>

string question;
string answer1;
string answer2;
string answer3;
string answer4;
unsigned short int correctAnswer;

//Default Constructors
Question::Question(){}

//Overloading Constructor
Question::Question(string question, string ans1, string ans2, string ans3, string ans4, unsigned short int correct)
{
    this->question = question;
    answer1 = ans1;
    answer2 = ans2;
    answer3 = ans3;
    answer4 = ans4;
    correctAnswer = correct;
    
}

//All setters for all the methods
void Question::setQuestion(string question)
{
    this->question = question;
}

void Question::setAnswer1(string ans)
{
    answer1 = ans;
}

void Question::setAnswer2(string ans)
{
    answer2 = ans;
}
void Question::setAnswer3(string ans)
{
    answer3 = ans;
}
void Question::setAnswer4(string ans)
{
    answer4 = ans;
}
void Question::setCorrect(unsigned short int correct)
{
    correctAnswer = correct;
}

//All getters for corresponding variables that return that variable when needed
string Question::getQuestion()
{
    return question;
}
string Question::getAnswer1()
{
    return answer1;
}
string Question::getAnswer2()
{
    return answer2;
}
string Question::getAnswer3()
{
    return answer3;
}
string Question::getAnswer4()
{
    return answer4;
}
unsigned short int Question::getCorrectAnswer()
{
    return correctAnswer;
}

