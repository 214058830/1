#include"game.h"

void test(){
	int input;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("������ָ��->:");
		scanf("%d", &input);
		switch (input){
			case 1:
				game();
				break;
			case 0:
				break;
			default:
				printf("����������������롣\n");
		}
	}while(input);
}
int main(){
	test();
	return 0;
}