projet.exe:  visualisationC.o visualisationT.o consigne.o regulation.o autotests.o test_unitaire.o simulateur.o #releve.o
	gcc -g visualisationC.o visualisationT.o consigne.o regulation.o autotests.o test_unitaire.o simulateur.o 
# i386/ftd2xx.lib

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

#test_simulateur.o: test_simulateur.c
#	gcc -c test_simulateur.c

test_unitaire.o: test_unitaire.c
	gcc -c test_unitaire.c
simulateur.o: simulateur.c simulateur.h
	gcc -c simulateur.c

# releve.o: releve.c releve.h
# 	gcc -c releve.c
clean :
	rm *.o *.exe