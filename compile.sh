#/usr/bin/bash

cd /home/damo/Desktop/dance/Empathy
cmake .
make  && chmod +x empathy && LD_LIBRARY_PATH=/usr/lib64 ./empathy
