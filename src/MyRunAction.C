#include "MyRunAction.h"

MyRunAction::MyRunAction(G4String vaOutfile) { aOutfile = vaOutfile; }
MyRunAction::~MyRunAction() {}

void MyRunAction::BeginOfRunAction(const G4Run *vfRun) {
  G4AnalysisManager *fAnalysisManager = G4AnalysisManager::Instance();

  fAnalysisManager->OpenFile(aOutfile);

  fAnalysisManager->CreateNtuple("Track", "Track");
  fAnalysisManager->CreateNtupleIColumn(0, "EventID");
  fAnalysisManager->CreateNtupleIColumn(0, "TrackID");
  fAnalysisManager->CreateNtupleSColumn(0, "ParticleName");
  fAnalysisManager->CreateNtupleDColumn(0, "X");
  fAnalysisManager->CreateNtupleDColumn(0, "Y");
  fAnalysisManager->CreateNtupleDColumn(0, "Z");
  fAnalysisManager->CreateNtupleDColumn(0, "Px");
  fAnalysisManager->CreateNtupleDColumn(0, "Py");
  fAnalysisManager->CreateNtupleDColumn(0, "Pz");
  fAnalysisManager->CreateNtupleDColumn(0, "BeginKineticEnergy");
  fAnalysisManager->CreateNtupleDColumn(0, "EndKineticEnergy");
  fAnalysisManager->CreateNtupleIColumn(0, "SecondariesNumber");
  fAnalysisManager->FinishNtuple(0);

  fAnalysisManager->CreateNtuple("Step", "Step");
  fAnalysisManager->CreateNtupleIColumn(1, "EventID");
  fAnalysisManager->CreateNtupleIColumn(1, "TrackID");
  fAnalysisManager->CreateNtupleSColumn(1, "ParticleName");
  fAnalysisManager->CreateNtupleDColumn(1, "PreKineticEnergy");
  fAnalysisManager->CreateNtupleDColumn(1, "PostKineticEnergy");
  fAnalysisManager->CreateNtupleDColumn(1, "EnergyDeposit");
  fAnalysisManager->CreateNtupleIColumn(1, "SecondariesNumber");
  fAnalysisManager->FinishNtuple(1);

  fAnalysisManager->CreateNtuple("ElectronSample", "ElectronSample");
  fAnalysisManager->CreateNtupleIColumn(2, "EventID");
  fAnalysisManager->CreateNtupleIColumn(2, "TrackID");
  fAnalysisManager->CreateNtupleDColumn(2, "Time");
  fAnalysisManager->CreateNtupleDColumn(2, "PositionX");
  fAnalysisManager->CreateNtupleDColumn(2, "PositionY");
  fAnalysisManager->CreateNtupleDColumn(2, "PositionZ");
  fAnalysisManager->CreateNtupleDColumn(2, "KineticEnergy");
  fAnalysisManager->CreateNtupleDColumn(2, "MomentumX");
  fAnalysisManager->CreateNtupleDColumn(2, "MomentumY");
  fAnalysisManager->CreateNtupleDColumn(2, "MomentumZ");
  fAnalysisManager->FinishNtuple(2);
}

void MyRunAction::EndOfRunAction(const G4Run *vfRun) {
  G4AnalysisManager *fAnalysisManager = G4AnalysisManager::Instance();

  fAnalysisManager->Write();
  fAnalysisManager->CloseFile();
}
