#include "TFile.h"
#include "TTree.h"
#include <iostream>
#include "passOptCuts.cxx"

using namespace std;

void Check_fraction(TString masspoint){
  
  TFile *input=new TFile("output/dataMC_2jets/miniNtuple_ttZ.root");
  TTree *tree=(TTree*)input->Get("Tree");

  Double_t weight;
  Int_t numOfjet,channel;
  Float_t mindR_l1j, mindR_l2j,m_ll,m_l1jj,m_all;
  tree->SetBranchAddress("channel",&channel);
  tree->SetBranchAddress("numOfjet",&numOfjet);
  tree->SetBranchAddress("weight",&weight);
  tree->SetBranchAddress("mindR_l1j",&mindR_l1j);
  tree->SetBranchAddress("mindR_l2j",&mindR_l2j);
  tree->SetBranchAddress("m_ll",&m_ll);
  tree->SetBranchAddress("m_l1jj",&m_l1jj);
  tree->SetBranchAddress("m_all",&m_all);

  Double_t count_ee(0),count_mumu(0),count_emu(0);
  for(int i=0;i<tree->GetEntries();i++){
      tree->GetEntry(i);

      if(channel==1 && passOptCuts(masspoint,"ee",mindR_l1j, mindR_l2j,m_ll,m_l1jj,m_all) ) count_ee+=weight;
      if(channel==2 && passOptCuts(masspoint,"mumu",mindR_l1j, mindR_l2j,m_ll,m_l1jj,m_all) ) count_mumu+=weight;
      if(channel==3 && passOptCuts(masspoint,"emu",mindR_l1j, mindR_l2j,m_ll,m_l1jj,m_all) ) count_emu+=weight;
  }
  cout<<"$$$$$$$$$$$$$"<<masspoint<<"$$$$$$$$$$$$$$$$"<<endl;
  cout<<"    ee    "<<"mumu"<<"     emu    "<<endl;
  cout<<"   "<<count_ee<<"   "<<count_mumu<<"   "<<count_emu<<endl;
}
