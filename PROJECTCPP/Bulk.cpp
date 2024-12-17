//#include "Bulk.h"
//
//Bulk::Bulk() :volume(0)
//{
//    // Initiala värden, dessa kan senare ändras i main-filen genom setter-metoder
//    setWeight(0.0f);  // Sätter standardvikt till 0.0
//    setName("");      // Sätter standardnamn till en tom sträng
//    setType("");      // Sätter standardtyp till en tom sträng
//}
//
//Bulk::~Bulk()
//{
//}
//
//void Bulk::displayInfo() const
//{
//// Använd getter-metoder från Goods
//std::cout << "Bulk Volume: " << getVolume() << " m3" << std::endl;
//std::cout << "Bulk Weight: " << getWeight() << " kg" << std::endl;
//std::cout << "Bulk Type: " << getType() << std::endl;
//std::cout << "Bulk Name: " << getName() << std::endl;
//}
//
//void Bulk::setVolume(float volume) 
//{
//    this->volume = volume;
//}
//
//float Bulk::getVolume() const
//{
//    return this->volume;
//}
////BERÄKNA VOLUME OM BARA WEIGHT ÄR GIVET