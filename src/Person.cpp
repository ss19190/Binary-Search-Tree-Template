#include "../include/Person.h"

Person::Person(){std::cout << "Newsflash! " << name << " traveled to us from the past at the age of " << age << "!\n";}
Person::Person(const std::string &name, const int &age) : name(name), age(age){std::cout << "Newsflash! " << name << " traveled to us from the past at the age of " << age << "!\n";};
Person::~Person() {std::cout << "Attention: Subject " << name << " has just vanished into the void at the age of " << age << "!\n";}

bool Person::operator<(const Person &other) const
{
  if (name < other.name)
    return true;
  else if (name > other.name)
    return false;

  return age < other.age;
}

bool Person::operator==(const Person &other) const
{
  return name == other.name && age == other.age;
}

bool Person::operator!=(const Person &other) const
{
  return !operator==(other);
}

std::istream &operator>>(std::istream &inputStream, Person &person)
{
  inputStream >> person.name >> person.age;
  return inputStream;
}

std::ostream &operator<<(std::ostream &outputStream, const Person &person)
{
  outputStream << person.name << " " << person.age << std::endl;
  return outputStream;
}
