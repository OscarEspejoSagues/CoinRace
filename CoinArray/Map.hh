class Map
{
public:
	Map(int &diff);                                     //constructor de la clase MAP
	void changeSymbol(int row, int col, char sym);     //funcion que cambiara els simbols del mapa
	void printField();                                //funcion que printa el mapa
	void mapGenerator();							 //funcion que permite generar el mapa lleno de puntos


private:
	char **md;
	int row;
	int col;
};

