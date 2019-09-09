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
	printf("请输入线性表的长度:\n");
	scanf("%d",&len);
	printf("请依次输入这%d个元素:\n",len);
	for(i=0;i<len;i++){
		scanf("%d",&num[i]);
		m.a[i] = num[i];
	}

	m.length = len;
	printf("线性表中最小的元素为%d\n",getMin(m));
	
	
}
 
