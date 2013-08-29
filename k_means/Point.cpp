#include <cmath>
#include "Point.h"

Point::Point(){
	x=0;
	y=0;
}

void Point::setx(double a){
	x=a;
}

void Point::sety(double b){
	y=b;
}

double Point::getx(){
	return x;
}

double Point::gety(){
	return y;
}

double Point::calDis(Point p){
	double a = p.getx();
	double b = p.gety();
	double dis = sqrt((x-a)*(x-a)+(y-b)*(y-b));
	return dis;
}

void Point::setCluster(int i){
	cluster = i;
}

int Point::getCluster(){
	return cluster;
}