#include "Point2D.h"
#include <iostream>
#include <math.h>

//Functions
void Point2D::setZero(){

	x = y = 0.0f;

}

bool Point2D::areZero()const{

	return x == 0.0f && y == 0.0f;

}


//Operators
Point2D Point2D::operator - (const Point2D &v) const {

	Point2D r; //We create a temporal Point2D which will return the value of the subtraction
	r.x = x - v.x;
	r.y = y - v.y;
	return(r);
}

Point2D Point2D::operator + (const Point2D &v) const {

	Point2D r; //We create a temporal Point2D which will return the value of the addition
	r.x = x + v.x;
	r.y = y + v.y;
	return(r);
}

const Point2D& Point2D::operator -= (const Point2D &v) {

	x -= v.x;
	y -= v.y;
	return(*this);
}

const Point2D& Point2D::operator += (const Point2D &v) {

	x += v.x;
	y += v.y;
	return(*this);
}

bool Point2D::operator ==(const Point2D& v) const {

	return (x == v.x && y == v.y);
}

bool Point2D::operator !=(const Point2D& v) const {

	return (x != v.x || y != v.y);
}

Point2D Point2D::operator = (const Point2D& v){

	x = v.x;
	y = v.y;

	return(*this);
}

float Point2D::distanceTo(const Point2D v)const{

	float d = sqrt(((v.x - x)*(v.x - x)) + ((v.y - y)*(v.y - y))); //We create a temporal float which will return the value of the distancen
	return d;
}
