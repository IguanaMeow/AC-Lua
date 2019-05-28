#ifndef __LUA_H__
#define __LUA_H__

extern "C"
{
	#include "../lua/src/lua.h"
}

#define LUA_SCRIPTS_PATH "lua/scripts/"
#define LUA_INCLUDES_PATH "lua/include/"

#include "lua_handlers.h"
#include "lua_generators.h"
#include "lua_tmr_library.h"
#include "lua_cfg_library.h"

#define LUA_FUNCTION_PREFIX( prefix, function ) int prefix##function( lua_State *L )
#define LUA_FUNCTION( function ) LUA_FUNCTION_PREFIX( __, function )


struct LuaArg;

class Lua
{
public:

	static const double version; // Lua mod version

	static void initialize( const char *scriptsPath );
	static void destroy();

	// Full group of methods designed to embed Lua mod's API into a Lua script.
	// {
	static void registerGlobals( lua_State *L ); // constants and functions
	static void openExtraLibs( lua_State *L );
	// }

	static int callHandler( const char *handler, const char *arguments, ... );
	static int callHandler( const char *handler, int argc, const LuaArg *args );

	// "Fake" here means that a Lua script is able to substitute the value of a server variable
	// with its own value whenever the variable is going to be read by the server.
	// To get a fake value from a Lua script, Lua mod calls needed function (whose name is predetermined by Lua mod's API) in the script.
	static void* getFakeVariable( const char *generator, int *numberOfReturns, int luaTypeReturned, const char* arguments, ... );
	static void* getFakeVariable( const char *generator, int *numberOfReturns, int luaTypeReturned, int argc, const LuaArg *args );

	static const int PLUGIN_BLOCK = 4; // "4" has been there throughout whole life of Lua mod

	static int numberOfScripts;
	static lua_State **scripts;
};

struct LuaArg
{
	char type;
	int count, origin; // only used if (type == 'o')

	union
	{
		int i;
		const char *ccp;
		bool b;
		double d;
		lua_State *lsp;
		bool *bp;
		int luatbl;
	};
};

#endif
