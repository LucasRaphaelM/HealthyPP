/**
 * Authors: Lucas Raphael Moreira Nogureira, 14/12/2022
 *          Luiz Antônio Vilhena Marangoni Silva
 *			Victor Hugo Pires
 *			Rogério Teixeira de Siqueira
 *
 * Copyright
 * Description: Esse código foi feito com o intuito de ser um beta para uma possivél aplicação
 * médica que visa conter todos os registros médicos do passiente.
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
