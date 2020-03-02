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
/* 3 external declarations */
/* 4 typedefs */
typedef struct {
	int coluna;
	int linha;
	char token[MAX_TAMANHO_NOME_VAR]
} Token;
/* 5 global variable declarations */
/* 6 function prototypes */
int valida_caractere(char);

int main(int argc, char *argv[]) {
	FILE *fp;
	char c;

	if(argc == 1) {
		printf("Usage:\n\t$catraca [options] [file-names]\n");
		printf("options:\n");
		printf("\tc - Compilar. Realiza analise lexica, sintatica e semantica.\n");
		printf("\nfile-names - Um ou mais nomes de arquivos, separados por virgula.");

//    	getchar();
		exit(-1);
	}

	if(fp = fopen(argv[1], "r")) {

		do {
			c = fgetc(fp);
			valida_caractere(c);

		} while(!feof(fp));

	} else {
		printf("Nao foi possivel ler do arquivo \"%s\"", argv[1]);
    	//getchar();
		exit(-1);
	}

	printf("Fim da compilacao!\n");
    //getchar();
	exit(1);
}

/* 8 function declarations */
int valida_caractere(char c) {
	char caracteres_permitidos[] = "0123456789,.(){}[]abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_&|;+-*^/\%=:\"<>! \t\n\v\f\r";
	char char_analizado[] = isspace(c) ? "%d" : "%c";
	char string_template[] = strcat(char_analizado, " = %s (%d)\n");
	"%c == %c = %s (%d)\n";
	int i = 0, valido;

	for(; caracteres_permitidos[i] != '\0'; i++) {
		valido = caracteres_permitidos[i] == c;
		printf(string_template, caracteres_permitidos[i], c, valido ? "true" : "false", c);
	}
}