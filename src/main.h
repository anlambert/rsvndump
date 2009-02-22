/*
 *      rsvndump - remote svn repository dump
 *      Copyright (C) 2008-2009 Jonas Gehring
 *
 *      This program is free software: you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation, either version 3 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * 	
 *      file: main.h
 *      desc: Common definitions and types
 */


#ifndef MAIN_H
#define MAIN_H


/* Application-specific constants */
#ifndef HAVE_CONFIG_H
 #define APPNAME "rsvndump"
 #define APPVERSION "0.4.4"
 #define APPAUTHOR "Jonas Gehring <jonas.gehring@boolsoft.org>"
#else
 #include "config.h"
 #define APPNAME PACKAGE
 #define APPVERSION PACKAGE_VERSION
 #define APPAUTHOR "Jonas Gehring <"PACKAGE_BUGREPORT">"

 /* Compability functions */
 #ifndef HAVE_MEMSET
  extern void *memset(void *str, int c, size_t len);
 #endif
 #ifndef HAVE_STRDUP
  extern char *strdup(const char *s);
 #endif 
 #ifndef HAVE_GETPASS
  extern char *getpass(const char *prompt);
 #endif
 #ifndef HAVE_RMDIR
  extern int rmdir(char const *dir);
 #endif
 #ifndef HAVE_STRNLEN
  extern size_t strnlen(const char *string, size_t maxlen);
 #endif
#endif


/* Helper definitions */
#define PROPS_END "PROPS-END\n"
#define PROPS_END_LEN (sizeof(PROPS_END))


/* Other features, some used for debugging */
#if defined(USE_TIMING) && !defined(HAVE_GETTIMEOFDAY)
 #undef USE_TIMING
#endif
/* This is _not_ implemented, but enables flags and options for deltas */
/*#define USE_DELTAS*/


#endif
