#define Pixel_Study_cxx
#include "Pixel_Study.h"

#include <TH1D.h>
#include <TH2D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TF1.h>
#include <TLine.h>
#include <TH2.h>
#include <TStyle.h>

TH1D * Pixel_X_1 = nullptr;
TH1D * Pixel_X_2 = nullptr;
TH1D * Pixel_Y_1 = nullptr;
TH1D * Pixel_Y_2 = nullptr;

TCanvas * c1 = nullptr;

void Pixel_Study::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void Pixel_Study::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();

   Pixel_X_1 = new TH1D("rtd events", "Pixel_X[3]", 500, 0, 500);
   Pixel_X_1->GetXaxis()->SetTitle("X Coordinate [pixel]");
   Pixel_X_1->GetYaxis()->SetTitle("nResets/pixel");
   Pixel_X_1->SetLineColor(kBlue);
   
   Pixel_X_2 = new TH1D("rtd events", "Pixel_X[9]", 500, 0, 500);
   Pixel_X_2->GetXaxis()->SetTitle("X Coordinate [pixel]");
   Pixel_X_2->GetYaxis()->SetTitle("nResets/pixel");
   Pixel_X_2->SetLineColor(kRed);
   
   Pixel_Y_1 = new TH1D("rtd events", "Pixel_Y[3]", 1600, 0, 1600);
   Pixel_Y_1->GetXaxis()->SetTitle("Y Coordinate [pixel]");
   Pixel_Y_1->GetYaxis()->SetTitle("nResets/pixel");
   Pixel_Y_1->SetLineColor(kBlue);
   
   Pixel_Y_2 = new TH1D("rtd events", "Pixel_Y[9]", 1600, 0, 1600);
   Pixel_Y_2->GetXaxis()->SetTitle("Y Coordinate [pixel]");
   Pixel_Y_2->GetYaxis()->SetTitle("nResets/pixel");
   Pixel_Y_2->SetLineColor(kRed);
      
   c1 = new TCanvas("canvas1", "Test Canvas1");      
}

Bool_t Pixel_Study::Process(Long64_t entry)
{
  GetEntry(entry);
  fReader.SetLocalEntry(entry);
  
  Pixel_X_1->Fill(pixel_x[3]);
  Pixel_X_2->Fill(pixel_x[9]);
   
  Pixel_Y_1->Fill(pixel_y[3]);
  Pixel_Y_2->Fill(pixel_y[9]);
   
   return kTRUE;
}

void Pixel_Study::SlaveTerminate()
{

}

void Pixel_Study::Terminate()
{
   
  c1->SetBottomMargin(0.2);
  c1->SetLeftMargin(0.15);
  gStyle->SetOptStat(0);   
   
Pixel_X_1->GetXaxis()->CenterTitle(true);
Pixel_X_1->GetXaxis()->SetTitleSize(20);
Pixel_X_1->GetXaxis()->SetTitleFont(43);
Pixel_X_1->GetXaxis()->SetTitleOffset(1.5);
Pixel_X_1->GetXaxis()->SetLabelSize(0.05);
Pixel_X_1->GetYaxis()->SetTitleSize(20);
Pixel_X_1->GetYaxis()->SetTitleFont(43);
Pixel_X_1->GetYaxis()->SetLabelSize(0.05);
Pixel_X_1->GetXaxis()->SetNdivisions(5);
Pixel_X_1->SetLineWidth(2);
Pixel_X_2->SetLineWidth(2);   
Pixel_X_1->Draw();  
Pixel_X_2->Draw("SAME");   
gPad->BuildLegend(0.7,0.7,0.9,0.9);   
Pixel_X_1->SetTitle("");
c1->SaveAs("Pixel_X.pdf");
c1->SaveAs("Pixel_X.png");   

   
Pixel_Y_1->GetXaxis()->CenterTitle(true);
Pixel_Y_1->GetXaxis()->SetTitleSize(20);
Pixel_Y_1->GetXaxis()->SetTitleFont(43);
Pixel_Y_1->GetXaxis()->SetTitleOffset(1.5);
Pixel_Y_1->GetXaxis()->SetLabelSize(0.05);
Pixel_Y_1->GetYaxis()->SetTitleSize(20);
Pixel_Y_1->GetYaxis()->SetTitleFont(43);
Pixel_Y_1->GetYaxis()->SetLabelSize(0.05);
Pixel_Y_1->GetXaxis()->SetNdivisions(5);
Pixel_Y_1->SetLineWidth(2);
Pixel_Y_2->SetLineWidth(2);   
Pixel_Y_1->Draw();  
Pixel_Y_2->Draw("SAME");   
gPad->BuildLegend(0.2,0.7,0.4,0.9);  
Pixel_Y_1->SetTitle("");   
c1->SaveAs("Pixel_Y.pdf");
c1->SaveAs("Pixel_Y.png");      
}
