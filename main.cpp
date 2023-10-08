/**
 ******************************************************************************
 *
 *   Copyright (C) 2023, Kulikova Alyona, IU8-11M, variant.5
 *
 ******************************************************************************
 *
 * @name Laboratory No. 2
 *
 * @file main.cpp
 *
 * <b>Modification History</b>
 *
 *   Date        Name        Description
 *
 ******************************************************************************
 * encoding:   UTF-8 BOM
 * tab size:   4
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

#define CONST_A -2
#define CONST_B 4
#define CONST_E 0.1

/**
* @brief random_search_method_table1
* Number of iterations and Output values
*
* @param begin, end, P, q
*
* @return null
*/
void random_search_method_table1(double begin, double end, double P, double q);

/**
* @brief random_search_method_table2
* Number of iterations and Output 'N' values
*
* @param begin, end, P, q
*
* @return null
*/
void random_search_method_table2(double begin, double end, double P, double q);

/**
* @brief random_search_method_table3
* Number of iterations and Output 'N' values
*
* @param begin, end, P, q
*
* @return null
*/
void random_search_method_table3(double begin, double end, double P, double q);

void info() {
    std::cout << "=========================\nKULIKOVA ALYONA IU8-11M\n=========================\n\n";
    std::cout << "variant #5\n";

    std::cout << "=========================\n";
    std::cout << "Initial data:\n";
    std::cout << "- unimodal function f(x)=-cos0.5x-1 [a,b]=[-2,4]\n";
    std::cout << "- multimodal function f(x)=(- cos(0.5 * x) - 1) * (sin(5 * x)) [a,b]=[-2,4]\n";
    std::cout << "Search:\n";
    std::cout << "Using the random search method, search for \n"
                 "the minimum with a given probability of falling \n"
                 "into the vicinity of the extremum with an acceptable \n"
                 "length of the uncertainty interval. Determine the required \n"
                 "number of tests. Perform a numerical experiment for the values \n";
    std::cout << "=========================\n";
}

int main() {
    info();

    /* We set the variables beginning and end of the segment, permissible error, vector of values
     * probabilities of missing each test 'q' and probabilities of finding
     * extremum for N iterations 'P' */

    std::vector<double> P, q;

    /* Let us polarize the vector of probabilities of getting into the vicinity of
     * the extremum in general */
    std::cout << "\n\nrandom_search_method_table1\n\n";
    std::string menu = "  q     \\P    ";
    double tmp = 0.90;
    while(tmp < 1) {
        P.push_back(tmp);
        menu += std::to_string(tmp).substr(0, 4) + "\t";
        tmp += 0.01;
    }

    std::cout << menu << std::endl;

    /* Filling in the probability vector
     * getting into the vicinity
     * exteremum by a random point */
    tmp = 0.005;
    while(tmp < 0.101) {
        q.push_back(tmp);
        tmp += 0.005;
    }

    /* We calculate the results N for
     * P and q data */
    for(size_t i = 0; i < q.size(); ++i) {
        std::cout << std::fixed << std::setprecision(3) << std::right;
        std::cout << q[i];
        for(size_t j = 0; j < P.size(); ++j) {
            random_search_method_table1(CONST_A, CONST_B, P[j], q[i]);
        }
        std::cout << std::endl;
    }

    std::cout << "\n\nrandom_search_method_table2\n\n";
    std::cout << std::endl << menu << std::endl;

    /* We calculate the results of Ymin for
     * P and q data */

    for(size_t i = 0; i < q.size(); ++i) {
        std::cout << std::fixed << std::setprecision(3) << std::right;
        std::cout << q[i];
        for(size_t j = 0; j < P.size(); ++j) {
            random_search_method_table2(CONST_A, CONST_B, P[j], q[i]);
        }
        std::cout << std::endl;
    }

    std::cout << "\n\nrandom_search_method_table3\n\n";
    std::cout << std::endl << menu << std::endl;

    /* We calculate the results of Ymin for
     * P and q data in a multimodal function */

    for(size_t i = 0; i < q.size(); ++i) {
        std::cout << std::fixed << std::setprecision(3) << std::right;
        std::cout << q[i];
        for(size_t j = 0; j < P.size(); ++j) {
            random_search_method_table3(CONST_A, CONST_B, P[j], q[i]);
        }
        std::cout << std::endl;
    }
    return 0;
}
