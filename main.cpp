#include <iostream>
#pragma once
#include <string>
#include"Compte_bancaire.h"
using namespace std;
#include <vector>
#include <string>

int main()
{
   Banque banque;  // Crée une instance de Banque

    std::cout << "Bienvenue dans le système de gestion bancaire.\n";
    banque.ajouterClient();  // Appelle la méthode pour ajouter un client
    banque.afficherClients();
    banque.gererComptes();


    // Pour continuer à gérer d'autres opérations, vous pouvez ajouter un menu ici
    return 0;
}

