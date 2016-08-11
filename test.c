#include "belse/dbg.h"

#define BELSE_TRY_CATCH_VERSION 3
#include "belse/try_catch.h"

int main(void)
{
  log_debug("Test: %d", __COUNTER__);
  log_info("Test: %d", __COUNTER__);
  log_warn("Test: %d", __COUNTER__);
  log_err("Test: %d", __COUNTER__);
  
  goto test;
  
error:
  log_debug("Test error: %d", __COUNTER__);
  goto rest;
  
test:
  check(false, "Test test: %d", __COUNTER__);
  assert(false);
  
rest:
  log_debug("Test rest: %d", __COUNTER__);
  
  TRY{
    log_debug("Test try_finaly try: %d", __COUNTER__);
    THROW( 1 );
    assert(false);
  } CATCH( 1 ){
    log_debug("Test try_finaly catch: %d", __COUNTER__);
  } CATCH( 2 ){
    assert(false);
  } FINALLY {
    log_debug("Test try_finaly finaly: %d", __COUNTER__);
  } ENTRY;

  TRY{
    log_debug("Test try_catch try: %d", __COUNTER__);
    THROW( 2 );
    assert(false);
  } CATCH( 1 ){
    assert(false);
  } CATCH( 2 ){
    log_debug("Test try_catch catch: %d", __COUNTER__);
  } ENDTRY;
  
  log_debug("Test exit: %d", __COUNTER__);
  
  printf("Good Bye.\n");
  
  exit(EXIT_SUCCESS);
}
