#define PixelResetTime_cxx
#include "PixelResetTime.h"

#include <TH2.h>
#include <TStyle.h>

void PixelResetTime::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void PixelResetTime::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();

}

Bool_t PixelResetTime::Process(Long64_t entry)
{

   fReader.SetLocalEntry(entry);

   return kTRUE;
}

void PixelResetTime::SlaveTerminate()
{


}

void PixelResetTime::Terminate()
{


}
