/*			Generic Communication Code		HTTCP.c
**			==========================
**
**	This code is in common between client and server sides.
*/

#include "HTUtils.h"
#include "tcp.h"


/*	Module-Wide variables
*/

PRIVATE char *hostname=0;		/* The name of this host */


/*	PUBLIC VARIABLES
*/

PUBLIC struct sockaddr_in HTHostAddress;	/* The internet address of the host */
					/* Valid after call to HTHostName() */

/*	Encode INET status (as in sys/errno.h)			  inet_status()
**	------------------
**
** On entry,
**	where		gives a description of what caused the error
**	global errno	gives the error number in the unix way.
**
** On return,
**	returns		a negative status in the unix way.
*/
#ifdef vms
extern int uerrno;	/* Deposit of error info (as perr errno.h) */
extern int vmserrno;	/* Deposit of VMS error info */
extern volatile noshare int errno;  /* noshare to avoid PSECT conflict */
#else
#ifndef errno
extern int errno;
#endif
#endif

#ifndef vms
#ifndef NeXT
extern char *sys_errlist[];		/* see man perror on cernvax */
extern int sys_nerr;
#endif
#endif


/*	Report Internet Error
**	---------------------
*/
#ifdef __STDC__
PUBLIC int HTInetStatus(char *where)
#else
PUBLIC int HTInetStatus(where)
    char    *where;
#endif
{
    CTRACE(tfp, "TCP: Error %d in `errno' after call to %s() failed.\n\t%s\n",
	    errno,  where,
#ifdef vms
	    "(Error number not translated)");
#else
#ifdef NeXT
	    strerror(errno));
#else
	    errno < sys_nerr ? sys_errlist[errno] : "Unknown error" );
#endif
#endif

#ifdef vms
    CTRACE(tfp, "         Unix error number (uerrno) = %ld dec\n", uerrno);
    CTRACE(tfp, "         VMS error (vmserrno)       = %lx hex\n", vmserrno);
#endif
    return -errno;
}


/*	Parse a cardinal value				       parse_cardinal()
**	----------------------
**
** On entry,
**	*pp	    points to first character to be interpreted, terminated by
**		    non 0:9 character.
**	*pstatus    points to status already valid
**	maxvalue    gives the largest allowable value.
**
** On exit,
**	*pp	    points to first unread character
**	*pstatus    points to status updated iff bad
*/
#ifdef __STDC__
PUBLIC unsigned int HTCardinal(int *pstatus,
	char		**pp,
	unsigned int	max_value)
#else
PUBLIC unsigned int HTCardinal(pstatus, pp, max_value)
   int			*pstatus;
   char			**pp;
   unsigned int		max_value;
#endif
{
    int   n;
    if ( (**pp<'0') || (**pp>'9')) {	    /* Null string is error */
	*pstatus = -3;  /* No number where one expeceted */
	return 0;
    }

    n=0;
    while ((**pp>='0') && (**pp<='9')) n = n*10 + *((*pp)++) - '0';

    if (n>max_value) {
	*pstatus = -4;  /* Cardinal outside range */
	return 0;
    }

    return n;
}


/*	Produce a string for an inernet address
**	---------------------------------------
**
** On exit,
**	returns	a pointer to a static string which must be copied if
**		it is to be kept.
*/
#ifdef __STDC__
PUBLIC const char * HTInetString(struct sockaddr_in* sin)
#else
PUBLIC char * HTInetString(sin)
    struct sockaddr_in *sin;
#endif
{
    static char string[16];
    sprintf(string, "%d.%d.%d.%d",
	    (int)*((unsigned char *)(&HTHostAddress.sin_addr)+0),
	    (int)*((unsigned char *)(&HTHostAddress.sin_addr)+1),
	    (int)*((unsigned char *)(&HTHostAddress.sin_addr)+2),
	    (int)*((unsigned char *)(&HTHostAddress.sin_addr)+3));
    return string;
}


/*	Derive the name of the host on which we are
**	-------------------------------------------
**
*/
#ifdef __STDC__
PRIVATE void get_host_details(void)
#else
PRIVATE void get_host_details()
#endif

#ifndef MAXHOSTNAMELEN
#define MAXHOSTNAMELEN 64		/* Arbitrary limit */
#endif

{
    char name[MAXHOSTNAMELEN+1];	/* The name of this host */
    struct hostent * phost;		/* Pointer to host -- See netdb.h */
    int namelength = sizeof(name);
    
    if (hostname) return;		/* Already done */
    gethostname(name, namelength);	/* Without domain */
    CTRACE(tfp, "FTP: Local host name is `%s'\n", name);
    phost=gethostbyname(name);		/* See netdb.h */
    if (!phost) {
	if (TRACE) printf(
		"FTP: Can't find my own internet node address for `%s'!!\n",
		name);
	return;  /* Fail! */
    }
    StrAllocCopy(hostname, phost->h_name);
    memcpy(&HTHostAddress, &phost->h_addr, phost->h_length);
    if (TRACE) printf("     Name server says that is `%s' = %s\n",
	    hostname, HTInetString(&HTHostAddress));
}

#ifdef __STDC__
PUBLIC const char * HTHostName(void)
#else
PUBLIC char * HTHostName()
#endif
{
    get_host_details();
    return hostname;
}

