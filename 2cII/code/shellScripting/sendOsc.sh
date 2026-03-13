#!/usr/bin/env bash

export PATH="/opt/homebrew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin"

HOST="127.0.0.1"
PORT="7777"
PATHOSC="/parameter"

value=50

while true; do
    clear
    echo "OSC Slider (← → change, q quit)"
    echo

    printf "["
    for ((i=0;i<100;i++)); do
        if [ $i -lt $value ]; then printf "="; else printf " "; fi
    done
    printf "] %d\n" "$value"

    read -rsn1 key

    case "$key" in
        q) exit ;;
        $'\x1b')
            read -rsn2 key
            case "$key" in
                "[C") ((value++)) ;;
                "[D") ((value--)) ;;
            esac
        ;;
    esac

    ((value<0)) && value=0
    ((value>100)) && value=100

    float=$(awk "BEGIN {printf \"%.3f\", $value/100}")
    oscsend $HOST $PORT $PATHOSC f $float
done
