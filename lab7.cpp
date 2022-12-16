#include <iostream>
#include <vector>
#include <string>
using namespace std;



enum Condicional {EMPTY, FULL};
template<typename Tipo_Dato,typename Tipo_Dato2>

class Tabla_Base
{
private:
    std::pair<Tipo_Dato*,std::vector<Tipo_Dato2>*> table;//creamos un pair que nos reciba 2 valores una llave y una vector que puede recibir 
                            //varios strings
    Condicional c;
public:
    template<typename M,typename N> friend class HashTable;
    Tabla_Base()
    {
        table.first = nullptr;
        table.second = new vector<Tipo_Dato2>;
        c = EMPTY;
    }
    ~Tabla_Base(){}
};

template<typename Tipo_Dato,typename Tipo_Dato2>

class HashTable{
private:
    Tabla_Base<Tipo_Dato,Tipo_Dato2>* BasePrincipal;
    unsigned int tamaño;
public:
    int hashFunction(Tipo_Dato key, int i){
        return (key + i) % tamaño;
    }
    HashTable(unsigned int size){
        this->tamaño = size;
        BasePrincipal = new Tabla_Base<Tipo_Dato, Tipo_Dato2> [size];
    }
    ~HashTable(){
        for (unsigned int i = 0; i < tamaño; i++){
            if (BasePrincipal[i].table.first != nullptr){
                delete BasePrincipal[i].table.first;
            }
            delete BasePrincipal[i].table.second;
        }
        delete [] BasePrincipal;
    }

    void insertData(Tipo_Dato key, Tipo_Dato2 data){
        int indice = 0;
        for (unsigned int i = 0; i < tamaño; i++){
            indice = hashFunction(key, i);
            if (BasePrincipal[indice].c == EMPTY){
                BasePrincipal[indice].c = FULL;
                BasePrincipal[indice].table.first = new Tipo_Dato (key);
                BasePrincipal[indice].table.second->push_back(data);
                return;
            }
            else if (*BasePrincipal[indice].table.first == key){
                BasePrincipal[indice].table.second->push_back(data);
                return;
            }
        } 
        return;
    }
    void displayHash(){
        cout << "indice\t"<< "Llave\t" << "Datos_de_los_nombre"<<endl;
        for (unsigned int i = 0; i < tamaño; i++){
            cout <<"["<<i<<"]-->"<< "\t";
            if (BasePrincipal[i].table.first == nullptr){
                cout << "llave vacia,nombre vacio"<<endl;
            }  
            
            else{
                cout <<"["<< *BasePrincipal[i].table.first <<"]"<< "\t";
                for (const auto& j : *BasePrincipal[i].table.second){
                    cout <<"["<< j << "]";
                }
                cout << endl;
            }
        }
    }     
};
class Robot
{
private:
    int numero_serie;
    string nombre;
public:
    Robot(int numero_serie,string nombre);
    ~Robot(){}

    friend std::ostream& operator<<(std::ostream& os, const Robot& e){
        return os << e.numero_serie << "-->" <<e.nombre;
    }
};
Robot::Robot(int numero_serie_,string nombre_){
    this->numero_serie = numero_serie_;
    this->nombre = nombre_;
}
class User
{
private:
    string name;
    string email;
public:
    User(string name,string email);
    ~User(){}

    friend std::ostream& operator<<(std::ostream& os, const User& e){
        return os << e.name << " - " <<e.email;
    }
};
User::User(string name_,string email_){
    this->name = name_;
    this->email = email_;
}
/*
int main(){

    HashTable<int, string> prueba(10);

    prueba.insertData(123,"ramiro");
    prueba.insertData(54,"juan");
    prueba.insertData(89,"diego");
    prueba.insertData(16,"lucia");
    prueba.insertData(400,"andres");
    prueba.displayHash();
    return 0;
}
*/
// PRUEBAS DE LA TABLA HASH
int main(){
    cout<<"pruebas con robots"<<endl;
    HashTable<int,Robot> robotPruebas(5);
    Robot a1(111,"bender");
    Robot a2(122,"cyborg");
    Robot a3(133,"terminator");
    robotPruebas.insertData(992,a1);
    robotPruebas.insertData(345,a2);
    robotPruebas.insertData(765,a3);
    robotPruebas.displayHash();
    cout<<"**********************************"<<endl;
    cout<<"pruebas con usuarios"<<endl;
    HashTable<int, User> pruebas(8);
    User p1("martin", "martin@unsa.edu.pe");
    User p2("matias", "matias@unsa.edu.pe");
    User p3("daniela", "dani@gmail.com");
    User p4("pricsila", "1029@gmail.com");
    User p5("marcos", "john12@gmail.com");
    pruebas.insertData(1111, p1);
    pruebas.insertData(5325, p2);
    pruebas.insertData(5642, p3);
    pruebas.insertData(2353, p4);
    pruebas.insertData(7642, p5);
    pruebas.displayHash();
    cout<<"**********************************"<<endl;
    return 0;
}
