/**
 * Authors: Lucas Raphael Moreira Nogureira, 14/12/2022
 *          Luiz Antônio Vilhena Marangoni Silva
 *			Victor Hugo Pires
 *			Rogério Teixeira de Siqueira
 * Copyright
 **/
#include "AdicionarNovoHistorico.h"
#include "raylib.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

bool caixaNomeA = false;
bool caixaIdA = false;
bool caixaHistoricoA = false;
bool setar0A = true;
bool fundoA = true;
bool controleNomeA = true;

int letterCountNomeA = 0;
int letterCountIdA = 0;
int letterCountHistoricoA = 0;
int telas = 0;

int NovaConsulta(listaDePessoas *lista)
{

    receber info;
    Color Cinzabonito = {200,200,200,255};
    Color Cinzabonito2 = {180,180,180,255};

    Rectangle CampoNome = {10,10,1100,60};
    Rectangle CampoId = {1120,10,150,60};
    Rectangle pesquisaId= {1210,10,60,60};
    Rectangle voltar = {1070,650,200,60};
    Rectangle Historico = {10,80,1260,60};
    Rectangle Salvar = {490,150,300,50};

    if(controleNomeA)
    {
        info.historico[0] = '\0';
        info.nome[0] = '\0';
        controleNomeA = false;
    }

    Image lupa2 = LoadImage("../images/lupa.png");
    ImageResize(&lupa2, 50, 50);
    Texture2D lupa =  LoadTextureFromImage(lupa2);

    if(setar0A)
    {
        info.nome[0] = '\0';
        info.id[0] = '\0';
        setar0A = false;
    }

    switch (telas)
    {
    case 0:

    if (CheckCollisionPointRec(GetMousePosition(), CampoNome) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {

            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            caixaNomeA = true;
            caixaIdA = false;

        }


            if(caixaNomeA)
            {
                int key = GetCharPressed();


                    if ((key >= 32) && (key <= 125) && (letterCountNomeA < 39))
                     {
                        info.nome[letterCountNomeA] = toupper((char)key);
                        info.nome[letterCountNomeA+1] = '\0';
                        letterCountNomeA++;
                    }

                     key = GetCharPressed();

                    if (IsKeyPressed(KEY_BACKSPACE))
                    {
                        letterCountNomeA--;
                        if (letterCountNomeA < 0) letterCountNomeA = 0;
                        info.nome[letterCountNomeA] = '\0';
                    }
            }

        else
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);


    if (CheckCollisionPointRec(GetMousePosition(), CampoId) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {

            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            caixaIdA = true;
            caixaNomeA = false;

        }


            if(caixaIdA)
            {
                int key = GetCharPressed();


                    if ((key >= 32) && (key <= 125) && (letterCountIdA < 3))
                     {
                        info.id[letterCountIdA] = toupper((char)key);
                        info.id[letterCountIdA+1] = '\0';
                        letterCountIdA++;
                    }

                     key = GetCharPressed();

                    if (IsKeyPressed(KEY_BACKSPACE))
                    {
                        letterCountIdA--;
                        if (letterCountIdA < 0) letterCountIdA = 0;
                        info.id[letterCountIdA] = '\0';
                    }
            }
        else
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);

    if (CheckCollisionPointRec(GetMousePosition(), voltar) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
    {
        setar0A = true;
        UnloadTexture(lupa);
        UnloadImage(lupa2);
        letterCountIdA = 0;
        letterCountNomeA = 0;
        return 0;
    }

    if (CheckCollisionPointRec(GetMousePosition(), pesquisaId) && IsMouseButtonDown(MOUSE_LEFT_BUTTON) && strcmp(info.id,"") != 0)
    {
        info.idI = atoi(info.id);
        if(pesquisaPorId(lista, info.idI) != 4)
        {
        setar0A = true;
        letterCountIdA = 0;
        letterCountNomeA = 0;
        telas = 1;
        }
    }

    BeginDrawing();
    if(fundoA)
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

    if(caixaNomeA)
        DrawRectangleLines((int)CampoNome.x, (int)CampoNome.y, (int)CampoNome.width, (int)CampoNome.height, RED);
    else
    {
        if(strcmp(info.nome,"") == 0)
            DrawText("DIGITE AQUI SEU NOME",(int)CampoNome.x+ 12, (int)CampoNome.y + 8, 40, Cinzabonito2);
    }
    DrawText(info.nome,(int)CampoNome.x+ 12, (int)CampoNome.y + 8, 40, DARKGRAY);
    if(caixaIdA)


        DrawRectangleLines((int)CampoId.x, (int)CampoId.y, (int)CampoId.width, (int)CampoId.height, RED);
    else
    {
        if(strcmp(info.id,"") == 0)
            DrawText("ID",(int)CampoId.x+ 12, (int)CampoId.y + 8, 40, Cinzabonito2);
    }
    DrawText(info.id,(int)CampoId.x+ 12, (int)CampoId.y + 8, 40, DARKGRAY);
    DrawText("PARA SELECIONAR A PESSOA DESEJADA, E NECESSARIO APOS SAEBER O ID, COLOCA-LO E CLICAR NA LUPA",10, 70, 20, RED);


    EndDrawing();
    UnloadImage(lupa2);
    UnloadTexture(lupa);

        break;
    case 1:

    if (CheckCollisionPointRec(GetMousePosition(), Historico) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            caixaHistoricoA = true;
        }


            if(caixaHistoricoA)
            {
                int key = GetCharPressed();


                    if ((key >= 32) && (key <= 125) && (letterCountHistoricoA < 59))
                     {
                        info.historico[letterCountHistoricoA] = toupper((char)key);
                        info.historico[letterCountHistoricoA+1] = '\0';
                        letterCountHistoricoA++;
                    }

                     key = GetCharPressed();

                    if (IsKeyPressed(KEY_BACKSPACE))
                    {
                        letterCountHistoricoA--;
                        if (letterCountHistoricoA < 0) letterCountHistoricoA = 0;
                        info.historico[letterCountHistoricoA] = '\0';
                    }
            }

        else
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        printf("%c",info.historico[0]);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("O QUE VEIO FAZER NO HOSPITAL:", (int)Historico.x , (int)Historico.y -40, 40, BLACK);
        DrawRectangleRec(Historico, Cinzabonito);
        DrawRectangleLines((int)Historico.x, (int)Historico.y, (int)Historico.width, (int)Historico.height, DARKGRAY);

        if(caixaHistoricoA)
            DrawRectangleLines((int)Historico.x, (int)Historico.y, (int)Historico.width, (int)Historico.height, RED);
        DrawText(info.historico, (int)Historico.x + 5, (int)Historico.y + 12, 30, BLACK);

    DrawRectangleRec(Salvar, DARKBLUE);
    DrawRectangleLines((int)Salvar.x, (int)Salvar.y, (int)Salvar.width, (int)Salvar.height, BLACK);
    DrawText("SALVAR", (int)Salvar.x+70, (int)Salvar.y +8, 40, BLACK);


    if (CheckCollisionPointRec(GetMousePosition(), Salvar) && IsMouseButtonDown(MOUSE_LEFT_BUTTON) && strcmp(info.historico,"") != 0)
    {
        DrawRectangleRec(Salvar, GREEN);
        DrawRectangleLines((int)Salvar.x, (int)Salvar.y, (int)Salvar.width, (int)Salvar.height, BLACK);
        DrawText("SALVAR", (int)Salvar.x+70, (int)Salvar.y +8, 40, BLACK);
        insereHistoricoM(lista,info.nome,info.historico,info.idI);
        letterCountHistoricoA = 0;
        controleNomeA = true;
        telas = 0;
        return 0;
    }
    else
    {
        if(CheckCollisionPointRec(GetMousePosition(), Salvar) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            DrawRectangleRec(Salvar, RED);
            DrawRectangleLines((int)Salvar.x, (int)Salvar.y, (int)Salvar.width, (int)Salvar.height, BLACK);
            DrawText("SALVAR", (int)Salvar.x+70, (int)Salvar.y +8, 40, BLACK);
         }
    }
        EndDrawing();

        break;
    }
    return 4;
}
