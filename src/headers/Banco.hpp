#ifndef BANCO_HPP
#define BANCO_HPP

#include "Queue.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <vector>
#include <fstream>

class Banco {
private:
    int cant_cajas;
    struct Client {
    public:
        Client();
        Client(std::string n, int wt);
        int atention_time;
        int start_time_atention;
        std::string name;
        void setStartTime(int);
    };

    int add_rand_client;
    int client_name_rand;

    bool cajas_ocupada[3] = {false, false, false};
    Queue<Client*>* cajas;
    Queue<Client*> cola_espera;
    Client *cajas_banco;
    bool* cajas_ocupadas;
    
public:
    Banco(Queue<Client*>*,Queue<Client*>, Client*, bool*);
    ~Banco();
    void openBank();
    void print(Client*, int);
    void printBox();
    void probarFuncion(void (*func)());
    void clearScreen();
friend std::ostream &operator<<(std::ostream &os, const Client &A);
};

#endif
