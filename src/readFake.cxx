#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include <iostream>

using namespace std;

void readFake(int peakcategory){

  TString samples[]={"diboson","ttV","tV","ttH","Vgam","QmisID","datacombined"};
  Float_t ff_ele=0.4742, ff_mu=0.4902, sys_ele=0.3946, sys_mu=0.3327;
  Float_t sf_ele=1/ff_ele, sf_mu=1/ff_mu;
  //high mass
  //Float_t ff_ele=0.4790, ff_mu=0.4221, sys_ele=0.2906, sys_mu=0.2731;
  cout<<" VV "<<" ttV "<<" tV "<<" ttH "<<" Vgam "<<" QmisID "<<" Data "<<endl;
  for(int i=0;i<7;i++){
      TString inputName;
      if(samples[i]!="QmisID") inputName="output/dataMC_2jets/miniNtuple_FFApp_"+samples[i]+".root";
      TChain *tree=new TChain("Tree");
      if(samples[i]!="QmisID") tree->Add(inputName);
      else {
        tree->Add("output/dataMC_2jets/miniNtuple_FFApp_Zjets.root");
        tree->Add("output/dataMC_2jets/miniNtuple_FFApp_ttbar.root");
        tree->Add("output/dataMC_2jets/miniNtuple_FFApp_DY.root");
        tree->Add("output/dataMC_2jets/miniNtuple_FFQmis_datacombined.root");
      }
      Double_t weight;
      Int_t channel, category;
      tree->SetBranchAddress("weight",&weight);
      tree->SetBranchAddress("channel",&channel);
      tree->SetBranchAddress("category",&category);

      double count_ee(0), count_mumu(0), count_antiemu(0), count_eantimu(0);
      double count_ee_err2(0), count_mumu_err2(0), count_antiemu_err2(0), count_eantimu_err2(0);
      for(Long64_t j=0;j<tree->GetEntries();j++){
          tree->GetEntry(j);
          //e+antie
          if(channel==1) {
             count_ee+=weight*1/ff_ele; 
             count_ee_err2 += (weight*1/ff_ele)*(weight*1/ff_ele);           
          }
          //mu + antimu
          if(channel==2) {
             count_mumu+=weight*1/ff_mu;           
             count_mumu_err2+= (weight*1/ff_mu)*(weight*1/ff_mu);           
          }
          //antie + mu
          if(category==22){
             count_antiemu += weight*1/ff_ele;
             count_antiemu_err2 += (weight*1/ff_ele)*(weight*1/ff_ele);
          }
          //e + antimu
          if(category==23){
             count_eantimu += weight*1/ff_mu;
             count_eantimu_err2 += (weight*1/ff_mu)*(weight*1/ff_mu);
          }
      }
      cout<<setiosflags(ios::fixed)<<setprecision(2);
      if(peakcategory==2) cout<<"  &"<<count_ee<<" $\\pm "<<sqrt(count_ee_err2);
      if(peakcategory==12)cout<<"  &"<<count_mumu<<" $\\pm "<<sqrt(count_mumu_err2);
      if(peakcategory==22)cout<<"  &"<<count_antiemu<<" $\\pm "<<sqrt(count_antiemu_err2);
      if(peakcategory==23)cout<<"  &"<<count_eantimu<<" $\\pm "<<sqrt(count_eantimu_err2);
  }
  cout<<endl;
}
