 /*Name: Abdirisak Arr
  *Date: 30/07/2019
  *Description: Program that asks user to enter the numbers from 1 to 16
                (in any order) and then displays the numbers in a 4 by 4
                arrangment, followed by the sums of the rows, columns, 
                and diagonals
  */
  
#include <stdio.h>

int main(void)
{
	int row_Sum1, row_Sum2, row_Sum3, row_Sum4;
	int column_Sum1, column_Sum2, column_Sum3, column_Sum4;
	int diagonal_Sum1, diagonal_Sum2;
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
	
	printf("Enter the numbers from 1 to 16 in any order:\n");
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &o, &p);
	
	row_Sum1 = a + b + c + d;
	row_Sum2 = e + f + g + h;
	row_Sum3 = i + j + k + l;
	row_Sum4 = m + n + o + p;
	
	column_Sum1 = a + e + i + m;
	column_Sum2 = b + f + j + n;
	column_Sum3 = c + g + k + o;
	column_Sum4 = d + h + l + p;
	
	diagonal_Sum1 = a + f + k + p;
	diagonal_Sum2 = d + g + j + m;
	
	printf("\n%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n", a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p);
	printf("\nRow sums: %d %d %d %d\n", row_Sum1, row_Sum2, row_Sum3, row_Sum4);
	printf("Column sums: %d %d %d %d\n", column_Sum1, column_Sum2, column_Sum3, column_Sum4);
	printf("Diagonal sums: %d %d", diagonal_Sum1, diagonal_Sum2);
	
	return 0;
	
}
