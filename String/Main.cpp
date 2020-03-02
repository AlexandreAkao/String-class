#include "String.cpp"
#include <iostream>
#include <locale.h> 

int main() {
	setlocale(LC_ALL, "");
	cout << endl << endl << endl << endl;

	cout << "|------------------|" << endl;
	String* a = new String();
	cout << "| Valor de a: " << a << "     |" << endl;
	cout << "| Tamanho de a: " << a->getLength() << "  |" << endl;

	cout << "|------------------|" << endl;
	String* b = new String('a');
	cout << "| Valor de b: " << b << "    |" << endl;
	cout << "| Tamanho de b: " << b->getLength() << "  |" << endl;

	cout << "|------------------|" << endl;
	String* c = new String("abc");
	cout << "| Valor de c: " << c << "  |" << endl;
	cout << "| Tamanho de c: " << c->getLength() << "  |" << endl;

	cout << "|------------------|" << endl;
	String* e = new String("abcd");
	cout << "| Valor de d: " << e << " |" << endl;
	cout << "| Tamanho de d: " << e->getLength() << "  |" << endl;
	cout << "|------------------|" << endl;
	cout << endl << endl << endl << endl << endl << endl << endl;

	String* k = new String();

	cout << "|---------------------------------------|" << endl;
	cout << "|              Operador ==              |" << endl;
	cout << "|---------------------------------------|" << endl;
	cout << "|   == com String   | == com const char |" << endl;
	cout << "|     *b == *c      |     *b == 'a'     |" << endl;
	cout << "|                 b = " << b << "                 |" << endl;
	cout << "|      c = " << c << "      |                   |" << endl;

	if (*b == *c) {
		cout << "|       TRUE        |";
	} else {
		cout << "|       FALSE       |";
	}
	if (*b == "a") {
		cout << "       TRUE        |" << endl;
	}
	else {
		cout << "       FALSE       |" << endl;
	}

	cout << "|---------------------------------------|" << endl;
	cout << endl << endl << endl << endl << endl << endl;

	cout << "|---------------------------------------|" << endl;
	cout << "|              Operador !=              |" << endl;
	cout << "|---------------------------------------|" << endl;
	cout << "|   != com String   | != com const char |" << endl;
	cout << "|     *b != *c      |     *b != 'a'     |" << endl;
	cout << "|                 b = " << b << "                 |" << endl;
	cout << "|      c = " << c << "      |                   |" << endl;

	if (*b != *c) {
		cout << "|       TRUE        |";
	}
	else {
		cout << "|       FALSE       |";
	}
	if (*b != "a") {
		cout << "       TRUE        |" << endl;
	}
	else {
		cout << "       FALSE       |" << endl;
	}

	cout << "|---------------------------------------|" << endl;
	cout << endl << endl << endl << endl << endl << endl;

	cout << "|---------------------------------------|" << endl;
	cout << "|              Operador >               |" << endl;
	cout << "|---------------------------------------|" << endl;
	cout << "|    > com String   |  > com const char |" << endl;
	cout << "|     *b > *c       |     *b > 'a'      |" << endl;
	cout << "|                 b = " << b << "                 |" << endl;
	cout << "|      c = " << c << "      |                   |" << endl;

	if (*b > *c) {
		cout << "|       TRUE        |";
	}
	else {
		cout << "|       FALSE       |";
	}
	if (*b > "a") {
		cout << "       TRUE        |" << endl;
	}
	else {
		cout << "       FALSE       |" << endl;
	}

	cout << "|---------------------------------------|" << endl;
	cout << endl << endl << endl << endl << endl << endl;

	cout << "|---------------------------------------|" << endl;
	cout << "|              Operador <               |" << endl;
	cout << "|---------------------------------------|" << endl;
	cout << "|    < com String   |  < com const char |" << endl;
	cout << "|     *b < *c       |     *b < 'a'      |" << endl;
	cout << "|                 b = " << b << "                 |" << endl;
	cout << "|      c = " << c << "      |                   |" << endl;

	if (*b < *c) {
		cout << "|       TRUE        |";
	}
	else {
		cout << "|       FALSE       |";
	}
	if (*b < "a") {
		cout << "       TRUE        |" << endl;
	}
	else {
		cout << "       FALSE       |" << endl;
	}

	cout << "|---------------------------------------|" << endl;
	cout << endl << endl << endl << endl << endl << endl;

	cout << "|---------------------------------------|" << endl;
	cout << "|              Operador <=              |" << endl;
	cout << "|---------------------------------------|" << endl;
	cout << "|    <= com String  | <= com const char |" << endl;
	cout << "|     *b <= *c      |     *b <= 'a'     |" << endl;
	cout << "|                 b = " << b << "                 |" << endl;
	cout << "|      c = " << c << "      |                   |" << endl;

	if (*b <= *c) {
		cout << "|       TRUE        |";
	}
	else {
		cout << "|       FALSE       |" ;
	}

	if (*b <= "a") {
		cout << "       TRUE        |" << endl;
	}
	else {
		cout << "       FALSE       |" << endl;
	}

	cout << "|---------------------------------------|" << endl;
	cout << endl << endl << endl << endl << endl << endl;

	cout << "|---------------------------------------|" << endl;
	cout << "|              Operador >=              |" << endl;
	cout << "|---------------------------------------|" << endl;
	cout << "|    >= com String  | >= com const char |" << endl;
	cout << "|     *b >= *c      |     *b >= 'a'     |" << endl;
	cout << "|                 b = " << b << "                 |" << endl;
	cout << "|      c = " << c << "      |                   |" << endl;

	if (*b >= *c) {
		cout << "|       TRUE        |";
	}
	else {
		cout << "|       FALSE       |";
	}
	if (*b >= "a") {
		cout << "       TRUE        |" << endl;
	}
	else {
		cout << "       FALSE       |" << endl;
	}

	cout << "|---------------------------------------|" << endl;
	cout << endl << endl << endl << endl << endl << endl;


	cout << "Diga o valor de k: ";
	cin >> k;
	int tamanho = k->getLength();
	cout << "Valor de k: " << k << endl;
	cout << "Tamanho de k: " << tamanho << endl << endl << endl;

	String* h = new String("Hello");
	String* w = new String(" world");

	cout << "*h += w" << endl;
	cout << "Valor de h: " << h << endl;
	cout << "Valor de w: " << w << endl;
	*h += w;
	cout << "Novo valor de h: " << h << endl;
	cout << "Novo tamanho de h: " << h->getLength() << endl << endl << endl;

	String* o = new String("Oi, ");

	cout << "*o += 'tudo bom ?'" << endl;
	cout << "Valor de o: " << o << endl;
	*o += "tudo bom ?";
	cout << "Novo valor de o: " << o << endl;
	cout << "Novo tamanho de o: " << o->getLength() << endl << endl << endl;


	cout << "*a = *c" << endl;
	cout << "Valor de a: " << a << endl;
	cout << "Valor de c: " << c << endl;
	*a = *c;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  	cout << a << endl;
	cout << "Novo valor de a: " << a << endl << endl << endl;

	cout << "*a = 'Opa Eriko'" << endl;
	cout << "Valor de a: " << a << endl;
	*a = "Opa Eriko";
	cout << "Novo valor de a: " << a << endl << endl << endl;

	char q = (*e)[0];
	char p = (*e)[1];

	cout << "Na string E: " << e << ", a letra na primera posicao é: " << q << endl;
	cout << "Na string E: " << e << ", a letra na segunda posicao é: " << p << endl;

	int t = k->getIndice('b');
	int y = k->getIndice('p');

	cout << "Na string K: "<< k<< ", b está na posição : " << t << endl;
	cout << "Na string K: " << k << ", p está na posição : " << y << endl;

	String* toUpper = new String("alou");
	cout << "Na string K: " << toUpper << ", upper case " << toUpper->upperCase(0,2) << endl;
	String* toLower = new String("ALOU");
	cout << "Na string K: " << toLower << ", upper case " << toLower->lowerCase(0, 2) << endl;

	String* toToggle = new String("AlOu");
	cout << "Na string K: " << toToggle << ", upper case " << toToggle->toggleCase(0, 2) << endl;


	return 0;
}