#ifndef __VIATURA_H__
#define __VIATURA_H__

#include <string>

namespace RB
{

class Viatura 
{
public:
    enum Estado {
        PARADO,
        ANDAMENTO
    };

    Viatura();
    Viatura(std::string marca, std::string modelo, std::string matricula, double deposito);

    void setMarca(std::string marca)         { m_marca = marca; }
    void setModelo(std::string modelo)       { m_modelo = modelo; }
    void setMatricula(std::string matricula) { m_matricula = matricula; }
    void setMaxDeposito(double deposito)     { m_maxDeposito = deposito; }
    
    std::string getMarca()      { return m_marca; }
    std::string getModelo()     { return m_modelo; }
    std::string getMatricula()  { return m_matricula; }
    double getMaxDeposito()     { return m_maxDeposito; }
    int getKms()                { return m_kms; }
    double getDeposito()        { return m_deposito; }
    Estado getEstado()          { return m_estado; }

    std::string getEstadoToString(Estado estado);
    void abastecer(double litros);
    void percorrerDistancia(double kms);
    void terminarMarcha();
    
    void prettyPrintEstado();
    void prettyPrint();
    std::string toString();

private:
    static constexpr double Consumo = 0.450;

    std::string m_marca;
    std::string m_modelo;
    std::string m_matricula;
    int m_kms;
    double m_maxDeposito;
    double m_deposito;
    Estado m_estado;


};

}  // namespace RB

#endif  // __VIATURA_H__