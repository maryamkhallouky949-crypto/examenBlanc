#include <iostream>
#include <string>
using namespace std;

// 1. Classe mère avec attributs protégés
class Vehicule {
protected:
    string marque;
    string modele;
    int annee;

public:
    // 2. Constructeur paramétré
    Vehicule(string mar, string mod, int an) {
        marque = mar;
        modele = mod;
        annee = an;
    }

    
    virtual void afficherDetails() const {
        cout << "Vehicule: " << marque << " " << modele << " (" << annee << ")" << endl;
    }

    virtual ~Vehicule() {
        cout << "Destruction Vehicule: " << marque << endl;
    }
};

// 3. Classes dérivées
class Voiture : public Vehicule {
private:
    int nbPortes;

public:
    Voiture(string mar, string mod, int an, int portes) 
        : Vehicule(mar, mod, an) {
        nbPortes = portes;
    }

    // 4. Redéfinition
    void afficherDetails() const override {
        cout << "[Voiture] " << marque << " " << modele 
             << " (" << annee << ") - " << nbPortes << " portes" << endl;
    }
};

class Camion : public Vehicule {
private:
    double chargeMax; 

public:
    Camion(string mar, string mod, int an, double charge) 
        : Vehicule(mar, mod, an) {
        chargeMax = charge;
    }

    void afficherDetails() const override {
        cout << "[Camion] " << marque << " " << modele 
             << " (" << annee << ") - Charge max: " << chargeMax << " tonnes" << endl;
    }
};

// 5. Main 
int main() {
   
    Vehicule* parc[2];

    parc[0] = new Voiture("Dacia", "Logan", 2022, 5);
    parc[1] = new Camion("Volvo", "FH16", 2020, 25.5);

    cout << " Details du parc" << endl;
    for (int i = 0; i < 2; i++) {
        parc[i]->afficherDetails(); 
    }


    for (int i = 0; i < 2; i++) {
        delete parc[i];
    }

    return 0;
}