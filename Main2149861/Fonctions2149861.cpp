#include "Fonctions2149861.h"
#include <iostream>
#include <string>

using namespace std;

void afficherMenu()
{
    // Afficher le menu suivant au user

    cout << "---------------------------- Calendrier Grégorien -----------------------------" << endl;
    cout << "------------------------- présenté par Harjot Singh ---------------------------" << endl << endl;

    cout << " 1. Afficher les informations d'un mois et d'une année donnée" << endl;
    cout << " 2. Afficher le calendrier mensuel d'un mois et d'une année donnée" << endl;
    cout << " 3. Afficher le calendrier trimestriel d'un mois et d'une année donnée" << endl;
    cout << " 4. Afficher le calendrier complet d'une année donnée" << endl;
    cout << " 5. Quitter le programme" << endl << endl;

    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "Votre choix --> ";
}

char validerChoixMenu(char min, char max)
{
    string clavier;

    getline(cin, clavier, '\n');
 
    char reponse = clavier.front();
    
    while (reponse < min || reponse > max)
    { 
        cout << "Erreur, entrez un chiffre entre " << min << " et " << max << ": ";
        getline(cin, clavier, '\n');
        reponse = clavier.front();
    }

    system("cls");
    
    return reponse;
}

int demanderAnnee()
{
    const string MIN_ANNEE = "1582";

    string clavier;

    cout << "Veuillez indiquer l'année : "; // Demande au user d'entrer une annee
    
    getline(cin, clavier, '\n');

    while (clavier < MIN_ANNEE || clavier >= "a" || clavier >= "A")
    {
        cout << "Erreur, entrez une annee plus que " << MIN_ANNEE << ": ";
        getline(cin, clavier, '\n');
    }
    
    int reponse;
    
    reponse = stoi(clavier);

    system("cls");

    return reponse;
}

int demanderMois()
{
    const string MIN_MOIS = "1";
    const string MAX_MOIS = "12";

    string clavier;
    int reponse;

    cout << "Veuillez indiquer le mois: "; // Demande au user d'entrer une annee

    getline(cin, clavier, '\n');

    while(clavier > MAX_MOIS)
    {
        cout << "Erreur, entrez une annee plus que " << MIN_MOIS << ": ";
        getline(cin, clavier, '\n');
    }

    reponse = stoi(clavier);

    system("cls");

    return reponse;

}

void afficherInfoMois(int year, int month)
{
    cout << "------------------------ "; afficherMois(month); cout << " " << year << " ------------------------" << endl << endl;

    int jourDeSemaine = premierJourSemaine(year, month);

    switch (jourDeSemaine) // Dependament de la valeur de final, je output un de ces messages
    {
    case 0: // Si la valeur est 0, output cela
        cout << "Le premier jour du mois est un dimanche" << endl << endl;
        break;
    case 1: // Si la valeur est 1, output cela
        cout << "Le premier jour du mois est un lundi" << endl << endl;
        break;
    case 2: // Si la valeur est 2, output cela
        cout << "Le premier jour du mois est un mardi" << endl << endl;
        break;
    case 3: // Si la valeur est 3, output cela
        cout << "Le premier jour du mois est un mercredi" << endl << endl;
        break;
    case 4: // Si la valeur est 4, output cela
        cout << "Le premier jour du mois est un jeudi" << endl << endl;
        break;
    case 5: // Si la valeur est 5, output cela
        cout << "Le premier jour du mois est un vendredi" << endl << endl;
        break;
    case 6: // Si la valeur est 6, output cela
        cout << "Le premier jour du mois est un samedi" << endl << endl;
        break;
    }

    // Montrer le nombre de jours dans chaque mois

    // Fevrier
    if (month == 2) // Si le user choisi 2 dans le mois (Fevrier), faire le suivant
    {
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) // Si c'est une annee bissextile, output le message suivant
        {
            cout << "Ce mois a 29 jours." << endl << endl;
        }
        else // Si ce n'est pas une annee bissextile, output le message suivant
            cout << "Ce mois a 28 jours." << endl << endl;
    }

    // Tous les mois qui ont 31 jours
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) // Si le user choisi une de ces options,
                                                                                                          // output le message suivant 
    {
        cout << "Ce mois a 31 jours." << endl << endl;
    }

    // Tous les mois qui ont 30 jours
    else if (month == 4 || month == 6 || month == 9 || month == 11) // Si le user choisi une de ces options, output ce message
    {
        cout << "Ce mois a 30 jours." << endl << endl;
    }

    cout << "--------------------------------------------------------------" << endl;

} 

void afficherMois(int month)
{
    switch (month)
    {
    case 1: cout << "Janvier";   break;
    case 2: cout << "Février";   break;
    case 3: cout << "Mars";      break;
    case 4: cout << "Avril";     break;
    case 5: cout << "Mai";       break;
    case 6: cout << "Juin";      break;
    case 7: cout << "Juillet";   break;
    case 8: cout << "Août";      break;
    case 9: cout << "Septembre"; break;
    case 10:cout << "Octobre";   break;
    case 11:cout << "Novembre";  break;
    case 12:cout << "Décembre";  break;
    }
} 

int premierJourSemaine(int year, int month)
{
    const int DAY = 1; // On veut toujours savoir le jour du premier, fais que c'est une constante
    
    int a;
    int y;
    int m;

    int final;

    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;

    final = (DAY + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    
    return final;
} 
