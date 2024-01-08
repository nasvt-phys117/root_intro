#define MyClass_cxx
#include "MyClass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

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

#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TArrow.h"
#include "TLatex.h"
#include "TRandom.h"
#include "TPaveText.h"

#include "TApplication.h"

#include "TLorentzVector.h"

#include "TKey.h"
#include "TBranchRef.h"
#include "TMemFile.h"

void MyClass::Loop()
{
   //   In a ROOT session, you can do:
   //      root> .L MyClass.C
   //      root> MyClass t
   //      root> t.GetEntry(12); // Fill t data members with entry number 12
   //      root> t.Show();       // Show values of entry 12
   //      root> t.Show(16);     // Read and show values of entry 16
   //      root> t.Loop();       // Loop on all entries
   //

   //     This is the loop skeleton where:
   //    jentry is the global entry number in the chain
   //    ientry is the entry number in the current Tree
   //  Note that the argument to GetEntry must be:
   //    jentry for TChain::GetEntry
   //    ientry for TTree::GetEntry and TBranch::GetEntry
   //
   //       To read only selected branches, Insert statements like:
   // METHOD1:
   //    fChain->SetBranchStatus("*",0);  // disable all branches
   //    fChain->SetBranchStatus("branchname",1);  // activate branchname
   // METHOD2: replace line
   //    fChain->GetEntry(jentry);       //read all branches
   // by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0)
      return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;

   // HISTOGRAMS
   TH1F *h_mn_px = new TH1F("h_mn_px", "mn_px", 200, -200, 200);
   TH1F *h_mn_py = new TH1F("h_mn_py", "mn_py", 200, -200, 200);
   TH1F *h_mn_pz = new TH1F("h_mn_pz", "mn_pz", 200, -200, 200);

   TH1F *h_mn_en = new TH1F("h_mn_en", "mn_en", 100, 0, 200);
   TH1F *h_mn_id = new TH1F("h_mn_id", "mn_id", 100, -50, 50);
   TH1F *h_mn_type = new TH1F("h_mn_type", "mn_type", 100, 0, 150);

   TH1F *h_mn_passId = new TH1F("h_mn_passId", "mn_passId", 100, -50, 50);
   TH1F *h_mn_passIdLoose = new TH1F("h_mn_passIdLoose", "mn_passIdLoose", 100, -10, 10);
   TH1F *h_mn_passSoftMuon = new TH1F("h_mn_passSoftMuon", "mn_passSoftMuon", 100, -10, 10);

   TH1F *h_mn_passIso = new TH1F("h_mn_passIso", "mn_passIso", 100, -10, 10);
   TH1F *h_mn_relIso = new TH1F("h_mn_relIso", "mn_relIso", 100, -10, 250);
   TH1F *h_mn_trkrelIso = new TH1F("h_mn_trkrelIso", "mn_trkrelIso", 100, -10, 50);

   TH1F *h_mn_validMuonHits = new TH1F("h_mn_validMuonHits", "mn_validMuonHits", 100, 0, 100);
   TH1F *h_mn_trkLayersWithMeasurement = new TH1F("h_mn_trkLayersWithMeasurement", "mn_trkLayersWithMeasurement", 100, 0, 50);
   TH1F *h_mn_pixelLayersWithMeasurement = new TH1F("h_mn_pixelLayersWithMeasurement", "mn_pixelLayersWithMeasurement", 100, 0, 50);

   // New histograms (added by GEORGIa)
   TH1F *h_mn_pt = new TH1F("h_mn_pt", "Muon transverse momentum", 100, 0., 500.);
   TH1F *h_mn_eta = new TH1F("h_mn_eta", "Muon pseudorapidity #eta", 100, -5., 5.);
   TH1F *h_mn_phi = new TH1F("h_mn_phi", "Muon pseudorapidity #eta", 100, -TMath::Pi(), TMath::Pi());

   for (Long64_t jentry = 0; jentry < nentries; jentry++)
   {
      GetEntry(jentry);
      for (Int_t j = 0; j < mn; j++)
      {
         h_mn_px->Fill(mn_px[j]);
         h_mn_py->Fill(mn_py[j]);
         h_mn_pz->Fill(mn_pz[j]);

         h_mn_en->Fill(mn_en[j]);
         h_mn_id->Fill(mn_id[j]);
         h_mn_type->Fill(mn_type[j]);

         h_mn_passId->Fill(mn_passId[j]);
         h_mn_passIdLoose->Fill(mn_passIdLoose[j]);
         h_mn_passSoftMuon->Fill(mn_passSoftMuon[j]);

         h_mn_passIso->Fill(mn_passIso[j]);
         h_mn_relIso->Fill(mn_relIso[j]);
         h_mn_trkrelIso->Fill(mn_trkrelIso[j]);

         h_mn_validMuonHits->Fill(mn_validMuonHits[j]);
         h_mn_trkLayersWithMeasurement->Fill(mn_trkLayersWithMeasurement[j]);
         h_mn_pixelLayersWithMeasurement->Fill(mn_pixelLayersWithMeasurement[j]);

         //TLorentzVectors TESTS

         TLorentzVector p_muon; //decl

         p_muon.SetPxPyPzE(mn_px[j],mn_py[j],mn_pz[j],mn_en[j]); //give its components values

         double pt_mu = p_muon.Pt();//get transverse momentum using the above
         double pt_eta_mu = p_muon.Eta(); // get pseudorapidity
         double pt_phi_mu = p_muon.Phi(); // get phi - angle in x-y plane
         // fill histograms
         h_mn_pt->Fill(pt_mu);
         h_mn_eta->Fill(pt_eta_mu);
         h_mn_phi->Fill(pt_phi_mu);

      }
   }

   TFile ff("histograms.root","new");
   h_mn_px->Write();
   h_mn_py->Write();
   h_mn_pz->Write();
}
