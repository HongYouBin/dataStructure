//B735539, ȫ����
#include <iostream>
using namespace std;

void sum(int* a, int b) {
	int k=0;
	cout << a << ' '<<*a << ' '<<&a<<endl;
	for (int i = 0; i < b; i++) {
		k += a[i];
	}
	cout << k;
	int* tmp=new int[3];
	std::copy(a, a + 3, tmp);
	cout << tmp << ' ' << *tmp << ' ' << &tmp << endl;
}

#include "bagstack.h"
int main() {
	int array[3] = { 1,2,3 };
	cout << array << ' ' << *array<<' '<<&array << endl;
	sum(array, 3);

	Bag b(3);
	Stack s(3);

	b.Push(1); 
	b.Push(2);
	b.Push(3);
	b.Push(4);
	b.Push(5);
	cout << "Bag: " << b;
	
	s.Push(1); 
	s.Push(2);
	s.Push(3);
	
	cout << "Stack: " << s << endl;
	
	b.Pop(); s.Pop();
	cout << "Bag: " << b;
	cout << "Stack: " << s << endl << endl;

	int j = s.Size(); //Stack�� �θ�Ŭ���� Bag�� Size()�� �ҷ�����
	cout << "Stack ũ��: " << j << endl;
	j = s.Top(); //Stack�� Top()�� �ҷ�����.
	cout << "Stack Top() ���: " << j << endl;
	j = s.Element(); //Stack�� �θ�Ŭ���� Bag�� Element()�� �ҷ�����.
	cout << "Stack Element() ���: " << j << endl << endl;

}