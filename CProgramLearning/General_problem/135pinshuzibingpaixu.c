#include<stdio.h>
#include<string.h>
int AsciiToInt(char ascii);
int SaveToArray(int* array, int number);
int PopSort(int* array, int length);
int UpsideDown(int* array, int length);
void ShowArray(int* array, int length);
int array[128]={0};
char str[128]="";



int main(){
    char now_ori=-1;
    int now_number=-1;
    int now_old=-1;
    int flag = 0;
    int count = 0;
    scanf("%s",str);

    for(int i=0; i<strlen(str); i++){
        now_ori = str[i];
        if(flag==1 && AsciiToInt(now_ori)==-1){
            SaveToArray(array, now_number);
            count++;
            flag = 0;
        }
        if(flag==0){
            now_number = AsciiToInt(now_ori);
            if(now_number!=-1){
                flag = 1;
            }
        }
        else if(flag==1){
            now_number = now_number*10 + AsciiToInt(now_ori);
        }
    }
    if(now_number!=-1){
        SaveToArray(array, now_number);
        count++;
    }

    PopSort(array, count);
    UpsideDown(array, count);
    ShowArray(array, count);

    return 0;
}



int AsciiToInt(char ascii){
    if(ascii>=48 && ascii<=57){
        return ascii-48;
    }
    else return -1;
}
int SaveToArray(int* array, int number){
    static int index=-1;
    array[++index] = number;
    return 0;
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
