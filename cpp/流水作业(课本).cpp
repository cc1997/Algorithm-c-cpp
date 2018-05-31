#include <iostream.h>

class Jobtype{
	public:
		bool operator<=(Jobtype a) const
		{return (key<=a.key);}
		int key,index;
		bool job;
	};


void sort(Jobtype *d,int n)
{
	
	Jobtype t;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(d[j+1].key<=d[j].key)
			{
				t=d[j];
				d[j]=d[j+1];
				d[j+1]=t;
			}
		}
	}


}

int FlowShop(int n,int *a,int *b,int *c)
{
	Jobtype *d=new Jobtype[n];
	for(int i=0;i<n;i++)
	{
		d[i].key=a[i]>b[i]?b[i]:a[i];
		d[i].job=a[i]<=b[i];
		d[i].index=i;
		cout<<d[i].key<<" "<<d[i].job<<" "<<d[i].index<<"\n";
	}
	sort(d,n);
	int j=0,k=n-1;
	for(i=0;i<n;i++){
		if(d[i].job) c[j++]=d[i].index;
		else c[k--]=d[i].index;
	}
	j=a[c[0]];
	k=j+b[c[0]];
	for(i=1;i<n;i++){
		j+=a[c[i]];
		k=j<k?k+b[c[i]]:j+b[c[i]];
	}

	cout<<"��ˮ��ҵ�����żӹ�˳��Ϊ��"<<endl;
	for(i=0;i<n;i++)
		cout<<c[i]<<"->";
	cout<<endl;
	delete d;
	return k;

}

void main()
{
	int n;
	int k=0;
	cout<<"��������ҵ�ĸ�����";
	cin>>n;
	int *a=new int[n];
	int *b=new int[n];
	int *c=new int[n];
	cout<<"�������������ÿ����ҵ�ĵ�һ����������Ҫ��ʱ��";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"�������������ÿ����ҵ�ĵڶ�����������Ҫ��ʱ��";
	for(i=0;i<n;i++)
		cin>>b[i];



	k=FlowShop(n,a,b,c);
	cout<<"��ˮ��ҵ�������õ�����ʱ��Ϊ��"<<k<<endl;
 
}