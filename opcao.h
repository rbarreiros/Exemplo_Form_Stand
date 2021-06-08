#ifndef __OPCAO_H__
#define __OPCAO_H__

#include <string>
#include <ostream>
#include <functional>

namespace RB
{

class Opcao
{
public:
    /**
     *  Constructor
     * 
     * O callback para a função suporta as novas funcionalidades de c++11
     * que permite chamar uma função dentro de classes através de std::bind
     * para isso, é necessário incluir functional e usar o namespace placeholders
     * para definir o número de argumentos do callback
     * 
     * #include <functional>
     * 
     * using namespace std::placeholders;
     * 
     * // Na class
     * 
     * class AMinhaClasse
     * {
     *      void funcaoASerChamadaPelaOpcao(void *arg);
     * }
     * 
     * // Ao criar o constructor da opcao
     * // - Primeiro argumento : nome da opção
     * // - Segundo argumento  : callback para o método a ser executado quando a opção é escolhida
     * // - Terceiro argumento : um pointer para o que se quer passar para o método a ser executado (pode ser nullptr)
     * 
     * Opcao("A minha opcao 1", std::bind(&AMinhaClasse::funcaoASerChamadaPelaOpcao, this, _1), nullptr);
     * 
     * // Pode-se também usar funções fora de classes, ex:
     * 
     * void aMinhaFuncao(void *arg)
     * {
     * }
     * 
     * int main(int, char**)
     * {
     *  Opcao("A Minha Opcao 2", aMinhaFuncao, nullptr);
     *  return 0;
     * }
     * 
     * 
     */
    Opcao(std::string nome, std::function<void(void*)> cb, void *arg = nullptr)
        : m_nome(nome), m_cb(cb), m_arg(arg) {}

    /**
     * run
     * 
     *  Executa a funcao que foi anexada a esta opcao
     *  com o argumento arg (pode ser null)
     */
    void run() { m_cb(m_arg); }

    /**
     * operator<<
     * 
     * Overload para o <<
     * ex:
     * Opcao teste("Teste", funcaoTeste);
     * cout << teste;
     */
    friend std::ostream &operator<<(std::ostream &output, const Opcao &opt)
    { 
        output << opt.m_nome;
        return output;            
    }

private:
    void *m_arg;                         // Argumento para passar à função a chamar
    std::string m_nome;                  // nome desta opção
    std::function<void(void*)> m_cb;     // função a chamar quando esta opção for seleccionada
};

}  // namespace RB

#endif  // __OPCAO_H__