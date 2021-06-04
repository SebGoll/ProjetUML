
GCC=g++
ECHO=echo
CCFLAGS=-c
CFLAGS= -Wall -ansi -pedantic -std=c++11
DFLAGS = 
OBJETSC= Objets/Capteur.o Controller.o Objets/FournisseurPurificateur.o Objets/Mesure.o Model.o Objets/Purificateur.o Objets/Utilisateur.o Objets/UtilisateurGouvernement.o Objets/UtilisateurPrive.o Vue.o
OBJETS= Capteur.o Controller.o FournisseurPurificateur.o Mesure.o Model.o Purificateur.o Utilisateur.o UtilisateurGouvernement.o UtilisateurPrive.o Vue.o
OBJETSTEST1C= Objets/Capteur.o Tests/TestCapteursSimilaires.o Objets/FournisseurPurificateur.o Objets/Mesure.o Model.o Objets/Purificateur.o Objets/Utilisateur.o Objets/UtilisateurGouvernement.o Objets/UtilisateurPrive.o Vue.o
OBJETSTEST1= Capteur.o TestCapteursSimilaires.o FournisseurPurificateur.o Mesure.o Model.o Purificateur.o Utilisateur.o UtilisateurGouvernement.o UtilisateurPrive.o Vue.o
OBJETSTEST2C= Objets/Capteur.o Tests/TestQualiteAirPoint.o Objets/FournisseurPurificateur.o Objets/Mesure.o Model.o Objets/Purificateur.o Objets/Utilisateur.o Objets/UtilisateurGouvernement.o Objets/UtilisateurPrive.o Vue.o
OBJETSTEST2= Capteur.o TestQualiteAirPoint.o FournisseurPurificateur.o Mesure.o Model.o Purificateur.o Utilisateur.o UtilisateurGouvernement.o UtilisateurPrive.o Vue.o

EXE=main

debug: DFLAGS = -DMAP
debug : $(EXE)

$(EXE):$(OBJETSC)
	$(GCC) -o $(EXE) $(OBJETS) $(CFLAGS)

test1 :$(OBJETSTEST1C)
	$(GCC) -o test1 $(OBJETSTEST1) $(CFLAGS)

test2 :$(OBJETSTEST2C)
	$(GCC) -o test2 $(OBJETSTEST2) $(CFLAGS)
%.o:%.cpp
	$(ECHO) $(GCC) $(CCFLAGS) $<
	$(GCC) $(CCFLAGS) $< $(DFLAGS)

Capteur.o : Objets/Mesure.h Objets/UtilisateurPrive.h
Model.o : Objets/Mesure.h Objets/Capteur.h Vue.h
Vue.o : Objets/Capteur.h Objets/Purificateur.h
Purificateur.o : Objets/FournisseurPurificateur.h
Controller.o : Vue.h Model.h
TestCapteursSimilaires.o : Model.h
TestQualiteAirPoint.o : Model.h
UtilisateurGouvernement.o : Objets/Utilisateur.h
UtilisateurPrive.o : Objets/Utilisateur.h
clean : 
	@rm -rf *.o

mrproper : clean

	@rm -rf $(EXE)
