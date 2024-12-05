#ifndef _MYPRIMARYGENERATORACTION_H_
#define _MYPRIMARYGENERATORACTION_H_

#include <G4AnalysisManager.hh>
#include <G4ParticleGun.hh>
#include <G4ParticleTable.hh>
#include <G4PhysicalConstants.hh>
#include <G4RunManager.hh>
#include <G4SystemOfUnits.hh>
#include <G4VUserPrimaryGeneratorAction.hh>

#include "Rootneed.h"

class MyPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:
  MyPrimaryGeneratorAction(G4double vaElectronKineticEnergy);
  ~MyPrimaryGeneratorAction();

  void GeneratePrimaries(G4Event *fEvent) override;

private:
  G4ParticleGun *fParticleGun;
  G4double aElectronKineticEnergy;
};
#endif
