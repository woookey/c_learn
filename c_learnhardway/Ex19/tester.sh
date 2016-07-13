#!/bin/bash

ch_n="n"
ch_s="s"
ch_e="e"
ch_w="w"
ch_a="a"

echo "Test 1..."
echo $ch_n $ch_s $ch_s | ./ex19
echo
echo "Test 2..."
echo $ch_n $ch_n $ch_e | ./ex19
echo
echo "Test 3..."
echo $ch_n $ch_e $ch_a | ./ex19
echo
echo "Test 4..."
echo $ch_n $ch_w $ch_a | ./ex19
echo
echo "Test 5..."
echo $ch_w $ch_e $ch_s | ./ex19
