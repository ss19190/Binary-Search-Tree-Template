/**
 * @file Car.h
 * @brief Declaration of the Car struct
 */

#ifndef __CAR_H__
#define __CAR_H__

#include <string>
#include <iostream>

/**
 * @brief Represents a car with a make, model, and year
 */
struct Car
{
public:
    std::string make;
    std::string model;
    int year;

    /**
     * @brief Default constructor.
     */
    Car();

    /**
     * @brief Constructor with parameters
     *
     * Creates a Car object with the specified make, model, and year
     *
     * @param make The make of the car
     * @param model The model of the car
     * @param year The year of the car
     */
    Car(const std::string &make, const std::string &model, int year);

    /**
     * @brief Destructor.
     */
    ~Car();

    /**
     * @brief Overloaded less-than operator
     *
     * Compares two Car objects based on their make, model, and year
     *
     * @param other The other Car object to compare with
     * @return True if this Car object is less than the other object, false otherwise
     */
    bool operator<(const Car &other) const;

    /**
     * @brief Overloaded equality operator
     *
     * Compares two Car objects based on their make, model, and year
     *
     * @param other The other Car object to compare with
     * @return True if this Car object is equal to the other object, false otherwise
     */
    bool operator==(const Car &other) const;

    /**
     * @brief Overloaded inequality operator
     *
     * Compares two Car objects based on their make, model, and year
     *
     * @param other The other Car object to compare with
     * @return True if this Car object is not equal to the other object, false otherwise
     */
    bool operator!=(const Car &other) const;

    /**
     * @brief Stream insertion operator
     *
     * Outputs the Car object to the specified output stream
     *
     * @param inputStream The output stream to write to
     * @param car The Car object to output
     * @return The output stream
     */
    friend std::istream &operator>>(std::istream &inputStream, Car &car);

    /**
     * @brief Stream extraction operator
     *
     * Reads the Car object from the specified input stream
     *
     * @param outputStream The output stream to read to
     * @param car The Car object to read into
     * @return The input stream
     */
    friend std::ostream &operator<<(std::ostream &outputStream, const Car &car);
};

#endif // __CAR_H__