#!/bin/bash

echo "Cleaning..."
make clean

echo "Compiling..."
make ex15

echo "Testing..."
make val
