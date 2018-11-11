/*
	Taylor Ray Shuster
	Ola 2A
	CSCI 3080-001
	Due: 10.18.2018

	This program uses recursion to calculate a user defined nth term of a given sequence. S(1) = 1 S(n) = S(n-1) + n^3
	To be tested and timed with different order of magnitude n's and timed vs other methods of calculation.
*/
#include <iostream>
using namespace std;
int S(int n);
int main(){
	int n, Sn;
	cout << "Define n" << endl;
	cin >> n;
	Sn = S(n);
	cout << Sn << endl;
	return 0;}
int S(int n){
	if (n == 1)
		return 1;
	else 
		return (S(n-1) + (n*n*n));}