#include "MyActionInitialization.h"

MyActionInitialization::MyActionInitialization(G4double vaElectronKineticEnergy,
                                               G4String vaOutfile) {
  aOutfile = vaOutfile;
  aElectronKineticEnergy = vaElectronKineticEnergy;
}
MyActionInitialization::~MyActionInitialization() {}

void MyActionInitialization::Build() const {
  MyPrimaryGeneratorAction *myPrimaryGeneratorAction =
      new MyPrimaryGeneratorAction(aElectronKineticEnergy);
  SetUserAction(myPrimaryGeneratorAction);

  MyRunAction *myRunAction = new MyRunAction(aOutfile);
  SetUserAction(myRunAction);

  MyEventAction *myEventAction = new MyEventAction(myRunAction);
  SetUserAction(myEventAction);

  MyTrackingAction *myTrackingAction = new MyTrackingAction(myEventAction);
  SetUserAction(myTrackingAction);

  MySteppingAction *mySteppingAction = new MySteppingAction(myTrackingAction);
  SetUserAction(mySteppingAction);

  MyStackingAction *myStackingAction = new MyStackingAction();
  SetUserAction(myStackingAction);
}
