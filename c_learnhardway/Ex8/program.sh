#!/bin/bash

echo "Cleaning files..."
make clean

echo "Compiling..."
make ex8

echo "Running valgrind"
make val
