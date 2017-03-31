//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Mar  6 17:07:02 2017 by ROOT version 5.34/18
// from TTree Tree/MC
// found on file: /scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/ntuples_mH260.root
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
   // Declaration of leaf types
   Double_t        n_weight_tight;
   Double_t        n_weight_loose;
   Int_t           dilep_type;
   Int_t           trilep_type;
   Int_t           qualep_type;
   Int_t           total_charge;
   Int_t           total_leptons;
   Double_t        MV2c10_70_EventWeight;
   Double_t        MV2c10_77_EventWeight;
   vector<float>   *jet_pt;
   vector<float>   *jet_eta;
   vector<float>   *jet_phi;
   vector<float>   *jet_E;
   vector<char>    *jet_passOR;
   vector<char>    *jet_passTauOR;
   vector<float>   *jet_flavor_weight_MV2c10;
   vector<float>   *jet_flavor_weight_MV2c00;
   vector<float>   *jet_flavor_weight_MV2c20;
   vector<short>   *selected_jets;
   vector<short>   *selected_jets_T;
   Int_t           nJets_OR_T_MV2c10_70;
   Int_t           nJets_OR_T_MV2c10_77;
   Int_t           nJets_OR_MV2c10_70;
   Int_t           nJets_OR_MV2c10_77;
   Int_t           nJets_OR_T;
   Int_t           nJets_OR;
   vector<float>   *tau_pt;
   vector<float>   *tau_eta;
   vector<float>   *tau_phi;
   vector<float>   *tau_E;
   vector<float>   *tau_charge;
   vector<char>    *tau_passOR;
   vector<int>     *tau_passEleOLR;
   vector<int>     *tau_isHadronicTau;
   vector<int>     *tau_isTruthMatched;
   vector<int>     *tau_truthOrigin;
   vector<int>     *tau_truthType;
   Float_t         MET_RefFinal_et;
   Float_t         MET_RefFinal_phi;
   Float_t         lep_ID_0;
   Float_t         lep_Pt_0;
   Float_t         lep_E_0;
   Float_t         lep_Eta_0;
   Float_t         lep_Phi_0;
   Float_t         lep_topoEtcone20_0;
   Float_t         lep_topoEtcone30_0;
   Float_t         lep_topoEtcone40_0;
   Float_t         lep_ptVarcone20_0;
   Float_t         lep_ptVarcone30_0;
   Float_t         lep_ptVarcone40_0;
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
   Char_t          lep_isFakeLep_0;
   Char_t          lep_isQMisID_0;
   Char_t          lep_isConvPh_0;
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
   Float_t         lep_topoEtcone30_1;
   Float_t         lep_topoEtcone40_1;
   Float_t         lep_ptVarcone20_1;
   Float_t         lep_ptVarcone30_1;
   Float_t         lep_ptVarcone40_1;
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
   Char_t          lep_isFakeLep_1;
   Char_t          lep_isQMisID_1;
   Char_t          lep_isConvPh_1;
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
   Float_t         lep_topoEtcone30_2;
   Float_t         lep_topoEtcone40_2;
   Float_t         lep_ptVarcone20_2;
   Float_t         lep_ptVarcone30_2;
   Float_t         lep_ptVarcone40_2;
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
   Char_t          lep_isQMisID_2;
   Char_t          lep_isConvPh_2;
   Char_t          lep_isISR_FSR_Ph_2;
   Char_t          lep_isBrems_2;
   Char_t          lep_isTruthMatched_2;
   Int_t           lep_truthType_2;
   Int_t           lep_truthOrigin_2;
   Int_t           lep_truthPdgId_2;
   Float_t         lep_ChargeIDBDTLoose_2;
   Float_t         lep_ChargeIDBDTMedium_2;
   Float_t         lep_ChargeIDBDTTight_2;
   Float_t         lep_PromptLeptonIso_TagWeight_2;
   Float_t         lep_ID_3;
   Float_t         lep_Pt_3;
   Float_t         lep_E_3;
   Float_t         lep_Eta_3;
   Float_t         lep_Phi_3;
   Float_t         lep_topoEtcone20_3;
   Float_t         lep_topoEtcone30_3;
   Float_t         lep_topoEtcone40_3;
   Float_t         lep_ptVarcone20_3;
   Float_t         lep_ptVarcone30_3;
   Float_t         lep_ptVarcone40_3;
   Float_t         lep_sigd0PV_3;
   Float_t         lep_Z0SinTheta_3;
   Float_t         lep_d0_3;
   Float_t         lep_z0_3;
   Char_t          lep_isTightLH_3;
   Char_t          lep_isMediumLH_3;
   Char_t          lep_isLooseLH_3;
   Char_t          lep_isTight_3;
   Char_t          lep_isMedium_3;
   Char_t          lep_isLoose_3;
   Int_t           lep_isolationLooseTrackOnly_3;
   Int_t           lep_isolationLoose_3;
   Int_t           lep_isolationGradient_3;
   Int_t           lep_isolationGradientLoose_3;
   Int_t           lep_isolationFixedCutTight_3;
   Int_t           lep_isolationFixedCutTightTrackOnly_3;
   Int_t           lep_isolationFixedCutLoose_3;
   Char_t          lep_isTrigMatch_3;
   Char_t          lep_isTrigMatchDLT_3;
   Char_t          lep_isPrompt_3;
   Char_t          lep_isFakeLep_3;
   Char_t          lep_isQMisID_3;
   Char_t          lep_isConvPh_3;
   Char_t          lep_isISR_FSR_Ph_3;
   Char_t          lep_isBrems_3;
   Char_t          lep_isTruthMatched_3;
   Int_t           lep_truthType_3;
   Int_t           lep_truthOrigin_3;
   Int_t           lep_truthPdgId_3;
   Float_t         lep_ChargeIDBDTLoose_3;
   Float_t         lep_ChargeIDBDTMedium_3;
   Float_t         lep_ChargeIDBDTTight_3;
   Float_t         lep_PromptLeptonIso_TagWeight_3;

   // List of branches
   TBranch        *b_weight_tight;   //!
   TBranch        *b_weight_loose;   //!
   TBranch        *b_dilep_type;   //!
   TBranch        *b_trilep_type;   //!
   TBranch        *b_qualep_type;   //!
   TBranch        *b_total_charge;   //!
   TBranch        *b_total_leptons;   //!
   TBranch        *b_MV2c10_70_EventWeight;   //!
   TBranch        *b_MV2c10_77_EventWeight;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_E;   //!
   TBranch        *b_jet_passOR;   //!
   TBranch        *b_jet_passTauOR;   //!
   TBranch        *b_jet_flavor_weight_MV2c10;   //!
   TBranch        *b_jet_flavor_weight_MV2c00;   //!
   TBranch        *b_jet_flavor_weight_MV2c20;   //!
   TBranch        *b_selected_jets;   //!
   TBranch        *b_selected_jets_T;   //!
   TBranch        *b_nJets_OR_T_MV2c10_70;   //!
   TBranch        *b_nJets_OR_T_MV2c10_77;   //!
   TBranch        *b_nJets_OR_MV2c10_70;   //!
   TBranch        *b_nJets_OR_MV2c10_77;   //!
   TBranch        *b_nJets_OR_T;   //!
   TBranch        *b_nJets_OR;   //!
   TBranch        *b_tau_pt;   //!
   TBranch        *b_tau_eta;   //!
   TBranch        *b_tau_phi;   //!
   TBranch        *b_tau_E;   //!
   TBranch        *b_tau_charge;   //!
   TBranch        *b_tau_passOR;   //!
   TBranch        *b_tau_passEleOLR;   //!
   TBranch        *b_tau_isHadronicTau;   //!
   TBranch        *b_tau_isTruthMatched;   //!
   TBranch        *b_tau_truthOrigin;   //!
   TBranch        *b_tau_truthType;   //!
   TBranch        *b_MET_RefFinal_et;   //!
   TBranch        *b_MET_RefFinal_phi;   //!
   TBranch        *b_lep_ID_0;   //!
   TBranch        *b_lep_Pt_0;   //!
   TBranch        *b_lep_E_0;   //!
   TBranch        *b_lep_Eta_0;   //!
   TBranch        *b_lep_Phi_0;   //!
   TBranch        *b_lep_topoEtcone20_0;   //!
   TBranch        *b_lep_topoEtcone30_0;   //!
   TBranch        *b_lep_topoEtcone40_0;   //!
   TBranch        *b_lep_ptVarcone20_0;   //!
   TBranch        *b_lep_ptVarcone30_0;   //!
   TBranch        *b_lep_ptVarcone40_0;   //!
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
   TBranch        *b_lep_isFakeLep_0;   //!
   TBranch        *b_lep_isQMisID_0;   //!
   TBranch        *b_lep_isConvPh_0;   //!
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
   TBranch        *b_lep_topoEtcone30_1;   //!
   TBranch        *b_lep_topoEtcone40_1;   //!
   TBranch        *b_lep_ptVarcone20_1;   //!
   TBranch        *b_lep_ptVarcone30_1;   //!
   TBranch        *b_lep_ptVarcone40_1;   //!
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
   TBranch        *b_lep_isFakeLep_1;   //!
   TBranch        *b_lep_isQMisID_1;   //!
   TBranch        *b_lep_isConvPh_1;   //!
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
   TBranch        *b_lep_topoEtcone30_2;   //!
   TBranch        *b_lep_topoEtcone40_2;   //!
   TBranch        *b_lep_ptVarcone20_2;   //!
   TBranch        *b_lep_ptVarcone30_2;   //!
   TBranch        *b_lep_ptVarcone40_2;   //!
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
   TBranch        *b_lep_isQMisID_2;   //!
   TBranch        *b_lep_isConvPh_2;   //!
   TBranch        *b_lep_isISR_FSR_Ph_2;   //!
   TBranch        *b_lep_isBrems_2;   //!
   TBranch        *b_lep_isTruthMatched_2;   //!
   TBranch        *b_lep_truthType_2;   //!
   TBranch        *b_lep_truthOrigin_2;   //!
   TBranch        *b_lep_truthPdgId_2;   //!
   TBranch        *b_lep_ChargeIDBDTLoose_2;   //!
   TBranch        *b_lep_ChargeIDBDTMedium_2;   //!
   TBranch        *b_lep_ChargeIDBDTTight_2;   //!
   TBranch        *b_lep_PromptLeptonIso_TagWeight_2;   //!
   TBranch        *b_lep_ID_3;   //!
   TBranch        *b_lep_Pt_3;   //!
   TBranch        *b_lep_E_3;   //!
   TBranch        *b_lep_Eta_3;   //!
   TBranch        *b_lep_Phi_3;   //!
   TBranch        *b_lep_topoEtcone20_3;   //!
   TBranch        *b_lep_topoEtcone30_3;   //!
   TBranch        *b_lep_topoEtcone40_3;   //!
   TBranch        *b_lep_ptVarcone20_3;   //!
   TBranch        *b_lep_ptVarcone30_3;   //!
   TBranch        *b_lep_ptVarcone40_3;   //!
   TBranch        *b_lep_sigd0PV_3;   //!
   TBranch        *b_lep_Z0SinTheta_3;   //!
   TBranch        *b_lep_d0_3;   //!
   TBranch        *b_lep_z0_3;   //!
   TBranch        *b_lep_isTightLH_3;   //!
   TBranch        *b_lep_isMediumLH_3;   //!
   TBranch        *b_lep_isLooseLH_3;   //!
   TBranch        *b_lep_isTight_3;   //!
   TBranch        *b_lep_isMedium_3;   //!
   TBranch        *b_lep_isLoose_3;   //!
   TBranch        *b_lep_isolationLooseTrackOnly_3;   //!
   TBranch        *b_lep_isolationLoose_3;   //!
   TBranch        *b_lep_isolationGradient_3;   //!
   TBranch        *b_lep_isolationGradientLoose_3;   //!
   TBranch        *b_lep_isolationFixedCutTight_3;   //!
   TBranch        *b_lep_isolationFixedCutTightTrackOnly_3;   //!
   TBranch        *b_lep_isolationFixedCutLoose_3;   //!
   TBranch        *b_lep_isTrigMatch_3;   //!
   TBranch        *b_lep_isTrigMatchDLT_3;   //!
   TBranch        *b_lep_isPrompt_3;   //!
   TBranch        *b_lep_isFakeLep_3;   //!
   TBranch        *b_lep_isQMisID_3;   //!
   TBranch        *b_lep_isConvPh_3;   //!
   TBranch        *b_lep_isISR_FSR_Ph_3;   //!
   TBranch        *b_lep_isBrems_3;   //!
   TBranch        *b_lep_isTruthMatched_3;   //!
   TBranch        *b_lep_truthType_3;   //!
   TBranch        *b_lep_truthOrigin_3;   //!
   TBranch        *b_lep_truthPdgId_3;   //!
   TBranch        *b_lep_ChargeIDBDTLoose_3;   //!
   TBranch        *b_lep_ChargeIDBDTMedium_3;   //!
   TBranch        *b_lep_ChargeIDBDTTight_3;   //!
   TBranch        *b_lep_PromptLeptonIso_TagWeight_3;   //!

   SampleHandler(TString input);
   virtual ~SampleHandler();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TChain *chain);
   virtual void     Loop(TString config);
   virtual void     cutflow(Int_t Njets);
   virtual void     makeNtuple(TString type);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef SampleHandler_cxx
SampleHandler::SampleHandler(TString input) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   TString inputFile;
   TChain *chain=new TChain("Tree");
   if(input=="datacombined") {
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00276262.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00276329.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00276336.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00276416.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00276511.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00276689.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00276778.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00276790.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00276952.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00276954.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00278880.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00278912.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00278968.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00279169.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00279259.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00279279.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00279284.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00279345.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00279515.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00279598.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00279685.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00279813.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00279867.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00279928.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00279932.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00279984.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00280231.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00280273.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00280319.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00280368.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00280423.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00280464.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00280500.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00280520.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00280614.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00280673.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00280753.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00280853.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00280862.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00280950.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00280977.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00281070.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00281074.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00281075.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00281317.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00281385.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00281411.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00282625.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00282631.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00282712.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00282784.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00282992.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00283074.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00283155.root");
       chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00283270.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00283429.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00283608.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00283780.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00284006.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00284154.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00284213.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00284285.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00284420.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00284427.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00284484.root");
      //3.2 above
       chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00297730.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00298595.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00298609.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00298633.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00298687.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00298690.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00298771.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00298773.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00298862.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00298967.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00299055.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00299144.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00299147.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00299184.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00299243.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00299584.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00300279.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00300345.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00300415.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00300418.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00300487.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00300540.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00300571.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00300600.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00300655.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00300687.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00300784.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00300800.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00300863.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00300908.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00301912.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00301918.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00301932.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00301973.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00302053.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00302137.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00302265.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00302269.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00302300.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00302347.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00302380.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00302391.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00302393.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00302737.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00302831.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00302872.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00302919.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00302925.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00302956.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00303007.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00303079.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00303201.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00303208.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00303264.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00303266.root");
       chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00303291.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00303304.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00303338.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00303421.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00303499.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00303560.root");
      //13.2 above
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00303638.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00303832.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00303846.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00303892.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00303943.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00304006.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00304008.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00304128.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00304178.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00304198.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00304211.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00304243.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00304308.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00304337.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00304409.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00304431.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00304494.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00305380.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00305543.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00305571.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00305618.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00305671.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00305674.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00305723.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00305727.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00305735.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00305777.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00305811.root");
       chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00305920.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00306269.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00306278.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00306310.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00306384.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00306419.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00306442.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00306448.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00306451.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00307126.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00307195.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00307259.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00307306.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00307354.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00307358.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00307394.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00307454.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00307514.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00307539.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00307569.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00307601.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00307656.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00307619.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00307710.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00307716.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00307732.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00307861.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00307935.root");
       chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00308047.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00308084.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00309375.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00309390.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00309440.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00309516.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00309640.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00309674.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00309759.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00310015.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00310247.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00310249.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00310341.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00310370.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00310405.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00310468.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00310473.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00310634.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00310691.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00310738.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00310809.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00310863.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00310872.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00310969.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00311071.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00311170.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00311244.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00311287.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00311321.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00311365.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00311402.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00311473.root");
      chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/00311481.root ");
   }
   if(input=="Zjets") {
      inputFile="/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/ntuples_sherpa2.1_";
      inputFile +=input;
      inputFile +=".root";
      chain->Add(inputFile);
   }
   //if(input=="xcheck") chain->Add("/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/361063.root");
   if((input != "Zjets") || (input != "datacombined")) {
      inputFile="/scratchfs/atlas/zhoums/ntuples_promptSS/v26.02/ntuples_";
      inputFile +=input;
      inputFile +=".root";
      chain->Add(inputFile);
   }
   if(input=="Zjets" ||input=="ttbar" || input=="DY")datasetType=3;
   else datasetType=1;
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
   jet_passTauOR = 0;
   jet_flavor_weight_MV2c10 = 0;
   jet_flavor_weight_MV2c00 = 0;
   jet_flavor_weight_MV2c20 = 0;
   selected_jets = 0;
   selected_jets_T = 0;
   tau_pt = 0;
   tau_eta = 0;
   tau_phi = 0;
   tau_E = 0;
   tau_charge = 0;
   tau_passOR = 0;
   tau_passEleOLR = 0;
   tau_isHadronicTau = 0;
   tau_isTruthMatched = 0;
   tau_truthOrigin = 0;
   tau_truthType = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("weight_tight", &n_weight_tight, &b_weight_tight);
   fChain->SetBranchAddress("weight_loose", &n_weight_loose, &b_weight_loose);
   fChain->SetBranchAddress("dilep_type", &dilep_type, &b_dilep_type);
   fChain->SetBranchAddress("trilep_type", &trilep_type, &b_trilep_type);
   fChain->SetBranchAddress("qualep_type", &qualep_type, &b_qualep_type);
   fChain->SetBranchAddress("total_charge", &total_charge, &b_total_charge);
   fChain->SetBranchAddress("total_leptons", &total_leptons, &b_total_leptons);
   fChain->SetBranchAddress("MV2c10_70_EventWeight", &MV2c10_70_EventWeight, &b_MV2c10_70_EventWeight);
   fChain->SetBranchAddress("MV2c10_77_EventWeight", &MV2c10_77_EventWeight, &b_MV2c10_77_EventWeight);
   fChain->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_E", &jet_E, &b_jet_E);
   fChain->SetBranchAddress("jet_passOR", &jet_passOR, &b_jet_passOR);
   fChain->SetBranchAddress("jet_passTauOR", &jet_passTauOR, &b_jet_passTauOR);
   fChain->SetBranchAddress("jet_flavor_weight_MV2c10", &jet_flavor_weight_MV2c10, &b_jet_flavor_weight_MV2c10);
   fChain->SetBranchAddress("jet_flavor_weight_MV2c00", &jet_flavor_weight_MV2c00, &b_jet_flavor_weight_MV2c00);
   fChain->SetBranchAddress("jet_flavor_weight_MV2c20", &jet_flavor_weight_MV2c20, &b_jet_flavor_weight_MV2c20);
   fChain->SetBranchAddress("selected_jets", &selected_jets, &b_selected_jets);
   fChain->SetBranchAddress("selected_jets_T", &selected_jets_T, &b_selected_jets_T);
   fChain->SetBranchAddress("nJets_OR_T_MV2c10_70", &nJets_OR_T_MV2c10_70, &b_nJets_OR_T_MV2c10_70);
   fChain->SetBranchAddress("nJets_OR_T_MV2c10_77", &nJets_OR_T_MV2c10_77, &b_nJets_OR_T_MV2c10_77);
   fChain->SetBranchAddress("nJets_OR_MV2c10_70", &nJets_OR_MV2c10_70, &b_nJets_OR_MV2c10_70);
   fChain->SetBranchAddress("nJets_OR_MV2c10_77", &nJets_OR_MV2c10_77, &b_nJets_OR_MV2c10_77);
   fChain->SetBranchAddress("nJets_OR_T", &nJets_OR_T, &b_nJets_OR_T);
   fChain->SetBranchAddress("nJets_OR", &nJets_OR, &b_nJets_OR);
   fChain->SetBranchAddress("tau_pt", &tau_pt, &b_tau_pt);
   fChain->SetBranchAddress("tau_eta", &tau_eta, &b_tau_eta);
   fChain->SetBranchAddress("tau_phi", &tau_phi, &b_tau_phi);
   fChain->SetBranchAddress("tau_E", &tau_E, &b_tau_E);
   fChain->SetBranchAddress("tau_charge", &tau_charge, &b_tau_charge);
   fChain->SetBranchAddress("tau_passOR", &tau_passOR, &b_tau_passOR);
   fChain->SetBranchAddress("tau_passEleOLR", &tau_passEleOLR, &b_tau_passEleOLR);
   fChain->SetBranchAddress("tau_isHadronicTau", &tau_isHadronicTau, &b_tau_isHadronicTau);
   fChain->SetBranchAddress("tau_isTruthMatched", &tau_isTruthMatched, &b_tau_isTruthMatched);
   fChain->SetBranchAddress("tau_truthOrigin", &tau_truthOrigin, &b_tau_truthOrigin);
   fChain->SetBranchAddress("tau_truthType", &tau_truthType, &b_tau_truthType);
   fChain->SetBranchAddress("MET_RefFinal_et", &MET_RefFinal_et, &b_MET_RefFinal_et);
   fChain->SetBranchAddress("MET_RefFinal_phi", &MET_RefFinal_phi, &b_MET_RefFinal_phi);
   fChain->SetBranchAddress("lep_ID_0", &lep_ID_0, &b_lep_ID_0);
   fChain->SetBranchAddress("lep_Pt_0", &lep_Pt_0, &b_lep_Pt_0);
   fChain->SetBranchAddress("lep_E_0", &lep_E_0, &b_lep_E_0);
   fChain->SetBranchAddress("lep_Eta_0", &lep_Eta_0, &b_lep_Eta_0);
   fChain->SetBranchAddress("lep_Phi_0", &lep_Phi_0, &b_lep_Phi_0);
   fChain->SetBranchAddress("lep_topoEtcone20_0", &lep_topoEtcone20_0, &b_lep_topoEtcone20_0);
   fChain->SetBranchAddress("lep_topoEtcone30_0", &lep_topoEtcone30_0, &b_lep_topoEtcone30_0);
   fChain->SetBranchAddress("lep_topoEtcone40_0", &lep_topoEtcone40_0, &b_lep_topoEtcone40_0);
   fChain->SetBranchAddress("lep_ptVarcone20_0", &lep_ptVarcone20_0, &b_lep_ptVarcone20_0);
   fChain->SetBranchAddress("lep_ptVarcone30_0", &lep_ptVarcone30_0, &b_lep_ptVarcone30_0);
   fChain->SetBranchAddress("lep_ptVarcone40_0", &lep_ptVarcone40_0, &b_lep_ptVarcone40_0);
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
   fChain->SetBranchAddress("lep_isFakeLep_0", &lep_isFakeLep_0, &b_lep_isFakeLep_0);
   fChain->SetBranchAddress("lep_isQMisID_0", &lep_isQMisID_0, &b_lep_isQMisID_0);
   fChain->SetBranchAddress("lep_isConvPh_0", &lep_isConvPh_0, &b_lep_isConvPh_0);
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
   fChain->SetBranchAddress("lep_topoEtcone30_1", &lep_topoEtcone30_1, &b_lep_topoEtcone30_1);
   fChain->SetBranchAddress("lep_topoEtcone40_1", &lep_topoEtcone40_1, &b_lep_topoEtcone40_1);
   fChain->SetBranchAddress("lep_ptVarcone20_1", &lep_ptVarcone20_1, &b_lep_ptVarcone20_1);
   fChain->SetBranchAddress("lep_ptVarcone30_1", &lep_ptVarcone30_1, &b_lep_ptVarcone30_1);
   fChain->SetBranchAddress("lep_ptVarcone40_1", &lep_ptVarcone40_1, &b_lep_ptVarcone40_1);
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
   fChain->SetBranchAddress("lep_isFakeLep_1", &lep_isFakeLep_1, &b_lep_isFakeLep_1);
   fChain->SetBranchAddress("lep_isQMisID_1", &lep_isQMisID_1, &b_lep_isQMisID_1);
   fChain->SetBranchAddress("lep_isConvPh_1", &lep_isConvPh_1, &b_lep_isConvPh_1);
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
   fChain->SetBranchAddress("lep_topoEtcone30_2", &lep_topoEtcone30_2, &b_lep_topoEtcone30_2);
   fChain->SetBranchAddress("lep_topoEtcone40_2", &lep_topoEtcone40_2, &b_lep_topoEtcone40_2);
   fChain->SetBranchAddress("lep_ptVarcone20_2", &lep_ptVarcone20_2, &b_lep_ptVarcone20_2);
   fChain->SetBranchAddress("lep_ptVarcone30_2", &lep_ptVarcone30_2, &b_lep_ptVarcone30_2);
   fChain->SetBranchAddress("lep_ptVarcone40_2", &lep_ptVarcone40_2, &b_lep_ptVarcone40_2);
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
   fChain->SetBranchAddress("lep_isQMisID_2", &lep_isQMisID_2, &b_lep_isQMisID_2);
   fChain->SetBranchAddress("lep_isConvPh_2", &lep_isConvPh_2, &b_lep_isConvPh_2);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_2", &lep_isISR_FSR_Ph_2, &b_lep_isISR_FSR_Ph_2);
   fChain->SetBranchAddress("lep_isBrems_2", &lep_isBrems_2, &b_lep_isBrems_2);
   fChain->SetBranchAddress("lep_isTruthMatched_2", &lep_isTruthMatched_2, &b_lep_isTruthMatched_2);
   fChain->SetBranchAddress("lep_truthType_2", &lep_truthType_2, &b_lep_truthType_2);
   fChain->SetBranchAddress("lep_truthOrigin_2", &lep_truthOrigin_2, &b_lep_truthOrigin_2);
   fChain->SetBranchAddress("lep_truthPdgId_2", &lep_truthPdgId_2, &b_lep_truthPdgId_2);
   fChain->SetBranchAddress("lep_ChargeIDBDTLoose_2", &lep_ChargeIDBDTLoose_2, &b_lep_ChargeIDBDTLoose_2);
   fChain->SetBranchAddress("lep_ChargeIDBDTMedium_2", &lep_ChargeIDBDTMedium_2, &b_lep_ChargeIDBDTMedium_2);
   fChain->SetBranchAddress("lep_ChargeIDBDTTight_2", &lep_ChargeIDBDTTight_2, &b_lep_ChargeIDBDTTight_2);
   fChain->SetBranchAddress("lep_PromptLeptonIso_TagWeight_2", &lep_PromptLeptonIso_TagWeight_2, &b_lep_PromptLeptonIso_TagWeight_2);
   fChain->SetBranchAddress("lep_ID_3", &lep_ID_3, &b_lep_ID_3);
   fChain->SetBranchAddress("lep_Pt_3", &lep_Pt_3, &b_lep_Pt_3);
   fChain->SetBranchAddress("lep_E_3", &lep_E_3, &b_lep_E_3);
   fChain->SetBranchAddress("lep_Eta_3", &lep_Eta_3, &b_lep_Eta_3);
   fChain->SetBranchAddress("lep_Phi_3", &lep_Phi_3, &b_lep_Phi_3);
   fChain->SetBranchAddress("lep_topoEtcone20_3", &lep_topoEtcone20_3, &b_lep_topoEtcone20_3);
   fChain->SetBranchAddress("lep_topoEtcone30_3", &lep_topoEtcone30_3, &b_lep_topoEtcone30_3);
   fChain->SetBranchAddress("lep_topoEtcone40_3", &lep_topoEtcone40_3, &b_lep_topoEtcone40_3);
   fChain->SetBranchAddress("lep_ptVarcone20_3", &lep_ptVarcone20_3, &b_lep_ptVarcone20_3);
   fChain->SetBranchAddress("lep_ptVarcone30_3", &lep_ptVarcone30_3, &b_lep_ptVarcone30_3);
   fChain->SetBranchAddress("lep_ptVarcone40_3", &lep_ptVarcone40_3, &b_lep_ptVarcone40_3);
   fChain->SetBranchAddress("lep_sigd0PV_3", &lep_sigd0PV_3, &b_lep_sigd0PV_3);
   fChain->SetBranchAddress("lep_Z0SinTheta_3", &lep_Z0SinTheta_3, &b_lep_Z0SinTheta_3);
   fChain->SetBranchAddress("lep_d0_3", &lep_d0_3, &b_lep_d0_3);
   fChain->SetBranchAddress("lep_z0_3", &lep_z0_3, &b_lep_z0_3);
   fChain->SetBranchAddress("lep_isTightLH_3", &lep_isTightLH_3, &b_lep_isTightLH_3);
   fChain->SetBranchAddress("lep_isMediumLH_3", &lep_isMediumLH_3, &b_lep_isMediumLH_3);
   fChain->SetBranchAddress("lep_isLooseLH_3", &lep_isLooseLH_3, &b_lep_isLooseLH_3);
   fChain->SetBranchAddress("lep_isTight_3", &lep_isTight_3, &b_lep_isTight_3);
   fChain->SetBranchAddress("lep_isMedium_3", &lep_isMedium_3, &b_lep_isMedium_3);
   fChain->SetBranchAddress("lep_isLoose_3", &lep_isLoose_3, &b_lep_isLoose_3);
   fChain->SetBranchAddress("lep_isolationLooseTrackOnly_3", &lep_isolationLooseTrackOnly_3, &b_lep_isolationLooseTrackOnly_3);
   fChain->SetBranchAddress("lep_isolationLoose_3", &lep_isolationLoose_3, &b_lep_isolationLoose_3);
   fChain->SetBranchAddress("lep_isolationGradient_3", &lep_isolationGradient_3, &b_lep_isolationGradient_3);
   fChain->SetBranchAddress("lep_isolationGradientLoose_3", &lep_isolationGradientLoose_3, &b_lep_isolationGradientLoose_3);
   fChain->SetBranchAddress("lep_isolationFixedCutTight_3", &lep_isolationFixedCutTight_3, &b_lep_isolationFixedCutTight_3);
   fChain->SetBranchAddress("lep_isolationFixedCutTightTrackOnly_3", &lep_isolationFixedCutTightTrackOnly_3, &b_lep_isolationFixedCutTightTrackOnly_3);
   fChain->SetBranchAddress("lep_isolationFixedCutLoose_3", &lep_isolationFixedCutLoose_3, &b_lep_isolationFixedCutLoose_3);
   fChain->SetBranchAddress("lep_isTrigMatch_3", &lep_isTrigMatch_3, &b_lep_isTrigMatch_3);
   fChain->SetBranchAddress("lep_isTrigMatchDLT_3", &lep_isTrigMatchDLT_3, &b_lep_isTrigMatchDLT_3);
   fChain->SetBranchAddress("lep_isPrompt_3", &lep_isPrompt_3, &b_lep_isPrompt_3);
   fChain->SetBranchAddress("lep_isFakeLep_3", &lep_isFakeLep_3, &b_lep_isFakeLep_3);
   fChain->SetBranchAddress("lep_isQMisID_3", &lep_isQMisID_3, &b_lep_isQMisID_3);
   fChain->SetBranchAddress("lep_isConvPh_3", &lep_isConvPh_3, &b_lep_isConvPh_3);
   fChain->SetBranchAddress("lep_isISR_FSR_Ph_3", &lep_isISR_FSR_Ph_3, &b_lep_isISR_FSR_Ph_3);
   fChain->SetBranchAddress("lep_isBrems_3", &lep_isBrems_3, &b_lep_isBrems_3);
   fChain->SetBranchAddress("lep_isTruthMatched_3", &lep_isTruthMatched_3, &b_lep_isTruthMatched_3);
   fChain->SetBranchAddress("lep_truthType_3", &lep_truthType_3, &b_lep_truthType_3);
   fChain->SetBranchAddress("lep_truthOrigin_3", &lep_truthOrigin_3, &b_lep_truthOrigin_3);
   fChain->SetBranchAddress("lep_truthPdgId_3", &lep_truthPdgId_3, &b_lep_truthPdgId_3);
   fChain->SetBranchAddress("lep_ChargeIDBDTLoose_3", &lep_ChargeIDBDTLoose_3, &b_lep_ChargeIDBDTLoose_3);
   fChain->SetBranchAddress("lep_ChargeIDBDTMedium_3", &lep_ChargeIDBDTMedium_3, &b_lep_ChargeIDBDTMedium_3);
   fChain->SetBranchAddress("lep_ChargeIDBDTTight_3", &lep_ChargeIDBDTTight_3, &b_lep_ChargeIDBDTTight_3);
   fChain->SetBranchAddress("lep_PromptLeptonIso_TagWeight_3", &lep_PromptLeptonIso_TagWeight_3, &b_lep_PromptLeptonIso_TagWeight_3);
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
