//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed May 24 12:41:06 2023 by ROOT version 6.26/06
// from TTree event_tree/event tree
// found on file: /scratch/user/eikenbcr/DUNE/Warmup/muon_rtd.root
//////////////////////////////////////////////////////////

#ifndef Pixel_Study_h
#define Pixel_Study_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include <vector>



class Pixel_Study : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Int_t> run = {fReader, "run"};
   TTreeReaderValue<Int_t> event = {fReader, "event"};
   TTreeReaderValue<Int_t> generator_initial_number_particles = {fReader, "generator_initial_number_particles"};
   TTreeReaderArray<double> generator_initial_particle_x = {fReader, "generator_initial_particle_x"};
   TTreeReaderArray<double> generator_initial_particle_y = {fReader, "generator_initial_particle_y"};
   TTreeReaderArray<double> generator_initial_particle_z = {fReader, "generator_initial_particle_z"};
   TTreeReaderArray<double> generator_initial_particle_t = {fReader, "generator_initial_particle_t"};
   TTreeReaderArray<double> generator_initial_particle_px = {fReader, "generator_initial_particle_px"};
   TTreeReaderArray<double> generator_initial_particle_py = {fReader, "generator_initial_particle_py"};
   TTreeReaderArray<double> generator_initial_particle_pz = {fReader, "generator_initial_particle_pz"};
   TTreeReaderArray<double> generator_initial_particle_energy = {fReader, "generator_initial_particle_energy"};
   TTreeReaderArray<int> generator_initial_particle_pdg_code = {fReader, "generator_initial_particle_pdg_code"};
   TTreeReaderArray<double> generator_initial_particle_mass = {fReader, "generator_initial_particle_mass"};
   TTreeReaderArray<double> generator_initial_particle_charge = {fReader, "generator_initial_particle_charge"};
   TTreeReaderValue<Int_t> generator_final_number_particles = {fReader, "generator_final_number_particles"};
   TTreeReaderArray<double> generator_final_particle_x = {fReader, "generator_final_particle_x"};
   TTreeReaderArray<double> generator_final_particle_y = {fReader, "generator_final_particle_y"};
   TTreeReaderArray<double> generator_final_particle_z = {fReader, "generator_final_particle_z"};
   TTreeReaderArray<double> generator_final_particle_t = {fReader, "generator_final_particle_t"};
   TTreeReaderArray<double> generator_final_particle_px = {fReader, "generator_final_particle_px"};
   TTreeReaderArray<double> generator_final_particle_py = {fReader, "generator_final_particle_py"};
   TTreeReaderArray<double> generator_final_particle_pz = {fReader, "generator_final_particle_pz"};
   TTreeReaderArray<double> generator_final_particle_energy = {fReader, "generator_final_particle_energy"};
   TTreeReaderArray<int> generator_final_particle_pdg_code = {fReader, "generator_final_particle_pdg_code"};
   TTreeReaderArray<double> generator_final_particle_mass = {fReader, "generator_final_particle_mass"};
   TTreeReaderArray<double> generator_final_particle_charge = {fReader, "generator_final_particle_charge"};
   TTreeReaderValue<Int_t> number_particles = {fReader, "number_particles"};
   TTreeReaderValue<Int_t> number_hits = {fReader, "number_hits"};
   TTreeReaderValue<Double_t> energy_deposit = {fReader, "energy_deposit"};
   TTreeReaderArray<int> particle_track_id = {fReader, "particle_track_id"};
   TTreeReaderArray<int> particle_parent_track_id = {fReader, "particle_parent_track_id"};
   TTreeReaderArray<int> particle_pdg_code = {fReader, "particle_pdg_code"};
   TTreeReaderArray<double> particle_mass = {fReader, "particle_mass"};
   TTreeReaderArray<double> particle_charge = {fReader, "particle_charge"};
   TTreeReaderArray<int> particle_process_key = {fReader, "particle_process_key"};
   TTreeReaderArray<int> particle_total_occupancy = {fReader, "particle_total_occupancy"};
   TTreeReaderArray<double> particle_initial_x = {fReader, "particle_initial_x"};
   TTreeReaderArray<double> particle_initial_y = {fReader, "particle_initial_y"};
   TTreeReaderArray<double> particle_initial_z = {fReader, "particle_initial_z"};
   TTreeReaderArray<double> particle_initial_t = {fReader, "particle_initial_t"};
   TTreeReaderArray<double> particle_initial_px = {fReader, "particle_initial_px"};
   TTreeReaderArray<double> particle_initial_py = {fReader, "particle_initial_py"};
   TTreeReaderArray<double> particle_initial_pz = {fReader, "particle_initial_pz"};
   TTreeReaderArray<double> particle_initial_energy = {fReader, "particle_initial_energy"};
   TTreeReaderArray<int> particle_number_daughters = {fReader, "particle_number_daughters"};
   TTreeReaderArray<vector<int>> particle_daughter_track_id = {fReader, "particle_daughter_track_id"};
   TTreeReaderArray<int> hit_track_id = {fReader, "hit_track_id"};
   TTreeReaderArray<double> hit_start_x = {fReader, "hit_start_x"};
   TTreeReaderArray<double> hit_start_y = {fReader, "hit_start_y"};
   TTreeReaderArray<double> hit_start_z = {fReader, "hit_start_z"};
   TTreeReaderArray<double> hit_start_t = {fReader, "hit_start_t"};
   TTreeReaderArray<double> hit_end_x = {fReader, "hit_end_x"};
   TTreeReaderArray<double> hit_end_y = {fReader, "hit_end_y"};
   TTreeReaderArray<double> hit_end_z = {fReader, "hit_end_z"};
   TTreeReaderArray<double> hit_end_t = {fReader, "hit_end_t"};
   TTreeReaderArray<double> hit_energy_deposit = {fReader, "hit_energy_deposit"};
   TTreeReaderArray<double> hit_length = {fReader, "hit_length"};
   TTreeReaderArray<int> hit_process_key = {fReader, "hit_process_key"};
   TTreeReaderArray<int> pixel_x = {fReader, "pixel_x"};
   TTreeReaderArray<int> pixel_y = {fReader, "pixel_y"};
   TTreeReaderArray<vector<double>> pixel_reset = {fReader, "pixel_reset"};
   TTreeReaderArray<vector<double>> pixel_tslr = {fReader, "pixel_tslr"};
   TTreeReaderArray<vector<vector<int> >> pixel_reset_truth_track_id = {fReader, "pixel_reset_truth_track_id"};
   TTreeReaderArray<vector<vector<int> >> pixel_reset_truth_weight = {fReader, "pixel_reset_truth_weight"};


   Pixel_Study(TTree * /*tree*/ =0) { }
   virtual ~Pixel_Study() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(Pixel_Study,0);

};

#endif

#ifdef Pixel_Study_cxx
void Pixel_Study::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t Pixel_Study::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef Pixel_Study_cxx
