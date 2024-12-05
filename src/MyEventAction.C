#include "MyEventAction.h"

MyEventAction::MyEventAction(MyRunAction *vfRunAction) {
  fRunAction = vfRunAction;
}

MyEventAction::~MyEventAction() {}

void MyEventAction::BeginOfEventAction(const G4Event *vfEvent) {
  G4cout << "Processing, EventID = " << vfEvent->GetEventID() << G4endl;
}

void MyEventAction::EndOfEventAction(const G4Event *vfEvent) {}
