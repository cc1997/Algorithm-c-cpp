// �÷��η�������

#include "cstdio"
#include "iostream.h"
#include "fstream.h"

// ������Ĺؼ��� ���м������Ϊ���ޣ� ȷ��������ʼ����ֹ����
void split(int s[], int n, int &l, int &r)
{
    int mid = n/2;
    for(l=0; l<n; ++l)
    {
        if (s[l] == s[mid])
            break;
    }
    for(r=l+1; r<n; ++r)
    {
        if (s[r] != s[mid])
            break;
    }

}

// num ������ maxCnt ����
void getMaxCnt(int &mid, int &maxCnt, int s[], int n)
{
    int l, r;
    split(s, n, l, r);  // �����и��������Ǳ�����Ĺؼ�
    int num = n/2;
    int cnt = r-l;

    // update
    if (cnt > maxCnt)
    {
        maxCnt = cnt;
        mid = s[num];
    }

    // l ��ʾ��ߵĸ�������ߵĸ���������� maxCnt ���б�Ҫ��Ѱ
    if (l+1 > maxCnt)
    {
        getMaxCnt(mid, maxCnt, s, l+1);
    }

    // �ұ���Ѱ, �ұ��������ʼ��ַҪ���
    if (n-r > maxCnt)
    {
        getMaxCnt(mid, maxCnt, s+r, n-r);
    }
}

int main(void)
{
    int s[] = {1, 2, 2, 2, 3, 3, 5, 6, 6, 6, 6};
    int n = sizeof(s)/sizeof(s[0]);

    int maxCnt = 0;
    int num = 0;
	ifstream infile("input.txt");
	for(int i=0;i<n;i++)
		infile>>s[i];#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>

#define maxsize 50

void main()
{
	int i,n;
	char c[maxsize][maxsize];
	char in[10];char out[10];
	cout<<"�����������ļ�����";
	cin>>in;cout<<endl;
	cout<<"������д����ļ�����";
	cin>>out;cout<<endl;
	ifstream infile(in);
	ofstream outfile(out);
	i=1;
	while(!infile.eof())
	{
		infile>>c[i][1]>>c[i][2]>>c[i][3]>>c[i][4];
		i++;
	}
	n=i-1;
	infile.close();
	outfile.setf(ios::left);
	cout<<"���뵽����ı���"<<endl;
	for(i=1;i<=n;i++)
	{
		for(int j=1;j<=4;j++)
			outfile<<setw(8)<<c[i][j]<<" ";
		outfile<<endl;
	}
	cout<<endl;

}
    getMaxCnt(num, maxCnt, s, n);
	ofstream outfile("output.txt");
	outfile<<num<<endl<<maxCnt<<endl;

    return 0;
}