#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct caracteristicasMusica {
    char titulo[30], artista[30], album[30], genero[30];
    int favorita;
};

struct caracteristicasMusica inserir_musica() {
    struct caracteristicasMusica caracteristicasMusica1;

    printf("Insira o nome da musica: ");
    scanf(" %29[^\n]", caracteristicasMusica1.titulo);

    printf("Digite o nome do artista/banda: ");
    scanf(" %29[^\n]", caracteristicasMusica1.artista);

    printf("Digite o nome do album/single: ");
    scanf(" %29[^\n]", caracteristicasMusica1.album);

    printf("Insira o genero da musica: ");
    scanf(" %29[^\n]", caracteristicasMusica1.genero);

    return caracteristicasMusica1;
}

void favoritarMusica(struct caracteristicasMusica *playlist, int tamanhoPlaylist) {
    char tituloFavorita[30];
    printf("Insira o titulo da musica que deseja favoritar: ");
    scanf(" %29[^\n]", tituloFavorita);

    int encontrada = 0;
    for (int digitada = 0; digitada < tamanhoPlaylist; digitada++) {
        if (strcmp(playlist[digitada].titulo, tituloFavorita) == 0) {
            playlist[digitada].favorita = 1;
            encontrada = 1;
            printf("Musica '%s' favoritada!\n", tituloFavorita);
            break;
        }
    }

    if (!encontrada) {
        printf("Musica nao encontrada na playlist.\n");
    }
    printf("\n");
}

void visualizar(struct caracteristicasMusica *playlist, int tamanhoPlaylist) {
    if(tamanhoPlaylist == 0){
        printf("A playlist nao possui nenhuma musica cadastrada\n");
    } else{
    printf("Musicas cadastradas:\n");

    for (int i = 0; i < tamanhoPlaylist; i++) {
            printf("Musica %d:\n", i + 1);
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
        }
    }
    printf("\n");
}

void buscarmusica(struct caracteristicasMusica *playlist, int tamanhoPlaylist){
    char musica[30];
    int verificar = 0;
    printf("Digite o nome da musica: ");
    scanf(" %29[^\n]", musica);

     if(tamanhoPlaylist == 0){
        printf("A playlist nao possui nenhuma musica cadastrada\n");
    } else{
        for(int i = 0; i < tamanhoPlaylist; i++){
            if(strcmp(musica, playlist[i].titulo) == 0){
                printf("A musica %s esta na playlist!", musica);
                verificar = 1;
            }
        }
    }
    if(verificar == 0){
        printf("Musica nao encontrada.\n");
    }
    printf("\n");
}

void editar(struct caracteristicasMusica *playlist, int tamanhoPlaylist){
    int verificar;
    char titulo2[30], artista2[30], album2[30], genero2[30];
    printf("Qual musica deseja editar?\n");
    
    for(int i = 0; i < tamanhoPlaylist; i++){
        printf("%d. %s\n", i + 1, playlist[i].titulo);
    }
    
    scanf("%d", &verificar);
    
    printf("Nome: ");
    scanf(" %29[^\n]", playlist[verificar - 1].titulo);
    
    printf("Artista/Banda: ");
    scanf(" %29[^\n]", playlist[verificar - 1].artista);
    
    printf("Album: ");
    scanf(" %29[^\n]", playlist[verificar - 1].album);
    
    printf("Genero: ");
    scanf(" %29[^\n]", playlist[verificar - 1].genero);
    
}

struct caracteristicasMusica* remover(struct caracteristicasMusica *playlist, int *tamanhoPlaylist) {
    int verificar;
    printf("Qual musica deseja remover?\n");
    
    for(int i = 0; i < *tamanhoPlaylist; i++){
        printf("%d. %s\n", i + 1, playlist[i].titulo);
    }
    scanf("%d", &verificar);
    
    if (verificar >= 1 && verificar <= *tamanhoPlaylist) {
        for (int i = verificar - 1; i < *tamanhoPlaylist - 1; i++) {
            playlist[i] = playlist[i + 1];
        }
        
        (*tamanhoPlaylist)--;
        
        struct caracteristicasMusica *novaPlaylist = realloc(playlist, (*tamanhoPlaylist) * sizeof(struct caracteristicasMusica));
        
        if (novaPlaylist == NULL) {
            printf("Erro na realocacao de memoria.");
            exit(1);
        }
        
        printf("Musica removida com sucesso.\n");
        
        return novaPlaylist;
    } else {
        printf("Indice invalido.\n");
        return playlist;
    }
    printf("\n");
}
    
    
int main() {
    int escolha, escolha2;
    int tamanhoArray = 4;
    int tamanhoPlaylist = 0;
    struct caracteristicasMusica *playlist = NULL;

    do {
        playlist = (struct caracteristicasMusica *)realloc(playlist, (tamanhoPlaylist + 1) * sizeof(struct caracteristicasMusica));

        if (playlist == NULL) {
            printf("Erro na alocacao de memoria.");
            return 1;
        }

        printf("1. Inserir nova musica.\n");
        printf("2. Favoritar musica.\n");
        printf("3. Mostrar musicas cadastradas na playlist, exibindo quais foram favoritadas.\n");
        printf("4. Buscar musica.\n");
        printf("5. Editar informacoes de uma musica.\n");
        printf("6. Remover musica.\n");
        printf("7. Salvar e sair.\n");

        scanf("%d", &escolha);

        if (escolha == 1) {
            playlist[tamanhoPlaylist] = inserir_musica();
            tamanhoPlaylist++;
        } else if (escolha == 2) {
            favoritarMusica(playlist, tamanhoPlaylist);
        } else if (escolha == 3) {
            visualizar(playlist, tamanhoPlaylist);
        } else if (escolha == 4){
            buscarmusica(playlist, tamanhoPlaylist);
        } else if (escolha == 5){
            editar(playlist, tamanhoPlaylist);
        } else if(escolha == 6){
            playlist = remover(playlist, &tamanhoPlaylist);
        } else if(escolha == 7){
            
        }
        
    } while (escolha == 0 || escolha == 1 || escolha == 2 || escolha == 3 
    || escolha == 4 || escolha == 5 || escolha == 6);

    free(playlist);

    return 0;
}