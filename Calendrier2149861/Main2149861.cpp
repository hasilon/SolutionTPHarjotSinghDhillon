// But : Afficher un calendrier avec les jours de la semaine, mois par mois en utilisant les fonctions
// Le programme affiche un menu offrant les choix suivants :
// 1. Afficher les informations d'un mois et d'une ann�e donn�e
// 2. Afficher le calendrier d'un mois et d'une ann�e donn�e
// 3. Afficher le calendrier du mois pr�c�dent, du mois courant et du mois suivant d'un mois et d'une ann�e donn�e
// 4. Afficher le calendrier complet d'une ann�e donn�e

// Auteur : Dhillon, Harjot Singh
// Date : 2021-10-21

#include <iostream>
#include <string>
#include "Fonctions2149861.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    // D�claration des variables
    char choix;
    int annee = 0;
    int mois = 0;

   // Fonction qui affiche le menu de choix
      afficherMenu();
   // Fonction qui sauvegarde et valide le choix du user
      choix = validerChoixMenu('1', '5');

      while (choix != '5')
      {
          // Fonction qui demande et valide l'annee entrer par le user
          annee = demanderAnnee(annee);

          // Si le choix est different que 4, faire le suivant 
          if (choix != '4')
          {
              mois = demanderMois(mois); // Executer la fonction "demanderMois" et stocker son resultat dans mois
          }

          afficherInfoMois(mois, annee);

      }



    


   

    system("pause");
    return 0;
}