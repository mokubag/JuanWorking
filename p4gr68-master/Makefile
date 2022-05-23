.PHONY: principal

principal: 
	g++ -Wall -g -c principal.cpp -o obj/principal.o
	g++ -Wall -g -c src/Sistema.cpp -o obj/Sistema.o
	g++ -Wall -g -c src/Arribo.cpp -o obj/Arribo.o
	g++ -Wall -g -c src/Barco.cpp -o obj/Barco.o
	g++ -Wall -g -c src/BarcoPasajeros.cpp -o obj/BarcoPasajeros.o
	g++ -Wall -g -c src/BarcoPesquero.cpp -o obj/BarcoPesquero.o
	g++ -Wall -g -c src/Puerto.cpp -o obj/Puerto.o
	g++ -Wall -g -c src/Colecciones.cpp -o obj/Colecciones.o
	g++ -Wall -g -c src/DtArribo.cpp -o obj/DtArribo.o
	g++ -Wall -g -c src/DtBarco.cpp -o obj/DtBarco.o
	g++ -Wall -g -c src/DtBarcoPasajeros.cpp -o obj/DtBarcoPasajeros.o
	g++ -Wall -g -c src/DtBarcoPesquero.cpp -o obj/DtBarcoPesquero.o
	g++ -Wall -g -c src/DtPuerto.cpp -o obj/DtPuerto.o
	g++ -Wall -g -c src/DtFecha.cpp -o obj/DtFecha.o
	g++ -Wall -g obj/principal.o obj/Sistema.o obj/Arribo.o obj/Barco.o obj/BarcoPasajeros.o obj/BarcoPesquero.o obj/Puerto.o obj/Colecciones.o obj/DtArribo.o obj/DtBarco.o obj/DtBarcoPasajeros.o obj/DtBarcoPesquero.o obj/DtPuerto.o obj/DtFecha.o -o principal
	rm obj/*


clean:
	rm principal
