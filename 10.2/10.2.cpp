#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int BSerch(string myText, int b, int i) {
	if (myText[i] == 'b'|| myText[i] == 'B' || (myText[i] == ' '&& myText[i+1] == 'b') || (myText[i] == ' ' && myText[i + 1] == 'B')) {
		b++;
		i++;
		if (i > myText.size()) {
			return b;
		}
	}
	
	if (i > myText.size()) {
		return b;
	}
	BSerch(myText,b,i+1);
}

int main() {

	ofstream MyFile("t.txt");

	MyFile << "Bamboleo bambolea porque mi vida yo la prefiero vivir asi";

	MyFile.close();

	string myText;

	ifstream MyReadFile("t.txt");

	while (MyReadFile >> myText)
	{
		cout << myText << endl;
	}

	MyReadFile.close();

	string myTextSecond;

	ifstream MyReadFileSecond("t.txt");
	int i = 0;
	int b = 0;
	while (MyReadFileSecond >> myTextSecond)
	{
		BSerch(myTextSecond, b,i);
	}
	cout << "The number of words that begin with b "<< BSerch(myTextSecond, b, i);

	MyReadFileSecond.close();
}
