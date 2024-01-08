#define MyClass_cxx
#include "MyClass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include "tabulate.hpp"
#include "TLorentzVector.h"

#include <iostream>
#include <fstream>
#include <string>

double getDeltaR(TLorentzVector vec_1, TLorentzVector vec_2);

void MyClass::Loop()
{
  if (fChain == 0)
    return;
  //TString file_name = "analysis_ZHToAATo4B_M20.root";
  TString file_name = "Analysis_TTToHadronic.root";
  //TString file_name = "DY4JetsToLL_M-50_MatchEWPDG20.root";
  //TString file_name = "WHToAATo4B_M20.root";

  Long64_t nentries = fChain->GetEntriesFast();

  //----Histograms------------------------
  
  
  // leptons

      //control plots
  TH1F *h_en_mult = new TH1F("en_mult", "electrons", 5, 0, 5);
  TH1F *h_mn_mult = new TH1F("mn_mult", "muons", 5, 0, 5);
  TH1F *h_lepton_mult = new TH1F("lepton_mult", "leptons", 5, 0, 5);

  //Multiplicities after cuts
  TH1F *h_en_mult_after = new TH1F("en_mult_after", "electrons", 5, 0, 5);
  TH1F *h_mn_mult_after = new TH1F("mn_mult_after", "muons", 5, 0, 5);
  TH1F *h_jet_mult_after = new TH1F("jet_mult_after", "Jets", 10, 0, 10);
  TH1F *h_fjet_mult_after = new TH1F("fjet_mult_after", "fjets", 10, 0, 10);
  TH1F *h_sv_mult_after = new TH1F("sv_mult_after", "SV's", 10, 0, 10);

  TH1F *h_en1_pt = new TH1F("h_en1_pt", "en1_pt", 100, 0, 500);
  TH1F *h_en1_eta= new TH1F("h_en1_eta", "en1_eta", 100, -5, 5);
  TH1F *h_en1_phi= new TH1F("h_en1_phi", "en1_phi", 100, -TMath::Pi(), TMath::Pi());

  TH1F *h_en2_pt = new TH1F("h_en2_pt", "en2_pt", 100, 0, 500);
  TH1F *h_en2_eta= new TH1F("h_en2_eta", "en2_eta", 100, -5, 5);
  TH1F *h_en2_phi= new TH1F("h_en2_phi", "en2_phi", 100, -TMath::Pi(), TMath::Pi());

  TH1F *h_mn1_pt = new TH1F("h_mn1_pt", "mn1_pt", 100, 0, 500);
  TH1F *h_mn1_eta = new TH1F("h_mn1_eta", "mn1_eta", 100, -5, 5);
  TH1F *h_mn1_phi = new TH1F("h_mn1_phi","muon1 phi",100,-TMath::Pi(),TMath::Pi());
  TH1F *h_mn2_pt = new TH1F("h_mn2_pt", "mn2_pt", 100, 0, 500);
  TH1F *h_mn2_eta = new TH1F("h_mn2_eta", "mn2_eta", 100, -5, 5);
  TH1F *h_mn2_phi = new TH1F("h_mn2_phi","muon2 phi",100,-TMath::Pi(),TMath::Pi());

  // jets
  TH1F *h_jet_mult = new TH1F("jet_mult", "Jets", 10, 0, 10);

  TH1F *h_jet1_pt = new TH1F("h_jet1_pt", "jet1_pt", 100, 0, 500);
  TH1F *h_jet1_eta = new TH1F("h_jet1_eta", "jet1_eta", 100,-5, 5);
  TH1F *h_jet1_phi = new TH1F("h_jet1_phi", "jet1_phi", 100,-TMath::Pi(),TMath::Pi());

  TH1F *h_jet2_pt = new TH1F("h_jet2_pt", "jet2_pt", 100, 0, 500);
  TH1F *h_jet2_eta = new TH1F("h_jet2_eta", "jet2_eta", 100,-5, 5);
  TH1F *h_jet2_phi = new TH1F("h_jet2_phi", "jet2_phi", 100,-TMath::Pi(),TMath::Pi());

  TH1F *h_jet3_pt = new TH1F("h_jet3_pt", "jet3_pt", 100, 0, 500);
  TH1F *h_jet3_eta = new TH1F("h_jet3_eta", "jet3_eta", 100,-5, 5);
  TH1F *h_jet3_phi = new TH1F("h_jet3_phi", "jet3_phi", 100,-TMath::Pi(),TMath::Pi());

  TH1F *h_jet4_pt = new TH1F("h_jet4_pt", "jet4_pt", 100, 0, 500);
  TH1F *h_jet4_eta = new TH1F("h_jet4_eta", "jet4_eta", 100,-5, 5);
  TH1F *h_jet4_phi = new TH1F("h_jet4_phi", "jet4_phi", 100,-TMath::Pi(),TMath::Pi());
  // fjets
  TH1F *h_fjet_mult = new TH1F("fjet_mult", "fjets", 10, 0, 10);

  TH1F *h_fjet1_pt = new TH1F("h_fjet1_pt", "fjet1_pt", 100, 0, 500);
  TH1F *h_fjet1_eta = new TH1F("h_fjet1_eta", "fjet1_eta", 100, -5, 5);
  TH1F *h_fjet1_phi = new TH1F("h_fjet1_phi", "fjet1_phi", 100,-TMath::Pi(),TMath::Pi());

  TH1F *h_fjet2_pt = new TH1F("h_fjet2_pt", "fjet2_pt", 100, 0, 500);
  TH1F *h_fjet2_eta = new TH1F("h_fjet2_eta", "fjet2_eta", 100, -5, 5);
  TH1F *h_fjet2_phi = new TH1F("h_fjet2_phi", "fjet2_phi", 100,-TMath::Pi(),TMath::Pi());
  // sv
  TH1F *h_sv_mult = new TH1F("sv_mult", "sv", 10, 0, 10);

  //TH1F *h_sv_ntrk = new TH1F("sv_ntrk", "n tracks", 20, 0, 20);
  TH1F *h_sv_pt = new TH1F("sv_pt", "SV pt", 100, 0, 500);
  TH1F *h_sv_eta = new TH1F("sv_eta", "SV eta", 100, -5, 5);
  TH1F *h_sv_phi = new TH1F("sv_phi", "SV phi", 100, -5, 5);

  //------Histograms -END ----------------

  //------Event Counters-------------
  Int_t n_event_lepton_test = 0;
  Int_t n_event_jet_test = 0;
  Int_t n_event_fjet_test = 0;
  Int_t n_event_Total = 0;


  //---------------------------------

  // ------ Start event loop---------------
  for (Long64_t jentry = 0; jentry < nentries; jentry++)
  {
    GetEntry(jentry);

    std::vector<TLorentzVector> vec_sv;
    std::vector<TLorentzVector> vec_jet;
    std::vector<TLorentzVector> vec_fjets;
    std::vector<TLorentzVector> vec_bjets;

    // Leptons
    std::vector<TLorentzVector> vec_muons;
    std::vector<TLorentzVector> vec_ele;

    for (int i = 0; i < mn; i++)
    {
      TLorentzVector p_muon;
      p_muon.SetPxPyPzE(mn_px[i], mn_py[i], mn_pz[i], mn_en[i]);

      if (p_muon.Pt() < 20. || std::fabs(p_muon.Eta()) > 2.4)
         continue;

      // id + Isolation
      if (mn_passId[i] && mn_passIso[i])
      {
        vec_muons.push_back(p_muon);
      }
    }

    for (int i = 0; i < en; i++)
    {
      TLorentzVector p_electron;
      p_electron.SetPxPyPzE(en_px[i], en_py[i], en_pz[i], en_en[i]);

      if (p_electron.Pt() < 20. || std::fabs(p_electron.Eta()) > 2.4)
         continue;

      if (en_passId[i] && en_passIso[i])
      {
        vec_ele.push_back(p_electron);
      }
    }
    // jets & cross cleaning
    for (int i = 0; i < jet; i++)
    {
      bool overlap = false;
      double dR1 = 0;

      TLorentzVector p_jet;
      p_jet.SetPxPyPzE(jet_px[i], jet_py[i], jet_pz[i], jet_en[i]);

      if (p_jet.Pt() < 20. || std::fabs(p_jet.Eta()) > 2.5)
        continue;
      for (int mn_count = 0; mn_count < vec_muons.size(); mn_count++)
      {
        dR1 = getDeltaR(p_jet, vec_muons[mn_count]);
        if (dR1 < 0.4)
          overlap = true;
      }

      for (int en_count = 0; en_count < vec_ele.size(); en_count++)
      {
        dR1 = getDeltaR(p_jet, vec_ele[en_count]);
        if (getDeltaR(p_jet, vec_ele[en_count]) < 0.4)
          overlap = true;
      }

      if (!overlap)
        vec_jet.push_back(p_jet);

      // if (jet_btag1[i] > 0.6)
      // {
      //   vec_bjets.push_back(p_jet);
      // }
    }

    // fat jets
    for (int i = 0; i < fjet; i++)
    {
      TLorentzVector p_fjet;
      p_fjet.SetPxPyPzE(fjet_px[i], fjet_py[i], fjet_pz[i], fjet_en[i]);

      if (p_fjet.Pt() < 30 || std::fabs(p_fjet.Eta()) > 2.5)
        continue;

      vec_fjets.push_back(p_fjet);
    }

    // secondary vertices
    for (int i = 0; i < sv; i++)
    {
      TLorentzVector p_sv;
      p_sv.SetPxPyPzE(sv_px[i], sv_py[i], sv_pz[i], sv_en[i]);

      if (sv_ntrk[i] <= 2 || sv_dxy[i] < 3 || sv_cos_dxyz_p[i] < 0.98 || sv_dxyz_signif[i] < 3)
        continue;

      // check deltaR with Jets
      for (int jet_count = 0; jet_count < jet; jet_count++)
      {
        TLorentzVector p_jet;
        p_jet.SetPxPyPzE(jet_px[jet_count], jet_py[jet_count], jet_pz[jet_count], jet_en[jet_count]);

        double deltaR;
        deltaR = getDeltaR(p_sv, p_jet);

        if (deltaR < 0.4)
          continue;
      }
      vec_sv.push_back(p_sv);
    }
    //-----End config ------------

    // ----- cut and count -------
    // control plots mult, pt, eta, phi
    h_en_mult->Fill(vec_ele.size());
    h_mn_mult->Fill(vec_muons.size());
    h_lepton_mult->Fill(vec_ele.size() + vec_muons.size());

    h_jet_mult->Fill(vec_jet.size());
    h_fjet_mult->Fill(vec_fjets.size());

    h_sv_mult->Fill(vec_sv.size());

    // lepton cuts---------------------------------------------------
    // no of leptons = 0 & nlepton = 1

    if (vec_ele.size() + vec_muons.size() == 0)
      continue;

    n_event_lepton_test++;
    // ele kinematics pt, eta, phi  e[1]
    if (vec_ele.size() > 0)
    {
      h_en1_pt->Fill(vec_ele[0].Pt());
      h_en1_eta->Fill(vec_ele[0].Eta());
      h_en1_phi->Fill(vec_ele[0].Phi());
    }
    if (vec_ele.size() > 1)
    {
      h_en2_pt->Fill(vec_ele[1].Pt());
      h_en2_eta->Fill(vec_ele[1].Eta());
      h_en2_phi->Fill(vec_ele[1].Phi());
    }

    if (vec_muons.size() > 0)
    {
      h_mn1_pt->Fill(vec_muons[0].Pt());
      h_mn1_eta->Fill(vec_muons[0].Eta());
      h_mn1_phi->Fill(vec_muons[0].Phi());
    }
    if (vec_muons.size() > 1)
    {
      h_mn2_pt->Fill(vec_muons[1].Pt());
      h_mn2_eta->Fill(vec_muons[1].Eta());
      h_mn2_phi->Fill(vec_muons[1].Phi());
    }

//---------------JET CUTS ------------------------------------------------
    if (vec_jet.size() < 1)
      continue;
    n_event_jet_test++;

    if (vec_fjets.size() <=1)
      continue;
    n_event_fjet_test++;

    if (vec_jet.size() > 0)
    {
      h_jet1_pt->Fill(vec_jet[0].Pt());
      h_jet1_eta->Fill(vec_jet[0].Eta());
      h_jet1_phi->Fill(vec_jet[0].Phi());
    }
    if (vec_jet.size() > 1)
    {
      h_jet2_pt->Fill(vec_jet[1].Pt());
      h_jet2_eta->Fill(vec_jet[1].Eta());
      h_jet2_phi->Fill(vec_jet[1].Phi());
    }
    if (vec_jet.size() > 2)
    {
      h_jet3_pt->Fill(vec_jet[2].Pt());
      h_jet3_eta->Fill(vec_jet[2].Eta());
      h_jet3_phi->Fill(vec_jet[2].Phi());
    }
    if (vec_jet.size() > 3)
    {
      h_jet4_pt->Fill(vec_jet[3].Pt());
      h_jet4_eta->Fill(vec_jet[3].Eta());
      h_jet4_phi->Fill(vec_jet[3].Phi());
    }

    if (vec_fjets.size() > 0)
    {
      h_fjet1_pt->Fill(vec_fjets[0].Pt());
      h_fjet1_eta->Fill(vec_fjets[0].Eta());
      h_fjet1_phi->Fill(vec_fjets[0].Phi());
    }
    if (vec_fjets.size() > 1)
    {
      h_fjet2_pt->Fill(vec_fjets[1].Pt());
      h_fjet2_eta->Fill(vec_fjets[1].Eta());
      h_fjet2_phi->Fill(vec_fjets[1].Phi());
    }

    if (vec_sv.size()>0)
    {
      h_sv_pt->Fill(vec_sv[0].Pt());
      h_sv_eta->Fill(vec_sv[0].Eta());
      h_sv_phi->Fill(vec_sv[0].Phi());
    }
    //plots pt, eta, phi
    // signal bg superimposed
    
    // number of events after cuts
    n_event_Total++;

    h_mn_mult_after   ->Fill(vec_muons.size());
    h_en_mult_after   ->Fill(vec_ele.size());
    h_jet_mult_after  ->Fill(vec_jet.size());
    h_fjet_mult_after ->Fill(vec_fjets.size());
    h_sv_mult_after   ->Fill(vec_sv.size());

  }

  std::cout << "number of events: " << nentries << std::endl;

  tabulate::Table cut_flow_table;
  cut_flow_table.add_row({"Requirements", "No. of Events", "Passed/Total 100%"});
  cut_flow_table.add_row({"Raw events", std::to_string(nentries), "100%"});
  cut_flow_table.add_row({"N Leptons > 0, ", std::to_string(n_event_lepton_test), std::to_string(100 * ((float)n_event_lepton_test) / (float)nentries) + "%"});
  cut_flow_table.add_row({"N jet > 1", std::to_string(n_event_jet_test), std::to_string(100 * ((float)n_event_jet_test) / (float)nentries) + "%"});
  cut_flow_table.add_row({"N fjet > 2", std::to_string(n_event_fjet_test), std::to_string(100 * ((float)n_event_fjet_test) / (float)nentries) + "%"});

  std::cout << cut_flow_table << std::endl;
  
  // std::ofstream out_file(file_name+".csv");
	// out_file<< "Cuts," << "No. of events," << "Efficiency" <<std::endl;
	// out_file << "(raw)," << nentries << ","<< nentries/nentries * 100 <<std::endl;
	// out_file << "jet cut," << n_event_jet_test << ","<< (float)n_event_jet_test/(float)nentries*100<<std::endl;
	// out_file << "fjet cut," << n_event_fjet_test << ","<< (float)n_event_fjet_test/(float)nentries*100 <<std::endl;
	// out_file << "sv cut," << n_event_Total <<","<< (float)n_event_Total/(float)nentries*100<<std::endl;

	// out_file.close();


  TFile ff("histos" + file_name, "RECREATE");
  //control plots
  h_en_mult->Write();
  h_mn_mult->Write();
  h_jet_mult->Write();
  h_fjet_mult->Write();
  h_sv_mult->Write();

//----lepton cuts
  h_en1_pt->Write();
  h_en1_eta->Write();
  h_en1_phi->Write();
  h_en2_pt->Write();
  h_en2_eta->Write();
  h_en2_phi->Write();

  h_mn1_pt->Write();
  h_mn1_eta->Write();
  h_mn1_phi->Write();
  h_mn2_pt->Write();
  h_mn2_eta->Write();
  h_mn2_phi->Write();
  // jet cuts--------

  h_jet1_pt->Write();
  h_jet1_eta->Write();
  h_jet1_phi->Write();
  h_jet2_pt->Write();
  h_jet2_eta->Write();
  h_jet2_phi->Write();
  h_jet3_pt->Write();
  h_jet3_eta->Write();
  h_jet3_phi->Write();
  h_jet4_pt->Write();
  h_jet4_eta->Write();
  h_jet4_phi->Write();

  h_fjet1_pt->Write();
  h_fjet1_eta->Write();
  h_fjet1_phi->Write();

  h_fjet2_pt->Write();
  h_fjet2_eta->Write();
  h_fjet2_phi->Write();

  h_sv_pt->Write();
  h_sv_eta->Write();
  h_sv_phi->Write();

  h_mn_mult_after->Write();
  h_en_mult_after->Write();
  h_jet_mult_after->Write();
  h_fjet_mult_after->Write();
  h_sv_mult_after->Write();
}

double getDeltaR(TLorentzVector vec_1, TLorentzVector vec_2)
{
  double delta_phi;
  double delta_eta;

  delta_phi = vec_1.Phi() - vec_2.Phi();
  delta_eta = vec_1.Eta() - vec_2.Eta();

  return std::sqrt(delta_phi * delta_phi + delta_eta * delta_eta);
}