Resultado.png: graficador.py datos.txt
	python grafica.py
    
datos.txt: a.out
	./a.out

a.out: PDE.cpp
	c++ PDE.cpp

clean:
	rm -rf *.out *.dat Resultado.png