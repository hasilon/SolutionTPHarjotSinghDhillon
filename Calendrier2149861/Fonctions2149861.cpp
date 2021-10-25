#include "Fonctions2149861.h"
#include <iostream>

using namespace std;


void afficherMenu() // Cette fonction est void parce qu'elle ne retourne rien
{
    // Afficher le menu suivant au user
    
    cout << "---------------------------- Calendrier Gr�gorien -----------------------------" << endl;
    cout << "------------------------- pr�sent� par Harjot Singh ---------------------------" << endl << endl;

    cout << " 1. Afficher les informations d'un mois et d'une ann�e donn�e" << endl;
    cout << " 2. Afficher le calendrier mensuel d'un mois et d'une ann�e donn�e" << endl;
    cout << " 3. Afficher le calendrier trimestriel d'un mois et d'une ann�e donn�e" << endl;
    cout << " 4. Afficher le calendrier complet d'une ann�e donn�e" << endl;
    cout << " 5. Quitter le programme" << endl << endl;

    cout << "-------------------------------------------------------------------------------" << endl;
    cout << " Votre choix --> ";

}

char validerChoixMenu(char min, char max) // La fonction qui verifie le choix du user
{
    char choice; /* La variable qui va stocker le choix du user, la variable est un char parce qu'elle verifie pas 
                    juste si un nombre est entrer, mais n'importe quel caractere  */

    cin >> choice; // Le user entre son choix

    while (choice < min || choice > max) // Si le choix est moins que minimum ou plus que max, faire le suivant
    {
        cout << "Erreur, entrez un chiffre entre " << min << " et " << max << ": "; // Lui output ce message
        cin >> choice; // Le user rentre son choix
    }
    
    return choice; // La fonction retourne choice
}

int demanderAnnee(int year) // Fonction qui verfie l'annee entrer
{
    /* Je pouvais utiliser un string pour "year", mais c'est specifiquement dit de verifier si c'est egale ou
       superieure a 1582, pas je devais verifier si c'etait un nombre,lettre,etc. */
    
    const int MIN_YEAR = 1582; // L'annee minimum que le user peut entrer

    cout << "Entrez une annee: "; // Demande au user d'entrer une annee
    cin >> year; // Le user entre une annee
   
    while (year < MIN_YEAR) // Si l'annee entrer est moins que "MIN_YEAR(1582)", faire le suivant
    {
        cout << "Erreur, entrez une annee superieure ou egale a " << MIN_YEAR << ": "; // Output un message d'erreur
        cin >> year; // Le user reentre une annee
    }

    return year; // La fonction retourne year
}

int demanderMois(int month)
{
    const int MIN_MONTH = 1; // Le mois minimum que le user peut entrer
    const int MAX_MONTH = 12; // Le mois maximum que le user peut entrer

    cout << "Entrez un mois: "; // Demande au user d'entrer un mois
    cin >> month; // Le user entre un mois

    while (month < MIN_MONTH || month > MAX_MONTH) // Si le mois entrer n'est pas entre min_month et max_month, faire le suivant
    {
        cout << "Erreur, entrez un mois entre " << MIN_MONTH << " et "<< MAX_MONTH << ": "; // Output un message d'erreur
        cin >> month; // Le user reentre un mois
    }

    return month; // La fonction retourne month

}

void afficherInfoMois(int month, int year)
{
    cout << "------------------------ " << month << " " << year << " ------------------------" << endl << endl;
    
    const int DAY = 1; // On veut toujours savoir le jour du premier, fais que c'est une constante
    
    //--------------------------------------------------------------------------------------
    /* Je ne suis pas sure comment ce code fonctionne, mais cela me permet de savoir le jour(lundi) avec le mois,
       l'annee, et le jour */
    
    int a;
    int y;
    int m;
    
    int final;
    
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;
    
    final = (DAY + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
   
    // Fin du code copier coller -------------------------------------------------------------------

    switch (final) // Dependament de la valeur de final, je output un de ces messages
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



}


