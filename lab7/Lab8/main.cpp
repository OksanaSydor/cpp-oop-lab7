#include <iostream>
#include <array>
#include <string>
// #include "Student.h"

using namespace std;

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

int main()
{
  array<int, 5> a1 = {1, 2, 3, 4, 5};

  cout << "Before: ";
  printArray(a1);

  shiftClockwise(a1, 2);

  cout << "After: ";
  printArray(a1);

  array<string, 4> a2 = {"A", "B", "C", "D"};

  cout << "Before: ";
  printArray(a2);

  shiftClockwise(a2, 1);

  cout << "After: ";
  printArray(a2);

  return 0;
}