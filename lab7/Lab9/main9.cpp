#include <algorithm>
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <array>
#include <string>
#include <deque>
#include <set>
#include <map>
#include <vector>

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

// Task 3
struct TaxApplier
{
  double taxRate;

  TaxApplier(double taxRate) : taxRate(taxRate) {}

  void operator()(double &price)
  {
    price *= (1 + taxRate);
  }
};

template <typename T>
void printDeque(const deque<T> &d)
{
  for (const T &value : d)
  {
    cout << value << " ";
  }
  cout << '\n';
}

// Task 4
struct WithinRange
{
  int minValue;
  int maxValue;

  WithinRange(int min, int max) : minValue(min), maxValue(max) {}

  bool operator()(int value) const
  {
    return value >= minValue && value <= maxValue;
  }
};

// Task 5
void printSet(const set<int> &s)
{
  for (const int &value : s)
  {
    cout << value << " ";
  }
  cout << '\n';
}

// Task 6
void printVector(vector<int> &v)
{
  for (const int &value : v)
  {
    cout << value << " ";
  }
  cout << '\n';
}

// Task 8
bool isVowel(char c)
{
  c = tolower(c);

  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
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

  cout << "----------Task 3----------" << endl;

  deque<double> prices = {100.0, 250.5, 80.0, 120.75};

  cout << "Before: \n";
  printDeque(prices);

  TaxApplier tax(0.2);

  for_each(prices.begin(), prices.end(), tax);

  cout << "After :\n";
  printDeque(prices);

  cout << "----------Task 4----------" << endl;

  set<int> snumbers = {-3, 0, 1, 5, 10, 15, 20, 25, 30, 43, 80};

  int min = 5;
  int max = 20;

  WithinRange range(min, max);

  int count = count_if(snumbers.begin(), snumbers.end(), range);

  cout << "Set: " << endl;
  printSet(snumbers);
  cout << "Amount of numbers in range from " << min << " to " << max << ": " << count << endl;

  cout << "----------Task 5----------" << endl;

  map<string, int> foodstuff = {{"Apples", 54}, {"Cucumbers", 230}, {"Chocolate bars", 200}, {"Milk", 87}, {"Bread", 187}};

  cout << "Items which are enough: \n";

  for_each(foodstuff.begin(), foodstuff.end(), [](const pair<string, int> &item)
           {if (item.second > 100){cout << item.first << ": " << item.second << endl;} });

  cout << "----------Task 6----------" << endl;

  vector<int> vnumbers = {-4, 10, -25, -3, 2, 90, 8};

  cout << "Before: \n";
  printVector(vnumbers);

  replace_if(vnumbers.begin(), vnumbers.end(), [](int n)
             { return n < 0; }, 0);

  cout << "After: \n";
  printVector(vnumbers);

  cout << "----------Task 7----------" << endl;

  double sum = 0;

  for_each(vnumbers.begin(), vnumbers.end(), [&sum](int n)
           { sum += n; });

  double average = 0;

  if (!vnumbers.empty())
  {
    average = sum / vnumbers.size();
  }

  cout << "Sum: " << sum << endl;
  cout << "Average: " << average << endl;

  cout << "----------Task 8----------" << endl;

  string text = "The eight task.";

  int count2 = count_if(text.begin(), text.end(), isVowel);

  cout << "Text: " << text << endl;
  cout << "Amount of vowels: " << count2 << endl;

  return 0;
}
