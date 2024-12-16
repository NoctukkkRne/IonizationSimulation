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
  G4int aParticleID = fTrack->GetTrackID();
  G4String aParticleName = fTrack->GetParticleDefinition()->GetParticleName();
  G4double aX = fTrack->GetPosition()[0];
  G4double aY = fTrack->GetPosition()[1];
  G4double aZ = fTrack->GetPosition()[2];
  G4double aPx = fTrack->GetMomentum()[0];
  G4double aPy = fTrack->GetMomentum()[1];
  G4double aPz = fTrack->GetMomentum()[2];
  G4double aBeginKineticEnergy = fTrack->GetVertexKineticEnergy();
  G4double aEndKineticEnergy = fTrack->GetKineticEnergy();

  fAnalysisManager->FillNtupleIColumn(0, 0, aEventID);
  fAnalysisManager->FillNtupleIColumn(0, 1, aParticleID);
  fAnalysisManager->FillNtupleSColumn(0, 2, aParticleName);
  fAnalysisManager->FillNtupleDColumn(0, 3, aX / mm);
  fAnalysisManager->FillNtupleDColumn(0, 4, aY / mm);
  fAnalysisManager->FillNtupleDColumn(0, 5, aZ / mm);
  fAnalysisManager->FillNtupleDColumn(0, 6, aPx / MeV);
  fAnalysisManager->FillNtupleDColumn(0, 7, aPy / MeV);
  fAnalysisManager->FillNtupleDColumn(0, 8, aPz / MeV);
  fAnalysisManager->FillNtupleDColumn(0, 9, aBeginKineticEnergy / MeV);
  fAnalysisManager->FillNtupleDColumn(0, 10, aEndKineticEnergy / MeV);
  fAnalysisManager->FillNtupleIColumn(0, 11, aSecondariesNumber / MeV);
  fAnalysisManager->AddNtupleRow(0);
}

void MyTrackingAction::ResetSecondariesNumber() { aSecondariesNumber = 0; }

void MyTrackingAction::AddSecondariesNumber(
    G4int vaSecondariesNumberInCurrentStep) {
  aSecondariesNumber += vaSecondariesNumberInCurrentStep;
}
