#!/bin/bash
echo gcc defines:
gcc -dM -E - < /dev/null

#echo ------------------------
#echo g++ defines:
#g++ -dM -E -x c++ - < /dev/null
