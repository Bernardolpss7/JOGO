#include <stdio.h>
#include "interfaces.h"
#include <windows.h>
#include <conio.h>
void telainicial(void){
    system("cls");
    printf("\n\n\n");
    printf("==============================================\n");
    printf("        BEM-VINDO AO DUNGEON CRAWLER!\n");
    printf("==============================================\n");
    printf("\n");

    printf("             ▄████▄   ██ ▄█▀ ▓█████ \n");
    printf("            ▒██▀ ▀█   ██▄█▒  ▓█   ▀ \n");
    printf("            ▒▓█    ▄ ▓███▄░  ▒███   \n");
    printf("            ▒▓▓▄ ▄██ ▓██ █▄  ▒▓█  ▄ \n");
    printf("            ▒ ▓███▀  ▒██▒ █▄ ░▒████▒\n");
    printf("            ░ ░▒ ▒   ▒ ▒▒ ▓▒ ░░ ▒░ ░\n");
    printf("              ░  ▒   ░ ░▒ ▒░  ░ ░  ░\n");
    printf("            ░        ░ ░░ ░     ░   \n");
    printf("            ░ ░      ░  ░       ░  ░\n");
    printf("\n");
    printf("==============================================\n");
    printf("                 1 PARA JOGAR\n");
    printf("==============================================\n");
    printf("\n");
    printf("==============================================\n");
    printf("              2 PARA OS CREDITOS\n");
    printf("==============================================\n");
    printf("\n");
    printf("==============================================\n");
    printf("                 3 PARA SAIR\n");
    printf("==============================================\n");
    printf("\nEscolha uma opção: ");
}
void creditos(void){
    system("cls");
    printf("\n=== Créditos ===\n");
    printf("Desenvolvido por:\n");
    printf("Bernardo Lopes Machado\n");
    printf("\nPressione ENTER para voltar...\n");
    getchar(); getchar();
}
void telasaida(void){
    system("cls");
    printf("\nSaindo do jogo...\n");
    printf("Até logo, aventureiro!\n");
}
void derrota(){
    system("cls");

    printf("╔════════════════════════════════════════════╗\n");
    printf("║                                            ║\n");
    printf("║                DERROTA TOTAL               ║\n");
    printf("║                                            ║\n");
    printf("║          Sua jornada chegou ao fim.        ║\n");
    printf("║                                            ║\n");
    printf("║          Pressione qualquer tecla...       ║\n");
    printf("║                                            ║\n");
    printf("╚════════════════════════════════════════════╝\n");

    getch();
}
void vitoria(){
    system("cls");

    printf("╔══════════════════════════════════════════════╗\n");
    printf("║                                              ║\n");
    printf("║                VITÓRIA ALCANÇADA             ║\n");
    printf("║                                              ║\n");
    printf("║         Você completou sua jornada!          ║\n");
    printf("║                                              ║\n");
    printf("║          Pressione qualquer tecla...         ║\n");
    printf("║                                              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    getch();
}
void reinicio(){
    system("cls");

    printf("╔══════════════════════════════════════════════╗\n");
    printf("║                                              ║\n");
    printf("║                                              ║\n");
    printf("║              SUA FASE REINICIOU              ║\n");
    printf("║                                              ║\n");
    printf("║                                              ║\n");
    printf("║          Pressione qualquer tecla...         ║\n");
    printf("║                                              ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    getch();
}