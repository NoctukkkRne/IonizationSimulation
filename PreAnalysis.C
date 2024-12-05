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

  TH1D *h1dR2 = new TH1D("h1dR2", "", 100, 0.0, 150.0);
  h1dR2->GetXaxis()->SetTitle("R^{2} [mm^{2}]");
  h1dR2->GetYaxis()->SetTitle("Counts");
  h1dR2->SetLineColor(kBlue);

  TH1D *h1dBeginKineticEnergy =
      new TH1D("h1dBeginKineticEnergy", "", NBins, Emin, Emax);
  h1dBeginKineticEnergy->GetXaxis()->SetTitle("Energy [MeV]");
  h1dBeginKineticEnergy->GetYaxis()->SetTitle("Counts");
  h1dBeginKineticEnergy->SetLineColor(kBlue);

  TH1D *h1dSecondariesNumber =
      new TH1D("h1dSecondariesNumber", "", NBins, Emin, Emax);
  h1dSecondariesNumber->GetXaxis()->SetTitle("Energy [MeV]");
  h1dSecondariesNumber->GetYaxis()->SetTitle("Average SecondariesNumber");
  h1dSecondariesNumber->SetLineColor(kBlue);

  TChain *tcTrack = new TChain("Track");
  tcTrack->Add("./data_out/Output.root");
  // tcTrack->Add("./data_out/Output_01.root");
  // tcTrack->Add("./data_out/Output_02.root");

  TChain *tcStep = new TChain("Step");

  Int_t EventID, TrackID, SecondariesNumber;
  Char_t ParticleName;
  Double_t X, Y, Z, Px, Py, Pz, BeginKineticEnergy, EndKineticEnergy,
      KineticEnergy;
  Double_t AverSecondariesNumber;

  tcTrack->SetBranchAddress("EventID", &EventID);
  tcTrack->SetBranchAddress("TrackID", &TrackID);
  tcTrack->SetBranchAddress("ParticleName", &ParticleName);
  tcTrack->SetBranchAddress("X", &X);
  tcTrack->SetBranchAddress("Y", &Y);
  tcTrack->SetBranchAddress("Z", &Z);
  tcTrack->SetBranchAddress("Px", &Px);
  tcTrack->SetBranchAddress("Py", &Py);
  tcTrack->SetBranchAddress("Pz", &Pz);
  tcTrack->SetBranchAddress("BeginKineticEnergy", &BeginKineticEnergy);
  tcTrack->SetBranchAddress("EndKineticEnergy", &EndKineticEnergy);
  tcTrack->SetBranchAddress("SecondariesNumber", &SecondariesNumber);

  tcTrack->GetEntry(0);
  Char_t ElectronName = ParticleName;

  for (Long64_t id = 0; id < tcTrack->GetEntries(); ++id) {
    tcTrack->GetEntry(id);

    if (ParticleName == ElectronName && TrackID != 1) {
      h1dR2->Fill(X * X + Y * Y);
      h1dBeginKineticEnergy->Fill(BeginKineticEnergy);
      h1dSecondariesNumber->Fill(BeginKineticEnergy, SecondariesNumber);
    }
  }
  for (int BinX = 0; BinX < NBins; ++BinX) {
    if (h1dSecondariesNumber->GetBinContent(BinX + 1) > 0.5) {
      AverSecondariesNumber = h1dSecondariesNumber->GetBinContent(BinX + 1) /
                              h1dBeginKineticEnergy->GetBinContent(BinX + 1);
      h1dSecondariesNumber->SetBinContent(BinX + 1, AverSecondariesNumber);
    }
  }

  h1dR2->Draw("HIST");
  cv->SaveAs("./data_out/figure/h1dR2.png");
  h1dBeginKineticEnergy->Draw("HIST");
  cv->SaveAs("./data_out/figure/h1dBeginKineticEnergy.png");
  h1dSecondariesNumber->Draw("HIST");
  cv->SaveAs("./data_out/figure/h1dSecondariesNumber.png");

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
