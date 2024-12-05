#include <iostream>

#include "G4RayTracer.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"
#include <G4RunManager.hh>
#include <G4UIExecutive.hh>
#include <G4UImanager.hh>
#include <G4VisExecutive.hh>
#include <G4VisManager.hh>

#include "MyActionInitialization.h"
#include "MyConstruction.h"
#include "MyPhysicsList.h"

void PrintUsage() {
  G4cerr << " Usage: " << G4endl;
  G4cerr << " Simulation [-g gdmlfile] [-e electronenergy/MeV] [-r g4seed] "
            "[-n beamonnumber] [-o outfile]"
         << G4endl;
}

int main(int argc, char **argv) {
  G4cout << "Cout anything here." << G4endl;

  if (argc != 11) {
    PrintUsage();
    return 1;
  }
  G4String gdmlfile = "";
  G4double electronenergy = 0.0;
  G4long g4seed = 1;
  G4int beamonnumber = 0;
  G4String outfile = "./data_out/Output.root";
  for (G4int i = 1; i < argc; i = i + 2) {
    if (G4String(argv[i]) == "-g")
      gdmlfile = argv[i + 1];
    else if (G4String(argv[i]) == "-e")
      electronenergy = std::stod(argv[i + 1]);
    else if (G4String(argv[i]) == "-r")
      g4seed = atoi(argv[i + 1]);
    else if (G4String(argv[i]) == "-n")
      beamonnumber = atoi(argv[i + 1]);
    else if (G4String(argv[i]) == "-o")
      outfile = argv[i + 1];
    else {
      PrintUsage();
      return 1;
    }
  }

  G4Random::setTheSeed(g4seed);

  G4RunManager *RunManager = new G4RunManager();
  RunManager->SetUserInitialization(new MyConstruction(gdmlfile));
  RunManager->SetUserInitialization(new MyPhysicsList());
  RunManager->SetUserInitialization(
      new MyActionInitialization(electronenergy, outfile));
  RunManager->Initialize();

  G4UIExecutive *UIExecutive = new G4UIExecutive(argc, argv);

  G4VisManager *VisManager = new G4VisExecutive(argc, argv);
  VisManager->Initialize();

  G4UImanager *UImanager = G4UImanager::GetUIpointer();
  UImanager->ApplyCommand("/vis/open OGL");
  UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 0.7 0.7 1");
  UImanager->ApplyCommand("/vis/drawVolume");
  UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
  UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
  UImanager->ApplyCommand("/run/numberOfThreads 4");

  std::stringstream ss;
  ss << beamonnumber;
  G4String runbeamcommand = "/run/beamOn " + ss.str();
  UImanager->ApplyCommand(runbeamcommand);

  // UIExecutive->SessionStart();

  delete VisManager;
  delete RunManager;

  return 0;
}
