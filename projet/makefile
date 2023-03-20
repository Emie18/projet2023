projet.exe:  visualisationC.o visualisationT.o consigne.o regulation.o autotests.o test_simulateur.o simulateur.o
	gcc -g visualisationC.o visualisationT.o consigne.o regulation.o autotests.o test_simulateur.o simulateur.o

visualisationC.o: visualisationC.c visualisationC.h
	gcc -c visualisationC.c
visualisationT.o: visualisationT.c visualisationT.h
	gcc -c visualisationT.c
consigne.o : consigne.c consigne.h
	gcc -c consigne.c
regulation.o: regulation.c regulation.h
	gcc -c regulation.c

autotests.o : autotests.c autotests.h
	gcc -c autotests.c

test_simulateur.o: test_simulateur.c
	gcc -c test_simulateur.c
simulateur.o: simulateur.c simulateur.h
	gcc -c simulateur.c
clean :
	rm *.o *.exe