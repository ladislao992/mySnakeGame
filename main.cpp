#include <iostream>
#include <Windows.h>
#include"snake.h"
int main()
{
	
	Snake S;
		S.Setup();

		bool st = false;
	while (!st) {
		S.Speed();
		S.Draw();
		S.Input();
		st = S.Logic();
	}

}
