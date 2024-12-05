#include "MyStackingAction.h"

MyStackingAction::MyStackingAction() {}

MyStackingAction::~MyStackingAction() {}

G4ClassificationOfNewTrack
MyStackingAction::ClassifyNewTrack(const G4Track *vfTrack) {

  return fUrgent;
}

void MyStackingAction::NewStage() {}

void MyStackingAction::PrepareNewEvent() {}
