/* 
   COPYRIGHT 
*/

/**
 * @file __proj_plat.h
 * This file contains the platform specific macro to abstruct
 * memory allocation. 
 */

#ifndef HEADER___PROJ_PLAT_H
#define HEADER___PROJ_PLAT_H

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
#endif  /* HEADER___PROJ_PLAT_H */
