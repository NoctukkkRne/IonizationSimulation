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
  G4String aProcessName =
      fStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName();
  G4double aPreTime = fStep->GetPreStepPoint()->GetGlobalTime();
  G4double aPostTime = fStep->GetPostStepPoint()->GetGlobalTime();
  G4double aPreKineticEnergy = fStep->GetPreStepPoint()->GetKineticEnergy();
  G4double aPostKineticEnergy = fStep->GetPostStepPoint()->GetKineticEnergy();
  G4double aPrePositionX = fStep->GetPreStepPoint()->GetPosition()[0];
  G4double aPrePositionY = fStep->GetPreStepPoint()->GetPosition()[1];
  G4double aPrePositionZ = fStep->GetPreStepPoint()->GetPosition()[2];
  G4double aPostPositionX = fStep->GetPostStepPoint()->GetPosition()[0];
  G4double aPostPositionY = fStep->GetPostStepPoint()->GetPosition()[1];
  G4double aPostPositionZ = fStep->GetPostStepPoint()->GetPosition()[2];
  G4double aPreMomentumDirectionX =
      fStep->GetPreStepPoint()->GetMomentumDirection()[0];
  G4double aPreMomentumDirectionY =
      fStep->GetPreStepPoint()->GetMomentumDirection()[1];
  G4double aPreMomentumDirectionZ =
      fStep->GetPreStepPoint()->GetMomentumDirection()[2];
  G4double aPostMomentumDirectionX =
      fStep->GetPostStepPoint()->GetMomentumDirection()[0];
  G4double aPostMomentumDirectionY =
      fStep->GetPostStepPoint()->GetMomentumDirection()[1];
  G4double aPostMomentumDirectionZ =
      fStep->GetPostStepPoint()->GetMomentumDirection()[2];
  G4int aSecondariesNumberInCurrentStep =
      fStep->GetNumberOfSecondariesInCurrentStep();
  G4int aStatus = fTrack->GetTrackStatus();

  fTrackingAction->AddSecondariesNumber(aSecondariesNumberInCurrentStep);

  G4AnalysisManager *fAnalysisManager = G4AnalysisManager::Instance();
  fAnalysisManager->FillNtupleIColumn(1, 0, aEventID);
  fAnalysisManager->FillNtupleIColumn(1, 1, aTrackID);
  fAnalysisManager->FillNtupleSColumn(1, 2, aParticleName);
  fAnalysisManager->FillNtupleSColumn(1, 3, aProcessName);
  fAnalysisManager->FillNtupleDColumn(1, 4, aPreTime);
  fAnalysisManager->FillNtupleDColumn(1, 5, aPostTime);
  fAnalysisManager->FillNtupleDColumn(1, 6, aPreKineticEnergy);
  fAnalysisManager->FillNtupleDColumn(1, 7, aPostKineticEnergy);
  fAnalysisManager->FillNtupleDColumn(1, 8, aPrePositionX);
  fAnalysisManager->FillNtupleDColumn(1, 9, aPrePositionY);
  fAnalysisManager->FillNtupleDColumn(1, 10, aPrePositionZ);
  fAnalysisManager->FillNtupleDColumn(1, 11, aPostPositionX);
  fAnalysisManager->FillNtupleDColumn(1, 12, aPostPositionY);
  fAnalysisManager->FillNtupleDColumn(1, 13, aPostPositionZ);
  fAnalysisManager->FillNtupleDColumn(1, 14, aPreMomentumDirectionX);
  fAnalysisManager->FillNtupleDColumn(1, 15, aPreMomentumDirectionY);
  fAnalysisManager->FillNtupleDColumn(1, 16, aPreMomentumDirectionZ);
  fAnalysisManager->FillNtupleDColumn(1, 17, aPostMomentumDirectionX);
  fAnalysisManager->FillNtupleDColumn(1, 18, aPostMomentumDirectionY);
  fAnalysisManager->FillNtupleDColumn(1, 19, aPostMomentumDirectionZ);
  fAnalysisManager->FillNtupleIColumn(1, 20, aSecondariesNumberInCurrentStep);
  fAnalysisManager->FillNtupleIColumn(1, 21, aStatus);
  fAnalysisManager->AddNtupleRow(1);
}
