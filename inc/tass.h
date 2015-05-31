#ifndef __tass_H__
#define __tass_H__

#include <app.h>
#include <Elementary.h>
#include <system_settings.h>
#include <efl_extension.h>
#include <dlog.h>

#ifdef  LOG_TAG
#undef  LOG_TAG
#endif
#define LOG_TAG "tass"

#if !defined(PACKAGE)
#define PACKAGE "org.tizen.tass_v_1_1"
#endif

typedef struct appdata {
	Evas_Object *win;
	Evas_Object *conform;
	Evas_Object *label;
} appdata_s;

#define ICON_DIR "/opt/usr/apps/org.tizen.tass_v_1_1/res/"

#endif /* __tass_v_1_1_H__ */
