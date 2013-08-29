#include <iostream>
#include "Cluster.h"
using namespace std;

void Cluster::calCenter(){
	int n = getMemNum();
	double x=0,y=0;
	vector<Point>::iterator it;
	for(it=member.begin();it!=member.end();it++)
	{
		x+=(*it).getx();
		y+=(*it).gety();
	}
	center.setx(x/n);
	center.sety(y/n);
}

void Cluster::setCenter(Point c){
	center.setx(c.getx());
	center.sety(c.gety());
}


Point Cluster::getCenter(){
	return center;
}

int Cluster::getMemNum(){
	return member.size();
}

vector<Point> Cluster::getMember(){
	vector<Point>::iterator it;
	for(it=member.begin();it!=member.end();it++)
	{
		cout<<"("<<(*it).getx()<<","<<(*it).gety()<<"),";
	}
	cout<<endl;
	return member;
}

void Cluster::addMember(Point c){
	member.push_back(c);
}

double Cluster::calError(){
	double error=0;
	vector<Point>::iterator it;
	for(it=member.begin();it!=member.end();it++)
	{
		double x,y,cx,cy;
		x = (*it).getx();
		y = (*it).gety();
		cx = center.getx();
		cy = center.gety();
		error+=(x-cx)*(x-cx)+(y-cy)*(y-cy);
	}
	return error;
}

void Cluster::clearMember(){
	member.clear();
}

void Cluster::removeMember(Point c){
	vector<Point>::iterator it;
	for(it=member.begin();it!=member.end();it++)
	{
		if((*it).getx()==c.getx() && (*it).gety()==c.gety())
		{
			member.erase(it);
			break;
		}
	}
}
