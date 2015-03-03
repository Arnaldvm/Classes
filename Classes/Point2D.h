#ifndef __Point2D_H__
#define __Point2D_H__

class Point2D{

public:

	//Functions
	void setZero();
	bool areZero()const;

	//Operators
	Point2D operator - (const Point2D &v) const;
	Point2D operator + (const Point2D &v) const;

	const Point2D& operator -= (const Point2D &v);
	const Point2D& operator += (const Point2D &v);

	bool operator ==(const Point2D& v) const;
	bool operator !=(const Point2D& v) const;

	Point2D operator = (const Point2D& v);

	//Utility
	float distanceTo(const Point2D v)const;


public:
	//Variables
	float x, y;

};

#endif 