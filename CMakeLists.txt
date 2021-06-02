cmake_minimum_required(VERSION 3.17)
project(ProjetUML)

set(CMAKE_CXX_STANDARD 11)


add_executable(ProjetUML Controller.cpp Vue.h Vue.cpp Model.cpp Model.h Objets/Mesure.cpp Objets/Mesure.h Objets/Capteur.cpp Objets/Capteur.h Objets/Utilisateur.h Objets/Utilisateur.cpp Objets/UtilisateurGouvernement.cpp Objets/UtilisateurGouvernement.h Objets/UtilisateurPrive.cpp Objets/UtilisateurPrive.h Objets/Purificateur.cpp Objets/Purificateur.h Objets/FournisseurPurificateur.h Objets/FournisseurPurificateur.cpp)


add_executable(TestValeursPurificateurs Tests/TestValeursPurificateurs.cpp Objets/Purificateur.cpp Objets/Purificateur.h Objets/FournisseurPurificateur.cpp Objets/FournisseurPurificateur.h Objets/Utilisateur.cpp Objets/Utilisateur.h)

add_executable(TestCapteurs Objets/Capteur.cpp Objets/Capteur.h Objets/Mesure.cpp Objets/Mesure.h Tests/TestCapteurs.cpp Objets/UtilisateurPrive.cpp Objets/UtilisateurPrive.h Objets/Utilisateur.h Objets/Utilisateur.cpp)
add_executable(TestMesures Objets/Mesure.cpp Objets/Mesure.h Tests/TestMesures.cpp)

add_executable(TestCapteursSimilaires Tests/TestCapteursSimilaires.cpp Vue.h Vue.cpp Model.cpp Model.h Objets/Mesure.cpp Objets/Mesure.h Objets/Capteur.cpp Objets/Capteur.h Objets/Utilisateur.h Objets/Utilisateur.cpp Objets/UtilisateurGouvernement.cpp Objets/UtilisateurGouvernement.h Objets/UtilisateurPrive.cpp Objets/UtilisateurPrive.h Objets/Purificateur.cpp Objets/Purificateur.h Objets/FournisseurPurificateur.h Objets/FournisseurPurificateur.cpp)

