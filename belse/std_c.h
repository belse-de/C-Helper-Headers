#pragma once
#ifndef BELSE_STD_C_H_
#define BELSE_STD_C_H_

#if   (__STDC_VERSION__ == 199409L) || (__cplusplus == 199711L) // c89 or c++98
#  include "std_c89.h"
#elif (__STDC_VERSION__ == 199901L) || (__cplusplus == 201103L) // c99 or c++11
#  include "std_c99.h"
#elif (__STDC_VERSION__ == 201112L) || (__cplusplus == 201402L) // c11 or c++14
#  include "std_c11.h"
#endif

#endif /* BELSE_STD_C_H_ */
