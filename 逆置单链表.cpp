#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct node{
	DataType data;
	struct node *next;
}Lnode,*Linklist;

//头插法建立单链表
Linklist ACreateList(){
	Linklist H = (Linklist)malloc(sizeof(Lnode));
	H->next = NULL;
	Lnode *s;
	int x;
	scanf("%d",&x);
	while(x!=-1){
		s = (Linklist)malloc(sizeof(Lnode));
		s->data = x;
		s->next = H->next;
		H->next = s;
		scanf("%d",&x);
	}
	return H;
} 
//尾插法建立单链表
Linklist BCreateList(){
	Linklist H = (Linklist)malloc(sizeof(Lnode));
	H->next =  NULL;
	Lnode *r,*s;
	r = H;
	int x;
	scanf("%d",&x);
	while(x!=-1){
		s = (Linklist)malloc(sizeof(Lnode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d",&x);
	}
	r->next =  NULL;
	return H;
	
} 
//单链表的输出

void Display(Linklist A){
	while(A->next!=NULL){
		printf("%d ",A->next->data); //输出时跳过头结点 
		A = A->next;
	}
	
} 
//单链表的逆置
void Reverse(Linklist H){
	Lnode *p,*q;
	p = H->next;
	H->next =  NULL;
	while(p){
		q = p;
		p = p->next;
		q->next = H->next;
		H->next = q; 
	}
	
} 

int main(){
	Linklist L;
	printf("开始建立单链表:\n");
	L =  BCreateList();
	Display(L);
	Reverse(L);
	printf("逆置后的单链表为:\n");
	Display(L);
}


