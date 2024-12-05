#include "MyDetector.h"

MyDetector_Box::MyDetector_Box(G4String aDetectorName)
    : G4VSensitiveDetector(aDetectorName) {}

MyDetector_Box::~MyDetector_Box() {}

G4bool MyDetector_Box::ProcessHits(G4Step *vfStep,
                                   G4TouchableHistory *vfTouchableHistory) {
  return true;
}
