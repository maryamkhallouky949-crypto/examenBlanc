#include <iostream>
#include <string>
using namespace std;

class CompteBancaire {
private:
    int numero;
    string titulaire;
    double solde;

public:
    // Constructeur
    CompteBancaire(int num, string tit, double s) {
        numero = num;
        titulaire = tit;
        solde = s;
    }

    void deposer(double montant) {
        if (montant > 0) {
            solde += montant;
            cout << "Depot de " << montant << " pour " << titulaire << endl;
        } else {
            cout << "Montant invalide !" << endl;
        }
    }

    void retirer(double montant) {
        if (montant > 0 && montant <= solde) {
            solde -= montant;
            cout << "Retrait de " << montant << " pour " << titulaire << endl;
        } else {
            cout << "Solde insuffisant ou montant invalide !" << endl;
        }
    }

    void afficher() const {
        
        cout << "Numero : " << numero << endl;
        cout << "Titulaire : " << titulaire << endl;
        cout << "Solde : " << solde << " DH" << endl;
    }     
};

int main() {
    
    CompteBancaire c1(101, "Ahmed", 5000);
    CompteBancaire c2(102, "Sara", 3000);

    
    c1.deposer(1500);  
    c2.retirer(1000); 

    // Affichage des soldes
    cout << "Etat final des comptes :" << endl;
    c1.afficher();
    c2.afficher();

    return 0;
}