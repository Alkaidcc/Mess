#include<iostream>
#include<math.h>
#define Pi 3.1415926
#define R 6371
using namespace std;
double distance(double x1,double y1,double x2,double y2 )
{
    double d,c;
    c=acos(cos(90-y2)*cos(90-y1)+sin(90-y2)*sin(90-y1)*cos(x2-x1));
	cout<<c<<" ";
	c=double(c/180)*Pi;
	cout<<c<<" ";
	d=R*c;
	cout<<d<<" ";
	return d;
}
int main()
{
	double x1=120.10,y1=30.16,x2=121.29,y2=31.14,d;
	d=distance(x1,y1,x2,y2);
	cout<<d;
    system("pause");	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
}
