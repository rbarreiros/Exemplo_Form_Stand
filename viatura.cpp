#include "viatura.h"
#include <iostream>

using namespace std;
using namespace RB;

Viatura::Viatura()
    : m_kms(0),
      m_deposito(0),
      m_estado(PARADO)
{
}

Viatura::Viatura(std::string marca, std::string modelo, std::string matricula, double deposito)
    : m_marca(marca),
      m_modelo(modelo),
      m_matricula(matricula),
      m_maxDeposito(deposito),
      m_kms(0),
      m_deposito(0),
      m_estado(PARADO)
{
}

string Viatura::getEstadoToString(Estado estado)
{
    switch(estado)
    {
        case PARADO:
            return "Parado";
            break;
        case ANDAMENTO:
            return "Andamento";
            break;
    }

    return string();
}

void Viatura::abastecer(double litros)
{
    if (litros + m_deposito > m_maxDeposito)
    {
        cout << "Abastacer " << litros << "l excede a capacidade do depósito em " << (litros + m_deposito) - m_maxDeposito << "l." << endl;
        return;
    }

    m_deposito += litros;
    cout << "Abasteceu " << litros << "l e tem um total de " << m_deposito << "l na viatura." << endl;
}

void Viatura::percorrerDistancia(double kms)
{
    double consumido = kms * Consumo;

    if(consumido > m_deposito)
    {
        cout << "O seu depósito com " << m_deposito << "l não lhe permite percorrer " << kms << "km" << endl;
        return;
    }

    m_kms += kms;
    m_deposito -= consumido;
    m_estado = ANDAMENTO;
}

void Viatura::terminarMarcha()
{
    m_estado = PARADO;
}

void Viatura::prettyPrintEstado()
{
    cout << "            Estado da viatura " << endl;
    cout << " ------------------------------------------ " << endl;
    cout << "   Marca:\t " << m_marca << "\tModelo:\t" << m_modelo << endl;
    cout << "   Matrícula: " << m_matricula << endl;
    cout << "   ______________________________________" << endl;
    cout << "   KM percorridos:\t" << m_kms << endl;
    cout << "   Depósito:\t\t" << m_deposito << endl;
    cout << "   Estado:\t" << getEstadoToString(m_estado) << endl;
    cout << " ------------------------------------------ " << endl;
}

void Viatura::prettyPrint()
{
    cout << "            Viatura " << endl;
    cout << " ------------------------------------------ " << endl;
    cout << "   Marca:\t " << m_marca << "\tModelo:\t" << m_modelo << endl;
    cout << "   Matrícula: " << m_matricula << endl;
    cout << " ------------------------------------------ " << endl;
}

string Viatura::toString()
{
    return m_marca + " - " + m_modelo + "(" + m_matricula +")";
}