#include "PluginSoomlaGrowLua.hpp"
#include "PluginSoomlaGrow/PluginSoomlaGrow.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"



int lua_PluginSoomlaGrowLua_PluginSoomlaGrow_purchaseLikelihood(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSoomlaGrow",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginSoomlaGrow::EDayQuarter arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginSoomlaGrow:purchaseLikelihood");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSoomlaGrowLua_PluginSoomlaGrow_purchaseLikelihood'", nullptr);
            return 0;
        }
        double ret = sdkbox::PluginSoomlaGrow::purchaseLikelihood(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSoomlaGrow:purchaseLikelihood",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSoomlaGrowLua_PluginSoomlaGrow_purchaseLikelihood'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSoomlaGrowLua_PluginSoomlaGrow_refreshInsights(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSoomlaGrow",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSoomlaGrowLua_PluginSoomlaGrow_refreshInsights'", nullptr);
            return 0;
        }
        sdkbox::PluginSoomlaGrow::refreshInsights();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSoomlaGrow:refreshInsights",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSoomlaGrowLua_PluginSoomlaGrow_refreshInsights'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSoomlaGrowLua_PluginSoomlaGrow_payRank(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSoomlaGrow",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        sdkbox::PluginSoomlaGrow::EGenre arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "sdkbox.PluginSoomlaGrow:payRank");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSoomlaGrowLua_PluginSoomlaGrow_payRank'", nullptr);
            return 0;
        }
        int ret = sdkbox::PluginSoomlaGrow::payRank(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSoomlaGrow:payRank",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSoomlaGrowLua_PluginSoomlaGrow_payRank'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginSoomlaGrowLua_PluginSoomlaGrow_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginSoomlaGrow",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginSoomlaGrowLua_PluginSoomlaGrow_init'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginSoomlaGrow::init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginSoomlaGrow:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginSoomlaGrowLua_PluginSoomlaGrow_init'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginSoomlaGrowLua_PluginSoomlaGrow_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginSoomlaGrow)");
    return 0;
}

int lua_register_PluginSoomlaGrowLua_PluginSoomlaGrow(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginSoomlaGrow");
    tolua_cclass(tolua_S,"PluginSoomlaGrow","sdkbox.PluginSoomlaGrow","",nullptr);

    tolua_beginmodule(tolua_S,"PluginSoomlaGrow");
        tolua_function(tolua_S,"purchaseLikelihood", lua_PluginSoomlaGrowLua_PluginSoomlaGrow_purchaseLikelihood);
        tolua_function(tolua_S,"refreshInsights", lua_PluginSoomlaGrowLua_PluginSoomlaGrow_refreshInsights);
        tolua_function(tolua_S,"payRank", lua_PluginSoomlaGrowLua_PluginSoomlaGrow_payRank);
        tolua_function(tolua_S,"init", lua_PluginSoomlaGrowLua_PluginSoomlaGrow_init);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginSoomlaGrow).name();
    g_luaType[typeName] = "sdkbox.PluginSoomlaGrow";
    g_typeCast["PluginSoomlaGrow"] = "sdkbox.PluginSoomlaGrow";
    return 1;
}
TOLUA_API int register_all_PluginSoomlaGrowLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginSoomlaGrowLua_PluginSoomlaGrow(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

