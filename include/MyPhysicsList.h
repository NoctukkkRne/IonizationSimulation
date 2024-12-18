#ifndef _MYPHYSICSLIST_H_
#define _MYPHYSICSLIST_H_

#include <G4EmDNAPhysics.hh>
#include <G4EmDNAPhysics_option2.hh>
#include <G4EmDNAPhysics_option3.hh>
#include <G4EmDNAPhysics_option4.hh>
#include <G4EmDNAPhysics_option5.hh>
#include <G4EmDNAPhysics_option6.hh>
#include <G4EmParameters.hh>
#include <G4EmStandardPhysics.hh>
#include <G4MollerBhabhaModel.hh>
#include <G4OpticalPhysics.hh>
#include <G4SystemOfUnits.hh>
#include <G4VModularPhysicsList.hh>

#include "Constant.h"

class MyPhysicsList : public G4VModularPhysicsList {
public:
  MyPhysicsList();
  ~MyPhysicsList();

  void SetCuts() override;
};

#endif
