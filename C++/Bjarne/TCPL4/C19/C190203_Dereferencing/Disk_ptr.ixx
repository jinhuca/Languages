export module Disk_ptr;
import std;

export template<typename T>
class Disk_ptr {
  std::string identifier;
  T* in_core_address;
  // ...
public:
  Disk_ptr(const std::string& s) :identifier { s }, in_core_address { nullptr } {}
  ~Disk_ptr() { write_to_disk(in_core_address); }
  T* read_from_disk(const std::string& string) { return &string; }

  T* operator->() {
    if(in_core_address == nullptr)
      in_core_address = read_from_disk(identifier);
    return in_core_address;
  }
};

export struct Rec {
  std::string name;
  // ...
};