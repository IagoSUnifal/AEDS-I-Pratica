#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// Funções para cálculo de área e volume dos objetos geométricos
double calcularAreaQuadrado(double lado) {
    return lado * lado;
}

double calcularAreaRetangulo(double comprimento, double largura) {
    return comprimento * largura;
}

double calcularAreaTriangulo(double base, double altura) {
    return (base * altura) / 2;
}

double calcularVolumeCubo(double lado) {
    return pow(lado, 3);
}

double calcularVolumeParalelepipedo(double comprimento, double largura, double altura) {
    return comprimento * largura * altura;
}

double calcularVolumeCilindro(double raio, double altura) {
    return M_PI * pow(raio, 2) * altura;
}

double calcularVolumeCone(double raio, double altura) {
    return (M_PI * pow(raio, 2) * altura) / 3;
}

double calcularVolumeEsfera(double raio) {
    return (4.0 / 3.0) * M_PI * pow(raio, 3);
}

int main() {
    ifstream arquivo("cenagrafica.txt"); // Abre o arquivo para leitura
    string tipo;
    double parametro1, parametro2, parametro3;
    double areaTotal = 0, volumeTotal = 0;

    if (!arquivo.is_open()) { // Verifica se o arquivo foi aberto corretamente
        cout << "Erro ao abrir o arquivo.\n";
        return 1;
    }

    while (arquivo >> tipo && tipo != "fim") { // Lê o tipo de objeto até encontrar "fim"
        if (tipo == "quadrado") {
            arquivo >> parametro1;
            areaTotal += calcularAreaQuadrado(parametro1);
        } else if (tipo == "retangulo") {
            arquivo >> parametro1 >> parametro2;
            areaTotal += calcularAreaRetangulo(parametro1, parametro2);
        } else if (tipo == "triangulo") {
            arquivo >> parametro1 >> parametro2;
            areaTotal += calcularAreaTriangulo(parametro1, parametro2);
        } else if (tipo == "cubo") {
            arquivo >> parametro1;
            volumeTotal += calcularVolumeCubo(parametro1);
        } else if (tipo == "paralelepipedo") {
            arquivo >> parametro1 >> parametro2 >> parametro3;
            volumeTotal += calcularVolumeParalelepipedo(parametro1, parametro2, parametro3);
        } else if (tipo == "cilindro") {
            arquivo >> parametro1 >> parametro2;
            volumeTotal += calcularVolumeCilindro(parametro1, parametro2);
        } else if (tipo == "cone") {
            arquivo >> parametro1 >> parametro2;
            volumeTotal += calcularVolumeCone(parametro1, parametro2);
        } else if (tipo == "esfera") {
            arquivo >> parametro1;
            volumeTotal += calcularVolumeEsfera(parametro1);
        } else {
            cout << "Tipo de objeto desconhecido: " << tipo << endl;
        }
    }

    arquivo.close(); // Fecha o arquivo após a leitura

    cout << "Área total da cena: " << areaTotal << endl;
    cout << "Volume total da cena: " << volumeTotal << endl;

    return 0;
}


