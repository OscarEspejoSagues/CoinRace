class CoinManager
{
public:
	CoinManager(int &rows, int &cols);
	void coinGenerator(int rows, int columns);
	void coininmap(int rows, int columns);

private:
	int filasMapa;
	int columnasMapa;
	int cantidaddemonedas;
};

