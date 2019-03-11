#include <iostream>
#include "TFile.h"
#include "TH1.h"
#include "GHTBCs.cxx"

using namespace std;
void ClosureTest_muon(){
  TFile *tmp_ttbar=new TFile("temp/hists_2jets_ttbar.root");
  TFile *ff_output=new TFile("output/hist_ff_ttbar.root","update");

  TH1* hist_eta_submuon_mumu_ttbar=(TH1*)tmp_ttbar->Get("hist_eta_submuon_mumu");
  TH1* hist_eta_antiidmuon_muantiidmu_ttbar=(TH1*)tmp_ttbar->Get("hist_eta_antiidmuon_muantiidmu");

  cout<<"  muon inclusive ff: "<<GHTBCs(hist_eta_submuon_mumu_ttbar)/GHTBCs(hist_eta_antiidmuon_muantiidmu_ttbar)<<endl;
  TH1 *hist_ff_eta_antiidmuon   =(TH1*)hist_eta_submuon_mumu_ttbar->Clone("hist_ff_eta_antiidmuon");
  hist_ff_eta_antiidmuon->Sumw2();
  hist_ff_eta_antiidmuon->Divide(hist_eta_submuon_mumu_ttbar,hist_eta_antiidmuon_muantiidmu_ttbar,1,1,"");
  hist_ff_eta_antiidmuon->Write();
  ff_output->Close();

}
