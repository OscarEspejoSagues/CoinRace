#include <conio.h>

enum class Key
{
	NONE, W, A, S, D, ENTER, ESC
};static Key getKey() 
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 87: case 119:
			return Key::W; 
		case 65: case 97:
			return Key::A; 
		case 83: case 115:
			return Key::S; 
		case 68: case 100:
			return Key::D; 
		case 13:
			return Key::ENTER; 
		case 27:
			return Key::ESC; 
		}
	}
	return Key::NONE;
}


class Player
{
public:
	Player(int &x, int &y, int &puntuacion);
	void playerinicial(int x, int y);
	
	int x;
	int y;
	char pj = '@';
	int puntuacion;


private:
	
};

