#include<stdio.h>

int main(){
    int a,b;
    int gcd=0;
    int temp;
    scanf("%d %d", &a, &b);

    temp = (b<a)?b:a;
    if(a==0||b==0){
        printf("%d",(a==0)?b:a);
        return 0;
    }
    for(int i=1; i<=temp; i++){
        if(a%i==0 && b%i==0){
            gcd=(i>gcd)?i:gcd;
        }
    }

    printf("%d",gcd);

    return 0;
}