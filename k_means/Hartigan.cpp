
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "Point.h"
#include "Cluster.h"
using namespace std;

int k;			//需要划分的cluster的个数
int n;			//需要划分的数据点个数
void InitPoint(Point *p);			//初始化数据点：从文件中取数据到P
void InitCluster(Cluster *c,Point *p);//初始化cluster:将每个数据点随机分配到一个cluster中，并计算各cluster的中心点

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
	bool done = false;
	while(!done){
		done = true;
		//对于每一个数据点
		int min;
		double minDis,tempDis;
		for(i=0;i<n;i++){
			int clu = p[i].getCluster();	//获取当前所属的cluster的编号
			min = 0;
			minDis = 50000;
			for(j=0;j<k;j++)		//计算最近的cluster的编号
			{
				tempDis = p[i].calDis(c[j].getCenter()); 
				if(tempDis < minDis)
				{
					minDis = tempDis;
					min = j;
				}
			}
			if(clu!=min)		//如果两个cluster不相等,则迭代不结束
			{
				done = false;
				c[clu].removeMember(p[i]);	//将数据点从原来的cluster中删除
				c[clu].calCenter();
				c[min].addMember(p[i]);		//	将数据点添加到新的cluster中
				c[min].calCenter();
				p[i].setCluster(min);
			}

		}
	}
	//显示每个cluster的信息
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
