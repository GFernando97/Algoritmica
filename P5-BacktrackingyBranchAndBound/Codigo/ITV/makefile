
EXE = generador itv
ESC = esc16.txt esc22.txt

rutaESC = ./Escenarios

min = 1
max = 20

all : $(EXE) $(ESC)

exe : $(EXE)

esc : $(ESC)

generador : generador.cpp
	g++ -Wall -std=c++17 -o $@ $<

itv : itv.cpp
	g++ -Wall -std=c++17 -o $@ $<

esc16.txt : generador
	./$< 16 $(min) $(max) > $(rutaESC)/$@

esc22.txt : generador
	./$< 22 $(min) $(max) > $(rutaESC)/$@

clean:
	rm $(EXE)
	rm $(rutaESC)/*

cleanexe:
	rm $(EXE)
