/* 
   COPYRIGHT 
*/

/**
 * @file proj_data.h
 * This public header contains generic data type used by implementations.
 */

#ifndef HEADER_PROJ_DATA_H
#define HEADER_PROJ_DATA_H

#ifdef  __cplusplus
extern "C" {
#endif

/*  */
typedef struct _proj_data_st
  {
    int type;
    union
    {
      /* General data declaration */
      int int_d;
      int *int_p;
      int **int_pp;

      unsigned int uint_d;
      unsigned int *uint_p;
      unsigned int **uint_pp;

      char char_d;
      char *char_p;
      char **char_pp;

      unsigned char uchar_d;
      unsigned char *uchar_p;
      unsigned char **uchar_pp;

      OBJ *generic_p;
    }d;
    
}PROJ_DATA;

#ifdef  __cplusplus
}
#endif
#endif  /* HEADER_PROJ_DATA_H */
