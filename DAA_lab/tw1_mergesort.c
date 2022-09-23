#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[1000],b[1000];

void mergeSort(int s,int e){
    int mid;
    if(s<e){
        mid=(s+e)/2;
        mergeSort(s,mid);
        mergeSort(mid+1,e);
        merge(s,mid,e);
    }
}
void merge(int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k=low;
    while (i<=mid && j<=high)
    {
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    while (i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;
    }
    while (j<=high)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    for(int i=low;i<=high;i++)
    {
        a[i]=b[i];
    }
}


int main(){
  int n;
  clock_t s,e;
  double cpu;
  printf("Enter the size of an Array \n");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    a[i]=rand()%100;
  }
  printf("The Random Elements into Array\n");
  for(int i=0;i<n;i++){
    printf("%d\t",a[i]);
  }
  s=clock();
  for(int i=0;i<1000;i++){
    for(int j=0;j<1000;j++){
        mergeSort(0,n-1);
    }
  }
  e=clock();
  cpu=(double)(e-s)/CLK_TCK;
  printf("\nThe Sorted Array\n");
    for(int i=0;i<n;i++){
        printf("%d\t",b[i]);
    }

  printf("\nCPU execution time %f",cpu);
}