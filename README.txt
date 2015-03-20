PROBLEM: 8queens is a problem where we should arrange N queens in an N*N chess board. In this arrangment no queen is allowed to cut each other. A queen can move 
horizontaly, 
vertically, diagonally.

ALGORITHM: 
1. Accept N. 
2. Initialize all the value of the matrix to zero. 
3. Iterate through each value in the matrix. If the values in the corresponding row , column and the diagonals are zero then change that value to 1. 
4. Push that row and column in a stack. 
5. After completion if the number of 1s is not N then backtracking is done. 
6. Pop values from the stack and change that value to 0 and go to step 3 for the next value.
7. Repeat this until you get N queens.

This program works in DEV-C++ version 5.8.3.

Screenshots are attached in this folder