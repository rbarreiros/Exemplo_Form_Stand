
#include "stand.h"
#include "opcao.h"

#include <iostream>
#include <cstdlib>
#include <strings.h>

using namespace std;
using namespace RB;
using namespace std::placeholders;

Stand::Stand()
{
    // Inizializar tudo no constuctor

    // Menu, usamos um pointer, porque assim podemos inicializar aqui
    // o menu
    m_menuPrincipal = new Menu("Menu Principal");

    // Adicionar opções
    m_menuPrincipal->addOption(Opcao("Adicionar Viatura", std::bind(&Stand::adicionarViatura, this, _1), nullptr));
    m_menuPrincipal->addOption(Opcao("Visualizar Lista", std::bind(&Stand::visualizarLista, this, _1), nullptr));
    m_menuPrincipal->addOption(Opcao("Editar Viatura", std::bind(&Stand::editarViatura, this, _1), nullptr));
    m_menuPrincipal->addOption(Opcao("Eliminar Viatura", std::bind(&Stand::eliminarViatura, this, _1), nullptr));
    m_menuPrincipal->addOption(Opcao("Abastecer Viatura", std::bind(&Stand::abastecerViatura, this, _1), nullptr));
    m_menuPrincipal->addOption(Opcao("Percorrer Distância", std::bind(&Stand::percorrerDistancia, this, _1), nullptr));

    // Para testar
    m_listaViaturas.push_back(Viatura("qwe", "asd", "123", 123));

}

Stand::~Stand()
{
    // Destructor para limpar a memória
    if(m_menuPrincipal)
        delete m_menuPrincipal;
}

void Stand::abrirStand()
{
    m_menuPrincipal->runMenu();
}

// Privadas

void Stand::adicionarViatura(void *)
{
    string tmp;
    double deposito = 0.0;
    Viatura viatura;

    cout << "Insira a marca da viatura: ";
    getline(cin, tmp);
    viatura.setMarca(tmp);

    cout << "Insira o modelo da viatura: ";
    getline(cin, tmp);
    viatura.setModelo(tmp);

    cout << "Insira a matricula da viatura: ";
    getline(cin, tmp);
    viatura.setMatricula(tmp);

    cout << "Indique qual o tamanho do depósito: ";
    cin >> deposito;
    viatura.setMaxDeposito(deposito);

    m_listaViaturas.push_back(viatura);
}

void Stand::visualizarLista(void *)
{
    cout << "\t\tLista de viaturas" << endl;
    cout << "----------------------------------------------------" << endl;

    for(auto viatura : m_listaViaturas)
    {
        viatura.prettyPrintEstado();
    }
}

void Stand::editarViatura(void *)
{
    Viatura *v = findViatura();

    if(v == nullptr)
        return;

    cout << "\t\tEditar a viatura: " << endl;

    v->prettyPrintEstado();

    Menu editarMenu("Editar Viatura");
    editarMenu.addOption(Opcao("Editar Marca", std::bind(&Stand::editarMarcaViatura, this, _1), v));
    editarMenu.addOption(Opcao("Editar Modelo", std::bind(&Stand::editarModeloViatura, this, _1), v));

    editarMenu.runMenu();
}

void Stand::eliminarViatura(void *)
{
    int id = findViaturaId();

    if(id < 0)
        return;

    Viatura *v = &m_listaViaturas.at(id);

    cout << "Eliminada a viatura : " << v->toString() << endl;
    m_listaViaturas.erase(m_listaViaturas.begin() + id);
}

void Stand::abastecerViatura(void *)
{
    Viatura *v = findViatura();
    int ltr = 0;

    if(v == nullptr) 
        return;

    cout << "Viatura: " << v->toString() << endl;
    cout << "Depósito actual: " << v->getDeposito()
         << "\tTamanho Depósito: " << v->getMaxDeposito() << endl;
    cout << "Quantos litros deseja abastecer? ";
    cin >> ltr;
    cin.get();

    v->abastecer(ltr);
}

void Stand::percorrerDistancia(void *)
{
    Viatura *v = findViatura();
    int kms;

    if(v == nullptr) 
        return;

    cout << "Quantos kms deve percorrer a viatura? ";
    cin >> kms;
    cin.get();

    v->percorrerDistancia(kms);
    v->prettyPrintEstado();
}

void Stand::editarMarcaViatura(void *arg)
{
    Viatura *v = static_cast<Viatura*>(arg);
    string tmp;

    cout << "Insira a marca da viatura: ";
    getline(cin, tmp);
    v->setMarca(tmp);
}

void Stand::editarModeloViatura(void *arg)
{
    Viatura *v = static_cast<Viatura*>(arg);
    string tmp;

    cout << "Insira o modelo da viatura: ";
    getline(cin, tmp);
    v->setModelo(tmp);
}

// Utils

int Stand::findViaturaId()
{
    int op;
    int id = -1;
    string matricula;

    system("clear");

    for(int i = 0; i < m_listaViaturas.size(); i++)
        cout << i << ") " << m_listaViaturas.at(i).getMarca()
             << " - " << m_listaViaturas.at(i).getModelo()
             << " (" << m_listaViaturas.at(i).getMatricula() << ")" 
             << endl << endl;

    cout << "Pesquisar viatura por: " << endl;
    cout << " 1) Matrícula " << endl;
    cout << " 2) ID da listagem " << endl << endl;
    cout << " 0) Voltar." << endl << endl;
    cout << "Escolha a opção: ";
    cin >> op;
    cin.get();

    if(op == 1)
    {
        cout << "Insira a matricula da viatura: ";
        getline(cin, matricula);

        for(int i = 0; i < m_listaViaturas.size(); i++)
        {
            if(strcasecmp(m_listaViaturas.at(i).getMatricula().c_str(), matricula.c_str()) == 0)
                return i;
        }

        // Se chegar aqui, não encontrou matrícula
        cout << "Matrícula " << matricula << " não encontrada." << endl;
        return -1;

    } else if(op == 2)
    {
        cout << "Insira o ID da viatura referente à listagem: ";
        cin >> id;
        cin.get();

        if(id > m_listaViaturas.size())
        {
            cout << "ID Inválido." << endl;
            return -1;
        }

        return id;
    }
    else if(op == 0)
        return -1;
    else 
    {
        cout << "Opção inválida." << endl;
        return -1;
    }

    return -1;
}

Viatura *Stand::findViatura()
{
    int id = findViaturaId();
    if(id < 0)
        return nullptr;

    return &m_listaViaturas.at(id);
}
