#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define max 50

int inc[max],w[max],sum,n;
int swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int prom(int i,int wt,int t)
{
    return(((wt+t)>=sum)&&((wt==sum)||(wt+w[i+1]<=sum)));
}
void sumset(int i,int wt,int t)
{
    int j;
    if(prom(i,wt,t))
    {
        if(wt==sum)
        {
            printf("\n{\t");
            for(j=0;j<=i;j++)
                if(inc[j])
                    printf("%d\t",w[j]);
            printf("}\n");
        }
        else
        {
            inc[i+1]=true;
            sumset(i+1,wt+w[i+1],t-w[i+1]);
            inc[i+1]=false;
            sumset(i+1,wt,t-w[i+1]);
        }
    }
}
int main()
{
    int i,j,tmp,t=0;
    printf("Enter how many numbers to read");
    scanf("%d",&n);
    printf("Enter the value for all nos");
    for(i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
        t+=w[i];
    }
    printf("Enter sum");
    scanf("%d",&sum);
    for(j=0;j<n-1;j++){
        if(w[j]>w[j+1])
        {
            swap(w[j],w[j+1]);
        }
    }
    printf(" Given %d numbers as Input\n",n);
    for(i=0;i<n;i++)
        printf("%d\t",w[i]);

    if(t<sum)
        printf("not possible");
    else
    {
        for(i=0;i<n;i++)
            inc[i]=0;
        printf("\nAnd soloution is as bellow \n");
        sumset(-1,0,t);
    }
    return 0;
}