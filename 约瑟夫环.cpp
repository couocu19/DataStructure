#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct NodeType{
	int id;
	int password;
	struct NodeType *next;
}NodeType;

void CreaList(NodeType **,int); //创建单向循环链表 
NodeType *GetNode(int,int);  //得到一个结点
void PrintList(NodeType *);
int IsEmptyList(NodeType *);// 测试链表是否为空
void JosephusOperate(NodeType **,int); //运行约瑟夫环问题

int main(){
	int n = 0;
	int m = 0;
	NodeType * pHead = NULL;
	do{
		//人数n超过最大人数，重新输入人数直至满足条件为止
		if(n>MAX){
			printf("人数太多，请重新输入！\n");
		} 
		printf("请输入人数n(最多%d个):",MAX);
		scanf("%d",&n);
	}while(n>MAX);
	printf("请输入初始密码m:");
	scanf("%d",&m);
	CreaList(&pHead,n); //创建单向循环链表
	printf("\n------------- a打印循环链表-----------\n");
	PrintList(pHead); //打印循环链表 
	printf("\n-------------打印出队情况-------------\n");
	JosephusOperate(&pHead,m);
	return 0;
} 

//创建有n个结点的循环链表

void CreaList(NodeType ** ppHead,int n){
	int i = 0;
	int iPassword = 0;
	NodeType *pNew = NULL;
	NodeType *pCur = NULL;
	
	for(i=1;i<=n;i++){
		printf("输入第%d个人的密码: ",i);
		scanf("%d",&iPassword);
		pNew = GetNode(i,iPassword);
		if(*ppHead == NULL){
			*ppHead = pCur = pNew;
			pCur->next = *ppHead;
		}
		else{
			pNew->next = pCur->next;
			pCur->next = pNew;
			pCur = pNew;
		}
	}
	printf("完成单向循环链表的创建！\n");
}

NodeType *GetNode(int iId,int iPassword){  //向结点中传送编号和密码 
	NodeType *pNew = NULL;    //建立指针 
	pNew = (NodeType *)malloc(sizeof(NodeType));  //为当前结点开辟新空间
	
	if(!pNew){
		printf("Error,the memory is not enough!\n");
		exit(-1);
	} 
	pNew->id = iId;
	pNew->password = iPassword;
	pNew->next = NULL;  //pNew的next指向空，置空表尾 
	return pNew;
} 
//依次输出至n个人，且输出密码，完成原始链表的打印

void PrintList(NodeType *pHead){
	
	NodeType *pCur = pHead;
	//调用EmptyList()函数来判断if语句是否执行，若pHead为空则执行
	if(!IsEmptyList(pHead)){
		printf("--ID-- --PASSWORD--\n");
		do{
			printf("%3d %7d\n",pCur->id,pCur->password);
			pCur = pCur->next;
		}while(pCur!=pHead);
		
	} 
} 

int IsEmptyList(NodeType *pHead){
	if(!pHead){
		//若为空，提示"空",返回值 1
		printf("The List is empty!\n");
		return 1;
	}

	return 0;
}


void JosephusOperate(NodeType **ppHead,int iPassword){
	int iCounter = 0;
	int iFlag = 1;
	NodeType *pPrv = NULL;
	NodeType *pCur = NULL;
	NodeType *pDel = NULL;
	pPrv = pCur = *ppHead;
	//将pPrv初始为指向尾结点，为删除做好准备
	while(pPrv->next != *ppHead){
		pPrv = pPrv->next;
	} 
	
	while(iFlag){
//		printf("1");
		for(iCounter = 1;iCounter<iPassword;iCounter++){
			pPrv = pCur;
			pCur = pCur->next;
		}
		if(pPrv==pCur)
		   iFlag = 0;
		pDel = pCur; //删除pCur指向的结点，即有人出列
		//使得pPrv指向结点与下下一个结点相连，让pCur从链表中脱节 
		pPrv->next = pCur->next;
		pCur = pCur->next;
		iPassword = pDel->password;
		printf("第%d个人出列(密码:%d)\n",pDel->id,pDel->password);
		free(pDel);
	}
	*ppHead = NULL;
	getchar();	
}
