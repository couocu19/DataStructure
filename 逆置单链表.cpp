#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct node{
	DataType data;
	struct node *next;
}Lnode,*Linklist;

//ͷ�巨����������
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
//β�巨����������
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
//����������

void Display(Linklist A){
	while(A->next!=NULL){
		printf("%d ",A->next->data); //���ʱ����ͷ��� 
		A = A->next;
	}
	
} 
//�����������
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
	printf("��ʼ����������:\n");
	L =  BCreateList();
	Display(L);
	Reverse(L);
	printf("���ú�ĵ�����Ϊ:\n");
	Display(L);
}


