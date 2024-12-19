#include <iostream>

#include <G4String.hh>
#include <G4SystemOfUnits.hh>

#include "Rootneed.h"
#include "jinpingStyle.h"

int main() {
  jinpingStyle();

  TCanvas *cv = new TCanvas("cv", "", 700, 500);

  TH2D *h2dSampleXY =
      new TH2D("h2dSampleXY", "", 1000, -100.0e-6 * mm, 100.0e-6 * mm, 1000,
               -100.0e-6 * mm, 100.0e-6 * mm);
  h2dSampleXY->GetXaxis()->SetTitle("X [mm]");
  h2dSampleXY->GetYaxis()->SetTitle("Y [mm]");

  TH1D *h1dSampleR = new TH1D("h1dSampleR", "", 1000, 0.0, 100.0e-6 * mm);
  h1dSampleR->GetXaxis()->SetTitle("R [mm]");
  h1dSampleR->GetYaxis()->SetTitle("Counts");
  h1dSampleR->SetLineColor(kBlue);

  TH1D *h1dSampleTime = new TH1D("h1dSampleTime", "", 1000, 0.0, 0.1e-3 * ns);
  h1dSampleTime->GetXaxis()->SetTitle("Time [ns]");
  h1dSampleTime->GetYaxis()->SetTitle("Counts");
  h1dSampleTime->SetLineColor(kBlue);

  TH1D *h1dSampleKineticEnergy =
      new TH1D("h1dSampleKineticEnergy", "", 1000, 0.0 * eV, 20.0 * eV);
  h1dSampleKineticEnergy->GetXaxis()->SetTitle("KineticEnergy [MeV]");
  h1dSampleKineticEnergy->GetYaxis()->SetTitle("Counts");
  h1dSampleKineticEnergy->SetLineColor(kBlue);

  TChain *tcElectronSample = new TChain("ElectronSample");
  tcElectronSample->Add("./data_out/Output.root");
  // tcElectronSample->Add("./data_out/Output_01.root");
  // tcElectronSample->Add("./data_out/Output_02.root");

  Int_t EventID, TrackID;
  Double_t PositionX, PositionY, PositionZ, MomentumX, MomentumY, MomentumZ,
      KineticEnergy, Time;
  Char_t ProcessName;

  tcElectronSample->SetBranchAddress("EventID", &EventID);
  tcElectronSample->SetBranchAddress("TrackID", &TrackID);
  tcElectronSample->SetBranchAddress("ProcessName", &ProcessName);
  tcElectronSample->SetBranchAddress("Time", &Time);
  tcElectronSample->SetBranchAddress("PositionX", &PositionX);
  tcElectronSample->SetBranchAddress("PositionY", &PositionY);
  tcElectronSample->SetBranchAddress("PositionZ", &PositionZ);
  tcElectronSample->SetBranchAddress("KineticEnergy", &KineticEnergy);
  tcElectronSample->SetBranchAddress("MomentumX", &MomentumX);
  tcElectronSample->SetBranchAddress("MomentumY", &MomentumY);
  tcElectronSample->SetBranchAddress("MomentumZ", &MomentumZ);

  for (Long64_t id = 0; id < tcElectronSample->GetEntries(); ++id) {
    tcElectronSample->GetEntry(id);

    h2dSampleXY->Fill(PositionX, PositionY);
    h1dSampleR->Fill(
        TMath::Sqrt(PositionX * PositionX + PositionY * PositionY));
    h1dSampleTime->Fill(Time);
    h1dSampleKineticEnergy->Fill(KineticEnergy);
  }

  h2dSampleXY->Draw("colz");
  cv->SetLogz(1);
  cv->SaveAs("./data_out/figure/h2dSampleXY.png");
  h1dSampleR->Draw("HIST");
  cv->SetLogy(0);
  cv->SaveAs("./data_out/figure/h1dSampleR.png");
  h1dSampleTime->Draw("HIST");
  cv->SetLogy(0);
  cv->SaveAs("./data_out/figure/h1dSampleTime.png");
  h1dSampleKineticEnergy->Draw("HIST");
  cv->SetLogy(1);
  cv->SaveAs("./data_out/figure/h1dSampleKineticEnergy.png");

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
