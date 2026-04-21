#include <iostream>
#include "LinkedListException.h"
#include "Node.h"
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"

using namespace std;

int main()
{
  cout << "----------Lab7----------" << endl;

  try
  {
    SingleLinkedList<int> sList;
    sList.push_back(10);
    sList.push_back(20);
    sList.push_front(5);
    sList.insertAt(1, 100);

    cout << sList << " Size: " << sList.size() << endl;

    cout << "Element at index 1: " << sList.elementAt(1) << endl;
    cout << "\n";

    DoubleLinkedList<string> dList;
    dList.push_back("Hello");
    dList.push_back("World");
    cout << dList << endl;
    dList.removeAt(1);
    cout << dList << endl;

    cout << "Element at index 1: " << dList.elementAt(1) << endl;
  }
  catch (const LinkedListException &e)
  {
    cerr << e.what() << endl;
  }

  return 0;
}