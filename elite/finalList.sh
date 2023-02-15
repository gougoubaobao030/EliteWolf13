#!/bin/bash

for i in {0..20}
do
	mv "${i}n.png" "n${i}.png"
	sleep 1
done
