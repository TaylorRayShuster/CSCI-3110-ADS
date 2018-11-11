/*Author:  Taylor Ray Shuster
*Course:  CSCI 3080
*Lab number: Ola 4
*Purpose:	The program you write for this lab will read in the number of nodes and a binary relation representing a graph. The program will create an adjacency matrix from the binary relation. Then based on user selection, it will perform and output different calculations.
*Due date: 11.15.2018
*/
#include <iostream>

void printAdj(int[10][10], int);
void isoNode(int[10][10], int);
void degreeNode(int[10][10], int);
void eulerPath(int[10][10], int);
void adjNode(int[10][10], int);

int main()
{
	int userChoice, numNodes, x, y;
	int adjMatrix[10][10] = { 0 };
	char read;

	std::cout << "Please input the number of nodes: ";
	std::cin >> numNodes;
	std::cout << "Please input the adjacency relation:" << std::endl;
	std::cin >> read;
	while (read != '}')
	{
		std::cin >> read >> x >> read >> y >> read >> read;
		adjMatrix[x-1][y-1]++;
	}
	std::cout << std::endl;
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1.  Print the adjacency matrix" << std::endl;
	std::cout << "2.  Determine if there are any isolated nodes" << std::endl;
	std::cout << "3.  Determine the degree of a node" << std::endl;
	std::cout << "4.  Determine if an Euler path exists" << std::endl;
	std::cout << "5.  Determine if one node is adjacent to another" << std::endl;
	std::cout << "6.  Quit" << std::endl << std::endl;
	std::cin >> userChoice;
	while (userChoice != 6)
	{
		switch (userChoice)
		{
		case 1: printAdj(adjMatrix, numNodes); break;
		case 2: isoNode(adjMatrix, numNodes); break;
		case 3: degreeNode(adjMatrix, numNodes); break;
		case 4: eulerPath(adjMatrix, numNodes); break;
		case 5: adjNode(adjMatrix, numNodes); break;
		}
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "1.  Print the adjacency matrix" << std::endl;
		std::cout << "2.  Determine if there are any isolated nodes" << std::endl;
		std::cout << "3.  Determine the degree of a node" << std::endl;
		std::cout << "4.  Determine if an Euler path exists" << std::endl;
		std::cout << "5.  Determine if one node is adjacent to another" << std::endl;
		std::cout << "6.  Quit" << std::endl << std::endl;
		std::cin >> userChoice;
	}
	std::cout << "Goodbye" << std::endl;
	return 0;
}

void printAdj(int adjMatrix[10][10], int numNodes)
{
	std::cout << std::endl << "The adjacency matrix is:" << std::endl;
	for (int i = 0; i < numNodes; i++)
	{
		for (int j = 0; j < numNodes; j++)
			std::cout << adjMatrix[i][j] << " ";
		std::cout << std::endl << std::endl;
	}
	return;
}

void isoNode(int adjMatrix[10][10], int numNodes)
{
	int isoNodes[10] = { 0 };
	int isoCount = 0;
	bool iso = true;
	for (int i = 0; i < numNodes; i++)
	{
		for (int j = 0; j < numNodes; j++)
		{
			if (adjMatrix[i][j] >= 1)
				iso = false;
		}
		if (iso == true)
		{
			isoNodes[isoCount] = (i + 1);
			isoCount++;
		}
		else
			iso = true;
	}
	if (isoNodes[0] != 0)
	{
		std::cout << "The isolated nodes are:" << std::endl;
		for (int i = 0; i < isoCount; i++)
			std::cout << isoNodes[i] << " " << std::endl;
		std::cout << std::endl << std::endl;
	}		
	else
	{
		std::cout << "There are no isolated nodes." << std::endl << std::endl;
	}
	return;
}

void degreeNode(int adjMatrix[10][10], int numNodes)
{
	int node;
	int degree = 0;
	std::cout << "Please input the node:" << std::endl;
	std::cin >> node;
	std::cout << std::endl;
	for (int i = 0; i < numNodes; i++)
	{
		degree += adjMatrix[node - 1][i];
	}
	std::cout << "The degree of node " << node << " is " << degree << std::endl << std::endl;
	return;
}
void eulerPath(int adjMatrix[10][10], int numNodes)
{
	int total, degree, i, j;
	total = 0;
	i = 0;
	while (total <= 2 && i <= numNodes)
	{
		degree = 0;
		for (j = 0; j < numNodes; j++)
			degree += adjMatrix[i][j];
		if (degree == 1 || degree == 3 || degree == 5 || degree == 7 || degree == 9 || degree == 11)
			total++;
		i++;
	}
	if (total > 2)
		std::cout << "An Euler path does NOT exist in the graph." << std::endl << std::endl;
	else
		std::cout << "An Euler path does exist in the graph." << std::endl << std::endl;
	return;
}
void adjNode(int adjMatrix[10][10], int numNodes)
{
	int x, y;
	std::cout << "Please input the nodes in question:" << std::endl;
	std::cin >> x >> y;
	if (adjMatrix[x][y] != 0)
		std::cout << "Node " << x << " is adjacent to node " << y << std::endl << std::endl;
	else
		std::cout << "Node " << x << " is NOT adjacent to node " << y << std::endl << std::endl;
	return;
}