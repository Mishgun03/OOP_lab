#pragma once
#include "Point.h"

class Triangle {
private:
	Point* a_;
	Point* b_;
	Point* c_;
public:
	Triangle();
	Triangle(Point& a, Point& b, Point& c);
	Triangle(Triangle& triangle);
	~Triangle();

	void setA(Point& a);
	void setB(Point& b);
	void setC(Point& c);

	Point getA();
	Point getB();
	Point getC();

	bool isTriangle();

	void move(double k);

	double getPerimeter();

	bool isEqual(Triangle& triangle);
};