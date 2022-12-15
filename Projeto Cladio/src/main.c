/**
 * Authors: Lucas Raphael Moreira Nogureira, 14/12/2022
 *          Luiz Ant�nio Vilhena Marangoni Silva
 *			Victor Hugo Pires
 *			Rog�rio Teixeira de Siqueira
 *
 * Copyright
 * Description: Esse c�digo foi feito com o intuito de ser um beta para uma possiv�l aplica��o
 * m�dica que visa conter todos os registros m�dicos do passiente.
 *
 **/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "raylib.h"
#include "AdicionarNovoHistorico.h"
#include "TelaPrincipal.h"

int main(void)
{
    int telas = 0;
    int id = 0;
    listaDePessoas listaDePacientes;
    listaDePacientes.fim = NULL;
    listaDePacientes.inicio = NULL;
    insereBancoDeDados(&listaDePacientes);
    SetTargetFPS(60);

    InitWindow(1280,720, "HealthyPP");

    while (!WindowShouldClose())
    {
        switch (telas)
        {
        case 0:
            telas = TelaPrincipal();
            break;
        case 1:
            telas = TelaCadastro(&listaDePacientes);
            break;
        case 2:
            telas = PesquisarPaciente(&listaDePacientes, &id);
            break;
        case 3:
            telas = InformacoesDoPaciente(&listaDePacientes, id);
            break;
        case 4:
            telas = NovaConsulta(&listaDePacientes);
        }
    }

    CloseWindow();
    return 0;
}
