#ifndef CALCFUNCTIONS_HPP
#define CALCFUNCTIONS_HPP

#include <vector>
#include <cmath>

using namespace std;

/**
	Library intended to give frequently used math operations during the entire program
*/

/**
    @author Oscar Silva
    @date Sep 30, 2016
*/

/**
	\brief Computes the average of a given vector of data
	\param numbers A vector of double numbers to be averaged
	\return The average
*/
double mean(vector < double > numbers);

/**
	\brief Computes the average of a given vector of data
	\param numbers A vector of int numbers to be averaged
	\return The average
*/
double mean(vector < int > numbers);

/**
	\brief Computes the variance of a given vector of data
	\param numbers A vector of double numbers
	\return The variance
*/
double var(vector < double > numbers);

/**
	\brief Computes the variance of a given vector of data
	\param numbers A vector of int numbers
	\return The variance
*/
double var(vector < int > numbers);

/**
	\brief Computes the standard deviation of a given vector of data
	\param numbers A vector of double numbers
	\return The standard deviation
*/
double stdDesviation(vector < double > numbers);

/**
	\brief Computes the standard deviation of a given vector of data
	\param numbers A vector of int numbers
	\return The standard deviation
*/
double stdDesviation(vector < int > numbers);

/**
	\brief Computes the minimum of a given vector of data
	\param numbers The vector of double data to be processed
	\param *index (optional) A pointer to an external index
	\return The minimum datum of the vector given.

	If an external index is given the function returns the minimum value and 
	copies it to the index pointer given.
*/
double min(vector < double > numbers, int * index = nullptr);

/**
	\brief Computes the minimum of a given vector of data
	\param numbers The vector of int data to be processed
	\param *index (optional) A pointer to an external index
	\return The minimum datum of the vector given.

	If an external index is given the function returns the minimum value and 
	copies it to the index pointer given.
*/
int min(vector < int > numbers, int * index = nullptr);

/**
	\brief Computes the maximum of a given vector of data
	\param numbers The vector of double data to be processed
	\param *index (optional) A pointer to an external index
	\return The maximum datum of the vector given.

	If an external index is given the function returns the maximum value and 
	copies it to the index pointer given.
*/
double max(vector < double > numbers, int * index = nullptr);

/**
	\brief Computes the maximum of a given vector of data
	\param numbers The vector of int data to be processed
	\param *index (optional) A pointer to an external index
	\return The maximum datum of the vector given.

	If an external index is given the function returns the maximum value and 
	copies it to the index pointer given.
*/
int max(vector < int > numbers, int * index = nullptr);

#endif