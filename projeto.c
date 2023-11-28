#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Armazenar as informações da música
struct caracteristicasMusica {
    char titulo[30], artista[20], album[20], genero[20];
    int favorita;
};

// Função para inserir música
struct caracteristicasMusica inserir_musica() {
    struct caracteristicasMusica caracteristicasMusica1;
    int escolha1, escolha2;

    printf("Insira o nome da música: ");
    scanf(" %29[^\n]", caracteristicasMusica1.titulo);

    printf("Voce sabe o nome do artista/banda?\n Sim = 1:\n Nao = 2: ");
    scanf("%d", &escolha1);

    while (escolha1 != 1 && escolha1 != 2) {
        printf("Erro! Digite novamente.\n");
        printf("Voce sabe o nome do artista/banda?\n Sim = 1:\n Nao = 2: ");
        scanf("\n%d", &escolha1);
    }

    if (escolha1 == 1) {
        printf("Digite o nome do artista/banda: ");
        scanf(" %19[^\n]", caracteristicasMusica1.artista);
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
        scanf(" %19[^\n]", caracteristicasMusica1.album);
    }

    printf("Insira o genero da musica: ");
    scanf(" %19[^\n]", caracteristicasMusica1.genero);

    return caracteristicasMusica1;
}

// Função para favoritar música
void favoritarMusica(struct caracteristicasMusica *playlist, int tamanhoPlaylist) {
    char tituloFavorita[30];
    printf("Insira o título da música que deseja favoritar: ");
    scanf(" %29[^\n]", tituloFavorita);

    int encontrada = 0;
    for (int digitada = 0; digitada < tamanhoPlaylist; digitada++) {
        if (strcmp(playlist[digitada].titulo, tituloFavorita) == 0) {
            playlist[digitada].favorita = 1; // Marcar a música como favorita
            encontrada = 1;
            printf("Música '%s' favoritada!\n", tituloFavorita);
            break;
        }
    }

    if (!encontrada) {
        printf("Musica não encontrada na playlist.\n");
    }
}

// Função para visualizar músicas
void vizualizar(struct caracteristicasMusica *playlist, int tamanhoPlaylist) {
    printf("Músicas cadastradas:\n");

    for (int i = 0; i < tamanhoPlaylist; i++) {
        printf("Música %d:\n", i + 1);
        printf("Nome: %s\n", playlist[i].titulo);

        if (strlen(playlist[i].artista) > 0) {
            printf("Artista/Banda: %s\n", playlist[i].artista);
        }

        if (strlen(playlist[i].album) > 0) {
            printf("Album: %s\n", playlist[i].album);
        }

        printf("Genero: %s\n", playlist[i].genero);

        if (playlist[i].favorita == 1) {
            printf("Esta música está favoritada.\n");
        } else {
            printf("Esta música não está favoritada.\n");
        }
        printf("\n");
    }
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
    printf("2. Favoritar musica.\n");
    printf("3. Mostrar musicas cadastradas na playlist, exibindo quais foram favoritadas.\n");
    printf("4. Buscar por uma musica.\n");
    printf("5. Editar informacoes de uma musica.\n");
    printf("6. Remover musica.\n");
    printf("7. Salvar playlist em um arquivo.\n");

    scanf("%d", &escolha);

    if (escolha == 1) {
        // Inserir nova musica
        struct caracteristicasMusica novaMusica = inserir_musica();
    } else if (escolha == 2) {
        // Favoritar musica
        favoritarMusica(playlist, tamanhoArray);
    } else if (escolha == 3) {
        // Visualizar musicas
        vizualizar(playlist, tamanhoArray);
}

return 0;
}