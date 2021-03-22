#!/bin/bash -i
rm a.out
#source ~/.bashrc
for filename in $(find . -type f -name "*.x.cpp"); do
d $filename
./a.out > /dev/null
if [ $? = 0 ]; then
  echo "$filename passed"
else
  echo "$filename failed"
fi
done
