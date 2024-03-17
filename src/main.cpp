#include "headers/Bank.hpp"
#include <iostream>
#include <new>
#include <vector>
#include <fstream>
#include "headers/Queue.hpp"
using namespace std;


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
    srand(time(nullptr));
    int TIEMPO_TOTAL = 10 // rand() % (240 - 120 + 1) + 120; .
    ;
 
    Bank bank(TIEMPO_TOTAL);
    std::string archivo = "src/nombres.txt";
    std::vector<std::string> names = leerNombresDesdeArchivo(archivo);

     try {
        for (int current_time = 0; current_time < TIEMPO_TOTAL; ++current_time) {
            bank.update(current_time, names[rand() % 100]);
            for (int i = 0; i < 3; ++i) {
                bank.assignClientModule(i, current_time);
                bank.verifyAttentionClient(current_time, i);
            }
        }
        bank.close();
    } catch (const char* &msg) {
        std::cout << msg << std::endl;
     } catch (std::bad_alloc& msg) {
         std::cerr << msg.what() << std::endl;
    }
    return 0;
}
