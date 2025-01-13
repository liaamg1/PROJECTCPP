#include "GoodsHandler.h"

GoodsHandler::GoodsHandler(int capacity) : stock(new Goods* [capacity] {nullptr}), currentNrOfGoods(0), 
currentNrOfFood(0), currentNrOfBulk(0), foodStock(new Goods* [capacity] {nullptr}), bulkStock(new Goods* [capacity] {nullptr}), capacity(capacity)
{
}


//----->Destructor<-----

GoodsHandler::~GoodsHandler() {
	
	delete[] foodStock;
	delete[] bulkStock;
	delete[] stock;


	std::cout << "\nstock ptr deleted" << std::endl;
}
bool GoodsHandler::isValidName(const std::string& name) const {

	for (char c : name) {
		if (!isalpha(c) && c != ' ') { 
			return false;
		}
	}
	return true;
}
// -----> Input into Goods constructor from file <-----

void GoodsHandler::readFromFile(const std::string& filename)
{
	int quantity;
	float weight;
	std::string name;
	float volume;
	std::ifstream InStream;

	
	InStream.open(filename);
	if (InStream.is_open()) {
		
		if (filename == "StoredFood.txt") {
			while (InStream >> quantity >> weight >> name) {
				if (currentNrOfFood < this->capacity) {  
					this->foodStock[this->currentNrOfFood] = new Food(quantity, weight, name);
					this->stock[this->currentNrOfGoods] = this->foodStock[this->currentNrOfFood];  
					this->currentNrOfFood++;
					this->currentNrOfGoods++;

					if (this->capacity == currentNrOfGoods)
					{
						this->expandStock();
					}
				}
				else {
					std::cout << "Error: Food stock is full. Cannot add more items." << std::endl;
					break;
				}
			}
		}
		else if (filename == "StoredBulk.txt") {
			while (InStream >> volume >> weight >> name) {
				if (this->currentNrOfBulk < this->capacity) {  
					this->bulkStock[this->currentNrOfBulk] = new Bulk(volume, weight, name);
					this->stock[this->currentNrOfGoods] = this->bulkStock[this->currentNrOfBulk];  
					this->currentNrOfBulk++;
					this->currentNrOfGoods++;

					if (this->capacity == currentNrOfGoods)
					{
						this->expandStock();
					}
				}
				else {
					std::cout << "Error: Bulk stock is full. Cannot add more items." << std::endl;
					break;
				}
			}
		}
	}
	InStream.close();
}
//-----> Expand arrays <-----
void GoodsHandler::expandStock()
{
	this->capacity += 5;
	
	Goods** newStock = new Goods * [this->capacity];
	Goods** newFoodStock = new Goods * [this->capacity];
	Goods** newBulkStock = new Goods * [this->capacity];
	for (int i = 0; i < currentNrOfGoods; ++i) {
		newStock[i] = this->stock[i];

	}
	for (int i = 0; i < currentNrOfBulk; i++)
	{
		newBulkStock[i] = this->bulkStock[i];
	}
	for (int i = 0; i < currentNrOfFood; i++)
	{
		newFoodStock[i] = this->foodStock[i];
	}
	delete[] stock;
	this->stock = newStock;
	delete[] foodStock;
	this->foodStock = newFoodStock;
	delete[] bulkStock;
	this->bulkStock = newBulkStock;
	std::cout << "Expand function called, current capacity = " << this->capacity << std::endl;
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
			Food* fPtr = dynamic_cast<Food*>(this->stock[i]);
			if (fPtr != nullptr)
			{
				OutStreamFood << std::to_string(fPtr->getQuantity()) + "\n";
				OutStreamFood << std::to_string(fPtr->getWeight()) + "\n";
				OutStreamFood << fPtr->getName() + "\n";
			}
			else {
				Bulk* bPtr = dynamic_cast<Bulk*>(this->stock[i]);
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

//----->Removes Current Contents In File<-----

void GoodsHandler::cleanseFileFromCurrentContents(const std::string& filename)
{
	std::ofstream cleanseFile;
	cleanseFile.open(filename, std::ofstream::out | std::ofstream::trunc);
	cleanseFile.close();
}

int GoodsHandler::getCurrentNrOfGoods()
{
	return this->currentNrOfGoods;
}

Goods* GoodsHandler::getCurrentIndex(int index)
{
	Goods* ptr = nullptr;
	if (index< this->currentNrOfGoods)
	{
		ptr = stock[index];
	}
	return ptr;
}

//----->ADD_GOODS<-----

bool GoodsHandler::addGoods(Goods* aGoods)
{
	if (capacity==currentNrOfGoods)
	{
		this->expandStock();
	}
	
	if (aGoods != nullptr && !isValidName(aGoods->getName())) {
		std::cout << "Invalid name for item. Cannot add to stock." << std::endl;
		return false;
	}

	if (this->currentNrOfGoods < capacity) {
		stock[this->currentNrOfGoods] = aGoods;
		this->currentNrOfGoods++;

		Food* foodPtr = dynamic_cast<Food*>(aGoods);
		if (foodPtr != nullptr) {
			if (this->currentNrOfFood < capacity) {
				this->foodStock[this->currentNrOfFood] = aGoods;
				this->currentNrOfFood++;
			}
		}
		else {
			Bulk* bulkPtr = dynamic_cast<Bulk*>(aGoods);
			if (bulkPtr != nullptr) {
				if (this->currentNrOfBulk < capacity) {
					this->bulkStock[this->currentNrOfBulk] = aGoods;
					this->currentNrOfBulk++;
				}
			}
		}
		return true;
	}
	return false;
}

//----->SHOW_GOODS<-----

void GoodsHandler::showAll(int sortChoice)
{
	Sorter<Goods> sorter;

	
	for (std::size_t i = 0; i < currentNrOfGoods; ++i) {
		sorter.addItem(stock[i]);
	}

	
	if (sortChoice == 1) {
		sorter.sortItems([](const Goods* a, const Goods* b) {
			return a->getWeight() > b->getWeight();  
			});
	}
	else if (sortChoice == 2) {
		sorter.sortItems([](const Goods* a, const Goods* b) {
			return a->getName() < b->getName();  
			});
	}
	else {
		std::cout << "Invalid choice. Defaulting to sorting by Weight.\n";
		sorter.sortItems([](const Goods* a, const Goods* b) {
			return a->getWeight() > b->getWeight(); 
			});
	}

	
	sorter.showItems();
}


void GoodsHandler::showFood() const
{
	std::cout << "\nShowing food items:\n";
	for (int i = 0; i < this->currentNrOfFood; i++) {
		if (this->foodStock[i] != nullptr) {
			std::cout << this->foodStock[i]->toString() << std::endl;
		}
	}
}

void GoodsHandler::showBulk() const
{
	std::cout << "\nShowing bulk items:\n";
	for (int i = 0; i < this->currentNrOfBulk; i++) {
		if (this->bulkStock[i] != nullptr) {
			std::cout << this->bulkStock[i]->toString() << std::endl;
		}
	}
}

// FUNCTION POINTER
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
		if (this->stock[i] != nullptr) {
			total += calcFunc(this->stock[i]); // CALL FUNCTION POINTER
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
	for (int i = 0; i < this->currentNrOfGoods; i++) {
		if (stock[i] != nullptr) {
			totalQuantity += sumQuantity(this->stock[i]);
		}
	}
	std::cout << "Total quantity: " << totalQuantity << std::endl;
}
