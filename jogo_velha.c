#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

void mostrar_tab(char tab[SIZE][SIZE]) 
{
	
  printf("      1    2    3\n\n");
  printf("1     %c  | %c  | %c\n", tab[0][0],tab[0][1],tab[0][2]);
  printf("     ---------------\n");
  printf("2     %c  | %c  | %c \n", tab[1][0],tab[1][1],tab[1][2]);
  printf("     ---------------\n");
  printf("3     %c  | %c  | %c\n", tab[2][0],tab[2][1],tab[2][2]);

	return;  
}

int main() 
{
	
	char tab[SIZE][SIZE], jog;
	int i,j, linha, coluna, final_jogo = 0,rodada;
	
	for (i = 0; i < SIZE; i++) 
	{
		for (j = 0; j < SIZE; j++) 
		{
		  tab[i][j] = ' ';
		}
	}
	
	
	mostrar_tab(tab);
	
	for (rodada = 1; rodada <= 9 && final_jogo == 0; rodada++) 
	{ 
		if (rodada % 2 == 1) 
		{
		  jog = 'X';
		}
		else 
		{
		  jog = 'O';
		}
		
		do 
		{
		  printf("\nJogador %c, digite a linha e coluna que deseja jogar (entre 1 e 3): ", jog);
		  scanf("%d %d", &linha, &coluna);
		} while(linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tab[linha-1][coluna-1] != ' ');
		
		tab[linha-1][coluna-1] = jog;
		
		system("cls");
		
		mostrar_tab(tab);
		
		if (tab[linha-1][0] == tab[linha-1][1] && tab[linha-1][1] == tab[linha-1][2]) //verifica se ganhou na horizontal
		{
		  final_jogo = 1;
		}
		else 
		{
			if (tab[0][coluna-1] == tab[1][coluna-1] && tab[1][coluna-1] == tab[2][coluna-1]) //verifica se ganhou na vertical
			{
				final_jogo = 1;
			}
			else 
			{
				if (linha == coluna && tab[0][0] == tab[1][1] && tab [1][1] == tab[2][2])  //verfica diagonal central
				{
				  final_jogo = 1;
				}
				else 
				{
				  if (linha + coluna == 4 && tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0]) 
				  {
				    final_jogo = 1;
				  }
				}
			}
		}
	}
	system("cls");
	
	mostrar_tab(tab);
	
	if (final_jogo == 0) 
	{
		printf("\nEmpate!");
	}
	else 
	{
		printf("\nVitoria do jogador '%c'\n", jog);
	}
	
	return 0;
}
