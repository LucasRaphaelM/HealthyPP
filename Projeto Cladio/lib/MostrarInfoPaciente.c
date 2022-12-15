/**
 * Authors: Lucas Raphael Moreira Nogureira, 14/12/2022
 *          Luiz Antônio Vilhena Marangoni Silva
 *			Victor Hugo Pires
 *			Rogério Teixeira de Siqueira
 * Copyright
 **/
#include "MostrarInfoPacientes.h"
#include "raylib.h"

bool fundoInfo = true;

int InformacoesDoPaciente(listaDePessoas *lista, int id)
{
    Rectangle voltar = {1070,650,200,60};

    BeginDrawing();
    if(fundoInfo)
    {
        ClearBackground(RAYWHITE);
        fundoInfo = false;
    }
    pesquisaPorId(lista, id);
    DrawRectangleRounded(voltar, 0.6, 64, DARKBLUE);
    DrawRectangleRoundedLines(voltar, 0.6, 64, 3, BLACK);
    DrawText("VOLTAR",(int)voltar.x+ 14, (int)voltar.y + 12, 40, BLACK);
    EndDrawing();

    if (CheckCollisionPointRec(GetMousePosition(), voltar) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
    {
        fundoInfo = true;
        return 0;
    }
    return 3;
}
