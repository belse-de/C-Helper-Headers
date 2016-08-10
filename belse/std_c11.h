#pragma once
#ifndef BELSE_STD_C11_H_
#define BELSE_STD_C11_H_

#include "std_c99.h"

#include <stdalign.h>    // alignas and alignof convenience macros
#ifndef  __STDC_NO_ATOMICS__
#  include <stdatomic.h>   // Atomic types
#endif
#include <stdnoreturn.h> // noreturn convenience macros
#ifndef __STDC_NO_THREADS__
#  include <threads.h>     // Thread library
#endif
#include <uchar.h>       // UTF-16 and UTF-32 character utilities

#endif /* BELSE_STD_C11_H_ */
