#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include "Node.h"
#include "LinkedListException.h"
#include <iostream>

using namespace std;

template <typename T>
class SingleLinkedList
{
private:
  shared_ptr<Node<T>> head;
  int listSize;

public:
  SingleLinkedList();

  void push_front(const T &value);
  void push_back(const T &value);

  void pop_front();
  void pop_back();

  int size() const;
  bool empty() const;

  T &elementAt(int index);
  void insertAt(int index, const T &value);
  void removeAt(int index);
  int find(const T &value);

  friend ostream &operator<<(ostream &os, const SingleLinkedList<T> &list)
  {
    auto current = list.head;
    os << "[ ";
    while (current)
    {
      os << current->data << " ";
      current = current->next;
    }
    os << "]";

    return os;
  }
};

#include "SingleLinkedList.h"

template <typename T>
SingleLinkedList<T>::SingleLinkedList() : head(nullptr), listSize(0) {}

template <typename T>
bool SingleLinkedList<T>::empty() const
{
  if (listSize == 0)
  {
    return true;
  }
  return false;
  // return size == 0;
}

template <typename T>
int SingleLinkedList<T>::size() const
{
  return listSize;
}

template <typename T>
void SingleLinkedList<T>::push_front(const T &value)
{
  auto newNode = make_shared<Node<T>>(value);
  newNode->next = head;
  head = newNode;
  listSize++;
}

template <typename T>
void SingleLinkedList<T>::push_back(const T &value)
{
  auto newNode = make_shared<Node<T>>(value);
  if (empty())
  {
    head = newNode;
  }
  else
  {
    auto current = head;

    while (current->next)
    {
      current = current->next;
    }
    current->next = newNode;
  }
  listSize++;
}

template <typename T>
void SingleLinkedList<T>::pop_front()
{
  if (empty())
  {
    throw LinkedListException("List is empty");
  }
  head = head->next;
  listSize--;
}

template <typename T>
void SingleLinkedList<T>::pop_back()
{
  if (empty())
  {
    throw LinkedListException("List is empty");
  }

  if (listSize == 1)
  {
    head = nullptr;
  }
  else
  {
    auto current = head;
    while (current->next->next)
    {
      current = current->next;
    }
    current->next = nullptr;
  }
  listSize--;
}

template <typename T>
T &SingleLinkedList<T>::elementAt(int index)
{
  if (index < 0 || index >= listSize)
  {
    throw LinkedListException("Out of range");
  }

  auto current = head;
  for (int i = 0; i < index; ++i)
  {
    current = current->next;
  }

  return current->data;
}

template <typename T>
void SingleLinkedList<T>::insertAt(int index, const T &value)
{
  if (index < 0 || index > listSize)
  {
    throw LinkedListException("Invalid index");
  }

  if (index == 0)
  {
    return push_front(value);
  }

  if (index == listSize)
  {
    return push_back(value);
  }

  auto newNode = make_shared<Node<T>>(value);
  auto current = head;
  for (int i = 0; i < index - 1; ++i)
  {
    current = current->next;
  }

  newNode->next = current->next;
  current->next = newNode;
  listSize++;
}

template <typename T>
void SingleLinkedList<T>::removeAt(int index)
{
  if (index < 0 || index >= listSize)
  {
    throw LinkedListException("Invalid index");
  }

  if (index == 0)
  {
    return pop_front();
  }

  auto current = head;
  for (int i = 0; i < index - 1; ++i)
  {
    current = current->next;
  }

  current->next = current->next->next;
  listSize--;
}

template <typename T>
int SingleLinkedList<T>::find(const T &value)
{
  auto current = head;
  for (int i = 0; i < listSize; ++i)
  {
    if (current->data == value)
    {
      return i;
    }

    current = current->next;
  }
  return -1;
}

#endif