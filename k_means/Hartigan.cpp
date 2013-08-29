
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "Point.h"
#include "Cluster.h"
using namespace std;

int k;			//��Ҫ���ֵ�cluster�ĸ���
int n;			//��Ҫ���ֵ����ݵ����
void InitPoint(Point *p);			//��ʼ�����ݵ㣺���ļ���ȡ���ݵ�P
void InitCluster(Cluster *c,Point *p);//��ʼ��cluster:��ÿ�����ݵ�������䵽һ��cluster�У��������cluster�����ĵ�

int main(){
	cin>>k;
	cin>>n;
	Point *p = new Point[n];		//��Ҫ���ֵ����ݵ�
	Cluster *c = new Cluster[k];	
	
	cout<<"InitPoint"<<endl;
	InitPoint(p);
	cout<<"InitCluster"<<endl;
	InitCluster(c,p);

	int i,j;
	bool done = false;
	while(!done){
		done = true;
		//����ÿһ�����ݵ�
		int min;
		double minDis,tempDis;
		for(i=0;i<n;i++){
			int clu = p[i].getCluster();	//��ȡ��ǰ������cluster�ı��
			min = 0;
			minDis = 50000;
			for(j=0;j<k;j++)		//���������cluster�ı��
			{
				tempDis = p[i].calDis(c[j].getCenter()); 
				if(tempDis < minDis)
				{
					minDis = tempDis;
					min = j;
				}
			}
			if(clu!=min)		//�������cluster�����,�����������
			{
				done = false;
				c[clu].removeMember(p[i]);	//�����ݵ��ԭ����cluster��ɾ��
				c[clu].calCenter();
				c[min].addMember(p[i]);		//	�����ݵ���ӵ��µ�cluster��
				c[min].calCenter();
				p[i].setCluster(min);
			}

		}
	}
	//��ʾÿ��cluster����Ϣ
	double totalError = 0,error;
	for(i=0;i<k;i++)
	{
		cout<<"Cluster "<<i<<":"<<endl;
		cout<<"		Center:("<<c[i].getCenter().getx()<<","<<c[i].getCenter().gety()<<")"<<endl;
		cout<<"		Member:";
		c[i].getMember();
		error=c[i].calError();
		cout<<"		Error:"<<error<<endl;
		totalError+=error;
	}
	cout<<"TotalError:"<<totalError<<endl;


	return 0;
}


void InitPoint(Point *p){
	//���ļ���ȡ�����ݵ�
	ifstream fin;	
	fin.open("data.txt");
	int i;
	double a,b;
	for(i=0;i<n;i++){
		fin>>a>>b;
		p[i].setx(a);
		p[i].sety(b);
		cout<<a<<" "<<b<<endl;
	}
	fin.close();
}

void InitCluster(Cluster *c,Point *p){
	int i;
	srand(time(NULL));
	for(i=0;i<n;i++)
	{	
		int a = rand()%k;
		c[a].addMember(p[i]);
		p[i].setCluster(a);
	}
	for(i=0;i<k;i++)
	{
		c[i].calCenter();
		cout<<c[i].getCenter().getx()<<" "<<c[i].getCenter().gety()<<":";
		c[i].getMember();
	}
}
