/**
 * @file main.cpp
 * @author Sebastian Marines (a01383056@tec.mx)
 * @date 2021-12-01
 */
/*
* Yo, como integrante de la comunidad estudiantil del Tecnológico de Monterrey,
* soy consciente de que la trampa y el engaño afectan mi dignidad como persona, mi aprendizaje y mi formación,
* por ello me comprometo a actuar honestamente, respetar y dar crédito al valor y esfuerzo con el que se elaboran las ideas propias,
* las de los compañeros y de los autores,
* así como asumir mi responsabilidad en la construcción de un ambiente de aprendizaje justo y confiable
*/
#include <iostream>
#include <iomanip>
#include "Persona.hpp"
#include "Tienda.hpp"
#include "Producto.hpp"

using namespace std;

int menu();

// Plantilla de función para poder encontrar un elemento en un vector de cualquier tipo de clase
template <class T>
int encontrarEnLista(vector<T> lista, string nombre)
{
    for (size_t i = 0; i < lista.size(); i++)
    {
        if (lista[i].getNombre() == nombre)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<Persona> listaDePersonas;
    vector<Tienda> listaDeTiendas;
    while (true)
    {
        switch (menu())
        {
        case 1: // Agregar persona
        {
            string nombre;
            string apellido;
            cout << "Ingrese el nombre: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Ingrese el apellido: ";
            getline(cin, apellido);
            Persona persona(nombre, apellido);
            cout << persona.getNombre() << " " << persona.getApellido() << endl;
            listaDePersonas.push_back(persona);
            break;
        }
        case 2: // Agregar tienda
        {
            string nombre;
            cout << "Ingrese el nombre de la tienda: ";
            cin.ignore();
            getline(cin, nombre);
            Tienda tienda(nombre);
            listaDeTiendas.push_back(tienda);
            break;
        }
        case 3: // Agregar producto
        {
            string nombre;
            int precio;
            string nombreTienda;
            cout << "Ingrese el nombre de la tienda: ";
            cin.ignore();
            getline(cin, nombreTienda);
            int posicion = encontrarEnLista(listaDeTiendas, nombreTienda);
            if (posicion == -1)
            {
                cout << "No se encontro la tienda" << endl;
                break;
            }
            cout << "Ingrese el nombre del producto: ";
            getline(cin, nombre);
            cout << "Ingrese el precio del producto: ";
            cin >> precio;
            cout << "Ingrese el numero de productos: ";
            int numeroDeProductos;
            cin >> numeroDeProductos;
            Producto producto(nombre, precio);
            for (int j = 0; j < numeroDeProductos; j++)
            {
                listaDeTiendas[posicion].agregarProducto(producto);
            }
            cout << "Productos agregados exitosamente" << endl;
            break;
        }
        case 4: // Comprar producto
        {
            string nombreTienda;
            cout << "Ingrese el nombre de la tienda: ";
            cin.ignore();
            getline(cin, nombreTienda);
            int posicion = encontrarEnLista(listaDeTiendas, nombreTienda);
            if (posicion == -1)
            {
                cout << "No se encontro la tienda" << endl;
                break;
            }
            string nombreCliente;
            cout << "Ingrese el nombre del cliente: ";
            getline(cin, nombreCliente);
            int posicionCliente = encontrarEnLista(listaDePersonas, nombreCliente);
            if (posicionCliente == -1)
            {
                cout << "No se encontro el cliente" << endl;
                break;
            }
            listaDeTiendas[posicion].mostrarProductos();
            cout << endl;
            cout << "Ingrese el nombre del producto: ";
            string nombreProducto;
            getline(cin, nombreProducto);
            int cantidadDeProductos;
            cout << "Ingrese la cantidad de productos a comprar: ";
            cin >> cantidadDeProductos;
            int productosComprados = 0;
            for (int i = 0; i < cantidadDeProductos; i++)
            {
                bool ok = listaDeTiendas[posicion].comprarProducto(nombreProducto, listaDePersonas[posicionCliente]);
                if (ok)
                {
                    productosComprados++;
                }
                else
                {
                    cout << "No hay suficientes productos" << endl;
                    break;
                }
            }
            cout << "Productos comprados: " << productosComprados << endl;
            break;
        }
        case 5: // Mostrar productos
        {
            string nombre;
            cout << "Ingrese el nombre de la tienda: ";
            cin.ignore();
            getline(cin, nombre);
            int posicion = encontrarEnLista(listaDeTiendas, nombre);
            if (posicion == -1)
            {
                cout << "No se encontro la tienda" << endl;
                break;
            }
            listaDeTiendas[posicion].mostrarProductos();
            break;
        }
        case 6: // Mostrar tiendas
        {
            for (size_t i = 0; i < listaDeTiendas.size(); i++)
            {
                cout << listaDeTiendas[i].getNombre() << endl;
            }
            break;
        }
        case 7: // Mostrar información de cliente
        {
            string nombre;
            cout << "Ingrese el nombre del cliente: ";
            cin.ignore();
            getline(cin, nombre);
            int posicion = encontrarEnLista(listaDePersonas, nombre);
            if (posicion == -1)
            {
                cout << "No se encontro el cliente" << endl;
                break;
            }
            cout << listaDePersonas[posicion].getNombre() << " " << listaDePersonas[posicion].getApellido() << endl;
            listaDePersonas[posicion].mostrarProductosComprados();
            break;
        }
        default:
            return 0;
        }
    }
}

int menu()
{
    string separator = string(13, '-');
    cout << setw(13) << "MENU" << endl;
    cout << string(26, '=') << endl;
    cout << setw(10) << "1. Agregar persona" << endl;
    cout << setw(10) << "2. Agregar tienda" << endl;
    cout << setw(10) << "3. Agregar producto" << endl;
    cout << setw(10) << "4. Comprar producto" << endl;
    cout << setw(10) << "5. Mostrar productos" << endl;
    cout << setw(10) << "6. Mostrar tiendas" << endl;
    cout << setw(10) << "7. Mostrar información de cliente" << endl;
    cout << left << setw(10) << "8. Salir" << right << endl;
    cout << endl;

    int opcion;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    if (opcion > 8 || opcion < 1)
    {
        cout << "Opcion invalida" << endl;
        return menu();
    }
    return opcion;
}
