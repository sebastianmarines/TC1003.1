#include <iostream>
#include <string>
#include <vector>
#include <map>
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
    bool eliminarProducto(string nombreDelProducto);
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

bool Tienda::eliminarProducto(string nombreDelProducto)
{
    for (size_t i = 0; i < productos.size(); i++)
    {
        if (productos[i].getNombre() == nombreDelProducto)
        {
            productos.erase(productos.begin() + i);
            return true;
        }
    }
    return false;
}

void Tienda::mostrarProductos()
{
    map<string, int> cantidadDeProductos;
    for (size_t i = 0; i < productos.size(); i++)
    {
        cantidadDeProductos[productos[i].getNombre()]++;
    }
    for (auto it = cantidadDeProductos.begin(); it != cantidadDeProductos.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
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
