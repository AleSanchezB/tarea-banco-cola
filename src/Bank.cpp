#include "headers/Bank.hpp"

#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <vector>
#include <fstream>

Bank::Client::Client() {}

Bank::Bank(int TIME_OPEN_BANK){
    cant_cajas = 3;
    attended_clients = new Queue<Client>[3];
    modules = new Client[3];
    available_modules = new bool[3];
    modules_attention_time = new int[3];
    this->TIME_OPEN_BANK = TIME_OPEN_BANK;

    for(int i = 0; i < 3; ++i) available_modules[i] = false;
}

Bank::~Bank() {
    delete [] attended_clients;
    delete [] modules;
    delete [] available_modules;
    delete [] modules_attention_time;
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


void Bank::assignClientModule(int i, int current_time) {

    if (!waiting_line.isEmpty() && !available_modules[i]) {
        modules_attention_time[i] = rand() % 7 + 2;
        waiting_line.getFront().setStartTime(i);
        modules[i] = waiting_line.getFront();
        available_modules[i] = true;
        waiting_line.pop();
    }
    print(modules[i], current_time);
    
}

void Bank::verifyAttentionClient(int current_time, int caja_index) {
    if (!available_modules[caja_index])
        return;
                
    Client client = modules[caja_index];
    if (current_time - client.start_time_atention >= modules_attention_time[caja_index]){
        available_modules[caja_index] = false;
        attended_clients[caja_index].push(client);
        
        std::this_thread::sleep_for(std::chrono::seconds(1));
        print(modules[caja_index], current_time);    
    }
}
void Bank::update(int current_time, std::string name) {
    int add_client = rand() % 1 + 1;
    if (current_time % add_client == 0 || current_time % add_client != 0) {
        waiting_line.push(Client(name));
    }     
           
}
void Bank::print(Client client, int tiempo_actual) {
    Client c = client;
    clearScreen();

    std::cout << "Duracion: " << TIME_OPEN_BANK << std::endl;

    std::cout << "\n\nTiempo transcurrido: " << tiempo_actual << "\n\n" <<std::endl;
    
     for (int caja_index = 0; caja_index < 3; ++caja_index) {

         if (available_modules[caja_index]){

             std::cout << "En Caja " << caja_index << ": " << modules[caja_index].name << " tiempo de atencion: " << modules_attention_time[caja_index] << std::endl;
         }
         else std::cout << "En Caja " << caja_index << ": No hay nadie" << std::endl;
     }
    
     std::cout << "\nEspera: " << std::endl;
     if (!waiting_line.isEmpty())
         waiting_line.print();
}

void Bank::close() {
    for(int i = 0; i < 3; ++i){
        if (!attended_clients->isEmpty()) {
            std::cout << "\nAtendidos en caja " << i << ": " << std::endl;
            attended_clients[i].print();
        }
        std::cout << std::endl;
    }
    if (!waiting_line.isEmpty()) {
        std::cout << "\n\nEn espera quedaron: " << std::endl;
        waiting_line.print();
    }
}
void Bank::printBox(){}
void Bank::clearScreen() {
    system("clear");
}
