#!/bin/bash
declare -i last_num
touch file
trap 'rm -f file.lock' EXIT

while true
do
  if ln file file.lock 2> /dev/null; then
    last_num=$(tail -n 1 file)
    echo $(((last_num+1))) >> file;
    rm -f file.lock;
  fi
done
