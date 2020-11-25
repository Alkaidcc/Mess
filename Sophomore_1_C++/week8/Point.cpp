#include <iostream>
using namespace std;
class Point
{
public:
	Point(double i = 0, double j = 0) :x(i), y(j) {};
	bool operator==(const Point& c1);
	bool operator!=(const Point& c1);
	void operator+=(const Point& c1);
	void operator-=(const Point& c1);
	Point& operator+(const Point& c1);
	Point operator-(const Point& c1);
	Point& operator=(const Point& c1);
    Point& operator++();
    Point operator++(int);
    friend ostream& operator<<(ostream& out,const Point& c1);
private:
	double x;
	double y;
};

Point& Point::operator++(){
    this->x++;
    this->y++;
    return *this;
}
Point Point::operator++(int){
    Point old = *this;
    (*this)++;
    return old;
}

void Point::operator-=(const Point& c1){
    this->x -= c1.x;
    this->y -= c1.y;
}

void Point::operator+=(const Point& c1){
    this->x += c1.x;
    this->y += c1.y;
}

ostream& operator<<(ostream& out, const Point& c1){
    out << "(" << c1.x << "," << c1.y << ")" << " ";
    return out;
}

bool Point::operator!=(const Point& c1){
    return (this->x != c1.x && this->y != c1.y);
}

bool Point::operator==(const Point& c1){
    return (this->x == c1.x && this->y == c1.y);
}
Point& Point::operator+(const Point& c1){
    this->x += c1.x;
    this->y += c1.y;
    return *this;
}

Point Point::operator-(const Point& c1){
    return Point(this->x - c1.x, this->y - c1.y);
}
Point& Point::operator=(const Point& c1){
    this->x = c1.x;
    this->y = c1.y;
    return *this;
}

int main(){
    Point a(5,6);
    Point b(3,2);
    Point c(11,2);
    Point d = a - b;
    Point e = a + b + c;
    cout << d;
    cout << e;
    system("pause");
    return 0;
}
