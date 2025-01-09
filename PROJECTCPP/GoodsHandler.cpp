#include "GoodsHandler.h"

GoodsHandler::GoodsHandler() : stock(new Goods* [100] {nullptr}), currentNrOfGoods(0), 
currentNrOfFood(0), currentNrOfBulk(0), foodStock(new Goods* [100] {nullptr}), bulkStock(new Goods* [100] {nullptr})
{
}

GoodsHandler::GoodsHandler(const GoodsHandler& other) : stock(new Goods* [100] {nullptr}), currentNrOfGoods(other.currentNrOfGoods), bulkStock(new Goods* [100] {nullptr}),
currentNrOfBulk(0), currentNrOfFood(0), foodStock(new Goods* [100] {nullptr})
{
	for (int i = 0; i < this->currentNrOfGoods; i++)
	{
		Bulk* bPtr = dynamic_cast<Bulk*>(other.stock[i]);

		if (bPtr != nullptr)
		{
			stock[i] = new Bulk(*bPtr);
		}
		else
		{
			Food* cPtr = dynamic_cast<Food*>(other.stock[i]);
			if (cPtr != nullptr)
			{
				stock[i] = new Food(*cPtr);
			}
		}
	}
}
bool GoodsHandler::isValidName(const std::string& name) const {

	for (char c : name) {
		if (!isalpha(c) && c != ' ') {  // Till�ter bara bokst�ver och mellanslag
			return false;
		}
	}
	return true;
}
// -----> Input into Goods constructor from file <-----

void GoodsHandler::readFromFile(const std::string& filename)
{
	std::vector<Goods*> entryAndExitStock;
	int quantity;
	float weight;
	std::string name;
	float volume;
	std::ifstream InStream;
	InStream.open(filename);
	if (InStream.is_open()) {
		if (filename == "StoredFood.txt") {
			while (InStream >> quantity >> weight >> name) {

				entryAndExitStock.push_back(new Food(quantity, weight, name));
				this->currentNrOfFood++;
				this->currentNrOfGoods++;
			}
		}
		else if (filename == "StoredBulk.txt") {
			while (InStream >> volume >> weight >> name) {
				
				entryAndExitStock.push_back(new Bulk(volume, weight, name));
				this->currentNrOfBulk++;
				this->currentNrOfGoods++;
			}
		}
	}
	InStream.close();
	if (currentNrOfGoods < 100)
	{
		for (int i = 0; i < this->currentNrOfGoods; i++)
		{
			if (this->stock[i] == nullptr)
			{
				this->stock[i] = entryAndExitStock[i];
			}
		}
		if (filename == "StoredFood.txt")
		{
			for (int i = 0; i < this->currentNrOfFood; i++)
			{
				if (this->foodStock[i] == nullptr)
				{
					this->foodStock[i] = entryAndExitStock[i];
				}
			}
		}
		else if (filename == "StoredBulk.txt")
		{
			for (int i = 0; i < this->currentNrOfBulk; i++)
			{
				if (this->bulkStock[i] == nullptr)
				{
					this->bulkStock[i] = entryAndExitStock[i];
				}
			}
		}
	}
	else
	{
		std::cout << "Error; File exceeds 100" << std::endl;
	}
}

//-----> Output into text file <-----

void GoodsHandler::addToFile()
{
	std::ofstream OutStreamFood;
	std::ofstream OutStreamBulk;
	OutStreamBulk.open("StoredBulk.txt");
	OutStreamFood.open("StoredFood.txt");
	if (OutStreamFood.is_open() || OutStreamBulk.is_open())
	{
		for (int i = 0; i < this->currentNrOfGoods; i++)
		{
			Food* fPtr = dynamic_cast<Food*>(stock[i]);
			if (fPtr != nullptr)
			{
				OutStreamFood << std::to_string(fPtr->getQuantity()) + "\n";
				OutStreamFood << std::to_string(fPtr->getWeight()) + "\n";
				OutStreamFood << fPtr->getName() + "\n";
			}
			else {
				Bulk* bPtr = dynamic_cast<Bulk*>(stock[i]);
				if (bPtr != nullptr)
				{
					OutStreamBulk << std::to_string(bPtr->getVolume()) + "\n";
					OutStreamBulk << std::to_string(bPtr->getWeight()) + "\n";
					OutStreamBulk << bPtr->getName() + "\n";
				}
			}
		}
	}
	OutStreamFood.close();
	OutStreamBulk.close();
}
//----->Destructor<-----

GoodsHandler::~GoodsHandler() {
	// Deleting arrays
	//Objects already deleted i smart pointer
	delete[] foodStock;
	delete[] bulkStock;
	delete[] stock;


	std::cout << "\nstock ptr deleted" << std::endl;
}

//----->ADD_GOODS<-----

bool GoodsHandler::addGoods(Goods* aGoods)
{
	
	if (aGoods != nullptr && !isValidName(aGoods->getName())) {
		std::cout << "Invalid name for item. Cannot add to stock." << std::endl;
		return false;
	}

	if (this->currentNrOfGoods < 100) {
		stock[this->currentNrOfGoods] = aGoods;
		this->currentNrOfGoods++;

		Food* foodPtr = dynamic_cast<Food*>(aGoods);
		if (foodPtr != nullptr) {
			if (this->currentNrOfFood < 100) {
				foodStock[this->currentNrOfFood] = aGoods;
				this->currentNrOfFood++;
			}
		}
		else {
			Bulk* bulkPtr = dynamic_cast<Bulk*>(aGoods);
			if (bulkPtr != nullptr) {
				if (this->currentNrOfBulk < 100) {
					bulkStock[this->currentNrOfBulk] = aGoods;
					this->currentNrOfBulk++;
				}
			}
		}

		return true;
	}

	return false;
}

//----->SHOW_GOODS<-----

void GoodsHandler::showAll() const {
	Goods** allGoods = new Goods * [this->currentNrOfGoods];  

	int index = 0;

	
	for (int i = 0; i < this->currentNrOfFood; i++) {
		if (foodStock[i] != nullptr) {
			allGoods[index++] = foodStock[i];
		}
	}

	
	for (int i = 0; i < this->currentNrOfBulk; i++) {
		if (bulkStock[i] != nullptr) {
			allGoods[index++] = bulkStock[i];
		}
	}

	// LAMBDA 1P
	std::sort(allGoods, allGoods + index, [](Goods* a, Goods* b) {
		return a->getWeight() > b->getWeight();  // J�mf�r vikten ** KOLLA �VER
		});

	std::cout << "Showing all goods (sorted by weight):" << std::endl;
	for (int i = 0; i < index; i++) {
		if (allGoods[i] != nullptr) {
			std::cout << allGoods[i]->toString() << std::endl;
		}
	}
	delete[] allGoods;
}



void GoodsHandler::showFood() const
{
	std::cout << "\nShowing food items:\n";
	for (int i = 0; i < this->currentNrOfFood; i++) {
		if (foodStock[i] != nullptr) {
			std::cout << foodStock[i]->toString() << std::endl;
		}
	}
}

void GoodsHandler::showBulk() const
{
	std::cout << "\nShowing bulk items:\n";
	for (int i = 0; i < this->currentNrOfBulk; i++) {
		if (bulkStock[i] != nullptr) {
			std::cout << bulkStock[i]->toString() << std::endl;
		}
	}
}

//----->Operator<-----

void GoodsHandler::operator=(const GoodsHandler& other)
{
	if (this != &other)
	{
		for (int i = 0; i < this->currentNrOfGoods; i++)
		{
			delete this->stock[i];
		}
		this->currentNrOfGoods = other.currentNrOfGoods;

		for (int i = 0; i < this->currentNrOfGoods; i++)
		{
			Bulk* bPtr = dynamic_cast<Bulk*>(other.stock[i]);

			if (bPtr != nullptr)
			{
				stock[i] = new Bulk(*bPtr);
			}
			else {
				Food* cPtr = dynamic_cast<Food*>(other.stock[i]);
				if (cPtr != nullptr)
				{
					stock[i] = new Food(*cPtr);
				}
			}
		}
	}
}
// FUNKTIONSPEKARE
double sumWeight(const Goods* goods) {
	return goods->getWeight(); 
}

double sumVolume(const Goods* goods) {
	const Bulk* bulkPtr = dynamic_cast<const Bulk*>(goods);

	if (bulkPtr != nullptr) {
		return bulkPtr->getVolume(); 
	}
	return 0.0f;
}

int sumQuantity(const Goods* goods) {
	const Food* foodPtr = dynamic_cast<const Food*>(goods);

	if (foodPtr != nullptr) {
		return foodPtr->getQuantity(); 
	}
	return 0;
}
double GoodsHandler::calculateTotal(double (*calcFunc)(const Goods*)) const {
	double total = 0.0;

	for (int i = 0; i < currentNrOfGoods; i++) {
		if (stock[i] != nullptr) {
			total += calcFunc(stock[i]); // CALL FUNCTION POINTER
		}
	}

	return total;
}
void GoodsHandler::showTotals() const {

	double totalWeight = calculateTotal(sumWeight);
	std::cout << "Total weight: " << totalWeight << std::endl;


	double totalVolume = calculateTotal(sumVolume);
	std::cout << "Total volume: " << totalVolume << std::endl;


	int totalQuantity = 0;
	for (int i = 0; i < currentNrOfGoods; i++) {
		if (stock[i] != nullptr) {
			totalQuantity += sumQuantity(stock[i]);
		}
	}
	std::cout << "Total quantity: " << totalQuantity << std::endl;
}
