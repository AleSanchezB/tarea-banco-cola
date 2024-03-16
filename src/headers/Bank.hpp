/**
 * \file Bank.hpp
 * \brief Implementacion de la clase Banco
 * \author Braulio Alessandro Sánchez Bermúdez
 * \author Carlos Enrique Mancillas Duran
 * \date 16/03/2024
 * */

#ifndef BANK_HPP
#define BANK_HPP
#include "Queue.hpp"

/**
 * \class Bank
 * \brief Clase Banco que simula las filas y colas de un Banco, asignando clientes a la lista de
 espera para posteriormente asignarlos a la caja correspondiente.
 *
 */

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
    /**
     * \brief Construtor por defecto que inicializa un objeto de clase Bank.
     * \param Client* Puntero a una cola de los clientes attendidos.
     * \param Client Cola con la lista de espera.
     * \param bool puntero a un booleano que decide si la caja esta disponible o no.
     */
    Bank(Queue<Client>*, Queue<Client>, Client *, bool *);

    /**
     * \brief Constructor por defecto que inicializa un objeto de clase Bank.
     * \param int El tiempo en el que esta abierto el banco.
     */
    Bank(int );

    /**
     * \brief Destructor que libera la memoria del objeto Bank.
     */
    ~Bank();

    /**
     * \brief Assigna cliente a modulo disponible.
     * \param int Checa que modulo (0,1,2) esta disponible
     * \param int Asigna el tiempo en el que empezo la atención al cliente
     */
    void assignClientModule(int, int);

    /**
     * \brief Imprime los clientes que fueron atendidos en cada queja y los que quedaron en la lista
     de espera.
     */
    void close();

    /**
     * \brief Imprime el nombre de la persona que esta haciendo atendida por caja.
     * \param Client persona que esta siendo atendida.
     * \param int tiempo actual en el que la persona empezo a ser atendida.
     */
    void print(Client, int);

    void printBox();
    void probarFuncion(void (*func)());

    /**
     * \brief Limpia la terminal.
     */
    void clearScreen();

    /**
     * \brief Metodo que agrega a la lista de espera el nombre del cliente.
     * \param int Tiempo actual en la que la persona llega al banco.
     * \param string Nombre de la persona.
     */
    void update(int, std::string);

    /**
     * \brief Verifica si la caja o mdulo esta disponible.
     * \param int Tiempo transcurrido.
     * \param int Número de caja.
     */
    void verifyAttentionClient(int,int);

    /**
     * \brief Sobrecarga para el operador de inserción.
     * @param os Salida de flujo.
     * @param A Cliente que recibe para imrprimir nombre.
     * @return Retorna la salida de flujo para imprimir nombre.
     */
friend std::ostream &operator<<(std::ostream &os, const Client &A);
};

#endif
