# C-Helper-Headers
A loose collection of helping header files for C programming.
This is probably expanded to be c++ compatible

Headers and their use:

'belse/std_c.h'       Includes all std C headers,
                      for the version of C selcted during compile time.
                      Intended use is as precompiled project header.
                      Example:
                        gcc -std=c11 -include "belse/std_c.h" -o a.out a.c
                      Supported versions are: C89, C99, C11
                   
'belse/try_catch.h'   Creates try/catch/finaly like error handling via macros.
                      Must not be nested!
                      Note the difference in '} ENTRY;' and '} ENDTRY;'
                      ENTRY:  with FINALLY block
                      ENDTRY: without FINALLY block
                      
                      Example:
                      
                        TRY{
                          // Throws error number 1
                          THROW(1);
                        } CATCH( 1 ){
                          // catches error 1
                        } CATCH( 2 ){
                          // catches error 2
                          // but is never reached in this case
                        } FINALLY {
                          // is allways executed
                        } ENTRY;

                        TRY{
                          THROW_IF( false, 2 );
                        } CATCH( 1 ){
                        } CATCH( 2 ){
                        } ENDTRY;
                        
'belse/dbg.h'
                                            

