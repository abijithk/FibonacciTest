//
//  FibonacciImpl.cpp
//  FibonacciTest
//
//  Created by Abijith Kumar on 3/10/19.
//  Copyright © 2019 Abijith Kumar. All rights reserved.
//

#include "FibonacciImpl.h"

#define FIB_INDEX_MIN 0
#define FIB_INDEX_MAX 100

#ifdef ENABLE_STACK_USAGE_CHECK
uint64_t FibonacciImpl::leastStackAddress = 0xFFFFFFFFFFFFFFFF;
uint64_t FibonacciImpl::maxStackAddress = 0;

void FibonacciImpl::setStackAddress(uint64_t addr)
{
    if (addr < FibonacciImpl::leastStackAddress)
    {
        FibonacciImpl::leastStackAddress = addr;
    }
    if (addr > FibonacciImpl::maxStackAddress)
    {
        FibonacciImpl::maxStackAddress = addr;
    }

}

void FibonacciImpl::resetStackAddresses()
{
    FibonacciImpl::leastStackAddress = 0xFFFFFFFFFFFFFFFF;
    FibonacciImpl::maxStackAddress = 0;
}
#endif

bool FibonacciImpl::iterativeFibonacci(int n, FiboResult& out)
{
#ifdef ENABLE_STACK_USAGE_CHECK
    int test;
    FibonacciImpl::setStackAddress((uint64_t)&test);
#endif
    if ((n < FIB_INDEX_MIN) || (n > FIB_INDEX_MAX))
    {
        return false;
    }
    else if (n < 2)
    {
        out = (uint64_t)n;
    }
    else
    {
        FiboResult first(0);
        out = 1;
        FiboResult temp;
        int counter = 2;
        while(counter <= n)
        {
            temp = out;
            out += first;
            first = temp;
            counter++;
        }
#ifdef ENABLE_STACK_USAGE_CHECK
        FibonacciImpl::setStackAddress((uint64_t)&counter);
#endif
    }

    return true;
}


// Trigger function for Recursive Fibonacci
bool FibonacciImpl::recursiveFibonacciTrigger(int n, FiboResult& out)
{
#ifdef ENABLE_STACK_USAGE_CHECK
    int test;
    FibonacciImpl::setStackAddress((uint64_t)&test);
#endif
    FiboResult first(0);
    out = 1;
    return FibonacciImpl::recursiveFibonacci(n, first, out);
}


// Recursive implementation of Fibonacci
bool FibonacciImpl::recursiveFibonacci(int n, FiboResult& next, FiboResult& out)
{
#ifdef ENABLE_STACK_USAGE_CHECK
    int test;
    FibonacciImpl::setStackAddress((uint64_t)&test);
#endif
    if ((n < FIB_INDEX_MIN) || (n > FIB_INDEX_MAX))
    {
        return false;
    }
    else if (n == 0)
    {
        out = next;
        return true;
    }
    else
    {
        next += out;
        return recursiveFibonacci(n-1, out, next);
    }
}
