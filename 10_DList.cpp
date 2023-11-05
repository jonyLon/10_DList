#include <iostream>
#include "DList.h"
int main()
{
    DList<int> list;

    list.addHead(34);
    list.addHead(12);
    list.addHead(24);
    list.removeData(31);
    list.addHead(13);
    list.addHead(44);
    list.print();

    DList<int> list2;
    list2.addTail(14);
    list2.addTail(13);
    list2.addTail(12);
    list2.addTail(12);
    list2.addTail(11);
    list2.addTail(18);
    list2.addTail(16);
    list2.addAfter(13, 88);
    list2.addBefore(13, 88);
    cout <<"Replaces: " << list2.replaceAll(88, 1) << endl;
    list2.print();
    list2.printR();
    DList<int> clone(list);
    clone.print();
    DList<int> list3 = list + list2;
    list3.print();
    //list += list2;
    //list.print();
    list.print();
    list2.print();
    DList<int> list4 = list * list2;
    list4.print();


}
