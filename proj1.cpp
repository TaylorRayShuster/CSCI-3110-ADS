/*
Taylor Ray Shuster
CSCI 3110-001
Project #1
Due: 09/10/18

This program's purpose is to simulate just-in-time memory allocation by dynamically allocating an array and reallocating it as the size of the input reaches the array's capacity.
*/

#include <fstream>
#include <iostream>
#include <new>

using namespace std;

int* allocateArray(int* A, int* size);
double calcAvg(int* A, int size);
void openOutFile(ofstream&);
void closeOutFile(ofstream&);
void openInFile(ifstream&);
void closeInFile(ifstream&);

int main()
{
	int* vector = nullptr;
	int size;
	int j = 0;
	const int initVals[7] = { 100, 125, 150, 175, 200, 225, 250 };
	ifstream inFile;
	ofstream outFile;
	bool initSpecs = false;

	openInFile(inFile);
	openOutFile(outFile);
	cout << "Enter # of elements to allocate (from 100 to 250 in increments of 25): ";
	cin >> size;
	cout << endl << endl;

	for (int i = 0; i < 7; i++)
	{
		if (size == initVals[i])
		{
			initSpecs = true;
			break;
		}
	}

	if (!initSpecs)
	{
		cout << size << " is not a valid initial size." << endl;
		return 1;
	}

	vector = allocateArray(vector, &size);
	cout << "Allocated " << size << " elements" << endl;
	outFile << "Allocated " << size << " elements" << endl;

	inFile >> *(vector + j);
	j++;
	while (!inFile.eof())
	{
		if (j == size)
		{
			cout << "Average so far is " << calcAvg(vector, size);
			outFile << "Average so far is " << calcAvg(vector, size);
			vector = allocateArray(vector, &size);
			cout << " - Array size now " << size << endl;
			outFile << " - Array size now " << size << endl;
		}
		inFile >> *(vector + j);
		j++;
	}

	cout << size << " integers were read and the average was " << calcAvg(vector, size) << endl;
	outFile << size << " integers were read and the average was " << calcAvg(vector, size) << endl;

	closeInFile(inFile);
	closeOutFile(outFile);

	delete vector;

	return 0;
}

/*
The function allocateArray is used to create, dynamically allocate memory for, and dynamically resize our array used to hold the input.
*/

int* allocateArray(int* A, int* size)
{
	int* temp;
	int initSize = (*size);

	if (A == nullptr)
	{
		A = new int[initSize];
	}
	else
	{
		(*size) = (int)((initSize)*(1.3));
		if ((*size) > 500)
			(*size) = 500;
		temp = A;
		A = new int[(*size)];
		for (int i = 0; i < initSize; i++)
		{
			*(A + i) = *(temp + i);
		}
		delete[] temp;
	}
	return A;
}

/*
The function calcAvg is used to calculate the average of all the values stored in our array.
*/

double calcAvg(int* A, int size)
{
	int sum = 0;
	double avg;

	for (int i = 0; i < size; i++)
	{
		sum += *(A + i);
	}

	avg = ((double)sum / size);

	return avg;
}

/*
Though exceedingly trivial, the next 4 functions handle file management. Reusing my old code from prior projects.
*/

void openOutFile(ofstream& outFile)
{
	outFile.open("out.txt");
	return;
}

void closeOutFile(ofstream& outFile)
{
	outFile.close();
	return;
}

void openInFile(ifstream& inFile)
{
	inFile.open("nums.txt");
	return;
}

void closeInFile(ifstream& inFile)
{
	inFile.close();
	return;
}
