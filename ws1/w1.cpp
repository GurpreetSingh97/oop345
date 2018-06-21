#include <iostream>
#include "process.h"
#include "cString.h"

using namespace std;
using namespace w1;
/*!
main function which receives the integer argc and argv[] array, which are size of the arguments passed 
into the program from the command line and the array of arguments respectively.
*/
int main(int argc, char* argv[]) {

	cout << "Command Line : w1";
	
	for (int j = 1; j < argc; j++) {
		cout << " " << argv[j];
	}
	cout << endl;
		/*!
		if condition checks, if the number of arguments provided by user is zero then gives error message and returns 0.
		*/
	if (argc == 1) {
		cout << "Insufficient number of arguments (min 1)" << endl;
		return 1;
	}
	/*!
	else condition checks, if the number of arguments provided by user is not zero then mention the max max_char and returns 0.
	*/
	else {
		/*!
		   the for loop that iterate through all the arguments provided by command line and process on them to get cString objects
		*/

		cout << "Maximum number of characters stored : " << max_char << endl;
		for (int i = 1; i < argc; i++) {
			process(argv[i]);
		}
		return 0;
	}
}