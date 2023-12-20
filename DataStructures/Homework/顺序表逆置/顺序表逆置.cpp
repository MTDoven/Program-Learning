//顺序表逆置.cpp
#include<stdio.h>
#include<malloc.h>
typedef char datatype;
const int maxsize=1024;
typedef struct
{ datatype data[maxsize];
  int last;
}sequenlist;
void create(sequenlist*&);
void print(sequenlist*);
void invert(sequenlist*);

int main()
{
	sequenlist*L;
	create(L);//建立顺序表
	print(L);//输出顺序表
	invert(L);//调用顺序表逆值的函数
	print(L);//输出顺序表
	return 0;
}

//建立顺序表
void create(sequenlist*&L)
{
	L=(sequenlist*)malloc(sizeof(sequenlist));
	L->last=0;
	char ch;
	while((ch=getchar())!='*')
	{   
		L->last++;
		L->data[L->last]=ch;
	}
}

//输出顺序表
void print(sequenlist*L)
{
	for(int i=1;i<=L->last;i++)
		printf("%2c",L->data[i]);
	printf("\n");
}

//添加顺序表逆置算法
void invert(sequenlist* L)
{
    int i = 1, j = L->last; // i是起始位置，j是结束位置
    while(i < j) {
        // 交换两端的元素
        datatype temp = L->data[i];
        L->data[i] = L->data[j];
        L->data[j] = temp;

        // 移动指针
        i++;
        j--;
    }
}
