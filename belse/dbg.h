#ifndef BELSE_DBG_H_
#define BELSE_DBG_H_

// based on the book: http://c.learncodethehardway.org/

#include <stdio.h>
#include <errno.h>

#define __FUNC__    __func__

#ifndef NCOLOUR
#  define TERM_RED    "\e[31;1m"
#  define TERM_GREEN  "\e[32;1m"
#  define TERM_YELLOW "\e[33;1m"
#  define TERM_BLUE   "\e[34;1m"
#  define TERM_NONE   "\e[0m"
#else
#  define TERM_RED    
#  define TERM_GREEN  
#  define TERM_YELLOW 
#  define TERM_BLUE   
#  define TERM_NONE   
#endif


#define clean_errno()     (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...)   fprintf(stderr, "[" TERM_RED    "ERROR" TERM_NONE "] (%s:%d:%s: errno: %s) " M "\n", __FILE__,__LINE__,__FUNC__, clean_errno() , ##__VA_ARGS__)
#define log_warn(M, ...)  fprintf(stderr, "[" TERM_YELLOW "WARN " TERM_NONE "] (%s:%d:%s: errno: %s) " M "\n", __FILE__,__LINE__,__FUNC__, clean_errno() , ##__VA_ARGS__)
#define log_info(M, ...)  fprintf(stderr, "[" TERM_GREEN  "INFO " TERM_NONE "] (%s:%d:%s) " M "\n",            __FILE__,__LINE__,__FUNC__ , ##__VA_ARGS__)
#ifndef NDEBUG
#  define log_debug(M, ...) fprintf(stderr, "[" TERM_BLUE   "DEBUG" TERM_NONE "] (%s:%d:%s) " M "\n",            __FILE__,__LINE__,__FUNC__ , ##__VA_ARGS__)
#else
#  define log_debug(M, ...) ((void)0)
#endif

#define check(A, M, ...)  do{if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }}while(0)

#define sentinel(M, ...)  do{ log_err(M, ##__VA_ARGS__); errno=0; goto error;}while(0)

#define check_mem(A)      check((A), "Out of memory.")


#endif /* BELSE_DBG_H_ */
