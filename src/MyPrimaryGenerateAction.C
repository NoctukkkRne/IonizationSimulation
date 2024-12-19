#include "MyPrimaryGeneratorAction.h"

MyPrimaryGeneratorAction::MyPrimaryGeneratorAction(
    G4double vaElectronKineticEnergy) {
  fParticleGun = new G4ParticleGun(1);
  aElectronKineticEnergy = vaElectronKineticEnergy;
}

MyPrimaryGeneratorAction::~MyPrimaryGeneratorAction() { delete fParticleGun; }

void MyPrimaryGeneratorAction::GeneratePrimaries(G4Event *fEvent) {
  G4AnalysisManager *fAnalysisManager = G4AnalysisManager::Instance();

  G4ParticleTable *fParticleTable = G4ParticleTable::GetParticleTable();
  G4String aParticleName = "e-";
  G4ParticleDefinition *fParticle = fParticleTable->FindParticle(aParticleName);

  G4ThreeVector aParticlePosition = {0.0, 0.0, -25.0 * mm};
  G4ThreeVector aParticleMomentumDirection = {0.0, 0.0, 1.0};

  fParticleGun->SetParticleDefinition(fParticle);
  fParticleGun->SetParticlePosition(aParticlePosition);
  fParticleGun->SetParticleMomentumDirection(aParticleMomentumDirection);
  fParticleGun->SetParticleEnergy(aElectronKineticEnergy);

  fParticleGun->GeneratePrimaryVertex(fEvent);
}
