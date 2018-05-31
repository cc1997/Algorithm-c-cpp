#include "iostream"
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define	OVERFLOW -2
typedef int ElemType;
typedef int Status;
typedef struct
{
	ElemType *elem;
	int length;
}Sqlist;

Status InitList(Sqlist &L)           
{
	L.elem=new ElemType[MAXSIZE];
	if(!L.elem) exit(OVERFLOW);
	L.length=0;
	return OK;
}

void inputList(Sqlist &L)                          
{
	cout<<"���������еĸ���"<<endl;
	cin>>L.length;
	cout<<"������"<<L.length<<"�����������еĹؼ���"<<endl;
	for(int i=1; i<=L.length; i++)
	{
		cin>>L.elem[i];
	}
}
void insertSort(Sqlist &L)//ֱ�Ӳ�������
{
	for(int i=2; i<=L.length; i++)
	{
		L.elem[0] = L.elem[i];
		int j= i-1;
		while(L.elem[j] > L.elem[0])
		{
			L.elem[j+1] = L.elem[j];
			j--;
		}
		L.elem[j+1] = L.elem[0];
	}
}
void BInsertSort(Sqlist &L)//�۰��������
{
	int low, high, m;
	for(int i=2; i<=L.length; i++)
	{
		L.elem[0] = L.elem[i];
		low = 1; high = i-1;
		while(low <= high)
		{
			m = (low+high)/2;
			if(L.elem[0] < L.elem[m]) high = m-1;
			else low = m+1;
		}
		for(int j=i-1; j>=high+1; j--)
			L.elem[j+1] = L.elem[j];
		L.elem[high+1] = L.elem[0];
	}
}
void BubbleSort(Sqlist &L)	//��˳���L��ð������
{

	int m,j,flag;
	ElemType t;
    m=L.length-1; flag=1; 				
    while((m>0)&&(flag==1))
	{
		flag=0;           				
        for(j=1;j<=m;j++)
			if(L.elem[j]>L.elem[j+1].key) 
			{
				flag=1;		
				t=L.elem[j];L.elem[j]=L.elem[j+1];L.elem[j+1]=t;	
			}
		--m;
    }									
}
void SelectSort(Sqlist &L)
{
	int k;
	ElemType t;
	for(int i=1; i<L.length; i++)
	{
		k = i;
		for(int j=i+1; j<=L.length; j++)
			if(L.elem[j] < L.elem[k])
				k = j;
		if(k != i)
		{
			t = L.elem[i];
			L.elem[i] = L.elem[k];
			L.elem[k] = t;
		}
	}
}
void output(Sqlist L)
{
	for(int i=1; i<=L.length; i++)
		cout<<L.elem[i]<<"  ";
} 

void main()
{
	Sqlist L;
	InitList(L);
	cout<<"�ڰ��¡�����ͬ���򷽷�"<<endl;
	cout<<"0.���������"<<endl;
	cout<<"1.ֱ�Ӳ�������"<<endl;
	cout<<"2.�۰��������"<<endl;
	cout<<"3.ð������"<<endl;
	cout<<"4.��ѡ������"<<endl;
	switch(x)
	{
	case 0:{
		inputList(L);
		break;
		   }
	case 1:{
		insertSort(L);
		cout<<"�����Ľ��Ϊ��"<<endl;
		output(L);
		   }
	case 2:{
		BInsertSort(L);
		cout<<"�����Ľ��Ϊ��"<<endl;
		output(L);
		   }
	case 3:{
		BubbleSort(L);
		cout<<"�����Ľ��Ϊ��"<<endl;
		output(L);
		   }
	case 4:{
		SelectSort(L);
		cout<<"�����Ľ��Ϊ��"<<endl;
		output(L);
		   }
	}
	
	
	

}