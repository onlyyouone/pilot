/* 
   COPYRIGHT 
*/

/**
 * @file proj_plat.h
 * This file contains the platform specific header.
 * This is where system header should be defined. Other header/source should not
 * include system header. 
 */

#ifndef HEADER_PROJ_PLAT_H
#define HEADER_PROJ_PLAT_H

#ifdef  __cplusplus
extern "C" {
#endif

#ifdef WINDOWS
  #include <windows.h>
#endif  

#include <stdlib.h>
#include <string.h>
  
/* More stuff to be in here.  */
  
#ifdef  __cplusplus
}
#endif
#endif  /* HEADER_PROJ_PLAT_H */
