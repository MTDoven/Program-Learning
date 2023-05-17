
/* This function is used to check if the input is a prime number
if it is, it will return 0 means false. Otherwise, 1 means ture. */
//return: 1 means true; 0 means false.
int IsPrime(int n){
    if(n<=3)
        return n>1;
    for(int i=2; i<n; i++)
        if(n%i==0) return 0;
    return 1;
}

/* This function is used to decompose the number to primes
if you input 0 it will return 1, and return the primes_list with [0,-1]
if you input 1 it will return 1, and return the primes_list with [1,-1]
if any number else, it will return 0 and all the primes end with "-1"
if you input a wrong number, such as "-2", it will return -1 and [-1] */
//return: 1 means get [0||1] input; 0 means a normal number; -1 means inputted an wrong number.
int DecomposeToPrime(int* primes, int number){
    if(number<0) return -1;
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




