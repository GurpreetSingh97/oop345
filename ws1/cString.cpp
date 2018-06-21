#include <iostream>
#include <cstring>
#include "cString.h"

namespace w1 {

	

	cString::cString(char arr[]) {
		
		for (int i = 0; i < max_char; i++) {
			if (i == max_char-1) { // never enters into this,need to put -1
				m_char[i] = arr[i];
				m_char[max_char] = '\0';
			}
			else if (arr[i] != '\0') {
				m_char[i] = arr[i];
			}
			else {
				m_char[i] = '\0';
				break;
			}
		}
	}

	
	void cString::display(std::ostream& os) const {
		os << this->m_char;
	}

	
	std::ostream& operator<<(std::ostream& os,const cString& obj) {
		static int count = 0;
		os << count << ": ";
		obj.display(os);
		count++;
		return os;
	}

}