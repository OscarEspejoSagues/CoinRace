

//Creacion de la clase CoinManager


typedef struct coin {
	int posX;
	int posY;
} apuntCoins;

class CoinManager
{
public:
	void coinGenerator(int rows, int columns);
	void removeCoin(int &posX, int &posY);
	int coininmap(apuntCoins **total) const;
	int monedas(int rows,int columns);
	CoinManager(int &rows, int &cols);

private:
	apuntCoins *coinData;
	int filasMapa;
	int columnasMapa;
	int cantidaddemonedas;
};

