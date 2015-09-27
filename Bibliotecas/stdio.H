/*----------------------------------------------------------------------+
|									|
|  Copyright (1992) Bentley Systems, Inc., All rights reserved.		|
|									|
|  "MicroStation", "MDL", and "MicroCSL" are trademarks of Bentley	|
|  Systems, Inc.							|
|									|
|  Limited permission is hereby granted to reproduce and modify this	|
|  copyrighted material provided that the resulting code is used only 	|
|  in conjunction with Bentley Systems products under the terms of the	|
|  license agreement provided therein, and that this notice is retained	|
|  in its entirety in any such reproduction or modification.		|
|									|
+----------------------------------------------------------------------*/
/*----------------------------------------------------------------------+
|									|
|   Current Revision:							|
|   $Workfile:   stdio.h  $
|   $Revision:   6.0  $  $Date:   Thu Oct 21 10:19:22 1993  $
|									|
+----------------------------------------------------------------------*/
/*----------------------------------------------------------------------+
|									|
|   stdio.h -- MDL standard IO                  			|
|									|
|									|
+----------------------------------------------------------------------*/

#if !defined (mdl)
#error This file is intended for MDL only.
#endif
    
#if !defined (__stdioH__)
#   define __stdioH__
    
#if !defined (__VA_LIST_T)
#   define    __VA_LIST_T
typedef char	*__va_list;
#endif

#if !defined (__stddefH__)
#   include    <stddef.h>
#endif
    
#if !defined (__SIZE_T)
#    define __SIZE_T
     typedef unsigned int size_t;
#endif

#if !defined (__FPOS_T)
#    define __FPOS_T
     typedef unsigned int fpos_t;
#endif
    
#   include    <mdlio.h>

FILE	*__getStdin (void);
FILE	*__getStdout (void);
FILE	*__getStderr (void);
    
#   define  stdin (__getStdin())
#   define  stdout (__getStdout())
#   define  stderr (__getStderr())
    
int	 remove (char *);
    
/* unlink is a synonym for remove */    
int	 unlink (char *);
    
int	 rename (char *, char *);
FILE	*tmpfile (void);
char	*tmpnam (char *);
int	 fclose (FILE *);
int	 fflush (FILE *);
FILE	*fopen (char *, char *);
FILE	*freopen (char *, char *, FILE *);
void	 setbuf (FILE *, char *);
int	 setvbuf (FILE *, char *, int, size_t);
int	 fprintf (FILE *, char *, ...);
int	 fscanf (FILE *, char *,...);
int	 printf (char *,...);
int	 scanf (char *,...);
int	 sprintf (char *, char *,...);
int	 sscanf (char *, char *,...);
int	 vprintf (char *, __va_list);
int	 vfprintf (FILE *, char *, __va_list);
int	 vsprintf (char *, char *, __va_list);
int	 fgetc (FILE *);
char	*fgets (char *, int, FILE *);
int	 fputc (int, FILE *);
int	 fputs (char *, FILE *);
int	 getc (FILE *);
int	 getchar (void);
char	*gets (char *);
int	 putc (int, FILE *);
int	 putchar (int);
int	 puts (char *);
int	 ungetc (int, FILE *);
int	 fgetpos (FILE *, fpos_t *);
int	 fseek (FILE *, long int, int);
int	 fsetpos (FILE *, fpos_t *);
long	 ftell (FILE *);
void	 rewind (FILE *);
void	 clearerr (FILE *);
int	 feof (FILE *);
int	 ferror (FILE *);
    
size_t	 fread(void *, size_t, size_t, FILE *);
size_t   fwrite(void *, size_t, size_t, FILE *);
    
/*  perror prints to stderr which may not be displayed. Use of
    perror should be restricted to INITAPPS. */
void	 perror (char *);
    
#endif /*  !defined (__stdioH__) */
