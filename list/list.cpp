#include "list.h"



ostream& operator<<(ostream& os, IntList& il)
{
    Node* ptr = il.first;
    while (ptr != 0) {
        os << ptr->data << " "; ptr = ptr->link;
    }
    os << endl;
    return os;
}

void IntList::InsertBack(int e)
{
    if (!first)   //empty list
        first = last = new Node(e);
    else {      //empty가 아닌경우
        last->link = new Node(e);
        last = last->link;    //링크 연결 순서 중요!
    }
}
void IntList::InsertFront(int e) { 
    if (!first)   //empty list
        first = last = new Node(e);
    else {  //empty가 아닌경우
        first = new Node(e, first);
    
        
    }
}

void IntList::Insert(int e) {   //일반적인 insert 함수 맨앞, 맨뒤, 또는 중간에도 추가가능
    if (!first)   //empty list
        first = last = new Node(e);
    else if (first->data > e) { // list 맨 앞에 추가
        first = new Node(e, first);
    }
    else if (first->data != e) {    //prev 찾아서 링크 조정 후 추가할 예정
        Node* cur = first->link;
        Node* prev = first;
        while (cur) {
            if (cur->data > e) {     //prev 다음에 e추가 -> e다음이 cur 링크조정하기
                prev->link = new Node(e, cur);
                return;
            }
            else if (cur->data < e) { //다음노드로 가기
                prev = cur;
                cur = cur->link;
            }
            else { //(cur->data ==e)
                return;
            }
        }
        //가장 큰 숫자로 마지막에 추가
        prev->link = new Node(e, cur);
        last = prev->link;
    }
}

void IntList::Delete(int e) { //삭제할 e를 찾은 후 링크 조정해주고 삭제하기
    Node* cur = first;
    Node* prev = first;
    Node* x;
    while (cur) {
        if (cur->data > e) { //no e delete}
            return;
        }
        else if (cur->data < e) {
            prev = cur;
            cur = cur->link;
        }
        else { //cur->data==e // 삭제할 e를 찾음
            x = cur;
            prev->link = cur->link; //링크 조정 후 삭제
            if (x == first)         //fist, last 체크 후 필요하면 링크 변경
                first = cur->link;
            if (x == last)
                last = prev;

            delete x; //delete cur;
            return;

        }
    }
}
