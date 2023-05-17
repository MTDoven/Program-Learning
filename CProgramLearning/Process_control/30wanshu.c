#include<stdio.h>

int main(){
    int a,b;
    int sum=0;
    scanf("%d %d", &a, &b);
    
    for(int i=a; i<=b; i++){
        for(int j=1; j<i; j++){
            if(i%j==0){
                sum=sum+j;
            }
        }
        if(sum==i)
            printf("%d\n",i);
        sum = 0;
    }


    return 0;
}