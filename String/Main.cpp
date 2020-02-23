#include "String.cpp";
#include <iostream>

int main() {

	String* a = new String();
	String *b = new String('a');
	String *c = new String("abc");

	//cout << &b[1] << endl;

	if (*b  == *c  ) {
		cout <<b <<" == " <<c<< endl;
	}

	if (*b == "a") {
		cout<< b << " == "<< "a" << endl;
	}
	
	if (*b != *c) {
		cout << b << " != " << c << endl;
	}

	if (*b != "a") {
		cout << b << " != " << "a" << endl;
	}

	if (*c > *b) {
		cout << c<<" > "<< b << endl;
	}

	if (*b > *c) {
		cout << b << " > " << c << endl;
	}

	if (*c < * b) {
		cout << c << " < " << b << endl;
	}

	if (*b < * c) {
		cout << b << " < " << c << endl;
	}

	if (*c <= *b) {
		cout << c << " <= " << b << endl;
	}

	if (*b <= *c) {
		cout << b << " <= " << c << endl;
	}

	if (*c <= "abc") {
		cout << c << " <= " << "abc" << endl;
	}

	if (*c >= *b) {
		cout << c << " >= " << b << endl;
	}

	if (*b >= *c) {
		cout << b << " >= " << c << endl;
	}

	if (*c >= "abc") {
		cout << c << " >= " << "abc" << endl;
	}

	cout << a << endl;
	*a = *b;
	cout << a << endl;

	String* d = *b + *c;
	cout << d << endl;
	String* e = *b + "docica";
	cout << e << endl;

	String* k = new String("kkkk");
	cout << k->getLength()<<endl;
	//cout << "diga o valor de k: " << endl;
	//cin >> k;   
	//cout << k << endl;

	*k += *b;
	cout << k->getWord() << endl;


	return 0;
}