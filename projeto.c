#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct caracteristicasMusica {
    char titulo[30], artista[20], album[20], genero[20];
};

struct caracteristicasMusica inserir_musica() {
    struct caracteristicasMusica caracteristicasMusica1;
    int escolha1, escolha2;

    printf("Insira o nome da música: ");
    scanf("%s", caracteristicasMusica1.titulo);

    printf("Voce sabe o nome do artista/banda?\n Sim = 1:\n Nao = 2: ");
    scanf("\n%d", &escolha1);

    while (escolha1 != 1 && escolha1 != 2) {
        printf("Erro! Digite novamente.\n");
        printf("Voce sabe o nome do artista/banda?\n Sim = 1:\n Nao = 2: ");
        scanf("\n%d", &escolha1);
    }

    if (escolha1 == 1) {
        printf("Digite o nome do artista/banda: ");
        scanf("%s", caracteristicasMusica1.artista);
    }

    printf("Voce sabe o nome do album?\n Sim = 1\n Nao = 2: ");
    scanf("%d", &escolha2);

    while (escolha2 != 1 && escolha2 != 2) {
        printf("Erro! Digite novamente.\n");
        printf("Voce sabe o nome do album?\n Sim = 1\n Nao = 2: ");
        scanf("%d", &escolha2);
    }

    if (escolha2 == 1) {
        printf("Digite o nome do album: ");
        scanf("%s", caracteristicasMusica1.album);
    }

    printf("Insira o genero da musica: ");
    scanf("%s", caracteristicasMusica1.genero);

    return caracteristicasMusica1;
}

int main() {
    int escolha;
    int tamanhoArray = 4;
    struct caracteristicasMusica *playlist;

    playlist = (struct caracteristicasMusica *)malloc(tamanhoArray * sizeof(struct caracteristicasMusica));

    if (playlist == NULL) {
        printf("Erro na alocacao de memoria.");
        return 1;
    }

    printf("1. Inserir nova musica.\n");
    printf("2 Favoritar musica.");
    printf("3. Mostrar musicas cadastradas na playlist, exibindo quais foram favoritadas.\n");
    printf("4. Buscar por uma musica.\n");
    printf("5. Editar informacoes de uma musica.\n");
    printf("6. Remover musica.\n");
    printf("7.'Favoritar' musica ja cadastrada na playlist\n");
    printf("8. Salvar playlist em um arquivo\n");

    scanf("%d", &escolha);

    if (escolha == 1) {
        struct caracteristicasMusica novaMusica = inserir_musica();
        
        printf("Música cadastrada:\n");
        printf("Nome: %s\n", novaMusica.titulo);
        if (strlen(novaMusica.artista) > 0) {
            printf("Artista/Banda: %s\n", novaMusica.artista);
        }
        if (strlen(novaMusica.album) > 0) {
            printf("Album: %s\n", novaMusica.album);
        }
        printf("Genero: %s\n", novaMusica.genero);
    }

    free(playlist);


    return 0;
}