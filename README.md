# ProjetUML
 
Sous terminal :	

Dans le repertoir avec tous les .h et .cpp, trois commandes sont possible grace au MakeFile:

	-la commande "make main" créera l'exécutable "main" qui correspond au fonctionnement standard du programme. Se référer au manuel utilisateur présent sur le 1er rapport pour naviguer dans les menus.	
	
	-La commande "make test1" créera l'exécutable "test1" qui teste la 1re fonctionnalité, soit la fonctionnalité pour trier les capteurs selon leurs similarités avec un capteur défini.  

	-La commande "make test2" créera l'exécutable "test2" qui teste la 2e fonctionnalité, soit la fonctionnalité pour afficher la qualité de l'air en un point.  

L'exécution de test1 et test2 donne les résultats attendus pour différents tests set à comparer avec les résultats du programme. 


Sous IDE (IDE de référence utilisé par le groupe : Clion) :

	-les trois exécutables sont composé des différents fichiers ;
	
	exécutable pour le fonctionnement standard :
	add_executable(ProjetUML Controller.cpp Vue.h Vue.cpp Model.cpp Model.h Objets/Mesure.cpp Objets/Mesure.h Objets/Capteur.cpp Objets/Capteur.h Objets/Utilisateur.h Objets/Utilisateur.cpp Objets/UtilisateurGouvernement.cpp Objets/UtilisateurGouvernement.h Objets/UtilisateurPrive.cpp Objets/UtilisateurPrive.h Objets/Purificateur.cpp Objets/Purificateur.h Objets/FournisseurPurificateur.h Objets/FournisseurPurificateur.cpp)
	
	exécutable pour test1 :
	add_executable(TestCapteursSimilaires Tests/TestCapteursSimilaires.cpp Vue.h Vue.cpp Model.cpp Model.h Objets/Mesure.cpp Objets/Mesure.h Objets/Capteur.cpp Objets/Capteur.h Objets/Utilisateur.h Objets/Utilisateur.cpp Objets/UtilisateurGouvernement.cpp Objets/UtilisateurGouvernement.h Objets/UtilisateurPrive.cpp Objets/UtilisateurPrive.h Objets/Purificateur.cpp Objets/Purificateur.h Objets/FournisseurPurificateur.h Objets/FournisseurPurificateur.cpp)

	exécutable pour test2 :
	add_executable(TestQualiteAirPoint Tests/TestQualiteAirPoint.cpp Vue.h Vue.cpp Model.h Model.cpp Objets/Capteur.h Objets/Capteur.cpp Objets/Mesure.h Objets/Mesure.cpp Objets/Utilisateur.h Objets/Utilisateur.cpp Objets/UtilisateurGouvernement.cpp Objets/UtilisateurGouvernement.h Objets/UtilisateurPrive.cpp Objets/UtilisateurPrive.h Objets/Purificateur.cpp Objets/Purificateur.h Objets/FournisseurPurificateur.h Objets/FournisseurPurificateur.cpp)

	-Il faut bien penser à mettre en working directory la racine du projet, pour la récupération des Csv.
