#include "Compte_bancaire.h"
#pragma once
#include <string>
#include <iostream>
using namespace std;

Compte_bancaire::Compte_bancaire()
{
    //ctor
}

Compte_bancaire::~Compte_bancaire()
{
    //dtor
}


Client::Client(int id, std::string nom, std::string prenom) // declaration constructeur
    : idClient(id), nom(nom), prenom(prenom), suivant(nullptr) {}

Client::~Client() {
    // Recursively delete the list
    delete suivant;
}



CompteBancaire::CompteBancaire(int numCompte, float solde, Client* titulaire)
    : numCompte(numCompte), solde(solde), titulaire(titulaire), suivant(nullptr) {}

CompteBancaire::~CompteBancaire() {
    delete suivant;
}


void CompteBancaire::deposerArgent(float montant) {
    solde += montant;
}


void CompteBancaire::retirerArgent(float montant) {
    if (montant > solde) {
        std::cout << "Fonds insuffisants!" << std::endl;
    } else {
        solde -= montant;
    }
}



 // M�thode pour supprimer un client
void Banque::supprimerClient() {
    int id;
    std::cout << "Entrer l'ID du client � supprimer: ";
    std::cin >> id;


    // Recherche du client
    for (auto it = clients.begin(); it != clients.end(); ++it) {
        if (it->getId() == id) {
            // Suppression des comptes li�s
            comptes.erase(std::remove_if(comptes.begin(), comptes.end(),
                [&id](const CompteBancaire& compte) { return compte.getTitulaireId() == id; }),
                comptes.end());


            // Suppression du client
            clients.erase(it);
            std::cout << "Client et ses comptes supprim�s avec succ�s.\n";
            return;
        }
    }
    std::cout << "Client non trouv�.\n";
}



void Banque::gererComptes() {
    int choix;
    do {
        std::cout << "1. D�poser\n  2. Retirer\n  3. Afficher Solde\n  4. Supprimer Compte\n  5. Retour\n";
        std::cout << "Choisissez une option: ";
        std::cin >> choix;

        switch (choix) {
            case 1:
                deposerArgent();
                break;
            case 2:
                retirerArgent();
                break;
            case 3:
                afficherSolde();
                break;
            case 4:
                supprimerCompte();
                break;
            case 5:
                return; // Retour au menu principal
        }
    } while (choix != 5);
}

void CompteBancaire::retirer(float montant) {
        if (montant > solde) {
            std::cout << "Fonds insuffisants!\n";
        } else {
            solde -= montant;
            std::cout << "Retrait r�ussi. Nouveau solde: " << solde << " EUR.\n";
        }
    }



void CompteBancaire::deposer(float montant) {
        solde += montant;
        std::cout << "D�p�t r�ussi. Nouveau solde: " << solde << " EUR.\n";
    }


    // M�thode pour ajouter un client
    void ajouterClient() {
        int id;
        std::string nom, prenom;

        std::cout << "Entrer l'ID du client: ";
        std::cin >> id;
        std::cin.ignore();  // Pour nettoyer le buffer apr�s la lecture de l'entier

        std::cout << "Entrer le nom du client: ";
        std::getline(std::cin, nom);

        std::cout << "Entrer le pr�nom du client: ";
        std::getline(std::cin, prenom);

        Client nouveauClient(id, nom, prenom);
        clients.push_back(nouveauClient);  // Ajoute le client � la liste

        std::cout << "Client ajout� avec succ�s.\n";
    }


     void gererComptes() {
        int choix;
        std::cout << "1. D�poser\n2. Retirer\n3. Afficher Solde\nChoisissez une option: ";
        std::cin >> choix;

        if (choix == 1 || choix == 2) {
            float montant;
            std::cout << "Entrer le montant: ";
            std::cin >> montant;
            // Ici, on suppose le compte � manipuler, simplification pour l'exemple
            if (choix == 1) {
                comptes.front().deposer(montant);
            } else {
                comptes.front().retirer(montant);
            }
        } else if (choix == 3) {
            comptes.front().afficherSolde();
        }
    }

