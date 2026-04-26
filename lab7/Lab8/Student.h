#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
  string name;
  int points;

public:
  Student()
  {
    name = "";
    points = 0;
  }

  Student(string name, int points) : name(name), points(points) {}

  friend ostream &operator<<(ostream &os, const Student &s)
  {
    os << s.name << "(" << s.points << ")";
    return os;
  }
};

#endif