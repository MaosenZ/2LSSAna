#include "TFile.h"
#include "TTree.h"
#include <iostream>
#include "passOptCuts.cxx"

using namespace std;

void getPDFuncer(){
  
  TString masspoints[]={"mH260","mH300","mH400","mH500","nonres","H280_S135","H300_S135","H320_S135","H340_S135","H340_S145",
                        "H340_S145","H340_S155","H340_S165"};
  
  for(int i=0;i<4;i++){
      TString masspoint=masspoints[i];
      TString inputFile=TString("output/PDF4LHC15_nlo_30/miniNtuple_")+masspoint+".root";
      TFile *input=new TFile(inputFile);
      TTree *tree=(TTree*)input->Get("Tree");

      Int_t channel,numOfjet;
      Double_t weight, PDF_UP, PDF_DOWN;
      Float_t mindR_l1j, mindR_l2j,m_ll,m_l1jj,m_all;
      tree->SetBranchAddress("channel",&channel);
      tree->SetBranchAddress("numOfjet",&numOfjet);
      tree->SetBranchAddress("weight",&weight);
      tree->SetBranchAddress("PDF_UP",&PDF_UP);
      tree->SetBranchAddress("PDF_DOWN",&PDF_DOWN);
      tree->SetBranchAddress("mindR_l1j",&mindR_l1j);
      tree->SetBranchAddress("mindR_l2j",&mindR_l2j);
      tree->SetBranchAddress("m_ll",&m_ll);
      tree->SetBranchAddress("m_l1jj",&m_l1jj);
      tree->SetBranchAddress("m_all",&m_all);
      
      Double_t count_ee_PDF_UP(0), count_ee_PDF_DOWN(0), count_ee_nominal(0);
      Double_t count_mumu_PDF_UP(0), count_mumu_PDF_DOWN(0), count_mumu_nominal(0);
      Double_t count_emu_PDF_UP(0), count_emu_PDF_DOWN(0), count_emu_nominal(0);
      cout<<tree->GetEntries()<<endl;
      for(int j=0;j<tree->GetEntries();j++){
          tree->GetEntry(j);
          if(j%1000==0) cout<<j<<endl;
          //if(((masspoint=="mH260"||masspoint=="mH300"||masspoint=="H280_S135"||masspoint=="H300_S135"||masspoint=="H320_S135")&&numOfjet>=2)
          if(((masspoint=="mH400"||masspoint=="mH260"||masspoint=="mH300"||masspoint=="H280_S135"||masspoint=="H300_S135"||masspoint=="H320_S135")&&numOfjet>=2)//for interpolation
  //||((masspoint=="mH400"||masspoint=="mH500"||masspoint=="H340_S135"||masspoint=="H340_S145"||masspoint=="H340_S155"||masspoint=="H340_S165"
  ||((masspoint=="mH500"||masspoint=="H340_S135"||masspoint=="H340_S145"||masspoint=="H340_S155"||masspoint=="H340_S165"//for interpolation
                ||masspoint=="nonres")&&numOfjet>=3)){
              if(channel==1 && passOptCuts(masspoint,"ee",mindR_l1j, mindR_l2j,m_ll,m_l1jj,m_all)){
                 count_ee_nominal+=weight;
                 count_ee_PDF_UP+=weight*PDF_UP;
                 count_ee_PDF_DOWN+=weight*PDF_DOWN;
              }
              if(channel==2 && passOptCuts(masspoint,"mumu",mindR_l1j, mindR_l2j,m_ll,m_l1jj,m_all)){
                 count_mumu_nominal+=weight;
                 count_mumu_PDF_UP+=weight*PDF_UP;
                 count_mumu_PDF_DOWN+=weight*PDF_DOWN;
              }
              if(channel==3 && passOptCuts(masspoint,"emu",mindR_l1j, mindR_l2j,m_ll,m_l1jj,m_all)){
                 count_emu_nominal+=weight;
                 count_emu_PDF_UP+=weight*PDF_UP;
                 count_emu_PDF_DOWN+=weight*PDF_DOWN;
              }
          }              
          
      }
      //print
      cout<<"$$$$$$$$$$$$$$ "<<masspoint<<" $$$$$$$$$$$$$$$$"<<endl;
      ofstream outfile_ee;
      string outputFileName_ee="/scratchfs/atlas/zhoums/2LSSAna_output/output/Systematics/"+masspoint+"/ee_PDF.txt";
      outfile_ee.open(outputFileName_ee.c_str(),ios::trunc);
      outfile_ee<<"PDF_ee_"<<masspoint<<"_UP "<<count_ee_PDF_UP/count_ee_nominal<<"\n";
      outfile_ee<<"PDF_ee_"<<masspoint<<"_DOWN "<<count_ee_PDF_DOWN/count_ee_nominal<<"\n";
 
      ofstream outfile_mumu;
      string outputFileName_mumu="/scratchfs/atlas/zhoums/2LSSAna_output/output/Systematics/"+masspoint+"/mumu_PDF.txt";
      outfile_mumu.open(outputFileName_mumu.c_str(),ios::trunc);
      outfile_mumu<<"PDF_mumu_"<<masspoint<<"_UP "<<count_mumu_PDF_UP/count_mumu_nominal<<"\n";
      outfile_mumu<<"PDF_mumu_"<<masspoint<<"_DOWN "<<count_mumu_PDF_DOWN/count_mumu_nominal<<"\n";

      ofstream outfile_emu;
      string outputFileName_emu="/scratchfs/atlas/zhoums/2LSSAna_output/output/Systematics/"+masspoint+"/emu_PDF.txt";
      outfile_emu.open(outputFileName_emu.c_str(),ios::trunc);
      outfile_emu<<"PDF_emu_"<<masspoint<<"_UP "<<count_emu_PDF_UP/count_emu_nominal<<"\n";
      outfile_emu<<"PDF_emu_"<<masspoint<<"_DOWN "<<count_emu_PDF_DOWN/count_emu_nominal<<"\n";
  }
}
