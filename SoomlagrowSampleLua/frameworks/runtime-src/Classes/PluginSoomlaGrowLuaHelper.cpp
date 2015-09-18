
#include "PluginSoomlaGrowLuaHelper.h"
#include "PluginSoomlaGrow/PluginSoomlaGrow.h"
#include "CCLuaEngine.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"

class SoomlaGrowListenerLua : public sdkbox::SoomlaGrowListener {
public:
	SoomlaGrowListenerLua(): mLuaHandler(0) {

	}
	~SoomlaGrowListenerLua() {
		resetHandler();
	}

	void setHandler(int luaHandler) {
		if (mLuaHandler == luaHandler) {
			return;
		}
		resetHandler();
		mLuaHandler = luaHandler;
	}

	void resetHandler() {
		if (0 == mLuaHandler) {
			return;
		}

        LUAENGINE->removeScriptHandler(mLuaHandler);
		mLuaHandler = 0;
	}

    void onGrowInitialized() {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("event", LuaValue::stringValue("onGrowInitialized")));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onGrowConnected() {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("event", LuaValue::stringValue("onGrowConnected")));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onGrowDisconnected() {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("event", LuaValue::stringValue("onGrowDisconnected")));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onGrowInsightsInitialized()
    {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("event", LuaValue::stringValue("onGrowInsightsInitialized")));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onInsightsRefreshFailed()
    {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("event", LuaValue::stringValue("onInsightsRefreshFailed")));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onInsightsRefreshFinished()
    {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("event", LuaValue::stringValue("onInsightsRefreshFinished")));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

    void onInsightsRefreshStarted()
    {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("event", LuaValue::stringValue("onInsightsRefreshStarted")));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }

private:
	int mLuaHandler;
};

int lua_PluginSoomlaGrowLua_PluginSoomlaGrow_setListener(lua_State* tolua_S) {
	int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSoomlaGrow",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S, 2 , "LUA_FUNCTION",0,&tolua_err))
        {
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
        SoomlaGrowListenerLua* lis = static_cast<SoomlaGrowListenerLua*> (sdkbox::PluginSoomlaGrow::getListener());
        if (nullptr == lis) {
        	lis = new SoomlaGrowListenerLua();
        }
        lis->setHandler(handler);
        sdkbox::PluginSoomlaGrow::setListener(lis);

        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSoomlaGrow::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSoomlaGrowLua_PluginSoomlaGrow_setListener'.",&tolua_err);
#endif
    return 0;
}



int extern_PluginSoomlaGrow(lua_State* L) {
	if (nullptr == L) {
		return 0;
	}

	lua_pushstring(L, "sdkbox.PluginSoomlaGrow");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"setListener", lua_PluginSoomlaGrowLua_PluginSoomlaGrow_setListener);
    }
     lua_pop(L, 1);

    return 1;
}

TOLUA_API int register_all_PluginSoomlaGrowLua_helper(lua_State* L) {
	tolua_module(L,"sdkbox",0);
	tolua_beginmodule(L,"sdkbox");

	extern_PluginSoomlaGrow(L);

	tolua_endmodule(L);
	return 1;
}


