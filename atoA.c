#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    printf("Enter string: ");
    scanf("%s",str);
    for(int i = 0; i<strlen(str) ;i++)
    {
        if (str[i]>='a' && str[i]<='z')
        {
            str[i]=str[i]-32;
        }else if (str[i]>='A'&&str[i]<='Z')
        {
            str[i]=str[i]+32;
        }
    }
    printf("%s",str);

}