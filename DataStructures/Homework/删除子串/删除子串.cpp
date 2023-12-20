//删除子串的程序代码
#include<stdio.h>
#include<string.h>
#include<malloc.h>
//顺序串的结构类型定义
#define maxsize 100
typedef struct
{  
	char str[maxsize];
    int len;
}seqstring;

void strPut(seqstring*);
void strDelete(seqstring*,int,int);
int main()
{
	seqstring*S;
	int i,m;
	S=(seqstring*)malloc(sizeof(seqstring));
	printf("输入串："); gets(S->str);
	S->len=strlen(S->str);
	strPut(S);
	printf("删除的开始位置:");scanf("%d",&i);
	printf("删除的字符个数:");scanf("%d",&m);
	strDelete(S,i,m);
	strPut(S);
	return 0;
}

//输出串
void strPut(seqstring*S)
{
	int i;
	for(i=0;i<S->len;i++)
		printf("%c",S->str[i]);
	printf("\n");
}

//添加删除子串算法
void strDelete(seqstring *S, int i, int m) {
    if (i < 0 || i >= S->len || m < 0 || i + m > S->len) {
        printf("参数不合法\n"); return;
    }
    for (int j = i + m; j < S->len; j++) {
        S->str[j - m] = S->str[j]; // 将后面的字符前移
    }
    S->len -= m; // 更新长度
}

