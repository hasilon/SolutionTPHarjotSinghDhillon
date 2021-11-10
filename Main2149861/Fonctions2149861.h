#pragma once
#include <string>

// Fonctions du TP
void afficherMenu();
char validerChoixMenu(char min, char max);
int demanderAnnee();
int demanderMois();
void afficherInfoMois(int year, int month);

// Fonctions Extra
void afficherMois(int month);
int premierJourSemaine(int year, int month);

