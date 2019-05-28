# README #

The source code was forked from **[UKnowMe/AC-Lua](https://github.com/UKnowMe/AC-Lua)**,:
This project aims to continue and update the AC-Lua mod for the AssaultCube gaming servers.


### Branches ###
+ Master branch contains AC-Lua server code using Lua 5.1.5
+ Headshot branch contains AC-Lua server code using Lua 5.1.5 and a headshot only patch
+ Testing branch contains AC-Lua server code using Lua 5.3.4


### Required Clients ###
+ **[AssaultCube](https://github.com/assaultcube/AC/releases/)**


### Dependencies ###

###### Windows
+ Windows 2000 or higher
+ 7zip from [7-zip.org](http://7-zip.org/)
+ **[Code::Blocks](http://www.codeblocks.org/)** (For compiling only!)

###### Linux
+ **[Linux Support](https://wiki.cubers.net/action/view/Linux_Support)**
+ Clang/LLVM
+ LuaJIT 5.1
+ Lua 5.1


### Build & Install ###

###### Windows
+ Windows users need to compile the server and server with mingw and codeblocks (see INSTALL.txt for details)

###### Linux
+ Linux users need to install dependencies by running ./install-dependencies.sh and compile the lua server by running ./build.sh
