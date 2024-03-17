#include <iostream>

//****************************************************************************
template <typename T> Queue<T>::Queue() : _size(0), found(nullptr) {}

//****************************************************************************
template <typename T> Queue<T>::~Queue() { clear(); }

//****************************************************************************
template <typename T>
Queue<T>::Queue(const Queue<T> &s) : found(nullptr), _size(0) {
    *this = s;
}

//****************************************************************************
template <typename T> Queue<T> &Queue<T>::operator=(const Queue<T> &q) {
    if (this == &q)
        return *this;
    clear();
    if (!q.isEmpty()) {         
        Element *now = q.front->next;
        while (now != nullptr) {
            push(now->value);
            now = now->next;
        }
    }
    _size = q._size;
    return *this;
}

//****************************************************************************
template <typename T> void Queue<T>::push(T value) {
    try {
        //(isEmpty() ? front : found->next) = found = new Element(value);
        Element* new_;
        if (!isEmpty()) {
            new_ = new Element(value, found->next);
            found->next = new_;
        }
        else
            new_ = new Element(value);
        found = new_;
        ++_size;
        if(_size == 1) found->next = found;
    } catch (std::bad_alloc &) {
        throw "Error: it's not possible to push the value onto the queue.";
    }
}

//****************************************************************************
template <typename T> void Queue<T>::pop() {
    if (isEmpty())
        throw "Error: The queue is empty.";
    Element *aux = found->next;
    found->next = aux->next;
    if(_size == 1) found = nullptr;
    delete aux;
    --_size;
}

//****************************************************************************
template <typename T> void Queue<T>::clear() {
    while (!isEmpty())
        pop();
}

//****************************************************************************
template <typename T> T Queue<T>::getFront() const {
    if (isEmpty())
        throw "Error: The queue is empty.";
    return found->next->value;
}

//****************************************************************************
template <typename T> T Queue<T>::getFound() const {
    if (isEmpty())
        throw "Error: The queue is empty.";
    return found->value;
}

//****************************************************************************
template <typename T> int Queue<T>::size() const { return _size; }

//****************************************************************************
template <typename T> bool Queue<T>::isEmpty() const { return _size == 0; }

//****************************************************************************
template <typename T> void Queue<T>::print() const {
    if (isEmpty())
        throw "Error: The queue is empty.";
    Element *aux;
    aux = found->next;
    std::cout << aux->value << std::endl;
    aux = aux->next;
    while (aux != found->next) {
        std::cout << aux->value << std::endl;
        aux = aux->next;
    }
}

//****************************************************************************
//internal method of the queue.
template <typename T>
Queue<T>::Element::Element(T v, Queue<T>::Element *next_)
: value(v), next(next_) {}
//****************************************************************************
