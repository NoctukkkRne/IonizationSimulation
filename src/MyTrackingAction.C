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
  G4double aBeginMomentumDirectionX = fTrack->GetVertexMomentumDirection()[0];
  G4double aBeginMomentumDirectionY = fTrack->GetVertexMomentumDirection()[1];
  G4double aBeginMomentumDirectionZ = fTrack->GetVertexMomentumDirection()[2];
  G4double aEndMomentumDirectionX = fTrack->GetMomentumDirection()[0];
  G4double aEndMomentumDirectionY = fTrack->GetMomentumDirection()[1];
  G4double aEndMomentumDirectionZ = fTrack->GetMomentumDirection()[2];
  G4double aBeginKineticEnergy = fTrack->GetVertexKineticEnergy();
  G4double aEndKineticEnergy = fTrack->GetKineticEnergy();
  G4int aStatus = fTrack->GetTrackStatus();

  fAnalysisManager->FillNtupleIColumn(0, 0, aEventID);
  fAnalysisManager->FillNtupleIColumn(0, 1, aTrackID);
  fAnalysisManager->FillNtupleSColumn(0, 2, aParticleName);
  fAnalysisManager->FillNtupleSColumn(0, 3, aProcessName);
  fAnalysisManager->FillNtupleDColumn(0, 4, aBeginTime);
  fAnalysisManager->FillNtupleDColumn(0, 5, aEndTime);
  fAnalysisManager->FillNtupleDColumn(0, 6, aBeginKineticEnergy);
  fAnalysisManager->FillNtupleDColumn(0, 7, aEndKineticEnergy);
  fAnalysisManager->FillNtupleDColumn(0, 8, aBeginPositionX);
  fAnalysisManager->FillNtupleDColumn(0, 9, aBeginPositionY);
  fAnalysisManager->FillNtupleDColumn(0, 10, aBeginPositionZ);
  fAnalysisManager->FillNtupleDColumn(0, 11, aEndPositionX);
  fAnalysisManager->FillNtupleDColumn(0, 12, aEndPositionY);
  fAnalysisManager->FillNtupleDColumn(0, 13, aEndPositionZ);
  fAnalysisManager->FillNtupleDColumn(0, 14, aBeginMomentumDirectionX);
  fAnalysisManager->FillNtupleDColumn(0, 15, aBeginMomentumDirectionY);
  fAnalysisManager->FillNtupleDColumn(0, 16, aBeginMomentumDirectionZ);
  fAnalysisManager->FillNtupleDColumn(0, 17, aEndMomentumDirectionX);
  fAnalysisManager->FillNtupleDColumn(0, 18, aEndMomentumDirectionY);
  fAnalysisManager->FillNtupleDColumn(0, 19, aEndMomentumDirectionZ);
  fAnalysisManager->FillNtupleIColumn(0, 20, aSecondariesNumber);
  fAnalysisManager->FillNtupleIColumn(0, 21, aStatus);
  fAnalysisManager->AddNtupleRow(0);
}

void MyTrackingAction::ResetSecondariesNumber() { aSecondariesNumber = 0; }

void MyTrackingAction::AddSecondariesNumber(
    G4int vaSecondariesNumberInCurrentStep) {
  aSecondariesNumber += vaSecondariesNumberInCurrentStep;
}
