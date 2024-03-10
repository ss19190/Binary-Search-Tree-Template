/**
 * @file Person.h
 * @brief Declaration of the Person class
 */

#ifndef __PERSON_H__
#define __PERSON_H__

#include <iostream>

/**
 * @brief Represents a person with a name and an age
 */
class Person
{

public:
  std::string name;
  int age;
  /**
   * @brief Default constructor.
   */
  Person();

  /**
   * @brief Constructor with parameters
   *
   * Creates a Person object with the specified name and age
   *
   * @param name The name of the person
   * @param age The age of the person
   */
  Person(const std::string &name, const int &age);

  /**
   * @brief Destructor.
   */
  ~Person();

  /**
   * @brief Overloaded less-than operator
   *
   * Compares two Person objects based on their name and age
   *
   * @param other The other Person object to compare with
   * @return True if this Person object is less than the other object, false otherwise
   */
  bool operator<(const Person &other) const;

  /**
   * @brief Overloaded equality operator
   *
   * Compares two Person objects based on their name and age
   *
   * @param other The other Person object to compare with
   * @return True if this Person object is equal to the other object, false otherwise
   */
  bool operator==(const Person &other) const;

  /**
   * @brief Overloaded inequality operator
   *
   * Compares two Person objects based on their name and age
   *
   * @param other The other Person object to compare with
   * @return True if this Person object is not equal to the other object, false otherwise
   */
  bool operator!=(const Person &other) const;

  /**
   * @brief Stream insertion operator
   *
   * Outputs the Person object to the specified output stream
   *
   * @param inputStream The output stream to write to
   * @param person The Person object to output
   * @return The output stream
   */
  friend std::istream &operator>>(std::istream &inputStream, Person &person);

  /**
   * @brief Stream extraction operator
   *
   * Reads the Person object from the specified input stream
   *
   * @param outputStream The output stream to read to
   * @param person The Person object to read into
   * @return The input stream
   */
  friend std::ostream &operator<<(std::ostream &outputStream, const Person &person);
};

#endif // __PERSON_H__