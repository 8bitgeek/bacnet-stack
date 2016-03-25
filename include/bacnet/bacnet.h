/**************************************************************************
*
* Copyright (C) 2012 Steve Karg <skarg@users.sourceforge.net>
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*********************************************************************/
#ifndef BACNET_H
#define BACNET_H

/** @file bacnet.h  This file is designed to reference the entire BACnet stack library */

/* core files */
#include <bacnet/version.h>
#include <bacnet/config.h>
#include <bacnet/address.h>
#include <bacnet/apdu.h>
#include <bacnet/bacapp.h>
#include <bacnet/bacdcode.h>
#include <bacnet/bacint.h>
#include <bacnet/bacreal.h>
#include <bacnet/bacstr.h>
#include <bacnet/bacdef.h>
#include <bacnet/bacenum.h>
#include <bacnet/bacerror.h>
#include <bacnet/bactext.h>
#include <bacnet/datalink.h>
#include <bacnet/indtext.h>
#include <bacnet/npdu.h>
#include <bacnet/reject.h>
#include <bacnet/tsm.h>

/* services */
#include <bacnet/arf.h>
#include <bacnet/awf.h>
#include <bacnet/cov.h>
#include <bacnet/dcc.h>
#include <bacnet/iam.h>
#include <bacnet/ihave.h>
#include <bacnet/rd.h>
#include <bacnet/rp.h>
#include <bacnet/rpm.h>
#include <bacnet/timesync.h>
#include <bacnet/whohas.h>
#include <bacnet/whois.h>
#include <bacnet/wp.h>
#include <bacnet/event.h>
#include <bacnet/lso.h>
#include <bacnet/alarm_ack.h>

/* required object - note: developer must supply the device.c file
   since it is not included in the library.  However, the library
   references the device.c members via the device.h API. */
#include <device.h>

/* demo objects */
#include <ai.h>
#include <ao.h>
#include <av.h>
#include <bacfile.h>
#include <bi.h>
#include <bo.h>
#include <bv.h>
#include <lc.h>
#include <lsp.h>
#include <mso.h>

/* demo handlers */
#include <txbuf.h>
#include <client.h>
#include <handlers.h>

/* Additions for Doxygen documenting */
/**
 * @mainpage BACnet-stack API Documentation
 * This documents the BACnet-Stack API, OS ports, and sample applications. <br>
 *
 *  - The high-level handler interface can be found in the Modules tab.
 *  - Specifics for each file can be found in the Files tab.
 *  - A full list of all functions is provided in the index of the
 *  Files->Globals subtab.
 *
 * While all the central files are included in the file list, not all important
 * functions have been given the javadoc treatment, nor have Modules (chapters)
 * been created yet for all groupings.  If you are doing work in an under-
 * documented area, please add the javadoc comments at least to the API calls,
 * and consider adding doxygen's module grouping for your area of interest.
 *
 * See doc/README.doxygen for notes on building and extending this document. <br>
 * In particular, if you have graphviz installed, you can enhance this
 * documentation by turning on the function call graphs feature.
 */
#endif
