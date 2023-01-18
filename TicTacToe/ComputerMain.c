#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include"checkWin.h"
#include"printBoard.h"
#include"getMove.h"

#define TOTALGAME 100

int main(){
	int dim=3;
	int moveCnt=0;
	int check,currP;
	int row,col;
	int *board=NULL;

	board=(int *)calloc(dim*dim,sizeof(int));
	srand(time(0));

	printBoard(board,dim);
	board=(int *)calloc(dim*dim,sizeof(int));
	moveCnt=0;
	do{
		sleep(1);
		moveCnt++;
		currP=(moveCnt%2==0)?-1:1;
		if(currP==1)
			printf("Player 1's turn\n");
		else
			printf("Player2's turn\n");

		row=rand()%dim+1;
		col=rand()%dim+1;

		check=getMove(board,row,col,currP,dim);
		printBoard(board,dim);

		if(check<0){
			printf("Invalid input\n");
			moveCnt--;
			continue;
		}
		
		if(check==1){
			printf("Cell is already occupied\n");
			moveCnt--;
			continue;
		}
		
		check=checkWin(board,row,col,currP,dim);
	
		if(check!=0){
			if(check==1){
				printf("Player1 Wins\n");
			}
			else{
				printf("Player2 Wins\n");
			}

			break;
		}
	}while(moveCnt!=dim*dim);
	

	if(moveCnt==(dim*dim)&&check==0){
		printf("It's a TIE\n");
	}

	return 0;
}
