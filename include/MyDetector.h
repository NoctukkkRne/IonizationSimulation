#ifndef _MYDETECTOR_H_
#define _MYDETECTOR_H_

#include <G4AnalysisManager.hh>
#include <G4RunManager.hh>
#include <G4SystemOfUnits.hh>
#include <G4VSensitiveDetector.hh>

class MyDetector_Box : public G4VSensitiveDetector {
public:
  MyDetector_Box(G4String aDetectorName);
  ~MyDetector_Box();

private:
  G4bool ProcessHits(G4Step *fStep,
                     G4TouchableHistory *fTouchableHistory) override;
};

#endif
