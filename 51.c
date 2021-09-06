#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    int x,y=0;
    printf("Enter string: ");
    scanf("%s",str);
    for(int i = 0; i<strlen(str) ;i++)
    {
        if (str[i]>='a' && str[i]<='z')
        {
            x++;
        }
    }
    printf("Lowercase letter : %d\n",x);
    for(int j = 0; j<strlen(str) ;j++)
    {
        if (str[j]>='A' && str[j]<='Z')
        {
            y++;
        }
    }
    printf("Capital letter : %d\n",y);
}
        