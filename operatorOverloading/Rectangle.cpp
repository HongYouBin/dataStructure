#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(int x = 0, int y = 0, int h = 0, int w = 0)
	: xLow(x), yLow(y), height(h), width(w){
}

Rectangle::~Rectangle(){
}

void Rectangle::Print()
{  // ���� ���õ� ���â�� ���˿� �°� ����� �� �ֵ��� ����
	cout << "xLow: " << xLow << ", yLow: " << yLow << ", height: "
		<< height << ", width: " << width << endl;
}

int Rectangle::Area()
{  // �������� �����Ͽ� ��ȯ�ϱ� 
	return width * height;
}


bool Rectangle::LessThan(Rectangle& s)
{  // �簢���� ����(Area())�� ū ��� ū �簢������ ���� 
	if (Area() < s.Area())
		return true;
	else return false;
}

bool Rectangle::Equal(Rectangle& s)
{  //��ġ, ����, ���� ��� ���ƾ� ���� �簢������ ���� 
	if (this == &s)
		return true;
	if ((xLow == s.xLow) && (yLow == s.yLow) && (height == s.height) && (width == s.width))
		return true;
	else return false;
}

int Rectangle::GetHeight(){ return height; }

int Rectangle::GetWidth() {
	return width; }

ostream& operator<<(ostream& os, Rectangle& s)
{
	//Rectangle s�� ��� ���� �� ���˿� ���߾� ����ϱ� 
	 os << "xLow: " << s.xLow << ", yLow: " << s.yLow << ", height: "
		<< s.height << ", width: " << s.width << endl;
	 return os;
}

bool Rectangle::operator<(Rectangle& s)
{
	if (Area() < s.Area())
		return true;
	else return false;
}

bool Rectangle::operator==(Rectangle& s)
{
	if (this == &s)
		return true;
	if ((xLow == s.xLow) && (yLow == s.yLow) && (height == s.height) && (width == s.width))
		return true;
	else return false;
}
