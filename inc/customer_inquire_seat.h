/*
 * customer_inquire_seat.h
 *
 *  Created on: May 31, 2015
 *      Author: seongyong
 */

#ifndef CUSTOMER_INQUIRE_SEAT_H_
#define CUSTOMER_INQUIRE_SEAT_H_

#include <app.h>
#include <Elementary.h>
#include <system_settings.h>
#include <efl_extension.h>
#include <dlog.h>
#include <curl/curl.h>
#include "tass.h"
#include "customer.h"

typedef struct train_seat {
	char train_number[20];
	char section_number;
	int seat_number;
	bool seat_empty[100];
} train_seat_s;

Evas_Object* add_customer_inquire_seat_view(Evas_Object *parent);

#endif /* CUSTOMER_INQUIRE_SEAT_H_ */
