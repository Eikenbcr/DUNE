#define PixelResetTime_cxx
#include "PixelResetTime.h"
#include "GaussianFit.C"

#include <TH1D.h>
#include <TH2D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TF1.h>
#include <TLine.h>
#include <TH2.h>
#include <TStyle.h>
#include <TGraph.h>

TH1D * Pixel_Reset_1 = nullptr;
TH1D * Pixel_Reset_2 = nullptr;
TH1D * Pixel_Reset_3 = nullptr;
TH1D * Pixel_Reset_4 = nullptr;
TH1D * Pixel_Reset_5 = nullptr;
TGraph * gr = nullptr;
TGraph * gr3 = nullptr;

const int pix_num = 2612;
const int pix_num_3 = 1482;

int n3 = 0;

TH1D * pix_res[pix_num];   
double tconv_pix_[pix_num];     
double mean[pix_num], rms[pix_num];

TH1D * pix_res_3[pix_num_3];   
double tconv_pix_3[pix_num_3];     
double mean_3[pix_num_3], rms_3[pix_num_3];

TString str;

TCanvas * c1 = nullptr;

void PixelResetTime::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void PixelResetTime::SlaveBegin(TTree * /*tree*/)
{
 
Pixel_Reset_1 = new TH1D("qpixrtd events", "Pixel [300,7] Reset Frequency", 18000, 200, 2000);
Pixel_Reset_1->GetXaxis()->SetTitle("time (#mus)");
Pixel_Reset_1->GetYaxis()->SetTitle("Resets / (0.1 #mus)");
   
Pixel_Reset_2 = new TH1D("qpixrtd events", "Pixel [300,10] Reset Frequency", 18000, 200, 2000);
Pixel_Reset_2->GetXaxis()->SetTitle("time (#mus)");
Pixel_Reset_2->GetYaxis()->SetTitle("Resets / (0.1 #mus)");   
   
Pixel_Reset_3 = new TH1D("qpixrtd events", "Pixel [300,50] Reset Frequency", 18000, 200, 2000);
Pixel_Reset_3->GetXaxis()->SetTitle("time (#mus)");
Pixel_Reset_3->GetYaxis()->SetTitle("Resets / (0.1 #mus)");      
   
Pixel_Reset_4 = new TH1D("qpixrtd events", "Pixel [300,100] Reset Frequency", 18000, 200, 2000);
Pixel_Reset_4->GetXaxis()->SetTitle("time (#mus)");
Pixel_Reset_4->GetYaxis()->SetTitle("Resets / (0.1 #mus)");    
   
Pixel_Reset_5 = new TH1D("qpixrtd events", "Pixel [300,500] Reset Frequency", 18000, 200, 2000);
Pixel_Reset_5->GetXaxis()->SetTitle("time (#mus)");
Pixel_Reset_5->GetYaxis()->SetTitle("Resets / (0.1 #mus)");     

  for (int i=0; i < pix_num; i++){ 
str.Form("%02d",i+1);          
pix_res[i] = new TH1D("qpixrtd events ["+str+"]", "Pixel ["+str+"]Reset Frequency", 18000, 200, 2000);
pix_res[i]->GetXaxis()->SetTitle("time (#mus)");
pix_res[i]->GetYaxis()->SetTitle("Resets / (0.1 #mus)");     
  }
 
  for (int i=0; i < pix_num_3; i++){ 
str.Form("%02d",i+1);          
pix_res_3[i] = new TH1D("qpixrtd events ["+str+"], res > 2", "Pixel ["+str+"]Reset Frequency", 18000, 200, 2000);
pix_res_3[i]->GetXaxis()->SetTitle("time (#mus)");
pix_res_3[i]->GetYaxis()->SetTitle("Resets / (0.1 #mus)");     
  }   
   
c1 = new TCanvas("canvas1", "Test Canvas1");   
}

Bool_t PixelResetTime::Process(Long64_t entry)
{

   GetEntry(entry);
  fReader.SetLocalEntry(entry);
   
         bool Event = (
       (*event == 0.)
       );  

if (Event){
std::cout << "number of pixels in Event 1: " << pixel_x.GetSize() << '\n'; 
   
      for (int i=0; i < pixel_x.GetSize(); i++){
         for (int j=0; j <pixel_reset[i].size(); j++){
               
   bool X_Val = (
      (pixel_x[i] == 300)
      );          
            
   bool Y_Val_1 = (
      (pixel_y[i] == 7)
      );
            
      bool Y_Val_2 = (
      (pixel_y[i] == 10)
      );
   
      bool Y_Val_3 = (
      (pixel_y[i] == 50)
      );
   
      bool Y_Val_4 = (
      (pixel_y[i] == 100)
      );
   
      bool Y_Val_5 = (
      (pixel_y[i] == 500)
      );       

            if (X_Val && Y_Val_1){
                double tconv_pix1 = (pixel_reset[i][j]) * 1e+6; 
                Pixel_Reset_1->Fill(tconv_pix1);           
            }    

            if (X_Val && Y_Val_2){
                double tconv_pix2 = (pixel_reset[i][j]) * 1e+6; 
                Pixel_Reset_2->Fill(tconv_pix2);           
            }     
            
            if (X_Val && Y_Val_3){
                double tconv_pix3 = (pixel_reset[i][j]) * 1e+6; 
                Pixel_Reset_3->Fill(tconv_pix3);           
            }     
            
            if (X_Val && Y_Val_4){
                double tconv_pix4 = (pixel_reset[i][j]) * 1e+6; 
                Pixel_Reset_4->Fill(tconv_pix4);           
            }  
            
            if (X_Val && Y_Val_5){
                double tconv_pix5 = (pixel_reset[i][j]) * 1e+6; 
                Pixel_Reset_5->Fill(tconv_pix5);           
            }  
            
tconv_pix_[i] = (pixel_reset[i][j]) * 1e+6; 
pix_res[i]->Fill(tconv_pix_[i]);            

            
if (pixel_reset[i].size() > 2.){
         for (int n=0; n <pix_num_3; n++){   
tconv_pix_3[n] = (pixel_reset[i][j]) * 1e+6; 
pix_res_3[n]->Fill(tconv_pix_3[n]);         
   }                
}       
         }
         
if (pixel_reset[i].size() > 2.){
   n3 = n3 + 1;
   }      
         
         }
   
   std::cout << "number of pixels in Event 1 with 3+ resets: " << n3 << '\n'; 
}
            

   
   return kTRUE;
}

void PixelResetTime::SlaveTerminate()
{


}

void PixelResetTime::Terminate()
{
  c1->SetBottomMargin(0.2);
  c1->SetLeftMargin(0.15);

TF1 *FitFunc = new TF1("FitFunc",Gaussian_fit,400, 600,2);
   
double PR1L =  Pixel_Reset_1->GetMean() - 2;
double PR1H =  Pixel_Reset_1->GetMean() + 2;   
double PR2L =  Pixel_Reset_2->GetMean() - 2;
double PR2H =  Pixel_Reset_2->GetMean() + 2; 
double PR3L =  Pixel_Reset_3->GetMean() - 2;
double PR3H =  Pixel_Reset_3->GetMean() + 2;      
double PR4L =  Pixel_Reset_4->GetMean() - 2;
double PR4H =  Pixel_Reset_4->GetMean() + 2;      
double PR5L =  Pixel_Reset_5->GetMean() - 2;
double PR5H =  Pixel_Reset_5->GetMean() + 2;      
   
Pixel_Reset_1->GetXaxis()->CenterTitle(true);
Pixel_Reset_1->GetXaxis()->SetTitleSize(20);
Pixel_Reset_1->GetXaxis()->SetTitleFont(43);
Pixel_Reset_1->GetXaxis()->SetTitleOffset(1.5);
Pixel_Reset_1->GetXaxis()->SetLabelSize(0.05);
Pixel_Reset_1->GetYaxis()->SetTitleSize(20);
Pixel_Reset_1->GetYaxis()->SetTitleFont(43);
Pixel_Reset_1->GetYaxis()->SetLabelSize(0.05);
Pixel_Reset_1->GetXaxis()->SetRangeUser(PR1L,PR1H);
Pixel_Reset_1->GetXaxis()->SetNdivisions(6); 
Pixel_Reset_1->Draw();
c1->SaveAs("Pixel_Reset_1.pdf");
c1->SaveAs("Pixel_Reset_1.png");
FitFunc->SetParameter(1, Pixel_Reset_1->GetRMS());      
FitFunc->SetParameter(0, Pixel_Reset_1->GetMean()); 
FitFunc->Draw("SAME");  
c1->SaveAs("Pixel_Reset_1_Fit.pdf");
c1->SaveAs("Pixel_Reset_1_Fit.png");
c1->Clear();   

Pixel_Reset_2->GetXaxis()->CenterTitle(true);
Pixel_Reset_2->GetXaxis()->SetTitleSize(20);
Pixel_Reset_2->GetXaxis()->SetTitleFont(43);
Pixel_Reset_2->GetXaxis()->SetTitleOffset(1.5);
Pixel_Reset_2->GetXaxis()->SetLabelSize(0.05);
Pixel_Reset_2->GetYaxis()->SetTitleSize(20);
Pixel_Reset_2->GetYaxis()->SetTitleFont(43);
Pixel_Reset_2->GetYaxis()->SetLabelSize(0.05);
Pixel_Reset_2->GetXaxis()->SetRangeUser(PR2L,PR2H);
Pixel_Reset_2->GetXaxis()->SetNdivisions(6); 
Pixel_Reset_2->Draw();
c1->SaveAs("Pixel_Reset_2.pdf");
c1->SaveAs("Pixel_Reset_2.png"); 
FitFunc->SetParameter(1, Pixel_Reset_2->GetRMS());      
FitFunc->SetParameter(0, Pixel_Reset_2->GetMean()); 
FitFunc->Draw("SAME");  
c1->SaveAs("Pixel_Reset_2_Fit.pdf");
c1->SaveAs("Pixel_Reset_2_Fit.png");
c1->Clear();   
   
Pixel_Reset_3->GetXaxis()->CenterTitle(true);
Pixel_Reset_3->GetXaxis()->SetTitleSize(20);
Pixel_Reset_3->GetXaxis()->SetTitleFont(43);
Pixel_Reset_3->GetXaxis()->SetTitleOffset(1.5);
Pixel_Reset_3->GetXaxis()->SetLabelSize(0.05);
Pixel_Reset_3->GetYaxis()->SetTitleSize(20);
Pixel_Reset_3->GetYaxis()->SetTitleFont(43);
Pixel_Reset_3->GetYaxis()->SetLabelSize(0.05);
Pixel_Reset_3->GetXaxis()->SetRangeUser(PR3L,PR3H);   
Pixel_Reset_3->GetXaxis()->SetNdivisions(6);  
Pixel_Reset_3->Draw();  
c1->SaveAs("Pixel_Reset_3.pdf");
c1->SaveAs("Pixel_Reset_3.png");   
FitFunc->SetParameter(1, Pixel_Reset_3->GetRMS());      
FitFunc->SetParameter(0, Pixel_Reset_3->GetMean()); 
FitFunc->Draw("SAME");  
c1->SaveAs("Pixel_Reset_3_Fit.pdf");
c1->SaveAs("Pixel_Reset_3_Fit.png");
c1->Clear();   
   
Pixel_Reset_4->GetXaxis()->CenterTitle(true);
Pixel_Reset_4->GetXaxis()->SetTitleSize(20);
Pixel_Reset_4->GetXaxis()->SetTitleFont(43);
Pixel_Reset_4->GetXaxis()->SetTitleOffset(1.5);
Pixel_Reset_4->GetXaxis()->SetLabelSize(0.05);
Pixel_Reset_4->GetYaxis()->SetTitleSize(20);
Pixel_Reset_4->GetYaxis()->SetTitleFont(43);
Pixel_Reset_4->GetYaxis()->SetLabelSize(0.05);
Pixel_Reset_4->GetXaxis()->SetRangeUser(PR4L,PR4H);
Pixel_Reset_4->GetXaxis()->SetNdivisions(6); 
Pixel_Reset_4->Draw();   
c1->SaveAs("Pixel_Reset_4.pdf");
c1->SaveAs("Pixel_Reset_4.png");    
FitFunc->SetParameter(1, Pixel_Reset_4->GetRMS());      
FitFunc->SetParameter(0, Pixel_Reset_4->GetMean()); 
FitFunc->Draw("SAME");  
c1->SaveAs("Pixel_Reset_4_Fit.pdf");
c1->SaveAs("Pixel_Reset_4_Fit.png");
c1->Clear();   
   
Pixel_Reset_5->GetXaxis()->CenterTitle(true);
Pixel_Reset_5->GetXaxis()->SetTitleSize(20);
Pixel_Reset_5->GetXaxis()->SetTitleFont(43);
Pixel_Reset_5->GetXaxis()->SetTitleOffset(1.5);
Pixel_Reset_5->GetXaxis()->SetLabelSize(0.05);
Pixel_Reset_5->GetYaxis()->SetTitleSize(20);
Pixel_Reset_5->GetYaxis()->SetTitleFont(43);
Pixel_Reset_5->GetYaxis()->SetLabelSize(0.05);
Pixel_Reset_5->GetXaxis()->SetRangeUser(PR5L,PR5H);
Pixel_Reset_5->GetXaxis()->SetNdivisions(6); 
Pixel_Reset_5->Draw();
c1->SaveAs("Pixel_Reset_5.pdf");
c1->SaveAs("Pixel_Reset_5.png");  
FitFunc->SetParameter(1, Pixel_Reset_5->GetRMS());      
FitFunc->SetParameter(0, Pixel_Reset_5->GetMean()); 
FitFunc->Draw("SAME");  
c1->SaveAs("Pixel_Reset_5_Fit.pdf");
c1->SaveAs("Pixel_Reset_5_Fit.png");
c1->Clear(); 
 
  for (int i=0; i < pix_num; i++){ 
  mean[i] = pix_res[i]->GetMean();   
  rms[i] =pix_res[i]->GetRMS();      
  } 
 
gr = new TGraph(pix_num,mean,rms);
gr->GetXaxis()->SetRangeUser(480,510);
gr->GetXaxis()->SetTitle("mean reset time [#mus]");   
gr->GetYaxis()->SetRangeUser(0,2);   
gr->GetYaxis()->SetTitle("rms [#mus]");  
gr->GetXaxis()->CenterTitle(true);
gr->GetXaxis()->SetTitleSize(20);
gr->GetXaxis()->SetTitleFont(43);
gr->GetXaxis()->SetTitleOffset(1.5);
gr->GetXaxis()->SetLabelSize(0.05);
gr->GetYaxis()->SetTitleSize(20);
gr->GetYaxis()->SetTitleFont(43);
gr->GetYaxis()->SetLabelSize(0.05);
gr->SetTitle("");
gr->SetMarkerColor(4);
gr->SetMarkerStyle(kFullDotMedium);   
gr->Draw("ap"); 
c1->SaveAs("Pixel_Reset_Scatterplot.pdf");
c1->SaveAs("Pixel_Reset_Scatterplot.png");

  for (int i=0; i < pix_num_3; i++){ 
  mean_3[i] = pix_res_3[i]->GetMean();   
  rms_3[i] =pix_res_3[i]->GetRMS();      
  } 
   
gr3 = new TGraph(pix_num_3,mean_3,rms_3);
gr3->GetXaxis()->SetRangeUser(480,510);
gr3->GetXaxis()->SetTitle("mean reset time [#mus]");   
gr3->GetYaxis()->SetRangeUser(0,2);   
gr3->GetYaxis()->SetTitle("rms [#mus]");  
gr3->GetXaxis()->CenterTitle(true);
gr3->GetXaxis()->SetTitleSize(20);
gr3->GetXaxis()->SetTitleFont(43);
gr3->GetXaxis()->SetTitleOffset(1.5);
gr3->GetXaxis()->SetLabelSize(0.05);
gr3->GetYaxis()->SetTitleSize(20);
gr3->GetYaxis()->SetTitleFont(43);
gr3->GetYaxis()->SetLabelSize(0.05);
gr3->SetTitle("");
gr3->SetMarkerColor(4);
gr3->SetMarkerStyle(kFullDotMedium);   
gr3->Draw("ap");
 
c1->SaveAs("Pixel_Reset_Scatterplot_Res3.pdf");
c1->SaveAs("Pixel_Reset_Scatterplot_Res3.png");
}
