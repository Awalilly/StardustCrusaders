#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

void writeStats(){

    string username;

    string filename;

    username = "Matteo cicci";

    filename = username;

    filename.append("_Stats.txt");

    ifstream file_to_check_existance;   //per verificare l'esistenza del file

    file_to_check_existance.open(filename);

    if(!file_to_check_existance){
        //file_to_check_existance.close();
        cout << "File inesistente" << endl;
    }

    file_to_check_existance.close();

    fstream victories;

    victories.open(filename, ios::app);

    //ofstream victories (filename);

    bool prova = true;

    int k = 1;

    if(!prova){
        cout << "ueue" << prova;
    }

    for(int i = 0; i < 3; i ++){

        victories << prova << "\t" << !prova << endl;

    }

    victories.close();





}

void getStats(){

    string f_name;

    // Dichiaro i vettori da riempire
    vector<int> match;
    vector<int> mode;
    vector<int> n_hit;
    vector<int> n_miss;
    vector<int> kind;

    vector<int> temp1; //vettore che contiene gli indici da leggere
    vector<int> temp2;

    vector<float> precision;


    // Il file da aprire
    f_name = "cavallo";
    f_name.append("_Stats.txt");

    ifstream file_to_check_existance;

    file_to_check_existance.open(f_name);

    if(!file_to_check_existance){ //Se il file non esiste è perché l'utente non ha ancora mai giocato

        cout << "Non sono presenti dati sulle tue partite" << endl;
        cout << "Gioca una partita per registrare le tue statistiche" << endl;

    }else { //se il file esiste proseguiamo con la lettura

        ifstream file(f_name); //apro il file

        int games, type, num_hit, num_miss, m;

        // Leggi i dati dal file
        while (file >> games >> type >> num_hit >> num_miss >> m){
            // Crea dei vettori che vengono riempiti colonna per colonna
            match.push_back(games);
            mode.push_back(type);
            n_hit.push_back(num_hit);
            n_miss.push_back(num_miss);
            kind.push_back(m); // true normale, false fast
        }

        cout << "Il numero di partite giocate in totale  e' " << match.size() << endl;
        cout << "\n\n\n";

        for(int i = 0; i < mode.size(); i ++){
            if(mode [i] == 1){
                temp1.push_back(i); //riempio il vettore temp con gli indici che mi interessano per selezionare la modalità vs Human
            }else{
                temp2.push_back(i);
            }
        }

        int k = 0, j = 0;
        int Vs_Human[temp1.size()], Vs_CPU[temp1.size()], Kind_vsH[temp1.size()], Kind_vsC[temp2.size()]; //creo 2 array dalle dimensioni di temp1 e temp2

        for(int i = 0; i < temp1.size(); i++){
            k = temp1 [i]; //k assume il valore di temp1[i]
            Vs_Human [i] = match [k]; //riempio il vettore Vs Human
            Kind_vsH [i] = kind [k];
        }

        for(int i = 0; i < temp2.size(); i++){
            j = temp2 [i]; //j assume il valore di temp2[i]
            Vs_CPU [i] = match [j]; //riempio il vettore Vs CPU
            Kind_vsC [i] = kind [j];
        }

        //Per calcolare il numero di vincite

        int n_vic_Vs_H = 0;
        int n_vic_Vs_C = 0;
        int n_def_Vs_H = 0;
        int n_def_Vs_C = 0;

        int vic_normal_mode_Vs_H = 0;
        int vic_fast_mode_Vs_H = 0;
        int vic_normal_mode_Vs_C = 0;
        int vic_fast_mode_Vs_C = 0;


        float perc_vic_Vs_H = 0;
        float perc_vic_Vs_C = 0;
        float perc_vic_n_H = 0, perc_vic_f_H = 0;
        float perc_vic_n_C = 0, perc_vic_f_C = 0;

        int tot_Vic = 0;
        int tot_Def = 0;

        for(int i = 0; i < temp1.size(); i++){
            if(Vs_Human[i] == 1){

                n_vic_Vs_H++;

                if(Kind_vsH[i] == 1) //modalità normale
                    vic_normal_mode_Vs_H++;
                else                 //modalità fast
                    vic_fast_mode_Vs_H++;
            }else
                n_def_Vs_H++;
        }

        perc_vic_Vs_H = (n_vic_Vs_H /(double) temp1.size()) * 100;
        perc_vic_n_H = (vic_normal_mode_Vs_H /(double) n_vic_Vs_H) * 100;
        perc_vic_f_H = (vic_fast_mode_Vs_H /(double) n_vic_Vs_H) * 100;

        cout << "\n\n\n";
        cout << "In modalità multigiocatore hai vinto " << n_vic_Vs_H << " volte, mentre hai perso " << n_def_Vs_H << " volte" << endl;
        cout << "\n";
        cout << "La tua percentuale di vittoria in questa modalità e' pari al " << setprecision(4) << perc_vic_Vs_H << "%" << endl;
        cout << "\n";
        cout << "Giocando una partita classica la tua percentuale di vittoria e' pari al " << setprecision(4) << perc_vic_n_H << "%, mentre in modalità veloce " <<  setprecision(2) << perc_vic_f_H << "%" <<  endl;
        cout << "\n\n\n";


        for(int i = 0; i < temp2.size(); i++){
            if(Vs_CPU[i] == 1){

                n_vic_Vs_C++;

                if(Kind_vsC[i] == 1) //modalità normale
                    vic_normal_mode_Vs_C++;
                else                 //modalità fast
                    vic_fast_mode_Vs_C++;
            }
            else
                n_def_Vs_C++;
        }

        perc_vic_Vs_C = (n_vic_Vs_C /(double) temp2.size()) * 100;
        perc_vic_n_C = (vic_normal_mode_Vs_C /(double) n_vic_Vs_C) * 100;
        perc_vic_f_C = (vic_fast_mode_Vs_C /(double) n_vic_Vs_C) * 100;

        cout << Kind_vsC[1] << "    " <<vic_normal_mode_Vs_C << "  "<< perc_vic_n_C << endl;

        cout << "Hai vinto contro il computer " << n_vic_Vs_C << " volte, mentre sei stato sconfitto " << n_def_Vs_C << " volte" << endl;
        cout << "\n";
        cout << "La tua percentuale di vittoria in questa modalità e' pari al " << setprecision(4) << perc_vic_Vs_C << "%" << endl;
        cout << "\n";
        cout << "Hai vinto il " << setprecision(4) << perc_vic_n_C << "% giocando ad una partita classica e il " <<  setprecision(4) << perc_vic_f_C << "% in modalità veloce" <<  endl;

        cout << "\n\n\n";

        tot_Vic = n_vic_Vs_C + n_vic_Vs_H;
        tot_Def = match.size() - tot_Vic;

        cout << "In totale il numero di partite vinte e' " << tot_Vic << endl;
        cout << "\n";
        cout << "Il numero totale di sconfitte ricevute e' " << tot_Def << endl;
        cout << "\n\n\n";


    //Per calcolare la precisione di ogni giocatore

    //Precisione da una singola partita

        float x = 0, sum_precision = 0, main = 0;

        for(int i = 0; i < match.size(); i++){

            x = (n_hit [i])/(double)(n_hit [i] + n_miss [i]);
            precision.push_back(x);

        }

        for(int i = 0; i < precision.size(); i++){
            sum_precision = precision[i] + sum_precision;
        }

        main = ((sum_precision)/(double)(precision.size()) * 100);

        cout << "La tua precisione e' pari al " << setprecision(4) << main << "%" << endl;
        cout << "\n\n\n";
    }

    file_to_check_existance.close();




}

int main(){

    //writeStats();
    getStats();

    cout <<"\t\t\t\t\t\t  \033[1;35m  ___   __    ___ __  __ ____ ___    ____ ______ ___  ______ ____\033[0m\n";
    cout <<"\t\t\t\t\t\t \033[1;35m  / _ \\ / /   / _ |\\ \\/ // __// _ \\  / __//_  __// _ |/_  __// __/\033[0m\n";
    cout <<"\t\t\t\t\t\t \033[1;35m / ___// /__ / __ | \\  // _/ / , _/ _\\ \\   / /  / __ | / /  _\\ \\ \033[0m\n";
    cout <<"\t\t\t\t\t\t \033[1;35m/_/   /____//_/ |_| /_//___//_/|_| /___/  /_/  /_/ |_|/_/  /___/  \033[0m\n";


}
