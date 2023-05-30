#pragma once

#include "TMath.h"

// For ROOT, "main" function must have same name as file

Double_t Gaussian_fit(Double_t *v, Double_t *par) {

//  create a fitting function for a Gaussian signal
//Par[1]=MeanValue, Par[2]=StandardDeviation    
    Double_t arg = 0;
    if (par[2] != 0)
        arg = (v[0] - par[1])/par[2];

    //  create a Gaussian with width par[2] and mean par[1]
    Double_t fitval = TMath::Exp(-0.5*arg*arg);

    return fitval;
}
