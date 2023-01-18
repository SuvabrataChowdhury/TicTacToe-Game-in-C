#include<stdio.h>
#include<stdlib.h>
#include"checkWin.h"
#include"printBoard.h"
#include"getMove.h"

int main(){
	int dim;
	int moveCnt=0;
	int check,currP;
	int row,col;
	int *board=NULL;
	
	printf("Enter the dimention of the board\n");
	scanf("%d",&dim);
	
	board=(int *)calloc(dim*dim,sizeof(int));
	
	printBoard(board,dim);
	do{
		moveCnt++;
		currP=(moveCnt%2==0)?-1:1;
		if(currP==1)
			printf("Player 1's turn\n");
		else
			printf("Player 2's turn\n");
		
		printf("Enter the coordinate\n");
		scanf("%d%d",&row,&col);
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
			if(check==1)
				printf("Player1 Wins\n");
			else
				printf("Player2 Wins\n");
			
			break;
		}
	}while(moveCnt!=dim*dim);
	
	if(moveCnt==dim*dim)
		printf("It's a TIE\n");
	
	return 0;
}
