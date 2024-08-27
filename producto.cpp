#include "producto.h"

Producto::Producto(int id, int precio, int cantidadVendida, const string &fechaVenta): 
    id(id), precio(precio), cantidadVendida(cantidadVendida), fechaVenta(fechaVenta) {}

// Método para obtener el id del producto
int Producto::getId() const { return id; }

// Método para obtener la precio del producto
int Producto::getPrecio() const { return precio; }

// Metodo para obtener la cantidad vendida
int Producto::getCantidadVendida() const { return cantidadVendida; }

// Método para obtener la fecha de venta
string Producto::getFechaVenta() const { return fechaVenta; }

// Sobrecarga del operador << para permitir la salida de objetos Producto a un
// flujo de salida
ostream &operator<<(ostream &os, const Producto &producto) {
  os << "Id: " << producto.id << ", Precio: " << producto.precio
     << ", Cantidad Vendida: " << producto.cantidadVendida
     << ", Fecha de Venta: " << producto.fechaVenta;
  return os;
}

// Sobrecarga del operador > para comparar dos objetos Producto por
bool Producto::operator>(const Producto &otra) const {
  if (cantidadVendida > otra.cantidadVendida) {
    return true;
  } else {
    if (cantidadVendida == otra.cantidadVendida && precio > otra.precio) {
      return true;
    }
  }
    return false;
}

// Sobrecarga del operador < para comparar dos objetos Producto por
bool Producto::operator<(const Producto &otra) const {
  if(cantidadVendida < otra.cantidadVendida){
      return true;
    } else {
      if((cantidadVendida == otra.cantidadVendida) && (precio < otra.precio)){
            return true;
        }
    }
    return false;
}

// Sobrecarga del operador == para comparar dos objetos Producto por
bool Producto::operator==(const Producto &otra) const {
    return (cantidadVendida == otra.cantidadVendida && precio == otra.precio);
}


