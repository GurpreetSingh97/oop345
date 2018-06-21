/*!
Header guard to maintain one-defination rule
*/
#ifndef GRADES_H
#define GRADES_H

#include <iostream>
#include <vector>

using namespace std;

/*!
Grades class to store the id and the marks of the students
*/
class Grades {
	vector <string> number;
	vector <double> grade;
	int count;
public:

	/*!
	Constructor to copy the data from the given file to the class
	*/
	Grades(const char* fileName);

	/*!
	Display function which send the StudentId and their numbers to the output
	*/
	template<typename func>
	void displayGrades(std::ostream &os, func exp) const
	{
		for (int i = 0; i < count; i++)
		{
			auto letter = exp(grade[i]);
			os << number[i].c_str() << " " << grade[i] << " " << letter << std::endl;
		}
	}

	/*!
	=Delete to prohibits copying, moving or assigning of a Grades object
	*/
	Grades& operator=(const Grades& obj) = delete;
	Grades&& operator=(Grades&& obj) = delete;
	Grades(const Grades& obj) = delete;
	Grades(Grades&& obj) = delete;

};

#endif 