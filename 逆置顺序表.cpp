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
	int t; //������ֵ����ʱ���� 
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
	printf("���������Ա�ĳ���:\n");
	scanf("%d",&len);
	printf("������������%d��Ԫ��:\n",len);
	for(i=0;i<len;i++){
		scanf("%d",&num[i]);
		m.a[i] = num[i];
	}
	m.length = len;
	ReverseList(m);
	
}


