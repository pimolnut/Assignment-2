#include<stdio.h>
int main(){
    int n;
    printf("Enter number : ");
    scanf("%d",&n);
    int e = (n*(n-1))/2 ;
    printf("%d",e);
    return 0 ;
}