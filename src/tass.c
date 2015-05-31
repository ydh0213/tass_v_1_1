#include <tizen.h>
#include <curl/curl.h>
#include "tass.h"
#include "customer.h"



static Elm_Entry_Filter_Limit_Size limit_size =
{
   .max_char_count = 16,
   .max_byte_count = 0
};

static Elm_Entry_Filter_Accept_Set accept_set =
{
   .accepted = NULL,
   .rejected = "</>"
};

static void
win_delete_request_cb(void *data, Evas_Object *obj, void *event_info)
{
	ui_app_exit();
}

static void
win_back_cb(void *data, Evas_Object *obj, void *event_info)
{
	appdata_s *ad = data;
	/* Let window go to hide state. */
	elm_win_lower(ad->win);
}

size_t writer(char *data, size_t size, size_t nmemb, char *writerData[255])   //WRITEFUNCTION 구현
{
   if (writerData == NULL)
      return 0;

   strcat(writerData,data);
   //writerData->   append(data, size*nmemb);   //지정된 string에 data를 덧붙인다.
   return size * nmemb;
}

static bool request_login(char* id, char* pass){

   CURL *curl;
   CURLcode res;
   char html[1000]={'0'};

   char* request[1000]={'0'};

   char* ptr;

   strcpy(request,"http://192.168.0.131:8080/TIZENSERVER/DbTestServlet?p=");
   strncat(request,id,strlen(id));
   strncat(request,"&&a=",strlen("&&a="));
   strncat(request,pass,strlen(pass));

   curl = curl_easy_init(); //easy handle을 생성

   dlog_print(DLOG_INFO, LOG_TAG, "test1" );

    dlog_print(DLOG_INFO, LOG_TAG, "%s",request );
    if(curl) {
    	curl_easy_setopt(curl, CURLOPT_URL, request);   //접속할 주소
    	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);         //redirect된 경우 경로를 따라 들어가도록 설정
    	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &html);         //여기 지정된 포인터를 WRITEFUNCTION에 넘겨준다.
    	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);      //writer함수 지정
    	res = curl_easy_perform(curl);      //수행

    	dlog_print(DLOG_INFO, LOG_TAG, "%s",html );

		ptr = strtok( html, "0");
		dlog_print(DLOG_INFO, LOG_TAG,  "%s\n", ptr);
		ptr = strtok( NULL, "0");

		dlog_print(DLOG_INFO, LOG_TAG, "함수 호출 후: %s\n", html);

	 	curl_easy_cleanup(curl);   //handle cleanup
   }


    return true;
}

static void clicked_login_btn_cb(void *data, Evas_Object *obj EINA_UNUSED, void *event_info EINA_UNUSED)
{
   appdata_s *ad = data;

   if(request_login("1","2")){
	   create_customer_view(ad);
   }
}

void create_login_view(appdata_s *ad){
	Evas_Object *conform = ad->conform;
	Evas_Object *grid, *bg, *label, *entry, *button;

	grid = elm_grid_add(conform);
	evas_object_size_hint_weight_set(grid, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(grid, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	elm_object_content_set(conform, grid);

	bg = elm_bg_add(grid);
	elm_win_resize_object_add(grid, bg);
	elm_grid_pack(grid, bg, 0, 0, 100, 100);
	elm_bg_color_set(bg, 38, 116, 212);
	evas_object_show(bg);

	bg = elm_bg_add(grid);
	elm_bg_color_set(bg, 38, 116, 212);
	elm_bg_file_set(bg,ICON_DIR"/train_icon0.png",NULL);
	elm_bg_option_set(bg,ELM_BG_OPTION_STRETCH);
	evas_object_show(bg);
	elm_grid_pack(grid, bg, 25, 10, 50, 30);

	label = elm_label_add(grid);
	elm_object_text_set(label,"ID : ");
	evas_object_size_hint_weight_set(label, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_show(label);
	elm_grid_pack(grid, label, 20, 50, 15, 10);

	label = elm_label_add(grid);
	elm_object_text_set(label,"PW :");
	evas_object_size_hint_weight_set(label, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_show(label);
	elm_grid_pack(grid, label, 20, 60, 15, 10);

	entry = elm_entry_add(grid);
	elm_entry_editable_set(entry, EINA_TRUE);
	elm_entry_entry_set(entry, "Input your ID here");
	evas_object_show(entry);
	elm_entry_single_line_set(entry, EINA_TRUE);
	elm_entry_markup_filter_append(entry, elm_entry_filter_limit_size, &limit_size);
	elm_grid_pack(grid, entry, 40, 48, 50, 10);
	evas_object_smart_callback_add(entry, "focused", NULL, entry);

	entry = elm_entry_add(grid);
	elm_entry_editable_set(entry, EINA_TRUE);
	elm_entry_entry_set(entry, "1111");
	evas_object_show(entry);
	elm_entry_single_line_set(entry, EINA_TRUE);
	elm_entry_markup_filter_append(entry, elm_entry_filter_limit_size, &limit_size);
	elm_grid_pack(grid, entry, 40, 58, 50, 10);
	evas_object_smart_callback_add(entry, "focused", NULL, entry);

	button = elm_button_add(grid);
	evas_object_size_hint_weight_set(button,EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(button,EVAS_HINT_FILL,EVAS_HINT_FILL);
	elm_object_text_set(button, "LOG IN");
	evas_object_smart_callback_add(button, "clicked", clicked_login_btn_cb, ad);
	evas_object_show(button);
	elm_grid_pack(grid, button, 30, 75, 40, 10);
}

static void
create_base_gui(appdata_s *ad)
{
	/* Window */
	ad->win = elm_win_util_standard_add(PACKAGE, PACKAGE);
	elm_win_autodel_set(ad->win, EINA_TRUE);

	evas_object_smart_callback_add(ad->win, "delete,request", win_delete_request_cb, NULL);
	eext_object_event_callback_add(ad->win, EEXT_CALLBACK_BACK, win_back_cb, ad);

	/* Conformant */
	ad->conform = elm_conformant_add(ad->win);
	elm_win_indicator_mode_set(ad->win, ELM_WIN_INDICATOR_SHOW);
	elm_win_indicator_opacity_set(ad->win, ELM_WIN_INDICATOR_OPAQUE);
	evas_object_size_hint_weight_set(ad->conform, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	elm_win_resize_object_add(ad->win, ad->conform);
	evas_object_show(ad->conform);

	create_login_view(ad);

	/* Show window after base gui is set up */
	evas_object_show(ad->win);
}

static bool
app_create(void *data)
{
	appdata_s *ad = data;

	create_base_gui(ad);

	return true;
}

static void
app_control(app_control_h app_control, void *data)
{
	/* Handle the launch request. */
}

static void
app_pause(void *data)
{
	/* Take necessary actions when application becomes invisible. */
}

static void
app_resume(void *data)
{
	/* Take necessary actions when application becomes visible. */
}

static void
app_terminate(void *data)
{
	/* Release all resources. */
}

static void
ui_app_lang_changed(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_LANGUAGE_CHANGED*/
	char *locale = NULL;
	system_settings_get_value_string(SYSTEM_SETTINGS_KEY_LOCALE_LANGUAGE, &locale);
	elm_language_set(locale);
	free(locale);
	return;
}

static void
ui_app_orient_changed(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_DEVICE_ORIENTATION_CHANGED*/
	return;
}

static void
ui_app_region_changed(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_REGION_FORMAT_CHANGED*/
}

static void
ui_app_low_battery(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_LOW_BATTERY*/
}

static void
ui_app_low_memory(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_LOW_MEMORY*/
}

int
main(int argc, char *argv[])
{
	appdata_s ad = {0,};
	int ret = 0;

	ui_app_lifecycle_callback_s event_callback = {0,};
	app_event_handler_h handlers[5] = {NULL, };

	event_callback.create = app_create;
	event_callback.terminate = app_terminate;
	event_callback.pause = app_pause;
	event_callback.resume = app_resume;
	event_callback.app_control = app_control;

	ui_app_add_event_handler(&handlers[APP_EVENT_LOW_BATTERY], APP_EVENT_LOW_BATTERY, ui_app_low_battery, &ad);
	ui_app_add_event_handler(&handlers[APP_EVENT_LOW_MEMORY], APP_EVENT_LOW_MEMORY, ui_app_low_memory, &ad);
	ui_app_add_event_handler(&handlers[APP_EVENT_DEVICE_ORIENTATION_CHANGED], APP_EVENT_DEVICE_ORIENTATION_CHANGED, ui_app_orient_changed, &ad);
	ui_app_add_event_handler(&handlers[APP_EVENT_LANGUAGE_CHANGED], APP_EVENT_LANGUAGE_CHANGED, ui_app_lang_changed, &ad);
	ui_app_add_event_handler(&handlers[APP_EVENT_REGION_FORMAT_CHANGED], APP_EVENT_REGION_FORMAT_CHANGED, ui_app_region_changed, &ad);
	ui_app_remove_event_handler(handlers[APP_EVENT_LOW_MEMORY]);

	ret = ui_app_main(argc, argv, &event_callback, &ad);
	if (ret != APP_ERROR_NONE) {
		dlog_print(DLOG_ERROR, LOG_TAG, "app_main() is failed. err = %d", ret);
	}

	return ret;
}
