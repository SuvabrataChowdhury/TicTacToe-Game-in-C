#include<stdio.h>
#include<stdlib.h>

int printBoard(int *board,int dim){
	system("clear");
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			/*if(j!=0||j!=dim-1)
				printf("|");*/
			
			switch(*(board+i*dim+j)){
				case 1:
					printf("X");
					break;
				case 0:
					printf(" ");
					break;
				case -1:
					printf("O");
			}
			
			if(j!=dim-1)
				printf("|");
		}
		
		if(i!=dim-1){
			printf("\n");
			for(int j=0;j<dim;j++)
				printf("--");
			printf("\n");
		}
	}
	
	printf("\n");
	
	return 0;
}

/*int main(){
	int board[4][4]={{1,-1,-1,1},{1,-1,-1,-1},{1,-1,1,1},{0,-1,0,0}};
	
	printBoard((int *)board,4);
	return 0;
}*/
