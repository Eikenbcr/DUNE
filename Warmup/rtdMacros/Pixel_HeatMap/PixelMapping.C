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

TH2D * Pixel_Mapping_ALL = nullptr;
TH2D * Pixel_Mapping_ONE = nullptr;

TCanvas * c1 = nullptr;

void PixelMapping::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void PixelMapping::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
   
   Pixel_Mapping_ALL = new TH2D("qpixrtd events", "QPix Heatmap (All Events)", 100, 250, 350, 1500, 0, 1500);
   Pixel_Mapping_ALL->GetXaxis()->SetTitle("X Coordinate [pixel]");
   Pixel_Mapping_ALL->GetYaxis()->SetTitle("Y Coordinate [pixel]");
 
   Pixel_Mapping_ONE = new TH2D("qpixrtd events", "QPix Heatmap (One Event)", 100, 250, 350, 1500, 0, 1500);
   Pixel_Mapping_ONE->GetXaxis()->SetTitle("X Coordinate [pixel]");
   Pixel_Mapping_ONE->GetYaxis()->SetTitle("Y Coordinate [pixel]");
   
   c1 = new TCanvas("canvas1", "Test Canvas1");   
}

Bool_t PixelMapping::Process(Long64_t entry)
{
  GetEntry(entry);
  fReader.SetLocalEntry(entry);
   
   
       bool Event = (
       (*event == 0.)
       );  
   
   for (int i=0; i < pixel_x.GetSize(); i++){
   Pixel_Mapping_ALL->Fill(pixel_x[i], pixel_y[i]);  
      if (Event){
   Pixel_Mapping_ONE->Fill(pixel_x[i], pixel_y[i]);           
      }
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
gStyle->SetPalette(kTemperatureMap);   
   
Pixel_Mapping_ALL->GetXaxis()->CenterTitle(true);
Pixel_Mapping_ALL->GetXaxis()->SetTitleSize(20);
Pixel_Mapping_ALL->GetXaxis()->SetTitleFont(43);
Pixel_Mapping_ALL->GetXaxis()->SetTitleOffset(1.5);
Pixel_Mapping_ALL->GetXaxis()->SetLabelSize(0.05);
Pixel_Mapping_ALL->GetYaxis()->SetTitleSize(20);
Pixel_Mapping_ALL->GetYaxis()->SetTitleFont(43);
Pixel_Mapping_ALL->GetYaxis()->SetLabelSize(0.05);
Pixel_Mapping_ALL->GetXaxis()->SetNdivisions(5); 
Pixel_Mapping_ALL->GetYaxis()->SetNdivisions(5);    
//Pixel_Mapping_ALL->SetMinimum(-0.00001);   
Pixel_Mapping_ALL->Draw("COLZ");

   gPad->Update();
   TPaletteAxis *palette1 = (TPaletteAxis*)Pixel_Mapping_ALL->GetListOfFunctions()->FindObject("palette");   
   palette1->SetX1NDC(0.86);
   palette1->SetX2NDC(0.9);
   palette1->SetY1NDC(0.2);
   palette1->SetY2NDC(0.6);
   gPad->Modified();
   gPad->Update();
   
c1->SaveAs("Pixel_Mapping_ALL.pdf");
c1->SaveAs("Pixel_Mapping_ALL.png");
   
 gStyle->SetNumberContours(1);  
   
Pixel_Mapping_ONE->GetXaxis()->CenterTitle(true);
Pixel_Mapping_ONE->GetXaxis()->SetTitleSize(20);
Pixel_Mapping_ONE->GetXaxis()->SetTitleFont(43);
Pixel_Mapping_ONE->GetXaxis()->SetTitleOffset(1.5);
Pixel_Mapping_ONE->GetXaxis()->SetLabelSize(0.05);
Pixel_Mapping_ONE->GetYaxis()->SetTitleSize(20);
Pixel_Mapping_ONE->GetYaxis()->SetTitleFont(43);
Pixel_Mapping_ONE->GetYaxis()->SetLabelSize(0.05);
Pixel_Mapping_ONE->GetXaxis()->SetNdivisions(5); 
Pixel_Mapping_ONE->GetYaxis()->SetNdivisions(5);    
Pixel_Mapping_ONE->GetZaxis()->SetNdivisions(1);    
//Pixel_Mapping_ONE->SetMinimum(-0.00001);   
Pixel_Mapping_ONE->Draw("COLZ");

   gPad->Update();
   TPaletteAxis *palette2 = (TPaletteAxis*)Pixel_Mapping_ONE->GetListOfFunctions()->FindObject("palette");   
   palette2->SetX1NDC(0.86);
   palette2->SetX2NDC(0.9);
   palette2->SetY1NDC(0.2);
   palette2->SetY2NDC(0.6);
   gPad->Modified();
   gPad->Update();
   
c1->SaveAs("Pixel_Mapping_ONE.pdf");
c1->SaveAs("Pixel_Mapping_ONE.png");   
}
