#include "TelaPrincipal.h"
#include "raylib.h"

int TelaPrincipal()
{
    Color  petroFraco= {0,0,0,35};
    Image fundo = LoadImage("../images/fundo.png");
    ImageResize(&fundo, 1280, 720); 
    Texture2D fundoT =  LoadTextureFromImage(fundo);

    Rectangle BotaoDeRegistro = {240,240,400,60};
    Rectangle VerificarListaPacientes = {240,320,400,60};
    Rectangle Sair = {240,400,400,60};

    BeginDrawing();
    DrawTexture(fundoT,0, 0, WHITE);

    DrawRectangleRounded(BotaoDeRegistro, 0.6, 64, petroFraco);
    DrawRectangleRoundedLines(BotaoDeRegistro, 0.6, 64, 3, BLACK);
    DrawText("Novo Paciente", (int)BotaoDeRegistro.x +50, (int)BotaoDeRegistro.y+8, 40, BLACK);

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
        return 10;
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

