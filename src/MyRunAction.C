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
  fAnalysisManager->CreateNtupleDColumn(0, "BeginKineticEnergy");
  fAnalysisManager->CreateNtupleDColumn(0, "EndKineticEnergy");
  fAnalysisManager->CreateNtupleDColumn(0, "BeginPositionX");
  fAnalysisManager->CreateNtupleDColumn(0, "BeginPositionY");
  fAnalysisManager->CreateNtupleDColumn(0, "BeginPositionZ");
  fAnalysisManager->CreateNtupleDColumn(0, "EndPositionX");
  fAnalysisManager->CreateNtupleDColumn(0, "EndPositionY");
  fAnalysisManager->CreateNtupleDColumn(0, "EndPositionZ");
  fAnalysisManager->CreateNtupleDColumn(0, "BeginMomentumDirectionX");
  fAnalysisManager->CreateNtupleDColumn(0, "BeginMomentumDirectionY");
  fAnalysisManager->CreateNtupleDColumn(0, "BeginMomentumDirectionZ");
  fAnalysisManager->CreateNtupleDColumn(0, "EndMomentumDirectionX");
  fAnalysisManager->CreateNtupleDColumn(0, "EndMomentumDirectionY");
  fAnalysisManager->CreateNtupleDColumn(0, "EndMomentumDirectionZ");
  fAnalysisManager->CreateNtupleIColumn(0, "SecondariesNumber");
  fAnalysisManager->CreateNtupleIColumn(0, "Status");
  fAnalysisManager->FinishNtuple(0);

  fAnalysisManager->CreateNtuple("Step", "Step");
  fAnalysisManager->CreateNtupleIColumn(1, "EventID");
  fAnalysisManager->CreateNtupleIColumn(1, "TrackID");
  fAnalysisManager->CreateNtupleSColumn(1, "ParticleName");
  fAnalysisManager->CreateNtupleSColumn(1, "ProcessName");
  fAnalysisManager->CreateNtupleDColumn(1, "PreTime");
  fAnalysisManager->CreateNtupleDColumn(1, "PostTime");
  fAnalysisManager->CreateNtupleDColumn(1, "PreKineticEnergy");
  fAnalysisManager->CreateNtupleDColumn(1, "PostKineticEnergy");
  fAnalysisManager->CreateNtupleDColumn(1, "PrePositionX");
  fAnalysisManager->CreateNtupleDColumn(1, "PrePositionY");
  fAnalysisManager->CreateNtupleDColumn(1, "PrePositionZ");
  fAnalysisManager->CreateNtupleDColumn(1, "PostPositionX");
  fAnalysisManager->CreateNtupleDColumn(1, "PostPositionY");
  fAnalysisManager->CreateNtupleDColumn(1, "PostPositionZ");
  fAnalysisManager->CreateNtupleDColumn(1, "PreMomentumDirectionX");
  fAnalysisManager->CreateNtupleDColumn(1, "PreMomentumDirectionY");
  fAnalysisManager->CreateNtupleDColumn(1, "PreMomentumDirectionZ");
  fAnalysisManager->CreateNtupleDColumn(1, "PostMomentumDirectionX");
  fAnalysisManager->CreateNtupleDColumn(1, "PostMomentumDirectionY");
  fAnalysisManager->CreateNtupleDColumn(1, "PostMomentumDirectionZ");
  fAnalysisManager->CreateNtupleIColumn(1, "SecondariesNumber");
  fAnalysisManager->CreateNtupleIColumn(1, "Status");
  fAnalysisManager->FinishNtuple(1);
}

void MyRunAction::EndOfRunAction(const G4Run *vfRun) {
  G4AnalysisManager *fAnalysisManager = G4AnalysisManager::Instance();

  fAnalysisManager->Write();
  fAnalysisManager->CloseFile();
}
