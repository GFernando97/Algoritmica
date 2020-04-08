#ALGORITMICA
#	PRACTICA 2
#	Makefile para automatizar la práctica.
#		Uso:
#		- Escribir make para compilar el código, es igual que 'make code'
#		- 'make datos' obtiene los datos, 'make graficas' obtiene las graficas, 'make ajuste' el ajuste y 'make all' todo lo anterior.

#Nombre de Ejecutables
EXE=Codigo/matrizTraspuestaDyV  Codigo/matrizTraspuestaDyV_O2 Codigo/matrizTraspuestaFB Codigo/matrizTraspuestaFB_O2 Codigo/ElementosRepetidosDyV Codigo/ElementosRepetidosFB Codigo/ElementosRepetidosDef
#Codigo/matrizTraspuestaDef

#Nombre de los datos
DAT=Datos/matrizTraspuestaDyV.dat Datos/matrizTraspuestaFB.dat Datos/ElementosRepetidosDyV.dat Datos/ElementosRepetidosFB.dat Datos/ElementosRepetidosDef.dat #Datos/matrizTraspuestaDef.dat

#Graficas de los algoritmos
GRAF=Graficas/matrizTraspuestaFBvsDyV.png Graficas/ElementosRepetidosFBvsDyV.png Graficas/ElementosRepetidosDef.png #Graficas/matrizTraspuestaDef.png

#Graficas de ajuste
GRAFAJ=Graficas/matrizTraspuestaDyVAjuste.png Graficas/matrizTraspuestaFB.png Graficas/ElementosRepetidosFBAjuste.png Graficas/ElementosRepetidosDyVAjuste.png

#Tamaños de casos
matIni=1
matFin=14
repetIni=2500
repetFin=25000
repetStep=500

#INICIO
code : $(EXE)

datos : $(DAT)

graficas : $(GRAF)

graficaMatriz: Graficas/matrizTraspuestaFBvsDyV.png 

ajuste : $(GRAFAJ)

all: $(EXE) $(DAT) $(GRAF) $(GRAFAJ)

# Compilar
Codigo/matrizTraspuestaDyV : Codigo/matrizTraspuestaDyV.cpp
	g++ -o Codigo/matrizTraspuestaDyV Codigo/matrizTraspuestaDyV.cpp

Codigo/matrizTraspuestaDyV_O2 : Codigo/matrizTraspuestaDyV.cpp
	g++ -O2 -o Codigo/matrizTraspuestaDyV_O2 Codigo/matrizTraspuestaDyV.cpp

Codigo/matrizTraspuestaFB : Codigo/matrizTraspuestaFB.cpp
	g++ Codigo/matrizTraspuestaFB.cpp -o Codigo/matrizTraspuestaFB

Codigo/matrizTraspuestaDef : Codigo/matrizTraspuestaDef.cpp
	g++ Codigo/matrizTraspuestaDef.cpp -o Codigo/matrizTraspuestaDef

Codigo/matrizTraspuestaFB_O2 : Codigo/matrizTraspuestaFB.cpp
	g++ Codigo/matrizTraspuestaFB.cpp -O2 -o Codigo/matrizTraspuestaFB_O2

matrizTraspuestaDef : Codigo/matrizTraspuestaDef.cpp
	g++ Codigo/matrizTraspuestaDef.cpp -o Codigo/matrizTraspuestaDef

Codigo/ElementosRepetidosDyV : Codigo/ElementosRepetidosDyV.cpp
	g++ Codigo/ElementosRepetidosDyV.cpp -o Codigo/ElementosRepetidosDyV

Codigo/ElementosRepetidosFB : Codigo/ElementosRepetidosFB.cpp
	g++ Codigo/ElementosRepetidosFB.cpp -o Codigo/ElementosRepetidosFB

Codigo/ElementosRepetidosDef : Codigo/ElementosRepetidosDef.cpp
	g++ Codigo/ElementosRepetidosDef.cpp -o Codigo/ElementosRepetidosDef

# Datos

Datos/matrizTraspuestaDyV.dat : Codigo/matrizTraspuestaDyV
	bash datosMatrizTranspuesta.sh matrizTraspuestaDyV $(matIni) $(matFin)

Datos/matrizTraspuestaDyV_O2.dat : Codigo/matrizTraspuestaDyV_O2
	bash datosMatrizTranspuesta.sh matrizTraspuestaDyV_O2 $(matIni) $(matFin)

Datos/matrizTraspuestaFB.dat : Codigo/matrizTraspuestaFB
	bash datosMatrizTranspuesta.sh matrizTraspuestaFB $(matIni) $(matFin)

Datos/matrizTraspuestaFB_O2.dat : Codigo/matrizTraspuestaFB_O2
	bash datosMatrizTranspuesta.sh matrizTraspuestaFB_O2 $(matIni) $(matFin)


Datos/ElementosRepetidosDyV.dat : Codigo/ElementosRepetidosDyV
	taskset --cpu-list 0 bash datosElementosRepetidos.sh ElementosRepetidosDyV $(repetIni) $(repetFin) $(repetStep)

Datos/ElementosRepetidosFB.dat : Codigo/ElementosRepetidosFB
	taskset --cpu-list 0 bash datosElementosRepetidos.sh ElementosRepetidosFB $(repetIni) $(repetFin) $(repetStep)

Datos/ElementosRepetidosDef.dat : Codigo/ElementosRepetidosDef
	taskset --cpu-list 0 bash datosElementosRepetidos.sh ElementosRepetidosDef $(repetIni) $(repetFin) $(repetStep)


# Graficas

Graficas/matrizTraspuestaFBvsDyV.png : Datos/matrizTraspuestaDyV.dat Datos/matrizTraspuestaFB.dat
	gnuplot Gnuplot/matrizTraspuestaFBvsDyV.gpi




Graficas/matrizTraspuestaFBvsDyV_O2.png : Datos/matrizTraspuestaDyV_O2.dat Datos/matrizTraspuestaFB_O2.dat
	gnuplot Gnuplot/matrizTraspuestaFBvsDyV_O2.gpi

Graficas/ElementosRepetidosFBvsDyV.png : Datos/ElementosRepetidosDyV.dat Datos/ElementosRepetidosFB.dat
	gnuplot Gnuplot/ElementosRepetidosFBvsDyV.gpi

Graficas/ElementosRepetidosDef.png : Datos/ElementosRepetidosDef.dat Datos/ElementosRepetidosFB.dat
	gnuplot Gnuplot/ElementosRepetidosDef.gpi

# Graficas Ajuste

Graficas/matrizTraspuestaDyVAjuste.png : Gnuplot/matrizTraspuestaDyVAjuste.gpi  Datos/matrizTraspuestaDyV.dat
	gnuplot Gnuplot/matrizTraspuestaDyVAjuste.gpi

Graficas/matrizTraspuestaDyV_O2Ajuste.png : Gnuplot/matrizTraspuestaDyV_O2Ajuste.gpi  Datos/matrizTraspuestaDyV_O2.dat
	gnuplot Gnuplot/matrizTraspuestaDyV_O2Ajuste.gpi 

Graficas/matrizTraspuestaFB_O2Ajuste.png : Gnuplot/matrizTraspuestaFB_O2Ajuste.gpi  Datos/matrizTraspuestaFB_O2.dat
	gnuplot Gnuplot/matrizTraspuestaFB_O2Ajuste.gpi 

Graficas/matrizTraspuestaFBAjuste.png : Gnuplot/matrizTraspuestaFBAjuste.gpi  Datos/matrizTraspuestaFB.dat
	gnuplot Gnuplot/matrizTraspuestaFBAjuste.gpi 

Graficas/ElementosRepetidosDyVAjuste.png : Gnuplot/ElementosRepetidosDyVAjuste.gpi  Datos/ElementosRepetidosDyV.dat
	gnuplot Gnuplot/ElementosRepetidosDyVAjuste.gpi 

Graficas/ElementosRepetidosFBAjuste.png : Gnuplot/ElementosRepetidosFBAjuste.gpi  Datos/ElementosRepetidosFB.dat
	gnuplot Gnuplot/ElementosRepetidosFBAjuste.gpi 

# Cleaners

cleanCode :
	rm $(EXE)

cleanDatos :
	rm $(DAT)

cleanGraficas :
	rm $(GRAF)

cleanAll :
	rm $(EXE) $(DAT) $(GRAF) $(GRAFAJ) fit.log


