#include <iostream>
#include "pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define _MAX 1000
//Autor: Filipi Pereira
using std::bad_alloc;
//Protótipos:
int menu();
int menu2();
void cadastra(Aluno* alunos[], Professor* professores[]);
void cadastraAluno(Aluno* alunos[]);
void cadastraProfessor(Professor* professores[]);
void lista(Aluno* alunos[], Professor* professores[]);
void listaAlunos(Aluno* alunos[]);
void listaProfessores(Professor* professores[]);
void altera(Aluno* alunos[], Professor* professores[]);
void alteraAluno(Aluno* alunos[]);
void alteraProfessor(Professor* professores[]);
void exclui(Aluno* alunos[], Professor* professores[]);
void excluiAluno(Aluno* alunos[]);
void excluiProfessor(Professor* professores[]);
void listaAniversariantes(Aluno* alunos[], Professor* professores[]);

int main(){//begin main
    FILE* arq1;
    //le os daods
    if((arq1 = fopen("quantidades.dat", "r+")) != NULL){
        fscanf(arq1, "%d", &Aluno::quantidadeAluno);
        fscanf(arq1, "%d", &Professor::quantidadeProfessor);
    }
    FILE* arq;
    Aluno* alunos[_MAX];
    Professor* professores[_MAX];
    if((arq = fopen("dados.dat", "rb")) != NULL){
        for(int i = 0; i < Aluno::quantidadeAluno; i++){
            alunos[i] = new Aluno;
            fread(alunos[i], sizeof(Aluno), 1, arq);
        }
        for(int i = 0; i < Professor::quantidadeProfessor; i++){
            professores[i] = new Professor;
            fread(professores[i], sizeof(Professor), 1, arq);
        }
    }

    int escolha;
    do{
        escolha = menu();
        switch(escolha){
            case 0: cout << "Obrigado!";
                break;
            case 1: try{
                        cadastra(alunos, professores);
                    }
                    catch(bad_alloc memoryAllocationException){
                        cout << "Exception occurred:" << memoryAllocationException.what() << endl;
                        cout << "\nMemoria insuficiente" << endl;
                    }
                break;
            case 2: lista(alunos, professores);
                break;
            case 3: altera(alunos, professores);
                break;
            case 4: exclui(alunos, professores);
                break;
            case 5: listaAniversariantes(alunos, professores);
                break;
        }
    }while(escolha != 0);
    //guarda os dados
    rewind(arq);
    Aluno aluno[Aluno::quantidadeAluno];
    for(int i = 0; i < Aluno::quantidadeAluno; i++){
        aluno[i].setNome(alunos[i]->getNome());
        aluno[i].getNascimento().setDia(alunos[i]->getNascimento().getDia());
        aluno[i].getNascimento().setMes(alunos[i]->getNascimento().getMes());
        aluno[i].getNascimento().setAno(alunos[i]->getNascimento().getAno());
        aluno[i].setMatricula(alunos[i]->getMatricula());
    }
    Professor professor[Professor::quantidadeProfessor];
    for(int i = 0; i < Professor::quantidadeProfessor; i++){
        professor[i].setNome(professores[i]->getNome());
        professor[i].getNascimento().setDia(professores[i]->getNascimento().getDia());
        professor[i].getNascimento().setMes(professores[i]->getNascimento().getMes());
        professor[i].getNascimento().setAno(professores[i]->getNascimento().getAno());
        professor[i].setTitulacao(professores[i]->getTitulacao());
    }
    fwrite(aluno, sizeof(Aluno), Aluno::quantidadeAluno, arq);
    fwrite(professor, sizeof(Professor), Professor::quantidadeProfessor, arq);
    fclose(arq);
    rewind(arq1);
    fprintf(arq1, "%d\n", Aluno::quantidadeAluno);
    fprintf(arq1, "%d\n", Professor::quantidadeProfessor);
    fclose(arq1);
    return 0;
}//end main
//funçao que mostra o primeiro menu e retorna a opcao selecionada
int menu(){
    int escolha;
    bool erro;
    cout << "\n0: Sair\n1: Cadastrar(A/P) \n2: Listar(A/P)\n3: Alterar(A/P)\n4: Excluir(A/P)\n5: Listar os aniversariantes do mes\n" << endl;
    cout << "Escolha sua opcao: ";
    do{
        cin >> escolha;
        erro = escolha < 0 || escolha > 5;
        if(erro) cout << "Opcao invalida, tente novamente" << endl;
    }while(erro);
    return escolha;
}
//funcao que mostra o segundo menu e retorna a opcao selecionada
int menu2(){
    int escolha;
    bool erro;
    cout << "\n0: Retornar\n1: Aluno\n2: Professor" << endl;
    cout << "Escolha sua opcao: ";
    do{
        cin >> escolha;
        erro = escolha < 0 || escolha > 2;
        if(erro) cout << "Opcao invalida, tente novamente" << endl;
    }while(erro);
    return escolha;
}
//funcao que recebe os vetores e rediriciona para a outra funcao(alunos/ professores)
void cadastra(Aluno* alunos[], Professor* professores[]){
    int escolha = menu2();
    switch(escolha){
            case 0: cout << "Voltando para o menu" << endl;
                break;
            case 1: cadastraAluno(alunos);
                break;
            case 2: cadastraProfessor(professores);
                break;
        }
}
//funcao que recebe vetor de aluno e cadastra um novo aluno
void cadastraAluno(Aluno* alunos[]){
    alunos[Aluno::quantidadeAluno - 1] = new Aluno;
    alunos[Aluno::quantidadeAluno - 1]->leiaPessoa();
    alunos[Aluno::quantidadeAluno - 1]->leiaMatricula();
}
//funcao que recebe o vetor de professores e cadastra um novo professor
void cadastraProfessor(Professor* professores[]){
    professores[Professor::quantidadeProfessor - 1] = new Professor;
    professores[Professor::quantidadeProfessor - 1]->leiaPessoa();
    professores[Professor::quantidadeProfessor - 1]->leiaTitulacao();
}
//funcao que recebe os vetores e direciona para outra funcao(alunos/professores)
void lista(Aluno* alunos[], Professor* professores[]){
    int escolha = menu2();
    switch(escolha){
            case 0: cout << "Voltando para o menu" << endl;
                break;
            case 1: listaAlunos(alunos);
                break;
            case 2: listaProfessores(professores);
                break;
        }
}
//funcao que recebe o vetor de alunos e lista os alunos
void listaAlunos(Aluno* alunos[]){
    if(Aluno::quantidadeAluno == 0) cout << "Ainda nao ha alunos" << endl;
    else{
        for(int i = 0; i < Aluno::quantidadeAluno; i++){
            alunos[i]->escrevaPessoa();
            cout << "Posicao: " << i+1 << endl;
        }
    }
}
//funcao que recebe o vetor de professores e lista os professores
void listaProfessores(Professor* professores[]){
    if(Professor::quantidadeProfessor == 0) cout << "Ainda nao ha professores" << endl;
    else{
        for(int i = 0; i < Professor::quantidadeProfessor; i++){
            professores[i]->escrevaPessoa();
            cout << "Posicao: " << i+1 << endl;
        }
    }
}
//funcao que recebe os vetores e redireciona para outra funcao(alunos/professores)
void altera(Aluno* alunos[], Professor* professores[]){
    int escolha = menu2();
    switch(escolha){
            case 0: cout << "Voltando para o menu" << endl;
                break;
            case 1: alteraAluno(alunos);
                break;
            case 2: alteraProfessor(professores);
                break;
        }
}
//funcao que recebe o vetor de alunos e altera um aluno definido pela posicao
void alteraAluno(Aluno* alunos[]){
    if(Aluno::quantidadeAluno > 0){
        int posicao;
        bool erro;
        do{
            cout << "Deseja alterar qual posicao? ";
            cin >> posicao;
            erro = posicao < 1 || posicao > Aluno::quantidadeAluno + 1;
            if(erro) cout << "Posicao nao existe" << endl;
        }while(erro);
        alunos[posicao-1]->leiaPessoa();
        alunos[posicao-1]->leiaMatricula();
    }
    else cout << "Nao ha alunos" << endl;
}
//funcao que recebe o vetor de professores e altera um professor definido pela posicao
void alteraProfessor(Professor* professores[]){
    if(Professor::quantidadeProfessor > 0){
        int posicao;
        bool erro;
        do{
            cout << "Deseja alterar qual posicao? ";
            cin >> posicao;
            erro = posicao < 1 || posicao > Professor::quantidadeProfessor + 1;
            if(erro) cout << "Posicao nao existe" << endl;
        }while(erro);
        professores[posicao-1]->leiaPessoa();
        professores[posicao-1]->leiaTitulacao();
    }
    else cout << "Nao ha professores" << endl;
}
//funcao que recebe os vetores e redireciona para outra funcao(aluno/professor)
void exclui(Aluno* alunos[], Professor* professores[]){
    int escolha = menu2();
    switch(escolha){
            case 0: cout << "Voltando para o menu" << endl;
                break;
            case 1: excluiAluno(alunos);
                break;
            case 2: excluiProfessor(professores);
                break;
        }
}
//funcao que recebe o vetor de alunos e exclui um aluno de acordo com a posicao
void excluiAluno(Aluno* alunos[]){
    if(Aluno::quantidadeAluno > 0){
        int posicao;
        bool erro;
        do{
            cout << "Deseja excluir qual posicao? ";
            cin >> posicao;
            erro = posicao < 1 || posicao > Aluno::quantidadeAluno + 1;
            if(erro) cout << "Posicao nao existe" << endl;
        }while(erro);
        delete alunos[posicao - 1];
        for(int i = posicao - 1; i < Aluno::quantidadeAluno - 1; i++){
            alunos[i] = alunos[i+1];
        }
        Aluno::quantidadeAluno--;
    }
    else cout << "Nao ha alunos" << endl;
}
//funcao que recebe o vetor de professores e exclui um professor de acordo com a posicao
void excluiProfessor(Professor* professores[]){
    if(Professor::quantidadeProfessor > 0){
        int posicao;
        bool erro;
        do{
            cout << "Deseja excluir qual posicao? ";
            cin >> posicao;
            erro = posicao < 1 || posicao > Professor::quantidadeProfessor + 1;
            if(erro) cout << "Posicao nao existe" << endl;
        }while(erro);
        delete professores[posicao - 1];
        for(int i = posicao - 1; i < Professor::quantidadeProfessor - 1; i++){
            professores[i] = professores[i+1];
        }
        Professor::quantidadeProfessor--;
    }
    else cout << "Nao ha professores" << endl;
}
//funcao que recebe os vetores e lista os aniversariantes de um determinado mes utilizando polimorfismo
void listaAniversariantes(Aluno* alunos[], Professor* professores[]){
    Pessoa* pessoas[2*_MAX];
    for(int i = 0; i < Aluno::quantidadeAluno; i++){
        pessoas[i] = alunos[i];
    }
    for(int i = 0; i < Professor::quantidadeProfessor; i ++){
        pessoas[Aluno::quantidadeAluno + i] = professores[i];
    }
    int mes;
    cout << "Qual mes? ";
    cin >> mes;
    for(int i = 0; i < Aluno::quantidadeAluno+Professor::quantidadeProfessor; i++){
        if(pessoas[i]->getNascimento().verificaMes(mes)) pessoas[i]->escrevaPessoa();
    }
}
