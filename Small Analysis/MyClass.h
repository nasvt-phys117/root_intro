//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Dec 20 09:55:15 2023 by ROOT version 6.28/04
// from TChain mainNtuplizer/data/
//////////////////////////////////////////////////////////

#ifndef MyClass_h
#define MyClass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class MyClass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           run;
   Int_t           lumi;
   Long64_t        event;
   Bool_t          hasTrigger;
   Int_t           triggerType;
   Int_t           nvtx;
   Float_t         vtx_x;
   Float_t         vtx_y;
   Float_t         vtx_z;
   Int_t           ngenITpu;
   Int_t           ngenOOTpu;
   Int_t           ngenOOTpum1;
   Int_t           ngenTruepu;
   Float_t         pthat;
   Float_t         genWeight;
   Float_t         qscale;
   Float_t         x1;
   Float_t         x2;
   Int_t           id1;
   Int_t           id2;
   Float_t         lheHt;
   Int_t           lheNJets;
   Int_t           npdfs;
   Float_t         pdfWeights[100];   //[npdfs]
   Int_t           nalphaS;
   Float_t         alphaSWeights[2];   //[nalphaS]
   Int_t           nmcparticles;
   Float_t         mc_px[12];   //[nmcparticles]
   Float_t         mc_py[12];   //[nmcparticles]
   Float_t         mc_pz[12];   //[nmcparticles]
   Float_t         mc_en[12];   //[nmcparticles]
   Int_t           mc_id[12];   //[nmcparticles]
   Int_t           mc_status[12];   //[nmcparticles]
   Int_t           mc_mom[12];   //[nmcparticles]
   Int_t           mc_momidx[12];   //[nmcparticles]
   Int_t           mn;
   Float_t         mn_px[4];   //[mn]
   Float_t         mn_py[4];   //[mn]
   Float_t         mn_pz[4];   //[mn]
   Float_t         mn_en[4];   //[mn]
   Int_t           mn_id[4];   //[mn]
   Int_t           mn_type[4];   //[mn]
   Bool_t          mn_passId[4];   //[mn]
   Bool_t          mn_passIdLoose[4];   //[mn]
   Bool_t          mn_passSoftMuon[4];   //[mn]
   Bool_t          mn_passIso[4];   //[mn]
   Float_t         mn_relIso[4];   //[mn]
   Float_t         mn_trkrelIso[4];   //[mn]
   Float_t         mn_validMuonHits[4];   //[mn]
   Float_t         mn_trkLayersWithMeasurement[4];   //[mn]
   Float_t         mn_pixelLayersWithMeasurement[4];   //[mn]
   Int_t           en;
   Float_t         en_px[3];   //[en]
   Float_t         en_py[3];   //[en]
   Float_t         en_pz[3];   //[en]
   Float_t         en_en[3];   //[en]
   Int_t           en_id[3];   //[en]
   Float_t         en_cor_en[3];   //[en]
   Float_t         en_EtaSC[3];   //[en]
   Float_t         en_R9[3];   //[en]
   Int_t           en_gainSeed[3];   //[en]
   Bool_t          en_passId[3];   //[en]
   Bool_t          en_passIdLoose[3];   //[en]
   Bool_t          en_passIso[3];   //[en]
   Float_t         en_relIso[3];   //[en]
   Float_t         en_enSigmaValue[3];   //[en]
   Float_t         en_enScaleValue[3];   //[en]
   Float_t         en_enScaleStatUp[3];   //[en]
   Float_t         en_enScaleStatDown[3];   //[en]
   Float_t         en_enScaleSystUp[3];   //[en]
   Float_t         en_enScaleSystDown[3];   //[en]
   Float_t         en_enScaleGainUp[3];   //[en]
   Float_t         en_enScaleGainDown[3];   //[en]
   Float_t         en_enSigmaRhoUp[3];   //[en]
   Float_t         en_enSigmaRhoDown[3];   //[en]
   Float_t         en_enSigmaPhiDown[3];   //[en]
   Int_t           jet;
   Float_t         jet_px[10];   //[jet]
   Float_t         jet_py[10];   //[jet]
   Float_t         jet_pz[10];   //[jet]
   Float_t         jet_en[10];   //[jet]
   Float_t         jet_btag0[10];   //[jet]
   Float_t         jet_btag1[10];   //[jet]
   Float_t         jet_mass[10];   //[jet]
   Float_t         jet_area[10];   //[jet]
   Float_t         jet_pu[10];   //[jet]
   Float_t         jet_puId[10];   //[jet]
   Bool_t          jet_PFLoose[10];   //[jet]
   Bool_t          jet_PFTight[10];   //[jet]
   Int_t           jet_partonFlavour[10];   //[jet]
   Int_t           jet_hadronFlavour[10];   //[jet]
   Int_t           jet_mother_id[10];   //[jet]
   Float_t         jet_parton_px[10];   //[jet]
   Float_t         jet_parton_py[10];   //[jet]
   Float_t         jet_parton_pz[10];   //[jet]
   Float_t         jet_parton_en[10];   //[jet]
   Float_t         jet_genpt[10];   //[jet]
   Int_t           sv;
   Float_t         sv_px[14];   //[sv]
   Float_t         sv_py[14];   //[sv]
   Float_t         sv_pz[14];   //[sv]
   Float_t         sv_en[14];   //[sv]
   Int_t           sv_ntrk[14];   //[sv]
   Float_t         sv_dxy[14];   //[sv]
   Float_t         sv_dxyz[14];   //[sv]
   Float_t         sv_dxyz_signif[14];   //[sv]
   Float_t         sv_cos_dxyz_p[14];   //[sv]
   Float_t         sv_chi2[14];   //[sv]
   Float_t         sv_ndof[14];   //[sv]
   Int_t           sv_mc_nbh_moms[14];   //[sv]
   Int_t           sv_mc_nbh_daus[14];   //[sv]
   Int_t           fjet;
   Float_t         fjet_px[13];   //[fjet]
   Float_t         fjet_py[13];   //[fjet]
   Float_t         fjet_pz[13];   //[fjet]
   Float_t         fjet_en[13];   //[fjet]
   Float_t         fjet_btag0[13];   //[fjet]
   Float_t         fjet_btag1[13];   //[fjet]
   Float_t         fjet_btag2[13];   //[fjet]
   Float_t         fjet_btag3[13];   //[fjet]
   Float_t         fjet_btag4[13];   //[fjet]
   Float_t         fjet_btag5[13];   //[fjet]
   Float_t         fjet_btag6[13];   //[fjet]
   Float_t         fjet_btag7[13];   //[fjet]
   Float_t         fjet_btag8[13];   //[fjet]
   Float_t         fjet_btag9[13];   //[fjet]
   Float_t         fjet_btag10[13];   //[fjet]
   Float_t         fjet_btag11[13];   //[fjet]
   Float_t         fjet_btag12[13];   //[fjet]
   Float_t         fjet_btag13[13];   //[fjet]
   Float_t         fjet_btag14[13];   //[fjet]
   Float_t         fjet_btag15[13];   //[fjet]
   Float_t         fjet_btag16[13];   //[fjet]
   Float_t         fjet_btag17[13];   //[fjet]
   Float_t         fjet_genpt[13];   //[fjet]
   Float_t         fjet_prunedM[13];   //[fjet]
   Float_t         fjet_softdropM[13];   //[fjet]
   Float_t         fjet_tau1[13];   //[fjet]
   Float_t         fjet_tau2[13];   //[fjet]
   Float_t         fjet_tau3[13];   //[fjet]
   Float_t         fjet_tau4[13];   //[fjet]
   Int_t           fjet_mother_id[13];   //[fjet]
   Float_t         fjet_parton_px[13];   //[fjet]
   Float_t         fjet_parton_py[13];   //[fjet]
   Float_t         fjet_parton_pz[13];   //[fjet]
   Float_t         fjet_parton_en[13];   //[fjet]
   Int_t           fjet_partonFlavour[13];   //[fjet]
   Int_t           fjet_hadronFlavour[13];   //[fjet]
   Float_t         fjet_chf[13];   //[fjet]
   Float_t         fjet_nhf[13];   //[fjet]
   Float_t         fjet_phf[13];   //[fjet]
   Float_t         fjet_muf[13];   //[fjet]
   Float_t         fjet_elf[13];   //[fjet]
   Float_t         fjet_ecfB1N2[13];   //[fjet]
   Float_t         fjet_ecfB1N3[13];   //[fjet]
   Int_t           fjet_subjet_count[13];   //[fjet]
   Float_t         fjet_subjets_px[13][2];   //[fjet]
   Float_t         fjet_subjets_py[13][2];   //[fjet]
   Float_t         fjet_subjets_pz[13][2];   //[fjet]
   Float_t         fjet_subjets_en[13][2];   //[fjet]
   Float_t         fjet_subjets_btag[13][2];   //[fjet]
   Int_t           fjet_subjets_partonFlavour[13][2];   //[fjet]
   Int_t           fjet_subjets_hadronFlavour[13][2];   //[fjet]
   Float_t         imet_pt[11];
   Float_t         imet_phi[11];
   Float_t         met_pt;
   Float_t         met_phi;
   Float_t         met_sumMET;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_event;   //!
   TBranch        *b_hasTrigger;   //!
   TBranch        *b_triggerType;   //!
   TBranch        *b_nvtx;   //!
   TBranch        *b_vtx_x;   //!
   TBranch        *b_vtx_y;   //!
   TBranch        *b_vtx_z;   //!
   TBranch        *b_ngenITpu;   //!
   TBranch        *b_ngenOOTpu;   //!
   TBranch        *b_ngenOOTpum1;   //!
   TBranch        *b_ngenTruepu;   //!
   TBranch        *b_pthat;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_qscale;   //!
   TBranch        *b_x1;   //!
   TBranch        *b_x2;   //!
   TBranch        *b_id1;   //!
   TBranch        *b_id2;   //!
   TBranch        *b_lheHt;   //!
   TBranch        *b_lheNJets;   //!
   TBranch        *b_npdfs;   //!
   TBranch        *b_pdfWeights;   //!
   TBranch        *b_nalphaS;   //!
   TBranch        *b_alphaSWeights;   //!
   TBranch        *b_nmcparticles;   //!
   TBranch        *b_mc_px;   //!
   TBranch        *b_mc_py;   //!
   TBranch        *b_mc_pz;   //!
   TBranch        *b_mc_en;   //!
   TBranch        *b_mc_id;   //!
   TBranch        *b_mc_status;   //!
   TBranch        *b_mc_mom;   //!
   TBranch        *b_mc_momidx;   //!
   TBranch        *b_mn;   //!
   TBranch        *b_mn_px;   //!
   TBranch        *b_mn_py;   //!
   TBranch        *b_mn_pz;   //!
   TBranch        *b_mn_en;   //!
   TBranch        *b_mn_id;   //!
   TBranch        *b_mn_type;   //!
   TBranch        *b_mn_passId;   //!
   TBranch        *b_mn_passIdLoose;   //!
   TBranch        *b_mn_passSoftMuon;   //!
   TBranch        *b_mn_passIso;   //!
   TBranch        *b_mn_relIso;   //!
   TBranch        *b_mn_trkrelIso;   //!
   TBranch        *b_mn_validMuonHits;   //!
   TBranch        *b_mn_trkLayersWithMeasurement;   //!
   TBranch        *b_mn_pixelLayersWithMeasurement;   //!
   TBranch        *b_en;   //!
   TBranch        *b_en_px;   //!
   TBranch        *b_en_py;   //!
   TBranch        *b_en_pz;   //!
   TBranch        *b_en_en;   //!
   TBranch        *b_en_id;   //!
   TBranch        *b_en_cor_en;   //!
   TBranch        *b_en_EtaSC;   //!
   TBranch        *b_en_R9;   //!
   TBranch        *b_en_gainSeed;   //!
   TBranch        *b_en_passId;   //!
   TBranch        *b_en_passIdLoose;   //!
   TBranch        *b_en_passIso;   //!
   TBranch        *b_en_relIso;   //!
   TBranch        *b_en_enSigmaValue;   //!
   TBranch        *b_en_enScaleValue;   //!
   TBranch        *b_en_enScaleStatUp;   //!
   TBranch        *b_en_enScaleStatDown;   //!
   TBranch        *b_en_enScaleSystUp;   //!
   TBranch        *b_en_enScaleSystDown;   //!
   TBranch        *b_en_enScaleGainUp;   //!
   TBranch        *b_en_enScaleGainDown;   //!
   TBranch        *b_en_enSigmaRhoUp;   //!
   TBranch        *b_en_enSigmaRhoDown;   //!
   TBranch        *b_en_enSigmaPhiDown;   //!
   TBranch        *b_jet;   //!
   TBranch        *b_jet_px;   //!
   TBranch        *b_jet_py;   //!
   TBranch        *b_jet_pz;   //!
   TBranch        *b_jet_en;   //!
   TBranch        *b_jet_btag0;   //!
   TBranch        *b_jet_btag1;   //!
   TBranch        *b_jet_mass;   //!
   TBranch        *b_jet_area;   //!
   TBranch        *b_jet_pu;   //!
   TBranch        *b_jet_puId;   //!
   TBranch        *b_jet_PFLoose;   //!
   TBranch        *b_jet_PFTight;   //!
   TBranch        *b_jet_partonFlavour;   //!
   TBranch        *b_jet_hadronFlavour;   //!
   TBranch        *b_jet_mother_id;   //!
   TBranch        *b_jet_parton_px;   //!
   TBranch        *b_jet_parton_py;   //!
   TBranch        *b_jet_parton_pz;   //!
   TBranch        *b_jet_parton_en;   //!
   TBranch        *b_jet_genpt;   //!
   TBranch        *b_sv;   //!
   TBranch        *b_sv_px;   //!
   TBranch        *b_sv_py;   //!
   TBranch        *b_sv_pz;   //!
   TBranch        *b_sv_en;   //!
   TBranch        *b_sv_ntrk;   //!
   TBranch        *b_sv_dxy;   //!
   TBranch        *b_sv_dxyz;   //!
   TBranch        *b_sv_dxyz_signif;   //!
   TBranch        *b_sv_cos_dxyz_p;   //!
   TBranch        *b_sv_chi2;   //!
   TBranch        *b_sv_ndof;   //!
   TBranch        *b_sv_mc_nbh_moms;   //!
   TBranch        *b_sv_mc_nbh_daus;   //!
   TBranch        *b_fjet;   //!
   TBranch        *b_fjet_px;   //!
   TBranch        *b_fjet_py;   //!
   TBranch        *b_fjet_pz;   //!
   TBranch        *b_fjet_en;   //!
   TBranch        *b_fjet_btag0;   //!
   TBranch        *b_fjet_btag1;   //!
   TBranch        *b_fjet_btag2;   //!
   TBranch        *b_fjet_btag3;   //!
   TBranch        *b_fjet_btag4;   //!
   TBranch        *b_fjet_btag5;   //!
   TBranch        *b_fjet_btag6;   //!
   TBranch        *b_fjet_btag7;   //!
   TBranch        *b_fjet_btag8;   //!
   TBranch        *b_fjet_btag9;   //!
   TBranch        *b_fjet_btag10;   //!
   TBranch        *b_fjet_btag11;   //!
   TBranch        *b_fjet_btag12;   //!
   TBranch        *b_fjet_btag13;   //!
   TBranch        *b_fjet_btag14;   //!
   TBranch        *b_fjet_btag15;   //!
   TBranch        *b_fjet_btag16;   //!
   TBranch        *b_fjet_btag17;   //!
   TBranch        *b_fjet_genpt;   //!
   TBranch        *b_fjet_prunedM;   //!
   TBranch        *b_fjet_softdropM;   //!
   TBranch        *b_fjet_tau1;   //!
   TBranch        *b_fjet_tau2;   //!
   TBranch        *b_fjet_tau3;   //!
   TBranch        *b_fjet_tau4;   //!
   TBranch        *b_fjet_mother_id;   //!
   TBranch        *b_fjet_parton_px;   //!
   TBranch        *b_fjet_parton_py;   //!
   TBranch        *b_fjet_parton_pz;   //!
   TBranch        *b_fjet_parton_en;   //!
   TBranch        *b_fjet_partonFlavour;   //!
   TBranch        *b_fjet_hadronFlavour;   //!
   TBranch        *b_fjet_chf;   //!
   TBranch        *b_fjet_nhf;   //!
   TBranch        *b_fjet_phf;   //!
   TBranch        *b_fjet_muf;   //!
   TBranch        *b_fjet_elf;   //!
   TBranch        *b_fjet_ecfB1N2;   //!
   TBranch        *b_fjet_ecfB1N3;   //!
   TBranch        *b_fjet_subjet_count;   //!
   TBranch        *b_fjet_subjets_px;   //!
   TBranch        *b_fjet_subjets_py;   //!
   TBranch        *b_fjet_subjets_pz;   //!
   TBranch        *b_fjet_subjets_en;   //!
   TBranch        *b_fjet_subjets_btag;   //!
   TBranch        *b_fjet_subjets_partonFlavour;   //!
   TBranch        *b_fjet_subjets_hadronFlavour;   //!
   TBranch        *b_imet_pt;   //!
   TBranch        *b_imet_phi;   //!
   TBranch        *b_met_pt;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_met_sumMET;   //!

   MyClass(TTree *tree=0);
   virtual ~MyClass();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef MyClass_cxx
MyClass::MyClass(TTree *tree) : fChain(0) 
{

  //TString in_file_name = "analysis_ZHToAATo4B_M20.root";
  TString in_file_name = "Analysis_TTToHadronic.root";
  //TString in_file_name = "DY4JetsToLL_M-50_MatchEWPDG20.root";
  //TString in_file_name = "WHToAATo4B_M20.root";

// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {

//#ifdef SINGLE_TREE
      // The following code should be used if you want this class to access
      // a single tree instead of a chain
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("2016/"+in_file_name);
      if (!f || !f->IsOpen()) {
         f = new TFile("2016/"+in_file_name);
      }
      TDirectory * dir = (TDirectory*)f->Get("2016/"+in_file_name+":/mainNtuplizer");
      dir->GetObject("data",tree);

//#else // SINGLE_TREE

      // The following code should be used if you want this class to access a chain
      // of trees.
      // TChain * chain = new TChain("mainNtuplizer/data","");
      // chain->Add("2016/analysis_ZHToAATo4B_M20.root/mainNtuplizer/data");
      // chain->Add("2016/DY4JetsToLL_M-50_MatchEWPDG20.root/mainNtuplizer/data");
      // chain->Add("2016/WHToAATo4B_M20.root/mainNtuplizer/data");
      // chain->Add("2016/Analysis_TTToHadronic.root/mainNtuplizer/data");
      // tree = chain;
//#endif // SINGLE_TREE

   }
   Init(tree);
}

MyClass::~MyClass()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t MyClass::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t MyClass::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void MyClass::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("hasTrigger", &hasTrigger, &b_hasTrigger);
   fChain->SetBranchAddress("triggerType", &triggerType, &b_triggerType);
   fChain->SetBranchAddress("nvtx", &nvtx, &b_nvtx);
   fChain->SetBranchAddress("vtx_x", &vtx_x, &b_vtx_x);
   fChain->SetBranchAddress("vtx_y", &vtx_y, &b_vtx_y);
   fChain->SetBranchAddress("vtx_z", &vtx_z, &b_vtx_z);
   fChain->SetBranchAddress("ngenITpu", &ngenITpu, &b_ngenITpu);
   fChain->SetBranchAddress("ngenOOTpu", &ngenOOTpu, &b_ngenOOTpu);
   fChain->SetBranchAddress("ngenOOTpum1", &ngenOOTpum1, &b_ngenOOTpum1);
   fChain->SetBranchAddress("ngenTruepu", &ngenTruepu, &b_ngenTruepu);
   fChain->SetBranchAddress("pthat", &pthat, &b_pthat);
   fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   fChain->SetBranchAddress("qscale", &qscale, &b_qscale);
   fChain->SetBranchAddress("x1", &x1, &b_x1);
   fChain->SetBranchAddress("x2", &x2, &b_x2);
   fChain->SetBranchAddress("id1", &id1, &b_id1);
   fChain->SetBranchAddress("id2", &id2, &b_id2);
   fChain->SetBranchAddress("lheHt", &lheHt, &b_lheHt);
   fChain->SetBranchAddress("lheNJets", &lheNJets, &b_lheNJets);
   fChain->SetBranchAddress("npdfs", &npdfs, &b_npdfs);
   fChain->SetBranchAddress("pdfWeights", pdfWeights, &b_pdfWeights);
   fChain->SetBranchAddress("nalphaS", &nalphaS, &b_nalphaS);
   fChain->SetBranchAddress("alphaSWeights", alphaSWeights, &b_alphaSWeights);
   fChain->SetBranchAddress("nmcparticles", &nmcparticles, &b_nmcparticles);
   fChain->SetBranchAddress("mc_px", mc_px, &b_mc_px);
   fChain->SetBranchAddress("mc_py", mc_py, &b_mc_py);
   fChain->SetBranchAddress("mc_pz", mc_pz, &b_mc_pz);
   fChain->SetBranchAddress("mc_en", mc_en, &b_mc_en);
   fChain->SetBranchAddress("mc_id", mc_id, &b_mc_id);
   fChain->SetBranchAddress("mc_status", mc_status, &b_mc_status);
   fChain->SetBranchAddress("mc_mom", mc_mom, &b_mc_mom);
   fChain->SetBranchAddress("mc_momidx", mc_momidx, &b_mc_momidx);
   fChain->SetBranchAddress("mn", &mn, &b_mn);
   fChain->SetBranchAddress("mn_px", mn_px, &b_mn_px);
   fChain->SetBranchAddress("mn_py", mn_py, &b_mn_py);
   fChain->SetBranchAddress("mn_pz", mn_pz, &b_mn_pz);
   fChain->SetBranchAddress("mn_en", mn_en, &b_mn_en);
   fChain->SetBranchAddress("mn_id", mn_id, &b_mn_id);
   fChain->SetBranchAddress("mn_type", mn_type, &b_mn_type);
   fChain->SetBranchAddress("mn_passId", mn_passId, &b_mn_passId);
   fChain->SetBranchAddress("mn_passIdLoose", mn_passIdLoose, &b_mn_passIdLoose);
   fChain->SetBranchAddress("mn_passSoftMuon", mn_passSoftMuon, &b_mn_passSoftMuon);
   fChain->SetBranchAddress("mn_passIso", mn_passIso, &b_mn_passIso);
   fChain->SetBranchAddress("mn_relIso", mn_relIso, &b_mn_relIso);
   fChain->SetBranchAddress("mn_trkrelIso", mn_trkrelIso, &b_mn_trkrelIso);
   fChain->SetBranchAddress("mn_validMuonHits", mn_validMuonHits, &b_mn_validMuonHits);
   fChain->SetBranchAddress("mn_trkLayersWithMeasurement", mn_trkLayersWithMeasurement, &b_mn_trkLayersWithMeasurement);
   fChain->SetBranchAddress("mn_pixelLayersWithMeasurement", mn_pixelLayersWithMeasurement, &b_mn_pixelLayersWithMeasurement);
   fChain->SetBranchAddress("en", &en, &b_en);
   fChain->SetBranchAddress("en_px", en_px, &b_en_px);
   fChain->SetBranchAddress("en_py", en_py, &b_en_py);
   fChain->SetBranchAddress("en_pz", en_pz, &b_en_pz);
   fChain->SetBranchAddress("en_en", en_en, &b_en_en);
   fChain->SetBranchAddress("en_id", en_id, &b_en_id);
   fChain->SetBranchAddress("en_cor_en", en_cor_en, &b_en_cor_en);
   fChain->SetBranchAddress("en_EtaSC", en_EtaSC, &b_en_EtaSC);
   fChain->SetBranchAddress("en_R9", en_R9, &b_en_R9);
   fChain->SetBranchAddress("en_gainSeed", en_gainSeed, &b_en_gainSeed);
   fChain->SetBranchAddress("en_passId", en_passId, &b_en_passId);
   fChain->SetBranchAddress("en_passIdLoose", en_passIdLoose, &b_en_passIdLoose);
   fChain->SetBranchAddress("en_passIso", en_passIso, &b_en_passIso);
   fChain->SetBranchAddress("en_relIso", en_relIso, &b_en_relIso);
   fChain->SetBranchAddress("en_enSigmaValue", en_enSigmaValue, &b_en_enSigmaValue);
   fChain->SetBranchAddress("en_enScaleValue", en_enScaleValue, &b_en_enScaleValue);
   fChain->SetBranchAddress("en_enScaleStatUp", en_enScaleStatUp, &b_en_enScaleStatUp);
   fChain->SetBranchAddress("en_enScaleStatDown", en_enScaleStatDown, &b_en_enScaleStatDown);
   fChain->SetBranchAddress("en_enScaleSystUp", en_enScaleSystUp, &b_en_enScaleSystUp);
   fChain->SetBranchAddress("en_enScaleSystDown", en_enScaleSystDown, &b_en_enScaleSystDown);
   fChain->SetBranchAddress("en_enScaleGainUp", en_enScaleGainUp, &b_en_enScaleGainUp);
   fChain->SetBranchAddress("en_enScaleGainDown", en_enScaleGainDown, &b_en_enScaleGainDown);
   fChain->SetBranchAddress("en_enSigmaRhoUp", en_enSigmaRhoUp, &b_en_enSigmaRhoUp);
   fChain->SetBranchAddress("en_enSigmaRhoDown", en_enSigmaRhoDown, &b_en_enSigmaRhoDown);
   fChain->SetBranchAddress("en_enSigmaPhiDown", en_enSigmaPhiDown, &b_en_enSigmaPhiDown);
   fChain->SetBranchAddress("jet", &jet, &b_jet);
   fChain->SetBranchAddress("jet_px", jet_px, &b_jet_px);
   fChain->SetBranchAddress("jet_py", jet_py, &b_jet_py);
   fChain->SetBranchAddress("jet_pz", jet_pz, &b_jet_pz);
   fChain->SetBranchAddress("jet_en", jet_en, &b_jet_en);
   fChain->SetBranchAddress("jet_btag0", jet_btag0, &b_jet_btag0);
   fChain->SetBranchAddress("jet_btag1", jet_btag1, &b_jet_btag1);
   fChain->SetBranchAddress("jet_mass", jet_mass, &b_jet_mass);
   fChain->SetBranchAddress("jet_area", jet_area, &b_jet_area);
   fChain->SetBranchAddress("jet_pu", jet_pu, &b_jet_pu);
   fChain->SetBranchAddress("jet_puId", jet_puId, &b_jet_puId);
   fChain->SetBranchAddress("jet_PFLoose", jet_PFLoose, &b_jet_PFLoose);
   fChain->SetBranchAddress("jet_PFTight", jet_PFTight, &b_jet_PFTight);
   fChain->SetBranchAddress("jet_partonFlavour", jet_partonFlavour, &b_jet_partonFlavour);
   fChain->SetBranchAddress("jet_hadronFlavour", jet_hadronFlavour, &b_jet_hadronFlavour);
   fChain->SetBranchAddress("jet_mother_id", jet_mother_id, &b_jet_mother_id);
   fChain->SetBranchAddress("jet_parton_px", jet_parton_px, &b_jet_parton_px);
   fChain->SetBranchAddress("jet_parton_py", jet_parton_py, &b_jet_parton_py);
   fChain->SetBranchAddress("jet_parton_pz", jet_parton_pz, &b_jet_parton_pz);
   fChain->SetBranchAddress("jet_parton_en", jet_parton_en, &b_jet_parton_en);
   fChain->SetBranchAddress("jet_genpt", jet_genpt, &b_jet_genpt);
   fChain->SetBranchAddress("sv", &sv, &b_sv);
   fChain->SetBranchAddress("sv_px", sv_px, &b_sv_px);
   fChain->SetBranchAddress("sv_py", sv_py, &b_sv_py);
   fChain->SetBranchAddress("sv_pz", sv_pz, &b_sv_pz);
   fChain->SetBranchAddress("sv_en", sv_en, &b_sv_en);
   fChain->SetBranchAddress("sv_ntrk", sv_ntrk, &b_sv_ntrk);
   fChain->SetBranchAddress("sv_dxy", sv_dxy, &b_sv_dxy);
   fChain->SetBranchAddress("sv_dxyz", sv_dxyz, &b_sv_dxyz);
   fChain->SetBranchAddress("sv_dxyz_signif", sv_dxyz_signif, &b_sv_dxyz_signif);
   fChain->SetBranchAddress("sv_cos_dxyz_p", sv_cos_dxyz_p, &b_sv_cos_dxyz_p);
   fChain->SetBranchAddress("sv_chi2", sv_chi2, &b_sv_chi2);
   fChain->SetBranchAddress("sv_ndof", sv_ndof, &b_sv_ndof);
   fChain->SetBranchAddress("sv_mc_nbh_moms", sv_mc_nbh_moms, &b_sv_mc_nbh_moms);
   fChain->SetBranchAddress("sv_mc_nbh_daus", sv_mc_nbh_daus, &b_sv_mc_nbh_daus);
   fChain->SetBranchAddress("fjet", &fjet, &b_fjet);
   fChain->SetBranchAddress("fjet_px", fjet_px, &b_fjet_px);
   fChain->SetBranchAddress("fjet_py", fjet_py, &b_fjet_py);
   fChain->SetBranchAddress("fjet_pz", fjet_pz, &b_fjet_pz);
   fChain->SetBranchAddress("fjet_en", fjet_en, &b_fjet_en);
   fChain->SetBranchAddress("fjet_btag0", fjet_btag0, &b_fjet_btag0);
   fChain->SetBranchAddress("fjet_btag1", fjet_btag1, &b_fjet_btag1);
   fChain->SetBranchAddress("fjet_btag2", fjet_btag2, &b_fjet_btag2);
   fChain->SetBranchAddress("fjet_btag3", fjet_btag3, &b_fjet_btag3);
   fChain->SetBranchAddress("fjet_btag4", fjet_btag4, &b_fjet_btag4);
   fChain->SetBranchAddress("fjet_btag5", fjet_btag5, &b_fjet_btag5);
   fChain->SetBranchAddress("fjet_btag6", fjet_btag6, &b_fjet_btag6);
   fChain->SetBranchAddress("fjet_btag7", fjet_btag7, &b_fjet_btag7);
   fChain->SetBranchAddress("fjet_btag8", fjet_btag8, &b_fjet_btag8);
   fChain->SetBranchAddress("fjet_btag9", fjet_btag9, &b_fjet_btag9);
   fChain->SetBranchAddress("fjet_btag10", fjet_btag10, &b_fjet_btag10);
   fChain->SetBranchAddress("fjet_btag11", fjet_btag11, &b_fjet_btag11);
   fChain->SetBranchAddress("fjet_btag12", fjet_btag12, &b_fjet_btag12);
   fChain->SetBranchAddress("fjet_btag13", fjet_btag13, &b_fjet_btag13);
   fChain->SetBranchAddress("fjet_btag14", fjet_btag14, &b_fjet_btag14);
   fChain->SetBranchAddress("fjet_btag15", fjet_btag15, &b_fjet_btag15);
   fChain->SetBranchAddress("fjet_btag16", fjet_btag16, &b_fjet_btag16);
   fChain->SetBranchAddress("fjet_btag17", fjet_btag17, &b_fjet_btag17);
   fChain->SetBranchAddress("fjet_genpt", fjet_genpt, &b_fjet_genpt);
   fChain->SetBranchAddress("fjet_prunedM", fjet_prunedM, &b_fjet_prunedM);
   fChain->SetBranchAddress("fjet_softdropM", fjet_softdropM, &b_fjet_softdropM);
   fChain->SetBranchAddress("fjet_tau1", fjet_tau1, &b_fjet_tau1);
   fChain->SetBranchAddress("fjet_tau2", fjet_tau2, &b_fjet_tau2);
   fChain->SetBranchAddress("fjet_tau3", fjet_tau3, &b_fjet_tau3);
   fChain->SetBranchAddress("fjet_tau4", fjet_tau4, &b_fjet_tau4);
   fChain->SetBranchAddress("fjet_mother_id", fjet_mother_id, &b_fjet_mother_id);
   fChain->SetBranchAddress("fjet_parton_px", fjet_parton_px, &b_fjet_parton_px);
   fChain->SetBranchAddress("fjet_parton_py", fjet_parton_py, &b_fjet_parton_py);
   fChain->SetBranchAddress("fjet_parton_pz", fjet_parton_pz, &b_fjet_parton_pz);
   fChain->SetBranchAddress("fjet_parton_en", fjet_parton_en, &b_fjet_parton_en);
   fChain->SetBranchAddress("fjet_partonFlavour", fjet_partonFlavour, &b_fjet_partonFlavour);
   fChain->SetBranchAddress("fjet_hadronFlavour", fjet_hadronFlavour, &b_fjet_hadronFlavour);
   fChain->SetBranchAddress("fjet_chf", fjet_chf, &b_fjet_chf);
   fChain->SetBranchAddress("fjet_nhf", fjet_nhf, &b_fjet_nhf);
   fChain->SetBranchAddress("fjet_phf", fjet_phf, &b_fjet_phf);
   fChain->SetBranchAddress("fjet_muf", fjet_muf, &b_fjet_muf);
   fChain->SetBranchAddress("fjet_elf", fjet_elf, &b_fjet_elf);
   fChain->SetBranchAddress("fjet_ecfB1N2", fjet_ecfB1N2, &b_fjet_ecfB1N2);
   fChain->SetBranchAddress("fjet_ecfB1N3", fjet_ecfB1N3, &b_fjet_ecfB1N3);
   fChain->SetBranchAddress("fjet_subjet_count", fjet_subjet_count, &b_fjet_subjet_count);
   fChain->SetBranchAddress("fjet_subjets_px", fjet_subjets_px, &b_fjet_subjets_px);
   fChain->SetBranchAddress("fjet_subjets_py", fjet_subjets_py, &b_fjet_subjets_py);
   fChain->SetBranchAddress("fjet_subjets_pz", fjet_subjets_pz, &b_fjet_subjets_pz);
   fChain->SetBranchAddress("fjet_subjets_en", fjet_subjets_en, &b_fjet_subjets_en);
   fChain->SetBranchAddress("fjet_subjets_btag", fjet_subjets_btag, &b_fjet_subjets_btag);
   fChain->SetBranchAddress("fjet_subjets_partonFlavour", fjet_subjets_partonFlavour, &b_fjet_subjets_partonFlavour);
   fChain->SetBranchAddress("fjet_subjets_hadronFlavour", fjet_subjets_hadronFlavour, &b_fjet_subjets_hadronFlavour);
   fChain->SetBranchAddress("imet_pt", imet_pt, &b_imet_pt);
   fChain->SetBranchAddress("imet_phi", imet_phi, &b_imet_phi);
   fChain->SetBranchAddress("met_pt", &met_pt, &b_met_pt);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("met_sumMET", &met_sumMET, &b_met_sumMET);
   Notify();
}

Bool_t MyClass::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void MyClass::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t MyClass::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef MyClass_cxx
