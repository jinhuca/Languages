// C0201.cpp
#include <iostream>
#include <vector>
#include <string>

#include "Book.h"
#include "Catalogue.h"

void fill(Catalogue& catalogue);
void test(const Catalogue& catalogue);

int main()
{
  Catalogue catalogue;

  fill(catalogue);
  test(catalogue);

  return 0;
}

void fill(Catalogue& catalogue)
{
  catalogue.add("Life of Pi", "Martel", "Yann");
  catalogue.add("The Call of the Wild", "London", "Jack");
  catalogue.add("To Kill a Mockingbird", "Lee", "Harper");
  catalogue.add("Little Women", "Alcott", "Louisa");
  catalogue.add("The Adventures of Sherlock Holmes", "Doyle", "Conan");
  catalogue.add("And Then There Were None", "Christie", "Agatha");
  catalogue.add("Carrie", "King", "Stephen");
  catalogue.add("It: A Novel", "King", "Stephen");
  catalogue.add("Frankenstein", "Shelley", "Mary");
  catalogue.add("2001: A Space Odyssey", "Clarke", "Arthur");
  catalogue.add("Ender's Game", "Card", "Orson");
}

void search(const Catalogue& catalogue, const Book& target)
{
  cout << endl << "Find " << target << endl;

  vector<Book*> matches = catalogue.find(target);

  if (matches.size() == 0) cout << "No matches." << endl;
  else
  {
    cout << "Matches:" << endl;

    for (Book* book : matches)
    {
      cout << "  " << *book << endl;
    }
  }
}

void test(const Catalogue& catalogue)
{
  Book target1("Life of Pi", "Martel", "Yann");
  search(catalogue, target1);

  Book target2("", "King", "");
  search(catalogue, target2);

  Book target3("1984", "Orwell", "George");
  search(catalogue, target3);

  Book target4("", "", "");
  search(catalogue, target4);
}
