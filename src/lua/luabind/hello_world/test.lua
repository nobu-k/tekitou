#!/usr/bin/lua

-- need "./"
package.loadlib("./hello_world.so", "init")()

greet()