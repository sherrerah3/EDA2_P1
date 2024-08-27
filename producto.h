#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
#include <iostream>
using namespace std;



class Producto{
private:
    int id;
    int precio;
    int cantidadVendida;
    string fechaVenta;

public:
    Producto(int id, int precio, int cantidadVendida, const string &fechaVenta);

    //Metodo para obtener valores de los atributos
    int getId() const;
    int getPrecio() const;
    int getCantidadVendida() const;
        string getFechaVenta() const;
    
    // Sobrecarga de operador << para permitir la salida de objetos Producto a un flujo de salida
    friend ostream &operator<<(ostream &os, const Producto &producto);

    // Sobrecarga del operador comparacion
    bool operator>(const Producto &otro) const;
    bool operator<(const Producto &otro) const;
    bool operator==(const Producto &otro) const;

};


#endif //PRODUCTO_H
