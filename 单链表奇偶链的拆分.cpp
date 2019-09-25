#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct LinkList {
	int data;
    struct LinkList *next;
}Node;
//尾插法建立单链表
Node *Create_Tail() {
	 Node *L = NULL;
	 Node *pNew, *r;
	 int x;
	 r = L;
	 scanf("%d",&x);
	 while(x != -1) {
	  pNew = (Node*)malloc(sizeof(Node));
	 	pNew->data = x;
	  if (L == NULL) {
	  	L = pNew;
	  	r = pNew;
	  } else {
		r->next = pNew;//关键代码
		r = pNew;//关键代码，尾指针移动
	  }
	  scanf("%d",&x);
	 }
	 r->next = NULL;
	 return L;
}
void Output(Node *L) {
   Node *p;
   p = L;
   while (p) {
   printf("%d ",p->data);
   p = p->next;
 }
}

void BubbleSort(Node *L) {
	for (Node *p = L; p != NULL; p = p->next) {
		for (Node *q = p->next; q != NULL; q = q->next) {
			if (p->data > q->data) {
				int t = q->data;
				q->data = p->data;
				p->data = t;
			}
		}
	}
	Output(L);
}

void Classify(Node *L) {
	Node *p = NULL, *q = NULL, *r1, *r2;
	Node *s1 = L;
	while (s1) {
		if (s1->data % 2 == 0 && p == NULL) {
			p = s1;
			r1 = s1;
		} else if (s1->data % 2 == 0 && p != NULL) {
			r1->next = s1;
			r1 = s1;
		}
		if (s1->data % 2 == 1 && q == NULL) {
			q = s1;
			r2 = s1;
		} else if (s1->data % 2 == 1 && q != NULL) {
			r2->next = s1;
			r2 = s1;
		}
		s1= s1->next;
	}
	r1->next = NULL;
	r2->next = NULL;
	printf("\n偶数链排序前:\n");
	Output(p);
	printf("\n偶数链排序后:\n");
	BubbleSort(p);
	printf("\n奇数链排序前:\n");
	Output(q);
	printf("\n奇数链排序后:\n");
	BubbleSort(q);
}
int main(void) {
   Node *L;
   printf("开始建立单链表L,输入-1结束: \n");
   L = Create_Tail();
   Output(L);
   Classify(L);
   return 0;
}

