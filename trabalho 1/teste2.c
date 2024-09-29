/**************************************************
*
* Giulia Delarissa
* Trabalho 1
* Professor(a): Diego Rupert
*
*/

#include <stdio.h>
#include <stdlib.h>
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

int valor_carta(char v) {
    if (v >= '2' && v <= '9') return v - '0';
    if (v == 'J') return 11;
    if (v == 'Q') return 12;
    if (v == 'K') return 13;
    if (v == 'A') return 14;
    return -1; // valor inválido
}

int compara_cartas(const void *a, const void *b) {
    t_carta *carta1 = (t_carta *)a;
    t_carta *carta2 = (t_carta *)b;
    if (carta1->valor != carta2->valor) {
        return carta1->valor - carta2->valor;
    }
    return carta1->naipe - carta2->naipe;
}

void ler_mao(t_mao *mao) {
    char valor[3], naipe;
    for (int i = 0; i < 5; i++) {
        scanf("%s %c", valor, &naipe);
        mao->cartas[i].valor = valor_carta(valor[0]);
        mao->cartas[i].naipe = naipe;
    }
}

t_valor_m classificar_mao(t_mao *mao) {
    qsort(mao->cartas, 5, sizeof(t_carta), compara_cartas);

    int frequencia[15] = {0};
    int maior_valor = 0;

    for (int i = 0; i < 5; i++) {
        frequencia[mao->cartas[i].valor]++;
        if (mao->cartas[i].valor > maior_valor) {
            maior_valor = mao->cartas[i].valor;
        }
    }

    int pares = 0, trinca = 0, quadra = 0;
    for (int i = 2; i <= 14; i++) {
        if (frequencia[i] == 2) pares++;
        if (frequencia[i] == 3) trinca++;
        if (frequencia[i] == 4) quadra++;
    }

    int sequencia = 1; // Assume que é uma sequência
    for (int i = 0; i < 4; i++) {
        if (mao->cartas[i + 1].valor != mao->cartas[i].valor + 1) {
            sequencia = 0;
            break;
        }
    }

    int flush = 1; // Assume que é um flush
    for (int i = 1; i < 5; i++) {
        if (mao->cartas[i].naipe != mao->cartas[0].naipe) {
            flush = 0;
            break;
        }
    }

    // Avaliação das mãos
    if (flush && sequencia && mao->cartas[0].valor == 14)
        return RFLUSH;
    if (flush && sequencia)
        return SFLUSH;
    if (quadra)
        return QUADRA;
    if (trinca && pares == 1)
        return FULL;
    if (flush)
        return FLUSH;
    if (sequencia)
        return SEQUENCIA;
    if (trinca)
        return TRINCA;
    if (pares == 2)
        return DOISPARES;
    if (pares == 1)
        return PAR;

    return maior_valor; // Retorna o maior valor se nenhuma outra combinação
}

int comparar_maos(t_mao *mao1, t_mao *mao2) {

    if (mao1->valor > mao2->valor) return 1;
    if (mao1->valor < mao2->valor) return 2;

    return 0;
}

char retorna_letras(int valor) {
    if (valor >= 2 && valor <= 9) return valor + '0';
    if (valor == 11) return 'J';
    if (valor == 12) return 'Q';
    if (valor == 13) return 'K';
    if (valor == 14) return 'A';
    return '?';
}
void imprimir_mao(t_carta cartas[5]) {
    for (int j = 0; j < 5; j++) {
        printf("%c %c", retorna_letras(cartas[j].valor), cartas[j].naipe);
        if (j < 4)
            printf(" ");
    }
    printf("\n");
}

int main() {
    int k;
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        t_mao mao1, mao2;

        // Ler as mãos das duas capivaras
        ler_mao(&mao1);
        ler_mao(&mao2);

        // Classificar as mãos
        mao1.valor = classificar_mao(&mao1);
        mao2.valor = classificar_mao(&mao2);

        // Comparar as mãos
        int resultado = comparar_maos(&mao1, &mao2);

        // Exibir o resultado
        if (resultado == 1) {
            printf("1 ");
            imprimir_mao(mao1.cartas);
        } else if (resultado == 2) {
            printf("2 ");
            imprimir_mao(mao2.cartas);
        } else {
            printf("E\n");
        }
    }

    return 0;
}
