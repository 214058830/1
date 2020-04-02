#include"game.h"

void test(){
	int input;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("请输入指令->:");
		scanf("%d", &input);
		switch (input){
			case 1:
				game();
				break;
			case 0:
				break;
			default:
				printf("输入有误，请从新输入。\n");
		}
	}while(input);
}
int main(){
	test();
	return 0;
}