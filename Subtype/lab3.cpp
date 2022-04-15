//B735539, 홍유빈
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

	int j = s.Size(); //Stack의 부모클래스 Bag의 Size()가 불려진다
	cout << "Stack 크기: " << j << endl;
	j = s.Top(); //Stack의 Top()가 불려진다.
	cout << "Stack Top() 결과: " << j << endl;
	j = s.Element(); //Stack의 부모클래스 Bag의 Element()가 불려진다.
	cout << "Stack Element() 결과: " << j << endl << endl;

}