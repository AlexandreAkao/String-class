#include <iostream>
using namespace std;

class String {
public:

	String() {
		this->length = 0;
		this->word = new char('\0');
	}	

	String(char new_char){
		char* aux = new char[2];
		aux[0] = new_char;
		aux[1] = '\0';
		this->length = 1;
		this->word = aux;
	}
	
	String(const char* new_char) {
		this->length = CharLength(new_char);
		char* aux = new char[length + 1];
		for (int i = 0; i < length; i++) {
			aux[i] = new_char[i];
		}
		aux[length] = '\0';

		this->word = aux;
	}

	int getLength() const {
		return this->length;
	}

	const char* getWord() const {
		return this->word;
	}

	int getIndice(char letra) {
		for (int i = 0; i < length; i++) {
			if (word[i] == letra) {
				return i;
			}
		}
		return -1;
	}

	char* upperCase(int i0, int i1) {
		if ((i0 < 0) || (i1 >= length)) 
			throw "posicao invalida";
		

		char* aux = new char[length + 1];

		for (int i = 0; i < length; i++) {
				if (i >= i0 && i <= i1) {
					if (word[i] >= 'a' && word[i] <= 'z') {
						aux[i] = word[i] - 32;
					}
					else {
						aux[i] = word[i];
					}
				}
				else {
					aux[i] = word[i];
				}
	
		}
		aux[length] = '\0';

		return aux;
	}

	char* lowerCase(int i0, int i1) {
		if (i0 < 0 || i1 >= this->length)
			throw "posicao invalida";

		char* aux = new char[length+1];

		for (int i = 0; i < length; i++) {
			if (i >= i0 && i <= i1) {
				if (word[i] >= 'A' && word[i] <= 'Z') {
					aux[i] = word[i] + 32;
				}
				else {
					aux[i] = word[i];

				}
			}
			else {
				aux[i] = word[i];
			}

		}
		aux[length] = '\0';

		return aux;

	}

	char* toggleCase(int i0, int i1) {
		if (i0 < 0 || i1 >= this->length) {
			throw "posicao invalida";
		}

		char* aux = new char[length+1];

		for (int i = 0; i < length; i++) {
			if (i >= i0 && i <= i1) {
				if (word[i] >= 'A' && word[i] <= 'Z') {
					aux[i] = word[i] + 32;
				}
				else if (word[i] >= 'a' && word[i] <= 'z') {
					aux[i] = word[i] - 32;
				}
				else {
					aux[i] = word[i];

				}
			}
			else {
				aux[i] = word[i];
			}

		}

		aux[length] = '\0';
		return aux;

	}

	char operator [] (int index) {
		if (this->length == 0) {
			throw "String vazia";
		}
		else if (index < 0 || index > this->length) {
			throw "posicao nao valida";
		}
		return word[index];
	}

	bool operator == (const String& string) {	
		return equalsComparation(string);
	}

	bool operator == (const char* string) {
		return equalsComparation(string);
	}

	bool operator != (const String& string) {
		return !equalsComparation(string);
	}

	bool operator != (const char* string) {
		return !equalsComparation(string);
	}



	void operator = (const String* string) {
		delete this;

		memcpy(this, string, sizeof(*string));

	}
	void operator = (const char* string) {
		delete this;
		String* aux = new String(string);
		memcpy(this, aux, sizeof(*aux));

	}


	void operator += (const String* string) {
		String* aux = ConcatString(string->getWord());
		delete this;

		memcpy(this, aux, sizeof(*aux));
	}

	void operator += (const char* string) {
		String* aux = ConcatString(string);

		delete this;

		memcpy(this, aux, sizeof(*aux));
	}

	bool operator > (const String& string) {
		return greaterThanComparation(string);
	}

	bool operator > (const char* string) {
		return greaterThanComparation(string);
	}

	bool operator < (const String& string) {
		return lesserThanComparation(string);
	}

	bool operator < (const char* string) {
		return lesserThanComparation(string);
	}

	bool operator <= (const String& string) {
		return lesserThanOrEqualsComparation(string);
	}

	bool operator <= (const char* string) {
		return lesserThanOrEqualsComparation(string);
	}

	bool operator >= (const String& string) {
		return greaterThanOrEqualsComparation(string);
	}

	bool operator >= (const char* string) {
		return greaterThanOrEqualsComparation(string);
	}

	String* operator + (const String& string) {
		return ConcatString(string);
	}

	String* operator + (const char* string) {
		return ConcatString(string);
	}

	friend ostream& operator << (ostream& out, String* c) {
		out << c->getWord();
		return out;
	}

	friend istream& operator >> (istream& in, String* string) {
		char* a= new char[10];
		in >> a;
		String* aux = new String(a);
		delete string;
		memcpy(string, aux, sizeof(*aux));
		return in;
	}

	~String() {
		delete(word);
	}

private:
	const char* word;
	int length;

	String* ConcatString(const String& string) {

		int size = length + string.getLength() ;
		char* newWord = new char[size+1];
		for (int i = 0; i < size; i++) {
			if (i < length) {
				newWord[i] = word[i];
			}
			else {

				newWord[i] = string.getWord()[i- length];
			}

		}
		newWord[size] = '\0';

		return new String(newWord);
	}

	int CharLength(const char* stringValue) {

		int size = 0;
		while (stringValue[size] != '\0')
			size++;

		return size;
	}

	bool equalsComparation(const String& word2) {
		if (length != word2.getLength()) {
			return false;
		}
		else {
			for (int i = 0; i < length; i++) {
				if (word[i] != word2.getWord()[i]) {
					return false;
				}
			}
			return true;
		}
	}
	
	bool greaterThanComparation(const String& string) {
		int indice = string.getLength();
		if (indice > length) {
			indice = length;
		}

		for (int i = 0; i < indice; i++) {
			if (word[i] < string.getWord()[i]) {
				return false;
			}
			else if (word[i] > string.getWord()[i]) {
				return true;
			}
		}

		if (length > string.getLength()) {
			return true;
		}
		else if (length < string.getLength()) {
			return false;
		}

		return false;
	}

	bool lesserThanComparation(const String& string) {
		int indice = string.getLength();
		if (indice > length) {
			indice = length;
		}

		for (int i = 0; i < indice; i++) {
			if (word[i] < string.getWord()[i]) {
				return true;
			} else if (word[i] > string.getWord()[i]) {
				return false;
			}
		}

		if (length > string.getLength()) {
			return false;
		} else if (length < string.getLength()) {
			return true;
		}

		return false;
	}

	bool greaterThanOrEqualsComparation(const String& string) {
		int indice = string.getLength();
		if (indice > length) {
			indice = length;
		}

		for (int i = 0; i < indice; i++) {
			if (word[i] < string.getWord()[i]) {
				return false;
			} else if (word[i] > string.getWord()[i]) {
				return true;
			}
		}

		if (length == string.getLength()) {
			return true;
		} else {
			if (length > string.getLength()) {
				return true;
			}
			else if (length < string.getLength()) {
				return false;
			}
		}
	}

	bool lesserThanOrEqualsComparation(const String& string) {
		int indice = string.getLength();
		if (indice > length) {
			indice = length;
		}

		for (int i = 0; i < indice; i++) {
			if (word[i] < string.getWord()[i]) {
				return true;
			} else if (word[i] > string.getWord()[i]) {
				return false;
			}
		}

		if (length == string.getLength()) {
			return true;
		} else {
			if (length > string.getLength()) {
				return false;
			}
			else if (length < string.getLength()) {
				return true;
			}
		}
	}
};


