#!/bin/bash

#Caminho do interpretador Python
#Recomendado ter python3
PYTHON_PATH=`which python`
PYTHON3_PATH=`which python3`

#Recomentado ter o pip
PIP_PATH=`which pip`
#Executa em python
#$PYTHON_PATH solver.py

$PIP_PATH install matplotlib
#Executa o python3
$PYTHON3_PATH solver.py
