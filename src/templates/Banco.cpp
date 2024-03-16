#include "../headers/Banco.hpp"

#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <vector>
#include <fstream>

Bank::Client::Client() {}

Bank::Bank(Queue<Client *> *attended_clients, Queue<Client> waiting_line,
             Client *modules, bool *available_modules)
: attended_clients(attended_clients), waiting_line(waiting_line), modules(modules), available_modules(available_modules) {
    cant_cajas = 3;
}

std::ostream & operator<<(std::ostream &out, const Bank::Client &c)
{

    out << c.name << std::endl;

    return out;
}
void Bank::Client::setStartTime(int time) { this->start_time_atention = time; }

Bank::Client::Client(std::string n) {
        name = n;
}


void Bank::assignClientModule(int i) {

    if (!waiting_line.isEmpty() && !available_modules[i]){    
        waiting_line.getFront().setStartTime(i);
        modules[i] = waiting_line.getFront();
        available_modules[i] = true;
        waiting_line.pop();
    }
}

void Bank::update(int current_time, std::string name) {
    int add_client = rand() % 5 + 1;
    if (current_time % add_client == 0 || current_time % add_client != 0) {
                waiting_line.push(Client(name));
    }
            
}
void Bank::print(Client client, int tiempo_actual) {
     clearScreen();
     std::cout << "\n\nTiempo transcurrido: " << tiempo_actual << "\n\n" <<std::endl;
    
     for (int caja_index = 0; caja_index < 3; ++caja_index) {
         if (available_modules[caja_index])
             std::cout << "En Caja " << caja_index << ": \n" << client.name << " tiempo de atencion: " << modules_attention_time[caja_index] << " inicio de atencion: " << client.start_time_atention << std::endl;
         else std::cout << "En Caja " << caja_index << ": No hay nadie \n" << std::endl;
     }
    
     std::cout << "\nEspera: " << std::endl;
     if (!waiting_line.isEmpty())
         waiting_line.print();
     std::cout << "\n\nTermino atencion a : " << client.name << std::endl;
}
void Bank::printBox(){}
void Bank::clearScreen() {
    system("clear");
}
