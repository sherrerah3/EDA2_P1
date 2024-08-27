# Variables
CXX = g++
CXXFLAGS = -Wall  #opción -Wall es una bandera del compilador g++ que habilita una serie de advertencias (warnings) útiles
OBJ = producto.o nodo.o listaLigada.o main.o
TARGET = programa

# Regla para compilar el programa
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Regla para compilar persona.cpp
producto.o: producto.cpp producto.h
	$(CXX) $(CXXFLAGS) -c producto.cpp

nodo.o: producto.h nodo.h nodo.cpp
	$(CXX) $(CXXFLAGS) -c nodo.cpp

listaLigada.o: producto.h nodo.h listaLigada.h listaLigada.cpp
	$(CXX) $(CXXFLAGS) -c listaLigada.cpp

main.o: producto.h nodo.h listaLigada.h main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp


# Limpiar archivos objeto y el ejecutable
clean:
	rm -f $(OBJ) $(TARGET)
