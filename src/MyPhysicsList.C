#include "MyPhysicsList.h"

MyPhysicsList::MyPhysicsList() {
  // RegisterPhysics(new G4EmStandardPhysics());
  RegisterPhysics(new G4EmDNAPhysics());
  //  RegisterPhysics(new G4OpticalPhysics());
}

MyPhysicsList::~MyPhysicsList() {}

void MyPhysicsList::SetCuts() {
  //  G4EmParameters *fEmParameters = G4EmParameters::Instance();
  //  fEmParameters->SetLowestElectronEnergy(aElectronLowsetKineticEnergy);
  //
  //  G4ProductionCutsTable::GetProductionCutsTable()->SetEnergyRange(7.4 * eV,
  //                                                                  10.0 *
  //                                                                  MeV);
  //  SetCutValue(aGammaProductionRangeCut, "gamma");
  //  SetCutValue(aElectronProductionRangeCut, "e-");
}
