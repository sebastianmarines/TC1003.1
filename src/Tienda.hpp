#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Producto.hpp"
#include "Persona.hpp"

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
    bool comprarProducto(string nombreDelProducto, Persona &persona);
    void mostrarProductos();
    void mostrarProductos(string nombre);

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

bool Tienda::comprarProducto(string nombreDelProducto, Persona &persona)
{
    for (size_t i = 0; i < productos.size(); i++)
    {
        if (productos[i].getNombre() == nombreDelProducto)
        {
            Producto producto = productos[i];
            persona.agregarProducto(producto);
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
    int cantidad = 0;
    for (size_t i = 0; i < productos.size(); i++)
    {
        if (productos[i].getNombre() == nombre)
        {
            cantidad++;
        }
    }
    cout << nombre << ": " << cantidad << endl;
}

#endif
