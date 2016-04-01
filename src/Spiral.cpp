/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
int *spiralRecursion(int top, int bottom, int left, int right, int direction, int ** input_array, int * result, int resIndex, int eles)
{
	int i;
	if (eles == resIndex) return result;

	if (direction == 0)
	{
		for (i = left; i <= right; i++)
		{
			result[resIndex] = input_array[top][i];
			resIndex++;
		}
		top++;
	}
	else if (direction == 1)
	{
		for (i = top; i <= bottom; i++)
		{
			result[resIndex] = input_array[i][right];
			resIndex++;
		}
		right--;

	}
	else if (direction == 2)
	{
		for (i = right; i >= left; i--)
		{
			result[resIndex] = input_array[bottom][i];
			resIndex++;
		}
		bottom--;

	}
	else if (direction == 3)
	{
		for (i = bottom; i >= top; i--)
		{
			result[resIndex] = input_array[i][left];
			//printf("%d ", result[resIndex]);
			resIndex++;
		}
		left++;

	}
	direction = (direction + 1) % 4;
	return spiralRecursion(top, bottom, left, right, direction, input_array, result, resIndex, eles);
}
int *spiral(int rows, int columns, int **input_array)
{
	int top = 0, bottom = rows - 1, left = 0, right = columns - 1, direction = 0,resIndex=0;
	int *result = (int *)malloc(rows*columns*sizeof(int));
	if(rows<=0 || columns <=0 ||input_array==NULL)return NULL;
	return spiralRecursion(top, bottom, left, right, direction,input_array, result, resIndex,rows*columns);
}
