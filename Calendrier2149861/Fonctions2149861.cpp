#include "Fonctions2149861.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


void afficherMenu() // Cette fonction est void parce qu'elle ne retourne rien
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

    system("cls");
    
    return choice; // La fonction retourne choice
}

void affiMois(int month)
{
    switch (month)
    {
    case 1:
        cout << "Janvier";
        break;
    case 2:
        cout << "Février";
        break;
    case 3:
        cout << "Mars";
        break;
    case 4:
        cout << "Avril";
        break;
    case 5:
        cout << "Mai";
        break;
    case 6:
        cout << "Juin";
        break;
    case 7:
        cout << "Juillet";
        break;
    case 8:
        cout << "Août";
        break;
    case 9:
        cout << "Septembre";
        break;
    case 10:
        cout << "Octobre";
        break;
    case 11:
        cout << "Novembre";
        break;
    case 12:
        cout << "Décembre";
        break;
    }
}

int demanderAnnee(int year) // Fonction qui verfie l'annee entrer
{
    /* Je pouvais utiliser un string pour "year", mais c'est specifiquement dit de verifier si c'est egale ou
       superieure a 1582, pas je devais verifier si c'etait un nombre,lettre,etc. */
    
    const int MIN_YEAR = 1582; // L'annee minimum que le user peut entrer
    string entrerAnnee;
    

    cout << "Veuillez indiquer l'année : "; // Demande au user d'entrer une annee
    cin >> year; // Le user entre une annee
    
    
    while (year < MIN_YEAR) // Si l'annee entrer est moins que "MIN_YEAR(1582)", faire le suivant
    {
        cout << "Erreur, entrez une annee superieure ou egale a " << MIN_YEAR << ": "; // Output un message d'erreur
        cin >> year; // Le user reentre une annee
    }

    system("cls");

    return year; // La fonction retourne year
}

int demanderMois(int month)
{
    const int MIN_MONTH = 1; // Le mois minimum que le user peut entrer
    const int MAX_MONTH = 12; // Le mois maximum que le user peut entrer

    cout << "Veuillez indiquer le numéro du mois : "; // Demande au user d'entrer un mois
    cin >> month; // Le user entre un mois

    while (month < MIN_MONTH || month > MAX_MONTH) // Si le mois entrer n'est pas entre min_month et max_month, faire le suivant
    {
        cout << "Erreur, entrez un mois entre " << MIN_MONTH << " et "<< MAX_MONTH << ": "; // Output un message d'erreur
        cin >> month; // Le user reentre un mois
    }

    system("cls");

    return month; // La fonction retourne month

}

void afficherInfoMois(int year, int month)
{
    cout << "------------------------ "; affiMois(month); cout << " " << year << " ------------------------" << endl << endl;
    
    const int DAY = 1; // On veut toujours savoir le jour du premier, fais que c'est une constante
    
    // Montrer le premier jour du mois--------------------------------------------------------------------------------------
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
    
    // Tous les mois a 31 jours
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) /* Si le user choisi une de ces options,
                                                                                                             output le message suivant */
    {
        cout << "Ce mois a 31 jours." << endl << endl;
    }
    
    // Tous les mois a 30 jours
    else if (month == 4 || month == 6 || month == 9 || month == 11) // Si le user choisi une de ces options, output ce message
    {
        cout << "Ce mois a 30 jours." << endl << endl;
    }

    cout << "--------------------------------------------------------------" << endl;
}

void afficherCalendrierMensuel(int month, int year)
{
    cout << "--------- "; affiMois(month); cout << " " << year << " ----------" << endl;

    
    
    const int MOIS_JOURSMAX = 32;
    int PremierJourMois;

    int a;
    int y;
    int m;

    int compterJ = 1;

    int final;

      
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;

    PremierJourMois = (1 + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    
    // ==========================================================================================================

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {

        switch (PremierJourMois)
        {
       
        case 0: 
            
            cout << " dim lun mar mer jeu ven sam" << endl; // Je output le header du menu
            
            for (int i = 1; compterJ < 31; i++) // ceci est ma premiere loop for qui me sert a changer de semaine
                                                // ou en d'autre mots, sauter des lignes
            {
                cout << setw(3) << right; // Ceci est la commande qui me sert a alligner la premiere date de chaque semaine

                for (int j = 0; j < 7; j++) // Cette loop me sert a output les nombres, fait que sa ouput 7 nombres
                                            // et ensuite sa sort du loop
                {
                    cout << setw(4) << right; // Commande qui alligne bien les dates

                    cout << compterJ; // Commande principal qui output chaque date
                     
                    if (compterJ == 31) // Commande pour arreter au fin du mois, qui veut dire que la loop arrete
                                        // une fois qu'on arrive a 31 jours
                    {
                        break; // Commande pour arreter le programme
                    }
                   
                    compterJ++; // Ajouter 1 a la variable qui compte les jours

                }
                
                cout << endl; // Commande qui saute de ligne apres chaque semain ou chaque 7 jours
            }
            break;
        
        case 1:

            cout << " dim lun mar mer jeu ven sam" << endl; // Ouput le menu

            for (int PremiereSemaine = 1; PremiereSemaine < 7; PremiereSemaine++) // Loop qui me sert a output la premiere semain puisque c'est different des autres
                                                                                  // Puisque les mois qui commencent lundi on que 6 jours et on commencent a 1, la loop va aller jusqua 7
            {
                if (PremiereSemaine == 1) // Si c'est la premiere journee du mois
                {
                    cout << setw(8) << right; // On alligne la date au bon endroit(Lundi)
                }
                else // Si ce n'est pas le premier du mois
                {
                    cout << setw(4) << right; // On l'alligne comme les autres
                }
               
                cout << PremiereSemaine; // On output la date
            }

           
            cout << endl; // On saute de ligne apres la premiere semaine

            
            compterJ = 7; // On commence la date a partir du 7 parce qu'on deja output les dates avant

            for (int i = 1; compterJ < 31; i++)
            {
               
                cout << setw(3) << right;

                for (int j = 0; j < 7; j++)
                {

                    cout << setw(4) << right;

                    cout << compterJ;

                    if (compterJ == 31)
                    {
                        break;
                    }

                    compterJ++;
                }
                
                cout << endl;

            }
           
            break;

        case 2:

            cout << " dim lun mar mer jeu ven sam" << endl;

            for (int PremiereSemaine = 1; PremiereSemaine < 6; PremiereSemaine++)
            {
                if (PremiereSemaine == 1)
                {
                    cout << setw(12) << right;
                }
                else
                {
                    cout << setw(4) << right;
                }

                cout << PremiereSemaine;
            }

            cout << endl;

            compterJ = 6;

            for (int i = 1; compterJ < 31; i++)
            {

                cout << setw(3) << right;

                for (int j = 0; j < 7; j++)
                {

                    cout << setw(4) << right;

                    cout << compterJ;

                    if (compterJ == 31)
                    {
                        break;
                    }

                    compterJ++;
                }

                cout << endl;

            }
            
            break;

        case 3:
            cout << " dim lun mar mer jeu ven sam" << endl; // Ouput le menu

            for (int PremiereSemaine = 1; PremiereSemaine < 5; PremiereSemaine++) // Loop qui me sert a output la premiere semain puisque c'est different des autres
                                                                                  // Puisque les mois qui commencent lundi on que 6 jours et on commencent a 1, la loop va aller jusqua 7
            {
                if (PremiereSemaine == 1) // Si c'est la premiere journee du mois
                {
                    cout << setw(16) << right; // On alligne la date au bon endroit(Lundi)
                }
                else // Si ce n'est pas le premier du mois
                {
                    cout << setw(4) << right; // On l'alligne comme les autres
                }

                cout << PremiereSemaine; // On output la date
            }


            cout << endl; // On saute de ligne apres la premiere semaine


            compterJ = 5; // On commence la date a partir du 5 parce qu'on deja output les dates avant

            for (int i = 1; compterJ < 31; i++)
            {

                cout << setw(3) << right;

                for (int j = 0; j < 7; j++)
                {

                    cout << setw(4) << right;

                    cout << compterJ;

                    if (compterJ == 31)
                    {
                        break;
                    }

                    compterJ++;
                }

                cout << endl;

            }


            break;

        case 4:
            cout << "dim lun mar mer jeu ven sam" << endl;

            cout << setw(19) << right << "1";
            cout << setw(4) << right << "2";
            cout << setw(4) << right << "3" << endl;

            cout << setw(3) << right << "4";
            cout << setw(4) << right << "5";
            cout << setw(4) << right << "6";
            cout << setw(4) << right << "7";
            cout << setw(4) << right << "8";
            cout << setw(4) << right << "9";
            cout << setw(4) << right << "10" << endl;

            cout << setw(3) << right << "11";
            cout << setw(4) << right << "12";
            cout << setw(4) << right << "13";
            cout << setw(4) << right << "14";
            cout << setw(4) << right << "15";
            cout << setw(4) << right << "16";
            cout << setw(4) << right << "17" << endl;

            cout << setw(3) << right << "18";
            cout << setw(4) << right << "19";
            cout << setw(4) << right << "20";
            cout << setw(4) << right << "21";
            cout << setw(4) << right << "22";
            cout << setw(4) << right << "23";
            cout << setw(4) << right << "24" << endl;

            cout << setw(3) << right << "25";
            cout << setw(4) << right << "26";
            cout << setw(4) << right << "27";
            cout << setw(4) << right << "28";
            cout << setw(4) << right << "29";
            cout << setw(4) << right << "30";
            cout << setw(4) << right << "31" << endl;

            break;

        case 5:
            cout << "dim lun mar mer jeu ven sam" << endl;

            cout << setw(23) << right << "1";
            cout << setw(4) << right << "2" << endl;
            
            cout << setw(3) << right << "3";
            cout << setw(4) << right << "4";
            cout << setw(4) << right << "5";
            cout << setw(4) << right << "6";
            cout << setw(4) << right << "7";
            cout << setw(4) << right << "8";
            cout << setw(4) << right << "9" << endl;
            
            cout << setw(3) << right << "10";
            cout << setw(4) << right << "11";
            cout << setw(4) << right << "12";
            cout << setw(4) << right << "13";
            cout << setw(4) << right << "14";
            cout << setw(4) << right << "15";
            cout << setw(4) << right << "16" << endl;
            
            cout << setw(3) << right << "17";
            cout << setw(4) << right << "18";
            cout << setw(4) << right << "19";
            cout << setw(4) << right << "20";
            cout << setw(4) << right << "21";
            cout << setw(4) << right << "22";
            cout << setw(4) << right << "23" << endl;
            
            cout << setw(3) << right << "24";
            cout << setw(4) << right << "25";
            cout << setw(4) << right << "26";
            cout << setw(4) << right << "27";
            cout << setw(4) << right << "28";
            cout << setw(4) << right << "29";
            cout << setw(4) << right << "30" << endl;
           
            cout << setw(3) << right << "31" << endl;

            break;
            
        case 6:
            cout << "dim lun mar mer jeu ven sam" << endl;

            cout << setw(27) << right << "1" << endl;
           
            cout << setw(3) << right << "2";
            cout << setw(4) << right << "3";
            cout << setw(4) << right << "4";
            cout << setw(4) << right << "5";
            cout << setw(4) << right << "6";
            cout << setw(4) << right << "7";
            cout << setw(4) << right << "8" << endl;

            cout << setw(3) << right << "9";
            cout << setw(4) << right << "10";
            cout << setw(4) << right << "11";
            cout << setw(4) << right << "12";
            cout << setw(4) << right << "13";
            cout << setw(4) << right << "14";
            cout << setw(4) << right << "15" << endl;
            
            cout << setw(3) << right << "16";
            cout << setw(4) << right << "17";
            cout << setw(4) << right << "18";
            cout << setw(4) << right << "19";
            cout << setw(4) << right << "20";
            cout << setw(4) << right << "21";
            cout << setw(4) << right << "22" << endl;

            cout << setw(3) << right << "23";
            cout << setw(4) << right << "24";
            cout << setw(4) << right << "25";
            cout << setw(4) << right << "26";
            cout << setw(4) << right << "27";
            cout << setw(4) << right << "28";
            cout << setw(4) << right << "29" << endl;

            cout << setw(3) << right << "30";
            cout << setw(4) << right << "31" << endl;

            break;

        }

        cout << "----------------------------" << endl;
    }

    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
    
    switch (PremierJourMois)
    {

    case 0:
        cout << "dim lun mar mer jeu ven sam" << endl;

        cout << setw(3) << right << "1";
        cout << setw(4) << right << "2";
        cout << setw(4) << right << "3";
        cout << setw(4) << right << "4";
        cout << setw(4) << right << "5";
        cout << setw(4) << right << "6";
        cout << setw(4) << right << "7" << endl;

        cout << setw(3) << right << "8";
        cout << setw(4) << right << "9";
        cout << setw(4) << right << "10";
        cout << setw(4) << right << "11";
        cout << setw(4) << right << "12";
        cout << setw(4) << right << "13";
        cout << setw(4) << right << "14" << endl;

        cout << setw(3) << right << "15";
        cout << setw(4) << right << "16";
        cout << setw(4) << right << "17";
        cout << setw(4) << right << "18";
        cout << setw(4) << right << "19";
        cout << setw(4) << right << "20";
        cout << setw(4) << right << "21" << endl;

        cout << setw(3) << right << "22";
        cout << setw(4) << right << "23";
        cout << setw(4) << right << "24";
        cout << setw(4) << right << "25";
        cout << setw(4) << right << "26";
        cout << setw(4) << right << "27";
        cout << setw(4) << right << "28" << endl;

        cout << setw(3) << right << "29";
        cout << setw(4) << right << "30" << endl;
       

        break;

    case 1:
        cout << "dim lun mar mer jeu ven sam" << endl;

        cout << setw(7) << right << "1";
        cout << setw(4) << right << "2";
        cout << setw(4) << right << "3";
        cout << setw(4) << right << "4";
        cout << setw(4) << right << "5";
        cout << setw(4) << right << "6" << endl;

        cout << setw(3) << right << "7";
        cout << setw(4) << right << "8";
        cout << setw(4) << right << "9";
        cout << setw(4) << right << "10";
        cout << setw(4) << right << "11";
        cout << setw(4) << right << "12";
        cout << setw(4) << right << "13" << endl;

        cout << setw(3) << right << "14";
        cout << setw(4) << right << "15";
        cout << setw(4) << right << "16";
        cout << setw(4) << right << "17";
        cout << setw(4) << right << "18";
        cout << setw(4) << right << "19";
        cout << setw(4) << right << "20" << endl;

        cout << setw(3) << right << "21";
        cout << setw(4) << right << "22";
        cout << setw(4) << right << "23";
        cout << setw(4) << right << "24";
        cout << setw(4) << right << "25";
        cout << setw(4) << right << "26";
        cout << setw(4) << right << "27" << endl;

        cout << setw(3) << right << "28";
        cout << setw(4) << right << "29";
        cout << setw(4) << right << "30" << endl;
       

        break;

    case 2:
        cout << "dim lun mar mer jeu ven sam" << endl;

        cout << setw(11) << right << "1";
        cout << setw(4) << right << "2";
        cout << setw(4) << right << "3";
        cout << setw(4) << right << "4";
        cout << setw(4) << right << "5" << endl;

        cout << setw(3) << right << "6";
        cout << setw(4) << right << "7";
        cout << setw(4) << right << "8";
        cout << setw(4) << right << "9";
        cout << setw(4) << right << "10";
        cout << setw(4) << right << "11";
        cout << setw(4) << right << "12" << endl;

        cout << setw(3) << right << "13";
        cout << setw(4) << right << "14";
        cout << setw(4) << right << "15";
        cout << setw(4) << right << "16";
        cout << setw(4) << right << "17";
        cout << setw(4) << right << "18";
        cout << setw(4) << right << "19" << endl;

        cout << setw(3) << right << "20";
        cout << setw(4) << right << "21";
        cout << setw(4) << right << "22";
        cout << setw(4) << right << "23";
        cout << setw(4) << right << "24";
        cout << setw(4) << right << "25";
        cout << setw(4) << right << "26" << endl;

        cout << setw(3) << right << "27";
        cout << setw(4) << right << "28";
        cout << setw(4) << right << "29";
        cout << setw(4) << right << "30" << endl;
     

        break;

    case 3:
        cout << "dim lun mar mer jeu ven sam" << endl;

        cout << setw(15) << right << "1";
        cout << setw(4) << right << "2";
        cout << setw(4) << right << "3";
        cout << setw(4) << right << "4" << endl;

        cout << setw(3) << right << "5";
        cout << setw(4) << right << "6";
        cout << setw(4) << right << "7";
        cout << setw(4) << right << "8";
        cout << setw(4) << right << "9";
        cout << setw(4) << right << "10";
        cout << setw(4) << right << "11" << endl;

        cout << setw(3) << right << "12";
        cout << setw(4) << right << "13";
        cout << setw(4) << right << "14";
        cout << setw(4) << right << "15";
        cout << setw(4) << right << "16";
        cout << setw(4) << right << "17";
        cout << setw(4) << right << "18" << endl;

        cout << setw(3) << right << "19";
        cout << setw(4) << right << "20";
        cout << setw(4) << right << "21";
        cout << setw(4) << right << "22";
        cout << setw(4) << right << "23";
        cout << setw(4) << right << "24";
        cout << setw(4) << right << "25" << endl;

        cout << setw(3) << right << "26";
        cout << setw(4) << right << "27";
        cout << setw(4) << right << "28";
        cout << setw(4) << right << "29";
        cout << setw(4) << right << "30" << endl;

        break;

    case 4:
        cout << "dim lun mar mer jeu ven sam" << endl;

        cout << setw(19) << right << "1";
        cout << setw(4) << right << "2";
        cout << setw(4) << right << "3" << endl;

        cout << setw(3) << right << "4";
        cout << setw(4) << right << "5";
        cout << setw(4) << right << "6";
        cout << setw(4) << right << "7";
        cout << setw(4) << right << "8";
        cout << setw(4) << right << "9";
        cout << setw(4) << right << "10" << endl;

        cout << setw(3) << right << "11";
        cout << setw(4) << right << "12";
        cout << setw(4) << right << "13";
        cout << setw(4) << right << "14";
        cout << setw(4) << right << "15";
        cout << setw(4) << right << "16";
        cout << setw(4) << right << "17" << endl;

        cout << setw(3) << right << "18";
        cout << setw(4) << right << "19";
        cout << setw(4) << right << "20";
        cout << setw(4) << right << "21";
        cout << setw(4) << right << "22";
        cout << setw(4) << right << "23";
        cout << setw(4) << right << "24" << endl;

        cout << setw(3) << right << "25";
        cout << setw(4) << right << "26";
        cout << setw(4) << right << "27";
        cout << setw(4) << right << "28";
        cout << setw(4) << right << "29";
        cout << setw(4) << right << "30" << endl;

        break;

    case 5:
        cout << "dim lun mar mer jeu ven sam" << endl;

        cout << setw(23) << right << "1";
        cout << setw(4) << right << "2" << endl;

        cout << setw(3) << right << "3";
        cout << setw(4) << right << "4";
        cout << setw(4) << right << "5";
        cout << setw(4) << right << "6";
        cout << setw(4) << right << "7";
        cout << setw(4) << right << "8";
        cout << setw(4) << right << "9" << endl;

        cout << setw(3) << right << "10";
        cout << setw(4) << right << "11";
        cout << setw(4) << right << "12";
        cout << setw(4) << right << "13";
        cout << setw(4) << right << "14";
        cout << setw(4) << right << "15";
        cout << setw(4) << right << "16" << endl;

        cout << setw(3) << right << "17";
        cout << setw(4) << right << "18";
        cout << setw(4) << right << "19";
        cout << setw(4) << right << "20";
        cout << setw(4) << right << "21";
        cout << setw(4) << right << "22";
        cout << setw(4) << right << "23" << endl;

        cout << setw(3) << right << "24";
        cout << setw(4) << right << "25";
        cout << setw(4) << right << "26";
        cout << setw(4) << right << "27";
        cout << setw(4) << right << "28";
        cout << setw(4) << right << "29";
        cout << setw(4) << right << "30" << endl;


        break;

    case 6:
        cout << "dim lun mar mer jeu ven sam" << endl;

        cout << setw(27) << right << "1" << endl;

        cout << setw(3) << right << "2";
        cout << setw(4) << right << "3";
        cout << setw(4) << right << "4";
        cout << setw(4) << right << "5";
        cout << setw(4) << right << "6";
        cout << setw(4) << right << "7";
        cout << setw(4) << right << "8" << endl;

        cout << setw(3) << right << "9";
        cout << setw(4) << right << "10";
        cout << setw(4) << right << "11";
        cout << setw(4) << right << "12";
        cout << setw(4) << right << "13";
        cout << setw(4) << right << "14";
        cout << setw(4) << right << "15" << endl;

        cout << setw(3) << right << "16";
        cout << setw(4) << right << "17";
        cout << setw(4) << right << "18";
        cout << setw(4) << right << "19";
        cout << setw(4) << right << "20";
        cout << setw(4) << right << "21";
        cout << setw(4) << right << "22" << endl;

        cout << setw(3) << right << "23";
        cout << setw(4) << right << "24";
        cout << setw(4) << right << "25";
        cout << setw(4) << right << "26";
        cout << setw(4) << right << "27";
        cout << setw(4) << right << "28";
        cout << setw(4) << right << "29" << endl;

        cout << setw(3) << right << "30" << endl;

        break;

    }

    cout << "----------------------------" << endl;

    }
    
    else if (month == 2) // Si le user choisi 2 dans le mois (Fevrier), faire le suivant
    {
    
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
    {
        switch (PremierJourMois)
        {

        case 0:
            cout << "dim lun mar mer jeu ven sam" << endl;

            cout << setw(3) << right << "1";
            cout << setw(4) << right << "2";
            cout << setw(4) << right << "3";
            cout << setw(4) << right << "4";
            cout << setw(4) << right << "5";
            cout << setw(4) << right << "6";
            cout << setw(4) << right << "7" << endl;

            cout << setw(3) << right << "8";
            cout << setw(4) << right << "9";
            cout << setw(4) << right << "10";
            cout << setw(4) << right << "11";
            cout << setw(4) << right << "12";
            cout << setw(4) << right << "13";
            cout << setw(4) << right << "14" << endl;

            cout << setw(3) << right << "15";
            cout << setw(4) << right << "16";
            cout << setw(4) << right << "17";
            cout << setw(4) << right << "18";
            cout << setw(4) << right << "19";
            cout << setw(4) << right << "20";
            cout << setw(4) << right << "21" << endl;

            cout << setw(3) << right << "22";
            cout << setw(4) << right << "23";
            cout << setw(4) << right << "24";
            cout << setw(4) << right << "25";
            cout << setw(4) << right << "26";
            cout << setw(4) << right << "27";
            cout << setw(4) << right << "28" << endl;

            cout << setw(3) << right << "29" << endl;

            break;

        case 1:
            cout << "dim lun mar mer jeu ven sam" << endl;

            cout << setw(7) << right << "1";
            cout << setw(4) << right << "2";
            cout << setw(4) << right << "3";
            cout << setw(4) << right << "4";
            cout << setw(4) << right << "5";
            cout << setw(4) << right << "6" << endl;

            cout << setw(3) << right << "7";
            cout << setw(4) << right << "8";
            cout << setw(4) << right << "9";
            cout << setw(4) << right << "10";
            cout << setw(4) << right << "11";
            cout << setw(4) << right << "12";
            cout << setw(4) << right << "13" << endl;

            cout << setw(3) << right << "14";
            cout << setw(4) << right << "15";
            cout << setw(4) << right << "16";
            cout << setw(4) << right << "17";
            cout << setw(4) << right << "18";
            cout << setw(4) << right << "19";
            cout << setw(4) << right << "20" << endl;

            cout << setw(3) << right << "21";
            cout << setw(4) << right << "22";
            cout << setw(4) << right << "23";
            cout << setw(4) << right << "24";
            cout << setw(4) << right << "25";
            cout << setw(4) << right << "26";
            cout << setw(4) << right << "27" << endl;

            cout << setw(4) << right << "28";
            cout << setw(3) << right << "29" << endl;
            break;

        case 2:
            cout << "dim lun mar mer jeu ven sam" << endl;

            cout << setw(11) << right << "1";
            cout << setw(4) << right << "2";
            cout << setw(4) << right << "3";
            cout << setw(4) << right << "4";
            cout << setw(4) << right << "5" << endl;

            cout << setw(3) << right << "6";
            cout << setw(4) << right << "7";
            cout << setw(4) << right << "8";
            cout << setw(4) << right << "9";
            cout << setw(4) << right << "10";
            cout << setw(4) << right << "11";
            cout << setw(4) << right << "12" << endl;

            cout << setw(3) << right << "13";
            cout << setw(4) << right << "14";
            cout << setw(4) << right << "15";
            cout << setw(4) << right << "16";
            cout << setw(4) << right << "17";
            cout << setw(4) << right << "18";
            cout << setw(4) << right << "19" << endl;

            cout << setw(3) << right << "20";
            cout << setw(4) << right << "21";
            cout << setw(4) << right << "22";
            cout << setw(4) << right << "23";
            cout << setw(4) << right << "24";
            cout << setw(4) << right << "25";
            cout << setw(4) << right << "26" << endl;

            cout << setw(3) << right << "27";
            cout << setw(4) << right << "28";
            cout << setw(4) << right << "29" << endl;

            break;

        case 3:
            cout << "dim lun mar mer jeu ven sam" << endl;

            cout << setw(15) << right << "1";
            cout << setw(4) << right << "2";
            cout << setw(4) << right << "3";
            cout << setw(4) << right << "4" << endl;

            cout << setw(3) << right << "5";
            cout << setw(4) << right << "6";
            cout << setw(4) << right << "7";
            cout << setw(4) << right << "8";
            cout << setw(4) << right << "9";
            cout << setw(4) << right << "10";
            cout << setw(4) << right << "11" << endl;

            cout << setw(3) << right << "12";
            cout << setw(4) << right << "13";
            cout << setw(4) << right << "14";
            cout << setw(4) << right << "15";
            cout << setw(4) << right << "16";
            cout << setw(4) << right << "17";
            cout << setw(4) << right << "18" << endl;

            cout << setw(3) << right << "19";
            cout << setw(4) << right << "20";
            cout << setw(4) << right << "21";
            cout << setw(4) << right << "22";
            cout << setw(4) << right << "23";
            cout << setw(4) << right << "24";
            cout << setw(4) << right << "25" << endl;

            cout << setw(3) << right << "26";
            cout << setw(4) << right << "27";
            cout << setw(4) << right << "28";
            cout << setw(4) << right << "29" << endl;

            break;

        case 4:
            cout << "dim lun mar mer jeu ven sam" << endl;

            cout << setw(19) << right << "1";
            cout << setw(4) << right << "2";
            cout << setw(4) << right << "3" << endl;

            cout << setw(3) << right << "4";
            cout << setw(4) << right << "5";
            cout << setw(4) << right << "6";
            cout << setw(4) << right << "7";
            cout << setw(4) << right << "8";
            cout << setw(4) << right << "9";
            cout << setw(4) << right << "10" << endl;

            cout << setw(3) << right << "11";
            cout << setw(4) << right << "12";
            cout << setw(4) << right << "13";
            cout << setw(4) << right << "14";
            cout << setw(4) << right << "15";
            cout << setw(4) << right << "16";
            cout << setw(4) << right << "17" << endl;

            cout << setw(3) << right << "18";
            cout << setw(4) << right << "19";
            cout << setw(4) << right << "20";
            cout << setw(4) << right << "21";
            cout << setw(4) << right << "22";
            cout << setw(4) << right << "23";
            cout << setw(4) << right << "24" << endl;

            cout << setw(3) << right << "25";
            cout << setw(4) << right << "26";
            cout << setw(4) << right << "27";
            cout << setw(4) << right << "28";
            cout << setw(4) << right << "29" << endl;

            break;

        case 5:
            cout << "dim lun mar mer jeu ven sam" << endl;

            cout << setw(23) << right << "1";
            cout << setw(4) << right << "2" << endl;

            cout << setw(3) << right << "3";
            cout << setw(4) << right << "4";
            cout << setw(4) << right << "5";
            cout << setw(4) << right << "6";
            cout << setw(4) << right << "7";
            cout << setw(4) << right << "8";
            cout << setw(4) << right << "9" << endl;

            cout << setw(3) << right << "10";
            cout << setw(4) << right << "11";
            cout << setw(4) << right << "12";
            cout << setw(4) << right << "13";
            cout << setw(4) << right << "14";
            cout << setw(4) << right << "15";
            cout << setw(4) << right << "16" << endl;

            cout << setw(3) << right << "17";
            cout << setw(4) << right << "18";
            cout << setw(4) << right << "19";
            cout << setw(4) << right << "20";
            cout << setw(4) << right << "21";
            cout << setw(4) << right << "22";
            cout << setw(4) << right << "23" << endl;

            cout << setw(3) << right << "24";
            cout << setw(4) << right << "25";
            cout << setw(4) << right << "26";
            cout << setw(4) << right << "27";
            cout << setw(4) << right << "28";
            cout << setw(4) << right << "29" << endl;

            break;

        case 6:
            cout << "dim lun mar mer jeu ven sam" << endl;

            cout << setw(27) << right << "1" << endl;

            cout << setw(3) << right << "2";
            cout << setw(4) << right << "3";
            cout << setw(4) << right << "4";
            cout << setw(4) << right << "5";
            cout << setw(4) << right << "6";
            cout << setw(4) << right << "7";
            cout << setw(4) << right << "8" << endl;

            cout << setw(3) << right << "9";
            cout << setw(4) << right << "10";
            cout << setw(4) << right << "11";
            cout << setw(4) << right << "12";
            cout << setw(4) << right << "13";
            cout << setw(4) << right << "14";
            cout << setw(4) << right << "15" << endl;

            cout << setw(3) << right << "16";
            cout << setw(4) << right << "17";
            cout << setw(4) << right << "18";
            cout << setw(4) << right << "19";
            cout << setw(4) << right << "20";
            cout << setw(4) << right << "21";
            cout << setw(4) << right << "22" << endl;

            cout << setw(3) << right << "23";
            cout << setw(4) << right << "24";
            cout << setw(4) << right << "25";
            cout << setw(4) << right << "26";
            cout << setw(4) << right << "27";
            cout << setw(4) << right << "28";
            cout << setw(4) << right << "29" << endl;

            break;

        }

       
    }

    else
    {

    switch (PremierJourMois)
    {

    case 0:
        cout << "dim lun mar mer jeu ven sam" << endl;

        cout << setw(3) << right << "1";
        cout << setw(4) << right << "2";
        cout << setw(4) << right << "3";
        cout << setw(4) << right << "4";
        cout << setw(4) << right << "5";
        cout << setw(4) << right << "6";
        cout << setw(4) << right << "7" << endl;

        cout << setw(3) << right << "8";
        cout << setw(4) << right << "9";
        cout << setw(4) << right << "10";
        cout << setw(4) << right << "11";
        cout << setw(4) << right << "12";
        cout << setw(4) << right << "13";
        cout << setw(4) << right << "14" << endl;

        cout << setw(3) << right << "15";
        cout << setw(4) << right << "16";
        cout << setw(4) << right << "17";
        cout << setw(4) << right << "18";
        cout << setw(4) << right << "19";
        cout << setw(4) << right << "20";
        cout << setw(4) << right << "21" << endl;

        cout << setw(3) << right << "22";
        cout << setw(4) << right << "23";
        cout << setw(4) << right << "24";
        cout << setw(4) << right << "25";
        cout << setw(4) << right << "26";
        cout << setw(4) << right << "27";
        cout << setw(4) << right << "28" << endl;

        break;

    case 1:
        cout << "dim lun mar mer jeu ven sam" << endl;

        cout << setw(7) << right << "1";
        cout << setw(4) << right << "2";
        cout << setw(4) << right << "3";
        cout << setw(4) << right << "4";
        cout << setw(4) << right << "5";
        cout << setw(4) << right << "6" << endl;

        cout << setw(3) << right << "7";
        cout << setw(4) << right << "8";
        cout << setw(4) << right << "9";
        cout << setw(4) << right << "10";
        cout << setw(4) << right << "11";
        cout << setw(4) << right << "12";
        cout << setw(4) << right << "13" << endl;

        cout << setw(3) << right << "14";
        cout << setw(4) << right << "15";
        cout << setw(4) << right << "16";
        cout << setw(4) << right << "17";
        cout << setw(4) << right << "18";
        cout << setw(4) << right << "19";
        cout << setw(4) << right << "20" << endl;

        cout << setw(3) << right << "21";
        cout << setw(4) << right << "22";
        cout << setw(4) << right << "23";
        cout << setw(4) << right << "24";
        cout << setw(4) << right << "25";
        cout << setw(4) << right << "26";
        cout << setw(4) << right << "27";

        cout << setw(4) << right << "28" << endl;
        break;

    case 2:
        cout << "dim lun mar mer jeu ven sam" << endl;

        cout << setw(11) << right << "1";
        cout << setw(4) << right << "2";
        cout << setw(4) << right << "3";
        cout << setw(4) << right << "4";
        cout << setw(4) << right << "5" << endl;

        cout << setw(3) << right << "6";
        cout << setw(4) << right << "7";
        cout << setw(4) << right << "8";
        cout << setw(4) << right << "9";
        cout << setw(4) << right << "10";
        cout << setw(4) << right << "11";
        cout << setw(4) << right << "12" << endl;

        cout << setw(3) << right << "13";
        cout << setw(4) << right << "14";
        cout << setw(4) << right << "15";
        cout << setw(4) << right << "16";
        cout << setw(4) << right << "17";
        cout << setw(4) << right << "18";
        cout << setw(4) << right << "19" << endl;

        cout << setw(3) << right << "20";
        cout << setw(4) << right << "21";
        cout << setw(4) << right << "22";
        cout << setw(4) << right << "23";
        cout << setw(4) << right << "24";
        cout << setw(4) << right << "25";
        cout << setw(4) << right << "26" << endl;

        cout << setw(3) << right << "27";
        cout << setw(4) << right << "28" << endl;
        break;

    case 3:
        cout << "dim lun mar mer jeu ven sam" << endl;

        cout << setw(15) << right << "1";
        cout << setw(4) << right << "2";
        cout << setw(4) << right << "3";
        cout << setw(4) << right << "4" << endl;

        cout << setw(3) << right << "5";
        cout << setw(4) << right << "6";
        cout << setw(4) << right << "7";
        cout << setw(4) << right << "8";
        cout << setw(4) << right << "9";
        cout << setw(4) << right << "10";
        cout << setw(4) << right << "11" << endl;

        cout << setw(3) << right << "12";
        cout << setw(4) << right << "13";
        cout << setw(4) << right << "14";
        cout << setw(4) << right << "15";
        cout << setw(4) << right << "16";
        cout << setw(4) << right << "17";
        cout << setw(4) << right << "18" << endl;

        cout << setw(3) << right << "19";
        cout << setw(4) << right << "20";
        cout << setw(4) << right << "21";
        cout << setw(4) << right << "22";
        cout << setw(4) << right << "23";
        cout << setw(4) << right << "24";
        cout << setw(4) << right << "25" << endl;

        cout << setw(3) << right << "26";
        cout << setw(4) << right << "27";
        cout << setw(4) << right << "28" << endl;
        break;

    case 4:
        cout << "dim lun mar mer jeu ven sam" << endl;

        cout << setw(19) << right << "1";
        cout << setw(4) << right << "2";
        cout << setw(4) << right << "3" << endl;

        cout << setw(3) << right << "4";
        cout << setw(4) << right << "5";
        cout << setw(4) << right << "6";
        cout << setw(4) << right << "7";
        cout << setw(4) << right << "8";
        cout << setw(4) << right << "9";
        cout << setw(4) << right << "10" << endl;

        cout << setw(3) << right << "11";
        cout << setw(4) << right << "12";
        cout << setw(4) << right << "13";
        cout << setw(4) << right << "14";
        cout << setw(4) << right << "15";
        cout << setw(4) << right << "16";
        cout << setw(4) << right << "17" << endl;

        cout << setw(3) << right << "18";
        cout << setw(4) << right << "19";
        cout << setw(4) << right << "20";
        cout << setw(4) << right << "21";
        cout << setw(4) << right << "22";
        cout << setw(4) << right << "23";
        cout << setw(4) << right << "24" << endl;

        cout << setw(3) << right << "25";
        cout << setw(4) << right << "26";
        cout << setw(4) << right << "27";
        cout << setw(4) << right << "28" << endl;
        break;

    case 5:
        cout << "dim lun mar mer jeu ven sam" << endl;

        cout << setw(23) << right << "1";
        cout << setw(4) << right << "2" << endl;

        cout << setw(3) << right << "3";
        cout << setw(4) << right << "4";
        cout << setw(4) << right << "5";
        cout << setw(4) << right << "6";
        cout << setw(4) << right << "7";
        cout << setw(4) << right << "8";
        cout << setw(4) << right << "9" << endl;

        cout << setw(3) << right << "10";
        cout << setw(4) << right << "11";
        cout << setw(4) << right << "12";
        cout << setw(4) << right << "13";
        cout << setw(4) << right << "14";
        cout << setw(4) << right << "15";
        cout << setw(4) << right << "16" << endl;

        cout << setw(3) << right << "17";
        cout << setw(4) << right << "18";
        cout << setw(4) << right << "19";
        cout << setw(4) << right << "20";
        cout << setw(4) << right << "21";
        cout << setw(4) << right << "22";
        cout << setw(4) << right << "23" << endl;

        cout << setw(3) << right << "24";
        cout << setw(4) << right << "25";
        cout << setw(4) << right << "26";
        cout << setw(4) << right << "27";
        cout << setw(4) << right << "28" << endl;
        break;

    case 6:
        cout << "dim lun mar mer jeu ven sam" << endl;

        cout << setw(27) << right << "1" << endl;

        cout << setw(3) << right << "2";
        cout << setw(4) << right << "3";
        cout << setw(4) << right << "4";
        cout << setw(4) << right << "5";
        cout << setw(4) << right << "6";
        cout << setw(4) << right << "7";
        cout << setw(4) << right << "8" << endl;

        cout << setw(3) << right << "9";
        cout << setw(4) << right << "10";
        cout << setw(4) << right << "11";
        cout << setw(4) << right << "12";
        cout << setw(4) << right << "13";
        cout << setw(4) << right << "14";
        cout << setw(4) << right << "15" << endl;

        cout << setw(3) << right << "16";
        cout << setw(4) << right << "17";
        cout << setw(4) << right << "18";
        cout << setw(4) << right << "19";
        cout << setw(4) << right << "20";
        cout << setw(4) << right << "21";
        cout << setw(4) << right << "22" << endl;

        cout << setw(3) << right << "23";
        cout << setw(4) << right << "24";
        cout << setw(4) << right << "25";
        cout << setw(4) << right << "26";
        cout << setw(4) << right << "27";
        cout << setw(4) << right << "28" << endl;
        break;

    }

        cout << "----------------------------" << endl;

    }

    }
} 






