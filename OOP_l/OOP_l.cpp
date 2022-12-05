#include <iostream>
#include "Point.h"
#include "Triangle.h"

bool isPointInCircle(double r, Point& point);
void input(Point& point);
void outputPoint(Point& point);
bool isEqualSquare(Triangle& triangle1, Triangle& triangle2);
void outputTriangle(Triangle& triangle);


int main()
{
    std::cout << std::boolalpha;

    std::cout << "Point\n";

    Point p1 = Point(), p2 = Point(), origin = Point();
    std::cout << "Enter the coordinates of the point: ";
    input(p1);
    std::cout << "Enter the coordinates of the point: ";
    input(p2);
    std::cout << "Are the points in a circle? ";
    std::cout << isPointInCircle(15, p1) << "\n";
    std::cout << isPointInCircle(15, p2) << "\n\n";

    double distance1 = p1.getDistance(origin);
    double distance2 = p2.getDistance(origin);

    std::cout << "A point at a smaller distance from the origin with coordinates:\n";

    if (distance1 > distance2)
        outputPoint(p2);
    else if (distance1 < distance2)
        outputPoint(p1);
    else
        std::cout << "Points at the same distance\n\n";



    std::cout << "Triangle";

    Point pointA = Point();
    Point pointB = Point();
    Point pointC = Point();

    Triangle* triangle1 = new Triangle();
    Triangle* triangle2 = new Triangle();

    std::cout << "\nEnter the coordinates of point A of the first triangle: ";
    input(pointA);
    std::cout << "\nEnter the coordinates of point B of the first triangle: ";
    input(pointB);
    std::cout << "\nEnter the coordinates of point C of the first triangle: ";
    input(pointC);

    triangle1 = new Triangle(pointA, pointB, pointC);

    std::cout << '\n';

    std::cout << "\nEnter the coordinates of point A of the second triangle: ";
    input(pointA);
    std::cout << "\nEnter the coordinates of point B of the second triangle: ";
    input(pointB);
    std::cout << "\nEnter the coordinates of point C of the second triangle: ";
    input(pointC);

    triangle2 = new Triangle(pointA, pointB, pointC);

    if (triangle1->isTriangle() && triangle2->isTriangle()) {

        std::cout << "Are the areas of the triangles equal? ";
        std::cout << isEqualSquare(*triangle1, *triangle2);

    }
    else {
        std::cerr << "It is not a triangle";
        exit(-1);
    }

}

void input(Point& point) {

    double x = 0;
    double y = 0;

    std::cin >> x >> y;
    if (!std::cin) {
        std::cerr << "Error!";
        exit(-1);
    }

    point.setX(x);
    point.setY(y);

}

void outputPoint(Point& point) {

    std::cout << "Coordinates of the point" << std::endl;
    std::cout << "x: " << point.getX() << " y: " << point.getY() << "\n\n";

}

bool isPointInCircle(double r, Point& point) {

    Point origin = Point();
    double distance = point.getDistance(origin);

    if (distance <= r) 
        return true;
    else 
        return false;

}

void outputTriangle(Triangle& triangle) {

    std::cout << "A: " << triangle.getA().getX() << " " << triangle.getA().getY() << '\n';
    std::cout << "B: " << triangle.getB().getX() << " " << triangle.getB().getY() << '\n';
    std::cout << "C: " << triangle.getC().getX() << " " << triangle.getC().getY() << '\n';

}

bool isEqualSquare(Triangle& triangle1, Triangle& triangle2) {

    if (triangle1.isEqual(triangle2))
        return true;
    else {

        double p1 = triangle1.getPerimeter() / 2;
        double p2 = triangle2.getPerimeter() / 2;

        double lAB1 = triangle1.getA().getDistance(triangle1.getB());
        double lBC1 = triangle1.getB().getDistance(triangle1.getC());
        double lCA1 = triangle1.getC().getDistance(triangle1.getA());

        double lAB2 = triangle2.getA().getDistance(triangle2.getB());
        double lBC2 = triangle2.getB().getDistance(triangle2.getC());
        double lCA2 = triangle2.getC().getDistance(triangle2.getA());

        double square1 = sqrt(p1 * (p1 - lAB1) * (p1 - lBC1) * (p1 - lCA1));
        double square2 = sqrt(p2 * (p2 - lAB2) * (p2 - lBC2) * (p2 - lCA2));

        return (abs(square1 - square2) < 0.000001);

    }
}