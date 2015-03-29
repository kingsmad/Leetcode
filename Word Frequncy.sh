#########################################################################
# File Name: Word Frequncy.sh
# Author: Archer
# mail: maple.km2041@me.com
# Created Time: Mon Mar 23 13:33:41 2015
#########################################################################
#!/bin/bash

echo $1

cat $1 | tr '\n' ' ' | sed "s/\s\s*/ /g" | awk -v RS=' ' '{print $0}' | sort | uniq -c | sort -nr -k1 | awk '{print $2 " " $1}'
