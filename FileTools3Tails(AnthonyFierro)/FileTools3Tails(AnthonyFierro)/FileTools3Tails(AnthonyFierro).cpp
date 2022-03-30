//
//
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {

	string fileName, junk, input;
	int lineCount = 0, counter = 0;
	ifstream fileInput;
	const int LIMIT = 15;

	cout << "Enter the name of the file you want to open: ";
	getline(cin >> ws, fileName);

	fileInput.open(fileName, ios::in);

	while (fileInput.fail())
	{
		cout << "Unable to open the file. Please try again: ";
		getline(cin >> ws, fileName);
		fileInput.open(fileName, ios::in);
	}

	while (!fileInput.eof())
	{
		getline(fileInput, junk);
		lineCount++;
	}

	cout << "There are " << lineCount + 1 << " lines in the file.\n\n";

	fileInput.seekg(0, ios::beg);

	while (!fileInput.eof() && lineCount > LIMIT)
	{
		if (counter <= (lineCount - LIMIT - 1)) {
			getline(fileInput, junk);
		}

		if (counter >= (lineCount - LIMIT + 1) && counter <= lineCount) {
			cout << counter + 1 << ". ";
			getline(fileInput, input);
			cout << input << endl;
		}
		counter++;
	}
	
	fileInput.seekg(0, ios::beg);

	while (!fileInput.eof() && lineCount <= LIMIT)
	{

		while(counter <= lineCount) {
			cout << counter + 1 << ". ";
			getline(fileInput, input);
			cout << input << endl;
			counter++;

		}
	}

	if (counter <= LIMIT)
		cout << "The whole file has been displayed.\n\n";

	/*	
	if (fileInput.eof() && counter <= LIMIT)
	{
		cout << "The whole file has been displayed.\n\n";
	}*/
	
	fileInput.close();

	cout << endl;
	
	system("pause");
	return 0;
}