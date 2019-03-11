#include "TCanvas.h"
#include "TFile.h"
#include "TTree.h"
#include "TStyle.h"
#include <iostream>
#include "TString.h"
#include <vector>
#include "lumi.cxx"
#include "GHTBCs.cxx"
using namespace std;
using namespace TMath;
void test(){
  //Get trees and variables 
  TFile *f_FFApp_data=new TFile("output/dataMC_2jets~/miniNtuple_FFApp_datacombined.root");
  TFile *f_FFQmis=new TFile("output/dataMC_2jets~/miniNtuple_FFQmis_datacombined.root");
  TFile *f_FFApp_subtractions_QmisID=new TFile("output/dataMC_2jets~/miniNtuple_FFApp_subtractions_QmisID.root");
  TFile *f_FFApp_subtractions_promptSS=new TFile("output/dataMC_2jets~/miniNtuple_FFApp_subtractions_promptSS.root");
  TFile *f_PseudoFakes=new TFile("output/dataMC_2jets~/PseudoFakes.root");
  
  TTree *FFApp_data=(TTree*)f_FFApp_data->Get("Tree");
  TTree *FFQmis=(TTree*)f_FFQmis->Get("Tree");
  TTree *FFApp_subtractions_QmisID=(TTree*)f_FFApp_subtractions_QmisID->Get("Tree");
  TTree *FFApp_subtractions_promptSS=(TTree*)f_FFApp_subtractions_promptSS->Get("Tree");
  TTree *PseudoFakes=(TTree*)f_PseudoFakes->Get("Tree");

  TString vars[]={"pt_leadinglepton","pt_sublepton","pt_j1","pt_j2","m_ll","m_jj_w","MET","m_jj","m_l1jj","mindR_l1j","mindR_l2j",
                  "pt_vecsum","pt_sum","m_all","Mt","m_l1j","m_l2j","RMS","numOfjet"};
  for(Int_t index=0;index<18;index++){  
      gROOT->Reset();
      TString var=vars[index];
  Float_t  FFApp_data_var,FFApp_subtractions_QmisID_var,FFApp_subtractions_promptSS_var,FFQmis_var,PseudoFakes_var;
  Double_t FFApp_data_weight,FFApp_subtractions_QmisID_weight,FFApp_subtractions_promptSS_weight, FFQmis_weight, PseudoFakes_weight;
  Int_t FFApp_data_channel,FFApp_subtractions_QmisID_channel,FFApp_subtractions_promptSS_channel, FFQmis_channel, PseudoFakes_channel;

  Int_t Nbins, xmin, xmax;
  if(var=="pt_leadinglepton") {Nbins=50; xmin=0; xmax=500;}
  if(var=="pt_sublepton") {Nbins=50; xmin=0; xmax=500;}
  if(var=="pt_j1") {Nbins=50; xmin=0; xmax=500;}
  if(var=="pt_j2") {Nbins=50; xmin=0; xmax=500;}
  if(var=="m_ll") {Nbins=50; xmin=0; xmax=500;}
  if(var=="m_jj_w"){ Nbins=50; xmin=0; xmax=500;}
  if(var=="MET") {Nbins=50; xmin=0; xmax=500;}
  if(var=="m_jj") {Nbins=20; xmin=0; xmax=1000;}
  if(var=="m_l1jj") {Nbins=20; xmin=0; xmax=1000;}
  if(var=="mindR_l1j"){ Nbins=20; xmin=0; xmax=5;}
  if(var=="mindR_l2j"){ Nbins=20; xmin=0; xmax=5;}
  if(var=="pt_vecsum"){ Nbins=50; xmin=0; xmax=500;}
  if(var=="pt_sum") {Nbins=30; xmin=0; xmax=1500;}
  if(var=="m_all") {Nbins=30; xmin=0; xmax=1500;}
  if(var=="Mt") {Nbins=30; xmin=0; xmax=1500;}
  if(var=="m_l1j"){ Nbins=20; xmin=0; xmax=1000;}
  if(var=="m_l2j"){ Nbins=20; xmin=0; xmax=1000;}
  if(var=="RMS") {Nbins=20; xmin=0; xmax=5;}
  if(var=="numOfjet") {Nbins=10; xmin=0; xmax=10;}
  
  FFQmis->SetBranchAddress(var,&FFQmis_var);
  FFApp_data->SetBranchAddress(var,&FFApp_data_var);
  FFApp_subtractions_QmisID->SetBranchAddress(var,&FFApp_subtractions_QmisID_var);
  FFApp_subtractions_promptSS->SetBranchAddress(var,&FFApp_subtractions_promptSS_var);
  PseudoFakes->SetBranchAddress(var,&PseudoFakes_var);

  FFApp_data->SetBranchAddress("weight",&FFApp_data_weight);
  PseudoFakes->SetBranchAddress("weight",&PseudoFakes_weight);
  FFQmis->SetBranchAddress("weight",&FFQmis_weight);
  FFApp_subtractions_QmisID->SetBranchAddress("weight",&FFApp_subtractions_QmisID_weight);
  FFApp_subtractions_promptSS->SetBranchAddress("weight",&FFApp_subtractions_promptSS_weight);

  FFApp_data->SetBranchAddress("channel",&FFApp_data_channel);
  PseudoFakes->SetBranchAddress("channel",&PseudoFakes_channel);
  FFQmis->SetBranchAddress("channel",&FFQmis_channel);
  FFApp_subtractions_QmisID->SetBranchAddress("channel",&FFApp_subtractions_QmisID_channel);
  FFApp_subtractions_promptSS->SetBranchAddress("channel",&FFApp_subtractions_promptSS_channel);

  TH1F *hist_fake_ee=new TH1F("hist_fake_ee","",Nbins,xmin,xmax);
  TH1F *hist_fake_mumu=new TH1F("hist_fake_mumu","",Nbins,xmin,xmax);
  TH1F *hist_fake_emu=new TH1F("hist_fake_emu","",Nbins,xmin,xmax);
  TH1F *hist_Pseudofake_ee=new TH1F("hist_Pseudofake_ee","",Nbins,xmin,xmax);
  TH1F *hist_Pseudofake_mumu=new TH1F("hist_Pseudofake_mumu","",Nbins,xmin,xmax);
  TH1F *hist_Pseudofake_emu=new TH1F("hist_Pseudofake_emu","",Nbins,xmin,xmax);  

  Float_t Lumi=lumi();
  for(Long64_t entry=0; entry<FFApp_data->GetEntries();entry++) {
      FFApp_data->GetEntry(entry);
      if(FFApp_data_channel==1) hist_fake_ee->Fill(FFApp_data_var,FFApp_data_weight);
      if(FFApp_data_channel==2) hist_fake_mumu->Fill(FFApp_data_var,FFApp_data_weight);
      if(FFApp_data_channel==3) hist_fake_emu->Fill(FFApp_data_var,FFApp_data_weight);
  }
  for(Long64_t entry=0; entry<FFApp_subtractions_QmisID->GetEntries();entry++) {
      FFApp_subtractions_QmisID->GetEntry(entry);
      if(FFApp_subtractions_QmisID_channel==1) hist_fake_ee->Fill(FFApp_subtractions_QmisID_var,-FFApp_subtractions_QmisID_weight*Lumi);
      if(FFApp_subtractions_QmisID_channel==3) hist_fake_emu->Fill(FFApp_subtractions_QmisID_var,-FFApp_subtractions_QmisID_weight*Lumi);
  }
  for(Long64_t entry=0; entry<FFQmis->GetEntries();entry++) {
      FFQmis->GetEntry(entry);
      if(FFQmis_channel==3) hist_fake_emu->Fill(FFQmis_var,-FFQmis_weight);
  }
  for(Long64_t entry=0; entry<FFApp_subtractions_promptSS->GetEntries();entry++) {
      FFApp_subtractions_promptSS->GetEntry(entry);
      if(FFApp_subtractions_promptSS_channel==1) hist_fake_ee->Fill(FFApp_subtractions_promptSS_var,-FFApp_subtractions_promptSS_weight*Lumi);
      if(FFApp_subtractions_promptSS_channel==2) hist_fake_mumu->Fill(FFApp_subtractions_promptSS_var,-FFApp_subtractions_promptSS_weight*Lumi);
      if(FFApp_subtractions_promptSS_channel==3) hist_fake_emu->Fill(FFApp_subtractions_promptSS_var,-FFApp_subtractions_promptSS_weight*Lumi);
  }
 
  for(Long64_t entry=0; entry<PseudoFakes->GetEntries();entry++){
      PseudoFakes->GetEntry(entry);
      if(PseudoFakes_channel==1)hist_Pseudofake_ee->Fill(PseudoFakes_var,PseudoFakes_weight);
      if(PseudoFakes_channel==2)hist_Pseudofake_mumu->Fill(PseudoFakes_var,PseudoFakes_weight);
      if(PseudoFakes_channel==3)hist_Pseudofake_emu->Fill(PseudoFakes_var,PseudoFakes_weight);
  } 
  cout<<"hist_fake_ee: "<<hist_fake_ee->Integral(0,Nbins+1)<<endl; 
  cout<<"hist_Pseudofake_ee: "<<hist_Pseudofake_ee->Integral(0,Nbins+1)<<endl; 
  TCanvas *c_xcheck_ee=new TCanvas("c_xcheck_ee","c_xcheck_ee",900,700);
  hist_fake_ee->SetLineColor(kBlue);
  hist_Pseudofake_ee->SetLineColor(kBlack);
  hist_fake_ee->Draw();
  hist_Pseudofake_ee->Draw("same");
  c_xcheck_ee->SaveAs("output/xcheck_plots/"+var+"_ee"+".png");
  
  TCanvas *c_xcheck_mumu=new TCanvas("c_xcheck_mumu","c_xcheck_mumu",900,700);
  hist_fake_mumu->SetLineColor(kBlue);
  hist_Pseudofake_mumu->SetLineColor(kBlack);
  hist_fake_mumu->Draw();
  hist_Pseudofake_mumu->Draw("same");
  c_xcheck_mumu->SaveAs("output/xcheck_plots/"+var+"_mumu"+".png");

  TCanvas *c_xcheck_emu=new TCanvas("c_xcheck_emu","c_xcheck_emu",900,700);
  hist_fake_emu->SetLineColor(kBlue);
  hist_Pseudofake_emu->SetLineColor(kBlack);
  hist_fake_emu->Draw();
  hist_Pseudofake_emu->Draw("same");
  c_xcheck_emu->SaveAs("output/xcheck_plots/"+var+"_emu"+".png");

  FFQmis->ResetBranchAddresses();
  FFApp_data->ResetBranchAddresses();
  FFApp_subtractions_promptSS->ResetBranchAddresses();
  FFApp_subtractions_QmisID->ResetBranchAddresses();
  PseudoFakes->ResetBranchAddresses();
  }//end of loop   
//end of manin func
}
