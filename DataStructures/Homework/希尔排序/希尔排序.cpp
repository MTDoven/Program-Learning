//希尔排序的程序代码
#include<stdio.h>
//顺序表结构类型定义
typedef int datatype;
typedef struct{
	int key;
	datatype data;
}rectype;
const int N=10;
const int D1=5;

void create(rectype[],int);
void print(rectype[],int);
void shellsort(rectype[],int[]);

int main()
{
    rectype r[N+D1];//D1个元素存放监视哨，N个元素存放记录
    int d[3]={5,3,1};//设置3趟的增量	
	create(r,N);//建立存放记录的顺序表
	printf("排序前的数据：");
	print(r,N);//输出排序前的记录表
	shellsort(r,d);//希尔排序
	printf("排序后的数据：");
	print(r,N);//输出排序后的记录表
	return 0;
}

//建立顺序表
void create(rectype r[],int n)
{
	printf("输入10个整型数：");
	for(int i=0;i<n;i++)
		scanf("%d",&r[D1+i].key);
}

//输出顺序表
void print(rectype r[],int n)
{
	for(int i=0;i<n;i++)
		printf("%5d",r[D1+i].key);
	printf("\n");
}

//添加希尔排序算法
void shellsort(rectype r[], int d[]) {
    int i, j, k, m;
    rectype temp;
    for (m = 0; m < 3; m++) { // 逐个取出增量值
        int dk = d[m]; // 当前增量
        for (i = dk; i < N; i++) { // 按当前增量进行插入排序
            temp = r[i + D1]; // 取出无序序列中的第i个作为待插入元素
            j = i - dk; // 序列中上一个位置
            while (j >= 0 && temp.key < r[j + D1].key) { // 寻找插入位置
                r[j + dk + D1] = r[j + D1]; // 数据移动
                j -= dk; // 继续向前寻找
            }
            r[j + dk + D1] = temp; // 插入元素
        }
    }
}