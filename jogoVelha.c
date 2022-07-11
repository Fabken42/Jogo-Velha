#include <stdio.h>
#include <stdlib.h>

// JOGO DA VELHA 

void imprime_tabuleiro();
void joga();
void verifica_venceu();
void imprimeTrofeu();
void jogarNovamente();
void limpaJogo();

char tabuleiro[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
int jogador=1,numJogadas=0,vencedor=0,empate=0;

	void imprime_tabuleiro(){
		int i,j;
		printf("\n          %d     %d     %d\n\n",0,1,2);
		for(i=0;i<3;i++){
			printf("\t     |     |      \n");	
			printf("    %d     %c  |  %c  |  %c  \n",i,tabuleiro[i][0],tabuleiro[i][1],tabuleiro[i][2]);	
			printf("\t     |     |      \n");	
			if(i<2)
				printf("\t=================\n");
		}
	}
	
	void joga(){
		int lin,col;
		printf("-----------------------------------\n");
		printf("\n\tJOGADOR %d\n",jogador);
		while(1){
			printf("\tDigite a linha: ");
			scanf("%d",&lin);
			printf("\tDigite a coluna: ");
			scanf("%d",&col);
			
			if((lin>=0 && lin <3) && (col>=0 && col <3) && (tabuleiro[lin][col]==' ')){
				if(jogador==1){
					tabuleiro[lin][col]='X';
					jogador++;
				}
				else{
					tabuleiro[lin][col]='O';
					jogador--;
				}
				numJogadas++;
				break;
			}
			else
				printf("\tInforme uma posicao valida!\n\n");
		}
	}
	
	void verifica_venceu(){//MELHORAR ESTA FUNCAO
		int aux;
		//VERIFICA SE GANHOU POR LINHA OU COLUNA
		for(aux=0;aux<3;aux++){	
			if(tabuleiro[aux][0]==tabuleiro[aux][1] && tabuleiro[aux][1]==tabuleiro[aux][2]){
				if(tabuleiro[aux][0]=='X')
					printf("\n\tJogador 1 venceu!\n\n");
				else if(tabuleiro[aux][0]=='O')
					printf("\n\tJogador 2 venceu!\n\n");
				
				if(tabuleiro[aux][0]!=' ')
					vencedor=1;
				}
				
			else if(tabuleiro[0][aux]==tabuleiro[1][aux] && tabuleiro[1][aux]==tabuleiro[2][aux]){
				if(tabuleiro[0][aux]=='X')
					printf("\n\tJogador 1 venceu!\n\n");
				else if(tabuleiro[0][aux]=='X')
					printf("\n\tJogador 2 venceu!\n\n");
				
				if(tabuleiro[0][aux]!=' ')
					vencedor=1;
				}
		}
		//VERIFICA SE GANHOU POR DIAGONAL PRINCIPAL
		if(tabuleiro[0][0]==tabuleiro[1][1] && tabuleiro[1][1]==tabuleiro[2][2]){
			if(tabuleiro[0][0]=='X')
				printf("\n\tJogador 1 venceu!\n\n");
			else if(tabuleiro[0][0]=='O')
				printf("\n\tJogador 2 venceu!\n\n");
				
			if(tabuleiro[0][0]!=' ')
				vencedor=1;
		}
		//VERIFICA SE GANHOU POR DIAGONAL SECUNDARIA
		else if(tabuleiro[0][2]==tabuleiro[1][1] && tabuleiro[1][1]==tabuleiro[2][0]){
			if(tabuleiro[0][2]=='X')
				printf("\n\tJogador 1 venceu!\n\n");
			else if(tabuleiro[0][2]=='O')
				printf("\n\tJogador 2 venceu!\n\n");
				
			if(tabuleiro[0][2]!=' ')
				vencedor=1;
		}
		//VERIFICA EMPATE
		if(numJogadas==9){
			printf("\n\tA partida empatou!\n\n");
			empate=1;
		}
	}
	
	void imprimeTrofeu(){
	printf("	   ___________\n");
    printf("          '._==_==_=_.'\n");
    printf("          .-\\:      /-.\n");
    printf("         | (|:.     |) |\n");
    printf("          '-|:.     |-'\n");
    printf("            \\::.    /\n");
    printf("             '::. .'\n");
    printf("               ) (\n");
    printf("             _.' '._\n");
    printf("            `%c%c%c%c%c%c%c`\n\n",34,34,34,34,34,34,34);
	}
	
	void imprimeEmpate(){
		printf("\t     _____\n");
		printf("\t   ,'  -. `. \n");
		printf("\t  /   - _ - \\ \n");
		printf("\t :    ' _)'  :  \n");
		printf("\t(_           ;)   \n");
		printf("\t  \\     _   /  \n");
		printf("\t   `..___..'   \n");
		printf("\t     ;._:    \n");
		printf("\t     /    \\ \n\n");
	}
	
	void jogarNovamente(){
		int opt;
		printf("\tDeseja jogar novamente [0-Nao | 1-Sim]\n");
		scanf("%d",&opt);
		if(opt==0)
			exit(1);
		else{
			limpaJogo();
		}
	}
	
	void limpaJogo(){
		int i,j;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				tabuleiro[i][j]=' ';
			}
		}
		jogador=1;numJogadas=0;vencedor=0;empate=0;
	}
	

int main(int argc, char *argv[]) {
	printf("\n      ----JOGO DA VELHA----\n\n");	
	do{
		imprime_tabuleiro();
		printf("\n");
		joga();
		verifica_venceu();
		
		if(vencedor==1){
			imprimeTrofeu();
			jogarNovamente();
		}
		else if(empate==1){
			imprimeEmpate();
			jogarNovamente();		
		}
	} while(1);
	return 0;
}
