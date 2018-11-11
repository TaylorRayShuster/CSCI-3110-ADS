/*Author:  Taylor Ray Shuster
*Course:  CSCI 3080
*Lab number: Ola 3
*Purpose:	1.  read in a left-child, middle-child, right-child array representation for a ternary tree 
			2.  store the tree as an adjacency matrix and as a left child, middle child, right child array.  
			3.  print out the adjacency matrix and the left child, middle child, right child array representation.  
			4.  print the preorder, inorder, and postorder traversals of the tree using the left,middle,right child array. 
*Due date: 11.8.2018
*/
#include <iostream>

void readTree(int[10][3], int[10][10], int&);
void printTree(int[10][3], int[10][10], int);
void inorder(int[10][3], int);
void preorder(int[10][3], int);
void postorder(int[10][3], int);

int main()
{
	int lmrArray[10][3];
	int adjMatrix[10][10];
	int nodes;
	int root = 1;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			adjMatrix[i][j] = 0;


	readTree(lmrArray, adjMatrix, nodes);
	printTree(lmrArray, adjMatrix, nodes);
	std::cout << "The preorder traversal is: " << std::endl;
	preorder(lmrArray, root);
	std::cout << std::endl << std::endl;
	std::cout << "The inorder traversal is: " << std::endl;
	inorder(lmrArray, root);
	std::cout << std::endl << std::endl;
	std::cout << "The postorder traversal is: " << std::endl;
	postorder(lmrArray, root);
	std::cout << std::endl << std::endl;

	return 0;
}

void readTree(int lmrArray[10][3], int adjMatrix[10][10], int& nodes)
{
	std::cout << "Enter Left, Middle, Right Array Representation of the tree:" << std::endl;
	std::cin >> nodes;
	int trash;

	for (int i = 0; i < nodes; i++)
	{
		std::cin >> trash;
		for (int j = 0; j < 3; j++)
		{
			std::cin >> lmrArray[i][j];
		}
	}

	for (int i = 0; i < nodes; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (lmrArray[i][j] != -1)
				adjMatrix[i][lmrArray[i][j] - 1] = 1;
		}
	}
	return;
}

void printTree(int lmrArray[10][3], int adjMatrix[10][10], int nodes)
{
	std::cout << "The adjacency matrix is: " << std::endl << std::endl;
	for (int i = 0; i < nodes; i++)
	{
		for (int j = 0; j < nodes; j++)
			std::cout << adjMatrix[i][j] << '\t';
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "The left child, middle child, right child array representation is:" << std::endl << std::endl;
	for (int i = 0; i < nodes; i++)
	{
		for (int j = 0; j < 3; j++)
			std::cout << lmrArray[i][j] << '\t';
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return;
}

void inorder(int lmrArray[10][3], int node)
{
	if (lmrArray[node - 1][0] != -1)
		inorder(lmrArray, lmrArray[node - 1][0]);
	std::cout << node << '\t';
	if (lmrArray[node - 1][1] != -1)
		inorder(lmrArray, lmrArray[node - 1][1]);
	if (lmrArray[node - 1][2] != -1)
		inorder(lmrArray, lmrArray[node - 1][2]);
	return;
}

void preorder(int lmrArray[10][3], int node)
{
	std::cout << node << '\t';
	if (lmrArray[node - 1][0] != -1)
		preorder(lmrArray, lmrArray[node - 1][0]);
	if (lmrArray[node - 1][1] != -1)
		preorder(lmrArray, lmrArray[node - 1][1]);
	if (lmrArray[node - 1][2] != -1)
		preorder(lmrArray, lmrArray[node - 1][2]);
	return;
}

void postorder(int lmrArray[10][3], int node)
{
	if (lmrArray[node - 1][0] != -1)
		postorder(lmrArray, lmrArray[node - 1][0]);
	if (lmrArray[node - 1][1] != -1)
		postorder(lmrArray, lmrArray[node - 1][1]);
	if (lmrArray[node - 1][2] != -1)
		postorder(lmrArray, lmrArray[node - 1][2]);
	std::cout << node << '\t';
	return;
}