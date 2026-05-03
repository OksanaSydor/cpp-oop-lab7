#include <algorithm>
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <array>
#include <string>

using namespace std;

// Task 1
bool isOdd(int n)
{
  return n % 2 != 0;
}

template <typename T>
void printList(const list<T> &l)
{
  for (T value : l)
  {
    cout << value << " ";
  }
  cout << '\n';
}

// Task 2
bool compareLength(const string &a, const string &b)
{
  return a.length() < b.length();
}

template <typename T, size_t size>
void printArray(const array<T, size> &arr)
{
  for (const T &value : arr)
  {
    cout << value << " ";
  }
  cout << '\n';
}

int main()
{
  cout << "----------Task 1----------" << endl;

  list<int> numbers;

  srand(time(nullptr));

  for (int i = 0; i < 20; ++i)
  {
    numbers.push_back(rand() % 100 + 1);
  }

  cout << "Before: \n";
  printList(numbers);

  auto newEnd = remove_if(numbers.begin(), numbers.end(), isOdd);
  numbers.erase(newEnd, numbers.end());

  cout << "After: \n";
  printList(numbers);

  cout << "----------Task 2----------" << endl;

  array<string, 6> names = {"Oksana", "Ivan", "Anna", "Petro", "Olha", "Max"};

  cout << "Before: \n";
  printArray(names);

  sort(names.begin(), names.end(), compareLength);

  cout << "After: \n";
  printArray(names);

  return 0;
}