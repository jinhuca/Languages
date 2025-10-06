#pragma once
import std;

class Student {
public:
  Student(std::string n, int a) : name { n }, age { a } {}
  ~Student() {
    std::cout << "destruct student object: " << name << '\n';
  }
private:
  std::string name;
  int age;
};