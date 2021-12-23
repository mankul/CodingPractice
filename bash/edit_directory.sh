#!/bin/bash
input_dir="./test"
of=write$(date +%y%m%d)".tz"
echo $input_dir
echo $of
tar -cvzf $of $input_dir
