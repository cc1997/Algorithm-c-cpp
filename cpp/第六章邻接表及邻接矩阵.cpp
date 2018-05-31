#include "iostream"
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
typedef int Status;

typedef struct
{//�ڽӾ���
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum,arcnum;//����������
}AMGraph;

//�ڽӱ�
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode* nextarc;
}ArcNode;
typedef struct
{
	VerTexType data;
	ArcNode* firstarc;
}VNode,AdjList[MVNum];
typedef struct
{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;

Status CreateUDN(AMGraph &G)
{//������
	int i,j;
	cout<<"����������Ͷ�����"<<endl;
	cin>>G.arcnum>>G.vexnum;
	cout<<"��˳�����붥������Ϣ��char��"<<endl;
	for(i=0;i<G.vexnum;++i)
		cin>>G.vexs[i];
	cout<<"��¼�����Ϣ(�ڽӾ���)"<<endl;
	for(i=0;i<G.vexnum;i++)  
    {  
            for(j=0;j<G.vexnum;j++)  
            {  
                    cin>>G.arcs[i][j];
            }
    }
	return OK;
}

Status CreateUDG(ALGraph* &G)
{//���ڽӱ�
	ArcNode* p1;
	int i,k;
	G=new ALGraph;
	cout<<"����������Ͷ�����"<<endl;
	cin>>G->arcnum>>G->vexnum;
	for(i=0;i<G->vexnum;++i)
	{
		cout<<"��˳�������"<<(i+1)<<"����������Ϣ��char��"<<endl;
		cin>>G->vertices[i].data;
		G->vertices[i].firstarc=NULL;
	}
	cout<<"��¼�����Ϣ"<<endl;
	for(k=0;k<G->vexnum;++k)
	{
		cout<<"�������"<<(k+1)<<"������ָ��Ķ��㣨��-1������"<<endl;
		for(cin>>i;i!=-1;cin>>i)
		{
		    p1=new ArcNode;
			p1->adjvex=i;
			p1->nextarc=G->vertices[k].firstarc;
			G->vertices[k].firstarc=p1;
		};
	}
	return OK;
}
void ChangeToUDG(AMGraph g,ALGraph* &G)  
//���ڽӾ���gת�����ڽӱ�G  
    {   int i,j;  
        ArcNode* p;  
        G=new ALGraph;  
        for (i=0;i<g.vexnum;i++)                  
            G->vertices[i].firstarc=NULL;  
        for (i=0;i<g.vexnum;i++)                    
            for (j=g.vexnum-1;j>=0;j--)  
                if (g.arcs[i][j]!=0)      
                {   
					p=new ArcNode;
                    p->adjvex=j;
                    p->nextarc=G->vertices[i].firstarc;
                    G->vertices[i].firstarc=p;
                }  
        G->vexnum=g.vexnum;G->arcnum=g.arcnum;
    }

void ChangeToUDN(ALGraph* G,AMGraph &g)  
//���ڽӱ�Gת�����ڽӾ���g 
    {   int i,j;  
        ArcNode* p;
		for(i=0;i<G->vexnum;i++)
			for(j=0;j<G->vexnum;j++)
				g.arcs[i][j]=0;//��ʼ���ڽӾ���
        for(i=0;i<G->vexnum;i++)
		{
			p=G->vertices[i].firstarc;
				while(p!=NULL)
				{
					g.arcs[i][p->adjvex]=1;
					p=p->nextarc;
				}
		}
		g.vexnum=G->vexnum;g.arcnum=G->arcnum;
    }

void ShowUDN(AMGraph g)  
//����ڽӾ���g  
{  
    int i,j;  
    for (i=0;i<g.vexnum;i++)  
    {  
        for (j=0;j<g.vexnum;j++)  
			cout<<g.arcs[i][j]<<"  ";
        cout<<endl;  
    }  
}

void ShowUDG(ALGraph *G)  
//����ڽӱ�G  
    {  
        int i;  
        ArcNode *p;
        for (i=0;i<G->vexnum;i++)  
        {  
            p=G->vertices[i].firstarc;  
            
            cout<<i<<"=>";  
            while (p!=NULL)  
            {
                cout<<p->adjvex<<" ";  
                p=p->nextarc;  
            }  
            printf("\n");  
        }  
    }  

void main()
{
	int x;
	AMGraph G1;
	ALGraph* G2;
	cout<<"�����¡����ڽӱ��ڽӾ���"<<endl;
	cout<<"1.�����ڽӾ���"<<endl;
	cout<<"2.�����ڽӱ�"<<endl;
	cout<<"3.�ڽӾ���==>>�ڽӱ�"<<endl;
	cout<<"4.�ڽӱ�==>>�ڽӾ���"<<endl;
	cout<<"5.����ڽӱ�"<<endl;
	cout<<"6.����ڽӾ���"<<endl;
	cin>>x;
	switch(x)
	{
	case 1:{
		CreateUDN(G1);
		break;
		   }
	case 2:{
		CreateUDG(G2);
		break;
		   }
	case 3:{
		CreateUDN(G1);
		ChangeToUDG(G1,G2);
		cout<<"ת�����ڽӱ��:"<<endl;
		ShowUDG(G2);
		break;
		   }
	case 4:{
		CreateUDG(G2);
		ChangeToUDN(G2,G1);
		cout<<"ת�����ڽӾ����:"<<endl;
		ShowUDN(G1);
		break;
		   }
	case 5:{
		ShowUDN(G1);
		break;
		   }
	case 6:{
		ShowUDG(G2);
		break;
		   }
	}
}