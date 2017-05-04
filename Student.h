//
// Created by 田植成 on 17/4/10.
//

#ifndef UNTITLED_STUDENG_H
#define UNTITLED_STUDENG_H

#include <iostream>
#include <string>
using namespace std;

struct Student{
    string name;
    int score;

    bool operator >(const Student &otherStudent){
        return score < otherStudent.score;
    }
    friend ostream& operator<<(ostream &os,Student &student){
        os<< "Student:" << student.name <<" " << student.score <<endl;
        return os;
    }
};
#endif

