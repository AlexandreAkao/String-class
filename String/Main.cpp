#include "String.cpp";
#include <iostream>

int main() {

	String* a = new String();
	String* b = new String('a');
	String* c = new String("ab");

	cout << "String: " << a << " tamanho: " << a->getLength()<< endl;
	cout << "String: " << b << " tamanho: " << b->getLength() << endl;
	cout << "String: " << c << " tamanho: " << c->getLength() << endl;

	String d = 'a';
	String e = "b";
	String f = c;
	String g = d;


	cout << "String: " << d << " tamanho: " << d.getLength() << endl;
	cout << "String: " << e << " tamanho: " << e.getLength() << endl;
	cout << "String: " << f << " tamanho: " << f.getLength() << endl;
	cout << "String: " << g << " tamanho: " << g.getLength() << endl;
	
	cout <<d.getIndice('b') <<   endl;
	cout << c->getIndice('b') << endl;

	String* cases = new String("SaMuel");
	cout << cases->lowerCase(0, 5) << endl;
	cout << cases->toggleCase(0, 5) << endl;
	cout << cases->upperCase(0, 5) << endl;
	
	cout << d[0] << endl;

	if (b > e) {
		cout << "hello" << endl;
	}
	if (e > c) {
		cout << "hello" << endl;
	}
	if (c > d) {
		cout << "hello" << endl;
	}

	//if (d == b) {
	//	cout << "hello" << endl;
	//}
	//if (b == d) {
	//	cout << "hello" << endl;
	//}
	//if (d == e) {
	//	cout << "hello" << endl;
	//}
	//if (c != d) {
	//	cout << "hello" << endl;
	//}
	//if (b != f) {
	//	cout << "hello" << endl;
	//}
	//if (f != e) {
	//	cout << "hello" << endl;
	//}




	return 0;
}