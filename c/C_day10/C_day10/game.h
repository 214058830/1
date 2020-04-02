#ifndef __GAME_H__
#define __GAME_H__

#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3

void menu();
void game();
void InitBoard(char board[ROW][COL]);
void DisplayBoard(char board[ROW][COL]);
void ComputerMove(char board[ROW][COL]);
void PlayerMove(char board[ROW][COL]);
char IsWin(char board[ROW][COL]);

#endif __GAME_H__