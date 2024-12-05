#include "MySteppingAction.h"

MySteppingAction::MySteppingAction(MyTrackingAction *vfTrackingAction) {
  fTrackingAction = vfTrackingAction;
}

MySteppingAction::~MySteppingAction() {}

void MySteppingAction::UserSteppingAction(const G4Step *vfStep) {
  const G4RunManager *fRunManager = G4RunManager::GetRunManager();

  const G4Step *fStep = vfStep;
  const G4Track *fTrack = fStep->GetTrack();
  const G4Event *fEvent = fRunManager->GetCurrentEvent();

  G4int aEventID = fEvent->GetEventID();
  G4int aTrackID = fTrack->GetTrackID();
  G4String aParticleName = fTrack->GetParticleDefinition()->GetParticleName();
  G4double aPreKineticEnergy = fStep->GetPreStepPoint()->GetKineticEnergy();
  G4double aPostKineticEnergy = fStep->GetPostStepPoint()->GetKineticEnergy();
  G4double aEnergyDeposit = fStep->GetTotalEnergyDeposit();
  G4int aSecondariesNumberInCurrentStep =
      vfStep->GetNumberOfSecondariesInCurrentStep();

  fTrackingAction->AddSecondariesNumber(aSecondariesNumberInCurrentStep);

  G4AnalysisManager *fAnalysisManager = G4AnalysisManager::Instance();
  fAnalysisManager->FillNtupleIColumn(1, 0, aEventID);
  fAnalysisManager->FillNtupleIColumn(1, 1, aTrackID);
  fAnalysisManager->FillNtupleSColumn(1, 2, aParticleName);
  fAnalysisManager->FillNtupleDColumn(1, 3, aPreKineticEnergy);
  fAnalysisManager->FillNtupleDColumn(1, 4, aPostKineticEnergy);
  fAnalysisManager->FillNtupleDColumn(1, 5, aEnergyDeposit);
  fAnalysisManager->FillNtupleIColumn(1, 6, aSecondariesNumberInCurrentStep);
  fAnalysisManager->AddNtupleRow(1);

  if (aParticleName == "e-" &&
      aPreKineticEnergy < aElectronLowsetKineticEnergy) {

    G4double aTime = fStep->GetPreStepPoint()->GetGlobalTime();
    G4double aPositionX = fStep->GetPreStepPoint()->GetPosition()[0];
    G4double aPositionY = fStep->GetPreStepPoint()->GetPosition()[1];
    G4double aPositionZ = fStep->GetPreStepPoint()->GetPosition()[2];
    G4double aMomentumX = fStep->GetPreStepPoint()->GetMomentum()[0];
    G4double aMomentumY = fStep->GetPreStepPoint()->GetMomentum()[1];
    G4double aMomentumZ = fStep->GetPreStepPoint()->GetMomentum()[2];

    fAnalysisManager->FillNtupleIColumn(2, 0, aEventID);
    fAnalysisManager->FillNtupleIColumn(2, 1, aTrackID);
    fAnalysisManager->FillNtupleDColumn(2, 2, aTime / ns);
    fAnalysisManager->FillNtupleDColumn(2, 3, aPositionX / mm);
    fAnalysisManager->FillNtupleDColumn(2, 4, aPositionY / mm);
    fAnalysisManager->FillNtupleDColumn(2, 5, aPositionZ / mm);
    fAnalysisManager->FillNtupleDColumn(2, 6, aPreKineticEnergy / eV);
    fAnalysisManager->FillNtupleDColumn(2, 7, aMomentumX / eV);
    fAnalysisManager->FillNtupleDColumn(2, 8, aMomentumY / eV);
    fAnalysisManager->FillNtupleDColumn(2, 9, aMomentumZ / eV);
    fAnalysisManager->AddNtupleRow(2);
  }
}
