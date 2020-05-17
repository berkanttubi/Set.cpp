#ifndef SET_H
#define SET_H

#include <iostream>
using namespace std;

template <class alpha>

class Set
{
private:
	int capacity;
	alpha *container;
	int  numberOfvalues;

public:
	Set() {
		capacity = 10;
		numberOfvalues = 0;
		container = new alpha [capacity];
	}
	Set(int x) {
		capacity = x;
		container = new alpha[capacity];
	}
	~Set() {
		delete[] container;
	}
	Set(const Set& x) {
	
		container = new alpha[x.capacity];

		for (int i = 0; i < x.numberOfvalues; i++) 
			container[i] = x.container[i];
				
		numberOfvalues = x.numberOfvalues;
		capacity = x.capacity;
		

		
	}
	void addElement(alpha element) {
		
		int valid = 1;
		if (numberOfvalues <=capacity) {
			for (int i = 0; i < numberOfvalues; i++) {
				for (int j = 0; j < numberOfvalues; j++) {
					if (element == container[j])
						valid = 0;
				}
			}

			if (valid) {
				container[numberOfvalues] = element;
				numberOfvalues++;
			}
		}
		else
			cout << "You don't have enough memory to do that!" << endl;
	}
	int removeElement(alpha element) {		
		int valid = 1;
		int counter=0;
		for (int i = 0; i < numberOfvalues; i++) {
			for (int j = 0; j < numberOfvalues; j++) {
				if (element == container[j]) {
					valid = 1;
					counter = j;
					break;
				}
			}
				
		}
		
		if (valid) {
			for (int i = counter; i < numberOfvalues ; i++)
				container[i] = container[i+1];
			numberOfvalues--;
			return 1;
		}
		
		
		
		return 0;
		

	}


	Set operator+(const Set& x) {
		
		alpha a;
		
		Set <alpha> temp(x.capacity);		
		
		for (int i = 0; i < numberOfvalues; i++) {
			temp.addElement(container[i]);
		}
		for (int i = 0; i < x.numberOfvalues; i++) {
			temp.addElement(x.container[i]);
		}		
		
		return temp;
	}
	Set operator-(Set& x) {
		
		alpha a;

		Set <alpha> temp(x.capacity);



		

		for (int i = 0; i < numberOfvalues; i++) {
			temp.addElement(container[i]);
		}
		for (int i = 0; i < x.numberOfvalues; i++) {
			temp.addElement(x.container[i]);
		}
		
		

		for (int i = 0; i < x.numberOfvalues; i++)
			temp.removeElement(x.container[i]);		

		return temp;
	}
	int operator==(const Set& x) {
		int valid = 1;

		for (int i = 0; i < numberOfvalues; i++) {
			for (int j = 0; j < x.numberOfvalues; j++)
			{
				if (container[i] != x.container[j])
					valid = 0;
				else
					valid = 1;
			}
		}

		if (valid)
			return 1;
		return 0;
	}
	int operator!=(const Set& x) {
		int valid = 1;

		for (int i = 0; i < numberOfvalues; i++) {
			for (int j = 0; j < x.numberOfvalues; j++)
			{
				if (container[i] == x.container[j])
					valid = 0;
				else
					valid = 1;
			}
		}

		if (valid)
			return 1;
		return 0;
	}
	void operator=(Set& x) {
		int i = 0;
		capacity = x.capacity;
		numberOfvalues = x.numberOfvalues;
		for ( i = 0; i < x.numberOfvalues; i++) {
			container[i] = x.container[i];
		}		
	}
	Set operator+=(const Set& x) {

		alpha a;

		Set <alpha> temp(x.capacity);

		for (int i = 0; i < numberOfvalues; i++) {
			temp.addElement(container[i]);
		}
		for (int i = 0; i < x.numberOfvalues; i++) {
			temp.addElement(x.container[i]);
		}
		numberOfvalues = temp.numberOfvalues;
		for (int i = 0; i < temp.numberOfvalues; i++) {
			container[i] = temp.container[i];
		}



		return temp;


	}
	int operator<(const Set&x) {
		int counter = 0;
		for (int i = 0; i < x.numberOfvalues; i++) {
			for (int j = 0; j < numberOfvalues; j++) {
				if (x.container[i] == container[j])
					counter += 1;
			}	
		}

		if (counter == numberOfvalues)
			return 1;
		return 0;

	}
	friend ostream& operator << (ostream& o, const Set& x) {
		o << "{";
		for (int i = 0; i < x.numberOfvalues; i++) {
		
			o << x.container[i] << ",";
		}
		o << "}";
		return o;
	}
		
	
	friend istream& operator>>(istream& input , Set& x) {

		alpha z ;

		for (int i = x.numberOfvalues; i < x.capacity; i++) {
			
			cout << x.numberOfvalues+1 << ".element: ";
			input >> z;

			x.addElement(z);
			
		}
			
	
		return input;
	}
	
};



#endif // !SET_H
