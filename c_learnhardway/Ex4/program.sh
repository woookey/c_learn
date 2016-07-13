#!/bin/bash

echo "Cleaning files..."
make clean

echo "Compiling..."
make ex4

echo "Running valgrind"
make val
