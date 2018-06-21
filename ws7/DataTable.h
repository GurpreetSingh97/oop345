/*!
Header guard to maintian the one defination rule
*/

#ifndef DATA_TABLE_H
#define DATA_TABLE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>
#include <fstream>
#include <utility>
#include <sstream>

using namespace std;

namespace w8{
	/*!
	A template class named, DataTable, which consist of two vectors containers
	and two integers
	*/
	template<class T>
	class DataTable{

		vector<T> x;
		vector<T>y;
		int width;
		int decimals;

	public:

		/*!
		This function extract the inforamtion from the file and store the in the member variable of the class
		*/
		DataTable(std::ifstream& is, int width, int decimals) : width(width), decimals(decimals){
			
			while (is.good()){
				
				string str;
				getline(is, str);

				// This inserts the content of the string into the stringstream object
				stringstream ss;

				// if line is not blank, return a respective product, else return nullptr
				if (!str.empty()){
					ss.str(str);

					T tempX;
					T tempY;
					ss >> tempX >> tempY;

					x.push_back(tempX);
					y.push_back(tempY);
				}
			}
		}



		/*!
		Mean function finds the mean of the dependent coordinates and return the value
		*/

		T mean() const{
			T temp = accumulate(y.begin(), y.end(), 0.0);
			return temp / y.size();
		}


		/*!
		This function is used to get the standard deviation of the dependent Coordinates
		*/
		T sigma() const{

			T deviation = 0.0;
			T tempMean = mean();

			for (int i = 0; i < y.size(); i++) {
				deviation += (y[i] - tempMean) * (y[i] - tempMean);
			}
			
			return sqrt(deviation / y.size());
		}


		/*!
		This function is used to get the mediam values of the dependent coordinates
		*/
		T median() const{
			vector<T> temp = y;

			sort(temp.begin(),temp.end());

			T median = temp[temp.size() / 2];

			return median;
		}



		/*!
		Regerssion function returns the slope and the intercept for the data provided
		*/
		void regression(T& slope, T& y_intercept) const{
			
			T avgerageOfX = accumulate(x.begin(), x.end(), 0.0) / x.size();
			T avgerageOfY = accumulate(y.begin(), y.end(), 0.0) / y.size();

			T denominator = 0.0;
			T numerator = 0.0;
			
			for (int i = 0; i<x.size(); i++){

				denominator += (x[i] - avgerageOfX) * (x[i] - avgerageOfX);
      			numerator += (x[i] - avgerageOfX) * (y[i] - avgerageOfY);			
			}

			slope = numerator / denominator;
			
			y_intercept = avgerageOfY - (slope * avgerageOfX);
		}


		/*!
		This function is used to display the pairs of data from the vector (i.e 'x' & 'y')
		*/
		void display(std::ostream& os) const{
			os << setw(width) << "x"<< setw(width) << "y" << endl;

			for (int i = 0; i < x.size(); i++){
				os << setw(width) << fixed << setprecision(decimals) << x[i] << setw(width) << fixed << setprecision(decimals) << y[i] << endl;
			}
		}


	};


	/*!
	A helper function which puts the data extracted from display() function into the ostream object
	*/
	template<class T>
	std::ostream& operator<<(std::ostream& os, const DataTable<T>& obj){
		obj.display(os);
		return os;
	}
}

#endif