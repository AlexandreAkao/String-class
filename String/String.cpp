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

	String(String* new_char) {
		this->length = CharLength(new_char->getWord());
		char* aux = new char[length + 1];

		for (int i = 0; i < length; i++) {
			aux[i] = new_char->getWord()[i];
		}
		aux[length] = '\0';

		this->word = aux;
	}

	String(String& new_char) {
		this->length = CharLength(new_char.getWord());
		char* aux = new char[length + 1];

		for (int i = 0; i < length; i++) {
			aux[i] = new_char.getWord()[i];
		}
		aux[length] = '\0';

		this->word = aux;
	}

	int getLength() {
		return this->length;
	}

	const char* getWord() {
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
		else if (index < 0 || index >= this->length) {
			throw "posicao nao valida";
		}
		return word[index];
	}



	friend auto operator == (String* word1, String& word2)->bool {
		String word = word1->getWord();
		return word.equalsComparation(word2);
	}

	friend auto operator == (String& word1, String* word2) ->bool {
		String word = word2->getWord();
		return word1.equalsComparation(word);
	}

	friend auto operator == (String& word1, String& word2) ->bool {
		return word1.equalsComparation(word2);
	}

	friend auto operator != (String* word1, String& word2)->bool {
		String word = word1->getWord();
		return !word.equalsComparation(word2);
	}

	friend auto operator != (String& word1, String* word2) ->bool {
		String word = word2->getWord();
		return !word1.equalsComparation(word);
	}

	friend auto operator != (String& word1, String& word2) ->bool {
		return !word1.equalsComparation(word2);
	}


	/*
	bool operator > (String otherWord) {
		int indice = otherWord.getLength();
		if (indice > length) {
			indice = length;
		}

		for (int i = 0; i < indice; i++) {
			if (word[i] < otherWord[i]) {
				return false;
			}
			else if (word[i] > otherWord[i]) {
				return true;
			}
		}

		if (length == otherWord.getLength()) {
			return false;
		}
		else if (length < otherWord.getLength()) {
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
		}
		else if (length < otherWord.length) {
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
			}
			else if (word[i] > otherWord[i]) {
				return true;
			}
		}

		if (length > otherWord.length) {
			return true;
		}
		else if (length < otherWord.length) {
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
			}
			else if (word[i] > otherWord[i]) {
				return false;
			}
		}

		if (length > otherWord.length) {
			return false;
		}
		else if (length < otherWord.length) {
			return true;
		}

		return true;
	}

*/

	/*
	String operator + (String newWord) {
		String aux =  ConcatString(newWord);
		return aux;
	}


	String operator = (String word) {
		String copyWord
	}

	String operator + (const char* newWord) {
		String value = newWord;

		return ConcatString(value);
	}

		String operator = (String newWord) {
		cout << "oie" << endl;
		this->length = CharLength(newWord.getWord());
		char* aux = new char[length + 1];
		for (int i = 0; i < length; i++) {
			aux[i] = newWord.getWord()[i];
		}
		aux[length] = '\0';
		String* deleteAux = new String(aux);
		return aux;
	}

	void operator += (String  newWord) {
		String res = ConcatString(newWord);
		this->length = res.length;
		this->word = res.word;
	}

	


	*/
	friend ostream& operator << (ostream& out, String* c) {
		out << c->getWord();
		return out;
	}

	friend ostream& operator << (ostream& out, String& c) {
		out << c.getWord();
		return out;
	}

	friend istream& operator >> (istream& in, String& c) {
		char* charAux;
		in >> charAux;
		int size = 0;

		String aux = charAux;
		c = aux;
		return in;
	}

	friend istream& operator >> (istream& in, String* c) {
		char* charAux;
		in >> charAux;

		c = new String(charAux);
		return in;
	}


	~String() {
		delete(word);
	}

private:
	const char* word;
	int length;

	String ConcatString(String& secondString) {
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
	bool equalsComparation(String word2) {
		if (length != word2.getLength()) {
			return false;
		}
		else {
			for (int i = 0; i < length; i++) {
				if (word[i] != word2[i]) {
					return false;
				}
			}
			return true;
		}
	}

	bool equalsComparation(String word1, String word2) {
		if (word1.getLength() != word2.getLength()) {
			return false;
		}
		else {
			for (int i = 0; i < word1.getLength(); i++) {
				if (word1[i] != word2[i]) {
					return false;
				}
			}
			return true;
		}
	}


};


