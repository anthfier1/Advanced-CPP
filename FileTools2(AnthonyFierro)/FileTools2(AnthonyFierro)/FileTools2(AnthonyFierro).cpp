/*Write a program that asks the user for the name of a file. The program should display the contents of the file on the screen.
If the file's contents won't fit on a single screen, the program should display 24 lines of output at a time, and then pause. 
Each time the program pauses it should wait for the user to strike a key before the next 24 lines are displayed.*/
// Anthony Fierro
// 2/21/18

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {

	const int LIMIT = 24;
	int count = 0;
	string fileName, input;
	ifstream fileInput;

	cout << "enter the name of the file you want to open: ";
	getline(cin >> ws, fileName);

	fileInput.open(fileName, ios::in);

	while (fileInput.fail()) {
		cout << "Could not open the file " << fileName << ". \nPlease enter another file name: ";
		getline(cin >> ws, fileName);
		fileInput.open(fileName, ios::in);
	}

	while (!fileInput.eof())
	{
		cout << count + 1 << ". ";
		getline(fileInput, input);
		count++;
		cout << input << endl;
		if (count %LIMIT == 0)
		{
			cout << "press enter to read more lines from the file.";
			cin.get();
		}
		
	}
	if (fileInput.eof() && count < LIMIT)
		cout << "The whole file has been displayed./n";

	system("pause");
	return 0;
}