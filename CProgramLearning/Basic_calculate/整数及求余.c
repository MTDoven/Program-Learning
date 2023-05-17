#include<stdio.h>

int main(){
    int a,b;
    char c;
    scanf("%d,%d,%c",&a,&b,&c);
    printf("%d,%d,%d",a/b/c,a%b%c,a/b%c);

    return 0;
}