#include<stdio.h>
#include<math.h>

int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a*a==b*b+c*c||a*a+b*b==c*c||a*a+c*c==b*b){
        float p,S;
        p = (a+b+c)/2.0;
        S = sqrt(p*(p-a)*(p-b)*(p-c));
        printf("%.1f",S);
    } 
    else printf("NO");

    return 0;
}

