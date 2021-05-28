cmake_minimum_required(VERSION 3.17)
project(ProjetUML)

set(CMAKE_CXX_STANDARD 11)

add_executable(ProjetUML Test.cpp Purificateur.cpp Purificateur.h Utilisateur.cpp Utilisateur.h FournisseurPurificateur.cpp FournisseurPurificateur.h UtilisateurGouvernement.cpp UtilisateurGouvernement.h UtilisateurPrive.cpp UtilisateurPrive.h Mesure.h Mesure.cpp Capteur.h Capteur.cpp)
