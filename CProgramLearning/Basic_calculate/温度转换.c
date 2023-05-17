#include<stdio.h>

int main(){
    int F;
    float C;
    scanf("%d",&F);
    C = (F-32)*5/9.0;
    printf("%.2f",C);
    return 0;
}