#include<stdio.h>
#define MAXSIZE 100
typedef int Type;
typedef struct{
    int a[MAXSIZE];
	int length;
}SeqList;

void Delete_num(SeqList m,int x){
	int i,j;
	for(i=0;i<m.length;i++){
		if(m.a[i] == x){
			for(j=i+1;j<m.length;j++){
				m.a[j-1] = m.a[j];
			}
			m.length--;
			i--;
			printf("%d\n",m.length);
		}
	}
	for(i = 0;i<m.length;i++)
	   printf("%d ",m.a[i]);
	printf("\n");
}

int main(){
	int i,n;
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
	printf("��������Ҫɾ����ֵ:\n");
	scanf("%d",&n);
	Delete_num(m,n);
	printf("\n");
	return 0;
}

