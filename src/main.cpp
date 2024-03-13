#include "headers/Queue.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;


struct Client {
    friend std::ostream &operator<<(std::ostream &os, const Client &A);
public:
    Client();
    Client(std::string n, int wt);
    int atention_time;
    int start_time_atention;
    std::string name;
    void setStartTime(int);
    
};


Client::Client() {}

std::ostream & operator<<(std::ostream &out, const Client &c)
{

    out << c.name << std::endl;

    return out;
}
void Client::setStartTime(int time) { this->start_time_atention = time; }

Client::Client(std::string n, int at) {
        name = n;
        atention_time = at;         
}
void clearScreen() {
    system("clear");
}

std::vector<std::string> leerNombresDesdeArchivo(const std::string& nombreArchivo) {
    std::vector<std::string> nombres;
    std::ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            nombres.push_back(linea);
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << std::endl;
    }

    return nombres;
}

int main() {

    bool cajas_ocupada[3] = {false, false, false};
    Queue<Client> c1;
    Queue<Client> cola_espera;
    Client* caja = new Client[1];

    std::string archivo = "src/nombres.txt";
    std::vector<std::string> nombres = leerNombresDesdeArchivo(archivo);
    
    int TIEMPO_TOTAL = rand() % 240 + 120;
    
    cout << "Duracion: " << TIEMPO_TOTAL << endl;

    int client_rand, client_waiting_time, no_caja;
    try {
        for (int i = 0; i < 10; ++i) {             
            // Generar un número aleatorio entre 1 y 10
            int add_client = rand() % 5 + 1;

            client_rand = rand() % 100;


            no_caja = 0;

            if (i % add_client == 0) {
                client_waiting_time = rand() % 10 + 1;
                cola_espera.push(
                                 Client(nombres[client_rand], client_waiting_time));
            }

            switch (no_caja) {
                case 0:

                    if (!cajas_ocupada[0] && !cola_espera.isEmpty()){
                        cola_espera.getFront().setStartTime(i);
                        caja[no_caja] = cola_espera.getFront();
                        cajas_ocupada[0] = true;
                        cola_espera.pop();
                    }
                    break;
             }
            clearScreen();
            cout << "\n\nTiempo transcurrido: " << i << "\n\n" << endl;

            for (int caja_index = 0; caja_index < 1; ++caja_index) {
                if (cajas_ocupada[caja_index])
                    cout << "En Caja 1: \n" << caja[0].name << std::endl;
                else cout << "En Caja 1: No hay nadie \n" << std::endl;
            }

            cout << "\nEspera: " << std::endl;
            if (!cola_espera.isEmpty())
                cola_espera.print();

            
            for (int caja_index = 0; caja_index < 1; ++caja_index) {
                if (!cajas_ocupada[caja_index])
                    continue;
                
                Client client = caja[caja_index];
                if (i - client.start_time_atention >= client.atention_time){
                    cajas_ocupada[caja_index] = false;
                    c1.push(client);
                    cout << "\n\nTermino atencion a : " << client.name << endl;
                }
            }
            
            this_thread::sleep_for(chrono::seconds(1));
        }
        if (!c1.isEmpty()) {
            std::cout << "Atendidos en caja 1: " << std::endl;
            c1.print();
        }
        if (!cola_espera.isEmpty()) {
            std::cout << "\n\nEn espera quedaron: " << std::endl;
            cola_espera.print();
        }
        delete [] caja;
    } catch (const char* &msg) {
        std::cout << msg << std::endl;
    } 
    return 0;  
}
 
