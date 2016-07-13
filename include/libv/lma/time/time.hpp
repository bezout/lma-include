/**

\file
\author Datta Ramadasan
//==============================================================================
//         Copyright 2015 INSTITUT PASCAL UMR 6602 CNRS/Univ. Clermont II
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================

*/

#ifndef __UTILS_SRC_TIME_TIME_HPP__
#define __UTILS_SRC_TIME_TIME_HPP__

#include <stdlib.h>
#include <ctime>
#ifndef WIN32
#include <sys/time.h>
#endif
#include <iostream>
#include <vector>
#include <chrono>


namespace utils {

//************************
//! Cette fonction lit le nombre de cycle processeur
//************************
static inline double read_cycles() {
    size_t hi, lo;
    //__asm __volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return double((long long)hi << 32 | lo);
}

static inline double  now()
{
  return double(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()) * 1e-6;
}

}//! eon utils

#endif // TIME_HPP
