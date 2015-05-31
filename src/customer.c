/*
 * customer.c
 *
 *  Created on: May 30, 2015
 *      Author: seongyong
 */

#include <tizen.h>
#include "customer.h"

static Evas_Object*
create_toolbar_more_btn(Evas_Object *parent, Evas_Smart_Cb func, void *data)
{
	Evas_Object *btn = elm_button_add(parent);
	if (btn == NULL) return NULL;
	elm_object_style_set(btn, "naviframe/more/default");
	evas_object_smart_callback_add(btn, "clicked", func, data);
	return btn;
}

static Evas_Object*
create_nocontent(Evas_Object *parent, const char *text)
{
	Evas_Object *layout, *scroller;

	/* Scroller */
	scroller = elm_scroller_add(parent);
	elm_scroller_bounce_set(scroller, EINA_FALSE, EINA_TRUE);
	elm_scroller_policy_set(scroller, ELM_SCROLLER_POLICY_OFF, ELM_SCROLLER_POLICY_AUTO);

	/* NoContent Layout */
	layout = elm_layout_add(scroller);
	elm_layout_theme_set(layout, "layout", "nocontents", "default");
	evas_object_size_hint_weight_set(layout, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(layout, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_part_text_set(layout, "elm.text", text);

	elm_object_content_set(scroller, layout);

	return scroller;
}

static void
toolbar_select_cb(void *data, Evas_Object *obj, void *event_info)
{
	Evas_Object *nf = data;
	Evas_Object *tab_view;
	Elm_Object_Item *tab_it, *nf_it;
	const char *str;
	char buf[128];

	tab_it = elm_toolbar_selected_item_get(obj);
	if (tab_it) {
		str = elm_object_item_text_get(tab_it);
		snprintf(buf, sizeof(buf),"%s", str);
	}

	tab_view = create_nocontent(nf, buf);

	nf_it = elm_naviframe_top_item_get(nf);
	elm_object_item_part_content_set(nf_it, NULL, tab_view);
}

static void
toolbar_select_customer_ticket_cb(void *data, Evas_Object *obj, void *event_info)
{
	Evas_Object *nf = data;
	Evas_Object *tab_view;
	Elm_Object_Item *nf_it;

	tab_view = add_customer_ticket_view(nf);

	nf_it = elm_naviframe_top_item_get(nf);
	elm_object_item_part_content_set(nf_it, NULL, tab_view);
}


static Evas_Object*
create_customer_tabbar(Evas_Object *parent, const char *style)
{
	Evas_Object *toolbar;

	/* Create Tabbar */
	toolbar = elm_toolbar_add(parent);
	if (style) {
		elm_object_style_set(toolbar, style);
	}
	elm_toolbar_shrink_mode_set(toolbar, ELM_TOOLBAR_SHRINK_EXPAND);
	elm_toolbar_transverse_expanded_set(toolbar, EINA_TRUE);

	elm_toolbar_item_append(toolbar, ICON_DIR"/00_controlbar_icon_artists.png", "좌석조회", toolbar_select_cb, parent);
	elm_toolbar_item_append(toolbar, ICON_DIR"/00_controlbar_icon_artists.png", "전자표", toolbar_select_customer_ticket_cb, parent);
	elm_toolbar_item_append(toolbar, ICON_DIR"/00_controlbar_icon_artists.png", "서비스", toolbar_select_cb, parent);
	elm_toolbar_item_append(toolbar, ICON_DIR"/00_controlbar_icon_artists.png", "", toolbar_select_cb, parent);
	elm_toolbar_select_mode_set(toolbar, ELM_OBJECT_SELECT_MODE_ALWAYS);

	return toolbar;
}

void create_customer_view(appdata_s *ad){
	Evas_Object *conform = ad->conform;
	Evas_Object *layout, *navi,*content, *tabbar, *content_layout;
	Elm_Object_Item *nf_it;

	layout = elm_layout_add(conform);
	evas_object_size_hint_weight_set(layout, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	elm_layout_theme_set(layout, "layout", "application", "default");
	evas_object_show(layout);

	elm_object_content_set(conform, layout);

	navi = elm_naviframe_add(layout);

	content = elm_scroller_add(navi);
	elm_scroller_bounce_set(content,EINA_FALSE, EINA_TRUE);
	elm_scroller_policy_set(content,ELM_SCROLLER_POLICY_OFF,ELM_SCROLLER_POLICY_AUTO);

	content_layout = elm_layout_add(content);
	elm_layout_theme_set(content_layout,"layout","application","default");
	evas_object_size_hint_weight_set(content_layout, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(content_layout, EVAS_HINT_FILL, EVAS_HINT_FILL);
	elm_object_part_text_set(content_layout, "elm.text", "tass");

	elm_object_content_set(content, content_layout);

	nf_it = elm_naviframe_item_push(navi,NULL,NULL,NULL,content, "tabbar/icon/notitle");

	tabbar = create_customer_tabbar(navi, "tabbar");
	elm_object_item_part_content_set(nf_it, "tabbar", tabbar);

	elm_object_part_content_set(layout, "elm.swallow.content", navi);
}
