#ifndef _MYSTEPPINGACTION_H_
#define _MYSTEPPINGACTION_H_

#include <G4OpticalPhoton.hh>
#include <G4SystemOfUnits.hh>
#include <G4Track.hh>
#include <G4UserSteppingAction.hh>

#include "Constant.h"
#include "MyTrackingAction.h"

class MySteppingAction : public G4UserSteppingAction {
public:
  MySteppingAction(MyTrackingAction *vfTrackingAction);
  ~MySteppingAction() override;

private:
  MyTrackingAction *fTrackingAction;

  void UserSteppingAction(const G4Step *vfStep) override;
};

#endif
