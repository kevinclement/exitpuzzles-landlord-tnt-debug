#!/bin/sh
pio run --target upload --upload-port /dev/ttyTNT

# Send 'mon' to program to get it to monitor after it uploads
if [ $? -eq 0 ] && [ "$1" = "mon" ]
then
 pio device monitor -b 9600 -p /dev/ttyTNT
fi


