#include <stdio.h>
int main(){
    int a ;
    printf("enter number : ");
    scanf("%d",&a);
    for (int i = 1; i <= a; i++)
    {
        for (int x = 1; x <= a; x++)
        {
             printf("*");
             
        }
        printf("\n");
    }
    
    return 0;
}