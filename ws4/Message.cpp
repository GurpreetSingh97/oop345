#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Message.h"

using namespace std;

namespace w5 {

	Message::Message(std::ifstream& in, char c) {
		string line;
		getline(in, line, c);

		istringstream is(line);

		if (username.empty()) {
			is >> username;
		}

		if (reply.empty()) {
			is >> reply;
			if ((int)reply.find('@')) { // if there is no @
				tweet = reply;

				string tempTweet;
				getline(is, tempTweet);
				tweet += tempTweet;
				
				reply.clear();		
			}
		}

		//just to remove the @ from rely beginning
		if (!reply.empty()) {
		string temp = reply.substr(1);
		reply = temp;
		}
	
		if (tweet.empty()) {
			// to remove one extra space
			string space;
			getline(is,space,' ');
			getline(is, tweet,c);
		}

		is.clear();
	}

	bool Message::empty() const {
		bool answer = false;
		if (tweet.empty()) {
	 		answer = true;
		}
		return answer;
	}
	void Message::display(std::ostream& os) const {
		os << "Message" << endl;
		os << "User  : " << username << endl;

		if (!reply.empty()) {
			os << "Reply : " << reply << endl;
		}

		os << "Tweet : " << tweet << endl;

	}

}