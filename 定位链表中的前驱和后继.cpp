#include<stdio.h>
#include<stdlib.h>
typedef int DataType;

typedef struct node{
	DataType data;
	struct node *next;
}*Linklist,Lnode;

Linklist CreateList(){
	int x;
	Linklist H = (Linklist)malloc(sizeof(Lnode));
	H->next = NULL;
	Lnode *r,*s;
	r = H;
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

int Locate(Linklist H,int x){
	Lnode *p;
	p = H->next;
	int i = 1;
	while(p->data!=x && p!=NULL){
		i++;
		p = p->next;
	}
	
	return i;
}

int getLength(Linklist H){
	int len = 1;
	Lnode *p = H->next;
	while(p){
		p = p->next;
		len++;
	}
	return len;
}
void PreAndLater(Linklist m,int x){
	if(x==1){
		printf("该元素无前驱，后继元素的存储位置为2\n");
	}else if(x==getLength(m)){
		printf("该元素无后继，前驱元素为%d\n",x-1);
	}else{
		printf("前驱:%d 后继:%d\n",x-1,x+1);
	}
}

int main(){
	Linklist L;
	int x;
	printf("开始建立单链表:\n");
	L =  CreateList();
	printf("请输入要定位的元素的值:\n");
	scanf("%d",&x);
	int s = Locate(L,x);
	PreAndLater(L,s);
	return 0;
}
