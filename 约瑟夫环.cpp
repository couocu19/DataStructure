#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct NodeType{
	int id;
	int password;
	struct NodeType *next;
}NodeType;

void CreaList(NodeType **,int); //��������ѭ������ 
NodeType *GetNode(int,int);  //�õ�һ�����
void PrintList(NodeType *);
int IsEmptyList(NodeType *);// ���������Ƿ�Ϊ��
void JosephusOperate(NodeType **,int); //����Լɪ������

int main(){
	int n = 0;
	int m = 0;
	NodeType * pHead = NULL;
	do{
		//����n�������������������������ֱ����������Ϊֹ
		if(n>MAX){
			printf("����̫�࣬���������룡\n");
		} 
		printf("����������n(���%d��):",MAX);
		scanf("%d",&n);
	}while(n>MAX);
	printf("�������ʼ����m:");
	scanf("%d",&m);
	CreaList(&pHead,n); //��������ѭ������
	printf("\n------------- a��ӡѭ������-----------\n");
	PrintList(pHead); //��ӡѭ������ 
	printf("\n-------------��ӡ�������-------------\n");
	JosephusOperate(&pHead,m);
	return 0;
} 

//������n������ѭ������

void CreaList(NodeType ** ppHead,int n){
	int i = 0;
	int iPassword = 0;
	NodeType *pNew = NULL;
	NodeType *pCur = NULL;
	
	for(i=1;i<=n;i++){
		printf("�����%d���˵�����: ",i);
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
	printf("��ɵ���ѭ������Ĵ�����\n");
}

NodeType *GetNode(int iId,int iPassword){  //�����д��ͱ�ź����� 
	NodeType *pNew = NULL;    //����ָ�� 
	pNew = (NodeType *)malloc(sizeof(NodeType));  //Ϊ��ǰ��㿪���¿ռ�
	
	if(!pNew){
		printf("Error,the memory is not enough!\n");
		exit(-1);
	} 
	pNew->id = iId;
	pNew->password = iPassword;
	pNew->next = NULL;  //pNew��nextָ��գ��ÿձ�β 
	return pNew;
} 
//���������n���ˣ���������룬���ԭʼ����Ĵ�ӡ

void PrintList(NodeType *pHead){
	
	NodeType *pCur = pHead;
	//����EmptyList()�������ж�if����Ƿ�ִ�У���pHeadΪ����ִ��
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
		//��Ϊ�գ���ʾ"��",����ֵ 1
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
	//��pPrv��ʼΪָ��β��㣬Ϊɾ������׼��
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
		pDel = pCur; //ɾ��pCurָ��Ľ�㣬�����˳���
		//ʹ��pPrvָ����������һ�������������pCur���������ѽ� 
		pPrv->next = pCur->next;
		pCur = pCur->next;
		iPassword = pDel->password;
		printf("��%d���˳���(����:%d)\n",pDel->id,pDel->password);
		free(pDel);
	}
	*ppHead = NULL;
	getchar();	
}
