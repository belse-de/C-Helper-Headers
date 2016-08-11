#pragma once
#ifndef BELSE_STD_CPP_H_
#define BELSE_STD_CPP_H_

#if   (__cplusplus == 199711L) // c++98
#  include "std_cpp98.h"
#elif (__cplusplus == 201103L) // c++11
#  include "std_cpp11.h"
#elif (__cplusplus == 201402L) // c++14
#  include "std_cpp14.h"
#endif

#endif /* BELSE_STD_CPP_H_ */
