#ifndef LINKED_LIST_EXCEPTION_H
#define LINKED_LIST_EXCEPTION_H

#include <stdexcept>
#include <string>

using namespace std;

class LinkedListException : public runtime_error
{
public:
  LinkedListException(const string &message) : runtime_error("LinkedList Error: " + message) {}
};

#endif