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
    else {      //empty�� �ƴѰ��
        last->link = new Node(e);
        last = last->link;    //��ũ ���� ���� �߿�!
    }
}
void IntList::InsertFront(int e) { 
    if (!first)   //empty list
        first = last = new Node(e);
    else {  //empty�� �ƴѰ��
        first = new Node(e, first);
    
        
    }
}

void IntList::Insert(int e) {   //�Ϲ����� insert �Լ� �Ǿ�, �ǵ�, �Ǵ� �߰����� �߰�����
    if (!first)   //empty list
        first = last = new Node(e);
    else if (first->data > e) { // list �� �տ� �߰�
        first = new Node(e, first);
    }
    else if (first->data != e) {    //prev ã�Ƽ� ��ũ ���� �� �߰��� ����
        Node* cur = first->link;
        Node* prev = first;
        while (cur) {
            if (cur->data > e) {     //prev ������ e�߰� -> e������ cur ��ũ�����ϱ�
                prev->link = new Node(e, cur);
                return;
            }
            else if (cur->data < e) { //�������� ����
                prev = cur;
                cur = cur->link;
            }
            else { //(cur->data ==e)
                return;
            }
        }
        //���� ū ���ڷ� �������� �߰�
        prev->link = new Node(e, cur);
        last = prev->link;
    }
}

void IntList::Delete(int e) { //������ e�� ã�� �� ��ũ �������ְ� �����ϱ�
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
        else { //cur->data==e // ������ e�� ã��
            x = cur;
            prev->link = cur->link; //��ũ ���� �� ����
            if (x == first)         //fist, last üũ �� �ʿ��ϸ� ��ũ ����
                first = cur->link;
            if (x == last)
                last = prev;

            delete x; //delete cur;
            return;

        }
    }
}
