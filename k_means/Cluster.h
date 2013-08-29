#ifndef CLUSTER_H
#define CLUSTER_H
#include "Point.h"
#include <vector>
using namespace std;

class Cluster{
public:
	void calCenter();
	void setCenter(Point c);
	Point getCenter();
	int getMemNum();
	vector<Point> getMember();
	void addMember(Point c);
	void removeMember(Point c);
	double calError();
	void clearMember();
private:
	Point center;
	vector<Point> member;
};



#endif