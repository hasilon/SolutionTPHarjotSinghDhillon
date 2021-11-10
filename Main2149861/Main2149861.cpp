// But : Afficher un calendrier avec les jours de la semaine, mois par mois en utilisant les fonctions
// Le programme affiche un menu offrant les choix suivants :
// 1. Afficher les informations d'un mois et d'une année donnée
// 2. Afficher le calendrier d'un mois et d'une année donnée
// 3. Afficher le calendrier du mois précédent, du mois courant et du mois suivant d'un mois et d'une année donnée
// 4. Afficher le calendrier complet d'une année donnée
// Auteur : Karine Moreau
// Date : 2021-10-14

#include "Fonctions2149861.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    // Déclaration des variables
    char choix;
    int annee;
    int mois;

    afficherMenu();
    choix = validerChoixMenu('1', '5');

    // Tant que le choix de l'utilisateur n'est pas de quitter, le programme recommence
    while (choix != '5')
   {
        // Dans tous les cas le programme doit demander une année
       annee = demanderAnnee();
        if (choix != '4')
            mois = demanderMois();
        // Selon le choix que l'utilisateur a fait, le programme appelle la bonne fonction
        switch (choix)
        {
        case '1':
            afficherInfoMois(annee, mois);
            break;
      /* case '2':
            afficherCalendrierMensuel(annee, mois, true, true);
            break;
        case '3':
            afficherCalendrierTrimestriel(annee, mois);
            break;
        case '4':
            afficherCalendrierAnnuel(annee);
            break; */
        }
        afficherMenu();
        choix = validerChoixMenu('1', '5'); 
    }
    system("pause");
    return 0;
}