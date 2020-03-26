//
//  Question.h
//  Trivia
//
//  Created by Hellen Pacheco on 10/15/18.
//  Copyright © 2018 Hellen Pacheco. All rights reserved.
//

#ifndef Question_h
#define Question_h

#include <string>

using namespace std;

class Question {
private:
    string question;
    string answer1;
    string answer2;
    string answer3;
    string answer4;
    unsigned short int correctAnswer;

public:
    Question();
    Question(string question, string ans1, string ans2, string ans3, string ans4, unsigned short int correct);
    void setQuestion(string question);
    void setAnswer1(string ans);
    void setAnswer2(string ans);
    void setAnswer3(string ans);
    void setAnswer4(string ans);
    void setCorrect(unsigned short int correct);
    string getQuestion();
    string getAnswer1();
    string getAnswer2();
    string getAnswer3();
    string getAnswer4();
    unsigned short int getCorrectAnswer();
};
#endif /* Question_hpp */
