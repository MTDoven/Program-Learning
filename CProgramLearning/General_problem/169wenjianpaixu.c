#include<stdio.h>
int array[128][4]={0};
long long msg[128]={0};
int PopSort(long long array[], int length);


int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d/%d/%d %d",
            &array[i][0],&array[i][1],&array[i][2],&array[i][3]);
    }
    for(int i=0; i<n; i++){
        msg[i] = (long long)array[i][0]*100*100*10000000000 + 
                 (long long)array[i][1]*100*10000000000 +
                 (long long)array[i][2]*10000000000 + 
                 (long long)array[i][3];
    }

    PopSort(msg,n);

    int year, month, day, size;
    for(int i=0; i<n; i++){
        year = (int)(msg[i]/(100*100*10000000000));
        msg[i] = msg[i]%(100*100*10000000000);
        month = (int)(msg[i]/(100*10000000000));
        msg[i] = msg[i]%(100*10000000000);
        day = (int)(msg[i]/(10000000000));
        msg[i] = msg[i]%(10000000000);
        size = (int)(msg[i]);
        msg[i] = -1;
        printf("%d/%d/%d %d\n", year, month, day, size);
    }

    return 0;
}


int PopSort(long long array[], int length){
    long long temp;
    for(int i=0; i<length; i++)
        for(int j=0; j<length-i-1; j++){
            if(array[j]<array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp; }
        }//the upper is small2big the lower is big2small
    return 0;
}









