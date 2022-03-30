#include <iostream>
#include <iomanip>
#include <new>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <vector>
#include "NumberList.h"
using namespace std;

int binarySearch(int arr[], int left, int right, int x);


int main() {
	// declearation 

	const int MAX = 1000, MIDDLE = (MAX / 2);
	double elapsedTime;
	int *largeArray, temp;
	largeArray = nullptr;
	vector <int> largeVector(MAX);
	srand(time(0));


	cout << right << setw(2);

	// trys to dynamically allocate an array of the max size
	try {
		largeArray = new int[MAX];
	}
	catch (bad_alloc) {  // if it fails and cannot allocate the amount of memory it will catch the exception and output an error

		cout << "insufficiant memory";
	}

	// starts timer
	auto start = std::chrono::steady_clock::now();

	// for loop that fills the array with random numbers 0 - MAX 
	for (int i = 0; i < MAX; i++) {
		binarySearch(largeArray, 0, MAX + 1, ((rand() % MAX) + 1));
		
		/*largeArray[i] = ((rand() % MAX) + 1);

		// a for loop that checks of the number is less than the previous subscripts and if it is it swaps them for the corrct one 
		for (int j = 0; j < MAX; j++)
			while (largeArray[i] < largeArray[j])
			{
				temp = largeArray[j];
				largeArray[j] = largeArray[i];
				largeArray[i] = temp;
			}
			*/
	}

	// output the array to check if it is correct
	for (int n = MIDDLE; n < (MIDDLE +300) ; n++)
		cout << n + 1 << ".    " << largeArray[n] << endl;

	//ending time
	auto end = std::chrono::steady_clock::now();


	elapsedTime = double(std::chrono::duration_cast<std::chrono::nanoseconds> (end - start).count());
	cout << "\nElapsed time for the array in seconds: " << elapsedTime / 1000000000 << endl;

	delete[] largeArray; // deletes the array after the program is finished.


	cout << "-------------------------------------------------------------------------------\n";
	cout << "  Fill the vector\n"; system("pause");


	try {
		for (int i = 0; i < MAX; i++) {
			largeVector[i] = ((rand() % MAX) + 1);
		}
	}
	catch (bad_alloc) {
		cout << "Error filling the vector";
	}


	// starts timer
	auto startVector = std::chrono::steady_clock::now();

	// for loop that fills the Vector with random numbers 0 - MAX 
	for (int i = 0; i < MAX; i++) {
		largeVector[i] = ((rand() % MAX) + 1);

		// a for loop that checks if the number is less than the previous subscripts and if it is it swaps them for the corrct one 
		for (int j = 0; j < MAX; j++)
			while (largeVector[i] < largeVector[j])
			{
				temp = largeVector[j];
				largeVector[j] = largeVector[i];
				largeVector[i] = temp;
			}

	}

	// output the vector to check if it is correct
	for (int n = MIDDLE; n < (MIDDLE + 300); n++)
		cout << n + 1 << ".    " << largeVector[n] << endl;

	//ending time
	auto endVector = std::chrono::steady_clock::now();
	largeVector.clear();

	double elapsedTimeVector = double(std::chrono::duration_cast<std::chrono::nanoseconds> (endVector - startVector).count());
	cout << "\nElapsed time for the Vector in seconds: " << elapsedTimeVector / 1000000000 << endl;
	cout << "\nElapsed time for the array in seconds: " << elapsedTime / 1000000000 << endl;

	cout << "-----------------------------------------------------------";
	cout << "  \nFill the Linked List\n"; system("pause");

	NumberList list;
	auto startList = std::chrono::steady_clock::now();

	for (int i = 0; i < MAX; i++) {
		list.insertNode(((rand() % MAX) + 1));
	}
		 list.displayList();
	
		auto endList = std::chrono::steady_clock::now();

	double linkedListElapsedTime = double(std::chrono::duration_cast<std::chrono::nanoseconds> (endList - startList).count());

	cout << "\nElapsed time for the array in seconds: " << elapsedTime / 1000000000 << endl;
	cout << "\nElapsed time for the Vector in seconds: " << elapsedTimeVector / 1000000000 << endl;
	cout << "\nElapsed time for the linked list in seconds: " << linkedListElapsedTime / 1000000000 << endl;

	system("pause");
	return 0;
}

int binarySearch(int arr[], int left, int right, int x)
{
	if (right >= left)
	{
		int middle = left + (right - left) / 2;

		// If the element is present at the middle 
		// itself
		if (arr[middle] == x)
			return arr[middle + 1] = x;

		// If element is smaller than mid, then 
		// it can only be present in left subarray
		if (arr[middle] > x)
			return binarySearch(arr, left, middle - 1, x);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, middle + 1, right, x);
	}

	// We reach here when element is not 
	// present in array
	return -1;
}