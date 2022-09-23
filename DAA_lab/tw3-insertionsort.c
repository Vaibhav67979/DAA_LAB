#include<stdio.h>
#include<time.h>
#include <stdlib.h>
#define MAX 10000
int A[MAX];
void insertionSort(int *A, int n){
	int i,j,temp;
	for(i=1 ; i<n ; i++){
		temp = A[i];
		j = i-1;
		while(A[j]>=temp && j>=0){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = temp;
	}
}
int main(){
	int i,j,n;
	time_t start,end;
	double cpu_exe_t;
	printf("enter number of elements: ");
	scanf("%d",&n);
	for(i=0 ; i<n ; i++)
		A[i] = rand()%100;
	printf("\n the array elements are: \n");
	for(i=0 ; i<n ; i++)
		printf("%d  ",A[i]);
	start = clock();
    for(int l=0 ; l<1000 ; l++)
	for(int k=0 ; k<1000 ; k++){
		insertionSort(A,n);
	}
	end = clock();
	cpu_exe_t = (double)(end-start)/CLOCKS_PER_SEC;
	printf("\norder of sorted elements: \n");
	for(i=0 ; i<n ; i++)
		printf("%d  ",A[i]);
	printf("\nCPU execution time:  %.2f \n",cpu_exe_t);
	return 0;
}
