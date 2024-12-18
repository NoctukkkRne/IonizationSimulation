#include <iostream>

#include <G4String.hh>
#include <G4SystemOfUnits.hh>

#include "Rootneed.h"
#include "jinpingStyle.h"

const Int_t NBins = 1000;
const Double_t Emin = 0.0 * eV;
const Double_t Emax = 50.0 * eV;
// const Double_t Emin = 0.0 * keV;
// const Double_t Emax = 10.0 * keV;

int main() {
  jinpingStyle();

  TCanvas *cv = new TCanvas("cv", "", 700, 500);

  TH1D *h1dR2 = new TH1D("h1dR2", "", 100, 0.0, 150e-12);
  h1dR2->GetXaxis()->SetTitle("R^{2} [mm^{2}]");
  h1dR2->GetYaxis()->SetTitle("Counts");
  h1dR2->SetLineColor(kBlue);

  TH1D *h1dKineticEnergy = new TH1D("h1dKineticEnergy", "", NBins, Emin, Emax);
  h1dKineticEnergy->GetXaxis()->SetTitle("KineticEnergy [MeV]");
  h1dKineticEnergy->GetYaxis()->SetTitle("Counts");
  h1dKineticEnergy->SetLineColor(kBlue);

  TChain *tcElectronSample = new TChain("ElectronSample");
  tcElectronSample->Add("./data_out/Output.root");
  // tcElectronSample->Add("./data_out/Output_01.root");
  // tcElectronSample->Add("./data_out/Output_02.root");

  Int_t EventID, TrackID;
  Double_t PositionX, PositionY, PositionZ, MomentumX, MomentumY, MomentumZ,
      KineticEnergy;

  tcElectronSample->SetBranchAddress("EventID", &EventID);
  tcElectronSample->SetBranchAddress("TrackID", &TrackID);
  tcElectronSample->SetBranchAddress("PositionX", &PositionX);
  tcElectronSample->SetBranchAddress("PositionY", &PositionY);
  tcElectronSample->SetBranchAddress("PositionZ", &PositionZ);
  tcElectronSample->SetBranchAddress("MomentumX", &MomentumX);
  tcElectronSample->SetBranchAddress("MomentumY", &MomentumY);
  tcElectronSample->SetBranchAddress("MomentumZ", &MomentumZ);
  tcElectronSample->SetBranchAddress("KineticEnergy", &KineticEnergy);

  for (Long64_t id = 0; id < tcElectronSample->GetEntries(); ++id) {
    tcElectronSample->GetEntry(id);

    h1dR2->Fill(PositionX * PositionX + PositionY * PositionY);
    h1dKineticEnergy->Fill(KineticEnergy);
  }

  h1dR2->Draw("HIST");
  cv->SaveAs("./data_out/figure/h1dR2.png");
  h1dKineticEnergy->Draw("HIST");
  cv->SaveAs("./data_out/figure/h1dKineticEnergy.png");

  ////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////

  return 0;
}
