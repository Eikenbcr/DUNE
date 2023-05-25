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

TH2D * Track_XY = nullptr;
TH2D * Track_XZ = nullptr;
TH2D * Track_YZ = nullptr;
TH3D * Track_XYZ = nullptr;

void g4_Particle_Tracks::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void g4_Particle_Tracks::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();
   
   Track_XY = new TH2D("qpixg4 events", "Muon Track X-Y Plane", 20, 119, 121, 20, -1, 1);
   Track_XY->GetXaxis()->SetTitle("X Coordinate [pixel]");
   Track_XY->GetYaxis()->SetTitle("Y Coordinate [pixel]");
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
