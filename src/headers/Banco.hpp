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
    struct Client {
    public:
        Client();
        Client(std::string n, int wt);
        int atention_time;
        int start_time_atention;
        std::string name;
        void setStartTime(int);
        void openBank();
    };
public:
    Banco();
    ~Banco();
friend std::ostream &operator<<(std::ostream &os, const Client &A);
};

#endif
