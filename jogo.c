#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int dado();

void preenche(int posição, int m){
    int i = 0;
    int casa = 0;
    int j = 0;
    char tabuleiro[m][m];

    for(i = 0; i < m; i++){
        for(j = 0; j < m; j++){
            if(casa < posição){
                tabuleiro[i][j] = 'X';
                printf("[%c]", tabuleiro[i][j]);
            } else if (casa == posição){
                tabuleiro[i][j] = 'O';
                printf("[%c]", tabuleiro[i][j]);  
            } else {
                tabuleiro[i][j] = '*';
                printf("[%c]", tabuleiro[i][j]);
            }
            casa++;
        }
        printf("\n ");
    }
}

int main() {
    srand(time(NULL));
    int continuar = 1;
    int n = 0;
    int m = 1;
    int num_iguais = 0;
    int valor1;
    int valor2;
    int posição = 0;
    int pontuação = 0;

    printf("O objetivo do jogo é chegar ao fim do tabuleiro, você deve tentar ganhar o máximo de pontos. \n Obs: Terminar em menos rodadas garante mais pontos, em cada rodada se joga dois dados de 4 lados, caso caia em números iguais aumenta os pontos\n\n");
    printf("Qual o tamanho do tabuleiro? Deve ser inteiro maior que 1: ");
    scanf("%i", &m);

    if(m < 2 || m > 20){ 
        printf("Número inválido ou muito alto, encerrando...");
        return 0;
    }

    int t = m * m;
    while(1){
        n++;
        printf("\nRodada %i: \n", n);
        printf("   -->Digite 1 para rolar os dados ou um valor diferente de 1 para parar o jogo: ");
        scanf("%i", &continuar);
        
        if(continuar != 1){
            printf("Você digitou um valor diferente de 1, finalizando jogo...\n");
            break;
        } else {
            valor1 = dado();
            valor2 = dado();
            printf("Os resultados foram %i e %i\n", valor1, valor2);

            while(valor1 == valor2){
                num_iguais++;
                printf("Os números são iguais!\n");
                valor1 = dado();
                valor2 = dado();
                printf("Novos dados: %i e %i\n", valor1, valor2);
            }
        }

        posição = (posição + valor1 + valor2 - 1);
        if(posição >= (t - 1)){
            printf("Você chegou na última casa. Parabéns você chegou no fim do tabuleiro!!!\n");
            preenche(t - 1, m);
            break;
        } else {
            printf("Você está na casa %i\n", posição + 1);
            preenche(posição, m);
        }
    }
      
    pontuação = (((m * 2) - (n / 2)) * (num_iguais + 1));
    printf("Sua pontuação foi: %i\n", pontuação);
    printf("Números iguais tirados: %i\n", num_iguais);
    return 0;
}
int dado(){
    return ((rand() % 4) + 1);
}
