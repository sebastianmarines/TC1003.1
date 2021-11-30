#include <iostream>
#include <string>
#include <vector>
#include "Producto.hpp"

using namespace std;

#ifndef TIENDA_HPP
#define TIENDA_HPP
class Tienda
{
private:
    string nombre;
    vector<Producto> productos;

public:
    Tienda(string nombre);
    string getNombre();

    void setNombre(string nombre);
    void agregarProducto(Producto producto);
    void eliminarProducto(Producto producto);
    void mostrarProductos();
    void mostrarProductos(string nombre);
    void mostrarProductos(int precio);

    bool operator==(Tienda &tienda);
};

Tienda::Tienda(string nombre) : nombre(nombre)
{
}

string Tienda::getNombre()
{
    return nombre;
}

void Tienda::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Tienda::agregarProducto(Producto producto)
{
    productos.push_back(producto);
}

void Tienda::eliminarProducto(Producto producto)
{
    for (size_t i = 0; i < productos.size(); i++)
    {
        if (productos[i] == producto)
        {
            productos.erase(productos.begin() + i);
        }
    }
}

void Tienda::mostrarProductos()
{
    for (size_t i = 0; i < productos.size(); i++)
    {
        cout << productos[i].getNombre() << " " << productos[i].getPrecio() << endl;
    }
}

void Tienda::mostrarProductos(string nombre)
{
    for (size_t i = 0; i < productos.size(); i++)
    {
        if (productos[i].getNombre() == nombre)
        {
            cout << productos[i].getNombre() << " " << productos[i].getPrecio() << endl;
        }
    }
}

void Tienda::mostrarProductos(int precio)
{
    for (size_t i = 0; i < productos.size(); i++)
    {
        if (productos[i].getPrecio() == precio)
        {
            cout << productos[i].getNombre() << " " << productos[i].getPrecio() << endl;
        }
    }
}

#endif
