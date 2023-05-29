#define PixelResetTime_cxx
#include "PixelResetTime.h"

#include <TH1D.h>
#include <TH2D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TF1.h>
#include <TLine.h>
#include <TH2.h>
#include <TStyle.h>

TH1D * Pixel_Reset_1 = nullptr;
TH1D * Pixel_Reset_2 = nullptr;
TH1D * Pixel_Reset_3 = nullptr;
TH1D * Pixel_Reset_4 = nullptr;
TH1D * Pixel_Reset_5 = nullptr;

TCanvas * c1 = nullptr;

void PixelResetTime::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void PixelResetTime::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();

Pixel_Reset_1 = new TH1D("qpixrtd events", "Pixel 1 Reset Frequency", 600, 470, 530);
Pixel_Reset_1->GetXaxis()->SetTitle("time (#mus)");
Pixel_Reset_1->GetYaxis()->SetTitle("Resets / (0.1 #mus)");
   
Pixel_Reset_2 = new TH1D("qpixrtd events", "Pixel 2 Reset Frequency", 600, 470, 530);
Pixel_Reset_2->GetXaxis()->SetTitle("time (#mus)");
Pixel_Reset_2->GetYaxis()->SetTitle("Resets / (0.1 #mus)");   
   
Pixel_Reset_3 = new TH1D("qpixrtd events", "Pixel 3 Reset Frequency", 600, 470, 530);
Pixel_Reset_3->GetXaxis()->SetTitle("time (#mus)");
Pixel_Reset_3->GetYaxis()->SetTitle("Resets / (0.1 #mus)");      
   
Pixel_Reset_4 = new TH1D("qpixrtd events", "Pixel 4 Reset Frequency", 600, 470, 530);
Pixel_Reset_4->GetXaxis()->SetTitle("time (#mus)");
Pixel_Reset_4->GetYaxis()->SetTitle("Resets / (0.1 #mus)");    
   
Pixel_Reset_5 = new TH1D("qpixrtd events", "Pixel 5 Reset Frequency", 600, 470, 530);
Pixel_Reset_5->GetXaxis()->SetTitle("time (#mus)");
Pixel_Reset_5->GetYaxis()->SetTitle("Resets / (0.1 #mus)");     
   
c1 = new TCanvas("canvas1", "Test Canvas1");   
}

Bool_t PixelResetTime::Process(Long64_t entry)
{

   GetEntry(entry);
  fReader.SetLocalEntry(entry);
   
         bool Event = (
       (*event == 0.)
       );  
   
   bool X_Val = (
      (*pixel_x[i] == 300)
      );
   
   bool Y_Val_1 = (
      (*pixel_y[i] == 10)
      );
 
      bool Y_Val_2 = (
      (*pixel_y[i] == 20)
      );
   
      bool Y_Val_3 = (
      (*pixel_y[i] == 30)
      );
   
      bool Y_Val_4 = (
      (*pixel_y[i] == 40)
      );
   
      bool Y_Val_5 = (
      (*pixel_y[i] == 50)
      );

      for (int i=0; i < pixel_reset.GetSize(); i++){
         for (int j=0; j <pixel_reset[i].GetSize(); j++){
        
            if (Event && X_Val && Y_Val_1){
                double tconv_pix1 = (pixel_reset[i][j]) * 1e+6; 
                Pixel_Reset_1->Fill(tconv_pix1);           
            }    

            if (Event && X_Val && Y_Val_2){
                double tconv_pix2 = (pixel_reset[i][j]) * 1e+6; 
                Pixel_Reset_2->Fill(tconv_pix2);           
            }     
            
            if (Event && X_Val && Y_Val_3){
                double tconv_pix3 = (pixel_reset[i][j]) * 1e+6; 
                Pixel_Reset_3->Fill(tconv_pix3);           
            }     
            
            if (Event && X_Val && Y_Val_4){
                double tconv_pix4 = (pixel_reset[i][j]) * 1e+6; 
                Pixel_Reset_4->Fill(tconv_pix4);           
            }  
            
            if (Event && X_Val && Y_Val_5){
                double tconv_pix5 = (pixel_reset[i][j]) * 1e+6; 
                Pixel_Reset_5->Fill(tconv_pix5);           
            }                  
      }
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

Pixel_Reset_1->GetXaxis()->CenterTitle(true);
Pixel_Reset_1->GetXaxis()->SetTitleSize(20);
Pixel_Reset_1->GetXaxis()->SetTitleFont(43);
Pixel_Reset_1->GetXaxis()->SetTitleOffset(1.5);
Pixel_Reset_1->GetXaxis()->SetLabelSize(0.05);
Pixel_Reset_1->GetYaxis()->SetTitleSize(20);
Pixel_Reset_1->GetYaxis()->SetTitleFont(43);
Pixel_Reset_1->GetYaxis()->SetLabelSize(0.05);
Pixel_Reset_1->Draw();
c1->SaveAs("Pixel_Reset_1.pdf");
c1->SaveAs("Pixel_Reset_1.png");
   
Pixel_Reset_2->GetXaxis()->CenterTitle(true);
Pixel_Reset_2->GetXaxis()->SetTitleSize(20);
Pixel_Reset_2->GetXaxis()->SetTitleFont(43);
Pixel_Reset_2->GetXaxis()->SetTitleOffset(1.5);
Pixel_Reset_2->GetXaxis()->SetLabelSize(0.05);
Pixel_Reset_2->GetYaxis()->SetTitleSize(20);
Pixel_Reset_2->GetYaxis()->SetTitleFont(43);
Pixel_Reset_2->GetYaxis()->SetLabelSize(0.05);
Pixel_Reset_2->Draw();
c1->SaveAs("Pixel_Reset_2.pdf");
c1->SaveAs("Pixel_Reset_2.png");
   
Pixel_Reset_3->GetXaxis()->CenterTitle(true);
Pixel_Reset_3->GetXaxis()->SetTitleSize(20);
Pixel_Reset_3->GetXaxis()->SetTitleFont(43);
Pixel_Reset_3->GetXaxis()->SetTitleOffset(1.5);
Pixel_Reset_3->GetXaxis()->SetLabelSize(0.05);
Pixel_Reset_3->GetYaxis()->SetTitleSize(20);
Pixel_Reset_3->GetYaxis()->SetTitleFont(43);
Pixel_Reset_3->GetYaxis()->SetLabelSize(0.05);
Pixel_Reset_3->Draw();
c1->SaveAs("Pixel_Reset_3.pdf");
c1->SaveAs("Pixel_Reset_3.png");   
   
Pixel_Reset_4->GetXaxis()->CenterTitle(true);
Pixel_Reset_4->GetXaxis()->SetTitleSize(20);
Pixel_Reset_4->GetXaxis()->SetTitleFont(43);
Pixel_Reset_4->GetXaxis()->SetTitleOffset(1.5);
Pixel_Reset_4->GetXaxis()->SetLabelSize(0.05);
Pixel_Reset_4->GetYaxis()->SetTitleSize(20);
Pixel_Reset_4->GetYaxis()->SetTitleFont(43);
Pixel_Reset_4->GetYaxis()->SetLabelSize(0.05);
Pixel_Reset_4->Draw();
c1->SaveAs("Pixel_Reset_4.pdf");
c1->SaveAs("Pixel_Reset_4.png");    

Pixel_Reset_5->GetXaxis()->CenterTitle(true);
Pixel_Reset_5->GetXaxis()->SetTitleSize(20);
Pixel_Reset_5->GetXaxis()->SetTitleFont(43);
Pixel_Reset_5->GetXaxis()->SetTitleOffset(1.5);
Pixel_Reset_5->GetXaxis()->SetLabelSize(0.05);
Pixel_Reset_5->GetYaxis()->SetTitleSize(20);
Pixel_Reset_5->GetYaxis()->SetTitleFont(43);
Pixel_Reset_5->GetYaxis()->SetLabelSize(0.05);
Pixel_Reset_5->Draw();
c1->SaveAs("Pixel_Reset_5.pdf");
c1->SaveAs("Pixel_Reset_5.png");  
}
