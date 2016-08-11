#!/usr/bin/tcc -run -Wall -Werror -g -b -I/usr/lib/gcc/x86_64-pc-linux-gnu/6.1.1/include/

// tcc Currently missing items are: complex and imaginary numbers and variable length arrays. 
#include "belse/tcc.h"
#include "belse/std_c.h"
#include "belse/dbg.h"
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
  
  // test finally
  TRY{
    log_debug("Test try_finaly try: %d", __COUNTER__);
    THROW( 1 );
    assert(false);
  } CATCH( 1 ){
    log_debug("Test try_finaly catch: %d", __COUNTER__);
  } CATCH( 2 ){
    assert(false);
  } CATCH_UNKNOWN {
    assert(false);
  } FINALLY {
    log_debug("Test try_finaly finaly: %d", __COUNTER__);
  } ENTRY;
  
  TRY{
    log_debug("Test try_finaly try: %d", __COUNTER__);
  } CATCH( 1 ){
    assert(false);
  } CATCH( 2 ){
    assert(false);
  } CATCH_UNKNOWN {
    assert(false);
  } FINALLY {
    log_debug("Test try_finaly finaly: %d", __COUNTER__);
  } ENTRY;

  // test catch
  TRY{
    log_debug("Test try_catch try: %d", __COUNTER__);
    THROW( 2 );
    assert(false);
  } CATCH( 1 ){
    assert(false);
  } CATCH( 2 ){
    log_debug("Test try_catch catch: %d", __COUNTER__);
  } CATCH_UNKNOWN {
    log_err("Test try_catch SHOULD NOT HAPPEN!");
    assert(false);
  } ENDTRY;
  
  // test catch unknown
  TRY{
    log_debug("Test try_catch_unknown try: %d", __COUNTER__);
    THROW( 2 );
    assert(false);
  } CATCH( 1 ){
    assert(false);
  } CATCH_UNKNOWN {
    log_debug("Test try_catch catch_unknown: %d", __COUNTER__);
  } ENDTRY;
  
  log_debug("Test exit: %d", __COUNTER__);
  
  printf("Good Bye.\n");
  
  exit(EXIT_SUCCESS);
}
