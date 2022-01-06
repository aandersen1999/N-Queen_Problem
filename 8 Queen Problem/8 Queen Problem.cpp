#include <stdio.h>
#include <string.h>
#include <iostream>

#define ROWS 8
#define COLUMNS 8

int count {};

int isSafe(char mat[][COLUMNS], int r, int c) 
{
    for (int i = 0; i < r; i++) 
    {
        if (mat[i][c] == 'Q') 
        {
            return 0;
        }
    }

    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) 
    {
        if (mat[i][j] == 'Q') 
        {
            return 0;
        }
    }

    for (int i = r, j = c; i >= 0 && j < COLUMNS; i--, j++)
    {
        if (mat[i][j] == 'Q') 
        {
            return 0;
        }
    }

    return 1;
}

void printSolution(char mat[][COLUMNS])
{
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
    printf("Solution: %d \n", count);
}

void nQueen(char mat[][COLUMNS], int r)
{
    if (r == ROWS) 
    {
        count++;
        printSolution(mat);
        return;
    }

    for (int i = 0; i < COLUMNS; i++) 
    {
        if (isSafe(mat, r, i)) 
        {
            mat[r][i] = 'Q';
            nQueen(mat, r + 1);
            mat[r][i] = '-';
        }
    }
}

int main()
{
    char mat[ROWS][COLUMNS];
    memset(mat, '-', sizeof mat);

    nQueen(mat, 0);

    system("pause");
    return 0;
}

