#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

int ROW = 0;
int COL = 0;
int **grid;
bool **visited;

void rottenCheck(int r, int c)
{
	if (r >= 0 && r < ROW && c >= 0 && c < COL && visited[r][c])
	{
		return;
	}
	else if (r >= 0 && r < ROW && c >= 0 && c < COL && grid[r][c] == 1)
	{
		grid[r][c] = 2;
		rottenCheck(r + 1, c);
		rottenCheck(r - 1, c);
		rottenCheck(r, c + 1);
		rottenCheck(r, c - 1);
	}
	else
	{
		return;
	}
}

int main()
{
	// Opens the input file
	//
	ifstream inFile;
	inFile.open("input-no.txt");

	// If unable to open file exit
	//
	if (!inFile)
	{
		cout << "Unable to open file";
		exit(1);
	}

	// Initilizes ROW and COL for array
	//
	inFile >> ROW;
	inFile >> COL;

	// Dynamically creates orange and visited array
	//
	grid = new int*[ROW];
	visited = new bool*[ROW];

	for (int i = 0; i < ROW; i++)
	{
		grid[i] = new int[COL];
		visited[i] = new bool[COL];
	}

	for (int j = 0; j < ROW; j++)
	{
		for (int k = 0; k < COL; k++)
		{
			inFile >> grid[j][k];
			visited[j][k] = 0;
		}
	}
	
	// Finds rotten orange and checks which oranges will be affected
	//
	for (int j = 0; j < ROW; j++)
	{
		for (int k = 0; k < COL; k++)
		{
			if (grid[j][k] == 2)
			{
				visited[j][k] = 1;
				rottenCheck(j + 1, k);
				rottenCheck(j - 1, k);
				rottenCheck(j, k + 1);
				rottenCheck(j, k - 1);
			}
		}
	}
	
	// Displays orange grid after rotting
	//
	/*
	for (int j = 0; j < ROW; j++)
	{
		for (int k = 0; k < COL; k++)
		{
			cout << grid[j][k] << " ";
		}
		cout << "\n";
	}
	*/

	// Checks for fresh oranges
	//
	bool output = true;

	for (int l = 0; l < ROW; l++)
	{
		for (int m = 0; m < COL; m++)
		{
			if (grid[l][m] == 1)
			{
				output = false;
			}
			
		}
	}

	// outputs Yes if all oranges are rotten
	// outputs No if there are fresh oranges
	//
	if (output)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}

	return 0;
}

