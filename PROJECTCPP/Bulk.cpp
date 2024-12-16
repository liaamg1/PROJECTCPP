#include "Bulk.h"

Bulk::Bulk()
{
    // Initiala v�rden, dessa kan senare �ndras i main-filen genom setter-metoder
    setWeight(0.0f);  // S�tter standardvikt till 0.0
    setQuantity(0);   // S�tter standardkvantitet till 0
    setName("");      // S�tter standardnamn till en tom str�ng
    setType("");      // S�tter standardtyp till en tom str�ng
}

void Bulk::displayInfo() const
{
   
    
// Anv�nd getter-metoder fr�n Goods
std::cout << "Bulk Name: " << getName() << std::endl;
std::cout << "Bulk Weight: " << getWeight() << " kg" << std::endl;
std::cout << "Bulk Quantity: " << getQuantity() << std::endl;
std::cout << "Bulk Type: " << getType() << std::endl;
}
