#include "snake.h"

void Snake::Fruit() {
	xFruit = rand() % widht + 1;
	yFruit = rand() % height + 1;
	fruite = rand() % 6;
}

void Snake::Setup() {
	xPos = widht / 2;
	yPos = height / 2;
	score = 0;
	gameOver = false;
	Fruit();
}

void Snake::Speed() {
	Sleep(speed);
}

void Snake::line() {
	for (int i = widht; i > 0; --i) {
		std::cout << "#-";
	}std::cout << std::endl;
}

void Snake::Draw() {
	DeleteCoursore();
	system("cls");
	line();

	for (int q = height; q > 0; --q) {

		for (int i = 0; i < widht; ++i) {
			if (i == 0) {
				std::cout << "#";
			}
			if (i == xPos && q == yPos) {
				std::cout << "00";
			}
			else if (i == xFruit && q == yFruit) {

				std::cout << fruite << fruite;
			}

			else {
				bool print = false;
				for (int y = 0; y < nTail; ++y) {
					if (xTail[y] == i && yTail[y] == q) {
						print = true;
						std::cout << "oo";
					}
				}
				if (!print)
					std::cout << "  ";
			}
			if (i == widht - 1) {
				std::cout << "#";
			}


		}
		std::cout << std::endl;
	}
	line();
}

void Snake::Input() {
	if (_kbhit()) {
		switch (_getch()) {

		case 'a':
			if (dir != RIGHT) {
				dir = LEFT;
			}
			break;
		case 'd': if (dir != LEFT) {
			dir = RIGHT;
		}
				break;
		case 'w': if (dir != DOWN) {
			dir = UP;
		}
				break;
		case 's': if (dir != UP) {
			dir = DOWN;
		}
				break;
		case 'p': system("pause");

			break;
		}
	}
}

bool Snake::Logic() {
	
	switch (dir)
	{
	case UP: ++yPos;
		break;
	case DOWN: --yPos;
		break;
	case RIGHT: ++xPos;
		break;
	case LEFT: --xPos;
		break;
	}
	int prevX = xTail[0];
	int prevY = yTail[0];
	int prev2X, prev2Y;
	xTail[0] = xPos;
	yTail[0] = yPos;
	for (int i = 1; i < nTail; i++) {
		prev2X = xTail[i];
		prev2Y = yTail[i];

		xTail[i] = prevX;
		yTail[i] = prevY;

		prevX = prev2X;
		prevY = prev2Y;
	}
	if (xPos == xFruit && yPos == yFruit) {
		score += 10;
		if (speed) {
			speed -= 10;
			++nTail;
			std::cout << (char)7;
		}
		Fruit();

	}
	for (int i = nTail; i > 0; --i) {
		if (xPos == xTail[i] && yPos == yTail[i]) {
			gameOver = true;
			std::cout << "Your score: " << score;
		}
	}
	if (xPos<0 || xPos>widht - 1 || yPos<1 || yPos>height) {
		gameOver = true;
		std::cout << "Your score: " << score;
	}
	return gameOver;

}

void Snake::DeleteCoursore() {
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}
