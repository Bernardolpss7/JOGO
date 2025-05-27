#include <stdio.h>
#include "interfaces.h"
#include "jogo.h"
#include "terminal.h"
#include <windows.h>
void menu()
{
    system("cls");
    terminal();
    int escolha;
    do{
        telainicial();
        scanf("%d",&escolha);
        switch(escolha){
            case 1:
                vila();
                break;
            case 2:
                creditos();
                break;
            case 3:
                telasaida();
                break;
            default:
                printf("opção invalida tente novamente\n");
                break;
        }
    } while(escolha != 3);
}