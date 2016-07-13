#!/bin/bash

echo "Cleaning files..."
make clean

echo "Compiling..."
make ex5

echo "Running valgrind"
make val
