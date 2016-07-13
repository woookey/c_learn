#!/bin/bash

echo "Cleaning files..."
make clean

echo "Compiling..."
make ex10

echo "Running valgrind"
make val
