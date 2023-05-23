#define PixelMapping_cxx
#include "PixelMapping.h"

#include <TH1D.h>
#include <TH2D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TF1.h>
#include <TLine.h>
#include <TH2.h>
#include <TStyle.h>

TH2D * Pixel_Mapping = nullptr;

TCanvas * c1 = nullptr;

void PixelMapping::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void PixelMapping::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
   
   PixelMapping = new TH2D("rtd events", "Pixel Heatmap", 125, 0, 500, 125, 0, 500);
   PixelMapping->GetXaxis()->SetTitle("X Coordinate [mm]");
   PixelMapping->GetYaxis()->SetTitle("Y Coordinate [mm]");

   c1 = new TCanvas("canvas1", "Test Canvas1");   
}

Bool_t PixelMapping::Process(Long64_t entry)
{
  GetEntry(entry);
  fReader.SetLocalEntry(entry);
  
   Pixel_Mapping->Fill(pixel_x[0], pixel_y[0]);
   

   return kTRUE;
}

void PixelMapping::SlaveTerminate()
{

}

void PixelMapping::Terminate()
{

  c1->SetBottomMargin(0.2);
  c1->SetLeftMargin(0.15);
   
Pixel_Mapping->GetXaxis()->CenterTitle(true);
Pixel_Mapping->GetXaxis()->SetTitleSize(20);
Pixel_Mapping->GetXaxis()->SetTitleFont(43);
Pixel_Mapping->GetXaxis()->SetTitleOffset(1.5);
Pixel_Mapping->GetXaxis()->SetLabelSize(0.05);
Pixel_Mapping->GetYaxis()->SetTitleSize(20);
Pixel_Mapping->GetYaxis()->SetTitleFont(43);
Pixel_Mapping->GetYaxis()->SetLabelSize(0.05);
Pixel_Mapping->Draw();
c1->SaveAs("Pixel_Mapping.pdf");
c1->SaveAs("Pixel_Mapping.png");
    
}
