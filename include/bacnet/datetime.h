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
#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <caribou/lib/stdint.h>

typedef enum BACnet_Weekday {
    BACNET_WEEKDAY_MONDAY = 1,
    BACNET_WEEKDAY_TUESDAY = 2,
    BACNET_WEEKDAY_WEDNESDAY = 3,
    BACNET_WEEKDAY_THURSDAY = 4,
    BACNET_WEEKDAY_FRIDAY = 5,
    BACNET_WEEKDAY_SATURDAY = 6,
    BACNET_WEEKDAY_SUNDAY = 7
} BACNET_WEEKDAY;

/* date */
typedef struct BACnet_Date {
    uint16_t year;      /* AD */
    uint8_t month;      /* 1=Jan */
    uint8_t day;        /* 1..31 */
    uint8_t wday;       /* 1=Monday-7=Sunday */
} BACNET_DATE;

/* time */
typedef struct BACnet_Time {
    uint8_t hour;
    uint8_t min;
    uint8_t sec;
    uint8_t hundredths;
} BACNET_TIME;

typedef struct BACnet_DateTime {
    BACNET_DATE date;
    BACNET_TIME time;
} BACNET_DATE_TIME;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

    /* utility initialization functions */
    void datetime_set_date(
        BACNET_DATE * bdate,
        uint16_t year,
        uint8_t month,
        uint8_t day);
    void datetime_set_time(
        BACNET_TIME * btime,
        uint8_t hour,
        uint8_t minute,
        uint8_t seconds,
        uint8_t hundredths);
    void datetime_set(
        BACNET_DATE_TIME * bdatetime,
        BACNET_DATE * bdate,
        BACNET_TIME * btime);
    void datetime_set_values(
        BACNET_DATE_TIME * bdatetime,
        uint16_t year,
        uint8_t month,
        uint8_t day,
        uint8_t hour,
        uint8_t minute,
        uint8_t seconds,
        uint8_t hundredths);
    /* utility test for validity */
    bool datetime_is_valid(
        BACNET_DATE * bdate,
        BACNET_TIME * btime);

    /* utility comparison functions:
       if the date/times are the same, return is 0
       if date1 is before date2, returns negative
       if date1 is after date2, returns positive */
    int datetime_compare_date(
        BACNET_DATE * date1,
        BACNET_DATE * date2);
    int datetime_compare_time(
        BACNET_TIME * time1,
        BACNET_TIME * time2);
    int datetime_compare(
        BACNET_DATE_TIME * datetime1,
        BACNET_DATE_TIME * datetime2);

    /* utility copy functions */
    void datetime_copy_date(
        BACNET_DATE * date1,
        BACNET_DATE * date2);
    void datetime_copy_time(
        BACNET_TIME * time1,
        BACNET_TIME * time2);
    void datetime_copy(
        BACNET_DATE_TIME * datetime1,
        BACNET_DATE_TIME * datetime2);

    /* utility add or subtract minutes function */
    void datetime_add_minutes(
        BACNET_DATE_TIME * bdatetime,
        int32_t minutes);

    /* date and time wildcards */
    bool datetime_wildcard(
        BACNET_DATE_TIME * bdatetime);
    bool datetime_wildcard_present(
        BACNET_DATE_TIME * bdatetime);
    void datetime_wildcard_set(
        BACNET_DATE_TIME * bdatetime);
    void datetime_date_wildcard_set(
        BACNET_DATE * bdate);
    void datetime_time_wildcard_set(
        BACNET_TIME * btime);

    int bacapp_encode_datetime(
        uint8_t * apdu,
        BACNET_DATE_TIME * value);

    int bacapp_encode_context_datetime(
        uint8_t * apdu,
        uint8_t tag_number,
        BACNET_DATE_TIME * value);

    int bacapp_decode_datetime(
        uint8_t * apdu,
        BACNET_DATE_TIME * value);

    int bacapp_decode_context_datetime(
        uint8_t * apdu,
        uint8_t tag_number,
        BACNET_DATE_TIME * value);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* DATE_TIME_H */
