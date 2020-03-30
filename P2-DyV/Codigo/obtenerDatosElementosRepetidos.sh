#!/bin/bash
# Funcionamiento:
# nombreEjecutable numeroMIN numeroMAX numeroStep


for (( i=$2; i<=$3; i+=$4 )); do
	echo "[Fuerza Bruta] Progreso: [ $i / $3 ]"
	./elementosFB $i >> datosRepetidosFB.dat	
done

for (( i=$2; i<=$3; i+=$4 )); do
	echo "[DyV] Progreso: Progreso: [ $i / $3 ]"
	./elementosDyV $i >> datosRepetidosDyV.dat	
done
