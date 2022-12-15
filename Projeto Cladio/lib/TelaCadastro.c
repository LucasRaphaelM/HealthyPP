/**
 * Authors: Lucas Raphael Moreira Nogureira, 14/12/2022
 *          Luiz Antônio Vilhena Marangoni Silva
 *			Victor Hugo Pires
 *			Rogério Teixeira de Siqueira
 * Copyright
 **/
#include "TelaCadastro.h"
#include "raylib.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool controleNome = true;

bool caixaNome = false;
bool caixaSexo = false;
bool caixaAltura = false;
bool caixaSangue = false;
bool caixaPeso = false;
bool caixaHistorico = false;
bool caixaMedicacoes = false;


int letterCountNome = 0;
int letterCountAltura = 0;
int letterCountHistorico =0;
int letterCountSangue =0;
int letterCountPeso =0;
int letterCountSexo =0;
int framesCounter = 0;
int letterCounterMedicacoes =0;
int id = 11;

int TelaCadastro(listaDePessoas *lista)
{
    Color Cinzabonito = {200,200,200,255};

    Rectangle CampoNome = {10,70,1260,60};
    Rectangle Sexo = {10,210,400,60};
    Rectangle Altura = {480,210,100,60};
    Rectangle Peso = {660,210,100,60};
    Rectangle Sangue = {840,210,130,60};
    Rectangle Historico = {10,350,1260,60};
    Rectangle Medicacoes = {10,490,1260,60};
    Rectangle Salvar = {490,660,300,50};

    receber info;

    if(controleNome)
    {
        info.nome[0] = '\0';
        info.historico[0] = '\0';
        info.pesoc [0]= '\0';
        info.alturac[0]= '\0';
        info.tipoSangue[0] = '\0';
        info.genero [0] = '\0';
        info.medicacoes [0]= '\0';
        controleNome = false;
    }



    if (caixaAltura || caixaHistorico || caixaPeso || caixaSangue || caixaSexo || caixaNome) framesCounter++;
    else framesCounter = 0;

    if (CheckCollisionPointRec(GetMousePosition(), CampoNome) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {

            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            caixaNome = true;
            caixaSexo = false;
            caixaAltura = false;
            caixaSangue = false;
            caixaPeso = false;
            caixaHistorico = false;
            caixaMedicacoes = false;

        }


            if(caixaNome)
            {
                int key = GetCharPressed();


                    if ((key >= 32) && (key <= 125) && (letterCountNome < 39))
                     {
                        info.nome[letterCountNome] = toupper((char)key);
                        info.nome[letterCountNome+1] = '\0';
                        letterCountNome++;
                    }

                     key = GetCharPressed();

                    if (IsKeyPressed(KEY_BACKSPACE))
                    {
                        letterCountNome--;
                        if (letterCountNome < 0) letterCountNome = 0;
                        info.nome[letterCountNome] = '\0';
                    }
            }

        else
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        printf("%c",info.nome[0]);






    if (CheckCollisionPointRec(GetMousePosition(), Altura) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {

            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            caixaAltura = true;
            caixaHistorico = false;
            caixaNome = false;
            caixaPeso = false;
            caixaSangue = false;
            caixaSexo = false;
            caixaMedicacoes = false;
        }


            if(caixaAltura)
            {
                int key = GetCharPressed();


                    if ((key >= 32) && (key <= 125) && (letterCountAltura < 4))
                     {
                        info.alturac[letterCountAltura] = toupper((char)key);
                        info.alturac[letterCountAltura+1] = '\0';
                        letterCountAltura++;
                    }

                     key = GetCharPressed();

                    if (IsKeyPressed(KEY_BACKSPACE))
                    {
                        letterCountAltura--;
                        if (letterCountAltura < 0) letterCountAltura = 0;
                        info.alturac[letterCountAltura] = '\0';
                    }
            }

        else
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        printf("%c",info.alturac[0]);





    if (CheckCollisionPointRec(GetMousePosition(), Historico) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {

            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            caixaHistorico = true;
            caixaAltura = false;
            caixaNome = false;
            caixaPeso = false;
            caixaSangue = false;
            caixaSexo = false;
            caixaMedicacoes = false;
        }


            if(caixaHistorico)
            {
                int key = GetCharPressed();


                    if ((key >= 32) && (key <= 125) && (letterCountHistorico < 59))
                     {
                        info.historico[letterCountHistorico] = toupper((char)key);
                        info.historico[letterCountHistorico+1] = '\0';
                        letterCountHistorico++;
                    }

                     key = GetCharPressed();

                    if (IsKeyPressed(KEY_BACKSPACE))
                    {
                        letterCountHistorico--;
                        if (letterCountHistorico < 0) letterCountHistorico = 0;
                        info.historico[letterCountHistorico] = '\0';
                    }
            }

        else
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        printf("%c",info.historico[0]);





    if (CheckCollisionPointRec(GetMousePosition(), Peso) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {

            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            caixaPeso = true;
            caixaAltura = false;
            caixaHistorico = false;
            caixaNome = false;
            caixaSangue = false;
            caixaSexo = false;
            caixaMedicacoes = false;
        }


            if(caixaPeso)
            {
                int key = GetCharPressed();


                    if ((key >= 32) && (key <= 125) && (letterCountPeso < 5))
                     {
                        info.pesoc[letterCountPeso] = toupper((char)key);
                        info.pesoc[letterCountPeso+1] = '\0';
                        letterCountPeso++;
                        }

                     key = GetCharPressed();

                    if (IsKeyPressed(KEY_BACKSPACE))
                    {
                        letterCountPeso--;
                        if (letterCountPeso < 0) letterCountPeso = 0;
                        info.pesoc[letterCountPeso] = '\0';
                    }
            }

        else
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        printf("%c",info.pesoc[0]);










    if (CheckCollisionPointRec(GetMousePosition(), Medicacoes) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {

            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            caixaMedicacoes = true;
            caixaAltura = false;
            caixaHistorico = false;
            caixaNome = false;
            caixaPeso = false;
            caixaSangue = false;
            caixaSexo = false;
        }


            if(caixaMedicacoes)
            {
                int key = GetCharPressed();


                    if ((key >= 32) && (key <= 125) && (letterCounterMedicacoes < 59))
                     {
                        info.medicacoes[letterCounterMedicacoes] = toupper((char)key);
                        info.medicacoes[letterCounterMedicacoes+1] = '\0';
                        letterCounterMedicacoes++;
                        }

                     key = GetCharPressed();

                    if (IsKeyPressed(KEY_BACKSPACE))
                    {
                        letterCounterMedicacoes--;
                        if (letterCounterMedicacoes < 0) letterCounterMedicacoes = 0;
                        info.medicacoes[letterCounterMedicacoes] = '\0';
                    }
            }

        else
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        printf("%c",info.medicacoes[0]);






    if (CheckCollisionPointRec(GetMousePosition(), Sexo) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {

            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            caixaSexo = true;
            caixaAltura = false;
            caixaHistorico = false;
            caixaNome = false;
            caixaPeso = false;
            caixaSangue = false;
            caixaMedicacoes = false;
        }


            if(caixaSexo)
            {
                int key = GetCharPressed();


                    if ((key >= 32) && (key <= 125) && (letterCountSexo < 9))
                     {
                        info.genero[letterCountSexo] = toupper((char)key);
                        info.genero[letterCountSexo+1] = '\0';
                        letterCountSexo++;
                        }

                     key = GetCharPressed();

                    if (IsKeyPressed(KEY_BACKSPACE))
                    {
                        letterCountSexo--;
                        if (letterCountSexo < 0) letterCountSexo = 0;
                        info.genero[letterCountSexo] = '\0';
                    }
            }

        else
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        printf("%c",info.genero[0]);





    if (CheckCollisionPointRec(GetMousePosition(), Sangue) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {

            SetMouseCursor(MOUSE_CURSOR_IBEAM);
            caixaSangue = true;
            caixaSexo = false;
            caixaAltura = false;
            caixaHistorico = false;
            caixaNome = false;
            caixaPeso = false;
            caixaMedicacoes = false;
        }


            if(caixaSangue)
            {
                int key = GetCharPressed();


                    if ((key >= 32) && (key <= 125) && (letterCountSangue < 3))
                     {
                        info.tipoSangue[letterCountSangue] = toupper((char)key);
                        info.tipoSangue[letterCountSangue+1] = '\0';
                        letterCountSangue++;
                        }

                     key = GetCharPressed();

                    if (IsKeyPressed(KEY_BACKSPACE))
                    {
                        letterCountSangue--;
                        if (letterCountSangue < 0) letterCountSangue = 0;
                        info.tipoSangue[letterCountSangue] = '\0';
                    }
            }

        else
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        printf("%c",info.tipoSangue[0]);










    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawRectangleRec(Salvar, DARKBLUE);
    DrawRectangleLines((int)Salvar.x, (int)Salvar.y, (int)Salvar.width, (int)Salvar.height, BLACK);
    DrawText("SALVAR", (int)Salvar.x+70, (int)Salvar.y +8, 40, BLACK);

    DrawText("NOME:", (int)CampoNome.x , (int)CampoNome.y -15, 15, BLACK);
    DrawRectangleRec(CampoNome, Cinzabonito);
    DrawRectangleLines((int)CampoNome.x, (int)CampoNome.y, (int)CampoNome.width, (int)CampoNome.height, DARKGRAY);


    DrawText("SEXO:", (int)Sexo.x , (int)Sexo.y -15, 15, BLACK);
    DrawRectangleRec(Sexo, Cinzabonito);
    DrawRectangleLines((int)Sexo.x, (int)Sexo.y, (int)Sexo.width, (int)Sexo.height, DARKGRAY);

    DrawText("ALTURA:", (int)Altura.x , (int)Altura.y -15, 15, BLACK);
    DrawRectangleRec(Altura, Cinzabonito);
    DrawRectangleLines((int)Altura.x, (int)Altura.y, (int)Altura.width, (int)Altura.height, DARKGRAY);

    DrawText("PESO:", (int)Peso.x , (int)Peso.y -15, 15, BLACK);
    DrawRectangleRec(Peso, Cinzabonito);
    DrawRectangleLines((int)Peso.x, (int)Peso.y, (int)Peso.width, (int)Peso.height, DARKGRAY);

    DrawText("TIPO SANGUINEO:", (int)Sangue.x , (int)Sangue.y -15, 15, BLACK);
    DrawRectangleRec(Sangue, Cinzabonito);
    DrawRectangleLines((int)Sangue.x, (int)Sangue.y, (int)Sangue.width, (int)Sangue.height, DARKGRAY);

    DrawText("HISTORICO:", (int)Historico.x , (int)Historico.y -15, 15, BLACK);
    DrawRectangleRec(Historico, Cinzabonito);
    DrawRectangleLines((int)Historico.x, (int)Historico.y, (int)Historico.width, (int)Historico.height, DARKGRAY);

    DrawText("REMEDIOS:", (int)Medicacoes.x , (int)Medicacoes.y -15, 15, BLACK);
    DrawRectangleRec(Medicacoes, Cinzabonito);
    DrawRectangleLines((int)Medicacoes.x, (int)Medicacoes.y, (int)Medicacoes.width, (int)Medicacoes.height, DARKGRAY);










    if(caixaNome)
        DrawRectangleLines((int)CampoNome.x, (int)CampoNome.y, (int)CampoNome.width, (int)CampoNome.height, RED);
    DrawText(info.nome, (int)CampoNome.x + 5, (int)CampoNome.y + 8, 40, BLACK);

    if(caixaAltura)
        DrawRectangleLines((int)Altura.x, (int)Altura.y, (int)Altura.width, (int)Altura.height, RED);
    DrawText(info.alturac, (int)Altura.x + 5, (int)Altura.y + 8, 40, BLACK);

    if(caixaHistorico)
        DrawRectangleLines((int)Historico.x, (int)Historico.y, (int)Historico.width, (int)Historico.height, RED);
    DrawText(info.historico, (int)Historico.x + 5, (int)Historico.y + 12, 30, BLACK);

    if(caixaPeso)
        DrawRectangleLines((int)Peso.x, (int)Peso.y, (int)Peso.width, (int)Peso.height, RED);
    DrawText(info.pesoc, (int)Peso.x + 5, (int)Peso.y + 8, 40, BLACK);

    if(caixaSexo)
        DrawRectangleLines((int)Sexo.x, (int)Sexo.y, (int)Sexo.width, (int)Sexo.height, RED);
    DrawText(info.genero, (int)Sexo.x + 5, (int)Sexo.y + 8, 40, BLACK);

    if(caixaSangue)
        DrawRectangleLines((int)Sangue.x, (int)Sangue.y, (int)Sangue.width, (int)Sangue.height, RED);
    DrawText(info.tipoSangue, (int)Sangue.x + 5, (int)Sangue.y + 8, 40, BLACK);

    if(caixaMedicacoes)
        DrawRectangleLines((int)Medicacoes.x, (int)Medicacoes.y, (int)Medicacoes.width, (int)Medicacoes.height, RED);
    DrawText(info.medicacoes, (int)Medicacoes.x + 5, (int)Medicacoes.y + 12, 30, BLACK);









    if (caixaNome)
    {
            if (((framesCounter/20)%2) == 0)
                DrawText("|", (int)CampoNome.x + 8 + MeasureText(info.nome, 40), (int)CampoNome.y + 12, 40, BLACK);
    }

    if (caixaAltura)
    {
            if (((framesCounter/20)%2) == 0)
                DrawText("|", (int)Altura.x + 8 + MeasureText(info.alturac, 40), (int)Altura.y + 12, 40, BLACK);
    }

    if (caixaPeso)
    {
            if (((framesCounter/20)%2) == 0)
                DrawText("|", (int)Peso.x + 8 + MeasureText(info.pesoc, 40), (int)Peso.y + 12, 40, BLACK);
    }

    if (caixaHistorico)
    {
            if (((framesCounter/20)%2) == 0)
                DrawText("|", (int)Historico.x + 8 + MeasureText(info.historico, 30), (int)Historico.y + 12, 40, BLACK);
    }

    if (caixaSangue)
    {
            if (((framesCounter/20)%2) == 0)
                DrawText("|", (int)Sangue.x + 8 + MeasureText(info.tipoSangue, 40), (int)Sangue.y + 12, 40, BLACK);
    }

    if (caixaSexo)
    {
            if (((framesCounter/20)%2) == 0)
                DrawText("|", (int)Sexo.x + 8 + MeasureText(info.genero, 40), (int)Sexo.y + 12, 40, BLACK);
    }

    if (caixaMedicacoes)
    {
            if (((framesCounter/20)%2) == 0)
                DrawText("|", (int)Medicacoes.x + 8 + MeasureText(info.medicacoes, 30), (int)Medicacoes.y + 12, 40, BLACK);
    }

    if (CheckCollisionPointRec(GetMousePosition(), Salvar) && IsMouseButtonDown(MOUSE_LEFT_BUTTON)
                                                           && strcmp(info.alturac,"") != 0
                                                           && strcmp(info.pesoc,"") != 0
                                                           && strcmp(info.genero,"") != 0
                                                           && strcmp(info.tipoSangue,"") != 0
                                                           && strcmp(info.medicacoes,"") != 0
                                                           && strcmp(info.historico,"") != 0
                                                           && strcmp(info.nome,"") != 0)
    {
        DrawRectangleRec(Salvar, GREEN);
        DrawRectangleLines((int)Salvar.x, (int)Salvar.y, (int)Salvar.width, (int)Salvar.height, BLACK);
        DrawText("SALVAR", (int)Salvar.x+70, (int)Salvar.y +8, 40, BLACK);
        inserePessoa(lista,info.nome,id);
        info.altura = atof(info.alturac);
        info.peso = atof(info.pesoc);
        insereInfo(lista,info.nome,info.genero,info.altura,info.peso,info.tipoSangue,info.medicacoes);
        insereHistoricoM(lista,info.nome,info.historico,id);
        id++;
        letterCountNome = 0;
        letterCountAltura = 0;
        letterCountHistorico =0;
        letterCountSangue =0;
        letterCountPeso =0;
        letterCountSexo =0;
        letterCounterMedicacoes =0;
        controleNome = true;
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

        return 1;
}



bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126)) keyPressed = true;

    return keyPressed;
}
