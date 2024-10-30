#ifndef COMPTE_BANCAIRE_H
#define COMPTE_BANCAIRE_H
#pragma once
#include <string>
#include <vector>
#include <limits>
#include <iostream>
class Compte_bancaire
{
    public:
        Compte_bancaire();
       // virtual ~Compte_bancaire();

    protected:

    private:
};


class Client {
public:
    int idClient;
    std::string nom;
    std::string prenom;

    Client(int id, const std::string& n, const std::string& p) : idClient(id), nom(n), prenom(p) {}

    void afficherInfos() const {
        std::cout << "ID Client: " << idClient
                  << "\nNom: " << nom
                  << "\nPrenom: " << prenom << std::endl;
    }


// Méthode pour supprimer un client
void supprimerClient() {
    int id;
    std::cout << "Entrer l'ID du client à supprimer: ";
    std::cin >> id;


    // Recherche du client
   for (auto it = clients.begin(); it != clients.end(); ++it) {
        if (it->getId() == id) {
            // Suppression des comptes liés
            comptes.erase(std::remove_if(comptes.begin(), comptes.end(),
                [&id](const CompteBancaire& compte) { return compte.getTitulaireId() == id; }),
                comptes.end());


            // Suppression du client
            clients.erase(it);
            std::cout << "Client et ses comptes supprimés avec succès.\n";
            return;
        }
    }
    std::cout << "Client non trouvé.\n";
}

};



class CompteBancaire {
public:
    Client* titulaire;
    float solde;

    CompteBancaire(Client* client) : titulaire(client), solde(0.0) {}

    void deposerArgent(float montant) ; // procedure

    void retirerArgent(float montant) ;


    void afficherSolde() const { // fonctions
        std::cout << "Solde du compte pour " << titulaire->nom << ": " << solde << " EUR.\n";
    }

    void afficherCompte() const {
    std::cout << "Numéro de compte: " << numCompte << std::endl;
              << "Nom du titulaire: " << titulaire->nom << std::endl;
              << "Prénom du titulaire: " << titulaire->prenom << std::endl;
              << "Solde: " << solde << std::endl;
}

};


class Banque {
private:
    std::vector<Client> clients;
    std::vector<CompteBancaire> comptes;
    std::vector<Client> clients;  // Liste des clients

public:
    // Méthode pour ajouter un client
    void ajouterClient() ;


    void afficherClients() const {
        for (const auto& client : clients) {
            client.afficherInfos();
        }
    }

    void gererComptes();



 // Méthode pour supprimer un compte
void supprimerCompte() {
    int numCompte;
    std::cout << "Entrer le numéro du compte à supprimer: ";
    std::cin >> numCompte;


    // Recherche et suppression du compte
    for (auto it = comptes.begin(); it != comptes.end(); ++it) {
        if (it->getNumCompte() == numCompte) {
            comptes.erase(it);
            std::cout << "Compte supprimé avec succès.\n";
            return;
        }
    }
    std::cout << "Compte non trouvé.\n";
}

};



#endif // COMPTE_BANCAIRE_H
