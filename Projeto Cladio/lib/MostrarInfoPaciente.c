#include "MostrarInfoPacientes.h"
#include "raylib.h"

bool fundoInfo = true;

int InformacoesDoPaciente(listaDePessoas *lista, int id)
{
    BeginDrawing();
    if(fundoInfo)
    {
        ClearBackground(RAYWHITE);
        fundoInfo = false;
    }
    pesquisaPorId(lista, id);
    EndDrawing();
    return 3;
}