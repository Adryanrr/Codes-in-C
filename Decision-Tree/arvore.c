#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_LEN 100

typedef struct Node {
    char *question;
    struct Node *yes;
    struct Node *no;
    void (*action)(char *, int);
} Node;

void cifraDeCesar(char *texto, int chave) {
    char c;
    int i;
    for (i = 0; texto[i] != '\0'; i++) {
        c = texto[i];
        if (c >= 'a' && c <= 'z') {
            c = c + chave;
            if (c > 'z') c = c - 'z' + 'a' - 1;
        } else if (c >= 'A' && c <= 'Z') {
            c = c + chave;
            if (c > 'Z') c = c - 'Z' + 'A' - 1;
        }
        texto[i] = c;
    }
}

void decifraDeCesar(char *texto, int chave) {
    char c;
    int i;
    for (i = 0; texto[i] != '\0'; i++) {
        c = texto[i];
        if (c >= 'a' && c <= 'z') {
            c = c - chave;
            if (c < 'a') c = c + 'z' - 'a' + 1;
        } else if (c >= 'A' && c <= 'Z') {
            c = c - chave;
            if (c < 'A') c = c + 'Z' - 'A' + 1;
        }
        texto[i] = c;
    }
}

Node* createNode(char *question, void (*action)(char*, int)) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->question = question;
    newNode->yes = NULL;
    newNode->no = NULL;
    newNode->action = action;
    return newNode;
}

void traverse(Node *node, char *texto, int chave) {
    char resposta;
    if (node->action != NULL) {
        node->action(texto, chave);
    } else {
        printf("%s (y/n): ", node->question);
        scanf(" %c", &resposta);  // Adicionado espaço para ignorar espaços em branco
        if (resposta == 'y' || resposta == 'Y') {
            traverse(node->yes, texto, chave);
        } else {
            traverse(node->no, texto, chave);
        }
    }
}

Node* buildTree() {
    // Cria os nós finais com ações
    Node *criptografaTextoCurtoChavePequena = createNode(NULL, cifraDeCesar);
    Node *criptografaTextoCurtoChaveGrande = createNode(NULL, cifraDeCesar);
    Node *criptografaTextoLongoChavePequena = createNode(NULL, cifraDeCesar);
    Node *criptografaTextoLongoChaveGrande = createNode(NULL, cifraDeCesar);
    Node *descriptografaTextoCurtoChavePequena = createNode(NULL, decifraDeCesar);
    Node *descriptografaTextoCurtoChaveGrande = createNode(NULL, decifraDeCesar);
    Node *descriptografaTextoLongoChavePequena = createNode(NULL, decifraDeCesar);
    Node *descriptografaTextoLongoChaveGrande = createNode(NULL, decifraDeCesar);

    // Cria nós intermediários
    Node *criptografarTextoCurto = createNode("A chave é pequena?", NULL);
    criptografarTextoCurto->yes = criptografaTextoCurtoChavePequena;
    criptografarTextoCurto->no = criptografaTextoCurtoChaveGrande;

    Node *criptografarTextoLongo = createNode("A chave é pequena?", NULL);
    criptografarTextoLongo->yes = criptografaTextoLongoChavePequena;
    criptografarTextoLongo->no = criptografaTextoLongoChaveGrande;

    Node *descriptografarTextoCurto = createNode("A chave é pequena?", NULL);
    descriptografarTextoCurto->yes = descriptografaTextoCurtoChavePequena;
    descriptografarTextoCurto->no = descriptografaTextoCurtoChaveGrande;

    Node *descriptografarTextoLongo = createNode("A chave é pequena?", NULL);
    descriptografarTextoLongo->yes = descriptografaTextoLongoChavePequena;
    descriptografarTextoLongo->no = descriptografaTextoLongoChaveGrande;

    // Cria nós raiz
    Node *criptografar = createNode("O texto é curto?", NULL);
    criptografar->yes = criptografarTextoCurto;
    criptografar->no = criptografarTextoLongo;

    Node *descriptografar = createNode("O texto é curto?", NULL);
    descriptografar->yes = descriptografarTextoCurto;
    descriptografar->no = descriptografarTextoLongo;

    // Nó raiz principal
    Node *root = createNode("Você quer criptografar?", NULL);
    root->yes = criptografar;
    root->no = descriptografar;

    return root;
}

void freeTree(Node *node) {
    if (node != NULL) {
        freeTree(node->yes);
        freeTree(node->no);
        free(node);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    char texto[MAX_LEN];
    int chave;
    Node *decisionTree = buildTree();

    printf("Digite o texto: ");
    fgets(texto, MAX_LEN, stdin);
    texto[strcspn(texto, "\n")] = '\0';

    printf("Digite a chave: ");
    scanf("%d", &chave);

    // Limpa o buffer de entrada para evitar problemas na leitura das respostas
    getchar();

    traverse(decisionTree, texto, chave);

    printf("Resultado: %s \n", texto);

    freeTree(decisionTree);
    return 0;
}
