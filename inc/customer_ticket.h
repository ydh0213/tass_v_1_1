/*
 * customer.h
 *
 *  Created on: May 30, 2015
 *      Author: seongyong
 */

#ifndef CUSTOMER_TICKET_H_
#define CUSTOMER_TICKET_H_

#include <app.h>
#include <Elementary.h>
#include <system_settings.h>
#include <efl_extension.h>
#include <dlog.h>
#include "tass.h"
#include "customer.h"

typedef struct customer {
	char customer_name[20];
	char customer_id[20];
	char ticket_number[20];
	char start_station[20];
	char start_time[20];
	char finish_station[20];
	char finish_time[20];
} customer_s;

Evas_Object* add_customer_ticket_view(Evas_Object *ad);

#endif /* CUSTOMER_H_ */
