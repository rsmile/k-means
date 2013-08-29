#ifndef POINT_H
#define POINT_H

class Point{
public:
	Point();
	void setx(double a);
	void sety(double b);
	double getx();
	double gety();
	double calDis(Point p);
	void setCluster(int i);
	int getCluster();
private:
	double x;
	double y;
	int cluster;
};


#endif