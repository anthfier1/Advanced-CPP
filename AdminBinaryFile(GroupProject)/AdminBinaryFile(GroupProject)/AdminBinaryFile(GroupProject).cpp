// Opens the admins binary file that will append the transactions for the day to file and it will read and write the all transactions plus the totals
// Anthony Fierro
// 2/20/18


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Items {
public:
	double donuts;
	double cakes;
	double muffins;
	double bread;
	double other;
	double total;

	Items() {
		donuts = cakes = muffins = bread = other = total = 0;
	}
};

void writeBinaryFile(Items &item, fstream &bfile);
void readBinaryFile(Items item, fstream &bfile, int &totalDonuts, int &totalCakes, int &totalMuffins, int &totalBread, int &totalOther);
void readExistingBinaryFile(Items item, fstream &bfile, int &totalDonuts, int &totalCakes, int &totalMuffins, int &totalBread, int &totalOther);
void printFile(Items item, ostream &output = cout);
void printHeader();
void getItems(Items &item);

int main() {
	ifstream fileInput;
	fstream bfile;
	string binaryFile = "AdminBinaryFile.txt", header;
	Items item;
	int totalDonuts = 0,
		totalCakes = 0,
		totalMuffins = 0,
		totalBread = 0,
		totalOther = 0;

	//==========Read old data
	bfile.open(binaryFile, ios::in | ios::binary);

	printHeader();
	readExistingBinaryFile(item, bfile, totalDonuts, totalCakes, totalMuffins, totalBread, totalOther);
	bfile.close();

	//==========Get new data
	getItems(item);

	//============= Append new data
	bfile.open(binaryFile, ios::out | ios::app | ios::binary);// opens the admin file 

															   /*if (bfile.fail())
															   {
															   cout << "File could not be open closing the program.\n";
															   system("pause");
															   return 0;
															   }
															   else
															   cout << "File successfully opened. \n";*/

	cout << "writing the file.\n";
	writeBinaryFile(item, bfile);
	bfile.close();


	//============= Read file with new addition
	bfile.clear();
	bfile.open(binaryFile, ios::in | ios::app | ios::binary);

	cout << "\n reading the binary file.\n";

	printHeader();

	readBinaryFile(item, bfile, totalDonuts, totalCakes, totalMuffins, totalBread, totalOther);
	bfile.close();

	// =========== print out the totals of the items that were sold
    // cout << "======Totals========\n";
	// cout << totalDonuts << '\t' << totalCakes << '\t' << totalMuffins <<'\t' <<  totalBread << '\t' << totalOther << '\n';

	system("pause");
	return 0;
}

void writeBinaryFile(Items &item, fstream &bfile)
{


	bfile.write(reinterpret_cast<char*> (&item.donuts), sizeof(item.donuts));
	bfile.write(reinterpret_cast<char*> (&item.cakes), sizeof(item.cakes));
	bfile.write(reinterpret_cast<char*> (&item.muffins), sizeof(item.muffins));
	bfile.write(reinterpret_cast<char*> (&item.bread), sizeof(item.bread));
	bfile.write(reinterpret_cast<char*> (&item.other), sizeof(item.other));
	bfile.write(reinterpret_cast<char*> (&item.total), sizeof(item.total));

}

void readBinaryFile(Items item, fstream &bfile, int &totalDonuts, int &totalCakes, int &totalMuffins, int &totalBread, int &totalOther)
{
	// Read first item
	bfile.read(reinterpret_cast<char*> (&item.donuts), sizeof(item.donuts));
	bfile.read(reinterpret_cast<char*> (&item.cakes), sizeof(item.cakes));
	bfile.read(reinterpret_cast<char*> (&item.muffins), sizeof(item.muffins));
	bfile.read(reinterpret_cast<char*> (&item.bread), sizeof(item.bread));
	bfile.read(reinterpret_cast<char*> (&item.other), sizeof(item.other));
	bfile.read(reinterpret_cast<char*> (&item.total), sizeof(item.total));


	while (bfile.good()) {
		printFile(item, cout);
		// Read subsequent items
		bfile.read(reinterpret_cast<char*> (&item.donuts), sizeof(item.donuts));
		bfile.read(reinterpret_cast<char*> (&item.cakes), sizeof(item.cakes));
		bfile.read(reinterpret_cast<char*> (&item.muffins), sizeof(item.muffins));
		bfile.read(reinterpret_cast<char*> (&item.bread), sizeof(item.bread));
		bfile.read(reinterpret_cast<char*> (&item.other), sizeof(item.other));
		bfile.read(reinterpret_cast<char*> (&item.total), sizeof(item.total));
		
		//totals are not working as of now they need to be fixed
		/* total the number of items that were sold 
		totalDonuts += item.donuts;
		totalCakes += item.cakes;
		totalMuffins += item.muffins;
		totalBread += item.bread;
		totalOther += item.other;*/
	}
}

void readExistingBinaryFile(Items item, fstream & bfile, int & totalDonuts, int & totalCakes, int & totalMuffins, int & totalBread, int & totalOther)
{
	// Read first item
	bfile.read(reinterpret_cast<char*> (&item.donuts), sizeof(item.donuts));
	bfile.read(reinterpret_cast<char*> (&item.cakes), sizeof(item.cakes));
	bfile.read(reinterpret_cast<char*> (&item.muffins), sizeof(item.muffins));
	bfile.read(reinterpret_cast<char*> (&item.bread), sizeof(item.bread));
	bfile.read(reinterpret_cast<char*> (&item.other), sizeof(item.other));
	bfile.read(reinterpret_cast<char*> (&item.total), sizeof(item.total));
	// total the number of items that were sold 
	totalDonuts += item.donuts;
	totalCakes += item.cakes;
	totalMuffins += item.muffins;
	totalBread += item.bread;
	totalOther += item.other;

	while (bfile.good()) {
		printFile(item, cout);
		// Read subsequent items
		bfile.read(reinterpret_cast<char*> (&item.donuts), sizeof(item.donuts));
		bfile.read(reinterpret_cast<char*> (&item.cakes), sizeof(item.cakes));
		bfile.read(reinterpret_cast<char*> (&item.muffins), sizeof(item.muffins));
		bfile.read(reinterpret_cast<char*> (&item.bread), sizeof(item.bread));
		bfile.read(reinterpret_cast<char*> (&item.other), sizeof(item.other));
		bfile.read(reinterpret_cast<char*> (&item.total), sizeof(item.total));
	
	}
}

void printFile(Items item, ostream & output)
{
	const int WIDTH = 8;

	output << right << setw(WIDTH);
	output << item.donuts << setw(WIDTH);
	output << item.cakes << setw(WIDTH);
	output << item.muffins << setw(WIDTH);
	output << item.bread << setw(WIDTH);
	output << item.other << setw(WIDTH);
	output << item.total << setw(WIDTH) << endl;

}

void printHeader() {
	const int WIDTH = 8;
	cout << setw(WIDTH) << "Donuts";
	cout << setw(WIDTH) << "Cakes";
	cout << setw(WIDTH) << "Muffins";
	cout << setw(WIDTH) << "Bread";
	cout << setw(WIDTH) << "Other";
	cout << setw(WIDTH) << "Total";
	cout << endl;
}

void getItems(Items & item)
{
	item.total = 0;
	cout << "enter the number of items\n";
	cout << "Donuts:";
	cin >> item.donuts;
	item.total += item.donuts;
	cout << "Cakes:";
	cin >> item.cakes;
	item.total += item.cakes;
	cout << "Muffins:";
	cin >> item.muffins;
	item.total += item.muffins;
	cout << "Bread:";
	cin >> item.bread;
	item.total += item.bread;
	cout << "other:";
	cin >> item.other;
	item.total += item.other;
}

