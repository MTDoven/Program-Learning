
/* This function is used to translate the ascii to number.
if the result is not a number, it will return -1. */
int AsciiToInt(char ascii){
    if(ascii>=48 && ascii<=57){
        return ascii-48;
    }
    else return -1;
}