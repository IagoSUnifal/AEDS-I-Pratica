/* 
 * File:   main.cpp
 * Author: Iago Sachsida Teixeira Rassilan Braga
 *
 * Created on 29 de abril de 2024, 16:28
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef struct Pessoa {
    string nome;
    string celular;
    string cidade;
    string email;
    bool valido;
} Pessoa;

//Adiciona um contato na agenda
void incluirContato(Pessoa agenda[], int& qtde) {
    if (qtde < 100) {
        cout << "Nome: ";
        cin >> agenda[qtde].nome;
        cout << "Celular: ";
        cin >> agenda[qtde].celular;
        cout << "Cidade: ";
        cin >> agenda[qtde].cidade;
        cout << "Email: ";
        cin >> agenda[qtde].email;

        agenda[qtde].valido = true;
        qtde++;
        cout << "Contato adicionado com sucesso!" << endl;

        ofstream arquivo("amigo.txt", ios::app);
        if (arquivo.is_open()) {
            arquivo << agenda[qtde - 1].nome << " " << agenda[qtde - 1].celular << " " << agenda[qtde - 1].cidade << " " << agenda[qtde - 1].email << endl;
            arquivo.close();
        } else {
            cout << "Erro ao abrir o arquivo amigo.txt." << endl;
        }
    } else {
        cout << "A agenda está cheia." << endl;
    }
}

//Remove o contato da agenda
void excluirContato(Pessoa agenda[], int& qtde) {
    if (qtde > 0) {
        string nome;
        cout << "Digite o nome do contato a ser excluído: ";
        cin >> nome;

        for (int i = 0; i < qtde; i++) {
            if (agenda[i].nome == nome) {
                agenda[i].valido = false;
                cout << "Contato excluído com sucesso!" << endl;

                ofstream arquivo("amigo.txt");
                if (arquivo.is_open()) {
                    for (int j = 0; j < qtde; j++) {
                        if (agenda[j].valido) {
                            arquivo << agenda[j].nome << " " << agenda[j].celular << " " << agenda[j].cidade << " " << agenda[j].email << endl;
                        }
                    }
                    arquivo.close();
                } else {
                    cout << "Erro ao abrir o arquivo amigo.txt." << endl;
                }

                return;
            }
        }
        cout << "Contato não encontrado." << endl;
    } else {
        cout << "A agenda está vazia." << endl;
    }
}

//Procura um nome na agenda
void procurarContato(const Pessoa agenda[], int qtde) {
    string nome;
    cout << "Digite o nome do contato a ser procurado: ";
    cin >> nome;

    for (int i = 0; i < qtde; i++) {
        if (agenda[i].nome == nome && agenda[i].valido) {
            cout << "Nome: " << agenda[i].nome << endl;
            cout << "Celular: " << agenda[i].celular << endl;
            cout << "Cidade: " << agenda[i].cidade << endl;
            cout << "Email: " << agenda[i].email << endl;
            return;
        }
    }
    cout << "Contato não encontrado." << endl;
}

//Arquivo amigo.txt
void carregarAgenda(Pessoa agenda[], int& qtde) {
    ifstream arquivo("amigo.txt");
    if (arquivo.is_open()) {
        while (qtde < 100 && arquivo >> agenda[qtde].nome >> agenda[qtde].celular >> agenda[qtde].cidade >> agenda[qtde].email) {
            agenda[qtde].valido = true;
            qtde++;
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo amigo.txt." << endl;
    }
}

//Menu de operações da agenda
int main() {
    Pessoa agenda[100];
    int qtde = 0, op;

    carregarAgenda(agenda, qtde);

    do {
        cout << "1- Incluir contato" << endl;
        cout << "2- Excluir contato" << endl;
        cout << "3- Procurar contato" << endl;
        cout << "0- Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> op;

        switch (op) {
            case 1:
                incluirContato(agenda, qtde);
                break;
            case 2:
                excluirContato(agenda, qtde);
                break;
            case 3:
                procurarContato(agenda, qtde);
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    } while (op != 0);

    return 0;
}
