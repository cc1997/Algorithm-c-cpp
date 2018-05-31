#include"iostream.h"
#define MAXTSIZE 100
typedef int Status;
typedef char TElemType;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
char ch;
BiTree bt;
Status InitBiTree(BiTree &T)
{
	T=NULL;return 1;
}
void CreateBiTree(BiTree &T)
{//���򴴽�
	cin>>ch;
	if(ch=='#') T=NULL;
	else
	{
		T=new BiTNode;
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}


void InOrderTraverse(BiTree T)
{//�������
	if(T)
	{
		InOrderTraverse(T->lchild);
		cout<<T->data;
		InOrderTraverse(T->rchild);
	}
}
void Copy(BiTree T,BiTree &NewT)
{
	if(T==NULL)
	{
		NewT=NULL;
		return;
	}else
	{
		NewT=new BiTNode;
		NewT->data=T->data;
		Copy(T->lchild,NewT->lchild);
		Copy(T->rchild,NewT->rchild);
	}
}

int Depth(BiTree T)
{
	int m,n;
	if(T==NULL) return 0;
	else
	{
		m=Depth(T->lchild);
		n=Depth(T->rchild);
		if(m>n) return(m+1);
		else return(n+1);
	}
}
int NodeCount(BiTree T)
{
	if(T==NULL) return 0;
	else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}

int l=0;
int LeafNodeCount(BiTree T)
{
	if(T==NULL) return 0;
	if(T->lchild==NULL&&T->rchild==NULL) l++;
	else
	{
		LeafNodeCount(T->lchild);LeafNodeCount(T->rchild);
	}
	return l;
}
int JudgeSame(BiTree T1,BiTree T2)
{
	if(T1==NULL&&T2!=NULL) l=1;
	if(T1!=NULL&&T2==NULL) l=1;
	if(T1&&T2){
		JudgeSame(T1->lchild,T2->lchild);
		JudgeSame(T1->rchild,T2->rchild);
		cout<<T1->data<<"  "<<T2->data<<endl;
		if(T1->data!=T2->data) l=1;
		if(T1->data==T2->data&&l!=1) l=0;
	}
	return l;
}
void Exchange(BiTree T)
{
	if(T)
	{
		bt=T->lchild;
		T->lchild=T->rchild;
		T->rchild=bt;
		Exchange(T->lchild);
		Exchange(T->rchild);
	}
}
void Width(BiTree T,int d,int &Pnum)
{
	int PTnum=1;
	if(T==NULL) return;
	if(d>0)
	{
			Width(T->lchild,--d,Pnum);
			Width(T->rchild,--d,Pnum);
	}
	else
	{
		Pnum++;
	}
}
void main()
{
	int x,d=0;
	BiTree T1,T2;
	InitBiTree(T1);
	InitBiTree(T2);
	while(1){
		cout<<"��5�� �κ��㷨��"<<endl;
		cout<<"0.���򴴽���������(����:ABC##DE#G##F###)"<<endl;
		cout<<"1.ͳ�ƶ�������Ҷ�ڵ����"<<endl;
		cout<<"2.�б����ö������Ƿ����"<<endl;
		cout<<"3.����������ÿ���������Ӻ��Һ���"<<endl;
		cout<<"4.��ƶ�������˫������㷨x"<<endl;
		cin>>x;
		switch(x)
		{
			case 0:{CreateBiTree(T1);break;}
			case 1:{cout<<LeafNodeCount(T1)<<endl;break;}
			case 2:{
				cout<<"�����ڶ�����������(����:ABC##DE#G##F###)"<<endl;
				CreateBiTree(T2);
				cout<<"T1:"<<endl;
				InOrderTraverse(T1);
				cout<<endl<<"T2:"<<endl;
				InOrderTraverse(T2);
				cout<<endl;
				d=JudgeSame(T1,T2);
				if(d==1){cout<<"����"<<endl;}
				else{cout<<"���"<<endl;}
				break;
				   }
			case 3:{
				cout<<"T1����ǰ(����):"<<endl;
				InOrderTraverse(T1);
				Exchange(T1);
				cout<<"������(����):"<<endl;
				InOrderTraverse(T1);
				break;
				   }
			case 4:{
				d=NodeCount(T1);
				cout<<"Node's quantity is:"<<d<<endl;
				break;
				   }
		}
	}
}
		