#ifndef BELSE_INLINE_H_
#define BELSE_INLINE_H_

// source: http://www.greenend.org.uk/rjk/tech/inline.html
#ifndef INLINE
#  if __GNUC__ && !__GNUC_STDC_INLINE__
#    define INLINE extern inline
#  else
#    define INLINE inline
#  endif
#endif

#endif /* BELSE_INLINE_H_ */
