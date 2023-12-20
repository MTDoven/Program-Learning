//ϣ������ĳ������
#include<stdio.h>
//˳���ṹ���Ͷ���
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
    rectype r[N+D1];//D1��Ԫ�ش�ż����ڣ�N��Ԫ�ش�ż�¼
    int d[3]={5,3,1};//����3�˵�����	
	create(r,N);//������ż�¼��˳���
	printf("����ǰ�����ݣ�");
	print(r,N);//�������ǰ�ļ�¼��
	shellsort(r,d);//ϣ������
	printf("���������ݣ�");
	print(r,N);//��������ļ�¼��
	return 0;
}

//����˳���
void create(rectype r[],int n)
{
	printf("����10����������");
	for(int i=0;i<n;i++)
		scanf("%d",&r[D1+i].key);
}

//���˳���
void print(rectype r[],int n)
{
	for(int i=0;i<n;i++)
		printf("%5d",r[D1+i].key);
	printf("\n");
}

//���ϣ�������㷨
void shellsort(rectype r[], int d[]) {
    int i, j, k, m;
    rectype temp;
    for (m = 0; m < 3; m++) { // ���ȡ������ֵ
        int dk = d[m]; // ��ǰ����
        for (i = dk; i < N; i++) { // ����ǰ�������в�������
            temp = r[i + D1]; // ȡ�����������еĵ�i����Ϊ������Ԫ��
            j = i - dk; // ��������һ��λ��
            while (j >= 0 && temp.key < r[j + D1].key) { // Ѱ�Ҳ���λ��
                r[j + dk + D1] = r[j + D1]; // �����ƶ�
                j -= dk; // ������ǰѰ��
            }
            r[j + dk + D1] = temp; // ����Ԫ��
        }
    }
}