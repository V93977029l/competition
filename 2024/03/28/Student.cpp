#pragma
#include "Student.h"
#include <iostream>

using std::cout;
using std::endl;

void Student::display()
{
	cout << "学号:" << num		<< endl;
	cout << "姓名:" << name		<< endl;
	cout << "语文:" << score1 	<< endl;
	cout << "数学:" << score2 	<< endl;
	cout << "英语:" << score3 	<< endl;
}
