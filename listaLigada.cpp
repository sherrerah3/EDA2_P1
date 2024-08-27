#include "listaLigada.h"
#include <iostream>

// Constructor que inicializa la lista vacía
ListaLigada::ListaLigada() : cabeza(nullptr) {}

// Constructor de copia
ListaLigada::ListaLigada(const ListaLigada &otraLista) : cabeza(nullptr) {
  if (otraLista.cabeza == nullptr) {
    return; // Si la lista original está vacía, no se hace nada
  }

  // Crear el primer nodo en la lista nueva con los datos del primer nodo de la
  // otra lista
  cabeza = new Nodo(otraLista.cabeza->data);
  Nodo *actualNuevo = cabeza; // Puntero al nodo actual en la nueva lista
  Nodo *actualOriginal =
      otraLista.cabeza
          ->siguiente; // Puntero al nodo siguiente en la lista original

  // Recorrer la lista original y copiar cada nodo a la nueva lista
  while (actualOriginal != nullptr) {
    actualNuevo->siguiente = new Nodo(
        actualOriginal
            ->data); // Crear un nuevo nodo con los datos del nodo original
    actualNuevo =
        actualNuevo->siguiente; // Avanzar al siguiente nodo en la nueva lista
    actualOriginal = actualOriginal ->siguiente; // Avanzar al siguiente nodo en la lista original
  }
}

ListaLigada::~ListaLigada() {
  while (cabeza != nullptr) {
    Nodo *temp = cabeza;
    cabeza = cabeza->siguiente;
    delete temp;
  }
}

// Método para agregar un nodo al final de la lista
void ListaLigada::agregar(const Producto &producto) {
  Nodo *nuevoNodo =
      new Nodo(producto); // Crear un nuevo nodo con los datos de persona
  if (cabeza == nullptr) {
    cabeza = nuevoNodo; // Si la lista está vacía, el nuevo nodo se convierte en
                        // la cabeza
  } else {
    Nodo *actual = cabeza;
    while (actual->siguiente != nullptr) {
      actual = actual->siguiente; // Avanzar hasta el último nodo
    }
    actual->siguiente = nuevoNodo; // Añadir el nuevo nodo al final
  }
}

// Método para imprimir todos los nodos de la lista
void ListaLigada::imprimir() const {
  Nodo *actual = cabeza;
  while (actual != nullptr) {
    std::cout << actual->data
              << std::endl;     // Imprimir los datos del nodo actual
    actual = actual->siguiente; // Avanzar al siguiente nodo
  }
}

// Método para intercambiar dos nodos si el primero es mayor que el segundo
void ListaLigada::intercambiar(Nodo *nodo1, Nodo *nodo2) {
  Producto temp = nodo1->data; // Guardar temporalmente los datos de nodo1
  nodo1->data = nodo2->data;   // Copiar los datos de nodo2 a nodo1
  nodo2->data = temp;          // Copiar los datos originales de nodo1 a nodo2
}

// Método para ordenar la lista usando el método de burbuja
void ListaLigada::ordenarBurbuja() {
  if (cabeza == nullptr)
    return; // Si la lista está vacía, no hacer nada

  bool intercambiado;
  do {
    intercambiado = false;
    Nodo *actual = cabeza;
    while (actual->siguiente != nullptr) {
      if (actual->data > actual->siguiente->data) {
        intercambiar(actual, actual->siguiente); // Intercambiar nodos si están
                                                 // en el orden incorrecto
        intercambiado = true;
      }
      actual = actual->siguiente; // Avanzar al siguiente nodo
    }
  } while (intercambiado); // Repetir hasta que no haya intercambios
}

// Método auxiliar para dividir la lista en dos partes según el pivote
Nodo *ListaLigada::dividir(Nodo *bajo, Nodo *alto, Nodo **nuevoBajo,
                           Nodo **nuevoAlto) {
  Nodo *pivote = alto;
  Nodo *previo = nullptr;
  Nodo *actual = bajo;
  Nodo *cola = pivote;
  while (actual != pivote) {
    if (pivote->data > actual->data) {
      if ((*nuevoBajo) == NULL) {
        (*nuevoBajo) = actual;
      }
      previo = actual;
      actual = actual->siguiente;
    } else {
      if (previo) {
        previo->siguiente = (actual->siguiente);
      }
      Nodo *temp = actual->siguiente;
      actual->siguiente = nullptr;
      cola->siguiente = (actual);
      cola = actual;
      actual = temp;
    }
  }
  if (*nuevoBajo == NULL) {
    *nuevoBajo = pivote;
  }
  *nuevoAlto = cola;
  return pivote;
}

// Método auxiliar para realizar el QuickSort de manera recursiva
Nodo *ListaLigada::quickSortRec(Nodo *bajo, Nodo *alto) {
  if (!bajo || bajo == alto) {
    return bajo;
  }
  Nodo *nuevaCabeza = NULL;
  Nodo *nuevoFinal = NULL;

  Nodo *pivote = dividir(bajo, alto, &nuevaCabeza, &nuevoFinal);

  if (nuevaCabeza != pivote) {
    Nodo *temp = nuevaCabeza;
    while (temp->siguiente != pivote) {
      temp = temp->siguiente;
    }
    temp->siguiente = nullptr;
    nuevaCabeza = quickSortRec(nuevaCabeza, temp);
    temp = obtenerUltimo(nuevaCabeza);
    temp->siguiente = pivote;
  }
  pivote->siguiente = (quickSortRec(pivote->siguiente, nuevoFinal));
  return nuevaCabeza;
}

void ListaLigada::quickSort() {
  Nodo *cola = obtenerUltimo(cabeza);

  cabeza = quickSortRec(cabeza, cola);
  return;
}

// Método auxiliar para obtener el último nodo de una lista
Nodo *ListaLigada::obtenerUltimo(Nodo *cabeza) {
  while (cabeza != nullptr && cabeza->siguiente != nullptr) {
    cabeza = cabeza->siguiente; // Avanzar al siguiente nodo
  }
  return cabeza; // Retornar el último nodo
}

// Método auxiliar para dividir la lista en dos mitades para MergeSort
Nodo *ListaLigada::mergeSortRec(Nodo *cabeza) {
  if (cabeza == nullptr || cabeza->siguiente == nullptr)
    return cabeza; // Lista vacía o con un solo nodo

  Nodo *medio = cabeza;
  Nodo *fin = cabeza;
  while (fin->siguiente != nullptr && fin->siguiente->siguiente != nullptr) {
    fin = fin->siguiente->siguiente;
    medio = medio->siguiente;
  }

  Nodo *mitad = medio->siguiente;
  medio->siguiente = nullptr;

  Nodo *izquierda = mergeSortRec(cabeza);
  Nodo *derecha = mergeSortRec(mitad);

  return unir(izquierda, derecha);
}

// Método auxiliar para unir dos listas ordenadas en una sola lista
Nodo *ListaLigada::unir(Nodo *primero, Nodo *segundo) {
  if (primero == nullptr)
    return segundo;
  if (segundo == nullptr)
    return primero;

  if (primero->data < segundo->data) {
    primero->siguiente = unir(primero->siguiente, segundo);
    return primero;
  } else {
    segundo->siguiente = unir(primero, segundo->siguiente);
    return segundo;
  }
}

void ListaLigada::mergeSort() { cabeza = mergeSortRec(cabeza); }
