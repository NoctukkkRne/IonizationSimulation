#ifndef _MYACTIONINITIALIZATION_H_
#define _MYACTIONINITIALIZATION_H_

#include <G4VUserActionInitialization.hh>

#include "MyEventAction.h"
#include "MyPrimaryGeneratorAction.h"
#include "MyRunAction.h"
#include "MyStackingAction.h"
#include "MySteppingAction.h"

class MyActionInitialization : public G4VUserActionInitialization {
public:
  MyActionInitialization(G4double vaElectronKineticEnergy, G4String vaOutfile);
  ~MyActionInitialization();

  void Build() const override;

private:
  G4String aOutfile;
  G4double aElectronKineticEnergy;
};

#endif
