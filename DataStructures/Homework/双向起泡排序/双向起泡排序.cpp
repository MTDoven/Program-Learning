//双向起泡排序的程序代码
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//顺序表结构类型定义
typedef int datatype;
typedef struct{
	int key;
	datatype data;
}sequenlist;

void create(sequenlist[],int);
void print(sequenlist[],int);
void dbubblesort(sequenlist[],int);

int main()
{
	const int n=10;
	sequenlist r[n+1];
	create(r,n);
	printf("排序前的数据：");
	print(r,n);
	dbubblesort(r,n);
	printf("排序后的数据：");
	print(r,n);
	return 0;
}

//建立顺序表
void create(sequenlist r[],int n)
{
	srand(time(0));
	for(int i=1;i<=n;i++)
		r[i].key=rand()%90;
}

//输出顺序表
void print(sequenlist r[],int n){
	for(int i=1;i<=n;i++)
		printf("%5d",r[i].key);
	printf("\n");
}

//添加双向起泡排序算法
void dbubblesort(sequenlist r[], int n) {
    int low = 1, high = n; // 设置排序范围的上下界
    int flag = 1; // 标志变量，用于优化排序过程
    while (low < high && flag == 1) {
        flag = 0;
        for (int j = low; j < high; j++) {
            if (r[j].key > r[j+1].key) {
                sequenlist temp = r[j]; // 交换元素
                r[j] = r[j+1];
                r[j+1] = temp;
                flag = 1; // 发生了交换，需要继续排序
            }
        } // 从低到高进行冒泡排序
		high--; // 尾部已经固定不需要再排序
        for (int j = high; j > low; j--) {
            if (r[j].key < r[j-1].key) {
                sequenlist temp = r[j]; // 交换元素
                r[j] = r[j-1];
                r[j-1] = temp;
                flag = 1; // 发生了交换，需要继续排序
            }
        } // 从高到低进行冒泡排序
		low++; // 头部已经固定不需要再排序
    }
}





