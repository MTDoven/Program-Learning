#include<stdio.h>
#include<string.h>
int AsciiToInt(char ascii);
int PopSort(int* array, int length);
void ShowArray(int* array, int length);
int UpsideDown(int* array, int length);

int main(){
    char str[16]="";
    int len;
    scanf("%s",&str);
    len = strlen(str);

    int numbers[16]={0};
    int index = -1;
    while(str[++index]!=0)
        numbers[index] = AsciiToInt(str[index]);
    PopSort(numbers, len);
    UpsideDown(numbers, len);

    ShowArray(numbers, len);
    
    return 0;
}



int AsciiToInt(char ascii){
    if(ascii>=48 && ascii<=57){
        return ascii-48;
    }
    else return -1;
}

int PopSort(int* array, int length){
    int temp;
    for(int i=0; i<length; i++)
        for(int j=0; j<length-i-1; j++){
            if(array[j]>array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp; }
        }//the upper is small2big the lower is big2small
    return 0;
}

void ShowArray(int* array, int length){
    if(length!=0){
        for(int i=0; i<length; i++)
            printf("%d ", array[i]);
    } else{//if length is a number according to the number
        int index=-1;
        while(array[++index]!=-1)
            printf("%d ", array[index]);
    }//if length is 0 according to the -1
}

int UpsideDown(int* array, int length){
    int temp;
    if(length%2==0)
        for(int i=0; i<(length/2); i++){
            temp = array[i];
            array[i] = array[length-i-1];
            array[length-i-1] = temp;
        }//the number is even
    else if(length%2==1)
        for(int i=0; i<((length+1)/2)-1; i++){
            temp = array[i];
            array[i] = array[length-i-1];
            array[length-i-1] = temp;
        }//the number is odd
    return 0;
}