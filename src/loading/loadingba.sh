#!/usr/bin/bash

while true
do
	for i in "[*    ]" "[ *   ]" "[  *  ]" "[   * ]" "[    *]" "[   * ]" "[  *  ]" "[ *   ]"
	do
		printf "\rLoading... %s" "$i"
		sleep 0.3
	done
done
