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
      fStep->GetNumberOfSecondariesInCurrentStep();
  G4String aProcessName =
      fStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName();

  fTrackingAction->AddSecondariesNumber(aSecondariesNumberInCurrentStep);

  G4AnalysisManager *fAnalysisManager = G4AnalysisManager::Instance();
  fAnalysisManager->FillNtupleIColumn(1, 0, aEventID);
  fAnalysisManager->FillNtupleIColumn(1, 1, aTrackID);
  fAnalysisManager->FillNtupleSColumn(1, 2, aParticleName);
  fAnalysisManager->FillNtupleSColumn(1, 3, aProcessName);
  fAnalysisManager->FillNtupleDColumn(1, 4, aPreKineticEnergy);
  fAnalysisManager->FillNtupleDColumn(1, 5, aPostKineticEnergy);
  fAnalysisManager->FillNtupleDColumn(1, 6, aEnergyDeposit);
  fAnalysisManager->FillNtupleIColumn(1, 7, aSecondariesNumberInCurrentStep);
  fAnalysisManager->AddNtupleRow(1);

  if (aParticleName == "e-" && fTrack->GetTrackStatus() == fStopAndKill) {

    G4double aTime = fStep->GetPreStepPoint()->GetGlobalTime();
    G4double aPositionX = fStep->GetPreStepPoint()->GetPosition()[0];
    G4double aPositionY = fStep->GetPreStepPoint()->GetPosition()[1];
    G4double aPositionZ = fStep->GetPreStepPoint()->GetPosition()[2];
    G4double aMomentumX = fStep->GetPreStepPoint()->GetMomentum()[0];
    G4double aMomentumY = fStep->GetPreStepPoint()->GetMomentum()[1];
    G4double aMomentumZ = fStep->GetPreStepPoint()->GetMomentum()[2];

    fAnalysisManager->FillNtupleIColumn(2, 0, aEventID);
    fAnalysisManager->FillNtupleIColumn(2, 1, aTrackID);
    fAnalysisManager->FillNtupleSColumn(2, 2, aProcessName);
    fAnalysisManager->FillNtupleDColumn(2, 3, aTime);
    fAnalysisManager->FillNtupleDColumn(2, 4, aPositionX);
    fAnalysisManager->FillNtupleDColumn(2, 5, aPositionY);
    fAnalysisManager->FillNtupleDColumn(2, 6, aPositionZ);
    fAnalysisManager->FillNtupleDColumn(2, 7, aPreKineticEnergy);
    fAnalysisManager->FillNtupleDColumn(2, 8, aMomentumX);
    fAnalysisManager->FillNtupleDColumn(2, 9, aMomentumY);
    fAnalysisManager->FillNtupleDColumn(2, 10, aMomentumZ);
    fAnalysisManager->AddNtupleRow(2);
  }
}
