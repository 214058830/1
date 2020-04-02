#include"game.h"

void game(){
	char board[ROW][COL], ret;
	InitBoard(board);
	DisplayBoard(board);
	while(1){
		ComputerMove(board);
		DisplayBoard(board);
		ret = IsWin(board);
		if(ret != 'j'){
			break;
		}
		PlayerMove(board);
		DisplayBoard(board);
		ret = IsWin(board);
		if(ret != 'j'){
			break;
		}
	}
	if(ret == 'X'){
		printf("玩家赢\n");
	}
	else if(ret == 'O'){
		printf("电脑赢\n");
	}
	else
		printf("平局\n");
}
void menu(){
	printf("*****************************\n");
	printf("***  1.play       0.exit  ***\n");
	printf("*****************************\n");
}

void InitBoard(char board[ROW][COL]){
	memset(board, ' ', sizeof(board[0][0])*ROW*COL);
}

void DisplayBoard(char board[ROW][COL]){
	int i;
	for(i=0; i<ROW; i++){
		int j = 0;
		for(j=0; j<COL; j++){
			printf(" %c ", board[i][j]);
			if(j < COL-1){
				printf("|");
			}
		}
		printf("\n");
		if(i < ROW-1){
			for(j=0; j<COL; j++){
				printf("---");
				if(j<COL-1){
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

void ComputerMove(char board[ROW][COL]){
	int x = 0;
	int y = 0;
	while(1){
		x = rand()%ROW;
		y = rand()%COL;
		if(board[x][y] == ' '){
			board[x][y] = 'O';
			break;
		}
	}
}
void PlayerMove(char board[ROW][COL]){
	int x, y;
	printf("请输入要下的坐标->:\n");
	while(1){
		scanf("%d%d", &x, &y);
		if(x>=1 && x<=3 && y>=1 && y<=3){
			if(board[x-1][y-1] == ' '){
				board[x-1][y-1] = 'X';
				break;
			}
			else
				printf("输入有误，请从新输入。\n");
		}
	}
}

static int IsFull(char board[ROW][COL]){
	int i, j;
	for(i=0; i<ROW; i++){
		for(j=0; j<COL; j++){
			if(board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL]){
	int i = 0;
	for(i=0; i<ROW; i++){
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' '){
			return board[i][0];
		}
	}
	for(i=0; i<COL; i++){
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' '){
			return board[0][i];
		}
	}
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' '){
		return board[0][0];
	}
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '){
		return board[0][2];
	}
	if(IsFull(board)){
		return 'p';
	}
	return 'j';
}
