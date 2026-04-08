#include <string.h>
#include <stdio.h>

struct Jogadores {
	int num;
	float peso;
	float altura;
	char inicial;
};

int main() {
	struct Jogadores jogadores[3];
	char nome[50];
	float maior_peso;
	float menor_altura = 2.50;

	for (int i = 0; i < 3; i++) {
		printf("\nNome: ");
		scanf("%s", nome);
		jogadores[i].inicial = nome[0];

		printf("\nNumero da camisa: ");
		scanf("%d", &jogadores[i].num);

		printf("\nPeso do jogador: ");
		scanf("%f", &jogadores[i].peso);

		if (jogadores[i].peso > maior_peso) {
			maior_peso = jogadores[i].peso;
		}

		printf("\nAltura do jogador: ");
		scanf("%f", &jogadores[i].altura);

		if (jogadores[i].altura < menor_altura) {
			menor_altura = jogadores[i].altura;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (menor_altura == jogadores[i].altura) {
			printf("Inicial do jogador mais baixo: %c", jogadores[i].inicial);
		}

		if (maior_peso == jogadores[i].peso) {
			printf("\nNumero da camisa do jogador mais pesado: %d", jogadores[i].num);
		}
	}
	return 0;
}
