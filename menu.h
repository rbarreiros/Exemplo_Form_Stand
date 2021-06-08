#ifndef __MENU_H__
#define __MENU_H__

#include "opcao.h"
#include <vector>
#include <string>

namespace RB
{

/**
 * Menu
 * 
 * Sistema muito simples de menus via linha de comandos
 * para os exercicios de aprendizagem de C/C++
 * 
 * Exemplo:
 * 
 * // As funções chamadas pela opção têm que ser da seguinte forma
 * // void nomeDaFuncao(void *argumento)
 * void testeOpcao1(void *argumento)
 * {
 *  if(argumento != nullptr)
 *    cout << *argumento;
 * }
 * 
 * // Criar um menu
 * Menu menuPrincipal("Menu Principal");
 * 
 * // Adicionar opções ao menu
 * // o constructor da classe Opcao é
 * // Opcao("Nome da Opcao", função_a_executar_se_seleccionado, argumento_a_passar_para_a_função_em_pointer)
 * 
 * char textoTeste[] = "Texto de teste";
 * Opcao op1("Opção 1", testeOpcao1, textoTeste);
 * menuPrincipal.addOption(op1);
 * 
 * // Pode também adicionar opcao directamente no addOption
 * 
 * menuPrincipal.addOption(Opcao("Opção 2", testeOpcao1, textoTexte));
 * 
 * // Para executar o menu
 * 
 * menuPrincipal.runMenu();
 * 
 */
class Menu
{
public:
    /**
     * Constructor
     */
    Menu(std::string nome);

    /**
     * addOption
     * 
     * Adicionar opção
     * 
     * @param Opcao
     */
    void addOption(Opcao opt);

    /**
     * runMenu
     * 
     */
    void runMenu();

    /**
     * printMenu
     * 
     */
    void printMenu();

private:
    void waitForInput();            // Espera por um newline para continuar
    std::string m_nome;             // Nome do menu
    std::vector<Opcao> m_options;   // vector com todas as opcoes possíveis do menu
};

}  // namespace RB

#endif  // __MENU_H__