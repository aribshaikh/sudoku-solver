/*
 * 
 * 
 * This program solves a Sudoku by taking it in a form of a 9x9 array of integers.
 * The array will have a few entries filled with numbers in
 * [1, 9], and the remaining entries set to zero.
 * 
 * For the example, the input array will
 * be
 * 
 * 5 3 0 0 7 0 0 0 0
 * 6 0 0 1 9 5 0 0 0
 * 0 9 8 0 0 0 0 6 0
 * 8 0 0 0 6 0 0 0 3
 * 4 0 0 8 0 3 0 0 1
 * 7 0 0 0 2 0 0 0 6
 * 0 6 0 0 0 0 2 8 0 
 * 0 0 0 4 1 9 0 0 5
 * 0 0 0 0 8 0 0 7 9
 * 
 * 
 * A correctly solved Sudoku is
 * one in which there are no repeated digits in any
 * row, any column, or any of the 3x3 sub-arrays that
 * make up the large 9x9 grid. Another way to think
 * about it is, every row, column, and 3x3 subgrid
 * uses all of the different digits.
 * 

 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_sudoku(int sudoku[9][9])
{
  printf("The Sudoku contains:\n");
  for (int j=0; j<9; j++)
  {
    for (int i=0; i<9;i++)
    {
      printf("%d  ",sudoku[j][i]);
    }
    printf("\n");
  }
}

int sudokuSolver(int sudoku[9][9], int row, int col)
{
	if(row == 9 || col == 9) return 1;
	
	if(sudoku[row][col] != 0)
	{
		if(col < 8)
			return sudokuSolver(sudoku, row, col + 1); 
		else if(row < 8)
			return sudokuSolver(sudoku, row + 1, 0);
		else return 1;
	}
	else
	{
		int valid;		
		for(int i = 1; i < 10; i++)
		{
			valid = 1;
			for(int j = 0; j < 9; j++)
			{
				if(sudoku[row][j] == i || sudoku[j][col] == i || sudoku[row - (row % 3) + j/3][3 * (col / 3) + j%3] == i) valid = 0;
			}
		
			if(valid)
			{
				sudoku[row][col] = i;
				
				if(col < 8)
				{
					if(sudokuSolver(sudoku, row, col + 1)) return 1;
					else sudoku[row][col] = 0;
				}
				else if(row < 8)
				{
					if(sudokuSolver(sudoku, row + 1, 0)) return 1;
					else sudoku[row][col] = 0;
				}
				else return 1;
			}
		}
	}
	return 0;
}

int checkSubGrid(int sub, int sudoku[9][9])
{
	int digits[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int row_start = sub - (sub % 3), col_start = 3 * (sub % 3);
	
	for(int i = row_start; i < 3; i++)
	{
		for(int j = col_start; j < 3; j++)
		{
			if(sudoku[i][j] != 0)
			{
				if(digits[i][j] == 0) return 0;
				digits[i][j] = 0;
			}
		}
	}
	return 1;
}

int check_sudoku(int sudoku[9][9])
{
  /*
   *  This function checks whether a Sudoku is properly
   * solved. That means that each row, column, and
   * 3x3 subgrid uses each digit only once.
   * 
   *  If *ignores* zeros, so you can use it to check
   * that a partial solution is valid
   */
   
   /*
    int digits[9] = {0};
    for(int i = 0; i < 9; i++)
    {
		digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	    for(int j = 0; j < 9; j++)
	    {
		    if(sudoku[i][j] != 0)
		    {
			    if(digits[j] == 0) return 0;
				digits[j] = 0;
		    }
	    }
		digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		for(int k = 0; k < 9; k++)
	    {
		    if(sudoku[k][i] != 0)
		    {
			    if(digits[k] == 0) return 0;
				digits[k] = 0;
		    }
	    }
		if(checkSubGrid(i, sudoku) == 0) return 0;
    }
    return 1;  
	*/
}

int solved(int sudoku[9][9])
{
  /*
   * This function checks whether a given Sudoku is
   * completely solved (it has no zeros, all digits
   * are used once per row, column, and sub-grid.
   * It returns 1 if the Sudoku is solved, zero
   * otherwise
   */
    for(int i = 0; i < 9; i++)
    {
	    for(int j = 0; j < 9; j++)
	    {
		    if(sudoku[i][j] == 0)
			    return 0;
	    }
    }
   
   if(check_sudoku(sudoku) == 0) return 0;
   return 1;
}

void solve_sudoku(int sudoku[9][9], int depth)
{
  /*
   * This function solves an input Sudoku, the
   * input has a value of 0 for any entries that
   * are not yet decided. If no solution exists
   * the function returns the input array *exactly
   * as it was* when the function was called.
   * 
   * The 'depth' parameter is provided in case you
   * want to use it to help debug and trace your
   * code. You do not need to use it if you don't
   * want to, and the problem can be solved without
   * using the depth value at all. 
   * 
   * The automated checker won't look at the depth
   * either.
   */
	sudokuSolver(sudoku, 0, 0);	
}

#ifndef __testing

int main()
{
  
   int Sudoku[9][9]={{5, 3, 0, 0, 7, 0, 0, 0, 0},
					 {6, 0, 0, 1, 9, 5, 0, 0, 0},
					 {0, 9, 8, 0, 0, 0, 0, 6, 0},
					 {8, 0, 0, 0, 6, 0, 0, 0, 3},
					 {4, 0, 0, 8, 0, 3, 0, 0, 1},
					 {7, 0, 0, 0, 2, 0, 0, 0, 6},
					 {0, 6, 0, 0, 0, 0, 2, 8, 0},
					 {0, 0, 0, 4, 1, 9, 0, 0, 5},
					 {0, 0, 0, 0, 8, 0, 0, 7, 9}};


  printf("Input puzzle is:\n");
  print_sudoku(Sudoku);
  
  solve_sudoku(Sudoku,0);
  
  printf("Solution is:\n");
  print_sudoku(Sudoku);
  
}

#endif