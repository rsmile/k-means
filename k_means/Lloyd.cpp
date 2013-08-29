/*
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "Point.h"
#include "Cluster.h"
using namespace std;

int k;			//��Ҫ���ֵ�cluster�ĸ���
int n;			//��Ҫ���ֵ����ݵ����
void InitPoint(Point *p);			//��ʼ�����ݵ㣺���ļ���ȡ���ݵ�p
void InitCluster(Cluster *c,Point *p);//��ʼ��cluster:��p�����ѡȡk����Ϊ���ĵ�

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
	bool flag = true;
	while(flag){
		//����ÿ�ε�������ÿ�����ݵ�������cluster�������ڵ�����ʼ���Խ�cluster�еĳ�Ա�����
		//����Ӱ�����ĵ�ļ���
		for(i=0;i<k;i++)
			c[i].clearMember();
		flag = false;
		//����ÿһ�����ݵ㣬���㵽K�����ĵ�ľ���
		int min;
		double minDis,tempDis;
		for(i=0;i<n;i++)
		{
			min = 0;
			minDis = 50000;
			for(j=0;j<k;j++)
			{
				tempDis = p[i].calDis(c[j].getCenter()); 
				if(tempDis < minDis)
				{
					minDis = tempDis;
					min = j;
				}
			}
			c[min].addMember(p[i]);		//��������뵽������С��cluster��
		}
		//����ÿһ��cluster,������ĵ�û�з����仯�����������
		for(i=0;i<k;i++)
		{
			double cx = c[i].getCenter().getx();
			double cy = c[i].getCenter().gety();
			c[i].calCenter();
			if(cx!=c[i].getCenter().getx()||cy!=c[i].getCenter().gety())
				flag = true;
		}
	}
	//���ÿ��cluster����Ϣ
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
	srand(time(NULL));
	for(int i=0;i<k;i++)
	{	
		int a = rand()%n;
		c[i].setCenter(p[a]);
		cout<<c[i].getCenter().getx()<<" "<<c[i].getCenter().gety()<<endl;
	}
}
*/