#ifndef __STAND_H__
#define __STAND_H__

#include <vector>
#include "viatura.h"
#include "menu.h"

namespace RB
{

class Stand
{
public:
    Stand();
    ~Stand();
    void abrirStand();

private:
    // Funções para processar as opções do menu
    void adicionarViatura(void *);
    void visualizarLista(void *);
    void editarViatura(void *);
    void eliminarViatura(void *);
    void abastecerViatura(void *);
    void percorrerDistancia(void *);

    // Funcoes para processar o menu editar viatura
    void editarMarcaViatura(void *arg);
    void editarModeloViatura(void *arg);

    // Utils
    Viatura *findViatura();
    int      findViaturaId();

    // Membros
    Menu                    *m_menuPrincipal;
    std::vector<Viatura>    m_listaViaturas;  
};

}  // namespace RB

#endif  // __STAND_H__