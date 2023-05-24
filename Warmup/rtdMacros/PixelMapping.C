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
   
   Pixel_Mapping = new TH2D("qpixrtd events", "Pixel Heatmap", 100, 250, 350, 1500, 0, 1500);
   Pixel_Mapping->GetXaxis()->SetTitle("X Coordinate [pixels]");
   Pixel_Mapping->GetYaxis()->SetTitle("Y Coordinate [pixels]");

   c1 = new TCanvas("canvas1", "Test Canvas1", 800, 800);   
}

Bool_t PixelMapping::Process(Long64_t entry)
{
  GetEntry(entry);
  fReader.SetLocalEntry(entry);
  
   for (int i=0; i < pixel_x.GetSize(); i++){
   Pixel_Mapping->Fill(pixel_x[i], pixel_y[i]);
   }
   return kTRUE;
}

void PixelMapping::SlaveTerminate()
{

}

void PixelMapping::Terminate()
{
  c1->SetBottomMargin(0.2);
  c1->SetLeftMargin(0.2);
  c1->SetRightMargin(0.2);   
   
Pixel_Mapping->GetXaxis()->CenterTitle(true);
Pixel_Mapping->GetXaxis()->SetTitleSize(20);
Pixel_Mapping->GetXaxis()->SetTitleFont(43);
Pixel_Mapping->GetXaxis()->SetTitleOffset(1.5);
Pixel_Mapping->GetXaxis()->SetLabelSize(0.05);
Pixel_Mapping->GetYaxis()->SetTitleSize(20);
Pixel_Mapping->GetYaxis()->SetTitleFont(43);
Pixel_Mapping->GetYaxis()->SetLabelSize(0.05);
Pixel_Mapping->GetXaxis()->SetNdivisions(5); 
Pixel_Mapping->GetYaxis()->SetNdivisions(5);    
Pixel_Mapping->SetMinimum(-0.00001);   
Pixel_Mapping->Draw("COLZ");

   gPad->Update();
   TPaletteAxis *palette = (TPaletteAxis*)Pixel_Mapping->GetListOfFunctions()->FindObject("palette");   
   palette->SetX1NDC(0.86);
   palette->SetX2NDC(0.9);
   palette->SetY1NDC(0.2);
   palette->SetY2NDC(0.6);
   gPad->Modified();
   gPad->Update();
   
c1->SaveAs("Pixel_Mapping.pdf");
c1->SaveAs("Pixel_Mapping.png");
    
}
