#include "../include/Car.h"

Car::Car(){std::cout << model << " manufactured by " << make << " from year " << year << " has just been found on the market!\n";}
Car::Car(const std::string &make, const std::string &model, int year) : make(make), model(model), year(year) {std::cout << model << " manufactured by " << make << " from year " << year << " has just been found on the market!\n";}
Car::~Car() {std::cout << "Boom! The " << model << " manufactured by " << make << " in year " << year << " has just exploded!\n";}

bool Car::operator<(const Car &other) const
{
  if (make < other.make)
    return true;
  else if (make > other.make)
    return false;

  if (model < other.model)
    return true;
  else if (model > other.model)
    return false;

  return year < other.year;
}

bool Car::operator==(const Car &other) const
{
  return make == other.make && model == other.model && year == other.year;
}

bool Car::operator!=(const Car &other) const
{
  return !operator==(other);
}

std::istream &operator>>(std::istream &inputStream, Car &car)
{
  inputStream >> car.make >> car.model >> car.year;
  return inputStream;
}

std::ostream &operator<<(std::ostream &outputStream, const Car &car)
{
  outputStream << car.make << " "<< car.model << " " << car.year << std::endl;
  return outputStream;
}
