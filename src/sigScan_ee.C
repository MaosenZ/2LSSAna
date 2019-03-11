//-------------------------------------------------------------------------------------------
// This script is to define cut-flow of hh->WWWW, using ntuples after hh4Wanalysis.C.
// Also can be used to draw plots
// Author: Maosen Zhou (maosen.zhou@cern.ch)
// Date: 25/Sep/2016
// --to scan different cuts to define best cuts
//   vars to be used: m_ll, mindR_l1j, mindR_l2j 
//-------------------------------------------------------------------------------------------

#include "TCanvas.h"
#include "TH1.h"
#include "TFile.h"
#include "TTree.h"
#include "TStyle.h"
#include <iostream>
#include "TString.h"
#include <vector>
#include "lumi.cxx"
using namespace std;
using namespace TMath;
void sigScan_ee(){


  TString vars[]={"pt_leadinglelpton","pt_sublepton","pt_j1","pt_j2","m_ll","m_jj","MET","m_jj_w","m_l1jj","mindR_l1j","mindR_l2j","pt_sum","m_all"};
  Float_t fixed_cuts[4];

  TFile *f_signal=new TFile("output/dataMC_2jets/miniNtuple_mH260.root");
  TFile *f_data=new TFile("output/dataMC_2jets/miniNtuple_datacombined.root");
  TFile *f_promptSS=new TFile("output/dataMC_2jets/miniNtuple_promptSS.root");
  TFile *f_Vgam=new TFile("output/dataMC_2jets/miniNtuple_Vgam.root");
  TFile *f_QmisID=new TFile("output/dataMC_2jets/miniNtuple_QmisID_datacombined.root");
  TFile *f_FFApp_data=new TFile("output/dataMC_2jets/miniNtuple_FFApp_datacombined.root");
  TFile *f_FFQmis=new TFile("output/dataMC_2jets/miniNtuple_FFQmis_datacombined.root");
  TFile *f_FFApp_subtractions_QmisID=new TFile("output/dataMC_2jets/miniNtuple_FFApp_subtractions_QmisID.root");
  TFile *f_FFApp_subtractions_promptSS=new TFile("output/dataMC_2jets/miniNtuple_FFApp_subtractions_promptSS.root");
  
  TTree *signal=(TTree*)f_signal->Get("Tree");
  TTree *data=(TTree*)f_data->Get("Tree");
  TTree *promptSS=(TTree*)f_promptSS->Get("Tree");
  TTree *Vgam=(TTree*)f_Vgam->Get("Tree");
  TTree *QmisID=(TTree*)f_QmisID->Get("Tree");
  TTree *FFApp_data=(TTree*)f_FFApp_data->Get("Tree");
  TTree *FFQmis=(TTree*)f_FFQmis->Get("Tree");
  TTree *FFApp_subtractions_QmisID=(TTree*)f_FFApp_subtractions_QmisID->Get("Tree");
  TTree *FFApp_subtractions_promptSS=(TTree*)f_FFApp_subtractions_promptSS->Get("Tree");

  Float_t signal_pt_sum,data_pt_sum,promptSS_pt_sum,Vgam_pt_sum,QmisID_pt_sum,FFApp_data_pt_sum,FFQmis_pt_sum,FFApp_subtractions_QmisID_pt_sum,
          FFApp_subtractions_promptSS_pt_sum;
  Float_t signal_met,data_met,promptSS_met,Vgam_met,QmisID_met,FFApp_data_met,FFQmis_met,FFApp_subtractions_QmisID_met,
          FFApp_subtractions_promptSS_met;
  Float_t signal_pt_leadinglepton,data_pt_leadinglepton,promptSS_pt_leadinglepton,Vgam_pt_leadinglepton,QmisID_pt_leadinglepton,
          FFApp_data_pt_leadinglepton,FFQmis_pt_leadinglepton,FFApp_subtractions_QmisID_pt_leadinglepton,
          FFApp_subtractions_promptSS_pt_leadinglepton;
  Float_t signal_pt_sublepton,data_pt_sublepton,promptSS_pt_sublepton,Vgam_pt_sublepton,QmisID_pt_sublepton,
          FFApp_data_pt_sublepton,FFQmis_pt_sublepton,FFApp_subtractions_QmisID_pt_sublepton,FFApp_subtractions_promptSS_pt_sublepton;
  Float_t signal_pt_j1,data_pt_j1,promptSS_pt_j1,Vgam_pt_j1,QmisID_pt_j1,FFApp_data_pt_j1,FFQmis_pt_j1,FFApp_subtractions_QmisID_pt_j1,
          FFApp_subtractions_promptSS_pt_j1;
  Float_t signal_pt_j2,data_pt_j2,promptSS_pt_j2,Vgam_pt_j2,QmisID_pt_j2,FFApp_data_pt_j2,FFQmis_pt_j2,FFApp_subtractions_QmisID_pt_j2,
          FFApp_subtractions_promptSS_pt_j2;
  Float_t signal_m_ll,data_m_ll,promptSS_m_ll,Vgam_m_ll,QmisID_m_ll,FFApp_data_m_ll,FFQmis_m_ll,FFApp_subtractions_QmisID_m_ll,
          FFApp_subtractions_promptSS_m_ll;
  Float_t signal_m_jj,data_m_jj,promptSS_m_jj,Vgam_m_jj,QmisID_m_jj,FFApp_data_m_jj,FFQmis_m_jj,FFApp_subtractions_QmisID_m_jj,
          FFApp_subtractions_promptSS_m_jj;
  Float_t signal_m_jj_w,data_m_jj_w,promptSS_m_jj_w,Vgam_m_jj_w,QmisID_m_jj_w,FFApp_data_m_jj_w,FFQmis_m_jj_w,
          FFApp_subtractions_QmisID_m_jj_w,FFApp_subtractions_promptSS_m_jj_w;
  Float_t signal_m_l1jj,data_m_l1jj,promptSS_m_l1jj,Vgam_m_l1jj,QmisID_m_l1jj,FFApp_data_m_l1jj,FFQmis_m_l1jj,
          FFApp_subtractions_QmisID_m_l1jj,FFApp_subtractions_promptSS_m_l1jj;
  Float_t signal_m_all,data_m_all,promptSS_m_all,Vgam_m_all,QmisID_m_all,FFApp_data_m_all,FFQmis_m_all,FFApp_subtractions_QmisID_m_all,
          FFApp_subtractions_promptSS_m_all;
  Float_t signal_mindR_l1j,data_mindR_l1j,promptSS_mindR_l1j,Vgam_mindR_l1j,QmisID_mindR_l1j,FFApp_data_mindR_l1j,FFQmis_mindR_l1j,
          FFApp_subtractions_QmisID_mindR_l1j,FFApp_subtractions_promptSS_mindR_l1j;
  Float_t signal_mindR_l2j,data_mindR_l2j,promptSS_mindR_l2j,Vgam_mindR_l2j,QmisID_mindR_l2j,FFApp_data_mindR_l2j,FFQmis_mindR_l2j,
          FFApp_subtractions_QmisID_mindR_l2j,FFApp_subtractions_promptSS_mindR_l2j;
  Double_t signal_weight,data_weight,promptSS_weight,Vgam_weight,QmisID_weight,FFApp_data_weight,FFQmis_weight,
           FFApp_subtractions_QmisID_weight,FFApp_subtractions_promptSS_weight;
  Int_t signal_channel,data_channel,promptSS_channel,Vgam_channel,QmisID_channel,FFApp_data_channel,FFQmis_channel,
        FFApp_subtractions_QmisID_channel,FFApp_subtractions_promptSS_channel;
  Int_t signal_numOfjet,data_numOfjet,promptSS_numOfjet,Vgam_numOfjet,QmisID_numOfjet,FFApp_data_numOfjet,FFQmis_numOfjet,
        FFApp_subtractions_QmisID_numOfjet,FFApp_subtractions_promptSS_numOfjet;
  
  signal->SetBranchAddress("pt_leadinglepton",&signal_pt_leadinglepton);
  data->SetBranchAddress("pt_leadinglepton",&data_pt_leadinglepton);
  promptSS->SetBranchAddress("pt_leadinglepton",&promptSS_pt_leadinglepton);
  Vgam->SetBranchAddress("pt_leadinglepton",&Vgam_pt_leadinglepton);
  QmisID->SetBranchAddress("pt_leadinglepton",&QmisID_pt_leadinglepton);
  FFApp_data->SetBranchAddress("pt_leadinglepton",&FFApp_data_pt_leadinglepton);
  FFQmis->SetBranchAddress("pt_leadinglepton",&FFQmis_pt_leadinglepton);
  FFApp_subtractions_QmisID->SetBranchAddress("pt_leadinglepton",&FFApp_subtractions_QmisID_pt_leadinglepton);
  FFApp_subtractions_promptSS->SetBranchAddress("pt_leadinglepton",&FFApp_subtractions_promptSS_pt_leadinglepton);

  signal->SetBranchAddress("pt_sublepton",&signal_pt_sublepton);
  data->SetBranchAddress("pt_sublepton",&data_pt_sublepton);
  promptSS->SetBranchAddress("pt_sublepton",&promptSS_pt_sublepton);
  Vgam->SetBranchAddress("pt_sublepton",&Vgam_pt_sublepton);
  QmisID->SetBranchAddress("pt_sublepton",&QmisID_pt_sublepton);
  FFApp_data->SetBranchAddress("pt_sublepton",&FFApp_data_pt_sublepton);
  FFQmis->SetBranchAddress("pt_sublepton",&FFQmis_pt_sublepton);
  FFApp_subtractions_QmisID->SetBranchAddress("pt_sublepton",&FFApp_subtractions_QmisID_pt_sublepton);
  FFApp_subtractions_promptSS->SetBranchAddress("pt_sublepton",&FFApp_subtractions_promptSS_pt_sublepton);

  signal->SetBranchAddress("pt_j1",&signal_pt_j1);
  data->SetBranchAddress("pt_j1",&data_pt_j1);
  promptSS->SetBranchAddress("pt_j1",&promptSS_pt_j1);
  Vgam->SetBranchAddress("pt_j1",&Vgam_pt_j1);
  QmisID->SetBranchAddress("pt_j1",&QmisID_pt_j1);
  FFApp_data->SetBranchAddress("pt_j1",&FFApp_data_pt_j1);
  FFQmis->SetBranchAddress("pt_j1",&FFQmis_pt_j1);
  FFApp_subtractions_QmisID->SetBranchAddress("pt_j1",&FFApp_subtractions_QmisID_pt_j1);
  FFApp_subtractions_promptSS->SetBranchAddress("pt_j1",&FFApp_subtractions_promptSS_pt_j1);

  signal->SetBranchAddress("pt_j2",&signal_pt_j2);
  data->SetBranchAddress("pt_j2",&data_pt_j2);
  promptSS->SetBranchAddress("pt_j2",&promptSS_pt_j2);
  Vgam->SetBranchAddress("pt_j2",&Vgam_pt_j2);
  QmisID->SetBranchAddress("pt_j2",&QmisID_pt_j2);
  FFApp_data->SetBranchAddress("pt_j2",&FFApp_data_pt_j2);
  FFQmis->SetBranchAddress("pt_j2",&FFQmis_pt_j2);
  FFApp_subtractions_QmisID->SetBranchAddress("pt_j2",&FFApp_subtractions_QmisID_pt_j2);
  FFApp_subtractions_promptSS->SetBranchAddress("pt_j2",&FFApp_subtractions_promptSS_pt_j2);

  signal->SetBranchAddress("MET",&signal_met);
  data->SetBranchAddress("MET",&data_met);
  promptSS->SetBranchAddress("MET",&promptSS_met);
  Vgam->SetBranchAddress("MET",&Vgam_met);
  QmisID->SetBranchAddress("MET",&QmisID_met);
  FFApp_data->SetBranchAddress("MET",&FFApp_data_met);
  FFQmis->SetBranchAddress("MET",&FFQmis_met);
  FFApp_subtractions_QmisID->SetBranchAddress("MET",&FFApp_subtractions_QmisID_met);
  FFApp_subtractions_promptSS->SetBranchAddress("MET",&FFApp_subtractions_promptSS_met);

  signal->SetBranchAddress("m_ll",&signal_m_ll);
  data->SetBranchAddress("m_ll",&data_m_ll);
  promptSS->SetBranchAddress("m_ll",&promptSS_m_ll);
  Vgam->SetBranchAddress("m_ll",&Vgam_m_ll);
  QmisID->SetBranchAddress("m_ll",&QmisID_m_ll);
  FFApp_data->SetBranchAddress("m_ll",&FFApp_data_m_ll);
  FFQmis->SetBranchAddress("m_ll",&FFQmis_m_ll);
  FFApp_subtractions_QmisID->SetBranchAddress("m_ll",&FFApp_subtractions_QmisID_m_ll);
  FFApp_subtractions_promptSS->SetBranchAddress("m_ll",&FFApp_subtractions_promptSS_m_ll);

  signal->SetBranchAddress("m_jj_w",&signal_m_jj_w);
  data->SetBranchAddress("m_jj_w",&data_m_jj_w);
  promptSS->SetBranchAddress("m_jj_w",&promptSS_m_jj_w);
  Vgam->SetBranchAddress("m_jj_w",&Vgam_m_jj_w);
  QmisID->SetBranchAddress("m_jj_w",&QmisID_m_jj_w);
  FFApp_data->SetBranchAddress("m_jj_w",&FFApp_data_m_jj_w);
  FFQmis->SetBranchAddress("m_jj_w",&FFQmis_m_jj_w);
  FFApp_subtractions_QmisID->SetBranchAddress("m_jj_w",&FFApp_subtractions_QmisID_m_jj_w);
  FFApp_subtractions_promptSS->SetBranchAddress("m_jj_w",&FFApp_subtractions_promptSS_m_jj_w);

  signal->SetBranchAddress("m_jj",&signal_m_jj);
  data->SetBranchAddress("m_jj",&data_m_jj);
  promptSS->SetBranchAddress("m_jj",&promptSS_m_jj);
  Vgam->SetBranchAddress("m_jj",&Vgam_m_jj);
  QmisID->SetBranchAddress("m_jj",&QmisID_m_jj);
  FFApp_data->SetBranchAddress("m_jj",&FFApp_data_m_jj);
  FFQmis->SetBranchAddress("m_jj",&FFQmis_m_jj);
  FFApp_subtractions_QmisID->SetBranchAddress("m_jj",&FFApp_subtractions_QmisID_m_jj);
  FFApp_subtractions_promptSS->SetBranchAddress("m_jj",&FFApp_subtractions_promptSS_m_jj);

  signal->SetBranchAddress("m_l1jj",&signal_m_l1jj);
  data->SetBranchAddress("m_l1jj",&data_m_l1jj);
  promptSS->SetBranchAddress("m_l1jj",&promptSS_m_l1jj);
  Vgam->SetBranchAddress("m_l1jj",&Vgam_m_l1jj);
  QmisID->SetBranchAddress("m_l1jj",&QmisID_m_l1jj);
  FFApp_data->SetBranchAddress("m_l1jj",&FFApp_data_m_l1jj);
  FFQmis->SetBranchAddress("m_l1jj",&FFQmis_m_l1jj);
  FFApp_subtractions_QmisID->SetBranchAddress("m_l1jj",&FFApp_subtractions_QmisID_m_l1jj);
  FFApp_subtractions_promptSS->SetBranchAddress("m_l1jj",&FFApp_subtractions_promptSS_m_l1jj);

  signal->SetBranchAddress("m_all",&signal_m_all);
  data->SetBranchAddress("m_all",&data_m_all);
  promptSS->SetBranchAddress("m_all",&promptSS_m_all);
  Vgam->SetBranchAddress("m_all",&Vgam_m_all);
  QmisID->SetBranchAddress("m_all",&QmisID_m_all);
  FFApp_data->SetBranchAddress("m_all",&FFApp_data_m_all);
  FFQmis->SetBranchAddress("m_all",&FFQmis_m_all);
  FFApp_subtractions_QmisID->SetBranchAddress("m_all",&FFApp_subtractions_QmisID_m_all);
  FFApp_subtractions_promptSS->SetBranchAddress("m_all",&FFApp_subtractions_promptSS_m_all);

  signal->SetBranchAddress("pt_sum",&signal_pt_sum);
  data->SetBranchAddress("pt_sum",&data_pt_sum);
  promptSS->SetBranchAddress("pt_sum",&promptSS_pt_sum);
  Vgam->SetBranchAddress("pt_sum",&Vgam_pt_sum);
  QmisID->SetBranchAddress("pt_sum",&QmisID_pt_sum);
  FFApp_data->SetBranchAddress("pt_sum",&FFApp_data_pt_sum);
  FFQmis->SetBranchAddress("pt_sum",&FFQmis_pt_sum);
  FFApp_subtractions_QmisID->SetBranchAddress("pt_sum",&FFApp_subtractions_QmisID_pt_sum);
  FFApp_subtractions_promptSS->SetBranchAddress("pt_sum",&FFApp_subtractions_promptSS_pt_sum);

  signal->SetBranchAddress("mindR_l1j",&signal_mindR_l1j);
  data->SetBranchAddress("mindR_l1j",&data_mindR_l1j);
  promptSS->SetBranchAddress("mindR_l1j",&promptSS_mindR_l1j);
  Vgam->SetBranchAddress("mindR_l1j",&Vgam_mindR_l1j);
  QmisID->SetBranchAddress("mindR_l1j",&QmisID_mindR_l1j);
  FFApp_data->SetBranchAddress("mindR_l1j",&FFApp_data_mindR_l1j);
  FFQmis->SetBranchAddress("mindR_l1j",&FFQmis_mindR_l1j);
  FFApp_subtractions_QmisID->SetBranchAddress("mindR_l1j",&FFApp_subtractions_QmisID_mindR_l1j);
  FFApp_subtractions_promptSS->SetBranchAddress("mindR_l1j",&FFApp_subtractions_promptSS_mindR_l1j);

  signal->SetBranchAddress("mindR_l2j",&signal_mindR_l2j);
  data->SetBranchAddress("mindR_l2j",&data_mindR_l2j);
  promptSS->SetBranchAddress("mindR_l2j",&promptSS_mindR_l2j);
  Vgam->SetBranchAddress("mindR_l2j",&Vgam_mindR_l2j);
  QmisID->SetBranchAddress("mindR_l2j",&QmisID_mindR_l2j);
  FFApp_data->SetBranchAddress("mindR_l2j",&FFApp_data_mindR_l2j);
  FFQmis->SetBranchAddress("mindR_l2j",&FFQmis_mindR_l2j);
  FFApp_subtractions_QmisID->SetBranchAddress("mindR_l2j",&FFApp_subtractions_QmisID_mindR_l2j);
  FFApp_subtractions_promptSS->SetBranchAddress("mindR_l2j",&FFApp_subtractions_promptSS_mindR_l2j);

  signal->SetBranchAddress("weight",&signal_weight);
  data->SetBranchAddress("weight",&data_weight);
  promptSS->SetBranchAddress("weight",&promptSS_weight);
  Vgam->SetBranchAddress("weight",&Vgam_weight);
  QmisID->SetBranchAddress("weight",&QmisID_weight);
  FFApp_data->SetBranchAddress("weight",&FFApp_data_weight);
  FFQmis->SetBranchAddress("weight",&FFQmis_weight);
  FFApp_subtractions_QmisID->SetBranchAddress("weight",&FFApp_subtractions_QmisID_weight);
  FFApp_subtractions_promptSS->SetBranchAddress("weight",&FFApp_subtractions_promptSS_weight);

  signal->SetBranchAddress("channel",&signal_channel);
  data->SetBranchAddress("channel",&data_channel);
  promptSS->SetBranchAddress("channel",&promptSS_channel);
  Vgam->SetBranchAddress("channel",&Vgam_channel);
  QmisID->SetBranchAddress("channel",&QmisID_channel);
  FFApp_data->SetBranchAddress("channel",&FFApp_data_channel);
  FFQmis->SetBranchAddress("channel",&FFQmis_channel);
  FFApp_subtractions_QmisID->SetBranchAddress("channel",&FFApp_subtractions_QmisID_channel);
  FFApp_subtractions_promptSS->SetBranchAddress("channel",&FFApp_subtractions_promptSS_channel);

  signal->SetBranchAddress("numOfjet",&signal_numOfjet);
  data->SetBranchAddress("numOfjet",&data_numOfjet);
  promptSS->SetBranchAddress("numOfjet",&promptSS_numOfjet);
  Vgam->SetBranchAddress("numOfjet",&Vgam_numOfjet);
  QmisID->SetBranchAddress("numOfjet",&QmisID_numOfjet);
  FFApp_data->SetBranchAddress("numOfjet",&FFApp_data_numOfjet);
  FFQmis->SetBranchAddress("numOfjet",&FFQmis_numOfjet);
  FFApp_subtractions_QmisID->SetBranchAddress("numOfjet",&FFApp_subtractions_QmisID_numOfjet);
  FFApp_subtractions_promptSS->SetBranchAddress("numOfjet",&FFApp_subtractions_promptSS_numOfjet);

  Int_t Nbins=40, xmin=0, xmax=200;
  TH1F *frame=new TH1F("frame","",Nbins,xmin,xmax);
  TH1F *hist_signal=new TH1F("hist_signal","",Nbins,xmin,xmax);
  TH1F *hist_promptSS=new TH1F("hist_promptSS","",Nbins,xmin,xmax);
  TH1F *hist_Vgam=new TH1F("hist_Vgam","",Nbins,xmin,xmax);
  TH1F *hist_QmisID=new TH1F("hist_QmisID","",Nbins,xmin,xmax);
  TH1F *hist_fake=new TH1F("hist_fake","",Nbins,xmin,xmax);
  Int_t numOfdata=0;  
  for(Long64_t entry=0; entry<data->GetEntries();entry++) {
          data->GetEntry(entry);
          if(data_channel!=1)continue;
          if(data_numOfjet<=2)continue;
             numOfdata++;
  }
  float tmp=0;
  for(Int_t index=0;index<4;index++){
      fixed_cuts[0]=0;fixed_cuts[1]=10;fixed_cuts[2]=10;fixed_cuts[3]=9999;
  for(Int_t i=0;i<=30;i++){
      Int_t numOfsignal=0,numOfpromptSS=0, numOfVgam=0, numOfVgam=0,numOfQmisID=0,numOfFFQmis=0,numOfFFApp_subtractions_QmisID=0,
            numOfFFApp_subtractions_promptSS=0,numOfFFApp_data=0;
      Double_t numOfwgtsignal=0,numOfwgtpromptSS=0, numOfwgtVgam=0, numOfwgtVgam=0,numOfwgtQmisID=0,numOfwgtFFQmis=0,
               numOfwgtFFApp_subtractions_QmisID=0,numOfwgtFFApp_subtractions_promptSS=0,numOfwgtFFApp_data=0;
      Double_t errOfwgtsignal=0,errOfwgtpromptSS=0, errOfwgtVgam=0, errOfwgtVgam=0,errOfwgtQmisID=0,errOfwgtFFQmis=0,
               errOfwgtFFApp_subtractions_QmisID=0,errOfwgtFFApp_subtractions_promptSS=0,errOfwgtFFApp_data=0;
      if(index==0) Float_t cut=5*i;
      if(index==1 || index==2) Float_t cut=0.3+i*0.1;
      if(index==3)Float_t cut=50+i*10;
      for(Long64_t entry=0; entry<signal->GetEntries();entry++) {
          signal->GetEntry(entry);
          if(signal_channel!=1)continue;
          if(signal_numOfjet<=2)continue;
          if(index==0 &&fabs(signal_m_ll-91.2)>cut){
             numOfsignal++;
             numOfwgtsignal+=signal_weight;errOfwgtsignal+=signal_weight*signal_weight;
          }
          if(index==1 && fabs(signal_m_ll-91.2)>fixed_cuts[0]&&signal_mindR_l2j<cut){
             numOfsignal++;
             numOfwgtsignal+=signal_weight; errOfwgtsignal+=signal_weight*signal_weight;
          } 
          if(index==2 &&fabs(signal_m_ll-91.2)>fixed_cuts[0]&&signal_mindR_l2j<fixed_cuts[1]&&signal_mindR_l1j<cut){
             numOfsignal++;
             numOfwgtsignal+=signal_weight; errOfwgtsignal+=signal_weight*signal_weight;
          }
        if(index==3 &&fabs(signal_m_ll-91.2)>fixed_cuts[0]&&signal_mindR_l2j<fixed_cuts[1]&&signal_mindR_l1j<fixed_cuts[2]&&signal_m_l1jj<cut){
             numOfsignal++;
             numOfwgtsignal+=signal_weight; errOfwgtsignal+=signal_weight*signal_weight;
          }
      }
      for(Long64_t entry=0; entry<promptSS->GetEntries();entry++) {
          promptSS->GetEntry(entry);
          if(promptSS_channel!=1)continue;
          if(promptSS_numOfjet<=2)continue;
          if(index==0 &&fabs(promptSS_m_ll-91.2)>cut){
             numOfpromptSS++;
             numOfwgtpromptSS+=promptSS_weight; errOfwgtpromptSS+=promptSS_weight*promptSS_weight;
          }
          if(index==1 && fabs(promptSS_m_ll-91.2)>fixed_cuts[0]&&promptSS_mindR_l2j<cut){
             numOfpromptSS++;
             numOfwgtpromptSS+=promptSS_weight; errOfwgtpromptSS+=promptSS_weight*promptSS_weight;
          }
          if(index==2 &&fabs(promptSS_m_ll-91.2)>fixed_cuts[0]&&promptSS_mindR_l2j<fixed_cuts[1]&&promptSS_mindR_l1j<cut){
             numOfpromptSS++;
             numOfwgtpromptSS+=promptSS_weight; errOfwgtpromptSS+=promptSS_weight*promptSS_weight;
          }
          if(index==3 &&fabs(promptSS_m_ll-91.2)>fixed_cuts[0]&&promptSS_mindR_l2j<fixed_cuts[1]&&promptSS_mindR_l1j<fixed_cuts[2]&&promptSS_m_l1jj<cut){
             numOfpromptSS++;
             numOfwgtpromptSS+=promptSS_weight; errOfwgtpromptSS+=promptSS_weight*promptSS_weight;
          }
      }
      for(Long64_t entry=0; entry<Vgam->GetEntries();entry++) {
          Vgam->GetEntry(entry);
          if(Vgam_channel!=1)continue;
          if(Vgam_numOfjet<=2)continue;
          if(index==0 &&fabs(Vgam_m_ll-91.2)>cut){
             numOfVgam++;
             numOfwgtVgam+=Vgam_weight; errOfwgtVgam+=Vgam_weight*Vgam_weight;
          }
          if(index==1 && fabs(Vgam_m_ll-91.2)>fixed_cuts[0]&&Vgam_mindR_l2j<cut){
             numOfVgam++;
             numOfwgtVgam+=Vgam_weight; errOfwgtVgam+=Vgam_weight*Vgam_weight;
          }
          if(index==2 &&fabs(Vgam_m_ll-91.2)>fixed_cuts[0]&&Vgam_mindR_l2j<fixed_cuts[1]&&Vgam_mindR_l1j<cut){
             numOfVgam++;
             numOfwgtVgam+=Vgam_weight; errOfwgtVgam+=Vgam_weight*Vgam_weight;
          }
          if(index==3 &&fabs(Vgam_m_ll-91.2)>fixed_cuts[0]&&Vgam_mindR_l2j<fixed_cuts[1]&&Vgam_mindR_l1j<fixed_cuts[2]&&Vgam_m_l1jj<cut){
             numOfVgam++;
             numOfwgtVgam+=Vgam_weight; errOfwgtVgam+=Vgam_weight*Vgam_weight;
          }
      }
      for(Long64_t entry=0; entry<QmisID->GetEntries();entry++) {
          QmisID->GetEntry(entry);
          if(QmisID_channel!=1)continue;
          if(QmisID_numOfjet<=2)continue;
          if(index==0 &&fabs(QmisID_m_ll-91.2)>cut){
             numOfQmisID++;
             numOfwgtQmisID+=QmisID_weight; errOfwgtQmisID+=QmisID_weight*QmisID_weight;
          }
          if(index==1 && fabs(QmisID_m_ll-91.2)>fixed_cuts[0]&&QmisID_mindR_l2j<cut){
             numOfQmisID++;
             numOfwgtQmisID+=QmisID_weight; errOfwgtQmisID+=QmisID_weight*QmisID_weight;
          }
          if(index==2 &&fabs(QmisID_m_ll-91.2)>fixed_cuts[0]&&QmisID_mindR_l2j<fixed_cuts[1]&&QmisID_mindR_l1j<cut){
             numOfQmisID++;
             numOfwgtQmisID+=QmisID_weight; errOfwgtQmisID+=QmisID_weight*QmisID_weight;
          }
        if(index==3 &&fabs(QmisID_m_ll-91.2)>fixed_cuts[0]&&QmisID_mindR_l2j<fixed_cuts[1]&&QmisID_mindR_l1j<fixed_cuts[2]&&QmisID_m_l1jj<cut){
             numOfQmisID++;
             numOfwgtQmisID+=QmisID_weight; errOfwgtQmisID+=QmisID_weight*QmisID_weight;
          }
      }
      for(Long64_t entry=0; entry<FFApp_data->GetEntries();entry++) {
          FFApp_data->GetEntry(entry);
          if(FFApp_data_channel!=1)continue;
          if(FFApp_data_numOfjet<=2)continue;
          if(index==0 &&fabs(FFApp_data_m_ll-91.2)>cut){
             numOfFFApp_data++;
             numOfwgtFFApp_data+=FFApp_data_weight; errOfwgtFFApp_data+=FFApp_data_weight*FFApp_data_weight;
          }
          if(index==1 && fabs(FFApp_data_m_ll-91.2)>fixed_cuts[0]&&FFApp_data_mindR_l2j<cut){
             numOfFFApp_data++;
             numOfwgtFFApp_data+=FFApp_data_weight; errOfwgtFFApp_data+=FFApp_data_weight*FFApp_data_weight;
          }
          if(index==2 &&fabs(FFApp_data_m_ll-91.2)>fixed_cuts[0]&&FFApp_data_mindR_l2j<fixed_cuts[1]&&FFApp_data_mindR_l1j<cut){
             numOfFFApp_data++;
             numOfwgtFFApp_data+=FFApp_data_weight; errOfwgtFFApp_data+=FFApp_data_weight*FFApp_data_weight;
          }
          if(index==3 &&fabs(FFApp_data_m_ll-91.2)>fixed_cuts[0]&&FFApp_data_mindR_l2j<fixed_cuts[1]&&FFApp_data_mindR_l1j<fixed_cuts[2]&&FFApp_data_m_l1jj<cut){
             numOfFFApp_data++;
             numOfwgtFFApp_data+=FFApp_data_weight; errOfwgtFFApp_data+=FFApp_data_weight*FFApp_data_weight;
          }
      }
      for(Long64_t entry=0; entry<FFQmis->GetEntries();entry++) {
          FFQmis->GetEntry(entry);
          if(FFQmis_channel!=1)continue;
          if(FFQmis_numOfjet<=2)continue;
          if(index==0 &&fabs(FFQmis_m_ll-91.2)>cut){
             numOfFFQmis++;
             numOfwgtFFQmis+=FFQmis_weight;
             errOfwgtFFQmis+=FFQmis_weight*FFQmis_weight;
          }
          if(index==1 && fabs(FFQmis_m_ll-91.2)>fixed_cuts[0]&&FFQmis_mindR_l2j<cut){
             numOfFFQmis++;
             numOfwgtFFQmis+=FFQmis_weight;
             errOfwgtFFQmis+=FFQmis_weight*FFQmis_weight;
          }
          if(index==2 &&fabs(FFQmis_m_ll-91.2)>fixed_cuts[0]&&FFQmis_mindR_l2j<fixed_cuts[1]&&FFQmis_mindR_l1j<cut){
             numOfFFQmis++;
             numOfwgtFFQmis+=FFQmis_weight;
             errOfwgtFFQmis+=FFQmis_weight*FFQmis_weight;
          }
          if(index==3 &&fabs(FFQmis_m_ll-91.2)>fixed_cuts[0]&&FFQmis_mindR_l2j<fixed_cuts[1]&&FFQmis_mindR_l1j<fixed_cuts[2]&&FFQmis_m_l1jj<cut){
             numOfFFQmis++;
             numOfwgtFFQmis+=FFQmis_weight;
             errOfwgtFFQmis+=FFQmis_weight*FFQmis_weight;
          }
      }
      for(Long64_t entry=0; entry<FFApp_subtractions_QmisID->GetEntries();entry++) {
          FFApp_subtractions_QmisID->GetEntry(entry);
          if(FFApp_subtractions_QmisID_channel!=1)continue;
          if(FFApp_subtractions_QmisID_numOfjet<=2)continue;
          if(index==0 &&fabs(FFApp_subtractions_QmisID_m_ll-91.2)>cut){
             numOfFFApp_subtractions_QmisID++;
             numOfwgtFFApp_subtractions_QmisID+=FFApp_subtractions_QmisID_weight;
             errOfwgtFFApp_subtractions_QmisID+=FFApp_subtractions_QmisID_weight*FFApp_subtractions_QmisID_weight;
          }
          if(index==1 && fabs(FFApp_subtractions_QmisID_m_ll-91.2)>fixed_cuts[0]&&FFApp_subtractions_QmisID_mindR_l2j<cut){
             numOfFFApp_subtractions_QmisID++;
             numOfwgtFFApp_subtractions_QmisID+=FFApp_subtractions_QmisID_weight;
             errOfwgtFFApp_subtractions_QmisID+=FFApp_subtractions_QmisID_weight*FFApp_subtractions_QmisID_weight;
          }
          if(index==2 &&fabs(FFApp_subtractions_QmisID_m_ll-91.2)>fixed_cuts[0]&&FFApp_subtractions_QmisID_mindR_l2j<fixed_cuts[1]&&FFApp_subtractions_QmisID_mindR_l1j<cut){
             numOfFFApp_subtractions_QmisID++;
             numOfwgtFFApp_subtractions_QmisID+=FFApp_subtractions_QmisID_weight;
             errOfwgtFFApp_subtractions_QmisID+=FFApp_subtractions_QmisID_weight*FFApp_subtractions_QmisID_weight;
          }
          if(index==3 &&fabs(FFApp_subtractions_QmisID_m_ll-91.2)>fixed_cuts[0]&&FFApp_subtractions_QmisID_mindR_l2j<fixed_cuts[1]&&FFApp_subtractions_QmisID_mindR_l1j<fixed_cuts[2]&&FFApp_subtractions_QmisID_m_l1jj<cut){
             numOfFFApp_subtractions_QmisID++;
             numOfwgtFFApp_subtractions_QmisID+=FFApp_subtractions_QmisID_weight;
             errOfwgtFFApp_subtractions_QmisID+=FFApp_subtractions_QmisID_weight*FFApp_subtractions_QmisID_weight;
          }
      }
      for(Long64_t entry=0; entry<FFApp_subtractions_promptSS->GetEntries();entry++) {
          FFApp_subtractions_promptSS->GetEntry(entry);
          if(FFApp_subtractions_promptSS_channel!=1)continue;
          if(FFApp_subtractions_promptSS_numOfjet<=2)continue;
          if(index==0 &&fabs(FFApp_subtractions_promptSS_m_ll-91.2)>cut){
             numOfFFApp_subtractions_promptSS++;
             numOfwgtFFApp_subtractions_promptSS+=FFApp_subtractions_promptSS_weight;
             errOfwgtFFApp_subtractions_promptSS+=FFApp_subtractions_promptSS_weight*FFApp_subtractions_promptSS_weight;
          }
          if(index==1 && fabs(FFApp_subtractions_promptSS_m_ll-91.2)>fixed_cuts[0]&&FFApp_subtractions_promptSS_mindR_l2j<cut){
             numOfFFApp_subtractions_promptSS++;
             numOfwgtFFApp_subtractions_promptSS+=FFApp_subtractions_promptSS_weight;
             errOfwgtFFApp_subtractions_promptSS+=FFApp_subtractions_promptSS_weight*FFApp_subtractions_promptSS_weight;
          }
          if(index==2 &&fabs(FFApp_subtractions_promptSS_m_ll-91.2)>fixed_cuts[0]&&FFApp_subtractions_promptSS_mindR_l2j<fixed_cuts[1]&&FFApp_subtractions_promptSS_mindR_l1j<cut){
             numOfFFApp_subtractions_promptSS++;
             numOfwgtFFApp_subtractions_promptSS+=FFApp_subtractions_promptSS_weight;
             errOfwgtFFApp_subtractions_promptSS+=FFApp_subtractions_promptSS_weight*FFApp_subtractions_promptSS_weight;
          }
          if(index==3 &&fabs(FFApp_subtractions_promptSS_m_ll-91.2)>fixed_cuts[0]&&FFApp_subtractions_promptSS_mindR_l2j<fixed_cuts[1]&&FFApp_subtractions_promptSS_mindR_l1j<fixed_cuts[2]&&FFApp_subtractions_promptSS_m_l1jj<cut){
             numOfFFApp_subtractions_promptSS++;
             numOfwgtFFApp_subtractions_promptSS+=FFApp_subtractions_promptSS_weight;
             errOfwgtFFApp_subtractions_promptSS+=FFApp_subtractions_promptSS_weight*FFApp_subtractions_promptSS_weight;
          }
      }

      Double_t totalbkg=-numOfwgtFFApp_subtractions_promptSS*lumi()-numOfwgtFFApp_subtractions_QmisID*lumi()-numOfwgtFFQmis+numOfwgtFFApp_data+numOfwgtQmisID+numOfwgtpromptSS*lumi()+numOfwgtVgam*lumi();
      Double_t tmpsig=numOfwgtsignal*lumi()/sqrt(totalbkg);
      Double_t tmpsigpur=numOfwgtsignal*lumi()/(totalbkg);
      if(tmpsig>tmp){
         Double_t sig=tmpsig;
         Double_t sig_Z0=sqrt(2*((numOfwgtsignal*lumi()+totalbkg)*log((numOfwgtsignal*lumi()+totalbkg)/totalbkg)-numOfwgtsignal*lumi()));
         Double_t sigpur=tmpsigpur;
         Double_t final_cut=cut; 
         Double_t final_weighted_signal=numOfwgtsignal*lumi();Int_t final_signal=numOfsignal;
         Double_t final_weighted_QmisID=numOfwgtQmisID;Int_t final_QmisID=numOfQmisID;
         Double_t final_weighted_FFQmis=numOfwgtFFQmis; Int_t final_FFQmis=numOfFFQmis;
         Double_t final_weighted_FFApp_subtractions_QmisID=numOfwgtFFApp_subtractions_QmisID*lumi(); 
                  Int_t final_FFApp_subtractions_QmisID=numOfFFApp_subtractions_QmisID;
         Double_t final_weighted_FFApp_subtractions_promptSS=numOfwgtFFApp_subtractions_promptSS*lumi();              
                  Int_t final_FFApp_subtractions_promptSS=numOfFFApp_subtractions_promptSS;
         Double_t final_weighted_promptSS=numOfwgtpromptSS*lumi(); Int_t final_promptSS=numOfpromptSS;
         Double_t final_weighted_Vgam=numOfwgtVgam*lumi();Int_t final_Vgam=numOfVgam;
         Double_t final_weighted_FFApp_data=numOfwgtFFApp_data;Int_t final_FFApp_data=numOfFFApp_data;
         Double_t final_total_bkg=totalbkg;
         Double_t ErrOfpromptSS=sqrt(errOfwgtpromptSS)*lumi(), ErrOfVgam=sqrt(errOfwgtVgam)*lumi(), ErrOfQmisID=sqrt(errOfwgtQmisID);
         Double_t ErrOffake=sqrt(errOfwgtFFApp_data+errOfwgtFFQmis+errOfwgtFFApp_subtractions_QmisID*lumi()*lumi()+
                                 errOfwgtFFApp_subtractions_promptSS*lumi()*lumi());
         Double_t ErrOfsignal=sqrt(errOfwgtsignal)*lumi();
         Double_t final_total_bkg_err=sqrt(errOfwgtpromptSS+errOfwgtVgam+errOfwgtQmisID+errOfwgtFFApp_data+ErrOffake*ErrOffake);
         Double_t predicted=totalbkg+numOfwgtsignal*lumi();
         Double_t predicted_err=sqrt(errOfwgtpromptSS+errOfwgtVgam+errOfwgtQmisID+errOfwgtFFApp_data+ErrOffake*ErrOffake+ErrOfsignal);
         tmp=sig;
         fixed_cuts[index]=final_cut;
      }
  }
  //if(index==4)fixed_cuts[index]=1500;
  cout<<"---------------------------------------"<<endl;
  cout<<"vars"<<"["<<index<<"]: "<<setw(10)<<fixed_cuts[index]<<endl;
  cout<<"signal: "<<setw(5)<<final_weighted_signal<<"+-"<<ErrOfsignal<<setw(10)<<final_signal<<endl;
  cout<<"promptSS: "<<setw(5)<<final_weighted_promptSS<<"+-"<<ErrOfpromptSS<<setw(10)<<final_promptSS<<endl;
  cout<<"Vgam: "<<setw(5)<<final_weighted_Vgam<<"+-"<<ErrOfVgam<<setw(10)<<final_Vgam<<endl;
  cout<<"QmisID: "<<setw(5)<<final_weighted_QmisID<<"+-"<<ErrOfQmisID<<setw(10)<<final_QmisID<<endl;
  cout<<"Fakes: "<<setw(5)<<numOfwgtFFApp_data-numOfwgtFFApp_subtractions_promptSS*lumi()-numOfwgtFFApp_subtractions_QmisID*lumi()-numOfwgtFFQmis<<"+-"<<ErrOffake<<setw(10)<<final_FFApp_data<<"-"<< final_FFQmis<<"-"<<final_weighted_FFApp_subtractions_QmisID*lumi()<<"-"<<final_weighted_FFApp_subtractions_promptSS*lumi()<<"-"<<final_weighted_FFQmis<<endl;
  cout<<"total bkg: "<<setw(5)<<final_total_bkg<<"+-"<<final_total_bkg_err<<endl;
  cout<<"predicted: "<<setw(5)<<predicted<<"+-"<<predicted_err<<endl;
  cout<<"data: "<<setw(5)<<numOfdata<<endl;
  cout<<"s/sqrt(B): "<<setw(5)<<sig<<endl;
  cout<<"Z0: "<<setw(5)<<sig_Z0<<endl;
  cout<<"log(exp(1)): "<<setw(5)<<log(exp(1))<<endl;
  cout<<"s/B: "<<setw(5)<<sigpur<<endl;
  }
//end of manin func
}
