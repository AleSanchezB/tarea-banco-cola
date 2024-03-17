#include "headers/Bank.hpp"

#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iomanip>

Bank::Bank(int TIME_OPEN_BANK){
    cant_cajas = 3;
    attended_clients = new Queue<Client>[cant_cajas];
    modules = new Module[cant_cajas];
    available_modules = new bool[cant_cajas];
    this->TIME_OPEN_BANK = TIME_OPEN_BANK;

    for(int i = 0; i < cant_cajas; ++i) available_modules[i] = false;
}

Bank::~Bank() {
    delete [] attended_clients;
    delete [] modules;
    delete [] available_modules;
}

void Bank::assignClientModule(int module_index, int current_time) {
    if (!waiting_line.isEmpty() && !available_modules[module_index]) {
        modules[module_index].attention_time = rand() % 7 + 2;
        modules[module_index].client = waiting_line.getFront();
        available_modules[module_index] = true;
        modules[module_index].start_time_attention = current_time;
        waiting_line.pop();
    }
    print(current_time);
}

void Bank::verifyAttentionClient(int current_time, int module_index) {
    if (!available_modules[module_index])
        return;
                
    Client client = modules[module_index].client;
    if (current_time - modules[module_index].start_time_attention >=
       modules[module_index].attention_time) {         
        available_modules[module_index] = false;
        attended_clients[module_index].push(client);
        print(current_time);    
    }
}
void Bank::update(int current_time, Client name) {
    int add_client = rand() % 1 + 1;
    if (current_time % add_client == 0) {
        waiting_line.push(Client(name));
    }
    print(current_time);
           
}
void Bank::print(int current_time) {
    clearScreen();

    std::cout << "Duracion: " << TIME_OPEN_BANK << std::endl;

    std::cout << "\n\nTiempo transcurrido: " << current_time << "\n\n" <<std::endl;

    std::cout << std::left << std::setw(20) << "Cajas" << std::setw(20) << "Nombre" << std::setw(20)  << "Tiempo de Espera" << std::endl;

    for (int module_index = 0; module_index < cant_cajas; ++module_index) {
        std::cout << std::setfill('-') << std::setw(60) << "-" << std::endl;
        std::cout << std::setfill(' ');
        printBox(module_index);
     }
    
     std::cout << "\nEspera: " << std::endl;

     if (!waiting_line.isEmpty())
         waiting_line.print();
    
     std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Bank::close() {
    clearScreen();
    for (int i = 0; i < cant_cajas; ++i) {
        if(available_modules[i]){ attended_clients[i].push(modules[i].client); }

        if (!attended_clients->isEmpty()) {
            std::cout << "\nAtendidos en caja " << i +1  << ": " << std::endl;
            attended_clients[i].print();
        }
        std::cout << std::endl;
    }
    if (!waiting_line.isEmpty()) {
        std::cout << "\n\nEn espera quedaron: " << std::endl;
        waiting_line.print();
    }
}
void Bank::printBox(int module_index) {
     if (available_modules[module_index]){
        std::cout << std::left << "En Caja " << module_index + 1 << std::setw(11) << ": " << std::setw(20) << modules[module_index].client << std::setw(20) << " Tiempo de atencion: " << modules[module_index].attention_time << std::endl;
     }
     else std::cout << std::left << "En Caja " << module_index + 1 << std::setw(10) << ":" << std::setw(20) << " No hay nadie" << std::setw(20) << "Tiempo de atencion: 0" << std::endl;
}
void Bank::clearScreen() { system("clear"); }


/* METODOS DE LA ESTRUCTURA DE CLIENTES*/

Bank::Module::Module() {}

