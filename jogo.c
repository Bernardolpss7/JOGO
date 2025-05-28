#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "menu.h"
#include "interfaces.h"
void jogo3(int *morteE2)
{
    srand(time(NULL));
    int a = 0;
    char tecla;
    int new_iy, new_ix;
    int i, j;
    int l = 40, c = 40;
    char mapa[l][c];
    int iy = l / 2, ix = c / 2;
    int y = 8, x = 1;
    int espy, espx;
    int ctd = 0;
    int vy = 38, vx = 15;
    int dx, dy;

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (i == 0 || j == 0 || i == l - 1 || j == c - 1)
            {
                mapa[i][j] = '*';
            }
            else
            {
                mapa[i][j] = ' ';
            }
        }
    }

    mapa[y][x] = '&';
    mapa[iy][ix] = 'X';
    mapa[7][28] = 'O';
    mapa[2][37] = '@';
    mapa[38][39] = 'D';
    mapa[4][24] = '>';
    mapa[26][1] = '>';
    mapa[vy][vx] = 'V';

    while (1)
    {
        espy = (rand() % 38) + 1;
        espx = (rand() % 38) + 1;
        if (mapa[espy][espx] != 'V' && mapa[espy][espx] != '*' && mapa[espy][espx] != 'X' && mapa[espy][espx] != 'O' && mapa[espy][espx] != '@' && mapa[espy][espx] != '>')
        {
            mapa[espy][espx] = '#';
            ctd++;
            if (ctd == 100)
            {
                break;
            }
        }
    }

    while (1)
    {
        for (i = 0; i < l; i++)
        {
            for (j = 0; j < c; j++)
            {
                printf("%c ", mapa[i][j]);
            }
            printf("\n");
        }
        tecla = getch();
        mapa[y][x] = ' ';
        mapa[iy][ix] = ' ';
        mapa[vy][vx] = ' ';
        mapa[4][24] = '>';
        mapa[26][1] = '>';
        if (tecla == 'w')
        {
            if (mapa[y - 1][x] != '*' && mapa[y - 1][x] != '@' && mapa[y - 1][x] != 'O' && mapa[y - 1][x] != 'D')
            {
                y--;
            }
        }
        if (tecla == 'a')
        {
            if (mapa[y][x - 1] != '*' && mapa[y][x - 1] != '@' && mapa[y][x - 1] != 'O' && mapa[y][x - 1] != 'D')
            {
                x--;
            }
        }
        if (tecla == 's')
        {
            if (mapa[y + 1][x] != '*' && mapa[y + 1][x] != '@' && mapa[y + 1][x] != 'O' && mapa[y + 1][x] != 'D')
            {
                y++;
            }
        }
        if (tecla == 'd')
        {
            if (mapa[y][x + 1] != '*' && mapa[y][x + 1] != '@' && mapa[y][x + 1] != 'O' && mapa[y][x + 1] != 'D')
            {
                x++;
            }
        }
        if (tecla == 'i')
        {
            if ((y == 2 && x == 36) || (y == 2 && x == 38) || (y == 1 && x == 37) || (y == 3 && x == 37))
            {
                mapa[2][37] = ' ';
            }
            if((y == 7 && x == 27) || (y == 7 && x == 29) || (y == 6 && x == 28) || (y == 8 && x == 28))
            {
                for (i = 1; i <= 38; i++)
                {
                    mapa[20][i] = '*';
                }
            }
        }
        while (1)
        {
            new_iy = iy + (-1 + rand() % 3);
            new_ix = ix + (-1 + rand() % 3);
            if ((new_iy > 0 && new_iy <= 38) && (new_ix > 0 && new_ix <= 38))
            {
                break;
            }
        }

        char destino = mapa[new_iy][new_ix];

        if (destino != '*' && destino != 'D' && destino != '=' && destino != 'O' && destino != '#')
        {
            iy = new_iy;
            ix = new_ix;
            mapa[iy][ix] = 'X';
        }
        if (y == iy && x == ix)
        {
            system("cls");
            reinicio();
            jogo3(morteE2);
            return;
        }
        if (mapa[y][x] == '#')
        {
            (*morteE2)++;
            if (*morteE2 >= 4)
            {
                system("cls");
                derrota();
                menu();
                return;
            }
            else
            {
                system("cls");
                reinicio();
                jogo3(morteE2);
                return;
            }
        }
        if ((y == vy && x == vx) || (mapa[y][x] == 'V'))
        {
            system("cls");
            reinicio();
            jogo3(morteE2);
            return;
        }
        if (y == 4 && x == 24)
        {
            y = 26;
            x = 2;
        }
        if (y == 26 && x == 1)
        {
            y = 4;
            x = 25;
        }
        if (mapa[2][37] == ' ')
        {
            mapa[38][39] = '=';
        }
        if (y == 38 && x == 39)
        {
            system("cls");
            vitoria();
            menu();
            return;
        }
        mapa[y][x] = '&';
        if (a > 15)
        {
            dy = y - vy;
            dx = x - vx;
            if (abs(dx) > abs(dy))
            {
                if (dx > 0 && mapa[vy][vx + 1] != '*' && mapa[vy][vx + 1] != '@' && mapa[vy][vx + 1] != 'O' && mapa[vy][vx + 1] != 'D' && mapa[vy][vx + 1] != '#')
                {
                    vx++;
                }
                else if (dx < 0 && mapa[vy][vx - 1] != '*' && mapa[vy][vx - 1] != '@' && mapa[vy][vx - 1] != 'O' && mapa[vy][vx - 1] != 'D' && mapa[vy][vx - 1] != '#')
                {
                    vx--;
                }
            }
            else
            {
                if (dy > 0 && mapa[vy + 1][vx] != '*' && mapa[vy + 1][vx] != '@' && mapa[vy + 1][vx] != 'O' && mapa[vy + 1][vx] != 'D' && mapa[vy + 1][vx] != '#')
                {
                    vy++;
                }
                else if (dy < 0 && mapa[vy - 1][vx] != '*' && mapa[vy - 1][vx] != '@' && mapa[vy - 1][vx] != 'O' && mapa[vy - 1][vx] != 'D' && mapa[vy - 1][vx] != '#')
                {
                    vy--;
                }
            }
        }
        mapa[vy][vx] = 'V';
        system("cls");
        a++;
    }
}
void jogo2(int *morteE)
{
    system("cls");
    srand(time(NULL));
    int morteE2 = 0;
    char tecla;
    int new_iy, new_ix;
    int i, j;
    int l = 20, c = 20;
    char mapa[l][c];
    int iy = l / 2, ix = c / 2;
    int y = 8, x = 1;
    int ey1 = 3, ex1 = 3;
    int ey2 = 5, ex2 = 15;
    int ey3 = 8, ex3 = 8;
    int ey4 = 12, ex4 = 4;
    int ey5 = 14, ex5 = 14;
    int ey6 = 17, ex6 = 10;

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (i == 0 || j == 0 || i == l - 1 || j == c - 1)
            {
                mapa[i][j] = '*';
            }
            else
            {
                mapa[i][j] = ' ';
            }
        }
    }

    mapa[y][x] = '&';
    mapa[iy][ix] = 'X';
    mapa[ey1][ex1] = '#';
    mapa[ey2][ex2] = '#';
    mapa[ey3][ex3] = '#';
    mapa[ey4][ex4] = '#';
    mapa[ey5][ex5] = '#';
    mapa[ey6][ex6] = '#';
    mapa[7][1] = '*';
    mapa[7][2] = '*';
    mapa[9][1] = '*';
    mapa[9][2] = '*';
    mapa[8][2] = 'O';
    mapa[3][9] = '@';
    mapa[18][19] = 'D';

    while (1)
    {
        for (i = 0; i < l; i++)
        {
            for (j = 0; j < c; j++)
            {
                printf("%c ", mapa[i][j]);
            }
            printf("\n");
        }
        tecla = getch();
        mapa[y][x] = ' ';
        mapa[iy][ix] = ' ';
        if (tecla == 'w')
        {
            if (mapa[y - 1][x] != '*' && mapa[y - 1][x] != '@' && mapa[y - 1][x] != 'O' && mapa[y - 1][x] != 'D')
            {
                y--;
            }
        }
        if (tecla == 'a')
        {
            if (mapa[y][x - 1] != '*' && mapa[y][x - 1] != '@' && mapa[y][x - 1] != 'O' && mapa[y][x - 1] != 'D')
            {
                x--;
            }
        }
        if (tecla == 's')
        {
            if (mapa[y + 1][x] != '*' && mapa[y + 1][x] != '@' && mapa[y + 1][x] != 'O' && mapa[y + 1][x] != 'D')
            {
                y++;
            }
        }
        if (tecla == 'd')
        {
            if (mapa[y][x + 1] != '*' && mapa[y][x + 1] != '@' && mapa[y][x + 1] != 'O' && mapa[y][x + 1] != 'D')
            {
                x++;
            }
        }
        if (tecla == 'i')
        {
            if (y == 8 && x == 1)
            {
                mapa[8][2] = ' ';
            }
            if ((y == 4 && x == 9) || (y == 3 && x == 10))
            {
                mapa[3][9] = ' ';
            }
        }
        if (mapa[3][9] == ' ')
        {
            mapa[18][19] = '=';
        }
        if (mapa[8][2] == ' ')
        {
            for (i = 7; i <= 9; i++)
            {
                mapa[2][i] = '#';
            }
            for (i = 3; i <= 4; i++)
            {
                mapa[i][8] = '#';
            }
            mapa[2][2] = '#';
            mapa[5][17] = '#';
            mapa[9][4] = '#';
            mapa[3][13] = '#';
            mapa[16][16] = '#';
            mapa[13][7] = '#';
            mapa[7][10] = '#';
            mapa[10][15] = '#';
            mapa[17][3] = '#';
            mapa[14][11] = '#';
            mapa[2][9] = '#';
            mapa[3][8] = '#';
            mapa[4][8] = '#';
            mapa[4][10] = '#';
            mapa[3][11] = '#';
            mapa[18][17] = '#';
            mapa[16][17] = '#';
            mapa[16][18] = '#';
        }
        while (1)
        {
            new_iy = iy + (-1 + rand() % 3);
            new_ix = ix + (-1 + rand() % 3);
            if ((new_iy > 0 && new_iy <= 18) && (new_ix > 0 && new_ix <= 18))
            {
                break;
            }
        }

        char destino = mapa[new_iy][new_ix];

        if (destino != '*' && destino != 'D' && destino != '=' && destino != 'O' && destino != '#')
        {
            iy = new_iy;
            ix = new_ix;
            mapa[iy][ix] = 'X';
        }
        if (y == iy && x == ix)
        {
            system("cls");
            reinicio();
            jogo2(morteE);
            return;
        }
        if (mapa[y][x] == '#')
        {
            (*morteE)++;
            if (*morteE >= 4)
            {
                system("cls");
                derrota();
                menu();
                return;
            }
            else
            {
                system("cls");
                jogo2(morteE);
                return;
            }
        }
        if (y == 18 && x == 19)
        {
            system("cls");
            jogo3(&morteE2);
            break;
        }
        mapa[y][x] = '&';
        system("cls");
    }
}
void jogo1()
{
    int morteE = 0;
    system("cls");
    char tecla;
    int i, j;
    int y = 8, x = 1;
    int l = 10, c = 10;
    int cy = 1, cx = 1;
    int py = 9, px = 8;
    char mapa[l][c];

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (i == 0 || j == 0 || i == 9 || j == 9)
            {
                mapa[i][j] = '*';
            }
            else
            {
                mapa[i][j] = ' ';
            }
        }
    }
    for (i = 1; i <= 4; i++)
    {
        mapa[3][i] = '*';
    }
    mapa[1][4] = '*';
    mapa[py][px] = 'D';
    mapa[y][x] = '&';
    mapa[cy][cx] = '@';

    while (1)
    {
        for (i = 0; i < l; i++)
        {
            for (j = 0; j < c; j++)
            {
                printf("%c ", mapa[i][j]);
            }
            printf("\n");
        }
        tecla = getch();
        mapa[y][x] = ' ';
        if (tecla == 'w')
        {
            if (mapa[y - 1][x] != '*' && mapa[y - 1][x] != '@' && mapa[y - 1][x] != 'D')
            {
                y--;
            }
        }

        if (tecla == 'a')
        {
            if (mapa[y][x - 1] != '*' && mapa[y][x - 1] != '@' && mapa[y][x - 1] != 'D')
            {
                x--;
            }
        }

        if (tecla == 's')
        {
            if (mapa[y + 1][x] != '*' && mapa[y + 1][x] != '@' && mapa[y + 1][x] != 'D')
            {
                y++;
            }
        }

        if (tecla == 'd')
        {
            if (mapa[y][x + 1] != '*' && mapa[y][x + 1] != '@' && mapa[y][x + 1] != 'D')
            {
                x++;
            }
        }
        if (tecla == 'i')
        {
            if ((y == 2 && x == 1) || (y == 1 && x == 2))
            {
                mapa[cy][cx] = ' ';
            }
        }
        if (mapa[cy][cx] == ' ')
        {
            mapa[py][px] = '=';
        }

        mapa[y][x] = '&';
        if (mapa[y][x] == mapa[9][8])
        {
            system("cls");
            jogo2(&morteE);
            break;
        }
        system("cls");
    }
}
void vila()
{
    system("cls");
    char tecla;
    int i, j;
    char mapa[10][10];
    int y = 8;
    int x = 1;
    int py = 6, px = 9;
    int npc1y = 8, npc1x = 5;
    int npc2y = 2, npc2x = 7;
    int cy = 2, cx = 3;
    char mostrarTexto = 0;
    int npcAtual = 0;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (i == 0 || j == 0 || i == 9 || j == 9)
            {
                mapa[i][j] = '*';
            }
            else
            {
                mapa[i][j] = ' ';
            }
        }
    }

    mapa[y][x] = '&';
    mapa[py][px] = 'D';
    mapa[npc1y][npc1x] = 'P';
    mapa[npc2y][npc2x] = 'P';
    mapa[cy][cx] = '@';

    while (1)
    {
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                printf("%c ", mapa[i][j]);
            }
            printf("\n");
        }

        if (mostrarTexto)
        {
            printf("\n");

            if (npcAtual == 1)
            {
                printf("Ola, aventureiro! Seja bem-vindo a nossa vila.\n\n");
                printf("Aqui vai o basico para comecar sua jornada:\n");
                printf("- Use W, A, S, D para se mover.\n");
                printf("- Use 'i' para interagir com objetos.\n");
                printf("Seu simbolo no mapa e: &\n");
                printf("Pegue a chave (@) e abra a porta (D) com 'i'.\n");
                printf("A porta aberta vira '='. Passe por ela para completar a fase!\n");
            }
            if (npcAtual == 2)
            {
                printf("Vejo que esta quase pronto para os desafios...\n\n");
                printf("Atencao aos perigos e itens especiais:\n");
                printf("- * sao paredes. Nao da pra passar.\n");
                printf("- O sao botoes. Interaja com 'i'.\n");
                printf("- # sao espinhos: se tocar, a fase reinicia.\n");
                printf("- > sao portais: te teleportam para outro lugar.\n");
                printf("- X e um monstro que anda aleatoriamente.\n");
                printf("- V e um monstro que te persegue!\n");
                printf("Evite os perigos e use sua inteligencia para vencer!\n");
            }
        }

        tecla = getch();

        mapa[y][x] = ' ';
        if (tecla == 'w')
        {
            if (mapa[y - 1][x] != '*' && mapa[y - 1][x] != 'D' && mapa[y - 1][x] != 'P' && mapa[y - 1][x] != '@')
            {
                y--;
            }
        }

        if (tecla == 'a')
        {
            if (mapa[y][x - 1] != '*' && mapa[y][x - 1] != 'D' && mapa[y][x - 1] != 'P' && mapa[y][x - 1] != '@')
            {
                x--;
            }
        }

        if (tecla == 's')
        {
            if (mapa[y + 1][x] != '*' && mapa[y + 1][x] != 'D' && mapa[y + 1][x] != 'P' && mapa[y + 1][x] != '@')
            {
                y++;
            }
        }

        if (tecla == 'd')
        {
            if (mapa[y][x + 1] != '*' && mapa[y][x + 1] != 'D' && mapa[y][x + 1] != 'P' && mapa[y][x + 1] != '@')
            {
                x++;
            }
        }

        if (tecla == 'i')
        {
            if ((y == npc1y && (x == npc1x - 1 || x == npc1x + 1)) ||
                (x == npc1x && (y == npc1y - 1 || y == npc1y + 1)))
            {
                mostrarTexto = 1;
                npcAtual = 1;
            }
            else if ((y == npc2y && (x == npc2x - 1 || x == npc2x + 1)) ||
                     (x == npc2x && (y == npc2y - 1 || y == npc2y + 1)))
            {
                mostrarTexto = 1;
                npcAtual = 2;
            }
            if ((y == 2 && x == 2) || (y == 1 && x == 3) || (y == 3 && x == 3) || (y == 2 && x == 4))
            {
                mapa[cy][cx] = ' ';
            }
        }
        if (mapa[cy][cx] == ' ')
        {
            mapa[py][px] = '=';
        }

        if (!((y == npc1y && (x == npc1x - 1 || x == npc1x + 1)) ||
              (x == npc1x && (y == npc1y - 1 || y == npc1y + 1)) ||
              (y == npc2y && (x == npc2x - 1 || x == npc2x + 1)) ||
              (x == npc2x && (y == npc2y - 1 || y == npc2y + 1))))
        {
            mostrarTexto = 0;
            npcAtual = 0;
        }
        if (mapa[6][9] == mapa[y][x])
        {
            jogo1();
            break;
        }

        mapa[y][x] = '&';
        system("cls");
    }
}
