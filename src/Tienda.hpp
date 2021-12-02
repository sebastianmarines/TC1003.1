/**
 * @file Tienda.hpp
 * @author Sebastian Marines (a01383056@tec.mx)
 * @date 2021-12-01
 */
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

// Constructor
Tienda::Tienda(string nombre) : nombre(nombre)
{
}

// Getters
string Tienda::getNombre()
{
    return nombre;
}

// Setters
void Tienda::setNombre(string nombre)
{
    this->nombre = nombre;
}

// Métodos
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
    // Se crea un hash map para llevar un conteo de la cantidad de cada producto y no imprimir los productos repetidos
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

// Sobrecarga del metodo mostrarProductos para que muestre los productos con un nombre determinado
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
