
/* Use this function to get the maximum number in the array.
The length means the array length which is effective. */
//return: the max number in the array. if something wrong, "-1" instead.
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

/* To add up the two array inputted.
the first is a place to put the result. */
int AddArray(int* result ,int* array1, int* array2, int length){
    for(int i=0; i<length; i++)
        result[i] = array1[i]+array2[i];
    return 0;
}//above add; below miner
int SubArray(int* result ,int* array1, int* array2, int length){
    for(int i=0; i<length; i++)
        result[i] = array1[i]-array2[i];
    return 0; 
}

/* Use this function to sort the numbers in a array
if the mode paramter was set to "0", means sort from smaller to bigger.
if it is set to "1", means sort from bogger to smaller. */
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

/* Use this function to turn the array upside down*/
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

/* Use this function to save the number to the array in the next position*/
int SaveToArray(int* array, int number){
    static int index=-1;
    array[++index] = number;
    return 0;
}

/* Use this function to search where is the vary number in the array,
The first position was an array, the second was the longth, the third is a vary number.*/
int SearchNumber(int array[], int length, int number){
    for(int i=0; i<length; i++)
        if(array[i]==number) return i;
}