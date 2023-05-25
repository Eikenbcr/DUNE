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

 vector <double> x_init(0);
 vector <double> x_fin(0);
 vector <double> y_init(0);
 vector <double> y_fin(0);
 vector <double> z_init(0);
 vector <double> z_fin(0);
 double x_arr[2];
 double y_arr[2];
 double z_arr[2];

TH2D * Track_XY = nullptr;
TH2D * Track_YZ = nullptr;
TH2D * Track_XZ = nullptr;
TH3D * Track_XYZ = nullptr;

TCanvas * c1 = nullptr;

void g4_Particle_Tracks::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void g4_Particle_Tracks::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
   
   Track_XY = new TH2D("qpixg4 events", "Track Hits in X-Y Plane", 575, 0, 230, 1500, 0, 600);
   Track_XY->GetXaxis()->SetTitle("X Position [cm]");
   Track_XY->GetYaxis()->SetTitle("Y Position [cm]");
   
   Track_XZ = new TH2D("qpixg4 events", "Track Hits in X-Z Plane", 575, 0, 230, 900, 0, 360);
   Track_XZ->GetXaxis()->SetTitle("X Position [cm]");
   Track_XZ->GetYaxis()->SetTitle("Z Position [cm]");
   
   Track_YZ = new TH2D("qpixg4 events", "Track Hits in Y-Z Plane", 1500, 0, 600, 900, 0, 360);
   Track_YZ->GetXaxis()->SetTitle("Y Position [cm]");
   Track_YZ->GetYaxis()->SetTitle("Z Position [cm]");
   
   Track_XYZ = new TH3D("qpixg4 events", "Track Hits in 3D", 575, 0, 230, 1500, 0, 600, 900, 0, 360);
   Track_XYZ->GetXaxis()->SetTitle("X Position [cm]]");
   Track_XYZ->GetYaxis()->SetTitle("Y Position [cm]");
   Track_XYZ->GetZaxis()->SetTitle("Z Position [cm]");

   
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

  x_init.push_back(hit_start_x[i]);        
  x_fin.push_back(hit_end_x[i]);  
  y_init.push_back(hit_start_y[i]);        
  y_fin.push_back(hit_end_y[i]);    
  z_init.push_back(hit_start_z[i]);        
  z_fin.push_back(hit_end_z[i]);                     
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
   
 Track_XY->GetXaxis()->CenterTitle(true);
 Track_XY->GetXaxis()->SetTitleSize(20);
 Track_XY->GetXaxis()->SetTitleFont(43);
 Track_XY->GetXaxis()->SetTitleOffset(1.5);
 Track_XY->GetXaxis()->SetLabelSize(0.05);
 Track_XY->GetYaxis()->SetTitleSize(20);
 Track_XY->GetYaxis()->SetTitleFont(43);
 Track_XY->GetYaxis()->SetLabelSize(0.05);   
 Track_XY->Draw();  

TLine * line_xy[x_init.size()];
 
   for (int n=0; n < x_init.size(); n++){
    line_xy[n] = new TLine(x_init[n],y_init[n],x_fin[n],y_fin[n]);
    line_xy[n]->SetLineColor(kRed);
    line_xy[n]->Draw("SAME");
   }
 
 c1->SaveAs("Track_XY.pdf");
 c1->SaveAs("Track_XY.png");   
 
 Track_XZ->GetXaxis()->CenterTitle(true);
 Track_XZ->GetXaxis()->SetTitleSize(20);
 Track_XZ->GetXaxis()->SetTitleFont(43);
 Track_XZ->GetXaxis()->SetTitleOffset(1.5);
 Track_XZ->GetXaxis()->SetLabelSize(0.05);
 Track_XZ->GetYaxis()->SetTitleSize(20);
 Track_XZ->GetYaxis()->SetTitleFont(43);
 Track_XZ->GetYaxis()->SetLabelSize(0.05);   
 Track_XZ->Draw();  

TLine * line_xz[x_init.size()];
 
   for (int n=0; n < x_init.size(); n++){
    line_xz[n] = new TLine(x_init[n],z_init[n],x_fin[n],z_fin[n]);
    line_xz[n]->SetLineColor(kRed);
    line_xz[n]->Draw("SAME");
   }
 
 c1->SaveAs("Track_XZ.pdf");
 c1->SaveAs("Track_XZ.png");   
 
 Track_YZ->GetXaxis()->CenterTitle(true);
 Track_YZ->GetXaxis()->SetTitleSize(20);
 Track_YZ->GetXaxis()->SetTitleFont(43);
 Track_YZ->GetXaxis()->SetTitleOffset(1.5);
 Track_YZ->GetXaxis()->SetLabelSize(0.05);
 Track_YZ->GetYaxis()->SetTitleSize(20);
 Track_YZ->GetYaxis()->SetTitleFont(43);
 Track_YZ->GetYaxis()->SetLabelSize(0.05);   
 Track_YZ->Draw();  

TLine * line_yz[x_init.size()];
 
   for (int n=0; n < x_init.size(); n++){
    line_yz[n] = new TLine(y_init[n],z_init[n],y_fin[n],z_fin[n]);
    line_yz[n]->SetLineColor(kRed);
    line_yz[n]->Draw("SAME");
   }
 
 c1->SaveAs("Track_YZ.pdf");
 c1->SaveAs("Track_YZ.png");   
 
 Track_XYZ->GetXaxis()->CenterTitle(true);  
 Track_XYZ->GetYaxis()->CenterTitle(true); 
 Track_XYZ->GetXaxis()->SetTitleOffset(2);
 Track_XYZ->GetYaxis()->SetTitleOffset(2);  
 Track_XYZ->GetZaxis()->SetTitleOffset(1.5);     
 Track_XYZ->Draw();  

 TPolyLine3D * line_xyz[x_init.size()];
 
    for (int n=0; n < x_init.size(); n++){
    x_arr[0] = x_init[n];
    x_arr[1] = x_fin[n];     
    y_arr[0] = y_init[n];
    y_arr[1] = y_fin[n];     
    z_arr[0] = z_init[n];
    z_arr[1] = z_fin[n];          
    line_xyz[n] = new TPolyLine3D(2, x_arr, y_arr, z_arr);
    line_xyz[n]->SetLineColor(kRed);
    line_xyz[n]->Draw("SAME");
   }
 
 c1->SaveAs("Track_XYZ.pdf");
 c1->SaveAs("Track_XYZ.png");      
}
