/*
 * customer_ticket.c
 *
 *  Created on: May 31, 2015
 *      Author: seongyong
 */

#include "customer_ticket.h"

Evas_Object* add_customer_ticket_view(Evas_Object *parent){
	Evas_Object *scroller,
				*grid,
				*bg,
				*label;

	customer_s *c_customer = calloc(1,sizeof(customer_s));

	strcpy(c_customer->customer_id,"customer_id");
	strcpy(c_customer->customer_name,"customer");
	strcpy(c_customer->ticket_number,"1234asdf");
	strcpy(c_customer->start_station,"Seoul");
	strcpy(c_customer->start_time,"2015.05.30 11:00");
	strcpy(c_customer->finish_station,"Busan");
	strcpy(c_customer->finish_time,"2015.05.30 14:00");

	scroller = elm_scroller_add(parent);
	elm_scroller_bounce_set(scroller, EINA_FALSE, EINA_TRUE);
	elm_scroller_policy_set(scroller, ELM_SCROLLER_POLICY_OFF, ELM_SCROLLER_POLICY_AUTO);

	grid = elm_grid_add(scroller);
 	evas_object_size_hint_weight_set(grid, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(grid, EVAS_HINT_FILL, EVAS_HINT_FILL);

	bg = elm_bg_add(grid);
	elm_win_resize_object_add(grid, bg);
	elm_object_content_set(grid, bg);
	elm_grid_pack(grid, bg, 1, 1, 98, 98);
	elm_bg_color_set(bg, 38, 116, 212);
	elm_bg_file_set(bg,ICON_DIR"/00_controlbar_icon_songs.png",NULL);
	evas_object_show(bg);

	label = elm_label_add(grid);
	elm_object_text_set(label, "NAME : ");
	evas_object_size_hint_weight_set(label, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_show(label);
	elm_grid_pack(grid, label, 10, 15, 20, 10);

	label = elm_label_add(grid);
	elm_object_text_set(label, c_customer->customer_name);
	evas_object_size_hint_weight_set(label, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_show(label);
	elm_grid_pack(grid, label, 35, 15, 50, 10);

	label = elm_label_add(grid);
	elm_object_text_set(label, "ID : ");
	evas_object_size_hint_weight_set(label, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_show(label);
	elm_grid_pack(grid, label, 10, 25, 20, 10);

	label = elm_label_add(grid);
	elm_object_text_set(label, c_customer->customer_id);
	evas_object_size_hint_weight_set(label, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_show(label);
	elm_grid_pack(grid, label, 35, 25, 50, 10);

	label = elm_label_add(grid);
	elm_object_text_set(label, "TICKET : ");
	evas_object_size_hint_weight_set(label, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_show(label);
	elm_grid_pack(grid, label, 10, 35, 20, 10);

	label = elm_label_add(grid);
	elm_object_text_set(label, c_customer->ticket_number);
	evas_object_size_hint_weight_set(label, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_show(label);
	elm_grid_pack(grid, label, 35, 35, 50, 10);

	label = elm_label_add(grid);
	elm_object_text_set(label, "START : ");
	evas_object_size_hint_weight_set(label, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_show(label);
	elm_grid_pack(grid, label, 10, 45, 20, 10);

	label = elm_label_add(grid);
	elm_object_text_set(label, c_customer->start_station);
	evas_object_size_hint_weight_set(label, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_show(label);
	elm_grid_pack(grid, label, 35, 45, 50, 10);

	label = elm_label_add(grid);
	elm_object_text_set(label, "  ");
	evas_object_size_hint_weight_set(label, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_show(label);
	elm_grid_pack(grid, label, 10, 55, 20, 10);

	label = elm_label_add(grid);
	elm_object_text_set(label, c_customer->start_time);
	evas_object_size_hint_weight_set(label, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_show(label);
	elm_grid_pack(grid, label, 35, 55, 50, 10);

	label = elm_label_add(grid);
	elm_object_text_set(label, "DEST : ");
	evas_object_size_hint_weight_set(label, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_show(label);
	elm_grid_pack(grid, label, 10, 65, 20, 10);

	label = elm_label_add(grid);
	elm_object_text_set(label, c_customer->finish_station);
	evas_object_size_hint_weight_set(label, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_show(label);
	elm_grid_pack(grid, label, 35, 65, 50, 10);

	label = elm_label_add(grid);
	elm_object_text_set(label, "  ");
	evas_object_size_hint_weight_set(label, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_show(label);
	elm_grid_pack(grid, label, 10, 75, 20, 10);

	label = elm_label_add(grid);
	elm_object_text_set(label, c_customer->finish_time);
	evas_object_size_hint_weight_set(label, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_show(label);
	elm_grid_pack(grid, label, 35, 75, 50, 10);


	elm_object_content_set(scroller, grid);

	return scroller;
}
