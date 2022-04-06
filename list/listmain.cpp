//B735539, 홍유빈
#include <iostream>
#include "list.h"
int main()
{
    IntList il;
    il.InsertBack(5); 
    il.InsertBack(7); 
    il.InsertBack(9);   
    
    cout << il;

    il.InsertFront(4); 
    il.InsertFront(3);
    cout << il;

    il.Insert(6);   //중간 추가 
    il.Insert(10);  //맨뒤 추가
    il.Insert(2);   //맨 앞 추가
    
    il.Insert(5); il.Insert(2); il.Insert(10); // already existing ones
    cout << il;

    il.Delete(2); // delete the first int
    il.Delete(6); // delete an int in the middle 
    il.Delete(10); // delete the last int
    cout << il;
}