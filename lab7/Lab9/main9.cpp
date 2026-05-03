#include <algorithm>
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;

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

int main()
{
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

  return 0;
}