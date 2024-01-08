#include <TH2.h>
#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <iostream>
#include <vector>
#include <TFile.h>
#include <TLorentzVector.h>

#include <iostream>
#include <fstream>
#include <string>

void print_histos()
{
    TFile ff_1("histosanalysis_ZHToAATo4B_M20.root");
    TFile ff_2("histosDY4JetsToLL_M-50_MatchEWPDG20.root");

    TFile ff("histos.root", "RECREATE");
    TH1F *hh_1_en = (TH1F *)ff_1.Get("en_mult_after");
    TH1F *hh_2_en = (TH1F *)ff_2.Get("en_mult_after");

    TH1F *hh_1_mn = (TH1F *)ff_1.Get("mn_mult_after");
    TH1F *hh_2_mn = (TH1F *)ff_2.Get("mn_mult_after");

    TH1F *hh_1_jet = (TH1F *)ff_1.Get("jet_mult_after");
    TH1F *hh_2_jet = (TH1F *)ff_2.Get("jet_mult_after");

    TH1F *hh_1_fjet = (TH1F *)ff_1.Get("fjet_mult_after");
    TH1F *hh_2_fjet = (TH1F *)ff_2.Get("fjet_mult_after");

    TH1F *hh_1_sv = (TH1F *)ff_1.Get("sv_mult_after");
    TH1F *hh_2_sv = (TH1F *)ff_2.Get("sv_mult_after");

    Int_t b_max1 = 0;
    Double_t y_max1 = 0;

    Int_t b_max2 = 0;
    Double_t y_max2 = 0;

    Double_t y_max_total =0;

    TCanvas *c_en = new TCanvas("en_mult", "en_multiplicity", 800, 600);
    
    hh_1_en->Scale(1.0 / hh_1_en->Integral());
    hh_2_en->Scale(1.0 / hh_2_en->Integral());

    b_max1 = hh_1_en->GetMaximumBin();
    y_max1 = hh_1_en->GetBinContent(b_max1);

    b_max2 = hh_2_en->GetMaximumBin();
    y_max2 = hh_2_en->GetBinContent(b_max2);

    y_max_total = y_max2;
    if (y_max1 >= y_max2)
        y_max_total = y_max1;

    hh_1_en->SetAxisRange(0, y_max_total + 0.1 * y_max_total, "Y");

    hh_1_en->SetLineWidth(3);
    hh_2_en->SetLineWidth(3);

    hh_1_en->SetLineColor(kBlue);
    hh_2_en->SetLineColor(kRed);

    hh_1_en->Draw("HIST");
    gStyle->SetOptStat(1);

    hh_2_en->Draw("HIST sames");
    gPad->Update();

    TLegend *legend_en = new TLegend(0.8, 0.7, 0.9, 0.9);
    legend_en->AddEntry(hh_1_en, "ZHToAATo4b", "l"); // ναμε οφ προψεσ
    legend_en->AddEntry(hh_2_en, "DY4JetsToLL", "l");
    legend_en->Draw();
    c_en->Write();

    TCanvas *c_mn = new TCanvas("mn_mult", "mn_multiplicity", 800, 600);
    
    hh_1_mn->Scale(1.0 / hh_1_mn->Integral());
    hh_2_mn->Scale(1.0 / hh_2_mn->Integral());

    b_max1 = hh_1_mn->GetMaximumBin();
    y_max1 = hh_1_mn->GetBinContent(b_max1);

    b_max2 = hh_2_mn->GetMaximumBin();
    y_max2 = hh_2_mn->GetBinContent(b_max2);

    y_max_total = y_max2;
    if (y_max1 >= y_max2)
        y_max_total = y_max1;

    hh_1_mn->SetAxisRange(0, y_max_total + 0.1 * y_max_total, "Y");

    hh_1_mn->SetLineWidth(3);
    hh_2_mn->SetLineWidth(3);

    hh_1_mn->SetLineColor(kBlue);
    hh_2_mn->SetLineColor(kRed);

    hh_1_mn->Draw("HIST");
    gStyle->SetOptStat(1);

    hh_2_mn->Draw("HIST sames");
    gPad->Update();

    TLegend *legend_mn = new TLegend(0.8, 0.7, 0.9, 0.9);
    legend_mn->AddEntry(hh_1_mn, "ZHToAATo4b", "l"); // ναμε οφ προψεσ
    legend_mn->AddEntry(hh_2_mn, "DY4JetsToLL", "l");
    legend_mn->Draw();
    c_mn->Write();

    //------------------jets--------------------------
    TCanvas *c_jet = new TCanvas("jet_mult", "jet_multiplicity", 800, 600);
    
    hh_1_jet->Scale(1.0 / hh_1_jet->Integral());
    hh_2_jet->Scale(1.0 / hh_2_jet->Integral());

    b_max1 = hh_1_jet->GetMaximumBin();
    y_max1 = hh_1_jet->GetBinContent(b_max1);

    b_max2 = hh_2_jet->GetMaximumBin();
    y_max2 = hh_2_jet->GetBinContent(b_max2);

    y_max_total = y_max2;
    if (y_max1 >= y_max2)
        y_max_total = y_max1;

    hh_1_jet->SetAxisRange(0, y_max_total + 0.1 * y_max_total, "Y");

    hh_1_jet->SetLineWidth(3);
    hh_2_jet->SetLineWidth(3);

    hh_1_jet->SetLineColor(kBlue);
    hh_2_jet->SetLineColor(kRed);

    hh_1_jet->Draw("HIST");
    gStyle->SetOptStat(1);

    hh_2_jet->Draw("HIST sames");
    gPad->Update();

    TLegend *legend_jet = new TLegend(0.8, 0.7, 0.9, 0.9);
    legend_jet->AddEntry(hh_1_jet, "ZHToAATo4b", "l"); // ναμε οφ προψεσ
    legend_jet->AddEntry(hh_2_jet, "DY4JetsToLL", "l");
    legend_jet->Draw();
    c_jet->Write();

        //------------------fat jets--------------------------
    TCanvas *c_fjet = new TCanvas("fjet_mult", "fjet_multiplicity", 800, 600);
    
    hh_1_fjet->Scale(1.0 / hh_1_fjet->Integral());
    hh_2_fjet->Scale(1.0 / hh_2_fjet->Integral());

    b_max1 = hh_1_fjet->GetMaximumBin();
    y_max1 = hh_1_fjet->GetBinContent(b_max1);

    b_max2 = hh_2_fjet->GetMaximumBin();
    y_max2 = hh_2_fjet->GetBinContent(b_max2);

    y_max_total = y_max2;
    if (y_max1 >= y_max2)
        y_max_total = y_max1;

    hh_1_fjet->SetAxisRange(0, y_max_total + 0.1 * y_max_total, "Y");

    hh_1_fjet->SetLineWidth(3);
    hh_2_fjet->SetLineWidth(3);

    hh_1_fjet->SetLineColor(kBlue);
    hh_2_fjet->SetLineColor(kRed);

    hh_1_fjet->Draw("HIST");
    gStyle->SetOptStat(1);

    hh_2_fjet->Draw("HIST sames");
    gPad->Update();

    TLegend *legend_fjet = new TLegend(0.8, 0.7, 0.9, 0.9);
    legend_fjet->AddEntry(hh_1_fjet, "ZHToAATo4b", "l"); // ναμε οφ προψεσ
    legend_fjet->AddEntry(hh_2_fjet, "DY4JetsToLL", "l");
    legend_fjet->Draw();
    c_fjet->Write();

            //------------------secondary vertices --------------------------
    TCanvas *c_sv = new TCanvas("sv_mult", "sv_multiplicity", 800, 600);
    
    hh_1_sv->Scale(1.0 / hh_1_sv->Integral());
    hh_2_sv->Scale(1.0 / hh_2_sv->Integral());

    b_max1 = hh_1_sv->GetMaximumBin();
    y_max1 = hh_1_sv->GetBinContent(b_max1);

    b_max2 = hh_2_sv->GetMaximumBin();
    y_max2 = hh_2_sv->GetBinContent(b_max2);

    y_max_total = y_max2;
    if (y_max1 >= y_max2)
        y_max_total = y_max1;

    hh_1_sv->SetAxisRange(0, y_max_total + 0.1 * y_max_total, "Y");

    hh_1_sv->SetLineWidth(3);
    hh_2_sv->SetLineWidth(3);

    hh_1_sv->SetLineColor(kBlue);
    hh_2_sv->SetLineColor(kRed);

    hh_1_sv->Draw("HIST");
    gStyle->SetOptStat(1);

    hh_2_sv->Draw("HIST sames");
    gPad->Update();

    TLegend *legend_sv = new TLegend(0.8, 0.7, 0.9, 0.9);
    legend_sv->AddEntry(hh_1_sv, "ZHToAATo4b", "l"); // ναμε οφ προψεσ
    legend_sv->AddEntry(hh_2_sv, "DY4JetsToLL", "l");
    legend_sv->Draw();
    c_sv->Write();

    // std::string count = std::to_string(i) + ".png";
    // TString file_name = count.c_str();

    // c->SaveAs(file_name);
    ff.Close();
}