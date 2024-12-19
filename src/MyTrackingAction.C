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

  G4String aProcessName = "Source";
  if (aTrackID != 1) {
    aProcessName = fTrack->GetCreatorProcess()->GetProcessName();
  }

  G4double aBeginTime = fTrack->GetProperTime();
  G4double aEndTime = fTrack->GetGlobalTime();
  G4double aBeginPositionX = fTrack->GetVertexPosition()[0];
  G4double aBeginPositionY = fTrack->GetVertexPosition()[1];
  G4double aBeginPositionZ = fTrack->GetVertexPosition()[2];
  G4double aEndPositionX = fTrack->GetPosition()[0];
  G4double aEndPositionY = fTrack->GetPosition()[1];
  G4double aEndPositionZ = fTrack->GetPosition()[2];
  G4double aBeginKineticEnergy = fTrack->GetVertexKineticEnergy();
  G4double aEndKineticEnergy = fTrack->GetKineticEnergy();

  fAnalysisManager->FillNtupleIColumn(0, 0, aEventID);
  fAnalysisManager->FillNtupleIColumn(0, 1, aTrackID);
  fAnalysisManager->FillNtupleSColumn(0, 2, aParticleName);
  fAnalysisManager->FillNtupleSColumn(0, 3, aProcessName);
  fAnalysisManager->FillNtupleDColumn(0, 4, aBeginTime);
  fAnalysisManager->FillNtupleDColumn(0, 5, aEndTime);
  fAnalysisManager->FillNtupleDColumn(0, 6, aBeginPositionX);
  fAnalysisManager->FillNtupleDColumn(0, 7, aBeginPositionY);
  fAnalysisManager->FillNtupleDColumn(0, 8, aBeginPositionZ);
  fAnalysisManager->FillNtupleDColumn(0, 9, aEndPositionX);
  fAnalysisManager->FillNtupleDColumn(0, 10, aEndPositionY);
  fAnalysisManager->FillNtupleDColumn(0, 11, aEndPositionZ);
  fAnalysisManager->FillNtupleDColumn(0, 12, aBeginKineticEnergy);
  fAnalysisManager->FillNtupleDColumn(0, 13, aEndKineticEnergy);
  fAnalysisManager->FillNtupleIColumn(0, 14, aSecondariesNumber);
  fAnalysisManager->AddNtupleRow(0);
}

void MyTrackingAction::ResetSecondariesNumber() { aSecondariesNumber = 0; }

void MyTrackingAction::AddSecondariesNumber(
    G4int vaSecondariesNumberInCurrentStep) {
  aSecondariesNumber += vaSecondariesNumberInCurrentStep;
}
