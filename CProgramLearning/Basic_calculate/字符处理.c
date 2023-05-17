#include<stdio.h>

int main(){
    char x;
    scanf("%c",&x);

    if(x>=65&&x<65+26)
        x = x+32;
    else if(x>=97&&x<97+26)
        x = x-32;
    
    printf("%c",x);
    return 0;
}