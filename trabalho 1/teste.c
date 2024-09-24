/**************************************************
 *
 * Nome do(a) estudante: [Seu Nome]
 * Trabalho 1
 * Professor(a): [Nome do(a) professor(a)]
 *
 **************************************************/

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
    if (v == 'T') return 10;
    if (v == 'J') return 11;
    if (v == 'Q') return 12;
    if (v == 'K') return 13;
    if (v == 'A') return 14;
    return -1; // valor inválido, só para garantir
}

int compara_cartas(const void *a, const void *b) {
    t_carta *carta1 = (t_carta *)a;
    t_carta *carta2 = (t_carta *)b;
    if (carta1->valor != carta2->valor) {
        return carta1->valor - carta2->valor; // Ordem crescente de valor
    }
    return carta1->naipe - carta2->naipe; // Se valor for igual, ordenar pelo naipe
}

t_valor_m classificar_mao(t_mao *mao) {
    // Exemplo básico: verificar se é um par
    qsort(mao->cartas, 5, sizeof(t_carta), compara_cartas);

    // Verificação de tipos de mãos (par, dois pares, trinca, etc.)
    // Você precisará adicionar a lógica para identificar cada tipo de mão
    // Por exemplo, para verificar se há um par:
    for (int i = 0; i < 4; i++) {
        if (mao->cartas[i].valor == mao->cartas[i+1].valor) {
            return PAR;
        }
    }
    return PAR; // Placeholder: você vai implementar cada verificação
}

int comparar_maos(t_mao *mao1, t_mao *mao2) {
    // Primeiro, comparar o valor da mão
    if (mao1->valor > mao2->valor) return 1;
    if (mao1->valor < mao2->valor) return 2;

    // Se as mãos forem do mesmo tipo, comparar carta a carta
    for (int i = 4; i >= 0; i--) {
        if (mao1->cartas[i].valor > mao2->cartas[i].valor) return 1;
        if (mao1->cartas[i].valor < mao2->cartas[i].valor) return 2;
    }

    // Se chegar aqui, é um empate
    return 0;
}

int main() {
    int k;
    scanf("%d", &k); // Número de casos de teste

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
            for (int j = 0; j < 5; j++) {
                printf("%d %c ", mao1.cartas[j].valor, mao1.cartas[j].naipe);
            }
            printf("\n");
        } else if (resultado == 2) {
            printf("2 ");
            for (int j = 0; j < 5; j++) {
                printf("%d %c ", mao2.cartas[j].valor, mao2.cartas[j].naipe);
            }
            printf("\n");
        } else {
            printf("E\n");
        }
    }

    return 0;
}

