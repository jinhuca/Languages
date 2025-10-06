// P255.cpp : open a file.
import PPP;

void ifstreamDemo() {
  std::cout << "Please enter input file name:";
  std::string iname;
  std::cin >> iname;
  std::ifstream ist{ iname };   // ist is an input stream for the file named name
  if (!ist) {
    PPP::error("can't open input file ", iname);
  }
}

void ofstreamDemo() {

}

int main()
{

}
