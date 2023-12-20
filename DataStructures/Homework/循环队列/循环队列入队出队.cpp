//ѭ��������ӳ���
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//ѭ�����еĽṹ���Ͷ���
const int m=5;
typedef int datatype;
typedef struct
{   datatype sequ[m];
    int  rear, quelen;
}qu;
void setnull(qu*);
void enqueue(qu*, datatype);
datatype *dequeue(qu*);

int main()
{  qu *sq;
   datatype x, *p;
   int key;
   sq=(qu*)malloc(sizeof(qu));
   setnull(sq);
   do
   {  printf("1.Enter Queue   2.Delete Queue   -1.Quit:");
      scanf("%d",&key);
      switch(key)
      {  case 1:  printf("Enter the Data:"); scanf("%d",&x);
		          enqueue(sq,x);  break;
	     case 2:  p=dequeue(sq);
		          if(p!=NULL) printf("%d\n",*p);
		          break;
	     case -1: exit(0);
      }
   }while(1);
   return 0;
}

//�ÿն�
void setnull(qu *sq)
{  sq->rear=m-1;
   sq->quelen=0;
}

//�������㷨
void enqueue(qu *sq, datatype x) {
    if (sq->quelen >= m) {
        printf("Queue is full\n");
    } else {
        sq->rear = (sq->rear + 1) % m;
        sq->sequ[sq->rear] = x;
        sq->quelen++;
    }
}


//��ӳ����㷨
datatype *dequeue(qu *sq) {
    if (sq->quelen <= 0) {
        printf("Queue is empty\n");
        return NULL;
    } else {
        int front = (sq->rear - sq->quelen + 1 + m) % m;  // �������ͷ��Ԫ�ص�λ��
        datatype *result = (datatype*)malloc(sizeof(datatype));
        *result = sq->sequ[front];
        sq->quelen--;
        return result;
    }
}



