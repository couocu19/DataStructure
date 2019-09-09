#include<stdio.h>
#define MAXSIZE 100

typedef int Type;
typedef struct{
    int a[MAXSIZE];
	int length;
}SeqList;

void ReverseList(SeqList m){
	int len = m.length;
	int i;
	int t; //交换两值的临时变量 
	for(i=0;i<len/2;i++){
		t = m.a[i];
		m.a[i] = m.a[len-1-i];
		m.a[len-1-i] = t;
	}
	for(i = 0;i<len;i++){
		printf("%d ",m.a[i]);
	}
	printf("\n");
	
}

int main(){
	int i;
	SeqList m;
	int num[10];
	int len;
	printf("请输入线性表的长度:\n");
	scanf("%d",&len);
	printf("请依次输入这%d个元素:\n",len);
	for(i=0;i<len;i++){
		scanf("%d",&num[i]);
		m.a[i] = num[i];
	}
	m.length = len;
	ReverseList(m);
	
}


