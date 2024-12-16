#include "Bulk.h"

Bulk::Bulk()
{
    // Initiala värden, dessa kan senare ändras i main-filen genom setter-metoder
    setWeight(0.0f);  // Sätter standardvikt till 0.0
    setQuantity(0);   // Sätter standardkvantitet till 0
    setName("");      // Sätter standardnamn till en tom sträng
    setType("");      // Sätter standardtyp till en tom sträng
}

void Bulk::displayInfo() const
{
   
    
// Använd getter-metoder från Goods
std::cout << "Bulk Name: " << getName() << std::endl;
std::cout << "Bulk Weight: " << getWeight() << " kg" << std::endl;
std::cout << "Bulk Quantity: " << getQuantity() << std::endl;
std::cout << "Bulk Type: " << getType() << std::endl;
}
