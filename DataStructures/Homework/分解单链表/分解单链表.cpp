#include<stdio.h>
#include<malloc.h>
typedef char datatype;
typedef struct node
{  datatype data;
   struct node *next;
}linklist;
void create(linklist*&);
void resolve(linklist*,linklist*,linklist*,linklist*);
void insert(linklist*,linklist*);
void print1(linklist*);
void print2(linklist*);
int main()
{  linklist *head,*letter,*digit,*other;
   create(head);
   print1(head);
   letter=(linklist*)malloc(sizeof(linklist));//����3����ѭ������
   letter->next=letter;
   digit=(linklist*)malloc(sizeof(linklist));
   digit->next=digit;
   other=(linklist*)malloc(sizeof(linklist));
   other->next=other;
   resolve(head,letter,digit,other);//���÷ֽⵥ����ĺ���
   print2(letter);//���ѭ������
   print2(digit);
   print2(other);
   return 0;
}

//����������
void create(linklist*&head)
{  datatype x;
   linklist *s,*r;
   head=new linklist;
   r=head;
   while((x=getchar())!='$')
   {  
	  s=(linklist*)malloc(sizeof(linklist));
      s->data=x;
	  r->next=s;
	  r=s;
   }
   r->next=NULL;
}

//��ѭ�������в���
void insert(linklist*h,linklist*p)
{  linklist *q=h;
   while(q->next!=h) q=q->next;
   q->next=p;
   p->next=h;
}

//���������
void print1(linklist*head)
{  linklist *p=head->next;
   while(p!=NULL)
   {  printf("%c",p->data);
      p=p->next;
   }
   printf("\n");
}

//���ѭ������
void print2(linklist*head)
{  linklist *p=head->next;
   while(p!=head)
   {  
	   printf("%c",p->data);
       p=p->next;
   }
   printf("\n");
}

//��Ӱ���ĸ�����֡������ַ��ֽⵥ�����㷨
void resolve(linklist *head, linklist *letter, linklist *digit, linklist *other) {
    linklist *p = head->next;
    while (p != NULL) {
        // ����һ���½ڵ�ѵ�ǰ�ڵ����ݴ���
        linklist *newNode = (linklist*)malloc(sizeof(linklist));
        newNode->data = p->data;
        newNode->next = NULL;

        // ����ĸ�Ͳ���letter����
        if ((newNode->data >= 'A' && newNode->data <= 'Z') || 
            (newNode->data >= 'a' && newNode->data <= 'z')) {
            insert(letter, newNode);
        }
        // �����־Ͳ���digit����
        else if (newNode->data >= '0' && newNode->data <= '9') {
            insert(digit, newNode);
        }
        // �����ľͲ���other����
        else {
            insert(other, newNode);
        }

        // ������һ���ڵ�
        p = p->next;
    }
}
