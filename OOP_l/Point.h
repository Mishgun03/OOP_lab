#pragma once

class Point {
private:
	double _x;
	double _y;

public:
	Point();
	Point(double x, double y);
	Point(const Point& point);
	~Point();

	void setX(double x);
	void setY(double y);

	double getX();
	double getY();

	bool isEqual(const Point& point);

	double getDistance(const Point& point);

	void move(double k);

};