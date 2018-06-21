#include <iostream>
#include <string>
#include <fstream>
#include "Grades.h"

using namespace std;

Grades::Grades(const char* fileName) {

	try {
		ifstream in(fileName);

		if (in.fail()) {
			throw "Oops, the file cannot be open!!!";
		}
		else {
			count = 0;
			string tempNumber;
			string tempGrade;

			while (in.good()) {
				getline(in, tempNumber, ' ');
				getline(in, tempGrade, '\n');

				number.push_back(tempNumber);
				grade.push_back(atof(tempGrade.c_str())); // atof() function to convert a String into a number(double)
				count++;
			}
		}
	}
	catch (string err) {
		cout << err << endl;
	}







}


