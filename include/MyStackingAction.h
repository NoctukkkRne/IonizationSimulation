#ifndef _MYSTACKINGACTION_H_
#define _MYSTACKINGACTION_H_

#include <G4OpticalPhoton.hh>
#include <G4Track.hh>
#include <G4UserStackingAction.hh>
#include <G4VProcess.hh>

class MyStackingAction : public G4UserStackingAction {
public:
  MyStackingAction();
  ~MyStackingAction() override;

  G4ClassificationOfNewTrack ClassifyNewTrack(const G4Track *vfTrack) override;
  void NewStage() override;
  void PrepareNewEvent() override;
};

#endif
