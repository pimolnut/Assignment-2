#include <stdio.h> 
int main(){
    int a;
    int bit[32];
    int i=0 ;
    printf("Enter number : ");
    scanf("%d",&a);
    do
    {
        bit[i++]=a%2;
        a=a/2;
    } while (a>0);
    for (int j = i-1; j>=0; j--)
    {
        printf("%d",bit[j]);
    }
}