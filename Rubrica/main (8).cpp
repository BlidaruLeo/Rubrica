#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ofstream rubrica;

struct data_nascita {
    int giorno;
    int mese;
    int anno;
};

struct dati_anagrafici {
    string nome;
    string cognome;
    data_nascita data;
    string indirizzo;
    int numero_telefonico;
};

void inserisciContatto(dati_anagrafici contatto[], int& numero_contatti);
void modificaContatto(dati_anagrafici contatto[], int numero_contatti);

int main() {
    int scelta;
    dati_anagrafici contatto[150];
    int numero_contatti = 0;

    cout << "GESTIONE CONTATTI TELEFONICI" << endl;
    cout << R"(
    1 - Inserimento contatto
    2 - Modifica dati contatto
    3 - Ricerca contatto per cognome
    4 - Ricerca contatto per cellulare
    5 - Cancella contatto
    6 - Riordino contatti per cognome
    7 - Riordino contatti per cellulare
    8 - Svuota rubrica
    9 - Salva rubrica
    U - Uscita)" << endl;

    cout << "Che cosa vuoi fare?" << endl;
    cin >> scelta;
    fflush(stdin);

    switch (scelta) {
        case 1:
            inserisciContatto(contatto, numero_contatti);
            break;
        case 2:
            modificaContatto(contatto, numero_contatti);
            break;

    };

    return 0;
}

void inserisciContatto(dati_anagrafici contatto[], int& numero_contatti) {
    char scelta2;

            rubrica.open("rubrica.txt");

    for (int i = numero_contatti; i < 150; i++) {
        cout << "Inserisci il nome" << endl;
        getline(cin, contatto[i].nome);
        cout << "Inserisci il cognome" << endl;
        getline(cin, contatto[i].cognome);
        cout << "Inserisci il giorno, il mese e l'anno di nascita" << endl;
        cin >> contatto[i].data.giorno >> contatto[i].data.mese >> contatto[i].data.anno;
        fflush(stdin);
        cout << "Inserisci l'indirizzo" << endl;
        getline(cin, contatto[i].indirizzo);
        cout << "Inserisci il numero telefonico" << endl;
        cin >> contatto[i].numero_telefonico;
        cout << "Vuoi inserire un altro contatto? s/n" << endl;
        cin >> scelta2;
        fflush(stdin);


        rubrica << contatto[i].nome << endl;
        rubrica << contatto[i].cognome << endl;
        rubrica << contatto[i].data.giorno << endl;
        rubrica << contatto[i].data.mese << endl;
        rubrica << contatto[i].data.anno << endl;
        rubrica << contatto[i].indirizzo << endl;
        rubrica << contatto[i].numero_telefonico << endl;
        rubrica << endl;


        if (scelta2 == 'n') {
            break;
        }
        numero_contatti++;
    }
            rubrica.close();
}

void modificaContatto(dati_anagrafici contatto[], int numero_contatti) {
    int numero;
    bool trovato = false;

    cout << "Inserisci il numero del contatto da modificare: ";
    cin >> numero;
    fflush(stdin);

    for (int i = 0; i < numero_contatti; i++) {
        if (contatto[i].numero_telefonico == numero) {
            trovato = true;

            cout << "Nuovo cognome: ";
            getline(cin, contatto[i].cognome);

            cout << "Nuovo nome: ";
            getline(cin, contatto[i].nome);

            cout << "Nuovo numero telefonico: ";
            cin >> contatto[i].numero_telefonico;

            cout << "Inserisci la nuova data di nascita (gg mm aaaa): ";
            cin >> contatto[i].data.giorno >> contatto[i].data.mese >> contatto[i].data.anno;
            fflush(stdin);

            cout << "Nuovo indirizzo: ";
            getline(cin, contatto[i].indirizzo);

            cout << "Contatto aggiornato.\n";
            break;
        }
    }

    if (!trovato) {
        cout << "Contatto non trovato.\n";
        return;
    }

        rubrica.open("rubrica.txt");
    for (int i = 0; i < numero_contatti; i++) {
        rubrica << contatto[i].nome << endl;
        rubrica << contatto[i].cognome << endl;
        rubrica << contatto[i].data.giorno << endl;
        rubrica << contatto[i].data.mese << endl;
        rubrica << contatto[i].data.anno << endl;
        rubrica << contatto[i].indirizzo << endl;
        rubrica << contatto[i].numero_telefonico << endl;
        rubrica << endl;
    }
            rubrica.close();
      }


void ricercaPerCognome(dati_anagrafici contatto[], int numero_contatti) {
    string cognome_cercato;
    bool trovato = false;

    cout<< "inserire il Cognome da ricercare " << endl;
    getline(cin, cognome_cercato);

    for(int i = 0; i < numero_contatti; i++) {
        if (cognome_cercato == contatto[i].cognome) {
            cout << " Contatto trovato " << endl;
            cout << " Nome " << contatto[i].nome << endl;
            cout << " Cognome " << contatto[i].cognome << endl;
            cout << " Data di nascita " << contatto[i].data.giorno << contatto[i].data.mese << contatto[i].data.anno << endl;
            cout << " Indirizzo " << contatto[i].indirizzo << endl;
            cout << " Numero telefonico " << contatto[i].numero_telefonico << endl;
        }
    }
}
