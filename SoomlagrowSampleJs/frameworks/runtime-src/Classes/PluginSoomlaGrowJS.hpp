#ifndef __PluginSoomlaGrowJS_h__
#define __PluginSoomlaGrowJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginSoomlaGrow_class;
extern JSObject *jsb_sdkbox_PluginSoomlaGrow_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginSoomlaGrowJS_PluginSoomlaGrow(JSContext *cx, JS::HandleObject global);
void register_all_PluginSoomlaGrowJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginSoomlaGrowJS_PluginSoomlaGrow(JSContext *cx, JSObject* global);
void register_all_PluginSoomlaGrowJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginSoomlaGrowJS_PluginSoomlaGrow_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginSoomlaGrowJS_PluginSoomlaGrow_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSoomlaGrowJS_PluginSoomlaGrow_purchaseLikelihood(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginSoomlaGrowJS_PluginSoomlaGrow_purchaseLikelihood(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSoomlaGrowJS_PluginSoomlaGrow_refreshInsights(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginSoomlaGrowJS_PluginSoomlaGrow_refreshInsights(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSoomlaGrowJS_PluginSoomlaGrow_payRank(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginSoomlaGrowJS_PluginSoomlaGrow_payRank(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSoomlaGrowJS_PluginSoomlaGrow_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginSoomlaGrowJS_PluginSoomlaGrow_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

