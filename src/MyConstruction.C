#include "MyConstruction.h"

MyConstruction::MyConstruction(G4String vaGdmlFile) {
  fGdmlPaser = new G4GDMLParser();
  fGdmlPaser->Read(vaGdmlFile, false);
}

MyConstruction::~MyConstruction() { delete fGdmlPaser; }

G4VPhysicalVolume *MyConstruction::Construct() {
  G4VPhysicalVolume *fPhysicalVolume_World = fGdmlPaser->GetWorldVolume();
  fLogicalVolume_Box = fGdmlPaser->GetVolume("LogicalVolume_Box");

  return fPhysicalVolume_World;
}

void MyConstruction::ConstructSDandField() {
  MyDetector_Box *myDetector_Box = new MyDetector_Box("Box");
  G4SDManager *fSDManager = G4SDManager::GetSDMpointer();
  fSDManager->AddNewDetector(myDetector_Box);
  fLogicalVolume_Box->SetSensitiveDetector(myDetector_Box);
}
