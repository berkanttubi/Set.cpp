/* It is just for testing to the codes, sample run */


#include <iostream>
#include "Set.h"

using namespace std;



int main() {
	
	
	
	Set<int> s;
	int x = 8;
	s.addElement(x);
	for (int i = 0; i < 4; i++)
		s.addElement(i + 6);
	cout << "s: " << s << endl;
	Set<char> s2;
	cout << "s2: " << s2 << endl;
	s2.addElement('a');
	cout << "s2 after adding 'a': " << s2 << endl;
	s2.addElement('b');
	cout << "s2 after adding 'b':" << s2 << endl;
	cout << "fill s2 with cin>>" << endl;
	cin >> s2;
	cout << "s2 after cin>>:" << s2 << endl;
	Set<int> a(s);
	a.removeElement(8);
	
	cout << "a: " << a << endl;
	
	Set <int> b;
	for (int i = 0; i < 5; i++)
		b.addElement(i + 6);
	b.addElement(20);
	cout << "b: " << b << endl;
	cout << "union b+a: " << (b + a) << endl;
	cout << "b: " << b << endl;
	cout << "a: " << a << endl;
	cout << "diff a-b: " << (a - b) << endl;
	cout << "b: " << b << endl;
	cout << "a: " << a << endl;
	cout << "diff b-a: " << (b - a) << endl;
	cout << "b: " << b << endl;
	cout << "a: " << a << endl;
	
	Set<int> d(a);
	cout << "equal d==a: " << (d == a) << endl;
	cout << "equal a==b: " << (a == b) << endl;
	cout << "not equal a!=b: " << (a != b) << endl;
	a.removeElement(6);
	cout << "a after removing 6: " << a << endl;
	cout << "d after a" << d << endl;
	a = d;
	cout << "a after a=d: " << a << endl;
	s += b;
	cout << "s+=b: " << s << endl;
	cout << "a<b: " << (a < b) << endl;
	cout << "a<d: " << (a < d) << endl;
	cout << "b: " << b << endl;
	cout << "a: " << a << endl;
	cout << "d: " << d << endl;
	
	return 0;
}
