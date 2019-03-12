//
//  FiboResult.h
//  FibonacciTest
//
//  Created by Abijith Kumar on 3/11/19.
//  Copyright © 2019 Abijith Kumar. All rights reserved.
//

#ifndef FiboResult_h
#define FiboResult_h
#include <iostream>

class FiboResult
{
public:
    uint64_t upper;
    uint64_t lower;
    FiboResult();
    FiboResult(uint64_t in);
    FiboResult(const FiboResult &res2);
    FiboResult& operator +=(FiboResult &res2);
    FiboResult& operator =(FiboResult &res2);
    FiboResult& operator =(uint64_t low);
    std::string getHexStr() const;
};

std::ostream& operator<<(std::ostream &strm, const FiboResult &res);


#endif /* FiboResult_h */
