#!/bin/bash
# Funcionamiento:
# nombreEjecutable numeroMIN numeroMAX numeroStep

min=$2
max=$(( 2**$3 ))

for (( i=$2; i<=$3; i+=1 )); do
	echo "[Fuerza Bruta] Progreso: $(( 2**$i)) [ $i / $3 ]"
	./matFB $(( 2**$i)) >> datosMatFB.dat	
done

for (( i=$2; i<=$3; i+=1 )); do
	echo "[DyV] Progreso: Progreso: $(( 2**$i)) [ $i / $3 ]"
	./matDyV $(( 2**$i)) >> datosMatDyV.dat	
done
