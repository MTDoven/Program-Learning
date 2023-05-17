#include<stdio.h>

int times=0;
int jiaogu_action(int nn);

int main(){
    int n;
    scanf("%d", &n);
    jiaogu_action(n);
    printf("%d",times);
    return 0;
}

int jiaogu_action(int nn){
    if(nn==1) return 1;
    times++;
    nn = (nn%2==0)?(nn/2):(3*nn+1);
    jiaogu_action(nn);
}