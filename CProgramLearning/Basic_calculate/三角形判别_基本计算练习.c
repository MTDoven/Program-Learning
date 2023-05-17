#include<stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a+b>c && a-b<c && b-a<c)
        printf("%d",a+b+c);
    else if(a+c>b && a-c<b && c-a<b)
        printf("%d",a+b+c);
    else if(c+b>a && c-b<a && b-c<a)
        printf("%d",a+b+c);
    else printf("No");
    return 0;
}