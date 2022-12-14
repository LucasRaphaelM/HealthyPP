#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "raylib.h"
#include "TelaPrincipal.h"
#include "MostrarInfoPacientes.h"

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
        }
    }

    CloseWindow();  
    return 0;
}