/***********************************************************************
* pc_api_internal.h
*
*  Signatures we need to share within the library, but not for 
*  use outside it.
*
* Portions Copyright (c) 2012, OpenGeo
*
***********************************************************************/

#ifndef _PC_API_INTERNAL_H
#define _PC_API_INTERNAL_H

#include "pc_api.h"

/**
* Utility defines
*/
#define PC_TRUE 1
#define PC_FALSE 0
#define PC_SUCCESS 1
#define PC_FAILURE 0

/**
* How many compression types do we support?
*/
#define PCCOMPRESSIONTYPES 2

#define PCPATCH_DEFAULT_MAXPOINTS 64

/**
* Interpretation types for our dimension descriptions
*/
#define NUM_INTERPRETATIONS 11

enum INTERPRETATIONS
{
	PC_UNKNOWN = 0,
	PC_INT8   = 1,  PC_UINT8  = 2,
	PC_INT16  = 3,  PC_UINT16 = 4,
	PC_INT32  = 5,  PC_UINT32 = 6,
	PC_INT64  = 7,  PC_UINT64 = 8,
	PC_DOUBLE = 9,  PC_FLOAT  = 10
};

static char *INTERPRETATION_STRINGS[NUM_INTERPRETATIONS] =
{
	"unknown",
	"int8_t",  "uint8_t",
	"int16_t", "uint16_t",
	"int32_t", "uint32_t",
	"int64_t", "uint64_t",
	"double",  "float"
};

static size_t INTERPRETATION_SIZES[NUM_INTERPRETATIONS] =
{
	-1,    /* PC_UNKNOWN */
	1, 1,  /* PC_INT8, PC_UINT8, */
	2, 2,  /* PC_INT16, PC_UINT16 */
	4, 4,  /* PC_INT32, PC_UINT32 */
	8, 8,  /* PC_INT64, PC_UINT64 */
	8, 4   /* PC_DOUBLE, PC_FLOAT */
};

/** Read interpretation type from buffer and cast to double */
double pc_double_from_ptr(const uint8_t *ptr, uint32_t interpretation);

/** Write value to buffer in the interpretation type */
int pc_double_to_ptr(uint8_t *ptr, uint32_t interpretation, double val);

/** Return number of bytes in a given interpretation */
size_t pc_interpretation_size(uint32_t interp);

/** True if there is a dimension of that name */
int pc_schema_has_name(const PCSCHEMA *s, const char *name);

/** Copy a string within the global memory management context */
char* pcstrdup(const char *str);


#endif /* _PC_API_INTERNAL_H */