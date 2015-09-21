#include "PluginSoomlaGrowJS.hpp"
#include "cocos2d_specifics.hpp"
#include "PluginSoomlaGrow/PluginSoomlaGrow.h"
#include "SDKBoxJSHelper.h"

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

        JS::RootedObject proto(cx, typeClass->proto.get());
        JS::RootedObject parent(cx, typeClass->parentProto.get());
        JS::RootedObject _tmp(cx, JS_NewObject(cx, typeClass->jsclass, proto, parent));
        
        T* cobj = new T();
        js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
        AddObjectRoot(cx, &pp->obj);
        args.rval().set(OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    args.rval().setBoolean(true);
    return true;    
}
#else
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

        JSObject *_tmp = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
        T* cobj = new T();
        js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
        JS_AddObjectRoot(cx, &pp->obj);
        JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, JS::HandleObject obj, JS::HandleId id, JS::MutableHandleValue vp)
{
    vp.set(BOOLEAN_TO_JSVAL(true));
    return true;    
}
#endif
#elif defined(JS_VERSION)
template<class T>
static JSBool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    TypeTest<T> t;
    T* cobj = new T();
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    assert(p);
    JSObject *_tmp = JS_NewObject(cx, p->jsclass, p->proto, p->parentProto);
    js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));

    return JS_TRUE;
}

static JSBool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return JS_FALSE;
}
#endif
JSClass  *jsb_sdkbox_PluginSoomlaGrow_class;
JSObject *jsb_sdkbox_PluginSoomlaGrow_prototype;

#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSoomlaGrowJS_PluginSoomlaGrow_purchaseLikelihood(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginSoomlaGrow::EDayQuarter arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginSoomlaGrowJS_PluginSoomlaGrow_purchaseLikelihood : Error processing arguments");
        double ret = sdkbox::PluginSoomlaGrow::purchaseLikelihood(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginSoomlaGrowJS_PluginSoomlaGrow_purchaseLikelihood : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSoomlaGrowJS_PluginSoomlaGrow_purchaseLikelihood(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginSoomlaGrow::EDayQuarter arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        double ret = sdkbox::PluginSoomlaGrow::purchaseLikelihood(arg0);
        jsval jsret;
        jsret = DOUBLE_TO_JSVAL(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSoomlaGrowJS_PluginSoomlaGrow_refreshInsights(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginSoomlaGrow::refreshInsights();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginSoomlaGrowJS_PluginSoomlaGrow_refreshInsights : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSoomlaGrowJS_PluginSoomlaGrow_refreshInsights(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginSoomlaGrow::refreshInsights();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSoomlaGrowJS_PluginSoomlaGrow_payRank(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        sdkbox::PluginSoomlaGrow::EGenre arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginSoomlaGrowJS_PluginSoomlaGrow_payRank : Error processing arguments");
        int ret = sdkbox::PluginSoomlaGrow::payRank(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginSoomlaGrowJS_PluginSoomlaGrow_payRank : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSoomlaGrowJS_PluginSoomlaGrow_payRank(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        sdkbox::PluginSoomlaGrow::EGenre arg0;
        ok &= jsval_to_int32(cx, argv[0], (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        int ret = sdkbox::PluginSoomlaGrow::payRank(arg0);
        jsval jsret;
        jsret = int32_to_jsval(cx, ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginSoomlaGrowJS_PluginSoomlaGrow_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::PluginSoomlaGrow::init();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginSoomlaGrowJS_PluginSoomlaGrow_init : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginSoomlaGrowJS_PluginSoomlaGrow_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::PluginSoomlaGrow::init();
        jsval jsret;
        jsret = BOOLEAN_TO_JSVAL(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif


void js_PluginSoomlaGrowJS_PluginSoomlaGrow_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (PluginSoomlaGrow)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    jsproxy = jsb_get_js_proxy(obj);
    if (jsproxy) {
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        sdkbox::PluginSoomlaGrow *nobj = static_cast<sdkbox::PluginSoomlaGrow *>(nproxy->ptr);
        if (nobj)
            delete nobj;
        
        jsb_remove_proxy(nproxy, jsproxy);
    }
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginSoomlaGrowJS_PluginSoomlaGrow(JSContext *cx, JS::HandleObject global) {
    jsb_sdkbox_PluginSoomlaGrow_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginSoomlaGrow_class->name = "PluginSoomlaGrow";
    jsb_sdkbox_PluginSoomlaGrow_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSoomlaGrow_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginSoomlaGrow_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSoomlaGrow_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginSoomlaGrow_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginSoomlaGrow_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginSoomlaGrow_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginSoomlaGrow_class->finalize = js_PluginSoomlaGrowJS_PluginSoomlaGrow_finalize;
    jsb_sdkbox_PluginSoomlaGrow_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("purchaseLikelihood", js_PluginSoomlaGrowJS_PluginSoomlaGrow_purchaseLikelihood, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("refreshInsights", js_PluginSoomlaGrowJS_PluginSoomlaGrow_refreshInsights, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("payRank", js_PluginSoomlaGrowJS_PluginSoomlaGrow_payRank, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginSoomlaGrowJS_PluginSoomlaGrow_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginSoomlaGrow_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_sdkbox_PluginSoomlaGrow_class,
        dummy_constructor<sdkbox::PluginSoomlaGrow>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "PluginSoomlaGrow", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginSoomlaGrow> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginSoomlaGrow_class;
        p->proto = jsb_sdkbox_PluginSoomlaGrow_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#else
void js_register_PluginSoomlaGrowJS_PluginSoomlaGrow(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginSoomlaGrow_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginSoomlaGrow_class->name = "PluginSoomlaGrow";
    jsb_sdkbox_PluginSoomlaGrow_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSoomlaGrow_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginSoomlaGrow_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSoomlaGrow_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginSoomlaGrow_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginSoomlaGrow_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginSoomlaGrow_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginSoomlaGrow_class->finalize = js_PluginSoomlaGrowJS_PluginSoomlaGrow_finalize;
    jsb_sdkbox_PluginSoomlaGrow_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        {"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
        {0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("purchaseLikelihood", js_PluginSoomlaGrowJS_PluginSoomlaGrow_purchaseLikelihood, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("refreshInsights", js_PluginSoomlaGrowJS_PluginSoomlaGrow_refreshInsights, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("payRank", js_PluginSoomlaGrowJS_PluginSoomlaGrow_payRank, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginSoomlaGrowJS_PluginSoomlaGrow_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginSoomlaGrow_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginSoomlaGrow_class,
        dummy_constructor<sdkbox::PluginSoomlaGrow>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "PluginSoomlaGrow", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginSoomlaGrow> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginSoomlaGrow_class;
        p->proto = jsb_sdkbox_PluginSoomlaGrow_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#endif
#elif defined(JS_VERSION)
void js_register_PluginSoomlaGrowJS_PluginSoomlaGrow(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginSoomlaGrow_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginSoomlaGrow_class->name = "PluginSoomlaGrow";
    jsb_sdkbox_PluginSoomlaGrow_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSoomlaGrow_class->delProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSoomlaGrow_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginSoomlaGrow_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginSoomlaGrow_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginSoomlaGrow_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginSoomlaGrow_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginSoomlaGrow_class->finalize = js_PluginSoomlaGrowJS_PluginSoomlaGrow_finalize;
    jsb_sdkbox_PluginSoomlaGrow_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    JSPropertySpec *properties = NULL;

    JSFunctionSpec *funcs = NULL;

    static JSFunctionSpec st_funcs[] = {
        JS_FN("purchaseLikelihood", js_PluginSoomlaGrowJS_PluginSoomlaGrow_purchaseLikelihood, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("refreshInsights", js_PluginSoomlaGrowJS_PluginSoomlaGrow_refreshInsights, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("payRank", js_PluginSoomlaGrowJS_PluginSoomlaGrow_payRank, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginSoomlaGrowJS_PluginSoomlaGrow_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginSoomlaGrow_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginSoomlaGrow_class,
        dummy_constructor<sdkbox::PluginSoomlaGrow>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
    JSBool found;
    JS_SetPropertyAttributes(cx, global, "PluginSoomlaGrow", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginSoomlaGrow> t;
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    if (!p) {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->type = typeId;
        p->jsclass = jsb_sdkbox_PluginSoomlaGrow_class;
        p->proto = jsb_sdkbox_PluginSoomlaGrow_prototype;
        p->parentProto = NULL;
        HASH_ADD_INT(_js_global_type_ht, type, p);
    }
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginSoomlaGrowJS(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "sdkbox", &ns);

    js_register_PluginSoomlaGrowJS_PluginSoomlaGrow(cx, ns);
}
#else
void register_all_PluginSoomlaGrowJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    JS::RootedValue nsval(cx);
    JS::RootedObject ns(cx);
    JS_GetProperty(cx, obj, "sdkbox", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkbox", nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginSoomlaGrowJS_PluginSoomlaGrow(cx, obj);
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginSoomlaGrowJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    jsval nsval;
    JSObject *ns;
    JS_GetProperty(cx, obj, "sdkbox", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkbox", &nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginSoomlaGrowJS_PluginSoomlaGrow(cx, obj);
}
#endif