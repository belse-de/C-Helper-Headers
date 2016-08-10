/*
 * try_catch.h
 *
 *  Created on: 01.12.2012
 *      Author: Sebastian Schrod
 *      E-Mail:	sebastian<dot>schrod<at>belse<dot>de
 *      Web:	www<dot>belse<dot>de
 *
 *  This Module provides you with basic error handling via try catch finaly.
 *  A little bit like c++.
 *
 *  HISTORY Duff's Device
 *  http://www.lysator.liu.se/c/duffs-device.html
 *
 *      Copyright (c) 2012, Sebastian Schrod
 *		All rights reserved.
 */

/* --- for Copy and Paste --- */
/*
#include "belse/try_catch.h"
TRY{
} CATCH( 1 ){
} CATCH( 2 ){
} FINALLY {
} ENTRY;

TRY{
} CATCH( 1 ){
} CATCH( 2 ){
} ENDTRY;
*/
#pragma once
#ifndef BELSE_TRY_CATCH_H
#define BELSE_TRY_CATCH_H

#ifdef __cplusplus
		#error "Do not use belse_try_catch with C++, because try/catch is native there!"
#else

#include <setjmp.h>

#ifndef BELSE_TRY_CATCH_VERSION
    #define BELSE_TRY_CATCH_VERSION 3
#endif
    
#if BELSE_TRY_CATCH_VERSION == 3 //not tested
    #define THROW_IF(x, err) if((x)){THROW((err));}
    #define THROW(x) longjmp(ex_buf__, x)
    #define TRY do{ jmp_buf ex_buf__; switch( setjmp(ex_buf__) ){ case 0: while(1){
    #define CATCH_UNKNOWN break; default:
    #define CATCH(x) break; case x:
    #define ENDTRY FINALLY ENTRY
    #define FINALLY break; }
    #define ENTRY } }while(0)
    
#elif BELSE_TRY_CATCH_VERSION == 2 //not tested
    #define THROW_IF(x, err) if(x){THROW(err);}
    #define THROW(err) longjmp(ex_buf__, err)
    #define TRY do{ jmp_buf ex_buf__; switch( setjmp(ex_buf__) ){ case 0: while(1){
    #define CATCH(x) break; case x:
    #define ENDTRY FINALLY ENTRY
    #define FINALLY break; } default:
    #define ENTRY } }while(0)
    
#elif BELSE_TRY_CATCH_VERSION == 1 //tested
    #define THROW_IF(x, err) if(x){THROW(err);}
    #define THROW(x) longjmp(ex_buf__, x)
    #define TRY do{ jmp_buf ex_buf__; switch( setjmp(ex_buf__) ){ case 0: while(1){
    #define CATCH(x) break; case x:
    #define FINALLY break; } default:
    #define ENTRY } }while(0)
    
#endif /*--- BELSE_TRY_CATCH_VERSION ---*/
#endif /*--- __cplusplus ---*/
#endif /*--- BELSE_TRY_CATCH_H ---*/


