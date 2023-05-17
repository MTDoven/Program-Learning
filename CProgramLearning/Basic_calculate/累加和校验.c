#include<stdio.h>
#include<string.h>

int main(){
    char strr[110]="\0";
    char temp[110]="\0";
    int sum=0;
    int times=0;
    int sign=1;
    //gets(strr);
    while(1){
        sign=scanf("%s",&temp);
        if(sign==EOF) break;
        strcat(strr,temp);
        times++;
    } times--;

    //printf("%s",strr);

    for(int i=0; i<strlen(strr); i++)
        sum += strr[i];
    sum += times*32;

    //sum = sum%(16*16);
    //sum = (int)(unsigned char)(sum&0xFF);
    sum = (char)(sum);
    printf("%d",sum);
    return 0;
}