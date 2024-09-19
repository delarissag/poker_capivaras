/**************************************************
*
* Giulia Delarissa
* Trabalho 1
* Professor(a): Diego Rupert
*
*/

#include <stdio.h>
#include <string.h>

typedef enum {
    COPAS = 'C',
    ESPADAS = 'E',
    OUROS = 'O',
    PAUS = 'P'
} t_naipe;

typedef struct {
    short valor;
    t_naipe naipe;
} t_carta;

typedef enum {
    PAR = 15,
    DOISPARES,
    TRINCA,
    SEQUENCIA,
    FLUSH,
    FULL,
    QUADRA,
    SFLUSH,
    RFLUSH
} t_valor_m;

typedef struct {
    t_carta cartas[5];
    t_valor_m valor;
} t_mao;


int valor_carta(char valor) {
    if (valor == 'J') return 11;
    if (valor == 'Q') return 12;
    if (valor == 'K') return 13;
    if (valor == 'A') return 14;
    return valor - '0';
}



int main() {
    int k;
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        t_mao capivara1, capivara2;

        // Leitura das cartas da primeira capivara
        for (int j = 0; j < 5; j++) {
            char valor, naipe;
            scanf(" %c %c", &valor, &naipe);
            capivara1.cartas[j].valor = valor_carta(valor);
            capivara1.cartas[j].naipe = (t_naipe)naipe;
        }

        // Leitura das cartas da segunda capivara
        for (int j = 0; j < 5; j++) {
            char valor, naipe;
            scanf(" %c %c", &valor, &naipe);
            capivara2.cartas[j].valor = valor_carta(valor);
            capivara2.cartas[j].naipe = (t_naipe)naipe;
        }
    }

    return 0;
}
