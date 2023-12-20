//˫����������ĳ������
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//˳���ṹ���Ͷ���
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
	printf("����ǰ�����ݣ�");
	print(r,n);
	dbubblesort(r,n);
	printf("���������ݣ�");
	print(r,n);
	return 0;
}

//����˳���
void create(sequenlist r[],int n)
{
	srand(time(0));
	for(int i=1;i<=n;i++)
		r[i].key=rand()%90;
}

//���˳���
void print(sequenlist r[],int n){
	for(int i=1;i<=n;i++)
		printf("%5d",r[i].key);
	printf("\n");
}

//���˫�����������㷨
void dbubblesort(sequenlist r[], int n) {
    int low = 1, high = n; // ��������Χ�����½�
    int flag = 1; // ��־�����������Ż��������
    while (low < high && flag == 1) {
        flag = 0;
        for (int j = low; j < high; j++) {
            if (r[j].key > r[j+1].key) {
                sequenlist temp = r[j]; // ����Ԫ��
                r[j] = r[j+1];
                r[j+1] = temp;
                flag = 1; // �����˽�������Ҫ��������
            }
        } // �ӵ͵��߽���ð������
		high--; // β���Ѿ��̶�����Ҫ������
        for (int j = high; j > low; j--) {
            if (r[j].key < r[j-1].key) {
                sequenlist temp = r[j]; // ����Ԫ��
                r[j] = r[j-1];
                r[j-1] = temp;
                flag = 1; // �����˽�������Ҫ��������
            }
        } // �Ӹߵ��ͽ���ð������
		low++; // ͷ���Ѿ��̶�����Ҫ������
    }
}





