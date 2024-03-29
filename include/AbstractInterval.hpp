/**
 * @authors Marco Colognese, Mattia Rossini
 * @version v1.0
 * @date October, 2018
 */

/*! \mainpage Index Page
 *
 * \section intro_sec Introduction
 *
 * \subsection intro_sec1 Library
 *
 * The project provides a library for numeric intervals, used in static analysis
 * to check variables' content.
 *
 * The library provides methods for integer and floating-point intervals, with
 * an implementation of operations with infinite values.
 *
 * An interval is an object delimited by two Bounds, which can contain infinite
 * or finite values. Every Bound is an object containing its value. Bounds have
 * arithmetic operations and comparison operators defined, as for intervals
 * classes. When an operation on interval is called, the library calls the
 * methods corresponding to the operation on the intervals' Bounds.
 *
 * The library is structured as:
 * -# an abstract class, containing the abstract interval prototype;
 * -# a Bound class, containing the definition of single Bounds;
 * -# an Infinity class, containing the definition of an Infinite value
 * (including operations);
 * -# an exception class, defining the exeption for unsupported operations;
 * -# interval class, for integer and floating point values, inheriting from
 * AbstractInterval.
 *
 *
 * \subsection intro_sec2 Interpreter
 *
 * An interpreter has also been implemented that uses the library developed to
 * perform the analysis of a program written in a simple language. This
 * interpreter performs the following analysis steps in an orderly manner:
 * -# search for the program written in the input.txt file (located in the
 * /build directory of the project);
 * -# read the file line by line, recognizing its content statement (assignment,
 * if or while);
 * -# after having identified the statement, make the changes to the variables
 * of the program, generating the corresponding intervals;
 * -# modify the intervals through the operations defined as library methods;
 * -# print a table on screen indicating the intervals corresponding to each
 * variable initialized in the object program (name, lower bound and upper
 * bound).
 */

#pragma once
#include "Bound.hpp"
#include <string>

/**
 * @brief namespace containing the implemented domain
 */
namespace domain {
/**
 * @brief Class representing a generic interval with integer numbers or floating
 * point numbers.
 */
class AbstractInterval {
private:
    /**
     * @brief The lower bound of the instantiated interval.
     * Can even be infinite.
     */
    Bound lowerBound;

    /**
     * @brief The upper bound of the instantiated interval.
     * Can even be infinite.
     */
    Bound upperBound;

public:
    /**
     * @brief Generates an interval built with two numbers or infinite
     *
     * @param l the lower bound number
     * @param u the upper bound number
     */
    AbstractInterval(const Bound& l, const Bound& u);

    /**
     * @brief Empty constructor
     */
    AbstractInterval() = default;

    /**
     * @brief Gets the lower bound of the current interval.
     *
     * @return the lower bound of the interval
     */
    virtual Bound getLowerBound() const final;

    /**
     * @brief Sets the lower bound of the current interval.
     *
     * @param object the object to be set as lower bound.
     */
    virtual void setLowerBound(const Bound& object) final;

    /**
     * @brief Gets the upper bound of the current interval.
     *
     * @return the upper bound of the interval
     */
    virtual Bound getUpperBound() const final;

    /**
     * @brief Sets the upper bound of the current interval.
     *
     * @param object the object to be set as upper bound.
     */
    virtual void setUpperBound(const Bound& object) final;

    /**
     * @brief Controls if the current interval contains just finite bounds.
     *
     * @return  'true' if the interval contains just finite bounds, 'false'
     * otherwise
     */
    virtual bool isFinite() = 0;

    /**
     * @brief Checks if the first interval is contained in the second
     * interval. An interval [l1, u1] is contained in [l2, u2] if l2 <= l1
     * and u2 >= u1.
     *
     * @param i  the interval
     * @return true if first interval is contained in the second interval,
     * false otherwise.
     */
    virtual bool isContainedIn(const AbstractInterval& i) = 0;

    /**
     * @brief Computes the width of the current interval.
     * The width of the interval is computed subtracting the lower bound
     * from the upper bound.
     *
     * @return the width of this interval
     */
    virtual Bound width() = 0;

    /**
     * @brief Controls if the interval intersects this interval.
     *
     * @param i  the second interval
     * @return 'true' if the first interval intersects this interval,
     * 'false' otherwise
     */
    virtual bool intersects(const AbstractInterval& i) = 0;
};

} // namespace domain
