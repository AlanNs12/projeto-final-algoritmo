#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Armazenar as informações da musica
struct caracteristicasMusica {
    char titulo[30], artista[30], album[30], genero[30];
    int favorita;
};

// Função para inserir musica
struct caracteristicasMusica inserir_musica() {
    struct caracteristicasMusica caracteristicasMusica1;

    printf("Insira o nome da musica: ");
    scanf(" %29[^\n]", caracteristicasMusica1.titulo);

    printf("Digite o nome do artista/banda: ");
    scanf(" %29[^\n]", &caracteristicasMusica1.artista);

    printf("Digite o nome do album/single: ");
    scanf(" %29[^\n]", &caracteristicasMusica1.album);

    printf("Insira o genero da musica: ");
    scanf(" %29[^\n]", caracteristicasMusica1.genero);

    return caracteristicasMusica1;
}

// Função para favoritar musica
void favoritarMusica(struct caracteristicasMusica *playlist, int tamanhoPlaylist) {
    char tituloFavorita[30];
    printf("Insira o titulo da musica que deseja favoritar: ");
    scanf(" %29[^\n]", tituloFavorita);

    int encontrada = 0;
    for (int digitada = 0; digitada < tamanhoPlaylist; digitada++) {
        if (strcmp(playlist[digitada].titulo, tituloFavorita) == 0) {
            playlist[digitada].favorita = 1; // Marcar a musica como favorita
            encontrada = 1;
            printf("musica '%s' favoritada!\n", tituloFavorita);
            break;
        }
    }

    if (!encontrada) {
        printf("Musica nao encontrada na playlist.\n");
    }
}

// Função para visualizar musicas
void visualizar(struct caracteristicasMusica *playlist, int tamanhoPlaylist) {
    printf("musicas cadastradas:\n");

    for (int i = 0; i < tamanhoPlaylist; i++) {
        printf("musica %d:\n", i + 1);
        printf("Nome: %s\n", playlist[i].titulo);

        if (strlen(playlist[i].artista) > 0) {
            printf("Artista/Banda: %s\n", playlist[i].artista);
        }

        if (strlen(playlist[i].album) > 0) {
            printf("Album: %s\n", playlist[i].album);
        }

        printf("Genero: %s\n", playlist[i].genero);

        if (playlist[i].favorita == 1) {
            printf("Esta musica esta favoritada.\n");
        } else {
            printf("Esta musica nao esta favoritada.\n");
        }
        printf("\n");
    }
}

void buscarMusica(struct caracteristicasMusica *playlist, int tamanhoPlaylist) {
    char tituloBusca[30];
    printf("Insira o titulo da musica que deseja buscar: ");
    scanf(" %29[^\n]", tituloBusca);

    int encontrada = 0;
    for (int i = 0; i < tamanhoPlaylist; i++) {
        if (strcmp(playlist[i].titulo, tituloBusca) == 0) {
            encontrada = 1;
            printf("Musica encontrada:\n");
            printf("Nome: %s\n", playlist[i].titulo);
            printf("Artista/Banda: %s\n", playlist[i].artista);
            printf("Album: %s\n", playlist[i].album);
            printf("Genero: %s\n", playlist[i].genero);
            if (playlist[i].favorita == 1) {
                printf("Esta musica esta favoritada.\n");
            } else {
                printf("Esta musica nao esta favoritada.\n");
            }
            break;
        }
    }

    if (!encontrada) {
        printf("musica nao encontrada na playlist.\n");
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
        // Adicione logica para armazenar novaMusica em sua playlist
    } else if (escolha == 2) {
        // Favoritar musica
        favoritarMusica(playlist, tamanhoArray);
    } else if (escolha == 3) {
        // Visualizar musicas
        visualizar(playlist, tamanhoArray);
    } else if(escolha == 4) {
        // busca uma musica ja salva
        buscarMusica(playlist, tamanhoArray);
    }

    // limpa a locação de memoria atual
    free(playlist);

    return 0;
}