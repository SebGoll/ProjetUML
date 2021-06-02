
GCC=g++
ECHO=echo
CCFLAGS=-c
CFLAGS= -Wall -ansi -pedantic -std=c++11
DFLAGS = 
OBJETS= Objets/Capteur.o Controller.o Objets/FournisseurPurificateur.o Objets/Mesure.o Model.o Objets/Purificateur.o Objets/Utilisateur.o Objets/UtilisateurGouvernement.o Objets/UtilisateurPrive.o Vue.o
OBJETSTEST= Objets/Capteur.o TestMesuresCapteurs.o FournisseurPurificateur.o Mesure.o Model.o Purificateur.o Utilisateur.o UtilisateurGouvernement.o UtilisateurPrive.o Vue.o
EXE=main

debug: DFLAGS = -DMAP
debug : $(EXE)

$(EXE):$(OBJETS)
	$(GCC) -o $(EXE) $(OBJETS) $(CFLAGS)

test :$(OBJETSTEST)
	$(GCC) -o test $(OBJETSTEST) $(CFLAGS)
%.o:%.cpp
	$(ECHO) $(GCC) $(CCFLAGS) $<
	$(GCC) $(CCFLAGS) $< $(DFLAGS)

Capteur.o : Objets/Mesure.h Objets/UtilisateurPrive.h
Model.o : Objets/Mesure.h Objets/Capteur.h Vue.h
Vue.o : Objets/Capteur.h Objets/Purificateur.h
Purificateur.o : Objets/FournisseurPurificateur.h
Controller.o : Vue.h Model.h
TestMesuresCapteurs.o : Objets/Capteur.h Objets/Mesure.h
UtilisateurGouvernement.o : Objets/Utilisateur.h
UtilisateurPrive.o : Objets/Utilisateur.h
clean : 
	@rm -rf *.o

mrproper : clean

	@rm -rf $(EXE)
