//
//  FibonacciImpl.h
//  FibonacciTest
//
//  Created by Abijith Kumar on 3/10/19.
//  Copyright © 2019 Abijith Kumar. All rights reserved.
//

#ifndef FibonacciImpl_h
#define FibonacciImpl_h
#include <iostream>
#include "FiboResult.h"

//#define ENABLE_STACK_USAGE_CHECK

class FibonacciImpl
{
public:
    static bool iterativeFibonacci(int n, FiboResult& out);
    static bool recursiveFibonacciTrigger(int n, FiboResult& out);

#ifdef ENABLE_STACK_USAGE_CHECK
    static uint64_t leastStackAddress;
    static uint64_t maxStackAddress;
    static void resetStackAddress();
private:
    static void setStackAddresses(uint64_t addr);
    static void setMaxStackAddress(uint64_t addr);
#endif
    
private:
    static bool recursiveFibonacci(int n, FiboResult& first, FiboResult& out);

};

#endif /* FibonacciImpl_h */
