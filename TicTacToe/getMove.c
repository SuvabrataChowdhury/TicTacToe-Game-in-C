#include<stdio.h>
#include<stdlib.h>
#include"printBoard.h"
int getMove(int *board,int row,int col,int sign,int dim){
	if(!(row>0&&row<=dim)||!(col>0&&col<=dim))
		return -1; //Invalid Input
	else if(*(board+(row-1)*dim+(col-1))!=0)
		return 1; // Space is occupied
	else
		*(board+(row-1)*dim+(col-1))=sign;
	
	return 0;
}

/*int main(){
	int moveCnt=0;
	int check;
	int x,y;
	int board[3][3]={0};
	
	printBoard((int *)board,3);
	while(1){
		printf("Enter the coordinate\n");
		scanf("%d%d",&x,&y);
		check=getMove((int *)board,x,y,(moveCnt%2==0)?1:-1,3);
		
		printBoard((int *)board,3);
		
		if(check<0){
			printf("Invalid input\n");
			moveCnt--;
		}
		
		if(check==1){
			printf("Cell is already occupied\n");
			moveCnt--;
		}
		
		moveCnt++;
	}
	
	return 0;
}*/
