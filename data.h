#include <stdbool.h>
#include <string.h>
#define _ANOATUAL 2024
using namespace std;
//autor: Filipi Pereira
//definicao da classe Data
class Data{
private:
    //atributos
    int dia;
    int mes;
    int ano;
public:
    //assinaturas dos metodos
    bool setDia(int dia);
    bool setMes(int mes);
    bool setAno(int ano);
    int getDia();
    int getMes();
    int getAno();
    bool dataValida();
    void setData(int dia, int mes, int ano);
    void leiaData();
    void escrevaData();
    bool verificaMes(int mes);
};
//sets
bool Data::setDia(int dia){
    bool valido = true;
    if(dia < 1 || dia > 31) valido = false;
    else this->dia = dia;
    return valido;
}
bool Data::setMes(int mes){
    bool valido = true;
    if(mes < 1 || mes > 12) valido = false;
    else this->mes = mes;
    return valido;
}
bool Data::setAno(int ano){
    bool valido = true;
    if(ano < 1900 || ano > _ANOATUAL) valido = false;
    else this->ano = ano;
    return valido;
}
//gets
int Data::getDia(){
    return this->dia;
}
int Data::getMes(){
    return this->mes;
}
int Data::getAno(){
    return this->ano;
}
//verifica se a data guardada no objeto corrente é valida
bool Data::dataValida(){
    bool valido = true;
    int diasFevereiro;
    if(getAno() % 4 == 0 && getAno() % 400 == 0) diasFevereiro = 28;
    else if(getAno() % 4 == 0 && getAno() % 100 == 0) diasFevereiro = 29;
    else if(getAno() % 4 == 0) diasFevereiro = 28;
    else diasFevereiro = 29;
    int diasMes[] = {31, diasFevereiro, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(getDia() > diasMes[getMes()-1]) valido = false;
    return valido;
}
//set data
void Data::setData(int dia, int mes, int ano){
    setDia(dia);
    setMes(mes);
    setAno(ano);
}
//le a data e, se valida, seta a data no objeto corrente
void Data::leiaData(){
    int dia;
    int mes;
    int ano;
    do{
        do{
            cout << "Digite o dia: ";
            cin >> dia;
            if(!setDia(dia)) cout << "Dia invalido" << endl;
        }while(!setDia(dia));
        do{
            cout << "Digite o mes: ";
            cin >> mes;
            if(!setMes(mes)) cout << "Mes invalido!" << endl;
        }while(!setMes(mes));
        do{
            cout << "Digite o ano: ";
            cin >> ano;
            if(!setAno(ano)) cout << "Ano invalido!" << endl;
        }while(!setAno(ano));
        setData(dia, mes, ano);
    }while(!dataValida());
}
//funcao que escreve a data do objeto corrente
void Data::escrevaData(){
    cout << "Data de nascimento: " << getDia() << "/" << getMes() << "/" << getAno() << endl;
}
//funcao que recebe um mes e retorna true se o mes do objeto corrento for igual ao mes parametrizado
bool Data::verificaMes(int mes){
    bool igual = false;
    if(getMes() == mes) igual = true;
    return igual;
}
