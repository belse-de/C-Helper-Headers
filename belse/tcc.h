
#ifndef BELSE_TCC_H_
#define BELSE_TCC_H_

#if defined(__TINYC__)
// tcc Currently missing items are: complex and imaginary numbers and variable length arrays.
static int __CONTER__i=0;
#  define __COUNTER__ (__CONTER__i++)

#define __GNUC_VA_LIST
typedef char* __gnuc_va_list;
typedef	char*	 __va_list;	/* pretend */
typedef char*  __isoc_va_list;

#define __STDC_NO_COMPLEX__
#define _COMPLEX_H
#define _TGMATH_H



#endif /* defined(__TINYC__) */

#endif /* BELSE_TCC_H_ */
