#include <iostream>
#include "DList.h"
int main()
{
    DList<int> list;

    list.addHead(34);
    list.addHead(31);
    list.addHead(24);
    list.removeData(31);
    list.print();

    DList<int> list2;
    list2.addTail(14);
    list2.addTail(13);
    list2.addTail(12);
    list2.removeHead();
    list2.removeTail();
    list2.printR();

    DList<int> clone(list);
    clone.print();

}
