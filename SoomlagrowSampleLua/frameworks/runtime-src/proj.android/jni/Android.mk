LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dlua_shared

LOCAL_MODULE_FILENAME := libcocos2dlua

LOCAL_SRC_FILES := ../../Classes/AppDelegate.cpp ../../Classes/ide-support/SimpleConfigParser.cpp ../../Classes/ide-support/RuntimeLuaImpl.cpp ../../Classes/ide-support/lua_debugger.c hellolua/main.cpp ../../Classes/PluginIAPLua.cpp ../../Classes/PluginIAPLuaHelper.cpp ../../Classes/SDKBoxLuaHelper.cpp ../../Classes/PluginFacebookLua.hpp ../../Classes/PluginFacebookLua.cpp ../../Classes/PluginFacebookLuaHelper.cpp ../../Classes/PluginFacebookLuaHelper.h ../../Classes/SDKBoxLuaHelper.h ../../Classes/PluginSoomlaGrowLua.cpp ../../Classes/PluginSoomlaGrowLuaHelper.cpp

LOCAL_LDLIBS := -landroid -llog
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
LOCAL_WHOLE_STATIC_LIBRARIES := PluginIAP sdkbox android_native_app_glue PluginFacebook PluginSoomlaGrow

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END

LOCAL_STATIC_LIBRARIES := cocos2d_lua_static
LOCAL_STATIC_LIBRARIES += cocos2d_simulator_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)
$(call import-add-path, $(LOCAL_PATH))

$(call import-module,scripting/lua-bindings/proj.android)
$(call import-module,tools/simulator/libsimulator/proj.android)
$(call import-module, ./sdkbox)
$(call import-module, ./pluginiap)
$(call import-module, ./pluginfacebook)
$(call import-module, ./pluginsoomlagrow)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
