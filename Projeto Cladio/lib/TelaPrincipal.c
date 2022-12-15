/**
 * Authors: Lucas Raphael Moreira Nogureira, 14/12/2022
 *          Luiz Antônio Vilhena Marangoni Silva
 *			Victor Hugo Pires
 *			Rogério Teixeira de Siqueira
 * Copyright
 **/
#include "TelaPrincipal.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

int TelaPrincipal()
{
    Color  petroFraco= {0,0,0,35};
    Image fundo = LoadImage("../images/fundo.png");
    ImageResize(&fundo, 1280, 720);
    Texture2D fundoT =  LoadTextureFromImage(fundo);

    Rectangle BotaoDeRegistro = {240,200,400,60};
    Rectangle BotaoNovaConsulta = {240,280,400,60};
    Rectangle VerificarListaPacientes = {240,360,400,60};
    Rectangle Sair = {240,440,400,60};

    BeginDrawing();
    DrawTexture(fundoT,0, 0, WHITE);

    DrawRectangleRounded(BotaoDeRegistro, 0.6, 64, petroFraco);
    DrawRectangleRoundedLines(BotaoDeRegistro, 0.6, 64, 3, BLACK);
    DrawText("Novo Paciente", (int)BotaoDeRegistro.x +50, (int)BotaoDeRegistro.y+8, 40, BLACK);

    DrawRectangleRounded(BotaoNovaConsulta, 0.6, 64, petroFraco);
    DrawRectangleRoundedLines(BotaoNovaConsulta, 0.6, 64, 3, BLACK);
    DrawText("Nova Consulta", (int)BotaoNovaConsulta.x +50, (int)BotaoNovaConsulta.y+8, 40, BLACK);

    DrawRectangleRounded(VerificarListaPacientes, 0.6, 64, petroFraco);
    DrawRectangleRoundedLines(VerificarListaPacientes, 0.6, 64, 3, BLACK);
    DrawText("Lista de Pacientes", (int)VerificarListaPacientes.x +12, (int)VerificarListaPacientes.y+8, 40, BLACK);

    DrawRectangleRounded(Sair, 0.6, 64, petroFraco);
    DrawRectangleRoundedLines(Sair, 0.6, 64, 3, BLACK);
    DrawText("Sair", (int)Sair.x +160, (int)Sair.y+8, 40, BLACK);


    EndDrawing();

    if (CheckCollisionPointRec(GetMousePosition(), BotaoDeRegistro))
    {
        SetMouseCursor(4);
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
        UnloadTexture(fundoT);
        UnloadImage(fundo);
        return 1;
        }
    }
    else if (CheckCollisionPointRec(GetMousePosition(), BotaoNovaConsulta))
    {
        SetMouseCursor(4);
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
        UnloadTexture(fundoT);
        UnloadImage(fundo);
        return 4;
        }
    }
    else  if (CheckCollisionPointRec(GetMousePosition(), VerificarListaPacientes))
    {
        SetMouseCursor(4);
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
        UnloadTexture(fundoT);
        UnloadImage(fundo);
        return 2;
        }

    }
    else  if (CheckCollisionPointRec(GetMousePosition(), Sair))
    {
        SetMouseCursor(4);
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
        UnloadTexture(fundoT);
        UnloadImage(fundo);
        exit (0);
        }
    }
    else
    {
        SetMouseCursor(1);
    }
        UnloadTexture(fundoT);
        UnloadImage(fundo);
        return 0;
}

