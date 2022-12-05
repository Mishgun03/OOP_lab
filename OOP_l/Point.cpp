#include "Point.h"
#include <cmath>

Point::Point() {

	_x = 0.0;
	_y = 0.0;

}

Point::Point(double x, double y) {

	this->_x = x;
	this->_y = y;

}

Point::Point(const Point& point) {

	this->_x = point._x;
	this->_y = point._y;

}

Point::~Point() {

}

void Point::setX(double x) {
	
	this->_x = x;

}

void Point::setY(double y) {

	this->_y = y;

}

double Point::getX() {

	return this->_x;

}

double Point::getY() {

	return this->_y;

}

bool Point::isEqual(const Point& point) {

	return (this->_x - point._x) < 0.000001 && (this->_y - point._y) < 0.000001;

}

double Point::getDistance(const Point& point) {

	double powX = std::pow(this->_x - point._x, 2);
	double powY = std::pow(this->_y - point._y, 2);
	return std::sqrt(powX + powY);

}

void Point::move(double k) {

	this->_x += k;
	this->_y += k;

}