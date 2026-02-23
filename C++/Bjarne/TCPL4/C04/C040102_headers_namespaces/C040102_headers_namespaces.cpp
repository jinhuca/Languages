// C040102_headers_namespaces.cpp 
#include <iostream>
#include <string>
#include <list>

std::string s {"Four legs Good; two legs Bad!"};
std::list<std::string> slogans {"War is Peace", "Freedom is Slavery", "Ignorance is Strength"};

using namespace std;

string s1 {"C++ is a general-purpose programming language"};  // OK: string is std::string

int main() {
	std::cout << s << '\n';
	std::cout << s1 << '\n';
	for(const auto& s : slogans)
		std::cout << s << '\n';
}
