/*
	Taylor Ray Shuster
	Ola 2B
	CSCI 3080-001
	Due: 10.18.2018

	This program uses a for loop to calculate a user defined nth term of a given sequence. S(1) = 1 S(n) = S(n-1) + n^3
	To be tested and timed with different order of magnitude n's and timed vs other methods of calculation.
*/
#include <iostream>
using namespace std;
int main(){
	int n;
	int Sn = 0;
	cout << "Define n" << endl;
	cin >> n;
	for (int i = 1; i <= n; i++){
		Sn += (i*i*i);
	}
	cout << Sn << endl;
	return 0;}