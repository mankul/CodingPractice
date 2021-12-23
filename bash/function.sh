#!/bin/bash
#defining a global variable
globalA="this is global variable"
function write {
	localA="this is local variable"
	echo $globalA
	echo $localA
}
echo $globalA
echo $localA
write
