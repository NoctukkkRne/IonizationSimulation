#ifndef _MYCONSTRUCTION_H_
#define _MYCONSTRUCTION_H_

#include <vector>

#include <G4Box.hh>
#include <G4GDMLParser.hh>
#include <G4LogicalBorderSurface.hh>
#include <G4LogicalSkinSurface.hh>
#include <G4LogicalVolume.hh>
#include <G4Material.hh>
#include <G4MaterialTable.hh>
#include <G4NistManager.hh>
#include <G4OpticalSurface.hh>
#include <G4PVPlacement.hh>
#include <G4PhysicalConstants.hh>
#include <G4SDManager.hh>
#include <G4SubtractionSolid.hh>
#include <G4SystemOfUnits.hh>
#include <G4Tubs.hh>
#include <G4VUserDetectorConstruction.hh>

#include "MyDetector.h"

class MyConstruction : public G4VUserDetectorConstruction {
public:
  MyConstruction(G4String vaGdmlFile);
  ~MyConstruction();

  G4VPhysicalVolume *Construct() override;

private:
  G4GDMLParser *fGdmlPaser;
  G4LogicalVolume *fLogicalVolume_Box;

  void ConstructSDandField() override;
};

#endif
