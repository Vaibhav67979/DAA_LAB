#include<stdio.h>

void printM(int D[10][10],int n){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            printf("%d\t",D[i][j]);
        printf("\n");
    }
}

void floyds(int D[10][10],int n){
    int i,j,k;
    for(k=1;k<=n;k++){
        printf("Matrix D(%d)\n",k);
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(i==j)
                    D[i][j]=0;
                else
                    D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
            }
        }
        printM(D,n);
    }
}
int min(int a,int b){
    return (a<b)?a:b;
}

int main(){
    int D[10][10],n,i,j;
    // clrscr();
    printf("\nEnter the number  of vertices:");
    scanf("%d",&n);
    printf("\nEnter the cost of matrix:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&D[i][j]);
        }
    }

    floyds(D,n);
    printf("\nThe Final Cost of Matrix:\n");
    printM(D,n);
    return 0;
}
