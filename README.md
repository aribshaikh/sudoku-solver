# sudoku-solver
This program solves a Sudoku by taking it in a form of a 9x9 array of integers.
  The array will have a few entries filled with numbers in
  [1, 9], and the remaining entries set to zero.
  
  For the example, the input array will
  be
  
   int Sudoku[9][9]={{5, 3, 0, 0, 7, 0, 0, 0, 0},
					 {6, 0, 0, 1, 9, 5, 0, 0, 0},
					 {0, 9, 8, 0, 0, 0, 0, 6, 0},
					 {8, 0, 0, 0, 6, 0, 0, 0, 3},
					 {4, 0, 0, 8, 0, 3, 0, 0, 1},
					 {7, 0, 0, 0, 2, 0, 0, 0, 6},
					 {0, 6, 0, 0, 0, 0, 2, 8, 0},
					 {0, 0, 0, 4, 1, 9, 0, 0, 5},
					 {0, 0, 0, 0, 8, 0, 0, 7, 9}};
  
 - Conditions on the input Sudoku
  	- It will have AT LEAST ONE DIGIT in each
  	3x3 subgrid. Likely there will be several
 	  3x3 subgrids with several digits already
 	  set to some value.

  - Solution outputs
  	- It should return a solution if there
  	  exists one.
  	- If no solution can be found, it will return the
 	  original input array
 
