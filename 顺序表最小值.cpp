#include<stdio.h>
#define MAXSIZE 100
typedef int Type;
typedef struct{
    int a[MAXSIZE];
	int length;
}SeqList;

int getMin(SeqList m){
	int min = m.a[0];
	int len = m.length;
	int i;
	for(i=0;i<len;i++){
		if(min>m.a[i]){
			min = m.a[i];
		}
		
	}
	return min;
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
	printf("���Ա�����С��Ԫ��Ϊ%d\n",getMin(m));
	
	
}
 
