#include "MyTrackingAction.h"

MyTrackingAction::MyTrackingAction(MyEventAction *vfEventAction) {
  fEventAction = vfEventAction;
}

MyTrackingAction::~MyTrackingAction() {}

void MyTrackingAction::PreUserTrackingAction(const G4Track *vfTrack) {
  ResetSecondariesNumber();
}

void MyTrackingAction::PostUserTrackingAction(const G4Track *vfTrack) {
  G4RunManager *fRunManager = G4RunManager::GetRunManager();
  G4AnalysisManager *fAnalysisManager = G4AnalysisManager::Instance();
  const G4Track *fTrack = vfTrack;

  G4int aEventID = fRunManager->GetCurrentEvent()->GetEventID();
  G4int aTrackID = fTrack->GetTrackID();
  G4String aParticleName = fTrack->GetParticleDefinition()->GetParticleName();
  G4double aPositionX = fTrack->GetPosition()[0];
  G4double aPositionY = fTrack->GetPosition()[1];
  G4double aPositionZ = fTrack->GetPosition()[2];
  G4double aMomentumX = fTrack->GetMomentum()[0];
  G4double aMomentumY = fTrack->GetMomentum()[1];
  G4double aMomentumZ = fTrack->GetMomentum()[2];
  G4double aBeginKineticEnergy = fTrack->GetVertexKineticEnergy();
  G4double aEndKineticEnergy = fTrack->GetKineticEnergy();

  fAnalysisManager->FillNtupleIColumn(0, 0, aEventID);
  fAnalysisManager->FillNtupleIColumn(0, 1, aTrackID);
  fAnalysisManager->FillNtupleSColumn(0, 2, aParticleName);
  fAnalysisManager->FillNtupleDColumn(0, 3, aPositionX);
  fAnalysisManager->FillNtupleDColumn(0, 4, aPositionY);
  fAnalysisManager->FillNtupleDColumn(0, 5, aPositionZ);
  fAnalysisManager->FillNtupleDColumn(0, 6, aMomentumX);
  fAnalysisManager->FillNtupleDColumn(0, 7, aMomentumY);
  fAnalysisManager->FillNtupleDColumn(0, 8, aMomentumZ);
  fAnalysisManager->FillNtupleDColumn(0, 9, aBeginKineticEnergy);
  fAnalysisManager->FillNtupleDColumn(0, 10, aEndKineticEnergy);
  fAnalysisManager->FillNtupleIColumn(0, 11, aSecondariesNumber);
  fAnalysisManager->AddNtupleRow(0);
}

void MyTrackingAction::ResetSecondariesNumber() { aSecondariesNumber = 0; }

void MyTrackingAction::AddSecondariesNumber(
    G4int vaSecondariesNumberInCurrentStep) {
  aSecondariesNumber += vaSecondariesNumberInCurrentStep;
}
