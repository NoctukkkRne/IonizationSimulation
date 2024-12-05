#ifndef _MYRUNACTION_H_
#define _MYRUNACTION_H_

#include <G4AnalysisManager.hh>
#include <G4UserRunAction.hh>

class MyRunAction : public G4UserRunAction {
public:
  MyRunAction(G4String vaOutfile);
  ~MyRunAction() override;

  void BeginOfRunAction(const G4Run *vfRun) override;
  void EndOfRunAction(const G4Run *vfRun) override;

private:
  G4String aOutfile;
};

#endif
