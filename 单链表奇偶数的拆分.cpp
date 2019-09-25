#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct node{
	DataType data;
	struct node *next;
}*Linklist,Lnode;

Linklist CreateList(){
	Linklist H = (Linklist)malloc(sizeof(Lnode));
	H->next = NULL;
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
	r->next = NULL;
	return H;
}

void printList(Linklist L){
	while(L->next){
		printf("%d ",L->next->data);
		L = L->next;
	}
	printf("\n");
}

//将单链表拆成奇链和偶链 
//void OddAndEven(Linklist L,Linklist P,Linklist Q){
//	Linklist H = L->next;
//	while(L->next!=NULL){
//		L->next = H->next;
//		if((H->data)%2==0){
//			H->next = P->next;
//			P->next = H;
//		}else{
//			H->next = Q->next;
//			Q->next = H;
//		}
//
//	}
//	free(L)
//	printList(P);
//	printList(Q);
//}
void OddAndEven(Linklist L){
	Linklist H = L->next;
	Lnode *p,*q;
	p = L;
	q = L;
	while(H){
		if((H->data)%2==0){
			p->next = H;
			p = H;
			printf("%d ",p->data);
		}
		H = H->next;
	}
	printf("\n");
	while(H){
		if((H->data)%2==1){
			q->next = H;
			q = H;
			printf("%d ",q->data);
		}
		H = H->next;
	}
	printf("\n");
	
}

int main(){
	printf("开始建立单链表:\n");
	Linklist L = CreateList();
//	Linklist p = (Linklist)malloc(sizeof(Lnode));
//	Linklist q = (Linklist)malloc(sizeof(Lnode));
	printList(L);
	OddAndEven(L);
	// OddAndEven(L,p,q);
	 
	 return 0;

} 



