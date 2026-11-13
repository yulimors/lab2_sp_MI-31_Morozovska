#!/bin/bash

if [ -z "$2" ]; then
    echo "Використання: ./energy_creative.sh <TDP_у_Ватах> <програма>"
    echo "Наприклад, ./energy_creative.sh 45 ./dot_O0"
    exit 1
fi

TDP=$1
shift
PROG=$@

START=$(date +%s.%N)

$PROG > /dev/null

END=$(date +%s.%N)

TIME_DIFF=$(echo "$END - $START" | bc)
ENERGY=$(echo "$TDP * $TIME_DIFF" | bc)

echo "звіт енерговитрат"
echo "Програма $PROG"
echo "TDP Процесора (Системи) $TDP Ват"
echo "Час виконання (t) $TIME_DIFF секунд"
echo "Витрачена енергія (E = P * t): $ENERGY Джоулів"
