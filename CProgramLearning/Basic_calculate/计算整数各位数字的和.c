#include<stdio.h>
#include<math.h>

int main(){
    double n;
    int sum=0;
    scanf("%lf",&n);
    
    for(int i=0; i<9; i++){
        sum = sum + (int)n%10;
        n = (double)(int)n/10.0;
        //printf("%d ",sum);
    }
    
    printf("%d ",sum);

    return 0;
}