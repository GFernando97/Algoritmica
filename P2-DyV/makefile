#ALGORITMICA
#	PRACTICA 2
#	Makefile para automatizar la práctica.
#		Uso:
#		- Escribir make para compilar el código, es igual que 'make code'
#		- 'make datos' obtiene los datos, 'make graficas' obtiene las graficas, 'make ajuste' el ajuste y 'make all' todo lo anterior.

#Nombre de Ejecutables
EXE=Codigo/matrizTraspuestaDyV Codigo/matrizTraspuestaFB Codigo/ElementosRepetidosDyV Codigo/ElementosRepetidosFB Codigo/ElementosRepetidosDef
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
repetIni=1000
repetFin=50000
repetStep=1000

#INICIO
code : $(EXE)

datos : $(DAT)

graficas : $(GRAF)

graficaMatriz: Graficas/matrizTraspuestaFBvsDyV.png 

ajuste : $(GRAFAJ)

all: $(EXE) $(DAT) $(GRAF) $(GRAFAJ)


matrizTraspuestaDyV : Codigo/matrizTraspuestaDyV.cpp
	g++ -o Codigo/matrizTraspuestaDyV Codigo/matrizTraspuestaDyV.cpp

matrizTraspuestaDyV_O2 : Codigo/matrizTraspuestaDyV.cpp
	g++ -O2 -o Codigo/matrizTraspuestaDyV_O2 Codigo/matrizTraspuestaDyV.cpp

matrizTraspuestaFB : Codigo/matrizTraspuestaFB.cpp
	g++ Codigo/matrizTraspuestaFB.cpp -o Codigo/matrizTraspuestaFB

matrizTraspuestaFB_O2 : Codigo/matrizTraspuestaFB.cpp
	g++ Codigo/matrizTraspuestaFB.cpp -O2 -o Codigo/matrizTraspuestaFB_O2

#matrizTraspuestaDef : Codigo/matrizTraspuestaDef.cpp
#	g++ Codigo/matrizTraspuestaDef.cpp -o Codigo/matrizTraspuestaDef

ElementosRepetidosDyV : Codigo/ElementosRepetidosDyV.cpp
	g++ Codigo/ElementosRepetidosDyV.cpp -o Codigo/ElementosRepetidosDyV

ElementosRepetidosFB : Codigo/ElementosRepetidosFB.cpp
	g++ Codigo/ElementosRepetidosFB.cpp -o Codigo/ElementosRepetidosFB

ElementosRepetidosDef : Codigo/ElementosRepetidosDef.cpp
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

#matrizTraspuestaDef.dat : matrizTraspuestaDef
#	bash datosMatrizTranspuesta.sh matrizTraspuestaDef $(matIni) $(matFin)

Datos/ElementosRepetidosDyV.dat : Codigo/ElementosRepetidosDyV
	bash datosElementosRepetidos.sh ElementosRepetidosDyV $(repetIni) $(repetFin) $(repetStep)

Datos/ElementosRepetidosFB.dat : Codigo/ElementosRepetidosFB
	bash datosElementosRepetidos.sh ElementosRepetidosFB $(repetIni) $(repetFin) $(repetStep)

Datos/ElementosRepetidosDef.dat : Codigo/ElementosRepetidosDef
	bash datosElementosRepetidos.sh ElementosRepetidosDef $(repetIni) $(repetFin) $(repetStep)


# Graficas

Graficas/matrizTraspuestaFBvsDyV.png : Datos/matrizTraspuestaDyV.dat Datos/matrizTraspuestaFB.dat
	gnuplot Gnuplot/matrizTraspuestaFBvsDyV.gpi

Graficas/ElementosRepetidosFBvsDyV.png : Datos/ElementosRepetidosDyV.dat Datos/ElementosRepetidosFB.dat
	gnuplot Gnuplot/ElementosRepetidosFBvsDyV.gpi

# Graficas Ajuste

Graficas/matrizTraspuestaDyVAjuste.png : Gnuplot/matrizTraspuestaDyVAjuste.gpi  Datos/matrizTraspuestaDyV.dat
	gnuplot Gnuplot/matrizTraspuestaDyVAjuste.gpi 

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


