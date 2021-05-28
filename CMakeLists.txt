cmake_minimum_required(VERSION 3.17)
project(ProjetUML)

set(CMAKE_CXX_STANDARD 11)


add_executable(ProjetUML Controller.cpp Vue.h Vue.cpp Model.cpp Model.h Objets/Mesure.cpp Objets/Mesure.h Objets/Capteur.cpp Objets/Capteur.h Objets/Utilisateur.h Objets/Utilisateur.cpp Objets/UtilisateurGouvernement.cpp Objets/UtilisateurGouvernement.h Objets/UtilisateurPrive.cpp Objets/UtilisateurPrive.h Objets/Purificateur.cpp Objets/Purificateur.h Objets/FournisseurPurificateur.h Objets/FournisseurPurificateur.cpp)
add_executable(TestMesuresCapteurs Objets/Capteur.cpp Objets/Capteur.h Objets/Mesure.cpp Objets/Mesure.h Tests/TestMesuresCapteurs.cpp Objets/UtilisateurPrive.cpp Objets/UtilisateurPrive.h Objets/Utilisateur.h Objets/Utilisateur.cpp)
add_executable(ProjetUML2 Test.cpp Purificateur.cpp Purificateur.h Utilisateur.cpp Utilisateur.h FournisseurPurificateur.cpp FournisseurPurificateur.h UtilisateurGouvernement.cpp UtilisateurGouvernement.h UtilisateurPrive.cpp UtilisateurPrive.h Mesure.h Mesure.cpp Capteur.h Capteur.cpp)

