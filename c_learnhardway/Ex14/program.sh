#!/bin/bash

echo "Cleaning..."
make clean

echo "Compiling..."
make ex14

echo "Testing..."
make val
