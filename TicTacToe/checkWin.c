#include<stdio.h>
#include<stdlib.h>

int checkWin(int *board,int row,int col,int currPlayer,int dim){
/*To check wheather the current player has won or not we need to check for vertical match, horizontal match and diagonal match.
 There are two ways a diagonal match can occur a major diagonal match and a minor diagonal match*/
 	int check;
 	int flag=0;

	//Logic for vertical match
	check=*(board+(row-1)*dim+(col-1));
	for(int i=1;i<dim;i++){
		if(check==*(board+((row-1+i)%dim)*dim+(col-1))){
			check=*(board+((row-1+i)%dim)*dim+(col-1));
			flag=1;
		}
		else{
			flag=0;
			break;
		}
	}

	if(flag==1)
		return currPlayer;

	/*if(*(board+(row-1)*dim+(col-1))==*(board+(row%dim)*dim+(col-1))&&*(board+(row%dim)*dim+(col-1))==*(board+((row+1)%dim)*dim+(col-1)))
		return currPlayer;//Vertical Match*/
	//Logic for horizontal match	
	check=*(board+(row-1)*dim+(col-1));
	for(int i=1;i<dim;i++){
		if(check==*(board+(row-1)*dim+((col-1+i)%dim))){
			check=*(board+(row-1)*dim+((col-1+i)%dim));
			flag=1;
		}
		else{
			flag=0;
			break;
		}
	}

	if(flag==1)
		return currPlayer;
	
	/*if(*(board+(row-1)*dim+(col-1))==*(board+(row-1)*dim+col%dim)&&*(board+(row-1)*dim+col%dim)==*(board+(row-1)*dim+(col+1)%dim))
		return currPlayer;//Horizontal Match*/
	//Logic for major diagonal match
	if(row==col){
		check=*board;
		for(int i=1;i<dim;i++){
			if(check==*(board+(i%dim)*dim+(i%dim))){
				check=*(board+(i%dim)*dim+(i%dim));
				flag=1;
			}
			else{
				flag=0;
				break;
			}
		}

		if(flag==1)
			return currPlayer;
	}
	/*if(*board==currPlayer&&*(board+4)==currPlayer&&*(board+8)==currPlayer)
		return currPlayer;//Major Diagonal Match*/
	//Logic for minor diagonal match
	if(row+col-2==dim-1){
		check=*(board+dim-1);
		for(int i=2;i<=dim;i++){
			if(check==*(board+(dim-1)*i)){
				check=*(board+(dim-1)*i);
				flag=1;
			}
			else{
				flag=0;
				break;
			}
		}

		if(flag==1)
			return currPlayer;
	}
	/*if(*(board+2)==currPlayer&&*(board+4)==currPlayer&&*(board+6)==currPlayer)
		return currPlayer;//Minor Diagonal Match*/
	
	return 0; //No Match
}
/*
int main(){
	int moveCnt=0;
	int check,currP;
	int row,col;
	int board[dim][dim]={0};
	
	printBoard((int *)board);
	do{
		moveCnt++;
		currP=(moveCnt%2==0)?-1:1;
		if(currP==1)
			printf("Player 1's turn\n");
		else
			printf("Player 2's turn\n");
		
		printf("Enter the coordinate\n");
		scanf("%d%d",&row,&col);
		check=getMove((int *)board,row,col,currP);
		
		printBoard((int *)board);
		
		if(check<0){
			printf("Invalid input\n");
			moveCnt--;
		}
		
		if(check==1){
			printf("Cell is already occupied\n");
			moveCnt--;
		}
		
		check=checkWin((int *)board,row,col,currP);
		
		if(check!=0){
			if(check==1)
				printf("Player1 Wins\n");
			else
				printf("Player2 Wins\n");
			
			break;
		}
	}while(moveCnt!=9);
	
	if(moveCnt==9)
		printf("It's a TIE\n");
	
	return 0;
}*/
