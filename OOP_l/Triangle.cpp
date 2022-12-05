#include "Point.h"
#include "Triangle.h"
#include <cmath>

Triangle::Triangle() {
	
	this->a_ = new Point();
	this->b_ = new Point();
	this->c_ = new Point();

}

Triangle::Triangle(Point& a, Point& b, Point& c) {

	this->a_ = new Point(a);
	this->b_ = new Point(b);
	this->c_ = new Point(c);

}

Triangle::Triangle(Triangle& triangle) {

	this->a_ = new Point(*triangle.a_);
	this->b_ = new Point(*triangle.b_);
	this->c_ = new Point(*triangle.c_);

}

Triangle::~Triangle() {
	
	delete a_;
	delete b_;
	delete c_;

}

void Triangle::setA(Point& a) {

	this->a_->setX(a.getX());
	this->a_->setY(a.getY());

}

void Triangle::setB(Point& b) {

	this->b_->setX(b.getX());
	this->b_->setY(b.getY());

}

void Triangle::setC(Point& c) {

	this->c_->setX(c.getX());
	this->c_->setY(c.getY());

}

Point Triangle::getA() {
	
	return Point(*a_);

}

Point Triangle::getB() {

	return Point(*b_);

}

Point Triangle::getC() {

	return Point(*c_);

}

bool Triangle::isTriangle() {

	double lAB = this->a_->getDistance(*this->b_);
	double lBC = this->b_->getDistance(*this->c_);
	double lCA = this->c_->getDistance(*this->a_);

	return lAB + lBC > lCA && lBC + lCA > lAB && lCA + lAB > lBC;

}

void Triangle::move(double k) {

	this->a_->move(k);
	this->b_->move(k);
	this->c_->move(k);

}

double Triangle::getPerimeter() {
	double lAB = this->a_->getDistance(*this->b_);
	double lBC = this->b_->getDistance(*this->c_);
	double lCA = this->c_->getDistance(*this->a_);



	return lAB + lBC + lCA;

}

bool Triangle::isEqual(Triangle& triangle) {
	
	return this->a_->isEqual(triangle.getA())
		&& this->b_->isEqual(triangle.getB())
		&& this->c_->isEqual(triangle.getC());

}