/**
 * \file Queue.hpp
 * \brief Implementacíon de colas de Banco
 * \author Carlos Enrique Mancillas Duran
 * \author Braulio Alessandro S&aacute;nchez Berm&uacute;dez
 * \date 16/03/2024
 */
#include <iostream>
#ifndef QUEUE_HPP
#define QUEUE_HPP

/**
 * \class Queue
 * \brief Clase genérica de Queue que implementa operaciones b&aacute;sicas de
pila.
 *
 * Esta clase template ofrece una implementaci&oacute;n de pila con operaciones
para agregar,
 * eliminar elementos, y consultar el tope de la pila, entre otras.
 *
 * \tparam T Tipo de elementos almacenados en la pila.
 *
 *
 *
 * \code Ejemplo.cpp

\endverbatim
*
 */
template <typename T = int> class Queue {
public:
  /**
   * \brief Constructor por defecto que inicializa una pila vac&iacute;a.
   */
  explicit Queue();

  /**
   * \brief Constructor de copia.
   * \param p Otra pila de la cual se copiar&aacute;n los elementos.
   */
  Queue(const Queue &p);

  /**
   * \brief Sobrecarga del operador de asignaci&oacute;n.
   * \param p Otra pila de la cual se copiar&aacute;n los elementos.
   * \exception const <b>char *</b> La pila copia no puede ser creado.
   *
   * \return Referencia a la pila actual.
   */
  Queue &operator=(const Queue &p);

  /**
   * \brief Destructor que libera la memoria de la pila.
   */
  ~Queue();

  /**
   * \brief Agrega un nuevo elemento al tope de la pila.
   * \param valor El valor a agregar.
   */
  void push(T valor);

  /**
   * \brief Elimina el elemento del tope de la pila.
   */
  void pop();

  /**
   * \brief Obtiene el valor del tope de la pila sin eliminarlo.
   *
   * \exception const <b>char *</b> La pila está vacía.

   * \return El valor en el tope de la pila.
   */
  T getFront() const;

  T getFound() const;
  /**
   * \brief Vac&iacute;a la pila eliminando todos sus elementos.
   *
   * \exception const <b>char *</b> La pial está vacía.

   */
  void clear();

  /**
   * \brief Obtiene el tamaño actual de la pila, es decir, el n&uacute;mero de
   * elementos.
   * \return El n&uacute;mero de elementos en la pila.
   */
  int size() const;

  /**
   * \brief Verifica si la pila est&aacute; vac&iacute;a.
   * \return Verdadero si la pila est&aacute; vac&iacute;a, falso de lo
   * contrario.
   */
  bool isEmpty() const;

  /**
   * \brief Imprime todos los elementos de la pila, utilizado para pruebas.
   */
  void print() const;

private:
    int _size;

    struct Element {
        Element(T v, Element *next_ = nullptr);
        T value;
        Element *next;
    }* found;
};

#include "../templates/Queue.tpp"

#endif // QUEUE_HPP
