#include<stdio.h>
void printsqu();
short squ[5000][5000];
short n,m;//n行m列

int main(){
    
    scanf("%hd %hd", &n, &m);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%hd", &squ[i][j]);
    //读入矩阵
    printsqu();
    return 0;
}




void printsqu(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            printf("%hd ", squ[i][j]);
        printf("\n");
    }
} //输出矩阵
