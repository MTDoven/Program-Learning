//ɾ���Ӵ��ĳ������
#include<stdio.h>
#include<string.h>
#include<malloc.h>
//˳�򴮵Ľṹ���Ͷ���
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
	printf("���봮��"); gets(S->str);
	S->len=strlen(S->str);
	strPut(S);
	printf("ɾ���Ŀ�ʼλ��:");scanf("%d",&i);
	printf("ɾ�����ַ�����:");scanf("%d",&m);
	strDelete(S,i,m);
	strPut(S);
	return 0;
}

//�����
void strPut(seqstring*S)
{
	int i;
	for(i=0;i<S->len;i++)
		printf("%c",S->str[i]);
	printf("\n");
}

//���ɾ���Ӵ��㷨
void strDelete(seqstring *S, int i, int m) {
    if (i < 0 || i >= S->len || m < 0 || i + m > S->len) {
        printf("�������Ϸ�\n"); return;
    }
    for (int j = i + m; j < S->len; j++) {
        S->str[j - m] = S->str[j]; // ��������ַ�ǰ��
    }
    S->len -= m; // ���³���
}

