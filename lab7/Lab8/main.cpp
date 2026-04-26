#include <iostream>
#include <array>
#include <vector>
#include <string>
#include "Student.h"

using namespace std;

// Task 1
template <typename T, size_t size>
void printArray(const array<T, size> &arr)
{
  for (auto it = arr.begin(); it != arr.end(); ++it)
  {
    cout << *it << " ";
  }
  cout << endl;
}

template <typename T, size_t size>
void shiftClockwise(array<T, size> &arr, int shift)
{
  if (size == 0)
  {
    return;
  }

  if (shift >= size)
  {
    shift = shift - size;
  }

  for (int s = 0; s < shift; s++)
  {
    auto lastIt = arr.end();
    --lastIt;
    T last = *lastIt;

    auto it = arr.end();
    --it;

    while (it != arr.begin())
    {
      auto prevIt = it;
      --prevIt;

      *it = *prevIt;

      --it;
    }

    *arr.begin() = last;
  }
}

// Task 2

template <typename T>
void printVector(const vector<T> &vector)
{
  for (auto it = vector.begin(); it != vector.end(); ++it)
  {
    cout << *it << " ";
  }
  cout << endl;
}

template <typename T>
void insertRange(vector<T> &first, const vector<T> &second, int position)
{
  if (position < 0)
  {
    position = 0;
  }

  if (position > first.size())
  {
    position = first.size();
  }

  auto insertIt = first.begin();

  for (int i = 0; i < position; i++)
  {
    ++insertIt;
  }

  auto secondIt = second.begin();

  for (; secondIt != second.end(); ++secondIt)
  {
    insertIt = first.insert(insertIt, *secondIt);
    ++insertIt;
  }
}

int main()
{
  cout << "---------- Task 1 ----------" << endl;
  cout << "\n";

  array<int, 5> a1 = {1, 2, 3, 4, 5};

  cout << "Before: ";
  printArray(a1);

  shiftClockwise(a1, 2);

  cout << "After: ";
  printArray(a1);
  cout << "\n";

  array<string, 4> a2 = {"A", "B", "C", "D"};

  cout << "Before: ";
  printArray(a2);

  shiftClockwise(a2, 1);

  cout << "After: ";
  printArray(a2);
  cout << "\n";

  array<Student, 3> a3 = {
      Student("Arsen", 99),
      Student("Ira", 88),
      Student("Nastia", 85)};

  cout << "Before: ";
  printArray(a3);

  shiftClockwise(a3, 1);

  cout << "After: ";
  printArray(a3);
  cout << "\n";

  cout << "---------- Task 2 ----------" << endl;
  cout << "\n";

  vector<int> v1 = {1, 2, 3, 4, 5};
  vector<int> v2 = {10, 200, 3000};

  cout << "Before: ";
  printVector(v1);

  insertRange(v1, v2, 3);

  cout << "After: ";
  printVector(v1);
  cout << "\n";

  vector<string> s1 = {"Apple", "Tomato", "Cucumber"};
  vector<string> s2 = {"sun", "moon"};

  cout << "Before: ";
  printVector(s1);

  insertRange(s1, s2, 1);

  cout << "After: ";
  printVector(s1);
  cout << "\n";

  vector<Student> vst1 = {
      Student("Arsen", 99),
      Student("Ira", 88)};

  vector<Student> vst2 = {
      Student("Nastia", 85),
      Student("Marta", 91)};

  cout << "Before: ";
  printVector(vst1);

  insertRange(vst1, vst2, 10);

  cout << "After: ";
  printVector(vst1);
  cout << "\n";

  return 0;
}