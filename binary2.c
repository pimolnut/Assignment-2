#include <stdio.h> 
int main(){
    int a;
    int sum=0;
    int i,m;
    int n=1;
    printf("Enter number : ");
    scanf("%d",&a);
    for (i=a;i>0;i=i/2)
    {
        m = i%2; 
        sum=sum+(m*n);
        n=n*10;
        
    }
     printf("%d",sum);
}