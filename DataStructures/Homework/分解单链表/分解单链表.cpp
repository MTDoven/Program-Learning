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
   letter=(linklist*)malloc(sizeof(linklist));//建立3个空循环链表
   letter->next=letter;
   digit=(linklist*)malloc(sizeof(linklist));
   digit->next=digit;
   other=(linklist*)malloc(sizeof(linklist));
   other->next=other;
   resolve(head,letter,digit,other);//调用分解单链表的函数
   print2(letter);//输出循环链表
   print2(digit);
   print2(other);
   return 0;
}

//建立单链表
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

//在循环链表中插入
void insert(linklist*h,linklist*p)
{  linklist *q=h;
   while(q->next!=h) q=q->next;
   q->next=p;
   p->next=h;
}

//输出单链表
void print1(linklist*head)
{  linklist *p=head->next;
   while(p!=NULL)
   {  printf("%c",p->data);
      p=p->next;
   }
   printf("\n");
}

//输出循环链表
void print2(linklist*head)
{  linklist *p=head->next;
   while(p!=head)
   {  
	   printf("%c",p->data);
       p=p->next;
   }
   printf("\n");
}

//添加按字母、数字、其它字符分解单链表算法
void resolve(linklist *head, linklist *letter, linklist *digit, linklist *other) {
    linklist *p = head->next;
    while (p != NULL) {
        // 创建一个新节点把当前节点数据存入
        linklist *newNode = (linklist*)malloc(sizeof(linklist));
        newNode->data = p->data;
        newNode->next = NULL;

        // 是字母就插入letter链表
        if ((newNode->data >= 'A' && newNode->data <= 'Z') || 
            (newNode->data >= 'a' && newNode->data <= 'z')) {
            insert(letter, newNode);
        }
        // 是数字就插入digit链表
        else if (newNode->data >= '0' && newNode->data <= '9') {
            insert(digit, newNode);
        }
        // 其他的就插入other链表
        else {
            insert(other, newNode);
        }

        // 继续下一个节点
        p = p->next;
    }
}
