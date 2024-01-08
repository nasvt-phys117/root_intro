#include <cstdlib>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <typeinfo>

#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"
#include "TObject.h"
#include "TTimeStamp.h"
#include "TLeaf.h"
#include "TH1.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TMath.h"
#include "TEfficiency.h"
#include "TPaveStats.h"

#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TArrow.h"
#include "TLatex.h"
#include "TRandom.h"
#include "TPaveText.h"

#include "TApplication.h"

#include "TKey.h"
#include "TBranchRef.h"
#include "TMemFile.h"

void print_histos()
{
    TFile ff_1("histosWHToAATo4B_M20.root");
    TFile ff_2("histosAnalysis_TTToHadronic.root");
    
    //TFile ff_1("histosanalysis_ZHToAATo4B_M20.root");
    //TFile ff_2("histosDY4JetsToLL_M-50_MatchEWPDG20.root");

    int num_of_hists_1 = ff_1.GetListOfKeys()->GetSize();
    int num_of_hists_2 = ff_2.GetListOfKeys()->GetSize();

    if (num_of_hists_1 != num_of_hists_2)
        return;
    int i = 0;
    TFile ff("histos.root", "RECREATE");
    TH1F *hh_1[num_of_hists_1];
    TH1F *hh_2[num_of_hists_1];
    TCanvas *c[num_of_hists_1];

    for (TKey *key : ROOT::RangeStaticCast<TKey *>(*ff_1.GetListOfKeys()))
    {
        hh_1[i] = (TH1F *)ff_1.Get(key->GetName());
        hh_2[i] = (TH1F *)ff_2.Get(key->GetName());
        c[i] = new TCanvas(hh_1[i]->GetName(), hh_1[i]->GetName(),800, 600);
        hh_1[i]->Scale(1.0 / hh_1[i]->Integral());
        hh_2[i]->Scale(1.0 / hh_2[i]->Integral());

        Int_t b_max1 = hh_1[i]->GetMaximumBin();
        Double_t y_max1 = hh_1[i]->GetBinContent(b_max1);

        Int_t b_max2 = hh_2[i]->GetMaximumBin();
        Double_t y_max2 = hh_2[i]->GetBinContent(b_max2);

        Double_t y_max_total = y_max2;
        if (y_max1 >= y_max2)
            y_max_total = y_max1;

        hh_1[i]->SetAxisRange(0,y_max_total + 0.1*y_max_total, "Y");

        hh_1[i]->SetLineWidth(3);
        hh_2[i]->SetLineWidth(3);

        hh_1[i]->SetLineColor(kBlue);
        hh_2[i]->SetLineColor(kRed);

        hh_1[i]->Draw("HIST");
        gStyle->SetOptStat(1);

        hh_2[i]->Draw("HIST sames");
        gPad->Update();

        TLegend *legend = new TLegend(0.8, 0.7, 0.9, 0.9);
        legend->AddEntry(hh_1[i], "WHToAATo4b", "l"); // ναμε οφ προψεσ
        legend->AddEntry(hh_2[i], "TTToHadronic", "l");

        //legend->AddEntry(hh_1[i], "ZHToAATo4B", "l"); // ναμε οφ προψεσ
        //legend->AddEntry(hh_2[i], "DY4JetsToLL", "l");
        legend->Draw();
        c[i]->Write();
        i++;

        // std::string count = std::to_string(i) + ".png";
        // TString file_name = count.c_str();

        //c->SaveAs(file_name);
    }
    ff.Close();
}