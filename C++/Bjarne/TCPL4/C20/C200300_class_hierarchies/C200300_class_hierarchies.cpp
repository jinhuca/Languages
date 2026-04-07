// C200300_class_hierarchies.cpp 
#include <iostream>

class Employee {};
class Manager :public Employee {};
class Director : public Manager {};

class Temporary {};
class Assistant :public Employee {};
class Temp : public Temporary, public Assistant {};
class Consultant :public Temporary, public Manager {};

int main() {}

