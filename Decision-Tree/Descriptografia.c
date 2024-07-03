#include <stdio.h>
#include <string.h>
#include <ctype.h>

void calcular_frequencias(const char *texto, float frequencias[26]) {
    int contador[26] = {0};
    int total = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        char c = tolower(texto[i]);
        if (isalpha(c)) {
            contador[c - 'a']++;
            total++;
        }
    }

    for (int i = 0; i < 26; i++) {
        frequencias[i] = (float)contador[i] / total;
    }
}

#define NUM_TREINAMENTO 3
#define NUM_DESLOCAMENTOS 26

typedef struct {
    float frequencias[26];
    int deslocamento;
} ExemploTreinamento;

void gerar_dados_treinamento(ExemploTreinamento dados_treinamento[NUM_TREINAMENTO * NUM_DESLOCAMENTOS], const char *textos_treinamento[NUM_TREINAMENTO]) {
    int index = 0;
    for (int t = 0; t < NUM_TREINAMENTO; t++) {
        for (int deslocamento = 0; deslocamento < NUM_DESLOCAMENTOS; deslocamento++) {
            char texto_criptografado[256];
            cifra_cesar(textos_treinamento[t], deslocamento, texto_criptografado);
            calcular_frequencias(texto_criptografado, dados_treinamento[index].frequencias);
            dados_treinamento[index].deslocamento = deslocamento;
            index++;
        }
    }
}

int predizer_deslocamento(const float frequencias[26], const ExemploTreinamento dados_treinamento[NUM_TREINAMENTO * NUM_DESLOCAMENTOS]) {
    int melhor_deslocamento = 0;
    float melhor_diferenca = FLT_MAX;

    for (int i = 0; i < NUM_TREINAMENTO * NUM_DESLOCAMENTOS; i++) {
        float diferenca = 0.0;
        for (int j = 0; j < 26; j++) {
            diferenca += fabs(frequencias[j] - dados_treinamento[i].frequencias[j]);
        }
        if (diferenca < melhor_diferenca) {
            melhor_diferenca = diferenca;
            melhor_deslocamento = dados_treinamento[i].deslocamento;
        }
    }
    return melhor_deslocamento;
}

void decifrar_sem_chave(const char *texto_criptografado, char *texto_decifrado, const ExemploTreinamento dados_treinamento[NUM_TREINAMENTO * NUM_DESLOCAMENTOS]) {
    float frequencias[26];
    calcular_frequencias(texto_criptografado, frequencias);
    int deslocamento_predito = predizer_deslocamento(frequencias, dados_treinamento);
    cifra_cesar(texto_criptografado, -deslocamento_predito, texto_decifrado);
}

int main() {
    const char *textos_treinamento[NUM_TREINAMENTO] = {
            "this is an example text",
            "another example sentence",
            "yet another piece of text"
    };

    ExemploTreinamento dados_treinamento[NUM_TREINAMENTO * NUM_DESLOCAMENTOS];
    gerar_dados_treinamento(dados_treinamento, textos_treinamento);

    const char *texto_original = "this is a test message";
    char texto_criptografado[256];
    int deslocamento = 5;
    cifra_cesar(texto_original, deslocamento, texto_criptografado);

    printf("Texto Criptografado: %s\n", texto_criptografado);

    char texto_decifrado[256];
    decifrar_sem_chave(texto_criptografado, texto_decifrado, dados_treinamento);

    printf("Texto Decifrado: %s\n", texto_decifrado);

    return 0;
}
