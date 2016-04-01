/*
There is a general and he has N Snipers in his control . He has a battefield of NxN Blocks .
He now has to place all N snipers in the battle field such that he can have control of all Blocks,
ie each block should atleast have One sniper having control on it .

A Sniper has control of all blocks in line in all 4 directions . and also all blocks in all 4 diagonals
from his position .

Example :

. C C C
C C S C
. C C C
C . C .

In the above field if Sniper S is placed at (1,2) He has control of all blocks denoted by C .
But their is a problem for the General. All his snipers dont like each other So if any sees any
other sniper in his field of view (Control Blocks) ,he will instantly kill the other sniper .So
Your task is to help the general to place all his N Snipers on NxN field such that ,No sniper can
kill other sniper,but still have control of all the Blocks .

Input : A NxN board , which is all 0's , and N (number of snipers )
Output : Return 1 if its General can place all N snipers or else return 0 .
		 Also modify the battlefield ,such that Blocks which have sniper placed are denoted by 1
		 and all other blocks as 0.

		 Note : If there are multiple correct arrangements ,Arrange in any 1 of the possible ways.
Example Input :
int battle_field[4][4]={0};
solve_nsnipers(&battle_field[0][0],4);

Example Output :
Returns 1 , and modifies battle_field as follows .
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0


Read :How to access elements in 2D array when its first element address is passed : http://www.geeksforgeeks.org/pass-2d-array-parameter-c/

P.S: The Above Problem is just a modified version of a popular BackTracking problem .
*/

#include "stdafx.h"

int canPlace(int *battlefield, int n, int row, int column)
{
	int i, j;
	/*printf("\n\n");
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%d ", *((battlefield + i*n) + j));
		printf("\n");
	}*/
	for (i = 0; i <column; i++)
	{
		if (*((battlefield + row*n) + i)) return 0;
	}
	for (i = row, j = column; i >= 0 && j >= 0; i--, j--)
	{
		if (*((battlefield + i*n) + j)) return 0;
	}
	for (i = row, j = column; j >= 0 && i<n; i++, j--)
	{
		if (*((battlefield + i*n) + j))return 0;
	}
	return 1;
}
int backtrackSnipers(int *battlefield, int n, int column)
{
	int row;
	if (column == n) return 1;
	for (row = 0; row < n; row++)
	{
		if (canPlace(battlefield, n, row, column))
		{
			*((battlefield + row*n) + column) = 1;
			//printf("%d %d\n", row, column);
			if (backtrackSnipers(battlefield, n, column + 1)) return 1;
			*((battlefield + row*n) + column) = 0;
		}
	}
	return 0;
}
int solve_nsnipers(int *battlefield, int n){
	if (battlefield == NULL || n <= 0)return 0;
	return backtrackSnipers(battlefield, n, 0);
}
