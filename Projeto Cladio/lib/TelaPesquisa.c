#include "TelaPesquisa.h"
#include "raylib.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool caixaNomeP = false;
bool caixaIdP = false;
bool setar0 = true;
bool mostrarNomes = false;
bool fundo = true;

int letterCountNomeP = 0;
int letterCountIdP = 0;


int PesquisarPaciente(listaDePessoas *lista, int *idP)
{
    receber info;
    Color Cinzabonito = {200,200,200,255};
    Color Cinzabonito2 = {180,180,180,255};

    Image lupa2 = LoadImage("../images/lupa.png");
    ImageResize(&lupa2, 50, 50); 
    Texture2D lupa =  LoadTextureFromImage(lupa2);

    Rectangle CampoNome = {10,10,1100,60};
    Rectangle CampoId = {1120,10,150,60};
    Rectangle pesquisaId= {1210,10,60,60};
    Rectangle voltar = {1070,650,200,60};

    if(setar0)
    {
        info.nome[0] = '\0';
        info.id[0] = '\0';
        setar0 = false;
    }

    if (CheckCollisionPointRec(GetMousePosition(), CampoNome) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {

            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            caixaNomeP = true;
            caixaIdP = false;

        }


            if(caixaNomeP)
            {
                int key = GetCharPressed();


                    if ((key >= 32) && (key <= 125) && (letterCountNomeP < 39))
                     {
                        info.nome[letterCountNomeP] = toupper((char)key);
                        info.nome[letterCountNomeP+1] = '\0'; 
                        letterCountNomeP++;
                    }   

                     key = GetCharPressed();

                    if (IsKeyPressed(KEY_BACKSPACE))
                    {
                        letterCountNomeP--;
                        if (letterCountNomeP < 0) letterCountNomeP = 0;
                        info.nome[letterCountNomeP] = '\0';
                    }
            }

        else
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);


    if (CheckCollisionPointRec(GetMousePosition(), CampoId) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {

            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            caixaIdP = true;
            caixaNomeP = false;

        }


            if(caixaIdP)
            {
                int key = GetCharPressed();


                    if ((key >= 32) && (key <= 125) && (letterCountIdP < 3))
                     {
                        info.id[letterCountIdP] = toupper((char)key);
                        info.id[letterCountIdP+1] = '\0'; 
                        letterCountIdP++;
                    }   

                     key = GetCharPressed();

                    if (IsKeyPressed(KEY_BACKSPACE))
                    {
                        letterCountIdP--;
                        if (letterCountIdP < 0) letterCountIdP = 0;
                        info.id[letterCountIdP] = '\0';
                    }
            }
        else
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    
    if (CheckCollisionPointRec(GetMousePosition(), voltar) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
    {
        setar0 = true;
        UnloadTexture(lupa);
        UnloadImage(lupa2);
        return 0;
    }

    if (CheckCollisionPointRec(GetMousePosition(), pesquisaId) && IsMouseButtonDown(MOUSE_LEFT_BUTTON) && strcmp(info.id,"") != 0)
    {
        info.idI = atoi(info.id);
        setar0 = true;
        *idP = info.idI;
        UnloadTexture(lupa);
        UnloadImage(lupa2);
        return 3;
    }

    BeginDrawing();
    if(fundo)
    {
        ClearBackground(RAYWHITE);
    }
        pesquisaPorNome(lista, info.nome);


    DrawRectangleRec(CampoNome, Cinzabonito);
    DrawRectangleLines((int)CampoNome.x, (int)CampoNome.y, (int)CampoNome.width, (int)CampoNome.height, DARKGRAY);

    DrawRectangleRec(CampoId, Cinzabonito);
    DrawRectangleLines((int)CampoId.x, (int)CampoId.y, (int)CampoId.width, (int)CampoId.height, DARKGRAY);
    DrawRectangleRec(pesquisaId, DARKBLUE);
    DrawRectangleLines((int)pesquisaId.x, (int)pesquisaId.y, (int)pesquisaId.width, (int)pesquisaId.height, DARKGRAY);
    DrawTexture(lupa,(int)pesquisaId.x+6, (int)pesquisaId.y+6, BLACK);

    DrawRectangleRounded(voltar, 0.6, 64, DARKBLUE);
    DrawRectangleRoundedLines(voltar, 0.6, 64, 3, BLACK);
    DrawText("VOLTAR",(int)voltar.x+ 14, (int)voltar.y + 12, 40, BLACK);

    if(caixaNomeP)
        DrawRectangleLines((int)CampoNome.x, (int)CampoNome.y, (int)CampoNome.width, (int)CampoNome.height, RED);
    else
    {
        if(strcmp(info.nome,"") == 0)
            DrawText("DIGITE AQUI SEU NOME",(int)CampoNome.x+ 12, (int)CampoNome.y + 8, 40, Cinzabonito2);
    }
    DrawText(info.nome,(int)CampoNome.x+ 12, (int)CampoNome.y + 8, 40, DARKGRAY);
    if(caixaIdP)


        DrawRectangleLines((int)CampoId.x, (int)CampoId.y, (int)CampoId.width, (int)CampoId.height, RED);
    else
    {
        if(strcmp(info.id,"") == 0)
            DrawText("ID",(int)CampoId.x+ 12, (int)CampoId.y + 8, 40, Cinzabonito2);
    }
    DrawText(info.id,(int)CampoId.x+ 12, (int)CampoId.y + 8, 40, DARKGRAY);


    EndDrawing();
    UnloadImage(lupa2);
    UnloadTexture(lupa);
    return 2;
}
