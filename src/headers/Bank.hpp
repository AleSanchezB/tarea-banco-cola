#ifndef BANK_HPP
#define BANK_HPP

#include "Queue.hpp"

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

    bool* available_modules;
    Queue<Client>* attended_clients;
    Queue<Client> waiting_line;
    Client *modules;
    int *modules_attention_time;
    int TIME_OPEN_BANK;
    
public:
    Bank(Queue<Client>*, Queue<Client>, Client *, bool *);
    Bank(int );
    ~Bank();
    void assignClientModule(int, int);
    void close();
    void print(Client, int);
    void printBox();
    void probarFuncion(void (*func)());
    void clearScreen();
    void update(int, std::string);
    void verifyAttentionClient(int,int);
friend std::ostream &operator<<(std::ostream &os, const Client &A);
};

#endif
