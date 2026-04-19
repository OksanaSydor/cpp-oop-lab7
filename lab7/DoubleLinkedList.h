#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include "Node.h"
#include "LinkedListException.h"
#include <iostream>

using namespace std;

template <typename T>
class DoubleLinkedList
{
private:
  shared_ptr<Node<T>> head;
  shared_ptr<Node<T>> tail;
  int listSize;

public:
  DoubleLinkedList();

  bool empty() const;
  int size() const;

  void push_front(const T &value);
  void push_back(const T &value);
  void pop_front();
  void pop_back();

  T &elementAt(int index);
  void insertAt(int index, const T &value);
  void removeAt(int index);
  int find(const T &value);

  friend ostream &operator<<(ostream &os, const DoubleLinkedList<T> &list)
  {
    auto current = list.head;

    os << "[";
    while (current)
    {
      os << current->data << " <---> ";
      current = current->next;
    }
    os << "]";

    return os;
  }
};

template <typename T>
void DoubleLinkedList<T>::insertAt(int index, const T &value)
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

  auto nextNode = current->next;

  newNode->next = nextNode;
  newNode->prev = current;

  current->next = newNode;
  nextNode->prev = newNode;

  listSize++;
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

template <typename T>
bool DoubleLinkedList<T>::empty() const
{
  if (listSize == 0)
  {
    return true;
  }
  return false;
}

template <typename T>
int DoubleLinkedList<T>::size() const
{
  return listSize;
}

template <typename T>
void DoubleLinkedList<T>::push_front(const T &value)
{
  auto newNode = make_shared<Node<T>>(value);

  if (empty())
  {
    head = tail = newNode;
  }
  else
  {
    newNode->next = head; // Вказівник на next newNode-и буде вказувати на те, що на даний момент є head
    head->prev = newNode; // Вказівник на prev head-а буде вказувати на те, що на даний момент є newNode(те, що ми щойно створили)

    head = newNode;
  }
  listSize++;
}

template <typename T>
void DoubleLinkedList<T>::push_back(const T &value)
{
  auto newNode = make_shared<Node<T>>(value);

  if (empty())
  {
    head = tail = newNode;
  }
  else
  {
    newNode->prev = tail;
    tail->next = newNode;

    tail = newNode;
  }
  listSize++;
}

template <typename T>
void DoubleLinkedList<T>::pop_front()
{
  if (empty())
  {
    throw LinkedListException("List is empty");
  }

  if (head == tail)
  {
    head = tail = nullptr;
  }
  else
  {
    head = head->next;
    head->prev.reset();
  }
  listSize--;
}

template <typename T>
void DoubleLinkedList<T>::pop_back()
{
  if (empty())
    throw LinkedListException("List is empty");

  if (head == tail)
  {
    head = tail = nullptr;
  }
  else
  {
    tail = tail->prev.lock();
    tail->next = nullptr;
  }
  listSize--;
}

template <typename T>
T &DoubleLinkedList<T>::elementAt(int index)
{
  if (index < 0 || index >= listSize)
  {
    throw LinkedListException("Invalid index");
  }

  auto current = head;
  for (int i = 0; i < index; ++i)
  {
    current = current->next;
  }

  return current->data;
}

template <typename T>
int DoubleLinkedList<T>::find(const T &value)
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

template <typename T>
void DoubleLinkedList<T>::removeAt(int index)
{
  if (index < 0 || index >= listSize)
  {
    throw LinkedListException("Invalid index");
  }

  if (index == 0)
  {
    return pop_front();
  }

  if (index == listSize - 1)
  {
    return pop_back();
  }

  auto current = head;
  for (int i = 0; i < index; ++i)
  {
    current = current->next;
  }

  auto before = current->prev.lock();
  auto after = current->next;

  before->next = after;
  after->prev = before;

  listSize--;
}

#endif