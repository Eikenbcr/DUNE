#define PDFsaver_Muon10GeV_cxx
#include "PDFsaver_Muon10GeV.h"

#include <TH1D.h>
#include <TH2D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TF1.h>
#include <TLine.h>
#include <TH2.h>
#include <TStyle.h>

TH1D * Muon_PositionX = nullptr;
TH1D * Muon_PositionY = nullptr;
TH1D * Muon_PositionZ = nullptr;
TH1D * Muon_MomentumX = nullptr;
TH1D * Muon_MomentumY = nullptr;
TH1D * Muon_MomentumZ = nullptr;
TH1D * Muon_Energy = nullptr;

TCanvas * c1 = nullptr;

void PDFsaver_Muon10GeV::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void PDFsaver_Muon10GeV::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();

Muon_PositionX = new TH1D("Muon X Position","", 50, 119, 121);
Muon_PositionX->GetXaxis()->SetTitle("X Position (cm)");
Muon_PositionX->GetYaxis()->SetTitle("Events / (0.2 cm)");
Muon_PositionY = new TH1D("Muon Y Position","", 50, -1, 1);
Muon_PositionY->GetXaxis()->SetTitle("Y Position (cm)");
Muon_PositionY->GetYaxis()->SetTitle("Events / (0.2 cm)");
Muon_PositionZ = new TH1D("Muon Z Position","", 125, 50, 300);
Muon_PositionZ->GetXaxis()->SetTitle("Z Position (cm)");
Muon_PositionZ->GetYaxis()->SetTitle("Events / (2.0 cm)");

Muon_MomentumX = new TH1D("Muon X Momentum","", 50, -1, 1);
Muon_MomentumX->GetXaxis()->SetTitle("X Momentum (MeV/c)");
Muon_MomentumX->GetYaxis()->SetTitle("Events / (0.2 MeV/c)");
Muon_MomentumY = new TH1D("Muon Y Momentum","", 50, 10104, 10106);
Muon_MomentumY->GetXaxis()->SetTitle("Y Momentum (MeV/c)");
Muon_MomentumY->GetYaxis()->SetTitle("Events / (0.2 MeV/c)");
Muon_MomentumZ = new TH1D("Muon Z Momentum","", 50, -1, 1);
Muon_MomentumZ->GetXaxis()->SetTitle("Z Momentum (MeV/c)");
Muon_MomentumZ->GetYaxis()->SetTitle("Events / (0.2 MeV/c)");

Muon_Energy = new TH1D("Muon Energy","", 50, 10104, 10106);
Muon_Energy->GetXaxis()->SetTitle("Energy (MeV)");
Muon_Energy->GetYaxis()->SetTitle("Events / (0.2 MeV)");

c1 = new TCanvas("canvas1", "Test Canvas1");

}

Bool_t PDFsaver_Muon10GeV::Process(Long64_t entry)
{

  GetEntry(entry);
  fReader.SetLocalEntry(entry);

Muon_PositionX->Fill(generator_initial_particle_x[0]);
Muon_PositionY->Fill(generator_initial_particle_y[0]);
Muon_PositionZ->Fill(generator_initial_particle_z[0]);

Muon_MomentumX->Fill(generator_initial_particle_px[0]);
Muon_MomentumY->Fill(generator_initial_particle_py[0]);
Muon_MomentumZ->Fill(generator_initial_particle_pz[0]);

Muon_Energy->Fill(generator_initial_particle_energy[0]);

   return kTRUE;
}

void PDFsaver_Muon10GeV::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void PDFsaver_Muon10GeV::Terminate()
{

  c1->SetBottomMargin(0.2);
  c1->SetLeftMargin(0.15);

Muon_PositionX->GetXaxis()->CenterTitle(true);
Muon_PositionX->GetXaxis()->SetTitleSize(20);
Muon_PositionX->GetXaxis()->SetTitleFont(43);
Muon_PositionX->GetXaxis()->SetTitleOffset(1.5);
Muon_PositionX->GetXaxis()->SetLabelSize(0.05);
Muon_PositionX->GetYaxis()->SetTitleSize(20);
Muon_PositionX->GetYaxis()->SetTitleFont(43);
Muon_PositionX->GetYaxis()->SetLabelSize(0.05);
Muon_PositionX->Draw();
c1->SaveAs("Muon_PositionX.pdf");

Muon_PositionY->GetXaxis()->CenterTitle(true);
Muon_PositionY->GetXaxis()->SetTitleSize(20);
Muon_PositionY->GetXaxis()->SetTitleFont(43);
Muon_PositionY->GetXaxis()->SetTitleOffset(1.5);
Muon_PositionY->GetXaxis()->SetLabelSize(0.05);
Muon_PositionY->GetYaxis()->SetTitleSize(20);
Muon_PositionY->GetYaxis()->SetTitleFont(43);
Muon_PositionY->GetYaxis()->SetLabelSize(0.05);
Muon_PositionY->Draw();
c1->SaveAs("Muon_PositionY.pdf");

Muon_PositionZ->GetXaxis()->CenterTitle(true);
Muon_PositionZ->GetXaxis()->SetTitleSize(20);
Muon_PositionZ->GetXaxis()->SetTitleFont(43);
Muon_PositionZ->GetXaxis()->SetTitleOffset(1.5);
Muon_PositionZ->GetXaxis()->SetLabelSize(0.05);
Muon_PositionZ->GetYaxis()->SetTitleSize(20);
Muon_PositionZ->GetYaxis()->SetTitleFont(43);
Muon_PositionZ->GetYaxis()->SetLabelSize(0.05);
Muon_PositionZ->Draw();
c1->SaveAs("Muon_PositionZ.pdf");

Muon_MomentumX->GetXaxis()->CenterTitle(true);
Muon_MomentumX->GetXaxis()->SetTitleSize(20);
Muon_MomentumX->GetXaxis()->SetTitleFont(43);
Muon_MomentumX->GetXaxis()->SetTitleOffset(1.5);
Muon_MomentumX->GetXaxis()->SetLabelSize(0.05);
Muon_MomentumX->GetYaxis()->SetTitleSize(20);
Muon_MomentumX->GetYaxis()->SetTitleFont(43);
Muon_MomentumX->GetYaxis()->SetLabelSize(0.05);
Muon_MomentumX->Draw();
c1->SaveAs("Muon_MomentumX.pdf");

Muon_MomentumY->GetXaxis()->CenterTitle(true);
Muon_MomentumY->GetXaxis()->SetTitleSize(20);
Muon_MomentumY->GetXaxis()->SetTitleFont(43);
Muon_MomentumY->GetXaxis()->SetTitleOffset(1.5);
Muon_MomentumY->GetXaxis()->SetLabelSize(0.05);
Muon_MomentumY->GetYaxis()->SetTitleSize(20);
Muon_MomentumY->GetYaxis()->SetTitleFont(43);
Muon_MomentumY->GetYaxis()->SetLabelSize(0.05);
Muon_MomentumY->GetYaxis()->SetLabelSize(0.05);
Muon_MomentumY->Draw();
c1->SaveAs("Muon_MomentumY.pdf");

Muon_MomentumZ->GetXaxis()->CenterTitle(true);
Muon_MomentumZ->GetXaxis()->SetTitleSize(20);
Muon_MomentumZ->GetXaxis()->SetTitleFont(43);
Muon_MomentumZ->GetXaxis()->SetTitleOffset(1.5);
Muon_MomentumZ->GetXaxis()->SetLabelSize(0.05);
Muon_MomentumZ->GetYaxis()->SetTitleSize(20);
Muon_MomentumZ->GetYaxis()->SetTitleFont(43);
Muon_MomentumZ->GetYaxis()->SetLabelSize(0.05);
Muon_MomentumZ->Draw();
c1->SaveAs("Muon_MomentumZ.pdf");

Muon_Energy->GetXaxis()->CenterTitle(true);
Muon_Energy->GetXaxis()->SetTitleSize(20);
Muon_Energy->GetXaxis()->SetTitleFont(43);
Muon_Energy->GetXaxis()->SetTitleOffset(1.5);
Muon_Energy->GetXaxis()->SetLabelSize(0.05);
Muon_Energy->GetYaxis()->SetTitleSize(20);
Muon_Energy->GetYaxis()->SetTitleFont(43);
Muon_Energy->GetYaxis()->SetLabelSize(0.05);
Muon_Energy->Draw();
c1->SaveAs("Muon_Energy.pdf");
}
