#include "../inc/SampleHandler.h"
#include "../src/ClosureTest.cxx"
#include "../src/GHTBCs.cxx"

int main(){
  //1) fist step
  SampleHandler Wjets_ttbar("Wjets_ttbar");
  //2)second step
  //Wjets_ttbar.Loop("CT_FFcal_2jets");
  //ClosureTest("Wjets_ttbar","2jets");
  //3)third step
  Wjets_ttbar.Loop("CT_FFApp_3jets");
  TFile *f=new TFile("/scratchfs/atlas/zhoums/2LSSAna_output/temp/hists_CT_FFApp_3jets_Wjets_ttbar.root");

  TH1* hist_eta_subelectron_ee=(TH1*)f->Get("hist_eta_subelectron_ee");
  TH1* hist_eta_antiidelectron_eantiide=(TH1*)f->Get("hist_eta_antiidelectron_eantiide");
  TH1* hist_eta_submuon_mumu=(TH1*)f->Get("hist_eta_submuon_mumu");
  TH1* hist_eta_antiidmuon_muantidmu=(TH1*)f->Get("hist_eta_antiidmuon_muantiidmu");
  TH1* hist_eta_muon_emu=(TH1*)f->Get("hist_eta_muon_emu");
  TH1* hist_eta_antiidelectron_antiidemu=(TH1*)f->Get("hist_eta_antiidelectron_antiidemu");
  TH1* hist_eta_antiidmuon_eantiidmu=(TH1*)f->Get("hist_eta_antiidmuon_eantiidmu");

  cout<<setw(10)<<"ee"<<endl;
  cout<<"predicted:"<<setw(3)<<GHTBCs(hist_eta_antiidelectron_eantiide)<<"+-"<<statistic_error(hist_eta_antiidelectron_eantiide)<<endl;
  cout<<"real     :"<<setw(3)<<GHTBCs(hist_eta_subelectron_ee)<<"+-"<<statistic_error(hist_eta_subelectron_ee)<<endl;
  cout<<setw(10)<<"mumu"<<endl;
  cout<<"predicted:"<<setw(3)<<GHTBCs(hist_eta_antiidmuon_muantidmu)<<"+-"<<statistic_error(hist_eta_antiidmuon_muantidmu)<<endl;
  cout<<"real     :"<<setw(3)<<GHTBCs(hist_eta_submuon_mumu)<<"+-"<<statistic_error(hist_eta_submuon_mumu)<<endl;
  cout<<setw(10)<<"emu"<<endl;
  cout<<"predicted:"<<setw(3)<<GHTBCs(hist_eta_antiidelectron_antiidemu)+GHTBCs(hist_eta_antiidmuon_eantiidmu)
           <<"+-"<<sqrt(pow(statistic_error(hist_eta_antiidelectron_antiidemu),2)+pow(statistic_error(hist_eta_antiidmuon_eantiidmu),2))<<endl;
  cout<<"predicted: "<<"antiemu "<<GHTBCs(hist_eta_antiidelectron_antiidemu)<<" eantimu "<<GHTBCs(hist_eta_antiidmuon_eantiidmu)<<endl;
  cout<<"real     :"<<setw(3)<<GHTBCs(hist_eta_muon_emu)<<"+-"<<statistic_error(hist_eta_muon_emu)<<endl;
  return 0;
  
}
