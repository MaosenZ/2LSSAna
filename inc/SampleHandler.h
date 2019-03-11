//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Mar 31 08:23:32 2017 by ROOT version 5.34/36
// from TTree Tree/MC
// found on file: /eos/atlas/user/x/xingguo/4w_ntuples/sig/343704.root
//////////////////////////////////////////////////////////

#ifndef SampleHandler_h
#define SampleHandler_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TPad.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>

// Header file for the classes stored in the TTree if any.
#include <vector>
using namespace std;
// Fixed size dimensions of array or collections stored in the TTree if any.

class SampleHandler {
public :
   TChain          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
   TString         dataset;
   Int_t           datasetType;
   TString         SysSrc;
   TString         SystematicType;
   // Declaration of leaf types
   Double_t        n_weight_tight;
   Double_t        n_weight_loose;
   Int_t           RunYear;
   Int_t           dilep_type;
   Int_t           trilep_type;
   Int_t           total_charge;
   Int_t           total_leptons;
   Double_t        MV2c10_70_EventWeight;
   Double_t        MV2c10_77_EventWeight;
   vector<float>   *jet_pt;
   vector<float>   *jet_eta;
   vector<float>   *jet_phi;
   vector<float>   *jet_E;
   vector<char>    *jet_passOR;
   vector<float>   *jet_flavor_weight_MV2c10;
   vector<float>   *jet_flavor_weight_MV2c00;
   vector<float>   *jet_flavor_weight_MV2c20;
   vector<short>   *selected_jets;
   Int_t           nJets_OR_MV2c10_70;
   Int_t           nJets_OR_MV2c10_77;
   Int_t           nJets_OR;
   Double_t        mcWeightOrg;
   Double_t        SherpaNJetWeight;
   Double_t        pileupEventWeight_090;
   Double_t        JVT_EventWeight;
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
   Float_t         lepSFTrigTight;//nominal
   //Double_t         lepSFTrigTight;//syst
   Float_t         lepSFObjLoose;
   Float_t         lepSFObjTight;
   //Double_t         lepSFObjTight; //syst
   vector<float>   *m_mcevt_pdf_X1;
   vector<float>   *m_mcevt_pdf_X2;
   vector<int>     *m_mcevt_pdf_PDGID1;
   vector<int>     *m_mcevt_pdf_PDGID2;
   vector<float>   *m_mcevt_pdf_Q;
   vector<float>   *m_mcevt_pdf_XF1;
   vector<float>   *m_mcevt_pdf_XF2;
   Float_t         lepSFTrigLoose_EL_SF_Trigger_UP;
   Float_t         lepSFTrigTight_EL_SF_Trigger_UP;
   Float_t         lepSFTrigLoose_EL_SF_Trigger_DOWN;
   Float_t         lepSFTrigTight_EL_SF_Trigger_DOWN;
   Float_t         lepSFObjLoose_EL_SF_Reco_UP;
   Float_t         lepSFObjTight_EL_SF_Reco_UP;
   Float_t         lepSFObjLoose_EL_SF_Reco_DOWN;
   Float_t         lepSFObjTight_EL_SF_Reco_DOWN;
   Float_t         lepSFObjLoose_EL_SF_ID_UP;
   Float_t         lepSFObjTight_EL_SF_ID_UP;
   Float_t         lepSFObjLoose_EL_SF_ID_DOWN;
   Float_t         lepSFObjTight_EL_SF_ID_DOWN;
   Float_t         lepSFObjLoose_EL_SF_Isol_UP;
   Float_t         lepSFObjTight_EL_SF_Isol_UP;
   Float_t         lepSFObjLoose_EL_SF_Isol_DOWN;
   Float_t         lepSFObjTight_EL_SF_Isol_DOWN;
   Float_t         lepSFTrigLoose_MU_SF_Trigger_STAT_UP;
   Float_t         lepSFTrigTight_MU_SF_Trigger_STAT_UP;
   Float_t         lepSFTrigLoose_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepSFTrigTight_MU_SF_Trigger_STAT_DOWN;
   Float_t         lepSFTrigLoose_MU_SF_Trigger_SYST_UP;
   Float_t         lepSFTrigTight_MU_SF_Trigger_SYST_UP;
   Float_t         lepSFTrigLoose_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepSFTrigTight_MU_SF_Trigger_SYST_DOWN;
   Float_t         lepSFObjLoose_MU_SF_ID_STAT_UP;
   Float_t         lepSFObjTight_MU_SF_ID_STAT_UP;
   Float_t         lepSFObjLoose_MU_SF_ID_STAT_DOWN;
   Float_t         lepSFObjTight_MU_SF_ID_STAT_DOWN;
   Float_t         lepSFObjLoose_MU_SF_ID_SYST_UP;
   Float_t         lepSFObjTight_MU_SF_ID_SYST_UP;
   Float_t         lepSFObjLoose_MU_SF_ID_SYST_DOWN;
   Float_t         lepSFObjTight_MU_SF_ID_SYST_DOWN;
   Float_t         lepSFObjLoose_MU_SF_ID_STAT_LOWPT_UP;
   Float_t         lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP;
   Float_t         lepSFObjLoose_MU_SF_ID_STAT_LOWPT_DOWN;
   Float_t         lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN;
   Float_t         lepSFObjLoose_MU_SF_ID_SYST_LOWPT_UP;
   Float_t         lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP;
   Float_t         lepSFObjLoose_MU_SF_ID_SYST_LOWPT_DOWN;
   Float_t         lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN;
   Float_t         lepSFObjLoose_MU_SF_Isol_STAT_UP;
   Float_t         lepSFObjTight_MU_SF_Isol_STAT_UP;
   Float_t         lepSFObjLoose_MU_SF_Isol_STAT_DOWN;
   Float_t         lepSFObjTight_MU_SF_Isol_STAT_DOWN;
   Float_t         lepSFObjLoose_MU_SF_Isol_SYST_UP;
   Float_t         lepSFObjTight_MU_SF_Isol_SYST_UP;
   Float_t         lepSFObjLoose_MU_SF_Isol_SYST_DOWN;
   Float_t         lepSFObjTight_MU_SF_Isol_SYST_DOWN;
   Float_t         lepSFObjLoose_MU_SF_TTVA_STAT_UP;
   Float_t         lepSFObjTight_MU_SF_TTVA_STAT_UP;
   Float_t         lepSFObjLoose_MU_SF_TTVA_STAT_DOWN;
   Float_t         lepSFObjTight_MU_SF_TTVA_STAT_DOWN;
   Float_t         lepSFObjLoose_MU_SF_TTVA_SYST_UP;
   Float_t         lepSFObjTight_MU_SF_TTVA_SYST_UP;
   Float_t         lepSFObjLoose_MU_SF_TTVA_SYST_DOWN;
   Float_t         lepSFObjTight_MU_SF_TTVA_SYST_DOWN;
   Float_t         MET_RefFinal_et;
   Float_t         MET_RefFinal_phi;
   Float_t         lep_ID_0;
   Float_t         lep_Pt_0;
   Float_t         lep_E_0;
   Float_t         lep_Eta_0;
   Float_t         lep_Phi_0;
   Float_t         lep_topoEtcone20_0;
   Float_t         lep_ptVarcone20_0;
   Float_t         lep_sigd0PV_0;
   Float_t         lep_Z0SinTheta_0;
   Float_t         lep_d0_0;
   Float_t         lep_z0_0;
   Char_t          lep_isTightLH_0;
   Char_t          lep_isMediumLH_0;
   Char_t          lep_isLooseLH_0;
   Char_t          lep_isTight_0;
   Char_t          lep_isMedium_0;
   Char_t          lep_isLoose_0;
   Int_t           lep_isolationLooseTrackOnly_0;
   Int_t           lep_isolationLoose_0;
   Int_t           lep_isolationGradient_0;
   Int_t           lep_isolationGradientLoose_0;
   Int_t           lep_isolationFixedCutTight_0;
   Int_t           lep_isolationFixedCutTightTrackOnly_0;
   Int_t           lep_isolationFixedCutLoose_0;
   Char_t          lep_isTrigMatch_0;
   Char_t          lep_isTrigMatchDLT_0;
   Char_t          lep_isPrompt_0;
   Char_t          lep_isISR_FSR_Ph_0;
   Char_t          lep_isBrems_0;
   Char_t          lep_isTruthMatched_0;
   Int_t           lep_truthType_0;
   Int_t           lep_truthOrigin_0;
   Int_t           lep_truthPdgId_0;
   Float_t         lep_ChargeIDBDTLoose_0;
   Float_t         lep_ChargeIDBDTMedium_0;
   Float_t         lep_ChargeIDBDTTight_0;
   Float_t         lep_PromptLeptonIso_TagWeight_0;
   Float_t         lep_ID_1;
   Float_t         lep_Pt_1;
   Float_t         lep_E_1;
   Float_t         lep_Eta_1;
   Float_t         lep_Phi_1;
   Float_t         lep_topoEtcone20_1;
   Float_t         lep_ptVarcone20_1;
   Float_t         lep_sigd0PV_1;
   Float_t         lep_Z0SinTheta_1;
   Float_t         lep_d0_1;
   Float_t         lep_z0_1;
   Char_t          lep_isTightLH_1;
   Char_t          lep_isMediumLH_1;
   Char_t          lep_isLooseLH_1;
   Char_t          lep_isTight_1;
   Char_t          lep_isMedium_1;
   Char_t          lep_isLoose_1;
   Int_t           lep_isolationLooseTrackOnly_1;
   Int_t           lep_isolationLoose_1;
   Int_t           lep_isolationGradient_1;
   Int_t           lep_isolationGradientLoose_1;
   Int_t           lep_isolationFixedCutTight_1;
   Int_t           lep_isolationFixedCutTightTrackOnly_1;
   Int_t           lep_isolationFixedCutLoose_1;
   Char_t          lep_isTrigMatch_1;
   Char_t          lep_isTrigMatchDLT_1;
   Char_t          lep_isPrompt_1;
   Char_t          lep_isISR_FSR_Ph_1;
   Char_t          lep_isBrems_1;
   Char_t          lep_isTruthMatched_1;
   Int_t           lep_truthType_1;
   Int_t           lep_truthOrigin_1;
   Int_t           lep_truthPdgId_1;
   Float_t         lep_ChargeIDBDTLoose_1;
   Float_t         lep_ChargeIDBDTMedium_1;
   Float_t         lep_ChargeIDBDTTight_1;
   Float_t         lep_PromptLeptonIso_TagWeight_1;
   Float_t         lep_ID_2;
   Float_t         lep_Pt_2;
   Float_t         lep_E_2;
   Float_t         lep_Eta_2;
   Float_t         lep_Phi_2;
   Float_t         lep_topoEtcone20_2;
   Float_t         lep_ptVarcone20_2;
   Float_t         lep_sigd0PV_2;
   Float_t         lep_Z0SinTheta_2;
   Float_t         lep_d0_2;
   Float_t         lep_z0_2;
   Char_t          lep_isTightLH_2;
   Char_t          lep_isMediumLH_2;
   Char_t          lep_isLooseLH_2;
   Char_t          lep_isTight_2;
   Char_t          lep_isMedium_2;
   Char_t          lep_isLoose_2;
   Int_t           lep_isolationLooseTrackOnly_2;
   Int_t           lep_isolationLoose_2;
   Int_t           lep_isolationGradient_2;
   Int_t           lep_isolationGradientLoose_2;
   Int_t           lep_isolationFixedCutTight_2;
   Int_t           lep_isolationFixedCutTightTrackOnly_2;
   Int_t           lep_isolationFixedCutLoose_2;
   Char_t          lep_isTrigMatch_2;
   Char_t          lep_isTrigMatchDLT_2;
   Char_t          lep_isPrompt_2;
   Char_t          lep_isFakeLep_2;
   Char_t          lep_isBrems_2;
   Char_t          lep_isTruthMatched_2;
   Int_t           lep_truthType_2;
   Int_t           lep_truthOrigin_2;
   Int_t           lep_truthPdgId_2;
   Float_t         lep_ChargeIDBDTLoose_2;
   Float_t         lep_ChargeIDBDTMedium_2;
   Float_t         lep_ChargeIDBDTTight_2;
   Float_t         lep_PromptLeptonIso_TagWeight_2;

   // List of branches
   TBranch        *b_weight_tight;   //!
   TBranch        *b_weight_loose;   //!
   TBranch        *b_RunYear;   //!
   TBranch        *b_dilep_type;   //!
   TBranch        *b_trilep_type;   //!
   TBranch        *b_total_charge;   //!
   TBranch        *b_total_leptons;   //!
   TBranch        *b_MV2c10_70_EventWeight;   //!
   TBranch        *b_MV2c10_77_EventWeight;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_E;   //!
   TBranch        *b_jet_passOR;   //!
   TBranch        *b_jet_flavor_weight_MV2c10;   //!
   TBranch        *b_jet_flavor_weight_MV2c00;   //!
   TBranch        *b_jet_flavor_weight_MV2c20;   //!
   TBranch        *b_selected_jets;   //!
   TBranch        *b_nJets_OR_MV2c10_70;   //!
   TBranch        *b_nJets_OR_MV2c10_77;   //!
   TBranch        *b_nJets_OR;   //!
   TBranch        *b_mcWeightOrg;   //!
   TBranch        *b_SherpaNJetWeight;   //!
   TBranch        *b_pileupEventWeight_090;   //!
   TBranch        *b_JVT_EventWeight;   //!
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
   TBranch        *b_m_mcevt_pdf_X1;   //!
   TBranch        *b_m_mcevt_pdf_X2;   //!
   TBranch        *b_m_mcevt_pdf_PDGID1;   //!
   TBranch        *b_m_mcevt_pdf_PDGID2;   //!
   TBranch        *b_m_mcevt_pdf_Q;   //!
   TBranch        *b_m_mcevt_pdf_XF1;   //!
   TBranch        *b_m_mcevt_pdf_XF2;   //!
   TBranch        *b_lepSFTrigLoose_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepSFTrigTight_EL_SF_Trigger_UP;   //!
   TBranch        *b_lepSFTrigLoose_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepSFTrigTight_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_lepSFObjLoose_EL_SF_Reco_UP;   //!
   TBranch        *b_lepSFObjTight_EL_SF_Reco_UP;   //!
   TBranch        *b_lepSFObjLoose_EL_SF_Reco_DOWN;   //!
   TBranch        *b_lepSFObjTight_EL_SF_Reco_DOWN;   //!
   TBranch        *b_lepSFObjLoose_EL_SF_ID_UP;   //!
   TBranch        *b_lepSFObjTight_EL_SF_ID_UP;   //!
   TBranch        *b_lepSFObjLoose_EL_SF_ID_DOWN;   //!
   TBranch        *b_lepSFObjTight_EL_SF_ID_DOWN;   //!
   TBranch        *b_lepSFObjLoose_EL_SF_Isol_UP;   //!
   TBranch        *b_lepSFObjTight_EL_SF_Isol_UP;   //!
   TBranch        *b_lepSFObjLoose_EL_SF_Isol_DOWN;   //!
   TBranch        *b_lepSFObjTight_EL_SF_Isol_DOWN;   //!
   TBranch        *b_lepSFTrigLoose_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepSFTrigTight_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_lepSFTrigLoose_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepSFTrigTight_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_lepSFTrigLoose_MU_SF_Trigger_SYST_UP;   //!
   TBranch        *b_lepSFTrigTight_MU_SF_Trigger_SYST_UP;   //!
   TBranch        *b_lepSFTrigLoose_MU_SF_Trigger_SYST_DOWN;   //!
   TBranch        *b_lepSFTrigTight_MU_SF_Trigger_SYST_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_STAT_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_STAT_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_STAT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_STAT_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_SYST_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_SYST_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_SYST_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_SYST_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_STAT_LOWPT_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_STAT_LOWPT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_SYST_LOWPT_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_ID_SYST_LOWPT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_Isol_STAT_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_Isol_STAT_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_Isol_STAT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_Isol_STAT_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_Isol_SYST_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_Isol_SYST_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_Isol_SYST_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_Isol_SYST_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_TTVA_STAT_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_TTVA_STAT_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_TTVA_STAT_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_TTVA_STAT_DOWN;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_TTVA_SYST_UP;   //!
   TBranch        *b_lepSFObjTight_MU_SF_TTVA_SYST_UP;   //!
   TBranch        *b_lepSFObjLoose_MU_SF_TTVA_SYST_DOWN;   //!
   TBranch        *b_lepSFObjTight_MU_SF_TTVA_SYST_DOWN;   //!
   TBranch        *b_MET_RefFinal_et;   //!
   TBranch        *b_MET_RefFinal_phi;   //!
   TBranch        *b_lep_ID_0;   //!
   TBranch        *b_lep_Pt_0;   //!
   TBranch        *b_lep_E_0;   //!
   TBranch        *b_lep_Eta_0;   //!
   TBranch        *b_lep_Phi_0;   //!
   TBranch        *b_lep_topoEtcone20_0;   //!
   TBranch        *b_lep_ptVarcone20_0;   //!
   TBranch        *b_lep_sigd0PV_0;   //!
   TBranch        *b_lep_Z0SinTheta_0;   //!
   TBranch        *b_lep_d0_0;   //!
   TBranch        *b_lep_z0_0;   //!
   TBranch        *b_lep_isTightLH_0;   //!
   TBranch        *b_lep_isMediumLH_0;   //!
   TBranch        *b_lep_isLooseLH_0;   //!
   TBranch        *b_lep_isTight_0;   //!
   TBranch        *b_lep_isMedium_0;   //!
   TBranch        *b_lep_isLoose_0;   //!
   TBranch        *b_lep_isolationLooseTrackOnly_0;   //!
   TBranch        *b_lep_isolationLoose_0;   //!
   TBranch        *b_lep_isolationGradient_0;   //!
   TBranch        *b_lep_isolationGradientLoose_0;   //!
   TBranch        *b_lep_isolationFixedCutTight_0;   //!
   TBranch        *b_lep_isolationFixedCutTightTrackOnly_0;   //!
   TBranch        *b_lep_isolationFixedCutLoose_0;   //!
   TBranch        *b_lep_isTrigMatch_0;   //!
   TBranch        *b_lep_isTrigMatchDLT_0;   //!
   TBranch        *b_lep_isPrompt_0;   //!
   TBranch        *b_lep_isISR_FSR_Ph_0;   //!
   TBranch        *b_lep_isBrems_0;   //!
   TBranch        *b_lep_isTruthMatched_0;   //!
   TBranch        *b_lep_truthType_0;   //!
   TBranch        *b_lep_truthOrigin_0;   //!
   TBranch        *b_lep_truthPdgId_0;   //!
   TBranch        *b_lep_ChargeIDBDTLoose_0;   //!
   TBranch        *b_lep_ChargeIDBDTMedium_0;   //!
   TBranch        *b_lep_ChargeIDBDTTight_0;   //!
   TBranch        *b_lep_PromptLeptonIso_TagWeight_0;   //!
   TBranch        *b_lep_ID_1;   //!
   TBranch        *b_lep_Pt_1;   //!
   TBranch        *b_lep_E_1;   //!
   TBranch        *b_lep_Eta_1;   //!
   TBranch        *b_lep_Phi_1;   //!
   TBranch        *b_lep_topoEtcone20_1;   //!
   TBranch        *b_lep_ptVarcone20_1;   //!
   TBranch        *b_lep_sigd0PV_1;   //!
   TBranch        *b_lep_Z0SinTheta_1;   //!
   TBranch        *b_lep_d0_1;   //!
   TBranch        *b_lep_z0_1;   //!
   TBranch        *b_lep_isTightLH_1;   //!
   TBranch        *b_lep_isMediumLH_1;   //!
   TBranch        *b_lep_isLooseLH_1;   //!
   TBranch        *b_lep_isTight_1;   //!
   TBranch        *b_lep_isMedium_1;   //!
   TBranch        *b_lep_isLoose_1;   //!
   TBranch        *b_lep_isolationLooseTrackOnly_1;   //!
   TBranch        *b_lep_isolationLoose_1;   //!
   TBranch        *b_lep_isolationGradient_1;   //!
   TBranch        *b_lep_isolationGradientLoose_1;   //!
   TBranch        *b_lep_isolationFixedCutTight_1;   //!
   TBranch        *b_lep_isolationFixedCutTightTrackOnly_1;   //!
   TBranch        *b_lep_isolationFixedCutLoose_1;   //!
   TBranch        *b_lep_isTrigMatch_1;   //!
   TBranch        *b_lep_isTrigMatchDLT_1;   //!
   TBranch        *b_lep_isPrompt_1;   //!
   TBranch        *b_lep_isISR_FSR_Ph_1;   //!
   TBranch        *b_lep_isBrems_1;   //!
   TBranch        *b_lep_isTruthMatched_1;   //!
   TBranch        *b_lep_truthType_1;   //!
   TBranch        *b_lep_truthOrigin_1;   //!
   TBranch        *b_lep_truthPdgId_1;   //!
   TBranch        *b_lep_ChargeIDBDTLoose_1;   //!
   TBranch        *b_lep_ChargeIDBDTMedium_1;   //!
   TBranch        *b_lep_ChargeIDBDTTight_1;   //!
   TBranch        *b_lep_PromptLeptonIso_TagWeight_1;   //!
   TBranch        *b_lep_ID_2;   //!
   TBranch        *b_lep_Pt_2;   //!
   TBranch        *b_lep_E_2;   //!
   TBranch        *b_lep_Eta_2;   //!
   TBranch        *b_lep_Phi_2;   //!
   TBranch        *b_lep_topoEtcone20_2;   //!
   TBranch        *b_lep_ptVarcone20_2;   //!
   TBranch        *b_lep_sigd0PV_2;   //!
   TBranch        *b_lep_Z0SinTheta_2;   //!
   TBranch        *b_lep_d0_2;   //!
   TBranch        *b_lep_z0_2;   //!
   TBranch        *b_lep_isTightLH_2;   //!
   TBranch        *b_lep_isMediumLH_2;   //!
   TBranch        *b_lep_isLooseLH_2;   //!
   TBranch        *b_lep_isTight_2;   //!
   TBranch        *b_lep_isMedium_2;   //!
   TBranch        *b_lep_isLoose_2;   //!
   TBranch        *b_lep_isolationLooseTrackOnly_2;   //!
   TBranch        *b_lep_isolationLoose_2;   //!
   TBranch        *b_lep_isolationGradient_2;   //!
   TBranch        *b_lep_isolationGradientLoose_2;   //!
   TBranch        *b_lep_isolationFixedCutTight_2;   //!
   TBranch        *b_lep_isolationFixedCutTightTrackOnly_2;   //!
   TBranch        *b_lep_isolationFixedCutLoose_2;   //!
   TBranch        *b_lep_isTrigMatch_2;   //!
   TBranch        *b_lep_isTrigMatchDLT_2;   //!
   TBranch        *b_lep_isPrompt_2;   //!
   TBranch        *b_lep_isFakeLep_2;   //!
   TBranch        *b_lep_isBrems_2;   //!
   TBranch        *b_lep_isTruthMatched_2;   //!
   TBranch        *b_lep_truthType_2;   //!
   TBranch        *b_lep_truthOrigin_2;   //!
   TBranch        *b_lep_truthPdgId_2;   //!
   TBranch        *b_lep_ChargeIDBDTLoose_2;   //!
   TBranch        *b_lep_ChargeIDBDTMedium_2;   //!
   TBranch        *b_lep_ChargeIDBDTTight_2;   //!
   TBranch        *b_lep_PromptLeptonIso_TagWeight_2;   //!

   //SampleHandler(TString input,TString SysSrc);
   SampleHandler(TString input);
   virtual ~SampleHandler();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TChain *tree);
   virtual void     Loop(TString config);
   virtual void     cutflow(Int_t Njets);
   virtual void     makeNtuple(TString type, TString CRSel);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef SampleHandler_cxx
//SampleHandler::SampleHandler(TString input,TString nSysSrc) : fChain(0) 
SampleHandler::SampleHandler(TString input) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   TString inputFile;
   TChain *chain=new TChain("Tree");
   TString inputList="inc/"+input+".list";
   ifstream ifile(inputList.Data(),ifstream::in);
   string line;
   while(getline(ifile,line)){
       char dsid[200];
       Float_t xsec, kfactor, filterEff;
       const char* readline=line.c_str();
       sscanf(readline,"%s %f %f %f",dsid,&xsec,&kfactor,&filterEff);
       if(dsid[0]=='#') continue;
       if(input=="datacombined") {
          inputFile="/publicfs/atlas/atlasnew/higgs/hgg/zhoums/4W/v27.01/data/";
          inputFile+=dsid;
          datasetType=1;
       }
       if(input!="datacombined"&&(input.Contains("mH")||input.Contains("nonres")||input.Contains("H280")||input.Contains("H300")||input.Contains("H320")||input.Contains("H340")||input.Contains("signal"))){
          inputFile="/publicfs/atlas/atlasnew/higgs/hgg/zhoums/4W/v27.01/nominal/";
          inputFile+=dsid;
          datasetType=1;
       }
       if((input!="datacombined")&&(!(input.Contains("mH")||input.Contains("nonres")||input.Contains("H280")||input.Contains("H300")||input.Contains("H320")||input.Contains("H340")))){
          inputFile="/publicfs/atlas/atlasnew/higgs/hgg/zhoums/4W/v27.01/nominal/";
          inputFile+=dsid;
          datasetType=4;//always truthing matching
          if(input=="Vgam")datasetType=2;//no truth matching
          if(input=="ttbar"||input=="DY"||input=="Zjets"||input=="WW") datasetType=3;//with truth matching, but won't be filled for mumu channel
       }
       chain->Add(inputFile);
   }
   //NonEventWeight Sys codes 
   /*TChain *chain=new TChain(nSysSrc);
   cout<<nSysSrc<<endl;
   inputFile="/publicfs/atlas/atlasnew/higgs/hgg/zhoums/4W/v27.01/sys/";
   inputFile+=nSysSrc;
   inputFile+="/ntuples_";
   inputFile+=input;
   inputFile+=".root";
   SysSrc=nSysSrc;
   SystematicType="NonEventWeight";
   if(input=="Vgam") datasetType=2;//no truth matching
   if(input.Contains("mH")||input.Contains("nonres")||input.Contains("S135")||input.Contains("H340")) datasetType=1;
   if(input!="Vgam" && (!input.Contains("mH")) && (!input.Contains("nonres"))) datasetType=4;//always truthing matching
   chain->Add(inputFile);*/ 

   dataset=input;
   Init(chain);
}

SampleHandler::~SampleHandler()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t SampleHandler::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t SampleHandler::LoadTree(Long64_t entry)
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

void SampleHandler::Init(TChain *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   jet_pt = 0;
   jet_eta = 0;
   jet_phi = 0;
   jet_E = 0;
   jet_passOR = 0;
   jet_flavor_weight_MV2c10 = 0;
   jet_flavor_weight_MV2c00 = 0;
   jet_flavor_weight_MV2c20 = 0;
   selected_jets = 0;
   m_mcevt_pdf_X1 = 0;
   m_mcevt_pdf_X2 = 0;
   m_mcevt_pdf_PDGID1 = 0;
   m_mcevt_pdf_PDGID2 = 0;
   m_mcevt_pdf_Q = 0;
   m_mcevt_pdf_XF1 = 0;
   m_mcevt_pdf_XF2 = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("weight_tight", &n_weight_tight, &b_weight_tight);
   fChain->SetBranchAddress("weight_loose", &n_weight_loose, &b_weight_loose);
   fChain->SetBranchAddress("RunYear", &RunYear, &b_RunYear);
   fChain->SetBranchAddress("dilep_type", &dilep_type, &b_dilep_type);
   fChain->SetBranchAddress("trilep_type", &trilep_type, &b_trilep_type);
   fChain->SetBranchAddress("total_charge", &total_charge, &b_total_charge);
   fChain->SetBranchAddress("total_leptons", &total_leptons, &b_total_leptons);
   fChain->SetBranchAddress("MV2c10_70_EventWeight", &MV2c10_70_EventWeight, &b_MV2c10_70_EventWeight);
   fChain->SetBranchAddress("MV2c10_77_EventWeight", &MV2c10_77_EventWeight, &b_MV2c10_77_EventWeight);
   fChain->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_E", &jet_E, &b_jet_E);
   fChain->SetBranchAddress("jet_passOR", &jet_passOR, &b_jet_passOR);
   fChain->SetBranchAddress("jet_flavor_weight_MV2c10", &jet_flavor_weight_MV2c10, &b_jet_flavor_weight_MV2c10);
   fChain->SetBranchAddress("jet_flavor_weight_MV2c00", &jet_flavor_weight_MV2c00, &b_jet_flavor_weight_MV2c00);
   fChain->SetBranchAddress("jet_flavor_weight_MV2c20", &jet_flavor_weight_MV2c20, &b_jet_flavor_weight_MV2c20);
   fChain->SetBranchAddress("selected_jets", &selected_jets, &b_selected_jets);
   fChain->SetBranchAddress("nJets_OR_MV2c10_70", &nJets_OR_MV2c10_70, &b_nJets_OR_MV2c10_70);
   fChain->SetBranchAddress("nJets_OR_MV2c10_77", &nJets_OR_MV2c10_77, &b_nJets_OR_MV2c10_77);
   fChain->SetBranchAddress("nJets_OR", &nJets_OR, &b_nJets_OR);
   fChain->SetBranchAddress("mcWeightOrg", &mcWeightOrg, &b_mcWeightOrg);
   fChain->SetBranchAddress("SherpaNJetWeight", &SherpaNJetWeight, &b_SherpaNJetWeight);
   fChain->SetBranchAddress("pileupEventWeight_090", &pileupEventWeight_090, &b_pileupEventWeight_090);
   fChain->SetBranchAddress("JVT_EventWeight", &JVT_EventWeight, &b_JVT_EventWeight);
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
   fChain->SetBranchAddress("m_mcevt_pdf_X1", &m_mcevt_pdf_X1, &b_m_mcevt_pdf_X1);
   fChain->SetBranchAddress("m_mcevt_pdf_X2", &m_mcevt_pdf_X2, &b_m_mcevt_pdf_X2);
   fChain->SetBranchAddress("m_mcevt_pdf_PDGID1", &m_mcevt_pdf_PDGID1, &b_m_mcevt_pdf_PDGID1);
   fChain->SetBranchAddress("m_mcevt_pdf_PDGID2", &m_mcevt_pdf_PDGID2, &b_m_mcevt_pdf_PDGID2);
   fChain->SetBranchAddress("m_mcevt_pdf_Q", &m_mcevt_pdf_Q, &b_m_mcevt_pdf_Q);
   fChain->SetBranchAddress("m_mcevt_pdf_XF1", &m_mcevt_pdf_XF1, &b_m_mcevt_pdf_XF1);
   fChain->SetBranchAddress("m_mcevt_pdf_XF2", &m_mcevt_pdf_XF2, &b_m_mcevt_pdf_XF2);
   fChain->SetBranchAddress("lepSFTrigLoose_EL_SF_Trigger_UP", &lepSFTrigLoose_EL_SF_Trigger_UP, &b_lepSFTrigLoose_EL_SF_Trigger_UP);
   fChain->SetBranchAddress("lepSFTrigTight_EL_SF_Trigger_UP", &lepSFTrigTight_EL_SF_Trigger_UP, &b_lepSFTrigTight_EL_SF_Trigger_UP);
   fChain->SetBranchAddress("lepSFTrigLoose_EL_SF_Trigger_DOWN", &lepSFTrigLoose_EL_SF_Trigger_DOWN, &b_lepSFTrigLoose_EL_SF_Trigger_DOWN);
   fChain->SetBranchAddress("lepSFTrigTight_EL_SF_Trigger_DOWN", &lepSFTrigTight_EL_SF_Trigger_DOWN, &b_lepSFTrigTight_EL_SF_Trigger_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_EL_SF_Reco_UP", &lepSFObjLoose_EL_SF_Reco_UP, &b_lepSFObjLoose_EL_SF_Reco_UP);
   fChain->SetBranchAddress("lepSFObjTight_EL_SF_Reco_UP", &lepSFObjTight_EL_SF_Reco_UP, &b_lepSFObjTight_EL_SF_Reco_UP);
   fChain->SetBranchAddress("lepSFObjLoose_EL_SF_Reco_DOWN", &lepSFObjLoose_EL_SF_Reco_DOWN, &b_lepSFObjLoose_EL_SF_Reco_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_EL_SF_Reco_DOWN", &lepSFObjTight_EL_SF_Reco_DOWN, &b_lepSFObjTight_EL_SF_Reco_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_EL_SF_ID_UP", &lepSFObjLoose_EL_SF_ID_UP, &b_lepSFObjLoose_EL_SF_ID_UP);
   fChain->SetBranchAddress("lepSFObjTight_EL_SF_ID_UP", &lepSFObjTight_EL_SF_ID_UP, &b_lepSFObjTight_EL_SF_ID_UP);
   fChain->SetBranchAddress("lepSFObjLoose_EL_SF_ID_DOWN", &lepSFObjLoose_EL_SF_ID_DOWN, &b_lepSFObjLoose_EL_SF_ID_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_EL_SF_ID_DOWN", &lepSFObjTight_EL_SF_ID_DOWN, &b_lepSFObjTight_EL_SF_ID_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_EL_SF_Isol_UP", &lepSFObjLoose_EL_SF_Isol_UP, &b_lepSFObjLoose_EL_SF_Isol_UP);
   fChain->SetBranchAddress("lepSFObjTight_EL_SF_Isol_UP", &lepSFObjTight_EL_SF_Isol_UP, &b_lepSFObjTight_EL_SF_Isol_UP);
   fChain->SetBranchAddress("lepSFObjLoose_EL_SF_Isol_DOWN", &lepSFObjLoose_EL_SF_Isol_DOWN, &b_lepSFObjLoose_EL_SF_Isol_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_EL_SF_Isol_DOWN", &lepSFObjTight_EL_SF_Isol_DOWN, &b_lepSFObjTight_EL_SF_Isol_DOWN);
   fChain->SetBranchAddress("lepSFTrigLoose_MU_SF_Trigger_STAT_UP", &lepSFTrigLoose_MU_SF_Trigger_STAT_UP, &b_lepSFTrigLoose_MU_SF_Trigger_STAT_UP);
   fChain->SetBranchAddress("lepSFTrigTight_MU_SF_Trigger_STAT_UP", &lepSFTrigTight_MU_SF_Trigger_STAT_UP, &b_lepSFTrigTight_MU_SF_Trigger_STAT_UP);
   fChain->SetBranchAddress("lepSFTrigLoose_MU_SF_Trigger_STAT_DOWN", &lepSFTrigLoose_MU_SF_Trigger_STAT_DOWN, &b_lepSFTrigLoose_MU_SF_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("lepSFTrigTight_MU_SF_Trigger_STAT_DOWN", &lepSFTrigTight_MU_SF_Trigger_STAT_DOWN, &b_lepSFTrigTight_MU_SF_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("lepSFTrigLoose_MU_SF_Trigger_SYST_UP", &lepSFTrigLoose_MU_SF_Trigger_SYST_UP, &b_lepSFTrigLoose_MU_SF_Trigger_SYST_UP);
   fChain->SetBranchAddress("lepSFTrigTight_MU_SF_Trigger_SYST_UP", &lepSFTrigTight_MU_SF_Trigger_SYST_UP, &b_lepSFTrigTight_MU_SF_Trigger_SYST_UP);
   fChain->SetBranchAddress("lepSFTrigLoose_MU_SF_Trigger_SYST_DOWN", &lepSFTrigLoose_MU_SF_Trigger_SYST_DOWN, &b_lepSFTrigLoose_MU_SF_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("lepSFTrigTight_MU_SF_Trigger_SYST_DOWN", &lepSFTrigTight_MU_SF_Trigger_SYST_DOWN, &b_lepSFTrigTight_MU_SF_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_ID_STAT_UP", &lepSFObjLoose_MU_SF_ID_STAT_UP, &b_lepSFObjLoose_MU_SF_ID_STAT_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_STAT_UP", &lepSFObjTight_MU_SF_ID_STAT_UP, &b_lepSFObjTight_MU_SF_ID_STAT_UP);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_ID_STAT_DOWN", &lepSFObjLoose_MU_SF_ID_STAT_DOWN, &b_lepSFObjLoose_MU_SF_ID_STAT_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_STAT_DOWN", &lepSFObjTight_MU_SF_ID_STAT_DOWN, &b_lepSFObjTight_MU_SF_ID_STAT_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_ID_SYST_UP", &lepSFObjLoose_MU_SF_ID_SYST_UP, &b_lepSFObjLoose_MU_SF_ID_SYST_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_SYST_UP", &lepSFObjTight_MU_SF_ID_SYST_UP, &b_lepSFObjTight_MU_SF_ID_SYST_UP);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_ID_SYST_DOWN", &lepSFObjLoose_MU_SF_ID_SYST_DOWN, &b_lepSFObjLoose_MU_SF_ID_SYST_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_SYST_DOWN", &lepSFObjTight_MU_SF_ID_SYST_DOWN, &b_lepSFObjTight_MU_SF_ID_SYST_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_ID_STAT_LOWPT_UP", &lepSFObjLoose_MU_SF_ID_STAT_LOWPT_UP, &b_lepSFObjLoose_MU_SF_ID_STAT_LOWPT_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP", &lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP, &b_lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_ID_STAT_LOWPT_DOWN", &lepSFObjLoose_MU_SF_ID_STAT_LOWPT_DOWN, &b_lepSFObjLoose_MU_SF_ID_STAT_LOWPT_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN", &lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN, &b_lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_ID_SYST_LOWPT_UP", &lepSFObjLoose_MU_SF_ID_SYST_LOWPT_UP, &b_lepSFObjLoose_MU_SF_ID_SYST_LOWPT_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP", &lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP, &b_lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_ID_SYST_LOWPT_DOWN", &lepSFObjLoose_MU_SF_ID_SYST_LOWPT_DOWN, &b_lepSFObjLoose_MU_SF_ID_SYST_LOWPT_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN", &lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN, &b_lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_Isol_STAT_UP", &lepSFObjLoose_MU_SF_Isol_STAT_UP, &b_lepSFObjLoose_MU_SF_Isol_STAT_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_Isol_STAT_UP", &lepSFObjTight_MU_SF_Isol_STAT_UP, &b_lepSFObjTight_MU_SF_Isol_STAT_UP);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_Isol_STAT_DOWN", &lepSFObjLoose_MU_SF_Isol_STAT_DOWN, &b_lepSFObjLoose_MU_SF_Isol_STAT_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_Isol_STAT_DOWN", &lepSFObjTight_MU_SF_Isol_STAT_DOWN, &b_lepSFObjTight_MU_SF_Isol_STAT_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_Isol_SYST_UP", &lepSFObjLoose_MU_SF_Isol_SYST_UP, &b_lepSFObjLoose_MU_SF_Isol_SYST_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_Isol_SYST_UP", &lepSFObjTight_MU_SF_Isol_SYST_UP, &b_lepSFObjTight_MU_SF_Isol_SYST_UP);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_Isol_SYST_DOWN", &lepSFObjLoose_MU_SF_Isol_SYST_DOWN, &b_lepSFObjLoose_MU_SF_Isol_SYST_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_Isol_SYST_DOWN", &lepSFObjTight_MU_SF_Isol_SYST_DOWN, &b_lepSFObjTight_MU_SF_Isol_SYST_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_TTVA_STAT_UP", &lepSFObjLoose_MU_SF_TTVA_STAT_UP, &b_lepSFObjLoose_MU_SF_TTVA_STAT_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_TTVA_STAT_UP", &lepSFObjTight_MU_SF_TTVA_STAT_UP, &b_lepSFObjTight_MU_SF_TTVA_STAT_UP);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_TTVA_STAT_DOWN", &lepSFObjLoose_MU_SF_TTVA_STAT_DOWN, &b_lepSFObjLoose_MU_SF_TTVA_STAT_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_TTVA_STAT_DOWN", &lepSFObjTight_MU_SF_TTVA_STAT_DOWN, &b_lepSFObjTight_MU_SF_TTVA_STAT_DOWN);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_TTVA_SYST_UP", &lepSFObjLoose_MU_SF_TTVA_SYST_UP, &b_lepSFObjLoose_MU_SF_TTVA_SYST_UP);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_TTVA_SYST_UP", &lepSFObjTight_MU_SF_TTVA_SYST_UP, &b_lepSFObjTight_MU_SF_TTVA_SYST_UP);
   fChain->SetBranchAddress("lepSFObjLoose_MU_SF_TTVA_SYST_DOWN", &lepSFObjLoose_MU_SF_TTVA_SYST_DOWN, &b_lepSFObjLoose_MU_SF_TTVA_SYST_DOWN);
   fChain->SetBranchAddress("lepSFObjTight_MU_SF_TTVA_SYST_DOWN", &lepSFObjTight_MU_SF_TTVA_SYST_DOWN, &b_lepSFObjTight_MU_SF_TTVA_SYST_DOWN);
   fChain->SetBranchAddress("MET_RefFinal_et", &MET_RefFinal_et, &b_MET_RefFinal_et);
   fChain->SetBranchAddress("MET_RefFinal_phi", &MET_RefFinal_phi, &b_MET_RefFinal_phi);
   fChain->SetBranchAddress("lep_ID_0", &lep_ID_0, &b_lep_ID_0);
   fChain->SetBranchAddress("lep_Pt_0", &lep_Pt_0, &b_lep_Pt_0);
   fChain->SetBranchAddress("lep_E_0", &lep_E_0, &b_lep_E_0);
   fChain->SetBranchAddress("lep_Eta_0", &lep_Eta_0, &b_lep_Eta_0);
   fChain->SetBranchAddress("lep_Phi_0", &lep_Phi_0, &b_lep_Phi_0);
   fChain->SetBranchAddress("lep_topoEtcone20_0", &lep_topoEtcone20_0, &b_lep_topoEtcone20_0);
   fChain->SetBranchAddress("lep_ptVarcone20_0", &lep_ptVarcone20_0, &b_lep_ptVarcone20_0);
   fChain->SetBranchAddress("lep_sigd0PV_0", &lep_sigd0PV_0, &b_lep_sigd0PV_0);
   fChain->SetBranchAddress("lep_Z0SinTheta_0", &lep_Z0SinTheta_0, &b_lep_Z0SinTheta_0);
   fChain->SetBranchAddress("lep_d0_0", &lep_d0_0, &b_lep_d0_0);
   fChain->SetBranchAddress("lep_z0_0", &lep_z0_0, &b_lep_z0_0);
   fChain->SetBranchAddress("lep_isTightLH_0", &lep_isTightLH_0, &b_lep_isTightLH_0);
   fChain->SetBranchAddress("lep_isMediumLH_0", &lep_isMediumLH_0, &b_lep_isMediumLH_0);
   fChain->SetBranchAddress("lep_isLooseLH_0", &lep_isLooseLH_0, &b_lep_isLooseLH_0);
   fChain->SetBranchAddress("lep_isTight_0", &lep_isTight_0, &b_lep_isTight_0);
   fChain->SetBranchAddress("lep_isMedium_0", &lep_isMedium_0, &b_lep_isMedium_0);
   fChain->SetBranchAddress("lep_isLoose_0", &lep_isLoose_0, &b_lep_isLoose_0);
   fChain->SetBranchAddress("lep_isolationLooseTrackOnly_0", &lep_isolationLooseTrackOnly_0, &b_lep_isolationLooseTrackOnly_0);
   fChain->SetBranchAddress("lep_isolationLoose_0", &lep_isolationLoose_0, &b_lep_isolationLoose_0);
   fChain->SetBranchAddress("lep_isolationGradient_0", &lep_isolationGradient_0, &b_lep_isolationGradient_0);
   fChain->SetBranchAddress("lep_isolationGradientLoose_0", &lep_isolationGradientLoose_0, &b_lep_isolationGradientLoose_0);
   fChain->SetBranchAddress("lep_isolationFixedCutTight_0", &lep_isolationFixedCutTight_0, &b_lep_isolationFixedCutTight_0);
   fChain->SetBranchAddress("lep_isolationFixedCutTightTrackOnly_0", &lep_isolationFixedCutTightTrackOnly_0, &b_lep_isolationFixedCutTightTrackOnly_0);
   fChain->SetBranchAddress("lep_isolationFixedCutLoose_0", &lep_isolationFixedCutLoose_0, &b_lep_isolationFixedCutLoose_0);
   fChain->SetBranchAddress("lep_isTrigMatch_0", &lep_isTrigMatch_0, &b_lep_isTrigMatch_0);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_0", &lep_isTrigMatchDLT_0, &b_lep_isTrigMatchDLT_0);
   fChain->SetBranchAddress("lep_isPrompt_0", &lep_isPrompt_0, &b_lep_isPrompt_0);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_0", &lep_isISR_FSR_Ph_0, &b_lep_isISR_FSR_Ph_0);
   fChain->SetBranchAddress("lep_isBrems_0", &lep_isBrems_0, &b_lep_isBrems_0);
   fChain->SetBranchAddress("lep_isTruthMatched_0", &lep_isTruthMatched_0, &b_lep_isTruthMatched_0);
   fChain->SetBranchAddress("lep_truthType_0", &lep_truthType_0, &b_lep_truthType_0);
   fChain->SetBranchAddress("lep_truthOrigin_0", &lep_truthOrigin_0, &b_lep_truthOrigin_0);
   fChain->SetBranchAddress("lep_truthPdgId_0", &lep_truthPdgId_0, &b_lep_truthPdgId_0);
   fChain->SetBranchAddress("lep_ChargeIDBDTLoose_0", &lep_ChargeIDBDTLoose_0, &b_lep_ChargeIDBDTLoose_0);
   fChain->SetBranchAddress("lep_ChargeIDBDTMedium_0", &lep_ChargeIDBDTMedium_0, &b_lep_ChargeIDBDTMedium_0);
   fChain->SetBranchAddress("lep_ChargeIDBDTTight_0", &lep_ChargeIDBDTTight_0, &b_lep_ChargeIDBDTTight_0);
   fChain->SetBranchAddress("lep_PromptLeptonIso_TagWeight_0", &lep_PromptLeptonIso_TagWeight_0, &b_lep_PromptLeptonIso_TagWeight_0);
   fChain->SetBranchAddress("lep_ID_1", &lep_ID_1, &b_lep_ID_1);
   fChain->SetBranchAddress("lep_Pt_1", &lep_Pt_1, &b_lep_Pt_1);
   fChain->SetBranchAddress("lep_E_1", &lep_E_1, &b_lep_E_1);
   fChain->SetBranchAddress("lep_Eta_1", &lep_Eta_1, &b_lep_Eta_1);
   fChain->SetBranchAddress("lep_Phi_1", &lep_Phi_1, &b_lep_Phi_1);
   fChain->SetBranchAddress("lep_topoEtcone20_1", &lep_topoEtcone20_1, &b_lep_topoEtcone20_1);
   fChain->SetBranchAddress("lep_ptVarcone20_1", &lep_ptVarcone20_1, &b_lep_ptVarcone20_1);
   fChain->SetBranchAddress("lep_sigd0PV_1", &lep_sigd0PV_1, &b_lep_sigd0PV_1);
   fChain->SetBranchAddress("lep_Z0SinTheta_1", &lep_Z0SinTheta_1, &b_lep_Z0SinTheta_1);
   fChain->SetBranchAddress("lep_d0_1", &lep_d0_1, &b_lep_d0_1);
   fChain->SetBranchAddress("lep_z0_1", &lep_z0_1, &b_lep_z0_1);
   fChain->SetBranchAddress("lep_isTightLH_1", &lep_isTightLH_1, &b_lep_isTightLH_1);
   fChain->SetBranchAddress("lep_isMediumLH_1", &lep_isMediumLH_1, &b_lep_isMediumLH_1);
   fChain->SetBranchAddress("lep_isLooseLH_1", &lep_isLooseLH_1, &b_lep_isLooseLH_1);
   fChain->SetBranchAddress("lep_isTight_1", &lep_isTight_1, &b_lep_isTight_1);
   fChain->SetBranchAddress("lep_isMedium_1", &lep_isMedium_1, &b_lep_isMedium_1);
   fChain->SetBranchAddress("lep_isLoose_1", &lep_isLoose_1, &b_lep_isLoose_1);
   fChain->SetBranchAddress("lep_isolationLooseTrackOnly_1", &lep_isolationLooseTrackOnly_1, &b_lep_isolationLooseTrackOnly_1);
   fChain->SetBranchAddress("lep_isolationLoose_1", &lep_isolationLoose_1, &b_lep_isolationLoose_1);
   fChain->SetBranchAddress("lep_isolationGradient_1", &lep_isolationGradient_1, &b_lep_isolationGradient_1);
   fChain->SetBranchAddress("lep_isolationGradientLoose_1", &lep_isolationGradientLoose_1, &b_lep_isolationGradientLoose_1);
   fChain->SetBranchAddress("lep_isolationFixedCutTight_1", &lep_isolationFixedCutTight_1, &b_lep_isolationFixedCutTight_1);
   fChain->SetBranchAddress("lep_isolationFixedCutTightTrackOnly_1", &lep_isolationFixedCutTightTrackOnly_1, &b_lep_isolationFixedCutTightTrackOnly_1);
   fChain->SetBranchAddress("lep_isolationFixedCutLoose_1", &lep_isolationFixedCutLoose_1, &b_lep_isolationFixedCutLoose_1);
   fChain->SetBranchAddress("lep_isTrigMatch_1", &lep_isTrigMatch_1, &b_lep_isTrigMatch_1);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_1", &lep_isTrigMatchDLT_1, &b_lep_isTrigMatchDLT_1);
   fChain->SetBranchAddress("lep_isPrompt_1", &lep_isPrompt_1, &b_lep_isPrompt_1);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_1", &lep_isISR_FSR_Ph_1, &b_lep_isISR_FSR_Ph_1);
   fChain->SetBranchAddress("lep_isBrems_1", &lep_isBrems_1, &b_lep_isBrems_1);
   fChain->SetBranchAddress("lep_isTruthMatched_1", &lep_isTruthMatched_1, &b_lep_isTruthMatched_1);
   fChain->SetBranchAddress("lep_truthType_1", &lep_truthType_1, &b_lep_truthType_1);
   fChain->SetBranchAddress("lep_truthOrigin_1", &lep_truthOrigin_1, &b_lep_truthOrigin_1);
   fChain->SetBranchAddress("lep_truthPdgId_1", &lep_truthPdgId_1, &b_lep_truthPdgId_1);
   fChain->SetBranchAddress("lep_ChargeIDBDTLoose_1", &lep_ChargeIDBDTLoose_1, &b_lep_ChargeIDBDTLoose_1);
   fChain->SetBranchAddress("lep_ChargeIDBDTMedium_1", &lep_ChargeIDBDTMedium_1, &b_lep_ChargeIDBDTMedium_1);
   fChain->SetBranchAddress("lep_ChargeIDBDTTight_1", &lep_ChargeIDBDTTight_1, &b_lep_ChargeIDBDTTight_1);
   fChain->SetBranchAddress("lep_PromptLeptonIso_TagWeight_1", &lep_PromptLeptonIso_TagWeight_1, &b_lep_PromptLeptonIso_TagWeight_1);
   fChain->SetBranchAddress("lep_ID_2", &lep_ID_2, &b_lep_ID_2);
   fChain->SetBranchAddress("lep_Pt_2", &lep_Pt_2, &b_lep_Pt_2);
   fChain->SetBranchAddress("lep_E_2", &lep_E_2, &b_lep_E_2);
   fChain->SetBranchAddress("lep_Eta_2", &lep_Eta_2, &b_lep_Eta_2);
   fChain->SetBranchAddress("lep_Phi_2", &lep_Phi_2, &b_lep_Phi_2);
   fChain->SetBranchAddress("lep_topoEtcone20_2", &lep_topoEtcone20_2, &b_lep_topoEtcone20_2);
   fChain->SetBranchAddress("lep_ptVarcone20_2", &lep_ptVarcone20_2, &b_lep_ptVarcone20_2);
   fChain->SetBranchAddress("lep_sigd0PV_2", &lep_sigd0PV_2, &b_lep_sigd0PV_2);
   fChain->SetBranchAddress("lep_Z0SinTheta_2", &lep_Z0SinTheta_2, &b_lep_Z0SinTheta_2);
   fChain->SetBranchAddress("lep_d0_2", &lep_d0_2, &b_lep_d0_2);
   fChain->SetBranchAddress("lep_z0_2", &lep_z0_2, &b_lep_z0_2);
   fChain->SetBranchAddress("lep_isTightLH_2", &lep_isTightLH_2, &b_lep_isTightLH_2);
   fChain->SetBranchAddress("lep_isMediumLH_2", &lep_isMediumLH_2, &b_lep_isMediumLH_2);
   fChain->SetBranchAddress("lep_isLooseLH_2", &lep_isLooseLH_2, &b_lep_isLooseLH_2);
   fChain->SetBranchAddress("lep_isTight_2", &lep_isTight_2, &b_lep_isTight_2);
   fChain->SetBranchAddress("lep_isMedium_2", &lep_isMedium_2, &b_lep_isMedium_2);
   fChain->SetBranchAddress("lep_isLoose_2", &lep_isLoose_2, &b_lep_isLoose_2);
   fChain->SetBranchAddress("lep_isolationLooseTrackOnly_2", &lep_isolationLooseTrackOnly_2, &b_lep_isolationLooseTrackOnly_2);
   fChain->SetBranchAddress("lep_isolationLoose_2", &lep_isolationLoose_2, &b_lep_isolationLoose_2);
   fChain->SetBranchAddress("lep_isolationGradient_2", &lep_isolationGradient_2, &b_lep_isolationGradient_2);
   fChain->SetBranchAddress("lep_isolationGradientLoose_2", &lep_isolationGradientLoose_2, &b_lep_isolationGradientLoose_2);
   fChain->SetBranchAddress("lep_isolationFixedCutTight_2", &lep_isolationFixedCutTight_2, &b_lep_isolationFixedCutTight_2);
   fChain->SetBranchAddress("lep_isolationFixedCutTightTrackOnly_2", &lep_isolationFixedCutTightTrackOnly_2, &b_lep_isolationFixedCutTightTrackOnly_2);
   fChain->SetBranchAddress("lep_isolationFixedCutLoose_2", &lep_isolationFixedCutLoose_2, &b_lep_isolationFixedCutLoose_2);
   fChain->SetBranchAddress("lep_isTrigMatch_2", &lep_isTrigMatch_2, &b_lep_isTrigMatch_2);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_2", &lep_isTrigMatchDLT_2, &b_lep_isTrigMatchDLT_2);
   fChain->SetBranchAddress("lep_isPrompt_2", &lep_isPrompt_2, &b_lep_isPrompt_2);
   fChain->SetBranchAddress("lep_isFakeLep_2", &lep_isFakeLep_2, &b_lep_isFakeLep_2);
   fChain->SetBranchAddress("lep_isBrems_2", &lep_isBrems_2, &b_lep_isBrems_2);
   fChain->SetBranchAddress("lep_isTruthMatched_2", &lep_isTruthMatched_2, &b_lep_isTruthMatched_2);
   fChain->SetBranchAddress("lep_truthType_2", &lep_truthType_2, &b_lep_truthType_2);
   fChain->SetBranchAddress("lep_truthOrigin_2", &lep_truthOrigin_2, &b_lep_truthOrigin_2);
   fChain->SetBranchAddress("lep_truthPdgId_2", &lep_truthPdgId_2, &b_lep_truthPdgId_2);
   fChain->SetBranchAddress("lep_ChargeIDBDTLoose_2", &lep_ChargeIDBDTLoose_2, &b_lep_ChargeIDBDTLoose_2);
   fChain->SetBranchAddress("lep_ChargeIDBDTMedium_2", &lep_ChargeIDBDTMedium_2, &b_lep_ChargeIDBDTMedium_2);
   fChain->SetBranchAddress("lep_ChargeIDBDTTight_2", &lep_ChargeIDBDTTight_2, &b_lep_ChargeIDBDTTight_2);
   fChain->SetBranchAddress("lep_PromptLeptonIso_TagWeight_2", &lep_PromptLeptonIso_TagWeight_2, &b_lep_PromptLeptonIso_TagWeight_2);
   Notify();
}

Bool_t SampleHandler::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void SampleHandler::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t SampleHandler::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef SampleHandler_cxx
