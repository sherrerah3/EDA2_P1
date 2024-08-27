#ifndef NODO_H
#define NODO_H
#include "producto.h"

class Nodo{
public: 
    Producto data;
    Nodo* siguiente;

    //Constructor 
    Nodo(const Producto &data);

};

#endif // NODO_H
