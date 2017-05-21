//Creacion de la clase Map
class Map
{
public:
	Map(int &diff, int &row, int &col);                               //constructor de la clase MAP
	void changeSymbol(int row, int col, char sym);                    //funcion que cambiara els simbols del mapa
	void printField(int &row, int &col);                             //funcion que printa el mapa
	void mapGenerator(int &row, int &col);							 //funcion que permite generar el mapa lleno de puntos

public:
	char **md;
	int row;
	int col;
};

