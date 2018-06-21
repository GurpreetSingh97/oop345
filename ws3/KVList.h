/*! Header guard to maintain one defination rule
*/
#ifndef KVLIST_H
#define KVLIST_H

/*template, it helps in using the same code for different data types 
*/
template<typename K, typename V, int N>
class KVList {
	
	/*!
	Key array and value array of same size but different data type to store data, the data types will be decided by the user
	*/
	K keyArr[N];
	V valArr[N];
	int count;
public:

/*!
constructor to set the member variables to safe empty state 
*/	
	KVList() {
		keyArr[0] = '\0';
		valArr[0] = '\0';
		count = 0;
	}
	
	/*! 
	This function return the number of element in the arrays
	*/
	size_t size() const {
		return count;
	}
	
	/*!
	It returns the element at the 'i'th index position of key Array
	*/
	const K& key(int i) const {
		return keyArr[i];
		
	}

	/*!
	It returns the element at the 'i'th index position of key Array
	*/
	const V& value(int i) const {
		return valArr[i];
	}


	/*!
	This function adds data to the parallel array at the end, till the maximum size is not reached in the array
	*/
	KVList& add(const K& k, const V& v) {
		if (count < N) {
			keyArr[count] = k;
			valArr[count] = v;
			count++;
		}
		return *this;
	}

	/*!
	This function return the index of array element which is equal to the given key
	*/
	int find(const K& k) const {
		int number = 0;
		for (int i = 0; i <count; i++) {
			if (keyArr[i] == k) {
				number = i;
				break;
			}
		}
		return number;
	}

	/*!
	This function replace the index at given postion in both the arrays with the given elements
	*/
	KVList& replace(int i, const K& k, const V& v) {
		keyArr[i] = k;
		valArr[i] = v;
		return *this;
	}


};

#endif