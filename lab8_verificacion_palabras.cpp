#include <iostream>
#include <vector>
using namespace std;
int comparacion_cadena(string a,string b){
     int j=0;
     int cont=0;
    while(j<=5){
        if(a[j]==b[j]){
            j++;
        }
        else{
            j++;
            cont++;
        } 
    }
    return cont;
}
bool verificacion(int comparacion_cadena){
    if (comparacion_cadena>1)
        return false;
    return true;
}
template<typename T>
void comparacion_vector(vector<T>& vec){
     for (unsigned i=0; i<vec.size(); i++){
        if(verificacion(comparacion_cadena(vec.at(i).first,vec.at(i).second))==true){
            cout<<"valida"<<endl;
        }else{
            cout<<"invalida"<<endl;  
        }   
     }
}
int main(){
vector<pair<string,string>> prueba{{"corps","coops" }, {"jayan","kryan"},{"words", "cords"}, {"crops", "drops"}, {"drips", "grips"}, {"gripe", "grape"},{"corps","crops"}};
    
   comparacion_vector(prueba);

    return 0;
}
