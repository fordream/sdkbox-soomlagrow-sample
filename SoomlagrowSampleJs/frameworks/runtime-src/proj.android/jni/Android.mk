LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2djs_shared

LOCAL_MODULE_FILENAME := libcocos2djs

LOCAL_SRC_FILES := hellojavascript/main.cpp ../../Classes/AppDelegate.cpp ../../Classes/PluginIAPJS.cpp ../../Classes/PluginIAPJSHelper.cpp ../../Classes/SDKBoxJSHelper.cpp ../../Classes/PluginFacebookJS.cpp ../../Classes/PluginFacebookJS.hpp ../../Classes/PluginFacebookJSHelper.cpp ../../Classes/PluginFacebookJSHelper.h ../../Classes/SDKBoxJSHelper.h ../../Classes/PluginSoomlaGrowJS.cpp ../../Classes/PluginSoomlaGrowJSHelper.cpp

LOCAL_LDLIBS := -landroid -llog
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
LOCAL_WHOLE_STATIC_LIBRARIES := PluginIAP sdkbox android_native_app_glue PluginFacebook PluginSoomlaGrow

LOCAL_STATIC_LIBRARIES := cocos2d_js_static

LOCAL_EXPORT_CFLAGS := -DCOCOS2D_DEBUG=2 -DCOCOS2D_JAVASCRIPT

include $(BUILD_SHARED_LIBRARY)
$(call import-add-path, $(LOCAL_PATH))


$(call import-module, scripting/js-bindings/proj.android)
$(call import-module, ./sdkbox)
$(call import-module, ./pluginiap)
$(call import-module, ./pluginfacebook)
$(call import-module, ./pluginsoomlagrow)
