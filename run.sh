#!/bin/bash

# Load conda from the correct installation path
source /opt/anaconda3/etc/profile.d/conda.sh

# Activate the environment
conda activate compbot

# Build and run
make
./compbot
