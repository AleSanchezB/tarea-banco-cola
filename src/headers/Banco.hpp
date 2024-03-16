#ifndef BANK_HPP
#define BANK_HPP

#include "Queue.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <vector>
#include <fstream>

class Bank {
private:
    int cant_cajas;
    struct Client {
    public:
        Client();
        Client(std::string n);         
        int start_time_atention;
        std::string name;
        void setStartTime(int);
    };

    int add_rand_client;
    int client_name_rand;

    bool* available_modules = new bool[3];
    Queue<Client*>* attended_clients = new Queue<Client*>[3];
    Queue<Client> waiting_line;
    Client *modules = new Client[3];
    int* modules_attention_time;
    
public:
    Bank(Queue<Client*>*,Queue<Client>, Client*, bool*);
    ~Bank();
    void assignClientModule(int);
    void print(Client*, int);
    void printBox();
    void probarFuncion(void (*func)());
    void clearScreen();
    void update(int, std::string);
friend std::ostream &operator<<(std::ostream &os, const Client &A);
};

#endif
