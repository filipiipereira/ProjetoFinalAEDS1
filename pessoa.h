#include "data.h"
#include <stdbool.h>
#include <string.h>
//autor: Filipi Pereira
//define a classe Pessoa
class Pessoa{
protected:
    //atributos
    string nome;
    Data nascimento;
public:
    static int quantidade;
    //construtores e destrutores
    Pessoa(){
        quantidade++;
    }
    Pessoa(string nome, int dia, int mes, int ano){
        quantidade++;
        setNome(nome);
        this->nascimento.setData(dia, mes, ano);
    }
    //assinaturas dos metodos
    void setNome(string nome);
    string getNome();
    Data getNascimento();
    void leiaNome();
    void escrevaNome();
    void leiaPessoa();
    virtual void escrevaPessoa();
};
//inicializacao do atributo estatico
int Pessoa::quantidade = 0;
//sets
void Pessoa::setNome(string nome){
    this->nome = nome;
}
//gets
string Pessoa::getNome(){
    return this->nome;
}
Data Pessoa::getNascimento(){
    return this->nascimento;
}
//le o nome e seta no objeto corrente
void Pessoa::leiaNome(){
    string nome;
    cout << "Digite o nome: ";
    fflush(stdin);
    getline(cin,nome);
    setNome(nome);
    fflush(stdin);
}
//escreve o nome do objeto corrente
void Pessoa::escrevaNome(){
    cout << endl << "Nome: " << getNome() << endl;
}
//le o nome e o nascimento e seta no objeto corrente
void Pessoa::leiaPessoa(){
    leiaNome();
    this->nascimento.leiaData();
}
//escreve os dados do objeto corrente
void Pessoa::escrevaPessoa(){
    escrevaNome();
    this->nascimento.escrevaData();
}
//definicao da classe Aluno, especializacao de Pessoa
class Aluno: public Pessoa{
private:
    //atributos
    int matricula;
public:
    static int quantidadeAluno;
    //construtores e destrutores
    Aluno(){
        quantidadeAluno++;
    }
    Aluno(string nome, int dia, int mes, int ano, int matricula){
        quantidade++;
        setNome(nome);
        this->nascimento.setData(dia, mes, ano);
        setMatricula(matricula);
    }
    ~Aluno(){
        cout << "Aluno apagado com sucesso" << endl;
    }
    //assinaturas dos metodos
    bool setMatricula(int matricula);
    int getMatricula();
    void leiaMatricula();
    void escrevaMatricula();
    void escrevaPessoa();
};
//inicializacao do atributo estatico
int Aluno::quantidadeAluno = 0;
//sets
bool Aluno::setMatricula(int matricula){
    bool valido = true;
    if(matricula > 0){
        this->matricula = matricula;
    }
    else valido = false;
    return valido;
}
//gets
int Aluno::getMatricula(){
    return this->matricula;
}
//le a matricula e seta ela no objeto corrente
void Aluno::leiaMatricula(){
    int matricula;
    do{
        cout << "Digite a matricula: ";
        cin >> matricula;
        if(!setMatricula(matricula)) cout << "Matricula invalida" << endl;
    }while(!setMatricula(matricula));
}
//escreve a matricula do objeto corrente
void Aluno::escrevaMatricula(){
    cout << "Matricula: " << getMatricula() << endl;
}
//escreve os dados do objeto corrente
void Aluno::escrevaPessoa(){
    Pessoa::escrevaPessoa();
    escrevaMatricula();
}
//definicao da classe Professor especializacao de Pessoa
class Professor: public Pessoa{
private:
    //atributos
    string titulacao;
public:
    static int quantidadeProfessor;
    //construtores e destrutores
    Professor(){
        quantidadeProfessor++;
    }
    Professor(string nome, int dia, int mes, int ano, string titulacao){
        quantidade++;
        setNome(nome);
        this->nascimento.setData(dia, mes, ano);
    }
    ~Professor(){
        cout << "Professor apagado com sucesso" << endl;
    }
    //assinaturas dos metodo
    bool setTitulacao(string titulacao);
    string getTitulacao();
    void leiaTitulacao();
    void escrevaTitulacao();
    void escrevaPessoa();
};
//inicializacao do atributo estatico
int Professor::quantidadeProfessor = 0;
//sets
bool Professor::setTitulacao(string titulacao){
    bool valido = true;
    if(titulacao == "Especialista" || titulacao == "Mestre" || titulacao == "Doutor" || titulacao == "especialista" || titulacao == "mestre" || titulacao == "doutor"){
        this->titulacao = titulacao;
    }
    else valido = false;
    return valido;
}
//gets
string Professor::getTitulacao(){
    return this->titulacao;
}
//le a titulacao e, se valida, guarda no objeto corrente
void Professor::leiaTitulacao(){//colocar condicao
    string titulacao;
    do{
        cout << "Digite a titulacao: ";
        cin >> titulacao;
        if(!setTitulacao(titulacao)) cout << "Titulacao invalida!" << endl;
    }while(!setTitulacao(titulacao));
}
//escreve a titulacao do objeto corrente
void Professor::escrevaTitulacao(){
    cout << "Titulacao: " << getTitulacao() << endl;
}
//escreve os dados do objeto corrente
void Professor::escrevaPessoa(){
    Pessoa::escrevaPessoa();
    escrevaTitulacao();
}
