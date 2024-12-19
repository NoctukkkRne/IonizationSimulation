#include <iostream>

#include <G4String.hh>
#include <G4SystemOfUnits.hh>

#include "Rootneed.h"
#include "jinpingStyle.h"

const Int_t NBins = 1000;
const Double_t Emin = 0.0 * eV;
const Double_t Emax = 20.0 * eV;
// const Double_t Emin = 0.0 * keV;
// const Double_t Emax = 10.0 * keV;

int main() {
  jinpingStyle();

  TCanvas *cv = new TCanvas("cv", "", 700, 500);

  TH2D *h2dPrePostKineticEnergy = new TH2D("h1dPrePostKineticEnergy", "", NBins,
                                           Emin, Emax, NBins, Emin, Emax);
  h2dPrePostKineticEnergy->GetXaxis()->SetTitle("PreKineticEnergy [MeV]");
  h2dPrePostKineticEnergy->GetYaxis()->SetTitle("PostKineticEnergy [MeV]");

  TChain *tcStep = new TChain("Step");
  tcStep->Add("./data_out/Output.root");
  // tcStep->Add("./data_out/Output_01.root");
  // tcStep->Add("./data_out/Output_02.root");

  Int_t EventID, TrackID, SecondariesNumber;
  Char_t ParticleName, ProcessName;
  Double_t PreKineticEnergy, PostKineticEnergy, EnergyDeposit;

  tcStep->SetBranchAddress("EventID", &EventID);
  tcStep->SetBranchAddress("TrackID", &TrackID);
  tcStep->SetBranchAddress("ParticleName", &ParticleName);
  tcStep->SetBranchAddress("ProcessName", &ProcessName);
  tcStep->SetBranchAddress("PreKineticEnergy", &PreKineticEnergy);
  tcStep->SetBranchAddress("PostKineticEnergy", &PostKineticEnergy);
  tcStep->SetBranchAddress("EnergyDeposit", &EnergyDeposit);
  tcStep->SetBranchAddress("SecondariesNumber", &SecondariesNumber);

  for (Long64_t id = 0; id < tcStep->GetEntries(); ++id) {
    tcStep->GetEntry(id);

    h2dPrePostKineticEnergy->Fill(PreKineticEnergy, PostKineticEnergy);
  }

  h2dPrePostKineticEnergy->Draw("colz");
  cv->SetLogz();
  cv->SaveAs("./data_out/figure/h2dStepPrePostKineticEnergy.png");

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
