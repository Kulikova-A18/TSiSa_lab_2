#include "determination_method.h"

/**
* @brief optimal_passive_method
* Returns the value of the function at a given point
*
* @param x
*
* @return result unimodal function -cos(0.5 * x) - 1
*/
double unimodal_function(double x) {
    return (double)-cos(0.5 * x) - 1;
}

/**
* @brief multimodal_function
* Returns the value of the function at a given point
*
* @param x
*
* @return result multimodal function (-cos(0.5 * x) - 1) * (sin(5 * x))
*/
double multimodal_function(double x) {
    return (double) (-cos(0.5 * x) - 1) * (sin(5 * x));
}

/**
* @brief _random
* random double on a given segment
*
* @param [min, max]
*
* @return random double on a given segment
*/
double _random(const double min, const double max) {
    double result = (double)rand() / RAND_MAX;
    return min + result * (max - min);
}

/*
 * ********************
 * Random Search Method
 * ********************
 * Based on the given probabilities, it is calculated
 * required number of interactions
 * by random selection of points that
 * provide the opportunity to provide data
*/

/**
* @brief random_search_method_table1
* Number of iterations and Output values
*
* @param begin, end, P, q
*
* @return null
*/
void random_search_method_table1(double begin, double end, double P, double q) {
    size_t N = log(1 - P) / log(1 - q); // Number of iterations

    std::cout << std::fixed << std::setprecision(5) << std::right;
    std::cout << "\t" << N;
}

/**
* @brief random_search_method_table2
* Number of iterations and Output 'N' values
*
* @param begin, end, P, q
*
* @return null
*/
void random_search_method_table2(double begin, double end, double P, double q) {
    size_t N = log(1 - P) / log(1 - q); // Number of iterations

    double X_min = begin, Y_min = unimodal_function(begin), Xi = 0;

    for (size_t i = 0; i < N; ++i) {
        Xi = _random(begin, end);

        // Checking if the condition is met
        if (unimodal_function(Xi) < Y_min) {
            Y_min = unimodal_function(Xi);
            X_min = Xi;
        }
    }

    std::cout << std::fixed << std::setprecision(5) << std::right;
    std::cout << "\t" << Y_min;
}

/**
* @brief random_search_method_table3
* Number of iterations and Output 'N' values
*
* @param begin, end, P, q
*
* @return null
*/
void random_search_method_table3(double begin, double end, double P, double q) {
    // Число итераций.
    size_t N = log(1 - P) / log(1 - q);  // Number of iterations

    double X_min = begin, Y_min = multimodal_function(begin), Xi = 0;

    for (size_t i = 0; i < N; ++i) {
        Xi = _random(begin, end);

        // Checking if the condition is met
        if (multimodal_function(Xi) < Y_min) {
            Y_min = multimodal_function(Xi);
            X_min = Xi;
        }
    }

    std::cout << std::fixed << std::setprecision(5) << std::right;
    std::cout << "\t" << Y_min;
}
