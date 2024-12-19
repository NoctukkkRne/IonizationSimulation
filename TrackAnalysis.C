#include <iostream>

#include <G4String.hh>
#include <G4SystemOfUnits.hh>

#include "Rootneed.h"
#include "jinpingStyle.h"

int main() {
  jinpingStyle();

  TCanvas *cv = new TCanvas("cv", "", 700, 500);

  TH1D *h1dBeginR = new TH1D("h1dBeginR", "", 1000, 0.0, 100.0e-6 * mm);
  h1dBeginR->GetXaxis()->SetTitle("BeginR [mm]");
  h1dBeginR->GetYaxis()->SetTitle("Counts");
  h1dBeginR->SetLineColor(kBlue);

  TH1D *h1dBeginTime = new TH1D("h1dBeginTime", "", 1000, 0.0, 0.1e-3 * ns);
  h1dBeginTime->GetXaxis()->SetTitle("BeginTime [ns]");
  h1dBeginTime->GetYaxis()->SetTitle("Counts");
  h1dBeginTime->SetLineColor(kBlue);

  TH1D *h1dEndTime = new TH1D("h1dEndTime", "", 1000, 0.0, 0.1e-3 * ns);
  h1dEndTime->GetXaxis()->SetTitle("EndTime [ns]");
  h1dEndTime->GetYaxis()->SetTitle("Counts");
  h1dEndTime->SetLineColor(kBlue);

  TH1D *h1dBeginKineticEnergy =
      new TH1D("h1dBeginKineticEnergy", "", 1000, 0.0 * eV, 100.0 * eV);
  h1dBeginKineticEnergy->GetXaxis()->SetTitle("BeginKineticEnergy [MeV]");
  h1dBeginKineticEnergy->GetYaxis()->SetTitle("Counts");
  h1dBeginKineticEnergy->SetLineColor(kBlue);

  TChain *tcTrack = new TChain("Track");
  tcTrack->Add("./data_out/Output.root");
  // tcElectronSample->Add("./data_out/Output_01.root");
  // tcElectronSample->Add("./data_out/Output_02.root");

  Int_t EventID, TrackID;
  Double_t BeginTime, EndTime, BeginPositionX, BeginPositionY, BeginPositionZ,
      EndPositionX, EndPositionY, EndPositionZ, BeginKineticEnergy,
      EndKineticEnergy;
  Char_t ParticleName, ProcessName;

  tcTrack->SetBranchAddress("EventID", &EventID);
  tcTrack->SetBranchAddress("TrackID", &TrackID);
  tcTrack->SetBranchAddress("ParticleName", &ParticleName);
  tcTrack->SetBranchAddress("ProcessName", &ProcessName);
  tcTrack->SetBranchAddress("BeginTime", &BeginTime);
  tcTrack->SetBranchAddress("EndTime", &EndTime);
  tcTrack->SetBranchAddress("BeginPositionX", &BeginPositionX);
  tcTrack->SetBranchAddress("BeginPositionY", &BeginPositionY);
  tcTrack->SetBranchAddress("BeginPositionZ", &BeginPositionZ);
  tcTrack->SetBranchAddress("EndPositionX", &EndPositionX);
  tcTrack->SetBranchAddress("EndPositionY", &EndPositionY);
  tcTrack->SetBranchAddress("EndPositionZ", &EndPositionZ);
  tcTrack->SetBranchAddress("BeginKineticEnergy", &BeginKineticEnergy);
  tcTrack->SetBranchAddress("EndKineticEnergy", &EndKineticEnergy);

  for (Long64_t id = 0; id < tcTrack->GetEntries(); ++id) {
    tcTrack->GetEntry(id);

    h1dBeginR->Fill(TMath::Sqrt(BeginPositionX * BeginPositionX +
                                BeginPositionY * BeginPositionY));
    h1dBeginTime->Fill(BeginTime);
    h1dEndTime->Fill(EndTime);
    h1dBeginKineticEnergy->Fill(BeginKineticEnergy);
  }

  h1dBeginR->Draw("HIST");
  cv->SetLogy(0);
  cv->SaveAs("./data_out/figure/h1dBeginR.png");
  h1dBeginTime->Draw("HIST");
  cv->SetLogy(0);
  cv->SaveAs("./data_out/figure/h1dBeginTime.png");
  h1dEndTime->Draw("HIST");
  cv->SetLogy(0);
  cv->SaveAs("./data_out/figure/h1dEndTime.png");
  h1dBeginKineticEnergy->Draw("HIST");
  cv->SetLogy(1);
  cv->SaveAs("./data_out/figure/h1dBeginKineticEnergy.png");

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
