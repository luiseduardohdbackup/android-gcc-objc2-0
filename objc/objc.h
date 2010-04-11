/*
 * Copyright (c) 1999-2007 Apple Inc.  All Rights Reserved.
 * 
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
/*
 *	objc.h
 *	Copyright 1988-1996, NeXT Software, Inc.
 */

#ifndef _OBJC_OBJC_H_
#define _OBJC_OBJC_H_

#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdarg.h>
#include <assert.h>
#include <ctype.h>
#include <objc/objc-api.h>


typedef struct objc_class *Class;
typedef struct objc_object {
    Class isa;
} *id;


typedef struct objc_selector 	*SEL;    
typedef id 			(*IMP)(id, SEL, ...); 
typedef signed char		BOOL; 
// BOOL is explicitly signed so @encode(BOOL) == "c" rather than "C" 
// even if -funsigned-char is used.
#define OBJC_BOOL_DEFINED

#define YES             (BOOL)1
#define NO              (BOOL)0


#ifndef Nil
#define Nil (Class)0
#endif

#ifndef nil
#define nil (id)0
#endif

OBJC_EXPORT const char *sel_getName(SEL sel);
OBJC_EXPORT SEL sel_registerName(const char *str);
OBJC_EXPORT const char *object_getClassName(id obj);
OBJC_EXPORT void *object_getIndexedIvars(id obj);

typedef BOOL (*objc_error_handler)(id, int code, const char *fmt, va_list ap);
extern objc_error_handler objc_set_error_handler(objc_error_handler func);

#endif
