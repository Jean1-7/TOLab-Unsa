#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

#include <iostream>
#include <stdexcept>
#include <functional>

template <typename T>
class ListaEnlazada {
private:
    struct Nodo {
        T dato;
        Nodo* sig;
        Nodo(const T& d, Nodo* s = nullptr) : dato(d), sig(s) {}
    };
    Nodo* cabeza;
    size_t tam;

public:
    ListaEnlazada() : cabeza(nullptr), tam(0) {}
    ~ListaEnlazada() { limpiar(); }

    ListaEnlazada(const ListaEnlazada& other) : cabeza(nullptr), tam(0) {
        Nodo* curr = other.cabeza;
        Nodo** lastPtr = &cabeza;
        while (curr) {
            *lastPtr = new Nodo(curr->dato);
            lastPtr = &((*lastPtr)->sig);
            curr = curr->sig;
            ++tam;
        }
    }

    ListaEnlazada& operator=(const ListaEnlazada& other) {
        if (this == &other) return *this;
        limpiar();
        Nodo* curr = other.cabeza;
        Nodo** lastPtr = &cabeza;
        while (curr) {
            *lastPtr = new Nodo(curr->dato);
            lastPtr = &((*lastPtr)->sig);
            curr = curr->sig;
            ++tam;
        }
        return *this;
    }

    void insertarFinal(const T& valor) {
        Nodo** p = &cabeza;
        while (*p) p = &((*p)->sig);
        *p = new Nodo(valor);
        ++tam;
    }

    void insertarInicio(const T& valor) {
        cabeza = new Nodo(valor, cabeza);
        ++tam;
    }

    void insertarEnPos(size_t pos, const T& valor) {
        if (pos > tam) throw std::out_of_range("posicion fuera de rango");
        if (pos == 0) {
            insertarInicio(valor);
            return;
        }
        Nodo* prev = cabeza;
        for (size_t i = 0; i + 1 < pos; ++i) prev = prev->sig;
        prev->sig = new Nodo(valor, prev->sig);
        ++tam;
    }

    T eliminarEnPos(size_t pos) {
        if (pos >= tam) throw std::out_of_range("posicion fuera de rango");
        Nodo* toDelete = nullptr;
        T valor;
        if (pos == 0) {
            toDelete = cabeza;
            cabeza = cabeza->sig;
        } else {
            Nodo* prev = cabeza;
            for (size_t i = 0; i + 1 < pos; ++i) prev = prev->sig;
            toDelete = prev->sig;
            prev->sig = toDelete->sig;
        }
        valor = toDelete->dato;
        delete toDelete;
        --tam;
        return valor;
    }

    int buscar(const T& valor) const {
        Nodo* curr = cabeza;
        int idx = 0;
        while (curr) {
            if (curr->dato == valor) return idx;
            curr = curr->sig;
            ++idx;
        }
        return -1;
    }

    void recorrer(const std::function<void(const T&)>& f) const {
        Nodo* curr = cabeza;
        while (curr) {
            f(curr->dato);
            curr = curr->sig;
        }
    }

    size_t size() const { return tam; }

    bool vacia() const { return tam == 0; }

    void limpiar() {
        Nodo* curr = cabeza;
        while (curr) {
            Nodo* nxt = curr->sig;
            delete curr;
            curr = nxt;
        }
        cabeza = nullptr;
        tam = 0;
    }
};

#endif
