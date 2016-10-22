#ifndef BELSE_UNUSED_H_
#define BELSE_UNUSED_H_

// source: http://stackoverflow.com/questions/3417837/what-is-the-best-way-to-supress-unused-variable-x-warning
#ifdef UNUSED
#elif defined(__GNUC__)
#  define UNUSED(x) UNUSED_ ## x __attribute__((unused))
#elif defined(__LCLINT__)
#  define UNUSED(x) /*@unused@*/ x
#else
#  define UNUSED(x) x
#endif

#endif /* BELSE_UNUSED_H_ */
