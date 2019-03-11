#include <iostream>
#include "TFile.h"
#include "TH1.h"
#include "GHTBCs.cxx"

using namespace std;
void ClosureTest(TString dataset,TString Njet){
  //------------------------------------------------------------------------------------
  TString inputFile,outputFile;
  if(Njet=="1jets") inputFile="/scratchfs/atlas/zhoums/2LSSAna_output/temp/hists_CT_FFcal_1jets_";
  if(Njet=="2jets") inputFile="/scratchfs/atlas/zhoums/2LSSAna_output/temp/hists_CT_FFcal_2jets_";
  inputFile+=dataset;
  inputFile+=".root";
  if(Njet=="1jets") outputFile="/scratchfs/atlas/zhoums/2LSSAna_output/output/hist_ff_1jets_";
  if(Njet=="2jets") outputFile="/scratchfs/atlas/zhoums/2LSSAna_output/output/hist_ff_2jets_";
  outputFile+=dataset;
  outputFile+=".root";
  TFile *tmp=new TFile(inputFile);
  TFile *ff_output=new TFile(outputFile,"update");
  //ele
  TH1* hist_pt_subelectron_ee=(TH1*)tmp->Get("hist_pt_subelectron_ee");
  TH1* hist_pt_antiidelectron_eantiide=(TH1*)tmp->Get("hist_pt_antiidelectron_eantiide");

  cout<<"  electron inclusive ff: "<<GHTBCs(hist_pt_subelectron_ee)/GHTBCs(hist_pt_antiidelectron_eantiide)<<" \\pm"<<
      (GHTBCs(hist_pt_subelectron_ee)/GHTBCs(hist_pt_antiidelectron_eantiide))*sqrt(1/GHTBCs(hist_pt_subelectron_ee)+1/GHTBCs(hist_pt_antiidelectron_eantiide))<<endl;
  
  TH1 *hist_ff_pt_antiidelectron   =(TH1*)hist_pt_subelectron_ee->Clone("hist_ff_pt_antiidelectron");
  hist_ff_pt_antiidelectron->Sumw2();
  hist_ff_pt_antiidelectron->Divide(hist_pt_subelectron_ee,hist_pt_antiidelectron_eantiide,1,1,"");
  
  hist_ff_pt_antiidelectron->Write();
  //mu
  TH1* hist_pt_submuon_mumu=(TH1*)tmp->Get("hist_pt_submuon_mumu");
  TH1* hist_pt_antiidmuon_muantiidmu=(TH1*)tmp->Get("hist_pt_antiidmuon_muantiidmu");

  cout<<"  muon inclusive ff: "<<GHTBCs(hist_pt_submuon_mumu)/GHTBCs(hist_pt_antiidmuon_muantiidmu)<<" \\pm"<<
  (GHTBCs(hist_pt_submuon_mumu)/GHTBCs(hist_pt_antiidmuon_muantiidmu))*sqrt(1/GHTBCs(hist_pt_submuon_mumu)+1/GHTBCs(hist_pt_antiidmuon_muantiidmu))<<endl;
  TH1 *hist_ff_pt_antiidmuon   =(TH1*)hist_pt_submuon_mumu->Clone("hist_ff_pt_antiidmuon");
  hist_ff_pt_antiidmuon->Sumw2();
  hist_ff_pt_antiidmuon->Divide(hist_pt_submuon_mumu,hist_pt_antiidmuon_muantiidmu,1,1,"");
  hist_ff_pt_antiidmuon->Write();
  ff_output->Close();
}
