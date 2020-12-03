#!/usr/bin/env bash

if [ "$1" == "-f" ]; then
    force=1
    shift
fi


day=$1
shift

advent_domain=https://adventofcode.com
input_url=${advent_domain}/2020/day/${day}/input
input=.input${day}

test -f ${input} ||
    curl --no-progress-meter -b "session=$(<.session)" \
         -o ${input} "${input_url}"

output=.output${day}
if [ -n "$force" ] || [ ! -f "${output}" ]; then
    ./day${day} < ${input} > ${output}
fi

cat ${output}
