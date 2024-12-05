#ifndef _MYTRACKINGACTION_H_
#define _MYTRACKINGACTION_H_

#include <G4AnalysisManager.hh>
#include <G4UserTrackingAction.hh>

#include "MyEventAction.h"

class MyTrackingAction : public G4UserTrackingAction {
public:
  MyTrackingAction(MyEventAction *vfEventAction);
  ~MyTrackingAction() override;

  void PreUserTrackingAction(const G4Track *vfTrack) override;
  void PostUserTrackingAction(const G4Track *vfTrack) override;

  void ResetSecondariesNumber();
  void AddSecondariesNumber(G4int vaSecondariesNumberInCurrentStep);

private:
  MyEventAction *fEventAction;
  G4int aSecondariesNumber;
};

#endif
