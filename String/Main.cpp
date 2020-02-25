#include "String.cpp";
#include <iostream>

int main() {
	String* a = new String();
	String* b = new String('a');
	String* c = new String("abc");
	String* e = new String("abcd");

	String* k = new String();


	cout << "== com String" << endl;
	if (*b == *c) {
		cout << "b == c"<< endl;
	}

	cout << "== com const char" << endl;
	if (*b == "a") {
		cout << "b é igual a 'a'"<< endl;
	} 
	
	if (*b != *c) {
		cout << "b != c"<< endl;
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


	cout << "Diga o valor de K" << endl;
	cin >> k;
	int tamanho = k->getLength();
	cout << "String K : " << k << endl;
	cout << "tamanho K : " << tamanho << endl;

	*e += c;
	cout << e << endl;
	cout << e->getLength() << endl;


	*b += "tudo bom ?";
	cout << b << endl;
	cout << b->getLength() << endl;

	*a = *c;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  	cout << a << endl;

	*a = "Opa Eriko";
	cout << a << endl;

	char q = (*k)[0];
	cout << q << endl;

	// T.T

	return 0;
}