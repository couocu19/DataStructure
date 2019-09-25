#include<stdio.h>
#define MAXSIZE 100
typedef int Type;
typedef struct{
    int a[MAXSIZE];
	int length;
}SeqList;

//求线性表中第一个值为x的元素的前驱和后继的存储位置 
//void Locate(SeqList m,int x){
//	int len = m.length;
//	int i;
//	if(x == m.a[0]){
//		printf("该元素无前驱,后继元素的存储位置为1");
//	}else{
//		for(i = 1;i<len;i++){
//			if(m.a[i] == x && i!=len-1){
//				printf("前驱:%d 后继:%d\n",i-1,i+1);
//				break;
//			}else{
//				printf("前驱:%d 无后继元素\n",i-1);
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
	printf("请输入线性表的长度:\n");
	scanf("%d",&len);
	printf("请依次输入这%d个元素:\n",len);
	for(i=0;i<len;i++){
		scanf("%d",&num[i]);
		m.a[i] = num[i];
	}
	m.length = len;
	printf("输入你要定位的值(在线性表中首次出现的位置):\n");
	scanf("%d",&x);
	Locate(m,x,&c,&d);
	printf("%d %d\n",c,d);
	return 0;
}
