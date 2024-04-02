// Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using std::string;

class Student
{
public:
	Student(string num, string name, int s1, int s2, int s3) : num(num), name(name), score1(s1), score2(s2), score3(s3) {};

private:
	string num;
	string name;
	int score1 = 0;
	int score2 = 0;
	int score3 = 0;

public:
	int average() const { return score1 + score2 + score3; }
	void display();                          
};

#endif
