#ifndef _MYEVENTACTION_H_
#define _MYEVENTACTION_H_

#include <G4AnalysisManager.hh>
#include <G4SDManager.hh>
#include <G4UserEventAction.hh>

#include "MyDetector.h"
#include "MyRunAction.h"

class MyEventAction : public G4UserEventAction {
public:
  MyEventAction(MyRunAction *vfRunAction);
  ~MyEventAction() override;

private:
  MyRunAction *fRunAction;

  void BeginOfEventAction(const G4Event *vfEvent) override;
  void EndOfEventAction(const G4Event *vfEvent) override;
};

#endif
