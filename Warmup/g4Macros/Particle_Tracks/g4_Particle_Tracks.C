#define g4_Particle_Tracks_cxx
#include "g4_Particle_Tracks.h"

#include <TH1D.h>
#include <TH2D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TF1.h>
#include <TLine.h>
#include <TH2.h>
#include <TStyle.h>

TH2D * Track_XY_Init = nullptr;
TH2D * Track_XZ_Init = nullptr;
TH2D * Track_YZ_Init = nullptr;
TH3D * Track_XYZ_Init = nullptr;

TH2D * Track_XY_Fin = nullptr;
TH2D * Track_XZ_Fin = nullptr;
TH2D * Track_YZ_Fin = nullptr;
TH3D * Track_XYZ_Fin = nullptr;

void g4_Particle_Tracks::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void g4_Particle_Tracks::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
   
   Track_XY_Init = new TH2D("qpixg4 events", "Initial Track Hits", 575, 0, 230, 1500, 0, 600);
   Track_XY_Init->GetXaxis()->SetTitle("X Position [cm]");
   Track_XY_Init->GetYaxis()->SetTitle("Y Position [cm]");
   Track_XY_Init-SetFillColor(kBlue);
   
   Track_XY_Fin = new TH2D("qpixg4 events", "Final Track Hits", 575, 0, 230, 1500, 0, 600);
   Track_XY_Fin->GetXaxis()->SetTitle("X Position [cm]]");
   Track_XY_Fin->GetYaxis()->SetTitle("Y Position [cm]");
   Track_XY_Fin-SetFillColor(kRed);      
   
   Track_XZ_Init = new TH2D("qpixg4 events", "Initial Track Hits", 575, 0, 230, 900, 0, 360);
   Track_XZ_Init->GetXaxis()->SetTitle("X Position [cm]");
   Track_XZ_Init->GetYaxis()->SetTitle("Z Position [cm]");
   Track_XZ_Init-SetFillColor(kBlue);
   
   Track_XZ_Fin = new TH2D("qpixg4 events", "Final Track Hits", 575, 0, 230, 900, 0, 360);
   Track_XZ_Fin->GetXaxis()->SetTitle("X Position [cm]]");
   Track_XZ_Fin->GetYaxis()->SetTitle("Z Position [cm]");
   Track_XZ_Fin-SetFillColor(kRed);   
   
   Track_YZ_Init = new TH2D("qpixg4 events", "Initial Track Hits", 1500, 0, 600, 900, 0, 360);
   Track_YZ_Init->GetXaxis()->SetTitle("Y Position [cm]");
   Track_YZ_Init->GetYaxis()->SetTitle("Z Position [cm]");
   Track_YZ_Init-SetFillColor(kBlue);
   
   Track_YZ_Fin = new TH2D("qpixg4 events", "Final Track Hits", 1500, 0, 600, 900, 0, 360);
   Track_YZ_Fin->GetXaxis()->SetTitle("Y Position [cm]]");
   Track_YZ_Fin->GetYaxis()->SetTitle("Z Position [cm]");
   Track_YZ_Fin-SetFillColor(kRed);   
   
   Track_XYZ_Init = new TH3D("qpixg4 events", "Initial Track Hits", 575, 0, 230, 1500, 0, 600, 900, 0, 360);
   Track_XYZ_Init->GetXaxis()->SetTitle("X Position [cm]");
   Track_XYZ_Init->GetYaxis()->SetTitle("Y Position [cm]");
   Track_XYZ_Init->GetZaxis()->SetTitle("Z Position [cm]");
   Track_XYZ_Init-SetFillColor(kBlue);
   
   Track_XYZ_Fin = new TH3D("qpixg4 events", "Final Track Hits", 575, 0, 230, 1500, 0, 600, 900, 0, 360);
   Track_XYZ_Fin->GetXaxis()->SetTitle("X Position [cm]]");
   Track_XYZ_Fin->GetYaxis()->SetTitle("Y Position [cm]");
   Track_XYZ_Fin->GetZaxis()->SetTitle("Z Position [cm]");
   Track_XYZ_Fin-SetFillColor(kRed);   
   
   c1 = new TCanvas("canvas1", "Test Canvas1");      
}

Bool_t g4_Particle_Tracks::Process(Long64_t entry)
{
  GetEntry(entry);
  fReader.SetLocalEntry(entry);
   
   
       bool Event = (
       (*event == 0.)
       );  
   
   for (int i=0; i < hit_start_x.GetSize(); i++){
      if (Event){
         
  Track_XY_Init->Fill(hit_start_x[i], hit_start_y[i]);   
  Track_XY_Fin->Fill(hit_end_x[i], hit_end_y[i]);
  Track_XZ_Init->Fill(hit_start_x[i], hit_start_z[i]);   
  Track_XZ_Fin->Fill(hit_end_x[i], hit_end_z[i]);       
  Track_YZ_Init->Fill(hit_start_y[i], hit_start_z[i]);   
  Track_YZ_Fin->Fill(hit_end_y[i], hit_end_z[i]);     
  Track_XYZ_Init->Fill(hit_start_x[i], hit_start_y[i], hit_start_z[i]);   
  Track_XYZ_Fin->Fill(hit_end_x[i], hit_end_y[i], hit_end_z[i]);             
      }
   }   

   return kTRUE;
}

void g4_Particle_Tracks::SlaveTerminate()
{

}

void g4_Particle_Tracks::Terminate()
{
  c1->SetBottomMargin(0.2);
  c1->SetLeftMargin(0.15);
  gStyle->SetOptStat(0);   
   
 Track_XY_Init->GetXaxis()->CenterTitle(true);
 Track_XY_Init->GetXaxis()->SetTitleSize(20);
 Track_XY_Init->GetXaxis()->SetTitleFont(43);
 Track_XY_Init->GetXaxis()->SetTitleOffset(1.5);
 Track_XY_Init->GetXaxis()->SetLabelSize(0.05);
 Track_XY_Init->GetYaxis()->SetTitleSize(20);
 Track_XY_Init->GetYaxis()->SetTitleFont(43);
 Track_XY_Init->GetYaxis()->SetLabelSize(0.05);   
 Track_XY_Init->Draw();  
 Track_XY_Fin->Draw("SAME");   
 gPad->BuildLegend(0.7,0.7,0.9,0.9);   
 Track_XY_Init->SetTitle("Track Hits in X-Y Plane");
 c1->SaveAs("Track_XY.pdf");
 c1->SaveAs("Track_XY.png");   

 Track_XZ_Init->GetXaxis()->CenterTitle(true);
 Track_XZ_Init->GetXaxis()->SetTitleSize(20);
 Track_XZ_Init->GetXaxis()->SetTitleFont(43);
 Track_XZ_Init->GetXaxis()->SetTitleOffset(1.5);
 Track_XZ_Init->GetXaxis()->SetLabelSize(0.05);
 Track_XZ_Init->GetYaxis()->SetTitleSize(20);
 Track_XZ_Init->GetYaxis()->SetTitleFont(43);
 Track_XZ_Init->GetYaxis()->SetLabelSize(0.05);   
 Track_XZ_Init->Draw();  
 Track_XZ_Fin->Draw("SAME");   
 gPad->BuildLegend(0.7,0.7,0.9,0.9);   
 Track_XZ_Init->SetTitle("Track Hits in X-Z Plane");
 c1->SaveAs("Track_XZ.pdf");
 c1->SaveAs("Track_XZ.png");      
   
 Track_YZ_Init->GetXaxis()->CenterTitle(true);
 Track_YZ_Init->GetXaxis()->SetTitleSize(20);
 Track_YZ_Init->GetXaxis()->SetTitleFont(43);
 Track_YZ_Init->GetXaxis()->SetTitleOffset(1.5);
 Track_YZ_Init->GetXaxis()->SetLabelSize(0.05);
 Track_YZ_Init->GetYaxis()->SetTitleSize(20);
 Track_YZ_Init->GetYaxis()->SetTitleFont(43);
 Track_YZ_Init->GetYaxis()->SetLabelSize(0.05);   
 Track_YZ_Init->Draw();  
 Track_YZ_Fin->Draw("SAME");   
 gPad->BuildLegend(0.7,0.7,0.9,0.9);   
 Track_YZ_Init->SetTitle("Track Hits in Y-Z Plane");
 c1->SaveAs("Track_YZ.pdf");
 c1->SaveAs("Track_YZ.png");       
   
 Track_XYZ_Init->Draw();  
 Track_XYZ_Fin->Draw("SAME");   
 gPad->BuildLegend(0.7,0.7,0.9,0.9);   
 Track_YZ_Init->SetTitle("Track Hits in 3D");
 c1->SaveAs("Track_XYZ.pdf");
 c1->SaveAs("Track_XYZ.png");      
}
