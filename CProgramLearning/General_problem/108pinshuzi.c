#include<stdio.h>
int AsciiToInt(char ascii);
int DecomposeToPrime(int* primes, int number);
int IsPrime(int n);
int GetMax(int* numbers, int length);

int main(){
    char input[101]="";
    char now = 0;
    int index = -1;
    int now_number = -1;
    int number = 0;
    scanf("%s", input);
    while(1){
        now = input[++index];
        if(AsciiToInt(now)!=-1){
            now_number = AsciiToInt(now);
            number = number*10+now_number;
        }
        else{
            if(now==0)
                break;
        }        
    }
    int primes[101]={0};
    int count=-1;
    DecomposeToPrime(primes, number);
    printf("%d", GetMax(primes, 0));
    return 0;
}


int AsciiToInt(char ascii){
    if(ascii>=48 && ascii<=57){
        return ascii-48;
    }
    else return -1;
}

int DecomposeToPrime(int* primes, int number){
    if(number==0 || number==1){
        primes[0]=number;
        primes[1]=-1;
        return 1;
    } //Avoid the 0 and 1 input
    primes[0]=1;
    int count=1;
    for(int i=1; i<=number; i++){
        if(number%i==0 && IsPrime(i)){
            primes[count]=i;
            count++;
        } } //Try all the number
    primes[count]=-1;
    return 0;
}


int IsPrime(int n){
    if (n<=3)
        return n>1;
    for(int i=2; i<n; i++)
        if(n%i==0) return 0;
    return 1;
}

int GetMax(int* numbers, int length){
    int max = -2147483648;
    if(length!=0){
        for(int i=0; i<length; i++)
            max = (numbers[i]>max) ? numbers[i]:max;
    } else{ // this mode above make the length a fixed number.
        int count=-1;
        if(numbers[0]==-1) return -1;
        while(numbers[++count]!=-1)
            max = (numbers[count]>max) ? numbers[count]:max;
    } // this mode below use a "-1" as the end.
    return max;
}