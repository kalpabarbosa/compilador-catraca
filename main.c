/* main.c */
/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 * 
 * Authors:
 * 		Kalpa Vrikcha <kalpa.barbosa@gmail.com>
 * 		Nathalia Lins <nathalia.lins1@gmail.com>
 * 
 * Repository:
 * 		git@github.com:kalpabarbosa/compilador-catraca.git
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* 2 defines */
#define MAX_TAMANHO_NOME_VAR	50
#define NULL					((void *)0)
/* 3 external declarations */
/* 4 typedefs */
typedef struct {
	int coluna;
	int linha;
	char nome[MAX_TAMANHO_NOME_VAR];
} Token;

typedef struct ListaToken {
	Token token;
	struct ListaToken *next;
} ListaToken;

/* 5 global variable declarations */
ListaToken *lista_tokens = NULL;
/* 6 function prototypes */
int valida_caractere(char);
ListaToken *insere(Token token, ListaToken*);
int eh_valido(char*);
void imprime_lista(ListaToken*);

int main(int argc, char *argv[]) {
	FILE *fp;
	char c;
	char nome_arquivo[50] = "file1.txt";

	// strcpy(nome_arquivo, argv[1]);
	// if(argc == 1) {
	// 	printf("Usage:\n\t$catraca [options] [file-names]\n");
	// 	printf("options:\n");
	// 	printf("\tc - Compilar. Realiza analise lexica, sintatica e semantica.\n");
	// 	printf("\nfile-names - Um ou mais nomes de arquivos, separados por virgula.");

   	// 	getchar();
	// 	exit(-1);
	// }

	if(fp = fopen(nome_arquivo, "r")) {

		do {
			c = fgetc(fp);
			valida_caractere(c);

		} while(!feof(fp));

		imprime_lista(lista_tokens);

	} else {
		printf("Nao foi possivel ler do arquivo \"%s\"", argv[1]);
    	getchar();
		exit(-1);
	}

	printf("Fim da compilacao!\n");
    // getchar();
	exit(1);
}

/* 8 function declarations */
int valida_caractere(char c) {
	static char nome_token[MAX_TAMANHO_NOME_VAR] = "\000";
	static int posicao = 0;
	static int linha = 0;
	static int coluna = 0;
	Token token;

	if(isspace(c)) {
		posicao = 0;
	} else {
		nome_token[posicao] = c;
		posicao++;
	}

	if(eh_valido(nome_token)) {
		token.coluna = coluna;
		token.linha = linha;
		strcpy(token.nome, nome_token);

		lista_tokens = insere(token, lista_tokens);
		strcpy(nome_token, "\000");
		// posicao = 0;
	}

	coluna++;
	if(c == '\n') {
		linha++;
		coluna = 0;
	}
}

ListaToken *insere(Token token, ListaToken *lista) {
	ListaToken *nova = (ListaToken*) malloc(sizeof(ListaToken));
	nova->token = token;
	nova->next = lista;

	return nova;
}

int eh_valido(char *nome_token) {
	if(nome_token[0] == '\000') return 0;

	return 1;
}

void imprime_lista(ListaToken *lista) {
	ListaToken *l = lista;

	while(l != NULL) {
		printf("%s\n", l->token.nome);

		l = l->next;
	}
}