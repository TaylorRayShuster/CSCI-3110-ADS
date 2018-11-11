/*
	Taylor Ray Shuster
	OLA 1
	CSCI 3080
	Due: 10.04.18
	This program will prompt the user for 2 wff's, calculate their truth tables, and determine if they are equivalent expressions.
*/

#include <iostream>

using namespace std;

int main()
{
	char reading, operand1, operand2;
	int working = 0;
	bool operand = 0;
	bool P[8] = { 1, 1, 1, 1, 0, 0, 0, 0 };
	bool Q[8] = { 1, 1, 0, 0, 1, 1, 0, 0 };
	bool R[8] = { 1, 0, 1, 0, 1, 0, 1, 0 };
	bool firstTable[8];
	bool secondTable[8];
	bool thirdTable[8];
	bool equivalence = true;

	cout << "input the first expression: " << endl;
	cin >> reading;
	while (reading != 'E')
	{
		if (reading == 'P')
		{
			if (!operand)
			{
				operand1 = reading;
				operand = 1;
			}
			else
			{
				operand2 = reading;
				operand = 0;
			}
		}
		if (reading == 'Q')
		{
			if (!operand)
			{
				operand1 = reading;
				operand = 1;
			}
			else
			{
				operand2 = reading;
				operand = 0;
			}

		}
		if (reading == 'R')
		{
			if (!operand)
			{
				operand1 = reading;
				operand = 1;
			}
			else
			{
				operand2 = reading;
				operand = 0;
			}

		}
		if (reading == 'N')
		{
			if (!operand)
			{
				if (operand2 == 'P')
				{
					for (int i = 0; i < 8; i++)
						P[i] = (!P[i]);
				}
				if (operand2 == 'Q')
				{
					for (int i = 0; i < 8; i++)
						Q[i] = (!Q[i]);
				}
				if (operand2 == 'R')
				{
					for (int i = 0; i < 8; i++)
						R[i] = (!R[i]);
				}
			}
			else
			{
				if (operand1 == 'P')
				{
					for (int i = 0; i < 8; i++)
						P[i] = (!P[i]);
				}
				if (operand1 == 'Q')
				{
					for (int i = 0; i < 8; i++)
						Q[i] = (!Q[i]);
				}
				if (operand1 == 'R')
				{
					for (int i = 0; i < 8; i++)
						R[i] = (!R[i]);
				}
			}

		}
		if (reading == 'A')
		{
			if (operand1 == 'P' && operand2 == 'Q')
			{
				for (int i = 0; i < 8; i++)
				{
					firstTable[i] = (P[i] && Q[i]);
				}
			}
			else if (operand1 == 'P' && operand2 == 'R')
			{
				for (int i = 0; i < 8; i++)
				{
					firstTable[i] = (P[i] && R[i]);
				}
			}
			else if (operand1 == 'Q' && operand2 == 'R')
			{
				for (int i = 0; i < 8; i++)
				{
					firstTable[i] = (Q[i] && R[i]);
				}
			}
			else if (operand1 == 'Q' && operand2 == 'P')
			{
				for (int i = 0; i < 8; i++)
				{
					firstTable[i] = (Q[i] && P[i]);
				}
			}
			else if (operand1 == 'R' && operand2 == 'P')
			{
				for (int i = 0; i < 8; i++)
				{
					firstTable[i] = (R[i] && P[i]);
				}
			}
			else if (operand1 == 'R' && operand2 == 'Q')
			{
				for (int i = 0; i < 8; i++)
				{
					firstTable[i] = (R[i] && Q[i]);
				}
			}


		}
		if (reading == 'O')
		{
			if (operand1 == 'P' && operand2 == 'Q')
			{
				for (int i = 0; i < 8; i++)
				{
					firstTable[i] = (P[i] || Q[i]);
				}
			}
			else if (operand1 == 'P' && operand2 == 'R')
			{
				for (int i = 0; i < 8; i++)
				{
					firstTable[i] = (P[i] || R[i]);
				}
			}
			else if (operand1 == 'Q' && operand2 == 'R')
			{
				for (int i = 0; i < 8; i++)
				{
					firstTable[i] = (Q[i] || R[i]);
				}
			}
			else if (operand1 == 'Q' && operand2 == 'P')
			{
				for (int i = 0; i < 8; i++)
				{
					firstTable[i] = (Q[i] || P[i]);
				}
			}
			else if (operand1 == 'R' && operand2 == 'P')
			{
				for (int i = 0; i < 8; i++)
				{
					firstTable[i] = (R[i] || P[i]);
				}
			}
			else if (operand1 == 'R' && operand2 == 'Q')
			{
				for (int i = 0; i < 8; i++)
				{
					firstTable[i] = (R[i] || Q[i]);
				}
			}
		}
		if (reading == 'I')
		{
			if (operand1 == 'P' && operand2 == 'Q')
			{
				for (int i = 0; i < 8; i++)
				{
					firstTable[i] = ((!P[i]) || Q[i]);
				}
			}
			else if (operand1 == 'P' && operand2 == 'R')
			{
				for (int i = 0; i < 8; i++)
				{
					firstTable[i] = ((!P[i]) || R[i]);
				}
			}
			else if (operand1 == 'Q' && operand2 == 'R')
			{
				for (int i = 0; i < 8; i++)
				{
					firstTable[i] = ((!Q[i]) || R[i]);
				}
			}
			else if (operand1 == 'Q' && operand2 == 'P')
			{
				for (int i = 0; i < 8; i++)
				{
					firstTable[i] = ((!Q[i]) || P[i]);
				}
			}
			else if (operand1 == 'R' && operand2 == 'P')
			{
				for (int i = 0; i < 8; i++)
				{
					firstTable[i] = ((!R[i]) || P[i]);
				}
			}
			else if (operand1 == 'R' && operand2 == 'Q')
			{
				for (int i = 0; i < 8; i++)
				{
					firstTable[i] = ((!R[i]) || Q[i]);
				}
			}

		}
		cin >> reading;
	}
	cout << "input the second expression: " << endl;
	cin >> reading;
	while (reading != 'E')
	{
		if (reading == 'P')
		{
			if (!operand)
			{
				operand1 = reading;
				operand = 1;
			}
			else
			{
				operand2 = reading;
				operand = 0;
			}
		}
		if (reading == 'Q')
		{
			if (!operand)
			{
				operand1 = reading;
				operand = 1;
			}
			else
			{
				operand2 = reading;
				operand = 0;
			}

		}
		if (reading == 'R')
		{
			if (!operand)
			{
				operand1 = reading;
				operand = 1;
			}
			else
			{
				operand2 = reading;
				operand = 0;
			}

		}
		if (reading == 'N')
		{
			if (!operand)
			{
				if (operand2 == 'P')
				{
					for (int i = 0; i < 8; i++)
						P[i] = (!P[i]);
				}
				if (operand2 == 'Q')
				{
					for (int i = 0; i < 8; i++)
						Q[i] = (!Q[i]);
				}
				if (operand2 == 'R')
				{
					for (int i = 0; i < 8; i++)
						R[i] = (!R[i]);
				}
			}
			else
			{
				if (operand1 == 'P')
				{
					for (int i = 0; i < 8; i++)
						P[i] = (!P[i]);
				}
				if (operand1 == 'Q')
				{
					for (int i = 0; i < 8; i++)
						Q[i] = (!Q[i]);
				}
				if (operand1 == 'R')
				{
					for (int i = 0; i < 8; i++)
						R[i] = (!R[i]);
				}
			}

		}
		if (reading == 'A')
		{
			if (operand1 == 'P' && operand2 == 'Q')
			{
				for (int i = 0; i < 8; i++)
				{
					secondTable[i] = (P[i] && Q[i]);
				}
			}
			else if (operand1 == 'P' && operand2 == 'R')
			{
				for (int i = 0; i < 8; i++)
				{
					secondTable[i] = (P[i] && R[i]);
				}
			}
			else if (operand1 == 'Q' && operand2 == 'R')
			{
				for (int i = 0; i < 8; i++)
				{
					secondTable[i] = (Q[i] && R[i]);
				}
			}
			else if (operand1 == 'Q' && operand2 == 'P')
			{
				for (int i = 0; i < 8; i++)
				{
					secondTable[i] = (Q[i] && P[i]);
				}
			}
			else if (operand1 == 'R' && operand2 == 'P')
			{
				for (int i = 0; i < 8; i++)
				{
					secondTable[i] = (R[i] && P[i]);
				}
			}
			else if (operand1 == 'R' && operand2 == 'Q')
			{
				for (int i = 0; i < 8; i++)
				{
					secondTable[i] = (R[i] && Q[i]);
				}
			}


		}
		if (reading == 'O')
		{
			if (operand1 == 'P' && operand2 == 'Q')
			{
				for (int i = 0; i < 8; i++)
				{
					secondTable[i] = (P[i] || Q[i]);
				}
			}
			else if (operand1 == 'P' && operand2 == 'R')
			{
				for (int i = 0; i < 8; i++)
				{
					secondTable[i] = (P[i] || R[i]);
				}
			}
			else if (operand1 == 'Q' && operand2 == 'R')
			{
				for (int i = 0; i < 8; i++)
				{
					secondTable[i] = (Q[i] || R[i]);
				}
			}
			else if (operand1 == 'Q' && operand2 == 'P')
			{
				for (int i = 0; i < 8; i++)
				{
					secondTable[i] = (Q[i] || P[i]);
				}
			}
			else if (operand1 == 'R' && operand2 == 'P')
			{
				for (int i = 0; i < 8; i++)
				{
					secondTable[i] = (R[i] || P[i]);
				}
			}
			else if (operand1 == 'R' && operand2 == 'Q')
			{
				for (int i = 0; i < 8; i++)
				{
					secondTable[i] = (R[i] || Q[i]);
				}
			}
		}
		if (reading == 'I')
		{
			if (operand1 == 'P' && operand2 == 'Q')
			{
				for (int i = 0; i < 8; i++)
				{
					secondTable[i] = ((!P[i]) || Q[i]);
				}
			}
			else if (operand1 == 'P' && operand2 == 'R')
			{
				for (int i = 0; i < 8; i++)
				{
					secondTable[i] = ((!P[i]) || R[i]);
				}
			}
			else if (operand1 == 'Q' && operand2 == 'R')
			{
				for (int i = 0; i < 8; i++)
				{
					secondTable[i] = ((!Q[i]) || R[i]);
				}
			}
			else if (operand1 == 'Q' && operand2 == 'P')
			{
				for (int i = 0; i < 8; i++)
				{
					secondTable[i] = ((!Q[i]) || P[i]);
				}
			}
			else if (operand1 == 'R' && operand2 == 'P')
			{
				for (int i = 0; i < 8; i++)
				{
					secondTable[i] = ((!R[i]) || P[i]);
				}
			}
			else if (operand1 == 'R' && operand2 == 'Q')
			{
				for (int i = 0; i < 8; i++)
				{
					secondTable[i] = ((!R[i]) || Q[i]);
				}
			}
		}
		cin >> reading;
	}
		for (int i = 0; i < 8; i++)
		{
			if (firstTable[i] != secondTable[i])
			{
				thirdTable[i] = false;
				equivalence = false;
			}
			else
				thirdTable[i] = true;
		}

		cout << "first\t" << "second\t" << "equivalence" << endl;
		//cout << boolalpha;
		for (int i = 0; i < 8; i++)
		{
			cout << firstTable[i] << "\t" << secondTable[i] << "\t" << thirdTable[i] << endl;
		}
		if (equivalence)
			cout << "the two expressions are equivalent" << endl;
		else
			cout << "the two expressions are not equivalent" << endl;

		return 0;

}