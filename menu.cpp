#include "menu.h"
#include <algorithm>
#include <iostream>

using namespace RB;
using namespace std;

/**
 * Constructor
 * 
 * @param nome  Nome do menu
 */
Menu::Menu(std::string nome)
    : m_nome(nome)
{
    m_options.clear();
}

/**
 * addOption
 * 
 * @param Opcao  Opcao a adicionar ao menu
 */
void Menu::addOption(Opcao opt)
{
    m_options.push_back(opt);
}

/**
 * printMenu
 * 
 * Imprime todas as opções do menu inclusivé
 * a opção para sair (0)
 */
void Menu::printMenu()
{
    cout << "--------------------------------------" << endl;
    cout << "\t\t" << m_nome << endl;
    cout << "--------------------------------------" << endl;
    for(int i = 1; i < m_options.size() + 1; i++)
    {
        cout << " " << i << ") " << m_options.at(i - 1) << endl;
    }
    cout << "--------------------------------------" << endl;
    cout << " 0) Sair" << endl;
    cout << "--------------------------------------" << endl;
}

/**
 * runMenu
 * 
 * Executa o menu.
 * Entra num loop infinito até o utilizador sair com a opção 0
 * todas as outras opções, executa a opção seleccionada.
 */
void Menu::runMenu()
{
    int op;

    do
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        printMenu();
        cout << "Seleccione a opção: ";
        cin >> op;
        cin.get();

        if(op > 0)
        {
            if((op - 1) < m_options.size())
            {
                m_options.at(op - 1).run();
                waitForInput();
            }
        }

    } while(op != 0);

}

// Privates

/**
 * waitForInput
 * 
 * Notifica o utilizador para pressionar enter/return para
 * continuar e aguarda pelo input
 */
void Menu::waitForInput()
{
    cout << "Pressione enter/return para continuar ..." << endl;
    cin.get();
}