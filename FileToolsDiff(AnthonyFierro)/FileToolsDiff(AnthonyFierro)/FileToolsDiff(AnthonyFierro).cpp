//
//
//


#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main() {

	ifstream file1, file2;
	string inputData1, inputData2, firstFileName, secondFileName, junk;
	int counter, firstFileLines = 0, secondFileLines = 0;

	cout << "Enter the names of the two files you want to compare: ";

	// open and check the number of lines in the first file
	getline(cin >> ws, firstFileName);
	file1.open(firstFileName, ios::in);

	while (file1.fail())
	{
		cout << "\nunable to open the first file please try again: ";
		getline(cin >> ws, firstFileName);
		file1.open(firstFileName, ios::in);
	}
	
	while (!file1.eof())
	{
		getline(file1, junk);
		firstFileLines++;
	}

	// Open and check the number of lines in the second file
	getline(cin >> ws, secondFileName);
	file2.open(secondFileName);

	while (file2.fail())
	{
		cout << "\nunable to open the second file please try again: ";
		getline(cin >> ws, secondFileName);
		file2.open(secondFileName, ios::in);
	}

	while (!file2.eof()) {
		getline(file2, junk);
		secondFileLines++;
	}

	if (firstFileLines != secondFileLines)
	{
		cout
			<< firstFileName << " has " << firstFileLines << " and "
			<< secondFileName << " has " << secondFileLines << "lines\n";
	}



	system("pause");
	return 0;
}

void connectFileStream(ifstream &file, string &fileName)
{
	getline(cin >> ws, fileName);

	file.open(fileName, ios::in);

	while (file.fail())
	{
		cout << "\nunable to open the file please try again: ";
		getline(cin >> ws, fileName);
		file.open(fileName, ios::in);
	}

}
