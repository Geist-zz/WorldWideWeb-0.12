/*	Macros for general use					HTUtils.h
*/
/*	Allocate a new copy of a string:
*/
#define StrAllocCopy(new,old) \
 if (new) free(new); (new) = (char *)malloc(strlen(old)+1); strcpy((new),(old))
/* extern void *malloc(size_t size); */

/*	Debug message control.
*/
#ifdef DEBUG
#define TRACE (WWW_TraceFlag)
#define PROGRESS(str) printf(str)
extern int WWW_TraceFlag;
#else
#define TRACE 0
#define PROGRESS(str) /* nothing for now */
#endif
#define CTRACE if(TRACE)fprintf
#define tfp stdout

/*	Standard C library for malloc() etc
*/
#ifdef vax
#ifdef unix
#define ultrix	/* Assume vax+unix=ultrix */
#endif
#endif

#ifndef VMS
#ifndef ultrix
#ifdef NeXT
#include <libc.h>	/* NeXT */
#endif
#include <stdlib.h>	/* ANSI */
#else
#include <malloc.h>	/* ultrix */
#include <memory.h>
#endif

#else				/* VMS */
#include <stdio.h>
#include <ctype.h>
#endif

#define PUBLIC			/* Accessible outside this module     */
#define PRIVATE static		/* Accessible only within this module */

#ifdef __STDC__
#define CONST const		/* "const" only exists in STDC */
#else
#define CONST
#endif

/* Note: GOOD and BAD are already defined (differently) on RS6000 aix */
/* #define GOOD(status) ((status)&1)	 VMS style status: test bit 0	      */
/* #define BAD(status)  (!GOOD(status))	 Bit 0 set if OK, otherwise clear   */

#ifndef BOOLEAN_DEFINED
typedef char	BOOLEAN;		/* Logical value */
#ifndef TRUE
#define TRUE	(BOOLEAN)1
#define	FALSE	(BOOLEAN)0
#endif
#define BOOLEAN_DEFINED
#endif

#ifndef BOOL
#define BOOL BOOLEAN
#endif
#ifndef YES
#define YES (BOOLEAN)1
#define NO (BOOLEAN)0
#endif

#define TCP_PORT 2784		/* Arbitrary value -- should be allocated */

/*	Is character c white space? */

#ifndef NOT_ASCII
#define WHITE(c) (((unsigned char)(c))<=' ')	/* Assumes ASCII but faster */
#else
#define WHITE(c) ( ((c)==' ') || ((c)=='\t') || ((c)=='\n') || ((c)=='\r') )
#endif

