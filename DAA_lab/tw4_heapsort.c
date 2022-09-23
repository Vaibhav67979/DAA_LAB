#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 10000
int  A[MAX];
void exchange(int *p, int *q){
    int t;
    t = *p;
    *p = *q;
    *q =t;
}

void HeapSort(int *A, int n){
    int i;
    for(i = n/2; i>=1; i--){
            Heapify(A,n,i);
    }
    for(i = n; i>=2; i--){
        exchange(&A[i], &A[1]);
        Heapify(A, i-1, 1);
    }
}

void Heapify(int *A, int n, int i){
    int largest, l, r;
    largest = i;
    l = 2*i; r = 2*i+1;

    if(l <= n && A[l] > A[largest]){
        largest = l;
    }
    if(r <= n && A[r] > A[largest]){
        largest = r;
    }
    if(largest != i){
        exchange(&A[largest], &A[i]);
        Heapify(A, n, largest);
    }
}

int main(){
    int i, n;
    time_t start, end;
    double cpu_exe_time;

    printf("Heap Sort..\n");
    printf("Enter the value of n: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        A[i] = rand() % 100;
    }
    printf("\nArray before sorting: \n");
    for(i = 1; i<=n; i++){
        printf("%d ", A[i]);
    }
    start = clock();
    for(int i=0; i<10000; i++){
        HeapSort(A,n);
    }
    end = clock();

    printf("\nArray after sorting: \n");
    for(i = 1; i<=n; i++){
        printf("%d ", A[i]);
    }

    cpu_exe_time = (double) (end - start)/CLK_TCK;
    printf("\nExecution time of heap sort is %lf", cpu_exe_time);
}