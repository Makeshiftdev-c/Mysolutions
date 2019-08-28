/*Name: Abdirisak Arr
 *Date: 20/08/2019
 *Description: prints the values of sizeof(int), sizeof(short), sizeof(long), sizeof(float), sizeof(double),
               sizeof(long double)
 */
 
 #include <stdio.h>
 
 int main(void)
 {
 	unsigned long int a;
 	
 	a = sizeof(int);
 	printf("Number of bytes required to store int variable: %lu\n", a);
 	
 	a = sizeof(short);
 	printf("Number of bytes required to store short int variable: %lu\n", a);
 	
 	a = sizeof(long int);
 	printf("Number of bytes required to store long int variable: %lu\n", a);
 	
 	a = sizeof(float);
 	printf("Number of bytes required to store float variable: %lu\n", a);
 	
 	a = sizeof(double);
 	printf("Number of bytes required to store double variable: %lu\n", a);
 	
 	a = sizeof(long double);
 	printf("Number of bytes required to store long double variable: %lu\n", a);
 	
 	return 0;
 }
