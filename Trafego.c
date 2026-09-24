#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define PARAR 0
#define DIREITA 1
#define ESQUERDA 2
#define CIMA 3
#define BAIXO 4
#define VERMELHO "\033[31m"
#define VERDE "\033[32m"
#define AMARELO "\033[33m"
#define RESET "\033[0m"
struct Carro
{
    int direcao;
    int x;
    int y;
    int ativo;
};
void desenha_rua(char rua[][100])
{
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 59; j++)
        {
            if ((i >= 6 && i <= 10) || (j >= 26 && j < 30))
            {
                rua[i][j] = '-';
            }
            else
            {
                rua[i][j] = ' ';
            }
            if ((i >= 6 && i <= 10) && (j >= 26 && j <= 30))
            {
                rua[i][j] = ' ';
            }
            if (((i >= 0 && i <= 5) || (i >= 11 && i <= 17)) && (j >= 26 && j <= 30))
            {
                rua[i][j] = '|';
            }
            if (((i >= 0 && i <= 5) || (i >= 11 && i <= 17)) && (j == 27 || j == 29))
            {
                rua[i][j] = ' ';
            }
            if ((i == 7 || i == 9) && (j <= 25))
            {
                rua[i][j] = ' ';
            }
            if ((i == 6 || i == 8 || i == 10) && (j >= 31 && j <= 58))
            {
                rua[i][j] = ' ';
            }
            if ((i == 6 || i == 10) && (j == 30))
            {
                rua[i][j] = '|';
            }
        }
    }
}
int main()
{
    struct Carro carros[5];
    char rua[100][100];
    int contador = 0;
    carros[0].x = 7;
    carros[0].y = 0;
    carros[0].direcao = DIREITA;
    carros[0].ativo = 1;
    carros[1].x = 9;
    carros[1].y = 0;
    carros[1].direcao = DIREITA;
    carros[1].ativo = 1;
    carros[2].x = 0;
    carros[2].y = 27;
    carros[2].direcao = BAIXO;
    carros[2].ativo = 1;
    carros[3].x = 0;
    carros[3].y = 29;
    carros[3].direcao = BAIXO;
    carros[3].ativo = 1;
    carros[4].x = 16;
    carros[4].y = 29;
    carros[4].direcao = CIMA;
    carros[4].ativo = 1; /**/
    /* Inicializa carros como inativos
    for(int i=0;i<5;i++){
    carros[i].ativo = 0;
    }*/
    while (1)
    {
        system("cls");
        // system("clear"); -> Para Linux

        contador++;
        if (contador == 124)
        {
            contador = 0;
        }
        /* MOVIMENTO DOS CARROS */
        for (int i = 0; i < 5; i++)
        {
            if (carros[i].ativo == 0)
                continue;
            /* CURVAS */
            if (carros[0].x == 7 && carros[0].y == 27)
            {
                carros[0].direcao = BAIXO;
            }
            else if (carros[0].x == 8)
            {
                carros[0].direcao = DIREITA;
            }
            if (carros[1].x == 9 && carros[1].y == 27)
            {
                carros[1].direcao = BAIXO;
            }
            if (carros[3].x == 8 && carros[3].y == 29)
            {
                carros[3].direcao = DIREITA;
            }
            if (carros[4].x == 8 && carros[4].y == 29)
            {
                carros[4].direcao = DIREITA;
            }
            /* ATUALIZA POSIÇÃO */
            if (carros[i].direcao == DIREITA)
                carros[i].y++;
            if (carros[i].direcao == ESQUERDA)
                carros[i].y--;
            if (carros[i].direcao == CIMA)
                carros[i].x--;
            if (carros[i].direcao == BAIXO)
                carros[i].x++;
            if (carros[i].direcao == PARAR)
                continue;
            /* DESATIVA SE SAIR DA TELA */
            if (carros[i].x < 0 || carros[i].x > 16 ||
                carros[i].y < 0 || carros[i].y > 58)
            {
                if (i == 0)
                {
                    carros[0].x = 7;
                    carros[0].y = 0;
                    carros[0].direcao = DIREITA;
                    carros[0].ativo = 1;
                }
                else if (i == 1)
                {
                    carros[1].x = 9;
                    carros[1].y = 0;
                    carros[1].direcao = DIREITA;
                    carros[1].ativo = 1;
                }
                else if (i == 2)
                {
                    carros[2].x = 0;
                    carros[2].y = 27;
                    carros[2].direcao = BAIXO;
                    carros[2].ativo = 1;
                }
                else if (i == 3)
                {
                    carros[3].x = 0;
                    carros[3].y = 29;
                    carros[3].direcao = BAIXO;
                    carros[3].ativo = 1;
                }
                else if (i == 4)
                {
                    carros[4].x = 16;
                    carros[4].y = 29;
                    carros[4].direcao = CIMA;
                    carros[4].ativo = 1;
                }
                else
                {
                    carros[i].ativo = 0;
                }
            }
        }
        desenha_rua(rua);
        /* DESENHA CARROS */
        for (int n = 0; n < 5; n++)
        {
            if (carros[n].ativo == 1)
            {
                rua[carros[n].x][carros[n].y] = '*';
            }
        }
        /* PRINTA A RUA */
        for (int i = 0; i < 17; i++)
        {
            for (int j = 0; j < 59; j++)
            {
                // RUA PRINCIPAL
                // SINAL PEDESTRE
                if (i == 11 && j == 23)
                {
                    if (contador < 45)
                    {
                        printf(VERMELHO "P" RESET);
                    }
                    else if (contador >= 45)
                    {
                        printf(VERDE "P" RESET);
                    }
                }
                // SINAL CARRO
                else if (i == 5 && j == 23)
                {
                    if (contador >= 0 && contador < 42)
                    {
                        printf(VERDE "C" RESET);
                        if ((carros[0].direcao && carros[1].direcao) == PARAR)
                        {
                            carros[0].direcao = DIREITA;
                            carros[1].direcao = DIREITA;
                        }
                    }
                    else if (contador >= 42 && contador < 45)
                    {
                        printf(AMARELO "C" RESET);
                    }
                    else if (contador >= 45)
                    {
                        printf(VERMELHO "C" RESET);
                        if (carros[0].y == 22)
                        {
                            carros[0].direcao = PARAR;
                        }
                        else if (carros[1].y == 22)
                        {
                            carros[1].direcao = PARAR;
                        }
                    }
                }
                // RUA NORTE
                // SINAL PEDESTRE
                else if (i == 4 && j == 31)
                {
                    if (contador >= 0 && contador < 46)
                    {
                        printf(VERDE "P" RESET);
                    }
                    else if (contador >= 46 && contador < 67)
                    {
                        printf(VERMELHO "P" RESET);
                    }
                    else if (contador >= 70)
                    {
                        printf(VERDE "P" RESET);
                    }
                }
                // SINAL CARRO
                else if (i == 4 && j == 25)
                {
                    if (contador >= 0 && contador < 46)
                    {
                        printf(VERMELHO "C" RESET);
                        if (carros[2].x == 3)
                        {
                            carros[2].direcao = PARAR;
                        }
                        if (carros[3].x == 3)
                        {
                            carros[3].direcao = PARAR;
                        }
                    }
                    else if (contador >= 46 && contador < 67)
                    {
                        printf(VERDE "C" RESET);
                        if ((carros[2].direcao && carros[3].direcao) == PARAR)
                        {
                            carros[2].direcao = BAIXO;
                            carros[3].direcao = BAIXO;
                        }
                    }
                    else if (contador >= 67 && contador < 70)
                    {
                        printf(AMARELO "C" RESET);
                    }
                    else if (contador >= 70)
                    {
                        printf(VERMELHO "C" RESET);
                        if (carros[2].x == 3)
                        {
                            carros[2].direcao = PARAR;
                        }
                        if (carros[3].x == 3)
                        {
                            carros[3].direcao = PARAR;
                        }
                    }
                }
                // RUA SUL
                // SINAL PEDESTRE
                else if (i == 12 && j == 25)
                {
                    if (contador >= 0 && contador < 103)
                    {
                        printf(VERMELHO "P" RESET);
                    }
                    else if (contador >= 104)
                    {
                        printf(VERDE "P" RESET);
                    }
                    // SINAL CARRO
                }
                else if (i == 12 && j == 31)
                {
                    if (contador >= 0 && contador < 70)
                    {
                        printf(VERMELHO "C" RESET);
                        if (carros[4].x == 13)
                        {
                            carros[4].direcao = PARAR;
                        }
                    }
                    else if (contador >= 70 && contador < 101)
                    {
                        printf(VERDE "C" RESET);
                        if (carros[4].direcao == PARAR)
                        {
                            carros[4].direcao = CIMA;
                        }
                    }
                    else if (contador >= 101 && contador < 103)
                    {
                        printf(AMARELO "C" RESET);
                    }
                    else if (contador >= 103)
                    {
                        printf(VERMELHO "C" RESET);
                        if (carros[4].x == 13)
                        {
                            carros[4].direcao = PARAR;
                        }
                    }
                }
                // RUA LESTE
                // SINAL PEDESTRE
                else if (i == 10 && j == 33)
                {
                    if (contador >= 0 && contador < 103)
                    {
                        printf(VERMELHO "P" RESET);
                    }
                    else if (contador >= 104)
                    {
                        printf(VERDE "P" RESET);
                    }
                    // SINAL CARRO
                }
                else if (i == 6 && j == 33)
                {
                    if (contador >= 0 && contador < 103)
                    {
                        printf(VERDE "C" RESET);
                    }
                    else if (contador >= 103 && contador < 105)
                    {
                        printf(AMARELO "C" RESET);
                    }
                    else if (contador >= 104)
                    {
                        printf(VERMELHO "C" RESET);
                    }
                }
                else
                {
                    printf("%c", rua[i][j]);
                }
            }
            printf("\n");
        }
        sleep(1);
    }
    return 0;
}