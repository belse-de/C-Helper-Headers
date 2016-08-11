#pragma once
#ifndef BELSE_STD_C_H_
#define BELSE_STD_C_H_

#ifdef __cplusplus
		#error "Do not use belse_std_c with C++, because there are compatibility headers native there!"
#endif

#if   (__STDC_VERSION__ == 199409L) // c89
#  include "std_c89.h"
#elif (__STDC_VERSION__ == 199901L) // c99
#  include "std_c89.h"
#  include "std_c95.h"
#  include "std_c99.h"
#elif (__STDC_VERSION__ == 201112L) // c11
#  include "std_c89.h"
#  include "std_c95.h"
#  include "std_c99.h"
#  include "std_c11.h"
#endif

#endif /* BELSE_STD_C_H_ */
