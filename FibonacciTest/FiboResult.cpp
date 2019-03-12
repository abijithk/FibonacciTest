//
//  FiboResult.cpp
//  FibonacciTest
//
//  Created by Abijith Kumar on 3/11/19.
//  Copyright © 2019 Abijith Kumar. All rights reserved.
//
#include "FiboResult.h"
#include <inttypes.h>
#include <iomanip>
#include <sstream>
#include "BaseConverter.h"

FiboResult::FiboResult()
: upper(0),
lower(0)
{
    // nothing here
}


FiboResult::FiboResult(uint64_t in)
: upper(0),
lower(in)
{
    // nothing here
}


FiboResult::FiboResult(const FiboResult &res2)
{
    lower = res2.lower;
    upper = res2.upper;
}


FiboResult& FiboResult::operator=(FiboResult &res2)
{
    upper = res2.upper;
    lower = res2.lower;
    return *this;
}


FiboResult& FiboResult::operator =(uint64_t low)
{
    upper = 0;
    lower = low;
    return *this;
}


FiboResult& FiboResult::operator+=(FiboResult &res2)
{
    upper += res2.upper + ((lower + res2.lower) < lower);
    lower += res2.lower;
    return *this;
}

// Returns the hexadecimal string equivalent of the 128 bit result ie upto 32 bytes long hex string
std::string FiboResult::getHexStr() const
{
    std::stringstream out;
    out << std::uppercase << std::hex << upper << std::setfill('0') << std::setw(16) << std::hex << lower;
    return out.str();
}

// Operator << to handle all FiboResult objects in output stream
std::ostream& operator<<(std::ostream &strm, const FiboResult &res)
{
    if (res.upper > 0)
    {
        const BaseConverter& hex2dec = BaseConverter::HexToDecimalConverter();
        return strm << hex2dec.Convert(res.getHexStr());
    }
    else
    {
        return strm << res.lower;
    }
}


