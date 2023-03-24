projet_sim.exe:  visualisationC.o visualisationT.o consigne.o regulation.o autotests.o test_simulateur.o simulateur.o define.h
	gcc -g visualisationC.o visualisationT.o consigne.o regulation.o autotests.o test_simulateur.o simulateur.o -o projet_sim.exe


projet_test.exe:  visualisationC.o visualisationT.o consigne.o regulation.o autotests.o test_unitaire.o simulateur.o define.h
	gcc -g visualisationC.o visualisationT.o consigne.o regulation.o autotests.o test_unitaire.o simulateur.o  -o projet_test.exe

# projet.exe:  visualisationC.o visualisationT.o consigne.o regulation.o commande.o releve.o test_usb.o define.h
# 	gcc visualisationC.o visualisationT.o consigne.o regulation.o commande.o releve.o test_usb.o i386/ftd2xx.lib -o projet.exe

visualisationC.o: visualisationC.c visualisationC.h
	gcc -c visualisationC.c

visualisationT.o: visualisationT.c visualisationT.h
	gcc -c visualisationT.c

consigne.o : consigne.c consigne.h
	gcc -c consigne.c

regulation.o: regulation.c regulation.h
	gcc -c regulation.c
#enlever:
autotests.o : autotests.c autotests.h
	gcc -c autotests.c

test_simulateur.o: test_simulateur.c
	gcc -c test_simulateur.c
#enlever
test_unitaire.o: test_unitaire.c
	gcc -c test_unitaire.c

simulateur.o: simulateur.c simulateur.h
	gcc -c simulateur.c

releve.o: releve.c releve.h
	gcc -c releve.c

commande.o: commande.c commande.h
	gcc -c commande.c

test_usb.o: test_usb.c
	gcc -c test_usb.c

clean :
	rm *.o