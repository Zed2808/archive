#!/bin/bash
# A gauge box example with dialog

(
c=10
while [ $c -ne 110 ]
	do
		echo $c
		echo "###"
		echo "$c %"
		echo "###"
		((c+=10))
		sleep 1
done
) |
dialog --title "A test gauge with dialog" --gauge "Please wait..." 6 60 0
