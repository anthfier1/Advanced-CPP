/* */
// Anthony Fierro
// 2/8/18

#include<iostream>
using namespace std;

struct USMeasurment
{
	int feet;
	double inches;
};

void getMeasurment(USMeasurment &rectangle);
void getMeasurmentArray(USMeasurment measureArray[], int size);


int main()
{
	const int NUMOFMEASUR = 2;
	USMeasurment length, width, height;
	USMeasurment measureArr[NUMOFMEASUR];

	cout << "\nWhats is the length of the rectangle?\n";
	getMeasurment(length);
	cout << "\nWhats is the width of the rectangle?\n";
	getMeasurment(width);
	cout << "\nWhats is the height of the rectangle?\n";
	getMeasurment(height);



	system("pause");
	return 0;
}

void getMeasurment(USMeasurment &rectangle)
{
	cout << "Feet: ";
	cin >> ws; cin >> rectangle.feet;
	cout << "\n Inches: ";
	cin >> ws; cin >> rectangle.inches;
	while (rectangle.inches >= 12)
	{
		cout << "Your inches measurment must be less than 12.\n Inches:";
		cin >> rectangle.inches;
	}

}

void getMeasurmentArray(USMeasurment measureArray[], int size)
{

}
