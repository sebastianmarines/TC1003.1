/**
 * @file Persona.hpp
 * @author Sebastian Marines (a01383056@tec.mx)
 * @date 2021-12-01
 */
#include <string>
#include <vector>
#include <map>
#include "Producto.hpp"

using namespace std;

#ifndef PERSONA_HPP
#define PERSONA_HPP
class Persona
{
private:
    string nombre;
    string apellido;
    vector<Producto> productosComprados;

public:
    Persona();
    Persona(string nombre, string apellido);
    string getNombre();
    string getApellido();
    void setNombre(string nombre);
    void setApellido(string apellido);
    void agregarProducto(Producto producto);
    void mostrarProductosComprados();
};

// Constructores
Persona::Persona()
{
}

Persona::Persona(string nombre, string apellido) : nombre(nombre), apellido(apellido)
{
}

// Getters
string Persona::getNombre()
{
    return nombre;
}

string Persona::getApellido()
{
    return apellido;
}

// Setters
void Persona::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Persona::setApellido(string apellido)
{
    this->apellido = apellido;
}

// Métodos
void Persona::agregarProducto(Producto producto)
{
    productosComprados.push_back(producto);
}

void Persona::mostrarProductosComprados()
{
    map<string, int> cantidadDeProductos;
    for (size_t i = 0; i < productosComprados.size(); i++)
    {
        cantidadDeProductos[productosComprados[i].getNombre()]++;
    }
    for (auto it = cantidadDeProductos.begin(); it != cantidadDeProductos.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
}
#endif