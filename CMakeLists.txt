cmake_minimum_required(VERSION 3.17)
project(ProjetUML)

set(CMAKE_CXX_STANDARD 11)

add_executable(ProjetUML Controller.cpp Vue.h Vue.cpp Model.cpp Model.h Mesure.cpp Mesure.h Capteur.cpp Capteur.h Utilisateur.h Utilisateur.cpp UtilisateurGouvernement.cpp UtilisateurGouvernement.h UtilisateurPrive.cpp UtilisateurPrive.h Purificateur.cpp Purificateur.h FournisseurPurificateur.h FournisseurPurificateur.cpp)