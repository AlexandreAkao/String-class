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
	/*
	String(const char* new_char) {
		this->length = CharLength(new_char);
		this->word = new char[length + 1];

		for (int i = 0; i < length; i++) {
			this->word[i] = new_char[i];
		}
		this->word[length] = '\0';
	}

	void print() {
		cout << word << endl;
	}

	String operator = (String word) {
		String copyWord
	}

	String operator + (const char* newWord) {
		String value = newWord;

		return ConcatString(value);
	}

	String operator + (String  newWord) {

		return ConcatString(newWord);
	}

	void operator += (String  newWord) {
		String res = ConcatString(newWord);
		this->length = res.length;
		this->word = res.word;
	}

	bool operator == (String otherWord) {
		if (length != otherWord.length) {
			return false;
		} else {
			for (int i = 0; i < length; i++) {
				if (word[i] != otherWord[i]) {
					return false;
				}
			}
			return true;
		}
	}

	bool operator != (String otherWord) {
		if (length != otherWord.length) {
			return true;
		}
		else {
			for (int i = 0; i < length; i++) {
				if (word[i] != otherWord[i]) {
					return true;
				}
			}
			return false;
		}
	}

	bool operator > (String otherWord) {
		int indice = otherWord.length;
		if (indice > length) {
			indice = length;
		}

		for (int i = 0; i < indice; i++) {
			if (word[i] < otherWord[i]) {
				return false;
			} else if (word[i] > otherWord[i]) {
				return true;
			}
		}

		if (length > otherWord.length) {
			return true;
		} else if (length < otherWord.length) {
			return false;
		}

		return false;
	}

	bool operator < (String otherWord) {
		int indice = otherWord.length;
		if (indice > length) {
			indice = length;
		}

		for (int i = 0; i < indice; i++) {
			if (word[i] < otherWord[i]) {
				return true;
			}
			else if (word[i] > otherWord[i]) {
				return false;
			}
		}

		if (length > otherWord.length) {
			return false;
		} else if (length < otherWord.length) {
			return true;
		}
		return false;
	}

	bool operator >= (String otherWord) {
		int indice = otherWord.length;
		if (indice > length) {
			indice = length;
		}

		for (int i = 0; i < indice; i++) {
			if (word[i] < otherWord[i]) {
				return false;
			} else if (word[i] > otherWord[i]) {
				return true;
			}
		}

		if (length > otherWord.length) {
			return true;
		} else if (length < otherWord.length) {
			return false;
		}

		return true;
	}

	bool operator <= (String otherWord) {
		int indice = otherWord.length;
		if (indice > length) {
			indice = length;
		}

		for (int i = 0; i < indice; i++) {
			if (word[i] < otherWord[i]) {
				return true;
			} else if (word[i] > otherWord[i]) {
				return false;
			}
		}

		if (length > otherWord.length) {
			return false;
		} else if (length < otherWord.length) {
			return true;
		}

		return true;
	}

	char operator [] (int index) {

		return word[index];
	}

	friend ostream& operator << (ostream& out, String& c) {
		out << c.word;
		return out;
	}

	friend istream& operator >> (istream& in, String& c) {
		in >> c.word;

		int size = 0;

		String aux = c.word;
		c = aux;
		return in;
	}

	int getLegth() {
		return length;
	}

	int indice(char letra) {
		for (int i = 0; i < length; i++) {
			if (word[i] == letra) {
				return i;
			}
		}
		return NULL;

	}

	void upperCase(int i0, int i1) {

		for (int i = i0; i <= i1; i++) {
			if (word[i] >= 'a' && word[i] <= 'z') {
				word[i] = word[i] - 32;
			}
		}
	}

	void lowerCase(int i0, int i1) {
		for (int i = i0; i <= i1; i++) {
			if (word[i] >= 'A' && word[i] <= 'Z') {
				word[i] = word[i] + 32;
			}
		}
	}

	void toggleCase(int i0, int i1) {
		for (int i = i0; i <= i1; i++) {
			if (word[i] >= 'A' && word[i] <= 'Z') {
				word[i] = word[i] + 32;
			}
			else if (word[i] >= 'a' && word[i] <= 'z') {
				word[i] = word[i] - 32;
			}
		}
	}
	*/
	friend ostream& operator << (ostream& out, String& c) {
		out << c.word;
		return out;
	}

	~String() {

	}

private:
	const char* word;
	int length;

	String ConcatString(String secondString) {
		String res;
		res.length = length + secondString.length;
		char* newWord = new char[res.length + 1];
		for (int i = 0; i < res.length; i++) {
			if (i < length) {
				newWord[i] = word[i];
			}
			else {

				newWord[i] = secondString.word[i - length];
			}

		}
		newWord[res.length] = '\0';
		res.word = newWord;


		return res;

	}

	int CharLength(const char* stringValue) {

		int size = 0;
		while (stringValue[size] != '\0')
			size++;

		return size;
	}

};