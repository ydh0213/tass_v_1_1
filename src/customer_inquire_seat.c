/*
 * customer_inquire_seat.c
 *
 *  Created on: May 31, 2015
 *      Author: seongyong
 */

#include <stdio.h>
#include <stdlib.h>
#include "customer_inquire_seat.h"

Evas_Object* add_customer_inquire_seat_view(Evas_Object *parent){
	Evas_Object *scroller,
				*grid,
				*bg,
				*layout,
				*label,
				*seat_layout,
				*map;

	train_seat_s *seat_s = calloc(1,sizeof(train_seat_s));

	int i;

	strcpy(seat_s->train_number,"A0001");
	seat_s->section_number = 'A';
	seat_s->seat_number = 40;

	for(i = 0 ; i < seat_s->seat_number; i++){
		seat_s->seat_empty[i] = true;
	}

	scroller = elm_scroller_add(parent);
	elm_scroller_bounce_set(scroller, EINA_FALSE, EINA_TRUE);
	elm_scroller_policy_set(scroller, ELM_SCROLLER_POLICY_OFF, ELM_SCROLLER_POLICY_AUTO);

	grid = elm_grid_add(scroller);
	evas_object_size_hint_weight_set(grid, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(grid, EVAS_HINT_FILL, EVAS_HINT_FILL);

	bg = elm_bg_add(grid);
	elm_win_resize_object_add(grid, bg);
	elm_object_content_set(grid, bg);
	elm_grid_pack(grid, bg, 0, 0, 100, 100);
	elm_bg_color_set(bg, 38, 116, 212);
	evas_object_show(bg);

	bg = elm_bg_add(grid);
	elm_object_content_set(grid, bg);
	elm_grid_pack(grid, bg, 5, 5, 10, 10);
	elm_bg_color_set(bg, 255, 255, 255);
	evas_object_show(bg);

	label = elm_label_add(grid);
	elm_object_text_set(label,seat_s->train_number);
	evas_object_size_hint_weight_set(label, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_show(label);
	elm_grid_pack(grid, label, 5, 5, 10, 10);



//	map = elm_map_add(grid);
//	elm_map_zoom_mode_set(map,ELM_MAP_ZOOM_MODE_MANUAL);
//	elm_map_zoom_set(map,12);
//	elm_map_region_bring_in(map,37.2,127.8);
//	elm_grid_pack(grid,map,5,5,90,90);
//	evas_object_show(map);
//


//	table = elm_table_add(grid);
//	elm_table_padding_set(table,12,5);



	elm_object_content_set(scroller, grid);

	return scroller;

}
