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
  fAnalysisManager->CreateNtupleSColumn(0, "ProcessName");
  fAnalysisManager->CreateNtupleDColumn(0, "BeginTime");
  fAnalysisManager->CreateNtupleDColumn(0, "EndTime");
  fAnalysisManager->CreateNtupleDColumn(0, "BeginPositionX");
  fAnalysisManager->CreateNtupleDColumn(0, "BeginPositionY");
  fAnalysisManager->CreateNtupleDColumn(0, "BeginPositionZ");
  fAnalysisManager->CreateNtupleDColumn(0, "EndPositionX");
  fAnalysisManager->CreateNtupleDColumn(0, "EndPositionY");
  fAnalysisManager->CreateNtupleDColumn(0, "EndPositionZ");
  fAnalysisManager->CreateNtupleDColumn(0, "BeginKineticEnergy");
  fAnalysisManager->CreateNtupleDColumn(0, "EndKineticEnergy");
  fAnalysisManager->CreateNtupleIColumn(0, "SecondariesNumber");
  fAnalysisManager->FinishNtuple(0);

  fAnalysisManager->CreateNtuple("Step", "Step");
  fAnalysisManager->CreateNtupleIColumn(1, "EventID");
  fAnalysisManager->CreateNtupleIColumn(1, "TrackID");
  fAnalysisManager->CreateNtupleSColumn(1, "ParticleName");
  fAnalysisManager->CreateNtupleSColumn(1, "ProcessName");
  fAnalysisManager->CreateNtupleDColumn(1, "PreKineticEnergy");
  fAnalysisManager->CreateNtupleDColumn(1, "PostKineticEnergy");
  fAnalysisManager->CreateNtupleDColumn(1, "EnergyDeposit");
  fAnalysisManager->CreateNtupleIColumn(1, "SecondariesNumber");
  fAnalysisManager->FinishNtuple(1);

  fAnalysisManager->CreateNtuple("ElectronSample", "ElectronSample");
  fAnalysisManager->CreateNtupleIColumn(2, "EventID");
  fAnalysisManager->CreateNtupleIColumn(2, "TrackID");
  fAnalysisManager->CreateNtupleSColumn(2, "ProcessName");
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
