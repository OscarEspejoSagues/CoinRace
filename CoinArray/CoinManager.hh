

//Creacion de la clase CoinManager


typedef struct coin {
	int posX;
	int posY;
} apuntCoins;

class CoinManager
{
public:
	void coinGenerator(int rows, int columns,int diff);
	void removeCoin(int &posX, int &posY,int diff,int rows,int cols);
	int coininmap(const apuntCoins **total) const;
	int monedas(int rows,int columns,int diff);
	CoinManager(int &rows, int &cols);
	int filasMapa(int filasMapa);
	int columnasMapa(int columnasMapa);

private:
	apuntCoins *coinData;
	int cantidaddemonedas;
};

