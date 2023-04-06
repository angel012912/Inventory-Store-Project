/*
Author: Jose Angel Garcia Gomez
Date: 30/11/2020
Description: This file is the definition of the class Cliente.
*/

#ifndef CLIENTE_C
#define CLIENTE_C

#include <iostream>
#include "producto.h"
#include "inventario.h"
#include <string>
#include <vector>

using  namespace std;

class Cliente{ 
    int telefono_cliente, compras, cantidad_compra;
    string nombre_cliente, correo_cliente, direccion_cliente, tipo_prenda;
    string tipo_cliente; 
    long id_cliente;
    public:
    Cliente(){
        compras = 0;
        id_cliente = 0;
    }

    int getTelefono_cliente(){return telefono_cliente;}
    string getNombre_cliente(){return nombre_cliente;}
    string getCorreo_cliente(){return correo_cliente;}
    string getDireccion_cliente(){return direccion_cliente;}
    long getId_cliente(){return id_cliente;}
    string getTipo_cliente(){return tipo_cliente;}
    int getCompras(){return compras;}
    int getCantidad_compra(){return cantidad_compra;}
    string getTipo_prenda(){return tipo_prenda;}
    void setTelefono_cliente(int telefono_cliente){ this -> telefono_cliente = telefono_cliente;}
    void setNombre_cliente(string nombre_cliente){ this -> nombre_cliente = nombre_cliente;}
    void setCorreo_cliente(string correo_cliente){ this -> correo_cliente = correo_cliente;}
    void setDireccion_cliente(string direccion_cliente){ this -> direccion_cliente = direccion_cliente;}
    void setId_cliente(long setId_cliente){ this -> id_cliente = id_cliente;}
    void setTipo_cliente(string tipo_cliente){ this -> tipo_cliente = tipo_cliente;}
    void setCompras(int compras){this ->compras = compras;}
    void setCantidad_compra(int cantidad_compra){this -> cantidad_compra = cantidad_compra;}
    void setTipo_prenda(string tipo_prenda){this -> tipo_prenda = tipo_prenda;}


     string otorgar_tipo(){
        if (compras>= 10){
            tipo_cliente = "Frecuente";
        } 
        else{
            tipo_cliente = "Standard";
        }
        setTipo_cliente(tipo_cliente);
        return tipo_cliente;
    }//Otorgar tipo

    void ingresar_datos(){
            id_cliente++;
            string nombre;
            int telefono;
            string correo;
            string direccion;
            cin.ignore(32767,'\n');
            cout << "Ingresa el nombre del cliente: ", getline(cin, nombre);
            cout << "Ingresa el correo del cliente: ",  getline(cin, correo);
            cout << "Ingresa la direccion del cliente: ", getline(cin, direccion);
            cout << "Ingresa el telefono del cliente: "; cin>>telefono; 
            cout<<endl;
            setId_cliente(id_cliente);
            setCorreo_cliente(correo);
            setTelefono_cliente(telefono);
            setNombre_cliente(nombre);
            setDireccion_cliente(direccion);
    }// Ingresar datos

    void registrar_compra(){
        cout << "Cliente: "+ nombre_cliente +"\n";
        cout << "Que tipo de prenda se va a adquirir (H/M): "; cin >> tipo_prenda;
        cout << "Cuantas prendas se quieren adquirir: "; cin >> cantidad_compra;
        compras = compras + cantidad_compra;
    }//Registrar compra
  
    int calcular_recompensa_cliente(){
        int recompensa;
        if (compras >= 5 ){
            recompensa = compras / 5 * 100;
        }//If 
        else{
            recompensa = 0;
        }//Else
        return recompensa;
    }//Calcula recompensa cliente



    string print(){
        return "Cliente: \n\tID: "+to_string(id_cliente)+"\n\tNombre: "+nombre_cliente+"\n\tCorreo: "+correo_cliente+"\n\tDireccion: "+direccion_cliente+"\n\tTelefono: "+to_string(telefono_cliente)+"\n";

    }

};


#endif