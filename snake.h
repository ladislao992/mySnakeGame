#pragma once
#include <iostream>
#include <Windows.h>
#include"snake.h"
#include <conio.h>



enum eDirection {
	STOP = 0,
	UP,
	DOWN,
	RIGHT,
	LEFT
};
class Snake {
public:

	void Setup();
	void Speed();;
	void Draw();
	void Input();
	bool Logic();
	void DeleteCoursore();

private:
	void Fruit();
	void line();
private:
	const int widht = 40;
	const int height = 30;

	eDirection dir;
	int speed = 300;

	int xPos, yPos, xFruit, yFruit, score;
	bool gameOver;

	int xTail[100], yTail[100];
	int nTail = 1;
	char fruite;


};
