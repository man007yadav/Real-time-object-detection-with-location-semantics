#!/bin/bash
# My first script
if [ $1 == 1 ]
then 
  ./darknet detect cfg/yolo.cfg yolo.weights data/$2 &
elif [ $1 == 2 ]
then 
 ./darknet detector demo cfg/coco.data cfg/yolo.cfg yolo.weights 
else
   ./darknet detector demo cfg/coco.data cfg/yolo.cfg yolo.weights $2
fi

rm feedback.txt
sleep 5
/home/my007/Documents/Seminar/darknet/myProg
exit

