#include<stdio.h>

int calS(float a, float b, float c);

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a*a+b*b==c*c)
        printf("%d",a*b);
    else
        printf("no");

    return 0;
}

