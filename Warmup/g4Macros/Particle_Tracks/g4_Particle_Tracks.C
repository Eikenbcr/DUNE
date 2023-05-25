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
   
   Track_XY_Init = new TH2D("qpixg4 events", "Initial Track Hits on X-Y Plane", 575, 0, 230, 1500, 0, 600);
   Track_XY_Init->GetXaxis()->SetTitle("X Position [cm]");
   Track_XY_Init->GetYaxis()->SetTitle("Y Position [cm]");
   Track_XY_Init-SetMarkerColor(kBlue);
   
   Track_XY_Fin = new TH2D("qpixg4 events", "Final Track Hits on X-Y Plane", 575, 0, 230, 1500, 0, 600);
   Track_XY_Fin->GetXaxis()->SetTitle("X Position [cm]]");
   Track_XY_Fin->GetYaxis()->SetTitle("Y Position [cm]");
   Track_XY_Fin-SetMarkerColor(kRed);      
   
   Track_XZ_Init = new TH2D("qpixg4 events", "Initial Track Hits on X-Z Plane", 575, 0, 230, 900, 0, 360);
   Track_XZ_Init->GetXaxis()->SetTitle("X Position [cm]");
   Track_XZ_Init->GetYaxis()->SetTitle("Z Position [cm]");
   Track_XZ_Init-SetMarkerColor(kBlue);
   
   Track_XZ_Fin = new TH2D("qpixg4 events", "Final Track Hits on X-Z Plane", 575, 0, 230, 900, 0, 360);
   Track_XZ_Fin->GetXaxis()->SetTitle("X Position [cm]]");
   Track_XZ_Fin->GetYaxis()->SetTitle("Z Position [cm]");
   Track_XZ_Fin-SetMarkerColor(kRed);   
   
   Track_YZ_Init = new TH2D("qpixg4 events", "Initial Track Hits on Y-Z Plane", 1500, 0, 600, 900, 0, 360);
   Track_YZ_Init->GetXaxis()->SetTitle("Y Position [cm]");
   Track_YZ_Init->GetYaxis()->SetTitle("Z Position [cm]");
   Track_YZ_Init-SetMarkerColor(kBlue);
   
   Track_YZ_Fin = new TH2D("qpixg4 events", "Final Track Hits on Y-Z Plane", 1500, 0, 600, 900, 0, 360);
   Track_YZ_Fin->GetXaxis()->SetTitle("Y Position [cm]]");
   Track_YZ_Fin->GetYaxis()->SetTitle("Z Position [cm]");
   Track_YZ_Fin-SetMarkerColor(kRed);   
   
   Track_XYZ_Init = new TH2D("qpixg4 events", "Initial Track Hits in 3D", 575, 0, 230, 1500, 0, 600, 900, 0, 360);
   Track_XYZ_Init->GetXaxis()->SetTitle("X Position [cm]");
   Track_XYZ_Init->GetYaxis()->SetTitle("Y Position [cm]");
   Track_XYZ_Init->GetZaxis()->SetTitle("Z Position [cm]");
   Track_XYZ_Init-SetMarkerColor(kBlue);
   
   Track_XYZ_Fin = new TH2D("qpixg4 events", "Final Track Hits in 3D", 575, 0, 230, 1500, 0, 600, 900, 0, 360);
   Track_XYZ_Fin->GetXaxis()->SetTitle("X Position [cm]]");
   Track_XYZ_Fin->GetYaxis()->SetTitle("Y Position [cm]");
   Track_XYZ_Fin->GetZaxis()->SetTitle("Z Position [cm]");
   Track_XYZ_Fin-SetMarkerColor(kRed);   
}

Bool_t g4_Particle_Tracks::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetLocalEntry(entry);

   return kTRUE;
}

void g4_Particle_Tracks::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void g4_Particle_Tracks::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
