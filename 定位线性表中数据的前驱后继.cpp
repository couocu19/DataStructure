#include<stdio.h>
#define MAXSIZE 100
typedef int Type;
typedef struct{
    int a[MAXSIZE];
	int length;
}SeqList;

//�����Ա��е�һ��ֵΪx��Ԫ�ص�ǰ���ͺ�̵Ĵ洢λ�� 
//void Locate(SeqList m,int x){
//	int len = m.length;
//	int i;
//	if(x == m.a[0]){
//		printf("��Ԫ����ǰ��,���Ԫ�صĴ洢λ��Ϊ1");
//	}else{
//		for(i = 1;i<len;i++){
//			if(m.a[i] == x && i!=len-1){
//				printf("ǰ��:%d ���:%d\n",i-1,i+1);
//				break;
//			}else{
//				printf("ǰ��:%d �޺��Ԫ��\n",i-1);
//				break;
//			}
//		}	
//	}
//} 
void Locate(SeqList m,int x,int *c,int *d){
	int len = m.length;
	int i;
	if(x == m.a[0]){
		*d = 1;
	}else{
		for(i = 1;i<len;i++){
			if(m.a[i] == x){
				if(i!=len-1){
					*c = i-1;
			    	*d = i+1;
				    break;
				}else{
					*c = i-1;
					break;
				}
			}
		}
		if(i == len){
			return;
		}
			
	}
} 


int main(){
	int i;
	int c,d;
	c = -100;
	d = -100;
	SeqList m;
	int num[10];
	int len,x;
	printf("���������Ա�ĳ���:\n");
	scanf("%d",&len);
	printf("������������%d��Ԫ��:\n",len);
	for(i=0;i<len;i++){
		scanf("%d",&num[i]);
		m.a[i] = num[i];
	}
	m.length = len;
	printf("������Ҫ��λ��ֵ(�����Ա����״γ��ֵ�λ��):\n");
	scanf("%d",&x);
	Locate(m,x,&c,&d);
	printf("%d %d\n",c,d);
	return 0;
}
