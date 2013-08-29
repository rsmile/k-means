/*
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "Point.h"
#include "Cluster.h"
using namespace std;

int k;			//需要划分的cluster的个数
int n;			//需要划分的数据点个数
void InitPoint(Point *p);			//初始化数据点：从文件中取数据到p
void InitCluster(Cluster *c,Point *p);//初始化cluster:从p中随机选取k个作为中心点

int main(){
	cin>>k;
	cin>>n;
	Point *p = new Point[n];		//需要划分的数据点
	Cluster *c = new Cluster[k];	
	
	cout<<"InitPoint"<<endl;		
	InitPoint(p);
	cout<<"InitCluster"<<endl;
	InitCluster(c,p);

	int i,j;
	bool flag = true;
	while(flag){
		//由于每次迭代都对每个数据点重新找cluster，所以在迭代开始可以将cluster中的成员都清除
		//以免影响中心点的计算
		for(i=0;i<k;i++)
			c[i].clearMember();
		flag = false;
		//对于每一个数据点，计算到K个中心点的距离
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
			c[min].addMember(p[i]);		//并将其加入到距离最小的cluster中
		}
		//遍历每一个cluster,如果中心点没有发生变化，则迭代结束
		for(i=0;i<k;i++)
		{
			double cx = c[i].getCenter().getx();
			double cy = c[i].getCenter().gety();
			c[i].calCenter();
			if(cx!=c[i].getCenter().getx()||cy!=c[i].getCenter().gety())
				flag = true;
		}
	}
	//输出每个cluster的信息
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
	//从文件中取出数据点
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