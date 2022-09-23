#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int A[100],n;
int swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void heapsort(int *A, int n){
    int i;
    for(i=n/2;i>=1;i--){
        heapify(A,n,i);
    }
    for(i=n;i>=2;i--){
        swap(&A[i],&A[1]);
        heapify(A,i-1,1);
    }
}
void heapify(int *A, int n, int i){
    int largest,l,r;
    largest=i; l=2*i; r=2*i+1;
    if(l<=n && A[l]>A[largest]){
        largest=l; 
    }
    if(r<=n && A[r]>A[largest]){
        largest=r;
    } 
    if(largest!=i){
        swap(&A[largest],&A[i]);
        heapify(A,n,largest);
    }
}
int main(){
    int low,high;
    clock_t s,e;
    double et;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        A[i]=rand()%100;
    }
    printf("Array elements : \n");
    for(int i=1;i<=n;i++){
        printf("%d\t",A[i]);
    }
    s=clock();
    for(int i=0;i<10000;i++){
        heapsort(A,n);
    }
    e=clock();
    et = (double)(e-s)/CLK_TCK;
    printf("\nSorted array : \n");
    for(int i=1;i<=n;i++){
        printf("%d\t",A[i]);
    }
    printf("\nCPU execution time : %lf",et);
}