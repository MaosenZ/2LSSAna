#include "TFile.h"
#include "TTree.h"
#include <iostream>
#include <iomanip>
#include "passOptCuts.cxx"

using namespace std;

void getSyst_theory(){
  
  TString masspoints[]={"mH260","mH300","mH400","mH500","nonres","H280_S135","H300_S135","H320_S135","H340_S145",
                        "H340_S145","H340_S155","H340_S165"};
  float WZ_syst=0.25, ttV_syst=0.5, tV_syst=0.5, ttH_syst=0.5, ssWW_syst=0.5, Vgam_syst=0.5; 
  //float WZ_ff_ele,ssWW_ff_ele, ttbar_ff_ele, Zjets_ff_ele;
  //float WZ_ff_mu,ssWW_ff_mu;
  for(int i=0;i<4;i++){
      TString masspoint=masspoints[i];
      /*if(masspoint=="mH260"||masspoint=="mH300"||masspoint=="H280_S135"||masspoint=="H300_S135"||masspoint=="H320_S135"){
         WZ_ff_ele=0.0369; ssWW_ff_ele=0.0124; ssWW_ff_mu=0.0630; WZ_ff_mu=0.1022;
         ttbar_ff_ele= ;Zjets_ff_ele=;
      }
      if(masspoint=="mH400"||masspoint=="mH500"||masspoint=="H340_S135"||masspoint=="H340_S145"||masspoint=="H340_S155"||masspoint=="H340_S165"
                ||masspoint=="nonres"){
         WZ_ff_ele=0.0369; ssWW_ff_ele=0.0124; ssWW_ff_mu=0.0630; WZ_ff_mu=0.1022;
      }*/
      TFile *input=new TFile("output/dataMC_2jets/miniNtuple_promptSS_detailed.root");
      TTree *tree=(TTree*)input->Get("Tree");

      Int_t channel,numOfjet;
      Double_t weight; 
      Float_t mindR_l1j, mindR_l2j,m_ll,m_l1jj,m_all;
      TString *component=0;
      tree->SetBranchAddress("channel",&channel);
      tree->SetBranchAddress("numOfjet",&numOfjet);
      tree->SetBranchAddress("weight",&weight);
      tree->SetBranchAddress("mindR_l1j",&mindR_l1j);
      tree->SetBranchAddress("mindR_l2j",&mindR_l2j);
      tree->SetBranchAddress("m_ll",&m_ll);
      tree->SetBranchAddress("m_l1jj",&m_l1jj);
      tree->SetBranchAddress("m_all",&m_all);
      tree->SetBranchAddress("component",&component);
      
      Double_t count_WZ_ee(0), count_ssWW_ee(0), count_ttH_ee(0), count_tV_ee(0), count_ttV_ee(0), count_ee_nominal(0);
     Double_t count_WZ_mumu(0), count_ssWW_mumu(0), count_ttH_mumu(0), count_tV_mumu(0), count_ttV_mumu(0), count_mumu_nominal(0);
      Double_t count_WZ_emu(0), count_ssWW_emu(0), count_ttH_emu(0), count_tV_emu(0), count_ttV_emu(0), count_emu_nominal(0);
      for(int j=0;j<tree->GetEntries();j++){
          tree->GetEntry(j);
          //              if((*component)=="ttV") cout<<*component<<endl;
          //if(((masspoint=="mH260"||masspoint=="mH300"||masspoint=="H280_S135"||masspoint=="H300_S135"||masspoint=="H320_S135")&&numOfjet>=2)
          if(((masspoint=="mH400"||masspoint=="mH260"||masspoint=="mH300"||masspoint=="H280_S135"||masspoint=="H300_S135"||masspoint=="H320_S135")&&numOfjet>=2)
  //||((masspoint=="mH400"||masspoint=="mH500"||masspoint=="H340_S135"||masspoint=="H340_S145"||masspoint=="H340_S155"||masspoint=="H340_S165"
  ||((masspoint=="mH500"||masspoint=="H340_S135"||masspoint=="H340_S145"||masspoint=="H340_S155"||masspoint=="H340_S165"//for interpolation
                ||masspoint=="nonres")&&numOfjet>=3)){
              if(channel==1 && passOptCuts(masspoint,"ee",mindR_l1j, mindR_l2j,m_ll,m_l1jj,m_all)){
                 count_ee_nominal+=weight;
                 if((*component)=="WZ") count_WZ_ee+=weight;
                 if((*component)=="ttH") count_ttH_ee+=weight;
                 if((*component)=="ttV") count_ttV_ee+=weight;
                 if((*component)=="tV") count_tV_ee+=weight;
                 if((*component)=="ssWW") count_ssWW_ee+=weight;
              }
              if(channel==2 && passOptCuts(masspoint,"mumu",mindR_l1j, mindR_l2j,m_ll,m_l1jj,m_all)){
                 count_mumu_nominal+=weight;
                 if((*component)=="WZ") count_WZ_mumu+=weight;
                 if((*component)=="ttH") count_ttH_mumu+=weight;
                 if((*component)=="ttV") count_ttV_mumu+=weight;
                 if((*component)=="tV") count_tV_mumu+=weight;
                 if((*component)=="ssWW") count_ssWW_mumu+=weight;
              }
              if(channel==3 && passOptCuts(masspoint,"emu",mindR_l1j, mindR_l2j,m_ll,m_l1jj,m_all)){
                 count_emu_nominal+=weight;
                 if((*component)=="WZ") count_WZ_emu+=weight;
                 if((*component)=="ttH") count_ttH_emu+=weight;
                 if((*component)=="ttV") count_ttV_emu+=weight;
                 if((*component)=="tV") count_tV_emu+=weight;
                 if((*component)=="ssWW") count_ssWW_emu+=weight;
              }
          }              
          
      }
      //print
      cout<<"$$$$$$$$$$$$$"<<masspoint<<"$$$$$$$$$$$$$$$$$$"<<endl;
      cout<<count_ee_nominal<<" "<<count_mumu_nominal<<" "<<count_emu_nominal<<endl;
      ofstream outfile_ee;
      string outputFileName_ee="/scratchfs/atlas/zhoums/2LSSAna_output/output/Systematics/"+masspoint+"/ee_theory.txt";
      outfile_ee.open(outputFileName_ee.c_str(),ios::trunc);
      outfile_ee<<"THEORY_WZ_UP "<<1+count_WZ_ee*WZ_syst/count_ee_nominal<<"\n";
      outfile_ee<<"THEORY_WZ_DOWN "<<1-count_WZ_ee*WZ_syst/count_ee_nominal<<"\n";
      outfile_ee<<"THEORY_ssWW_UP "<<1+count_ssWW_ee*ssWW_syst/count_ee_nominal<<"\n";
      outfile_ee<<"THEORY_ssWW_DOWN "<<1-count_ssWW_ee*ssWW_syst/count_ee_nominal<<"\n";
      outfile_ee<<"THEORY_ttV_UP "<<1+count_ttV_ee*tV_syst/count_ee_nominal<<"\n";
      outfile_ee<<"THEORY_ttV_DOWN "<<1-count_ttV_ee*tV_syst/count_ee_nominal<<"\n";
      outfile_ee<<"THEORY_tV_UP "<<1+count_tV_ee*tV_syst/count_ee_nominal<<"\n";
      outfile_ee<<"THEORY_tV_DOWN "<<1-count_tV_ee*tV_syst/count_ee_nominal<<"\n";
      outfile_ee<<"THEORY_ttH_UP "<<1+count_ttH_ee*ttH_syst/count_ee_nominal<<"\n";
      outfile_ee<<"THEORY_ttH_DOWN "<<1-count_ttH_ee*ttH_syst/count_ee_nominal<<"\n";
      //for Vgam
      outfile_ee<<"THEORY_Vgam_UP "<<1+Vgam_syst<<"\n";
      outfile_ee<<"THEORY_Vgam_DOWN "<<1-Vgam_syst<<"\n";
  
      ofstream outfile_mumu;
      string outputFileName_mumu="/scratchfs/atlas/zhoums/2LSSAna_output/output/Systematics/"+masspoint+"/mumu_theory.txt";
      outfile_mumu.open(outputFileName_mumu.c_str(),ios::trunc);
      outfile_mumu<<"THEORY_WZ_UP "<<1+count_WZ_mumu*WZ_syst/count_mumu_nominal<<"\n";
      outfile_mumu<<"THEORY_WZ_DOWN "<<1-count_WZ_mumu*WZ_syst/count_mumu_nominal<<"\n";
      outfile_mumu<<"THEORY_ssWW_UP "<<1+count_ssWW_mumu*ssWW_syst/count_mumu_nominal<<"\n";
      outfile_mumu<<"THEORY_ssWW_DOWN "<<1-count_ssWW_mumu*ssWW_syst/count_mumu_nominal<<"\n";
      outfile_mumu<<"THEORY_ttV_UP "<<1+count_ttV_mumu*ttV_syst/count_mumu_nominal<<"\n";
      outfile_mumu<<"THEORY_ttV_DOWN "<<1-count_ttV_mumu*ttV_syst/count_mumu_nominal<<"\n";
      outfile_mumu<<"THEORY_tV_UP "<<1+count_tV_mumu*tV_syst/count_mumu_nominal<<"\n";
      outfile_mumu<<"THEORY_tV_DOWN "<<1-count_tV_mumu*tV_syst/count_mumu_nominal<<"\n";
      outfile_mumu<<"THEORY_ttH_UP "<<1+count_ttH_mumu*ttH_syst/count_mumu_nominal<<"\n";
      outfile_mumu<<"THEORY_ttH_DOWN "<<1-count_ttH_mumu*ttH_syst/count_mumu_nominal<<"\n";

      ofstream outfile_emu;
      string outputFileName_emu="/scratchfs/atlas/zhoums/2LSSAna_output/output/Systematics/"+masspoint+"/emu_theory.txt";
      outfile_emu.open(outputFileName_emu.c_str(),ios::trunc);
      outfile_emu<<"THEORY_WZ_UP "<<1+count_WZ_emu*WZ_syst/count_emu_nominal<<"\n";
      outfile_emu<<"THEORY_WZ_DOWN "<<1-count_WZ_emu*WZ_syst/count_emu_nominal<<"\n";
      outfile_emu<<"THEORY_ssWW_UP "<<1+count_ssWW_emu*ssWW_syst/count_emu_nominal<<"\n";
      outfile_emu<<"THEORY_ssWW_DOWN "<<1-count_ssWW_emu*ssWW_syst/count_emu_nominal<<"\n";
      outfile_emu<<"THEORY_ttV_UP "<<1+count_ttV_emu*ttV_syst/count_emu_nominal<<"\n";
      outfile_emu<<"THEORY_ttV_DOWN "<<1-count_ttV_emu*ttV_syst/count_emu_nominal<<"\n";
      outfile_emu<<"THEORY_tV_UP "<<1+count_tV_emu*tV_syst/count_emu_nominal<<"\n";
      outfile_emu<<"THEORY_tV_DOWN "<<1-count_tV_emu*tV_syst/count_emu_nominal<<"\n";
      outfile_emu<<"THEORY_ttH_UP "<<1+count_ttH_emu*ttH_syst/count_emu_nominal<<"\n";
      outfile_emu<<"THEORY_ttH_DOWN "<<1-count_ttH_emu*ttH_syst/count_emu_nominal<<"\n";
      outfile_emu<<"THEORY_Vgam_UP "<<1+Vgam_syst<<"\n";
      outfile_emu<<"THEORY_Vgam_DOWN "<<1-Vgam_syst<<"\n";
      
  }
}
