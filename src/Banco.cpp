#include "headers/Banco.hpp"

#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <vector>
#include <fstream>

Banco::Client::Client() {}

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


void Banco::openBank() {
    
}
