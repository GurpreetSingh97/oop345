#include <iostream>
#include <fstream>
#include "Text.h"

using namespace std;

namespace w3 {

	Text::Text() {
		m_arr = nullptr;
		m_count  = 0;
	}

	Text::Text(const string filename)  {
		ifstream m_file(filename);

		if (m_file.is_open()) {
			int count = 0;
			string str;

			while (!m_file.fail()) {
				getline(m_file, str, '\n');
				count++;
			}
			
			m_file.clear();
			m_file.seekg(0, ios::beg);

			m_arr = new string[count];
			
			for (int i = 0; !m_file.fail(); i++) {
				getline(m_file, m_arr[i], '\n');
			}
			m_count = count;
			
			m_file.close();
		}
		else {
			Text();
		}
		
	}

	Text::Text(const Text& obj) {
		
		m_count = obj.m_count;
		
		if (obj.m_arr != nullptr) {
			
			m_arr = new string[m_count];

			for (int i = 0; i < m_count; i++) {
				m_arr[i] = obj.m_arr[i];
			}
		}
		else {
			m_arr = nullptr;
			
		}
	
	}

	Text& Text::operator=(const Text& obj) {
		if (this != &obj) {
			delete[] m_arr;
	
			m_count = obj.m_count;

			if (obj.m_arr != nullptr) {

				m_arr = new string[m_count];

				for (int i = 0; i < m_count; i++) {
					m_arr[i] = obj.m_arr[i];
				}
			}
			else {
				m_arr = nullptr;

			}

		}
		
		return *this;
	}

	


	Text::Text( Text&& obj) {
		m_count = obj.m_count;
		
		if (obj.m_arr != nullptr) {
			
			m_arr = new string[m_count];

			for (int i = 0; i < m_count; i++) {
				m_arr[i] = obj.m_arr[i];
			}
		}
		else {
			m_arr = nullptr;
			
		}
		
		obj.m_arr = nullptr;
		obj.m_count = 0;
		

	}

	Text&& Text::operator=( Text&& obj) {
		
		if (this != &obj) {
			delete[] m_arr;
			
			m_count = obj.m_count;

			if (obj.m_arr != nullptr) {

				m_arr = new string[m_count];

				for (int i = 0; i < m_count; i++) {
					m_arr[i] = obj.m_arr[i];
				}
			}
			else {
				m_arr = nullptr;

			}


		}
		
		return move(*this);
	}


	Text::~Text() {
		delete[] m_arr;
	}
	size_t Text::size() const {
		return m_count;
	}


}
