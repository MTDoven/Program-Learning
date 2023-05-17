#include<stdio.h>
#include<string.h>

int main(){
    int a,b;
    char sign;
    scanf("%d%c%d",&a,&sign,&b);

    if(sign=='+'){
        printf("%d%c%d=%d",a,sign,b,a+b);}
    if(sign=='-'){
        printf("%d%c%d=%d",a,sign,b,a-b);}
    if(sign=='*'){
        printf("%d%c%d=%d",a,sign,b,a*b);}
    if(sign=='/'){
        printf("%d%c%d=%d",a,sign,b,a/b);}
    if(sign=='%'){
        printf("%d%c%d=%d",a,sign,b,a%b);}

    return 0;
}