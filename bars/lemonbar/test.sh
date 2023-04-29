#!/bin/sh

# Define the clock
Clock() {
        DATETIME=$(date "+%a %b %d, %T")

        printf "$DATETIME"
}

# Print the clock

while true; do
        echo "%{c}%{F#FFFF00}%{B#0000FF} %{A:st -e nvim:}$(Clock)%{A} %{F-}%{B-} "

        sleep 1
done



