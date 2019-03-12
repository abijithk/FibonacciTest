//
//  main.cpp
//  FibonacciTest
//
//  Created by Abijith Kumar on 3/10/19.
//  Copyright © 2019 Abijith Kumar. All rights reserved.
//

#include <iostream>
#include "FibonacciImpl.h"
#include <chrono>
#include <iomanip>

#define FIBO_TEST_RANGE_MIN -5
#define FIBO_TEST_RANGE_MAX 105

int main(int argc, const char * argv[]) {
    std::cout << "**************************************************\n";
    std::cout << "*********** Starting Fibonacci Test! *************\n";
    std::cout << "**************************************************\n";

    std::cout << "\n\n-------------- Recursive Fibonacci ---------------\n\n";
    for(int n = FIBO_TEST_RANGE_MIN; n <= FIBO_TEST_RANGE_MAX; ++n)
    {
        bool result = false;
        FiboResult out;
#ifndef ENABLE_STACK_USAGE_CHECK
        auto start = std::chrono::high_resolution_clock::now();
#else
        FibonacciImpl::resetStackAddresses();
#endif
        result = FibonacciImpl::recursiveFibonacciTrigger(n, out);
#ifndef ENABLE_STACK_USAGE_CHECK
        auto stop = std::chrono::high_resolution_clock::now();
#endif
        if (result)
        {
#ifdef ENABLE_STACK_USAGE_CHECK
            std::cout << "Index : " << n << "\tResult : " << std::setw(30) << out << "\tMem : " << (FibonacciImpl::maxStackAddress - FibonacciImpl::leastStackAddress) << std::endl;
#else
            std::cout << "Index : " << n << "\tResult : " << std::setw(30) << out << "\tTime : " << (stop - start).count() << std::endl;
#endif
        }
        else
        {
            std::cout << "Invalid input index : " << n << std::endl;
        }
    }
    
    std::cout << "\n--------------------------------------------------\n";
    std::cout << "\n\n-------------- Iterative Fibonacci ---------------\n\n";
    // Run Iterative Fibonacci test
    for(int n = FIBO_TEST_RANGE_MIN; n <= FIBO_TEST_RANGE_MAX; ++n)
    {
        FiboResult out;
#ifndef ENABLE_STACK_USAGE_CHECK
        auto start = std::chrono::high_resolution_clock::now();
#else
        FibonacciImpl::resetStackAddresses();
#endif
        bool result = FibonacciImpl::iterativeFibonacci(n, out);
#ifndef ENABLE_STACK_USAGE_CHECK
        auto stop = std::chrono::high_resolution_clock::now();
#endif
        if (result)
        {
#ifdef ENABLE_STACK_USAGE_CHECK
            std::cout << "Index : " << n << "\tResult : " << std::setw(30) << out << "\tMem : " << (FibonacciImpl::maxStackAddress - FibonacciImpl::leastStackAddress) << std::endl;
#else
            std::cout << "Index : " << n << "\tResult : " << std::setw(30) << out << "\tTime : " << (stop - start).count() << std::endl;
#endif
        }
        else
        {
            std::cout << "Invalid input index : " << n << std::endl;
        }
    }
    std::cout << "\n--------------------------------------------------\n";
    return 0;
}
