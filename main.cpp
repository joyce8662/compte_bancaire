#include <iostream>
#pragma once
#include <string>
#include"Compte_bancaire.h"
using namespace std;
#include <vector>
#include <string>

int main()
{
   Banque banque;  // Cr�e une instance de Banque

    std::cout << "Bienvenue dans le syst�me de gestion bancaire.\n";
    banque.ajouterClient();  // Appelle la m�thode pour ajouter un client
    banque.afficherClients();
    banque.gererComptes();


    // Pour continuer � g�rer d'autres op�rations, vous pouvez ajouter un menu ici
    return 0;
}

