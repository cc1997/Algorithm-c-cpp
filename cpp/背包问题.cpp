#include <iostream.h>
#include "fstream.h"
#include <iomanip.h>
const int MAX=1000;
int w[MAX],v[MAX],best[MAX];
int V[MAX][MAX];//����ֵ����
int W,n;//WΪ�����������������nΪ��Ʒ������
//�����ֵ����
int max(int x,int y)
{
	return x>=y?x:y;
}
//����Сֵ����
int min(int x,int y)
{
	return x>=y?y:x;
}
void knaspack()
{
	int Max=min(w[n]-1,W);
	for(int j=1;j<=Max;j++)
		V[n][j]=0;
	for(j=w[n];j<=W;j++)
		V[n][j]=v[n];
	for(int i=n-1;i>1;i--)
	{
		Max=min(w[i]-1,W);
		for(j=1;j<=Max;j++)
			V[i][j]=V[i+1][j];
		for(j=w[i];j<=W;j++)
			V[i][j]=max(V[i+1][j],V[i+1][j-w[i]]+v[i]);
	}
	V[1][W]=V[2][W]; //�ȼ����һ����Ʒ������
	if(W>w[1])
		V[1][W]=max(V[1][W],V[2][W-w[1]]+v[1]);
}
//�����������飬����ĳ����Ʒ�Ƿ�Ӧ�÷��뱳��
void traceback()
{
	for(int i=1;i<n;i++)//�ȽϾ����������У������һ�У�����������ΪW������ֵ
	{
		if(V[i][W]==V[i+1][W])//�����ǰ�е�����ֵ����һ�е�����ֵ��ȣ����������Ʒ���ܷ�
		{
			best[i]=0;
		}
		else
		{
			best[i]=1;
			W-=w[i];
		}
	}
	best[n]=(V[n][W])?1:0;
}
void main()
{
	int i;
	char input[100],output[100];
    cout<<"�����������ļ���:"<<endl;
	cin>>input;
	cout<<"������������ļ���:"<<endl;
	cin>>output;
	ifstream infile(input);
	ofstream outfile(output);
	//cout<<"������Ʒ������n�ͱ���������W��";
	infile>>n;
	infile>>W;
	//cout<<"����ÿ����Ʒ������W��"<<endl;
	for(i=1;i<=n;i++)
		infile>>w[i];
	//memset(V,0,sizeof(V));
	//cout<<"����ÿ����Ʒ�ļ�ֵv��"<<endl;
	for(i=1;i<=n;i++)
		infile>>v[i];
	infile.close();
	outfile.setf(ios::left);
	cout<<endl<<"�����д������ı���"<<endl;
	knaspack();//�������
	traceback();//��������������
	int totalW=0;
	int totalV=0;
	//��ʾ���Է������Ʒ
	outfile<<"��ѡ�����Ʒ���£�"<<endl;
	outfile<<"��Ʒ���i:   ����w:   �۸�v:  "<<endl;
	for(i=1;i<=n;i++)
	{
		if(best[i]==1)
		{
			totalW+=w[i];
			totalV+=v[i];
			outfile<<setw(5)<<i<<"        "<<w[i]<<"        "<<v[i]<<endl;
		}
	}
	outfile<<"�������Ʒ�����ܺ��ǣ�"<<totalW<<"  ��ֵ���Ž��ǣ�"<<totalV<<endl;
}
