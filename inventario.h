/*
Author: Jose Angel Garcia Gomez
Date: 30/11/2020
Description: This file is the definition of the class Inventario.
*/

#ifndef INVENTARIO_C
#define INVENTARIO_C


#include <iostream>
#include <string>
#include <vector>
#include "producto.h"
#include "proveedor.h"
#include "cliente.h"
using  namespace std;

class Inventario{
    int cantidad_producto;
    int cantidad_pedido; // Este atributo es parte de la implementacion de la clase individual de Angel
    float promocion_tienda;
    Producto producto;
    Cliente cliente;
    Proveedor proveedor; // Este objeto es la implementacion de la clase individual de Angel
    vector<Producto>productos;
    vector<Cliente>clientes;
    public:
    Inventario(){
        cantidad_pedido = 0;
    };
    Inventario (int cantidad_producto,int cantidad_pedido,float promocion_tienda, Cliente cliente,Producto producto, Proveedor proveedor/*Este es parte de la implementacion de la programacion individual de Angel*/,vector<Producto> productos,vector<Cliente>clientes){
        this->cantidad_producto = cantidad_producto;
        this->promocion_tienda = promocion_tienda;
        this -> cantidad_pedido = cantidad_pedido;
        this -> producto = producto ;
        this -> cliente = cliente;
        this -> proveedor = proveedor; // Este es parte de la implementacion de la programacion individual de Angel
        this->productos = productos;
        this->clientes = clientes;
    }

    int getCantidad_producto(){return cantidad_producto;}
    int getCantidad_pedido(){return cantidad_pedido;}//Este es parte de la implementacion de la programacion individual de Angel
    float getPromocion_tienda(){return promocion_tienda;}
    Producto getProducto(){return producto;}
    Cliente getCliente(){return cliente;}
    Proveedor getProveedor(){return proveedor;}//Este es parte de la implementacion de la programacion individual de Angel
    vector<Producto> getProductos(){return productos;}
    vector<Cliente> getClientes(){return clientes;}


    void setCantidad_producto(int cantidad_producto){this->cantidad_producto = cantidad_producto;}
    void setPromocion_tienda(float promocion_tienda){this->promocion_tienda = promocion_tienda;}
    void setCantidad_pedido(int cantidad_pedido){this -> cantidad_pedido = cantidad_pedido;}//Este es parte de la implementacion de la programacion individual de Angel
    void setProducto(Producto producto){this-> producto = producto;}
    void setCliente(Cliente cliente){this -> cliente = cliente;}
    void setProveedor(Proveedor proveedor){this -> proveedor = proveedor;}//Este es parte de la implementacion de la programacion individual de Angel
    void setProductos(vector<Producto>){this->productos = productos;}
    void setClientes(vector<Cliente>){this->clientes=clientes;}

    void mostrar_atributos_producto(){
        for (int i = 0; i < productos.size();i++){
            cout << productos[i].print() << endl;
        }//Ciclo para ir mopstrando cada objeto del vector
    }//Mostrar atributos del producto

    string mostrar_disponible(){
         return "Tienes "+ to_string(productos.size())+ " productos disponibles";
    }//mostrar disponible

    string agregar_Clientes(){
        int opcion = 1;
        int contador = 0;
        while (opcion == 1){
            cliente.ingresar_datos();
            contador++;
            cout<<"¿Quieres ingresar otro cliente? (si = 1, no = 0): "; cin >>opcion;
            clientes.push_back(cliente);
        }//while
        return "\nSe agregaron "+to_string(contador)+ " clientes. ";         
    }// Agregar cliente

    void mostrar_atributos_cliente(){
        for (int i = 0; i < clientes.size();i++){
            cout << clientes[i].print() << endl;
        }//Ciclo para ir mopstrando cada objeto del vector
    }// Mostrar atributos del cliente

    void borrar_producto(){
        string tipo;
        string tipo_cliente;
        int contador_m = 0;
        int contador_h = 0;
        int cantidad;
        for (int c = 0; c < productos.size(); c ++){
            if (productos[c].getGenero_prenda() == "H"){
                contador_h++;
            }//if
            else if (productos[c].getGenero_prenda() == "M")
            {
                contador_m++;
            }// elseif  
        }//For
        for (int i = 0; i < clientes.size(); i ++){
            clientes[i].registrar_compra();
            tipo = clientes[i].getTipo_prenda();
            cantidad = clientes[i].getCantidad_compra();
            tipo_cliente = saber_tipo_cliente(clientes[i]);
            if (tipo_cliente == "Frecuente"){
                cout << "\nSe le hace un descuento del 15% adicional a "+ clientes[i].getNombre_cliente() + " por ser cliente Frecuente. \n" << endl;
            }
                for (int a = 0; a < cantidad; a ++){
                    for (int b = 0; b < productos.size(); b ++){
                        if (tipo == productos[b].getGenero_prenda()){
                            proveedor.calcular_ganancia(productos[b].getPrecio());//Esto es parte de la implementacion de la programacion individual de Angel
                            productos.erase(productos.begin() + b);
                            if (tipo_cliente == "Frecuente"){
                                productos[b].aplicar_descuento_cliente();
                            }//If
                            cout << "\nSe aquirio el producto: "+ productos[b].print() + "\n"; 
                             break;
                        }// condicion que evalua si el tipo de prenda que se compro esta en algun objeto del vector productos
                    }// ciclo que itera el vector productos
                }// ciclo que se repíte la cantidad de veces que se compro un tipo de prenda
                if (tipo == "H" && cantidad > contador_h){
                    cout << "\nHace falta comprar "+ to_string(cantidad - contador_h) + " prendas de tipo: "+ tipo + "\n";
                    cantidad_pedido = cantidad_pedido + (cantidad - contador_h); //Esto es parte de la implementacion de la programacion individual de Angel
                }//If
                else if (tipo == "M" && cantidad > contador_m){
                    cout << "\nHace falta comprar "+ to_string(cantidad - contador_m) + " prendas de tipo: "+ tipo + "\n";
                    cantidad_pedido = cantidad_pedido + (cantidad - contador_m); //Esto es parte de la implementacion de la programacion individual de Angel
                }//ElseIf
                else{
                    cout << "\nQuedan "+ to_string(productos.size()) + " productos en su inventario.\n" << endl;
                }//Else
        }// ciclo que itera el vector clientes
    }//borrar producto

    string saber_tipo_cliente(Cliente cli){
        cout << "\nEl cliente "+ cli.getNombre_cliente() + " es tipo: "+ cli.otorgar_tipo() +"\n" << endl;
        return cli.otorgar_tipo();
    }

    void recompensa_tipo_cliente(){
        for (int i = 0; i < clientes.size(); i++ ){
            cout << "\nEl cliente: "+ clientes[i].getNombre_cliente() + " tiene una recompensa de: $"+ to_string(clientes[i].calcular_recompensa_cliente()) +" en su tienda.\n" << endl;
        }        
    }


    string agregar_producto(){
        int opcion = 1;
        int contador = 0;
        int cantidad;
        while (opcion == 1){
            producto.datos_producto();
            cout << "\n¿Cuantos productos iguales adquiriste? "; cin >> cantidad;
            cout<<"¿Quieres ingresar otro producto? (si = 1, no = 0): "; cin >>opcion;
            for (int i = 0; i < cantidad; i++){
                contador++;
                producto.otorgar_id_producto();
                productos.push_back(producto);
            }//Ciclo que va a agregar el producto la cantidad de veces que se adquirieron
        }//while
        return "\nSe agregaron "+to_string(contador)+ " tipos de productos. "; 
    }//agregar producto

    void agregar_datos_proveedor(){
        proveedor.registrar_datos_proveedor();
    }// Agregar datos al proveedor. Esto es parte de la implementacion de la programacion individual de Angel

    void mostrar_atributos_proveedor(){
        cout << proveedor.print() << endl;
    }//Mostrar atributos proveedor. Esto es parte de la implementacion de la programacion individual de Angel

    void calcular_ganancia(){
        for (int i = 0; i < productos.size(); i++){
            proveedor.calcular_ganancia(productos[i].getPrecio());
        }//For
    }// Calcular ganancia. Esto es parte de la implementacion de la programacion individual de Angel

    void hacer_pedido(){
        proveedor.hacer_pedido(cantidad_pedido);
    }//Hacer pedido al proveedor. Este es parte de la implementacion de la programacion individual de Angel
};//Clase Inventario
#endif