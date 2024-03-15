#include "../headers/Banco.hpp"

#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <vector>
#include <fstream>

Banco::Client::Client() {}

Banco::Banco(Queue<Client *> *cajas, Queue<Client *> cola_espera,
             Client *cajas_banco, bool *cajas_ocupadas)
: cajas(cajas), cola_espera(cola_espera), cajas_banco(cajas_banco), cajas_ocupadas(cajas_ocupadas) {
    cant_cajas = 3;
}

std::ostream & operator<<(std::ostream &out, const Banco::Client &c)
{

    out << c.name << std::endl;

    return out;
}
void Banco::Client::setStartTime(int time) { this->start_time_atention = time; }

Banco::Client::Client(std::string n, int at) {
        name = n;
        atention_time = at;         
}


void Banco::openBank() {}

void Banco::probarFuncion(void (*func)()) {
    
}

void Banco::print(Client* client, int tiempo_actual) {
     clearScreen();
     std::cout << "\n\nTiempo transcurrido: " << tiempo_actual << "\n\n" <<std::endl;
    
     for (int caja_index = 0; caja_index < 1; ++caja_index) {
         if (cajas_ocupada[caja_index])
             std::cout << "En Caja " << caja_index << ": \n" << client->name << " tiempo de atencion: " << client->atention_time << " inicio de atencion: " << client->start_time_atention << std::endl;
         else std::cout << "En Caja " << caja_index << ": No hay nadie \n" << std::endl;
     }
    
     std::cout << "\nEspera: " << std::endl;
     if (!cola_espera.isEmpty())
         cola_espera.print();
     std::cout << "\n\nTermino atencion a : " << client->name << std::endl;
}
void Banco::printBox(){}
void Banco::clearScreen() {
    system("clear");
}
