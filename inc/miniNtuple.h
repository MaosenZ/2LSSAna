//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May  2 15:17:11 2017 by ROOT version 5.34/18
// from TTree Tree/vars
// found on file: /scratchfs/atlas/zhoums/2LSSAna_output/output/Systematics/2jets/miniNtuple_prompt.root
//////////////////////////////////////////////////////////

#ifndef miniNtuple_h
#define miniNtuple_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <TString.h>
#include <iostream>
#include <fstream>
#include <string>
#include "NomErr2.h"
#include "TH1F.h"
#include <cmath>
// Fixed size dimensions of array or collections stored in the TTree if any.
using namespace std;
class miniNtuple {
public :
   TChain          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
   string          masspoint; //
   string          SystematicType;
   vector<string>          SysSrcs;
   string          sample;
   float           ff_ele;
   float           ff_mu;
   float           sys_ele;
   float           sys_mu;
   float           Stat_ff_ele;
   float           QmisID_ff_ele;
   float           Closure_ff_ele;
   float           Composition_ff_ele;
   float           Stat_ff_mu;
   float           Closure_ff_mu;
   float           Composition_ff_mu;
   float           WZ_ff_ele;
   float           Vgam_ff_ele;
   float           ssWW_ff_ele;
   float           ttbar_ff_ele;
   float           Zjets_ff_ele;
   float           WZ_ff_mu;
   float           ssWW_ff_mu;
   float           QmisIDMC_ff_ele;

   // Declaration of leaf types
   Double_t        pileupEventWeight_UP;
   Double_t        pileupEventWeight_DOWN;
   Float_t         MV2c10_70_EventWeight_B0_up;
   Float_t         MV2c10_70_EventWeight_B0_down;
   Float_t         MV2c10_70_EventWeight_B1_up;
   Float_t         MV2c10_70_EventWeight_B1_down;
   Float_t         MV2c10_70_EventWeight_B2_up;
   Float_t         MV2c10_70_EventWeight_B2_down;
   Float_t         MV2c10_70_EventWeight_B3_up;
   Float_t         MV2c10_70_EventWeight_B3_down;
   Float_t         MV2c10_70_EventWeight_B4_up;
   Float_t         MV2c10_70_EventWeight_B4_down;
   Float_t         MV2c10_70_EventWeight_B5_up;
   Float_t         MV2c10_70_EventWeight_B5_down;
   Float_t         MV2c10_70_EventWeight_C0_up;
   Float_t         MV2c10_70_EventWeight_C0_down;
   Float_t         MV2c10_70_EventWeight_C1_up;
   Float_t         MV2c10_70_EventWeight_C1_down;
   Float_t         MV2c10_70_EventWeight_C2_up;
   Float_t         MV2c10_70_EventWeight_C2_down;
   Float_t         MV2c10_70_EventWeight_C3_up;
   Float_t         MV2c10_70_EventWeight_C3_down;
   Float_t         MV2c10_70_EventWeight_Light0_up;
   Float_t         MV2c10_70_EventWeight_Light0_down;
   Float_t         MV2c10_70_EventWeight_Light1_up;
   Float_t         MV2c10_70_EventWeight_Light1_down;
   Float_t         MV2c10_70_EventWeight_Light2_up;
   Float_t         MV2c10_70_EventWeight_Light2_down;
   Float_t         MV2c10_70_EventWeight_Light3_up;
   Float_t         MV2c10_70_EventWeight_Light3_down;
   Float_t         MV2c10_70_EventWeight_Light4_up;
   Float_t         MV2c10_70_EventWeight_Light4_down;
   Float_t         MV2c10_70_EventWeight_Light5_up;
   Float_t         MV2c10_70_EventWeight_Light5_down;
   Float_t         MV2c10_70_EventWeight_Light6_up;
   Float_t         MV2c10_70_EventWeight_Light6_down;
   Float_t         MV2c10_70_EventWeight_Light7_up;
   Float_t         MV2c10_70_EventWeight_Light7_down;
   Float_t         MV2c10_70_EventWeight_Light8_up;
   Float_t         MV2c10_70_EventWeight_Light8_down;
   Float_t         MV2c10_70_EventWeight_Light9_up;
   Float_t         MV2c10_70_EventWeight_Light9_down;
   Float_t         MV2c10_70_EventWeight_Light10_up;
   Float_t         MV2c10_70_EventWeight_Light10_down;
   Float_t         MV2c10_70_EventWeight_Light11_up;
   Float_t         MV2c10_70_EventWeight_Light11_down;
   Float_t         MV2c10_70_EventWeight_Light12_up;
   Float_t         MV2c10_70_EventWeight_Light12_down;
   Float_t         MV2c10_70_EventWeight_Light13_up;
   Float_t         MV2c10_70_EventWeight_Light13_down;
   Float_t         MV2c10_70_EventWeight_Light14_up;
   Float_t         MV2c10_70_EventWeight_Light14_down;
   Float_t         MV2c10_70_EventWeight_Light15_up;
   Float_t         MV2c10_70_EventWeight_Light15_down;
   Float_t         MV2c10_70_EventWeight_extrapolation_up;
   Float_t         MV2c10_70_EventWeight_extrapolation_down;
   Float_t         MV2c10_70_EventWeight_extrapolation_from_charm_up;
   Float_t         MV2c10_70_EventWeight_extrapolation_from_charm_down;
   Double_t        JVT_EventWeight_UP;
   Double_t        JVT_EventWeight_DOWN;
   Float_t         lepSFTrigLoose;
   Float_t         lepSFTrigTight;
   Float_t         lepSFObjLoose;
   Float_t         lepSFObjTight;
   Float_t         lepSFTrigTight_EL_SF_Trigger_UP;
   Float_t         lepSFTrigTight_EL_SF_Trigger_DOWN;
   Float_t         lepSFObjTight_EL_SF_Reco_UP;
   Float_t         lepSFObjTight_EL_SF_Reco_DOWN;
   Float_t         lepSFObjTight_EL_SF_ID_UP;
   Float_t         lepSFObjTight_EL_SF_ID_DOWN;
   Float_t         lepSFObjTight_EL_SF_Isol_UP;
   Float_t         lepSFObjTight_EL_SF_Isol_DOWN;
   Float_t         lepSFTrigTight_MU_SF_Trigger_STAT_UP;
   Float_t         lepSFTrigTight_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepSFTrigTight_MU_SF_Trigger_SYST_UP;
   Float_t         lepSFTrigTight_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepSFObjTight_MU_SF_ID_STAT_UP;
   Float_t         lepSFObjTight_MU_SF_ID_STAT_DOWN;
   Float_t         lepSFObjTight_MU_SF_ID_SYST_UP;
   Float_t         lepSFObjTight_MU_SF_ID_SYST_DOWN;
   Float_t         lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP;
   Float_t         lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN;
   Float_t         lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP;
   Float_t         lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN;
   Float_t         lepSFObjTight_MU_SF_Isol_STAT_UP;
   Float_t         lepSFObjLoose_MU_SF_Isol_STAT_DOWN;
   Float_t         lepSFObjTight_MU_SF_Isol_STAT_DOWN;
   Float_t         lepSFObjTight_MU_SF_Isol_SYST_UP;
   Float_t         lepSFObjTight_MU_SF_Isol_SYST_DOWN;
   Float_t         lepSFObjTight_MU_SF_TTVA_STAT_UP;
   Float_t         lepSFObjTight_MU_SF_TTVA_STAT_DOWN;
   Float_t         lepSFObjTight_MU_SF_TTVA_SYST_UP;
   Float_t         lepSFObjTight_MU_SF_TTVA_SYST_DOWN;
   Float_t         m_ll;
   Float_t         m_jj;
   Float_t         MET;
   Float_t         pt_leadinglepton;
   Float_t         pt_sublepton;
   Float_t         pt_j1;
   Float_t         pt_j2;
   Float_t         m_jj_w;
   Float_t         m_l1jj;
   Float_t         m_all;
   Float_t         pt_sum;
   Float_t         pt_vecsum;
   Float_t         mindR_l1j;
   Float_t         m_l1j;
   Float_t         mindR_l2j;
   Float_t         RMS;
   Float_t         m_l2j;
   Float_t         Mt;
   Double_t        weight;
   Int_t           channel;
   Int_t           category;
   TString         *component;
   Int_t           numOfjet;
   Float_t         ChargeIDBDTTight_0;
   Float_t         ChargeIDBDTTight_1;
   Float_t         PromptLeptonIso_TagWeight_0;
   Float_t         PromptLeptonIso_TagWeight_1;

   // List of branches
   TBranch        *b_pileupEventWeight_UP;   //!
   TBranch        *b_pileupEventWeight_DOWN;   //!
   TBranch        *b_MV2c10_70_EventWeight_B0_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_B0_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_B1_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_B1_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_B2_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_B2_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_B3_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_B3_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_B4_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_B4_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_B5_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_B5_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_C0_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_C0_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_C1_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_C1_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_C2_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_C2_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_C3_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_C3_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light0_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light0_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light1_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light1_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light2_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light2_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light3_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light3_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light4_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light4_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light5_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light5_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light6_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light6_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light7_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light7_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light8_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light8_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light9_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light9_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light10_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light10_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light11_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light11_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light12_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light12_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light13_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light13_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light14_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light14_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light15_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_Light15_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_extrapolation_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_extrapolation_down;   //!
   TBranch        *b_MV2c10_70_EventWeight_extrapolation_from_charm_up;   //!
   TBranch        *b_MV2c10_70_EventWeight_extrapolation_from_charm_down;   //!
   TBranch        *b_JVT_EventWeight_UP;   //!
   TBranch        *b_JVT_EventWeight_DOWN;   //!
   TBranch        *b_lepSFTrigLoose;   //!
   TBranch        *b_lepSFTrigTight;   //!
   TBranch        *b_lepSFObjLoose;   //!
   TBranch        *b_lepSFObjTight;   //!
   TBranch        *b_lepSFTrigTight_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepSFTrigTight_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepSFObjTight_EL_SF_Reco_UP;   //!
   TBranch        *b_lepSFObjTight_EL_SF_Reco_DOWN;   //!
   TBranch        *b_lepSFObjTight_EL_SF_ID_UP;   //!
   TBranch        *b_lepSFObjTight_EL_SF_ID_DOWN;   //!
   TBranch        *b_lepSFObjTight_EL_SF_Isol_UP;   //!
   TBranch        *b_lepSFObjTight_EL_SF_Isol_DOWN;   //!
   TBranch        *b_lepSFTrigTight_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepSFTrigTight_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepSFTrigTight_MU_SF_Trigger_SYST_UP;   //!
   TBranch        *b_lepSFTrigTight_MU_SF_Trigger_SYST_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_STAT_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_STAT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_SYST_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_SYST_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_Isol_STAT_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_Isol_STAT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_Isol_STAT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_Isol_SYST_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_Isol_SYST_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_TTVA_STAT_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_TTVA_STAT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_TTVA_SYST_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_TTVA_SYST_DOWN;   //!
   TBranch        *b_m_ll;   //!
   TBranch        *b_m_jj;   //!
   TBranch        *b_MET;   //!
   TBranch        *b_pt_leadinglepton;   //!
   TBranch        *b_pt_sublepton;   //!
   TBranch        *b_pt_j1;   //!
   TBranch        *b_pt_j2;   //!
   TBranch        *b_m_jj_w;   //!
   TBranch        *b_m_l1jj;   //!
   TBranch        *b_m_all;   //!
   TBranch        *b_pt_sum;   //!
   TBranch        *b_pt_vecsum;   //!
   TBranch        *b_mindR_l1j;   //!
   TBranch        *b_m_l1j;   //!
   TBranch        *b_mindR_l2j;   //!
   TBranch        *b_RMS;   //!
   TBranch        *b_m_l2j;   //!
   TBranch        *b_Mt;   //!
   TBranch        *b_weight;   //!
   TBranch        *b_channel;   //!
   TBranch        *b_category;   //!
   TBranch        *b_component;   //!
   TBranch        *b_numOfjet;   //!
   TBranch        *b_ChargeIDBDTTight_0;   //!
   TBranch        *b_ChargeIDBDTTight_1;   //!
   TBranch        *b_PromptLeptonIso_TagWeight_0;   //!
   TBranch        *b_PromptLeptonIso_TagWeight_1;   //!

   miniNtuple(string nmasspoint, string nsample, string nSystematicType);
   virtual ~miniNtuple();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TChain *tree);
   //virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   virtual map<string,NomErr2>     GetSysts();
   virtual void     makeTH1Fs(TH1F *hist_ee,TH1F *hist_mumu,TH1F *hist_emu,TH1F *hist_antiemu,TH1F *hist_eantimu,Float_t Nbins, Float_t xmin, Float_t xmax,TString var);
   //virtual void     DatadrivenSysts();
};

#endif

#ifdef miniNtuple_cxx
miniNtuple::miniNtuple(string nmasspoint,string nsample,string nSystematicType) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
  TChain *chain=new TChain("Tree");

  if(nmasspoint!="mH260" && nmasspoint!="mH300" && nmasspoint!="mH400" && nmasspoint!="mH500" && nmasspoint!="nonres")
     cout<<"Error: you should only pass: mH260, mH300, mH400, mH500 or nonres for first argument!"<<endl;
  if(nsample!="mH260" && nsample!="mH300" &&nsample!="mH400" &&nsample!="mH500" &&nsample!="nonres"&& nsample!="ttH" && nsample!="tV" && nsample!="Vgam" && nsample!="promptSS" && nsample!="fake" && nsample!="QmisID")
     cout<<"Error: you should only pass: mH*, promptSS, Vgam, fake or QmisID for second argument!"<<endl;
  //first define NonEventWeight Syst
    /*string nSysSrcs[]={
     "EG_RESOLUTION_ALL__1down",
     "EG_RESOLUTION_ALL__1up",
     "EG_SCALE_ALL__1down",
     "EG_SCALE_ALL__1up",
     "JET_21NP_JET_BJES_Response__1down",
     "JET_21NP_JET_BJES_Response__1up",
     "JET_21NP_JET_EffectiveNP_1__1down",
     "JET_21NP_JET_EffectiveNP_1__1up",
     "JET_21NP_JET_EffectiveNP_2__1down",
     "JET_21NP_JET_EffectiveNP_2__1up",
     "JET_21NP_JET_EffectiveNP_3__1down",
     "JET_21NP_JET_EffectiveNP_3__1up",
     "JET_21NP_JET_EffectiveNP_4__1down",
     "JET_21NP_JET_EffectiveNP_4__1up",
     "JET_21NP_JET_EffectiveNP_5__1down",
     "JET_21NP_JET_EffectiveNP_5__1up",
     "JET_21NP_JET_EffectiveNP_6__1down",
     "JET_21NP_JET_EffectiveNP_6__1up",
     "JET_21NP_JET_EffectiveNP_7__1down",
     "JET_21NP_JET_EffectiveNP_7__1up",
     "JET_21NP_JET_EffectiveNP_8restTerm__1down",
     "JET_21NP_JET_EffectiveNP_8restTerm__1up",
     "JET_21NP_JET_EtaIntercalibration_Modelling__1down",
     "JET_21NP_JET_EtaIntercalibration_Modelling__1up",
     "JET_21NP_JET_EtaIntercalibration_NonClosure__1down",
     "JET_21NP_JET_EtaIntercalibration_NonClosure__1up",
     "JET_21NP_JET_EtaIntercalibration_TotalStat__1down",
     "JET_21NP_JET_EtaIntercalibration_TotalStat__1up",
     "JET_21NP_JET_Flavor_Composition__1down",
     "JET_21NP_JET_Flavor_Composition__1up",
     "JET_21NP_JET_Flavor_Response__1down",
     "JET_21NP_JET_Flavor_Response__1up",
     "JET_21NP_JET_Pileup_OffsetMu__1down",
     "JET_21NP_JET_Pileup_OffsetMu__1up",
     "JET_21NP_JET_Pileup_OffsetNPV__1down",
     "JET_21NP_JET_Pileup_OffsetNPV__1up",
     "JET_21NP_JET_Pileup_PtTerm__1down",
     "JET_21NP_JET_Pileup_PtTerm__1up",
     "JET_21NP_JET_Pileup_RhoTopology__1down",
     "JET_21NP_JET_Pileup_RhoTopology__1up",
     "JET_21NP_JET_PunchThrough_AFII__1down",
     "JET_21NP_JET_PunchThrough_AFII__1up",
     "JET_21NP_JET_PunchThrough_MC15__1down",
     "JET_21NP_JET_PunchThrough_MC15__1up",
     "JET_21NP_JET_RelativeNonClosure_AFII__1down",
     "JET_21NP_JET_RelativeNonClosure_AFII__1up",
     "JET_21NP_JET_SingleParticle_HighPt__1down",
     "JET_21NP_JET_SingleParticle_HighPt__1up",
     "JET_JER_SINGLE_NP__1up",
     "MET_SoftTrk_ResoPara",
     "MET_SoftTrk_ResoPerp",
     "MET_SoftTrk_ScaleDown",
     "MET_SoftTrk_ScaleUp",
     "MUON_ID__1down",
     "MUON_ID__1up",
     "MUON_MS__1down",
     "MUON_MS__1up",
     "MUON_SAGITTA_RESBIAS__1down",
     "MUON_SAGITTA_RESBIAS__1up",
     "MUON_SAGITTA_RHO__1down",
     "MUON_SAGITTA_RHO__1up",
     "MUON_SCALE__1down",
     "MUON_SCALE__1up"
   }*/ 
  TString inputFile; int SystematicTypeNum;
  if(nSystematicType=="EventWeight") SystematicTypeNum=1;
  if(nSystematicType=="NonEventWeight") SystematicTypeNum=2;
  if(nSystematicType=="Data-driven") SystematicTypeNum=3;
  switch(SystematicTypeNum){

    case  1: 
      {inputFile="/afs/ihep.ac.cn/users/z/zhoums/work/2LSSAna/output/dataMC_2jets/miniNtuple_"+nsample+".root";
      chain->Add(inputFile);}//this bracket is to avoid cross initinilaztion
       break;

    case 2 : {
      TString NonEventWeightSysSrcsFile="/afs/ihep.ac.cn/users/z/zhoums/work/2LSSAna/inc/NonEventWeightSysSrcs.txt";
      ifstream ifile(NonEventWeightSysSrcsFile.Data(),ifstream::in);
      if(!ifile) cout<<"not be able open "<<NonEventWeightSysSrcsFile.Data()<<endl;
      string line;
      cout<<"enter in NonEventWeight case"<<endl;
      while(getline(ifile,line)){
            char dsid[200];
            const char* readline=line.c_str();
            sscanf(readline,"%s",dsid);
            if(dsid[0]=='#') continue;
            string SysSrc(dsid);
            SysSrcs.push_back(SysSrc);
            cout<<SysSrc<<endl;
            //inputFile="/scratchfs/atlas/zhoums/2LSSAna_output/output/Systematics/";
            inputFile="/publicfs/atlas/atlasnew/higgs/hgg/zhoums/4W/v27.01/2LSSAna_output/output/Systematics/";
            inputFile=inputFile+SysSrc+"/miniNtuple_"+nsample+".root";
            chain->Add(inputFile);
       }
    }
       break;

    case 3 : 
      //for Njet division , data-driven bkgs have different systematics
      {if(nsample!="fake" && nsample!="QmisID") cout<<"Error: only QmisID and fake have Data-driven syst."<<endl;
      //if(nmasspoint=="mH260" || nmasspoint=="mH300" || nmasspoint=="H280_S135" || nmasspoint=="H300_S135" || nmasspoint=="H320_S135"){ 
      if(nmasspoint=="mH260" || nmasspoint=="mH300" || nmasspoint=="mH400" || nmasspoint=="H280_S135" || nmasspoint=="H300_S135" || nmasspoint=="H320_S135"){ //for interpolation
         inputFile ="/afs/ihep.ac.cn/users/z/zhoums/work/2LSSAna/output/dataMC_2jets/miniNtuple_"+nsample+".root";
         ff_ele=0.5401; ff_mu=0.5033; sys_ele=0.6309; sys_mu=0.6455;
         Stat_ff_ele=0.0576; QmisID_ff_ele=0.33; Closure_ff_ele=0.388; Composition_ff_ele=0.3383;
         Stat_ff_mu=0.999; Closure_ff_mu=0.388; Composition_ff_mu=0.3169;
         WZ_ff_ele=0.0893; ssWW_ff_ele=0.0122; ssWW_ff_mu=0.0606; WZ_ff_mu=0.3900;
         QmisIDMC_ff_ele=0.015;
         Vgam_ff_ele=0.1155;
      }
      //else if(nmasspoint=="mH400" || nmasspoint=="mH500" || nmasspoint=="nonres" || nmasspoint=="H340_S135" || nmasspoint=="H340_S145"
      else if(nmasspoint=="mH500" || nmasspoint=="nonres" || nmasspoint=="H340_S135" || nmasspoint=="H340_S145"//for interpolation
               || nmasspoint=="H340_S155" || nmasspoint=="H340_S165"){
         inputFile ="/afs/ihep.ac.cn/users/z/zhoums/work/2LSSAna/output/dataMC_3jets/miniNtuple_"+nsample+".root";
         ff_ele=0.5472; ff_mu=0.4544; sys_ele=0.6918; sys_mu=0.7179; 
         Stat_ff_ele=0.0482; QmisID_ff_ele=0.30; Closure_ff_ele=0.388; Composition_ff_ele=0.462;
         Stat_ff_mu=0.077; Closure_ff_mu=0.388; Composition_ff_mu=0.485;
         WZ_ff_ele=0.0794; ssWW_ff_ele=0.0208; ssWW_ff_mu=0.1039; WZ_ff_mu=0.3364;
         QmisIDMC_ff_ele=0.02;
         Vgam_ff_ele=0.1228;
      }
      chain->Add(inputFile);}
        break;

    default : cout<<"Error: you have to define Systematic Type: EventWeight, NonEventWeight or Data-driven!"<<endl;
  }
  Init(chain);
  masspoint=nmasspoint;
  SystematicType=nSystematicType;
  sample=nsample;
}

miniNtuple::~miniNtuple()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t miniNtuple::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t miniNtuple::LoadTree(Long64_t entry)
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

void miniNtuple::Init(TChain *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   component = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("pileupEventWeight_UP", &pileupEventWeight_UP, &b_pileupEventWeight_UP);
   fChain->SetBranchAddress("pileupEventWeight_DOWN", &pileupEventWeight_DOWN, &b_pileupEventWeight_DOWN);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_B0_up", &MV2c10_70_EventWeight_B0_up, &b_MV2c10_70_EventWeight_B0_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_B0_down", &MV2c10_70_EventWeight_B0_down, &b_MV2c10_70_EventWeight_B0_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_B1_up", &MV2c10_70_EventWeight_B1_up, &b_MV2c10_70_EventWeight_B1_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_B1_down", &MV2c10_70_EventWeight_B1_down, &b_MV2c10_70_EventWeight_B1_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_B2_up", &MV2c10_70_EventWeight_B2_up, &b_MV2c10_70_EventWeight_B2_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_B2_down", &MV2c10_70_EventWeight_B2_down, &b_MV2c10_70_EventWeight_B2_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_B3_up", &MV2c10_70_EventWeight_B3_up, &b_MV2c10_70_EventWeight_B3_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_B3_down", &MV2c10_70_EventWeight_B3_down, &b_MV2c10_70_EventWeight_B3_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_B4_up", &MV2c10_70_EventWeight_B4_up, &b_MV2c10_70_EventWeight_B4_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_B4_down", &MV2c10_70_EventWeight_B4_down, &b_MV2c10_70_EventWeight_B4_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_B5_up", &MV2c10_70_EventWeight_B5_up, &b_MV2c10_70_EventWeight_B5_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_B5_down", &MV2c10_70_EventWeight_B5_down, &b_MV2c10_70_EventWeight_B5_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_C0_up", &MV2c10_70_EventWeight_C0_up, &b_MV2c10_70_EventWeight_C0_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_C0_down", &MV2c10_70_EventWeight_C0_down, &b_MV2c10_70_EventWeight_C0_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_C1_up", &MV2c10_70_EventWeight_C1_up, &b_MV2c10_70_EventWeight_C1_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_C1_down", &MV2c10_70_EventWeight_C1_down, &b_MV2c10_70_EventWeight_C1_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_C2_up", &MV2c10_70_EventWeight_C2_up, &b_MV2c10_70_EventWeight_C2_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_C2_down", &MV2c10_70_EventWeight_C2_down, &b_MV2c10_70_EventWeight_C2_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_C3_up", &MV2c10_70_EventWeight_C3_up, &b_MV2c10_70_EventWeight_C3_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_C3_down", &MV2c10_70_EventWeight_C3_down, &b_MV2c10_70_EventWeight_C3_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light0_up", &MV2c10_70_EventWeight_Light0_up, &b_MV2c10_70_EventWeight_Light0_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light0_down", &MV2c10_70_EventWeight_Light0_down, &b_MV2c10_70_EventWeight_Light0_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light1_up", &MV2c10_70_EventWeight_Light1_up, &b_MV2c10_70_EventWeight_Light1_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light1_down", &MV2c10_70_EventWeight_Light1_down, &b_MV2c10_70_EventWeight_Light1_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light2_up", &MV2c10_70_EventWeight_Light2_up, &b_MV2c10_70_EventWeight_Light2_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light2_down", &MV2c10_70_EventWeight_Light2_down, &b_MV2c10_70_EventWeight_Light2_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light3_up", &MV2c10_70_EventWeight_Light3_up, &b_MV2c10_70_EventWeight_Light3_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light3_down", &MV2c10_70_EventWeight_Light3_down, &b_MV2c10_70_EventWeight_Light3_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light4_up", &MV2c10_70_EventWeight_Light4_up, &b_MV2c10_70_EventWeight_Light4_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light4_down", &MV2c10_70_EventWeight_Light4_down, &b_MV2c10_70_EventWeight_Light4_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light5_up", &MV2c10_70_EventWeight_Light5_up, &b_MV2c10_70_EventWeight_Light5_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light5_down", &MV2c10_70_EventWeight_Light5_down, &b_MV2c10_70_EventWeight_Light5_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light6_up", &MV2c10_70_EventWeight_Light6_up, &b_MV2c10_70_EventWeight_Light6_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light6_down", &MV2c10_70_EventWeight_Light6_down, &b_MV2c10_70_EventWeight_Light6_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light7_up", &MV2c10_70_EventWeight_Light7_up, &b_MV2c10_70_EventWeight_Light7_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light7_down", &MV2c10_70_EventWeight_Light7_down, &b_MV2c10_70_EventWeight_Light7_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light8_up", &MV2c10_70_EventWeight_Light8_up, &b_MV2c10_70_EventWeight_Light8_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light8_down", &MV2c10_70_EventWeight_Light8_down, &b_MV2c10_70_EventWeight_Light8_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light9_up", &MV2c10_70_EventWeight_Light9_up, &b_MV2c10_70_EventWeight_Light9_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light9_down", &MV2c10_70_EventWeight_Light9_down, &b_MV2c10_70_EventWeight_Light9_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light10_up", &MV2c10_70_EventWeight_Light10_up, &b_MV2c10_70_EventWeight_Light10_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light10_down", &MV2c10_70_EventWeight_Light10_down, &b_MV2c10_70_EventWeight_Light10_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light11_up", &MV2c10_70_EventWeight_Light11_up, &b_MV2c10_70_EventWeight_Light11_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light11_down", &MV2c10_70_EventWeight_Light11_down, &b_MV2c10_70_EventWeight_Light11_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light12_up", &MV2c10_70_EventWeight_Light12_up, &b_MV2c10_70_EventWeight_Light12_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light12_down", &MV2c10_70_EventWeight_Light12_down, &b_MV2c10_70_EventWeight_Light12_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light13_up", &MV2c10_70_EventWeight_Light13_up, &b_MV2c10_70_EventWeight_Light13_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light13_down", &MV2c10_70_EventWeight_Light13_down, &b_MV2c10_70_EventWeight_Light13_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light14_up", &MV2c10_70_EventWeight_Light14_up, &b_MV2c10_70_EventWeight_Light14_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light14_down", &MV2c10_70_EventWeight_Light14_down, &b_MV2c10_70_EventWeight_Light14_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light15_up", &MV2c10_70_EventWeight_Light15_up, &b_MV2c10_70_EventWeight_Light15_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_Light15_down", &MV2c10_70_EventWeight_Light15_down, &b_MV2c10_70_EventWeight_Light15_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_extrapolation_up", &MV2c10_70_EventWeight_extrapolation_up, &b_MV2c10_70_EventWeight_extrapolation_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_extrapolation_down", &MV2c10_70_EventWeight_extrapolation_down, &b_MV2c10_70_EventWeight_extrapolation_down);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_extrapolation_from_charm_up", &MV2c10_70_EventWeight_extrapolation_from_charm_up, &b_MV2c10_70_EventWeight_extrapolation_from_charm_up);
   fChain->SetBranchAddress("MV2c10_70_EventWeight_extrapolation_from_charm_down", &MV2c10_70_EventWeight_extrapolation_from_charm_down, &b_MV2c10_70_EventWeight_extrapolation_from_charm_down);
   fChain->SetBranchAddress("JVT_EventWeight_UP", &JVT_EventWeight_UP, &b_JVT_EventWeight_UP);
   fChain->SetBranchAddress("JVT_EventWeight_DOWN", &JVT_EventWeight_DOWN, &b_JVT_EventWeight_DOWN);
   fChain->SetBranchAddress("lepSFTrigLoose", &lepSFTrigLoose, &b_lepSFTrigLoose);
   fChain->SetBranchAddress("lepSFTrigTight", &lepSFTrigTight, &b_lepSFTrigTight);
   fChain->SetBranchAddress("lepSFObjLoose", &lepSFObjLoose, &b_lepSFObjLoose);
   fChain->SetBranchAddress("lepSFObjTight", &lepSFObjTight, &b_lepSFObjTight);
   fChain->SetBranchAddress("lepSFTrigTight_EL_SF_Trigger_UP", &lepSFTrigTight_EL_SF_Trigger_UP, &b_lepSFTrigTight_EL_SF_Trigger_UP);
   fChain->SetBranchAddress("lepSFTrigTight_EL_SF_Trigger_DOWN", &lepSFTrigTight_EL_SF_Trigger_DOWN, &b_lepSFTrigTight_EL_SF_Trigger_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_EL_SF_Reco_UP", &lepSFObjTight_EL_SF_Reco_UP, &b_lepSFObjTight_EL_SF_Reco_UP);
   fChain->SetBranchAddress("lepSFObjTight_EL_SF_Reco_DOWN", &lepSFObjTight_EL_SF_Reco_DOWN, &b_lepSFObjTight_EL_SF_Reco_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_EL_SF_ID_UP", &lepSFObjTight_EL_SF_ID_UP, &b_lepSFObjTight_EL_SF_ID_UP);
   fChain->SetBranchAddress("lepSFObjTight_EL_SF_ID_DOWN", &lepSFObjTight_EL_SF_ID_DOWN, &b_lepSFObjTight_EL_SF_ID_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_EL_SF_Isol_UP", &lepSFObjTight_EL_SF_Isol_UP, &b_lepSFObjTight_EL_SF_Isol_UP);
   fChain->SetBranchAddress("lepSFObjTight_EL_SF_Isol_DOWN", &lepSFObjTight_EL_SF_Isol_DOWN, &b_lepSFObjTight_EL_SF_Isol_DOWN);
   fChain->SetBranchAddress("lepSFTrigTight_MU_SF_Trigger_STAT_UP", &lepSFTrigTight_MU_SF_Trigger_STAT_UP, &b_lepSFTrigTight_MU_SF_Trigger_STAT_UP);
   fChain->SetBranchAddress("lepSFTrigTight_MU_SF_Trigger_STAT_DOWN", &lepSFTrigTight_MU_SF_Trigger_STAT_DOWN, &b_lepSFTrigTight_MU_SF_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("lepSFTrigTight_MU_SF_Trigger_SYST_UP", &lepSFTrigTight_MU_SF_Trigger_SYST_UP, &b_lepSFTrigTight_MU_SF_Trigger_SYST_UP);
   fChain->SetBranchAddress("lepSFTrigTight_MU_SF_Trigger_SYST_DOWN", &lepSFTrigTight_MU_SF_Trigger_SYST_DOWN, &b_lepSFTrigTight_MU_SF_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_STAT_UP", &lepSFObjTight_MU_SF_ID_STAT_UP, &b_lepSFObjTight_MU_SF_ID_STAT_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_STAT_DOWN", &lepSFObjTight_MU_SF_ID_STAT_DOWN, &b_lepSFObjTight_MU_SF_ID_STAT_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_SYST_UP", &lepSFObjTight_MU_SF_ID_SYST_UP, &b_lepSFObjTight_MU_SF_ID_SYST_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_SYST_DOWN", &lepSFObjTight_MU_SF_ID_SYST_DOWN, &b_lepSFObjTight_MU_SF_ID_SYST_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP", &lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP, &b_lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN", &lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN, &b_lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP", &lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP, &b_lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN", &lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN, &b_lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_Isol_STAT_UP", &lepSFObjTight_MU_SF_Isol_STAT_UP, &b_lepSFObjTight_MU_SF_Isol_STAT_UP);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_Isol_STAT_DOWN", &lepSFObjLoose_MU_SF_Isol_STAT_DOWN, &b_lepSFObjLoose_MU_SF_Isol_STAT_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_Isol_STAT_DOWN", &lepSFObjTight_MU_SF_Isol_STAT_DOWN, &b_lepSFObjTight_MU_SF_Isol_STAT_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_Isol_SYST_UP", &lepSFObjTight_MU_SF_Isol_SYST_UP, &b_lepSFObjTight_MU_SF_Isol_SYST_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_Isol_SYST_DOWN", &lepSFObjTight_MU_SF_Isol_SYST_DOWN, &b_lepSFObjTight_MU_SF_Isol_SYST_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_TTVA_STAT_UP", &lepSFObjTight_MU_SF_TTVA_STAT_UP, &b_lepSFObjTight_MU_SF_TTVA_STAT_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_TTVA_STAT_DOWN", &lepSFObjTight_MU_SF_TTVA_STAT_DOWN, &b_lepSFObjTight_MU_SF_TTVA_STAT_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_TTVA_SYST_UP", &lepSFObjTight_MU_SF_TTVA_SYST_UP, &b_lepSFObjTight_MU_SF_TTVA_SYST_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_TTVA_SYST_DOWN", &lepSFObjTight_MU_SF_TTVA_SYST_DOWN, &b_lepSFObjTight_MU_SF_TTVA_SYST_DOWN);
   fChain->SetBranchAddress("m_ll", &m_ll, &b_m_ll);
   fChain->SetBranchAddress("m_jj", &m_jj, &b_m_jj);
   fChain->SetBranchAddress("MET", &MET, &b_MET);
   fChain->SetBranchAddress("pt_leadinglepton", &pt_leadinglepton, &b_pt_leadinglepton);
   fChain->SetBranchAddress("pt_sublepton", &pt_sublepton, &b_pt_sublepton);
   fChain->SetBranchAddress("pt_j1", &pt_j1, &b_pt_j1);
   fChain->SetBranchAddress("pt_j2", &pt_j2, &b_pt_j2);
   fChain->SetBranchAddress("m_jj_w", &m_jj_w, &b_m_jj_w);
   fChain->SetBranchAddress("m_l1jj", &m_l1jj, &b_m_l1jj);
   fChain->SetBranchAddress("m_all", &m_all, &b_m_all);
   fChain->SetBranchAddress("pt_sum", &pt_sum, &b_pt_sum);
   fChain->SetBranchAddress("pt_vecsum", &pt_vecsum, &b_pt_vecsum);
   fChain->SetBranchAddress("mindR_l1j", &mindR_l1j, &b_mindR_l1j);
   fChain->SetBranchAddress("m_l1j", &m_l1j, &b_m_l1j);
   fChain->SetBranchAddress("mindR_l2j", &mindR_l2j, &b_mindR_l2j);
   fChain->SetBranchAddress("RMS", &RMS, &b_RMS);
   fChain->SetBranchAddress("m_l2j", &m_l2j, &b_m_l2j);
   fChain->SetBranchAddress("Mt", &Mt, &b_Mt);
   fChain->SetBranchAddress("weight", &weight, &b_weight);
   fChain->SetBranchAddress("channel", &channel, &b_channel);
   fChain->SetBranchAddress("category", &category, &b_category);
   fChain->SetBranchAddress("component", &component, &b_component);
   fChain->SetBranchAddress("numOfjet", &numOfjet, &b_numOfjet);
   fChain->SetBranchAddress("ChargeIDBDTTight_0", &ChargeIDBDTTight_0, &b_ChargeIDBDTTight_0);
   fChain->SetBranchAddress("ChargeIDBDTTight_1", &ChargeIDBDTTight_1, &b_ChargeIDBDTTight_1);
   fChain->SetBranchAddress("PromptLeptonIso_TagWeight_0", &PromptLeptonIso_TagWeight_0, &b_PromptLeptonIso_TagWeight_0);
   fChain->SetBranchAddress("PromptLeptonIso_TagWeight_1", &PromptLeptonIso_TagWeight_1, &b_PromptLeptonIso_TagWeight_1);
   Notify();
}

Bool_t miniNtuple::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void miniNtuple::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t miniNtuple::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef miniNtuple_cxx
