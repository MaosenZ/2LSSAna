//-------------------------------------------------------------------------------------------
// This script is to define cut-flow of hh->WWWW, using ntuples after hh4Wanalysis.C.
// Also can be used to draw plots
// Author: Maosen Zhou (maosen.zhou@cern.ch)
// Date: 15/July/2016
// --to scan different cuts to define best cuts
//   vars to be used: m_jj_w, m_ljj, mindR_lj, m_ljjljj
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
void sigScan(){

  //Get trees and variables 

  TString vars[]={"pt_leadinglelpton","pt_sublepton","pt_j1","pt_j2","m_ll","m_jj","MET","m_jj_w","m_l1jj","mindR_l1j","mindR_l2j","pt_sum","m_all"};
  Float_t fixed_cuts[7];

  TFile *f_signal=new TFile("output/dataMC_3jets/miniNtuple_nonres.root");
  TFile *f_promptSS=new TFile("output/dataMC_3jets/miniNtuple_promptSS.root");
  TFile *f_Vgam=new TFile("output/dataMC_3jets/miniNtuple_Vgam.root");
  TFile *f_QmisID=new TFile("output/dataMC_3jets/miniNtuple_QmisID_datacombined.root");
  TFile *f_FFApp_data=new TFile("output/dataMC_3jets/miniNtuple_FFApp_datacombined.root");
  TFile *f_FFApp_subtractions=new TFile("output/dataMC_3jets/miniNtuple_FFApp_subtractions.root");
  
  TTree *signal=(TTree*)f_signal->Get("Tree");
  TTree *promptSS=(TTree*)f_promptSS->Get("Tree");
  TTree *Vgam=(TTree*)f_Vgam->Get("Tree");
  TTree *QmisID=(TTree*)f_QmisID->Get("Tree");
  TTree *FFApp_data=(TTree*)f_FFApp_data->Get("Tree");
  TTree *FFApp_subtractions=(TTree*)f_FFApp_subtractions->Get("Tree");

  Float_t signal_pt_sum,promptSS_pt_sum,Vgam_pt_sum,QmisID_pt_sum,FFApp_data_pt_sum,FFApp_subtractions_pt_sum;
  Float_t signal_met,promptSS_met,Vgam_met,QmisID_met,FFApp_data_met,FFApp_subtractions_met;
  Float_t signal_pt_leadinglepton,promptSS_pt_leadinglepton,Vgam_pt_leadinglepton,QmisID_pt_leadinglepton,
          FFApp_data_pt_leadinglepton,FFApp_subtractions_pt_leadinglepton;
  Float_t signal_pt_sublepton,promptSS_pt_sublepton,Vgam_pt_sublepton,QmisID_pt_sublepton,
          FFApp_data_pt_sublepton,FFApp_subtractions_pt_sublepton;
  Float_t signal_pt_j1,promptSS_pt_j1,Vgam_pt_j1,QmisID_pt_j1,FFApp_data_pt_j1,FFApp_subtractions_pt_j1;
  Float_t signal_pt_j2,promptSS_pt_j2,Vgam_pt_j2,QmisID_pt_j2,FFApp_data_pt_j2,FFApp_subtractions_pt_j2;
  Float_t signal_m_ll,promptSS_m_ll,Vgam_m_ll,QmisID_m_ll,FFApp_data_m_ll,FFApp_subtractions_m_ll;
  Float_t signal_m_jj,promptSS_m_jj,Vgam_m_jj,QmisID_m_jj,FFApp_data_m_jj,FFApp_subtractions_m_jj;
  Float_t signal_m_jj_w,promptSS_m_jj_w,Vgam_m_jj_w,QmisID_m_jj_w,FFApp_data_m_jj_w,FFApp_subtractions_m_jj_w;
  Float_t signal_m_l1jj,promptSS_m_l1jj,Vgam_m_l1jj,QmisID_m_l1jj,FFApp_data_m_l1jj,FFApp_subtractions_m_l1jj;
  Float_t signal_m_all,promptSS_m_all,Vgam_m_all,QmisID_m_all,FFApp_data_m_all,FFApp_subtractions_m_all;
  Float_t signal_mindR_l1j,promptSS_mindR_l1j,Vgam_mindR_l1j,QmisID_mindR_l1j,FFApp_data_mindR_l1j,FFApp_subtractions_mindR_l1j;
  Float_t signal_mindR_l2j,promptSS_mindR_l2j,Vgam_mindR_l2j,QmisID_mindR_l2j,FFApp_data_mindR_l2j,FFApp_subtractions_mindR_l2j;
  Double_t signal_weight,promptSS_weight,Vgam_weight,QmisID_weight,FFApp_data_weight,FFApp_subtractions_weight;
  Int_t signal_channel,promptSS_channel,Vgam_channel,QmisID_channel,FFApp_data_channel,FFApp_subtractions_channel;
  Int_t signal_numOfjet,promptSS_numOfjet,Vgam_numOfjet,QmisID_numOfjet,FFApp_data_numOfjet,FFApp_subtractions_numOfjet;

  signal->SetBranchAddress("pt_leadinglepton",&signal_pt_leadinglepton);
  promptSS->SetBranchAddress("pt_leadinglepton",&promptSS_pt_leadinglepton);
  Vgam->SetBranchAddress("pt_leadinglepton",&Vgam_pt_leadinglepton);
  QmisID->SetBranchAddress("pt_leadinglepton",&QmisID_pt_leadinglepton);
  FFApp_data->SetBranchAddress("pt_leadinglepton",&FFApp_data_pt_leadinglepton);
  FFApp_subtractions->SetBranchAddress("pt_leadinglepton",&FFApp_subtractions_pt_leadinglepton);

  signal->SetBranchAddress("pt_sublepton",&signal_pt_sublepton);
  promptSS->SetBranchAddress("pt_sublepton",&promptSS_pt_sublepton);
  Vgam->SetBranchAddress("pt_sublepton",&Vgam_pt_sublepton);
  QmisID->SetBranchAddress("pt_sublepton",&QmisID_pt_sublepton);
  FFApp_data->SetBranchAddress("pt_sublepton",&FFApp_data_pt_sublepton);
  FFApp_subtractions->SetBranchAddress("pt_sublepton",&FFApp_subtractions_pt_sublepton);

  signal->SetBranchAddress("pt_j1",&signal_pt_j1);
  promptSS->SetBranchAddress("pt_j1",&promptSS_pt_j1);
  Vgam->SetBranchAddress("pt_j1",&Vgam_pt_j1);
  QmisID->SetBranchAddress("pt_j1",&QmisID_pt_j1);
  FFApp_data->SetBranchAddress("pt_j1",&FFApp_data_pt_j1);
  FFApp_subtractions->SetBranchAddress("pt_j1",&FFApp_subtractions_pt_j1);

  signal->SetBranchAddress("pt_j2",&signal_pt_j2);
  promptSS->SetBranchAddress("pt_j2",&promptSS_pt_j2);
  Vgam->SetBranchAddress("pt_j2",&Vgam_pt_j2);
  QmisID->SetBranchAddress("pt_j2",&QmisID_pt_j2);
  FFApp_data->SetBranchAddress("pt_j2",&FFApp_data_pt_j2);
  FFApp_subtractions->SetBranchAddress("pt_j2",&FFApp_subtractions_pt_j2);

  signal->SetBranchAddress("MET",&signal_met);
  promptSS->SetBranchAddress("MET",&promptSS_met);
  Vgam->SetBranchAddress("MET",&Vgam_met);
  QmisID->SetBranchAddress("MET",&QmisID_met);
  FFApp_data->SetBranchAddress("MET",&FFApp_data_met);
  FFApp_subtractions->SetBranchAddress("MET",&FFApp_subtractions_met);

  signal->SetBranchAddress("m_ll",&signal_m_ll);
  promptSS->SetBranchAddress("m_ll",&promptSS_m_ll);
  Vgam->SetBranchAddress("m_ll",&Vgam_m_ll);
  QmisID->SetBranchAddress("m_ll",&QmisID_m_ll);
  FFApp_data->SetBranchAddress("m_ll",&FFApp_data_m_ll);
  FFApp_subtractions->SetBranchAddress("m_ll",&FFApp_subtractions_m_ll);

  signal->SetBranchAddress("m_jj_w",&signal_m_jj_w);
  promptSS->SetBranchAddress("m_jj_w",&promptSS_m_jj_w);
  Vgam->SetBranchAddress("m_jj_w",&Vgam_m_jj_w);
  QmisID->SetBranchAddress("m_jj_w",&QmisID_m_jj_w);
  FFApp_data->SetBranchAddress("m_jj_w",&FFApp_data_m_jj_w);
  FFApp_subtractions->SetBranchAddress("m_jj_w",&FFApp_subtractions_m_jj_w);

  signal->SetBranchAddress("m_jj",&signal_m_jj);
  promptSS->SetBranchAddress("m_jj",&promptSS_m_jj);
  Vgam->SetBranchAddress("m_jj",&Vgam_m_jj);
  QmisID->SetBranchAddress("m_jj",&QmisID_m_jj);
  FFApp_data->SetBranchAddress("m_jj",&FFApp_data_m_jj);
  FFApp_subtractions->SetBranchAddress("m_jj",&FFApp_subtractions_m_jj);

  signal->SetBranchAddress("m_l1jj",&signal_m_l1jj);
  promptSS->SetBranchAddress("m_l1jj",&promptSS_m_l1jj);
  Vgam->SetBranchAddress("m_l1jj",&Vgam_m_l1jj);
  QmisID->SetBranchAddress("m_l1jj",&QmisID_m_l1jj);
  FFApp_data->SetBranchAddress("m_l1jj",&FFApp_data_m_l1jj);
  FFApp_subtractions->SetBranchAddress("m_l1jj",&FFApp_subtractions_m_l1jj);

  signal->SetBranchAddress("m_all",&signal_m_all);
  promptSS->SetBranchAddress("m_all",&promptSS_m_all);
  Vgam->SetBranchAddress("m_all",&Vgam_m_all);
  QmisID->SetBranchAddress("m_all",&QmisID_m_all);
  FFApp_data->SetBranchAddress("m_all",&FFApp_data_m_all);
  FFApp_subtractions->SetBranchAddress("m_all",&FFApp_subtractions_m_all);

  signal->SetBranchAddress("pt_sum",&signal_pt_sum);
  promptSS->SetBranchAddress("pt_sum",&promptSS_pt_sum);
  Vgam->SetBranchAddress("pt_sum",&Vgam_pt_sum);
  QmisID->SetBranchAddress("pt_sum",&QmisID_pt_sum);
  FFApp_data->SetBranchAddress("pt_sum",&FFApp_data_pt_sum);
  FFApp_subtractions->SetBranchAddress("pt_sum",&FFApp_subtractions_pt_sum);

  signal->SetBranchAddress("mindR_l1j",&signal_mindR_l1j);
  promptSS->SetBranchAddress("mindR_l1j",&promptSS_mindR_l1j);
  Vgam->SetBranchAddress("mindR_l1j",&Vgam_mindR_l1j);
  QmisID->SetBranchAddress("mindR_l1j",&QmisID_mindR_l1j);
  FFApp_data->SetBranchAddress("mindR_l1j",&FFApp_data_mindR_l1j);
  FFApp_subtractions->SetBranchAddress("mindR_l1j",&FFApp_subtractions_mindR_l1j);

  signal->SetBranchAddress("mindR_l2j",&signal_mindR_l2j);
  promptSS->SetBranchAddress("mindR_l2j",&promptSS_mindR_l2j);
  Vgam->SetBranchAddress("mindR_l2j",&Vgam_mindR_l2j);
  QmisID->SetBranchAddress("mindR_l2j",&QmisID_mindR_l2j);
  FFApp_data->SetBranchAddress("mindR_l2j",&FFApp_data_mindR_l2j);
  FFApp_subtractions->SetBranchAddress("mindR_l2j",&FFApp_subtractions_mindR_l2j);

  signal->SetBranchAddress("weight",&signal_weight);
  promptSS->SetBranchAddress("weight",&promptSS_weight);
  Vgam->SetBranchAddress("weight",&Vgam_weight);
  QmisID->SetBranchAddress("weight",&QmisID_weight);
  FFApp_data->SetBranchAddress("weight",&FFApp_data_weight);
  FFApp_subtractions->SetBranchAddress("weight",&FFApp_subtractions_weight);

  signal->SetBranchAddress("channel",&signal_channel);
  promptSS->SetBranchAddress("channel",&promptSS_channel);
  Vgam->SetBranchAddress("channel",&Vgam_channel);
  QmisID->SetBranchAddress("channel",&QmisID_channel);
  FFApp_data->SetBranchAddress("channel",&FFApp_data_channel);
  FFApp_subtractions->SetBranchAddress("channel",&FFApp_subtractions_channel);

  signal->SetBranchAddress("numOfjet",&signal_numOfjet);
  promptSS->SetBranchAddress("numOfjet",&promptSS_numOfjet);
  Vgam->SetBranchAddress("numOfjet",&Vgam_numOfjet);
  QmisID->SetBranchAddress("numOfjet",&QmisID_numOfjet);
  FFApp_data->SetBranchAddress("numOfjet",&FFApp_data_numOfjet);
  FFApp_subtractions->SetBranchAddress("numOfjet",&FFApp_subtractions_numOfjet);
  //bool m_jj_w_isUsed=false, m_jj_w_isUsed=false,m_l1jj_isUsed=false,m_l2jj_isUsed=false,
  //     m_ljjljj_isUsed=false,mindR_l1j_isUsed=false,mindR_l2j_isUsed=false;
  Int_t Nbins=40, xmin=0, xmax=200;
  TH1F *frame=new TH1F("frame","",Nbins,xmin,xmax);
  TH1F *hist_signal=new TH1F("hist_signal","",Nbins,xmin,xmax);
  TH1F *hist_promptSS=new TH1F("hist_promptSS","",Nbins,xmin,xmax);
  TH1F *hist_Vgam=new TH1F("hist_Vgam","",Nbins,xmin,xmax);
  TH1F *hist_QmisID=new TH1F("hist_QmisID","",Nbins,xmin,xmax);
  TH1F *hist_fake=new TH1F("hist_fake","",Nbins,xmin,xmax);
   
  float tmp=0;
  for(Int_t index=0;index<7;index++){
      fixed_cuts[0]=20; fixed_cuts[1]=25; fixed_cuts[2]=0;fixed_cuts[3]=9999;fixed_cuts[4]=0;fixed_cuts[5]=10;fixed_cuts[6]=10;
  for(Int_t i=0;i<=30;i++){
      Int_t numOfsignal=0,numOfpromptSS=0, numOfVgam=0, numOfVgam=0,numOfQmisID=0,numOfFFApp_subtractions=0,numOfFFApp_data=0;
      Double_t numOfwgtsignal=0,numOfwgtpromptSS=0, numOfwgtVgam=0, numOfwgtVgam=0,numOfwgtQmisID=0,
               numOfwgtFFApp_subtractions=0,numOfwgtFFApp_data;
      Double_t errsquareOfwgtsignal=0,errsquareOfwgtpromptSS=0, errsquareOfwgtVgam=0, errsquareOfwgtVgam=0,errsquareOfwgtQmisID=0,
               errsquareOfwgtFFApp_subtractions=0, errsquareOfwgtFFApp_data=0;
      if(index==0) Float_t cut=20+5*i;
      if(index==1) Float_t cut=25+5*i;
      if(index==2) Float_t cut=5*i;
      if(index==3) Float_t cut=50+5*i;
      if(index==4) Float_t cut=20+5*i;
      if(index==5 || index==6) Float_t cut=0.3+i*0.1;
      for(Long64_t entry=0; entry<signal->GetEntries();entry++) {
          signal->GetEntry(entry);
          if(signal_channel!=1)continue;
          if(signal_numOfjet<3)continue;
          if(index==0 && signal_pt_sublepton>cut){
             numOfsignal++;
             numOfwgtsignal+=signal_weight; errsquareOfwgtsignal+=signal_weight*signal_weight;
          }
          if(index==1 && signal_pt_sublepton>fixed_cuts[0] && signal_pt_j2>cut&&signal_m_jj_w<cut){
             numOfsignal++;
             numOfwgtsignal+=signal_weight; errsquareOfwgtsignal+=signal_weight*signal_weight;
          }
          if(index==2 && signal_pt_sublepton>fixed_cuts[0]&&signal_pt_j2>fixed_cuts[1]&&fabs(signal_m_ll-91.2)>cut){
             numOfsignal++;
             numOfwgtsignal+=signal_weight; errsquareOfwgtsignal+=signal_weight*signal_weight;
          }
          if(index==3 && signal_pt_sublepton>fixed_cuts[0]&&signal_pt_j2>fixed_cuts[1]&&fabs(signal_m_ll-91.2)>fixed_cuts[2]&&
             signal_m_l1jj<cut){
             numOfsignal++;
             numOfwgtsignal+=signal_weight; errsquareOfwgtsignal+=signal_weight*signal_weight;
          }
          if(index==4 && signal_pt_sublepton>fixed_cuts[0]&&signal_pt_j2>fixed_cuts[1]&&fabs(signal_m_ll-91.2)>fixed_cuts[2]&&
             signal_m_l1jj<fixed_cuts[3] && signal_pt_sum>cut){
             numOfsignal++;
             numOfwgtsignal+=signal_weight; errsquareOfwgtsignal+=signal_weight*signal_weight;
          }
          if(index==5 && signal_pt_sublepton>fixed_cuts[0]&&signal_pt_j2>fixed_cuts[1]&&fabs(signal_m_ll-91.2)>fixed_cuts[2]&&
             signal_m_l1jj<fixed_cuts[3] && signal_pt_sum>fixed_cuts[4]&&signal_mindR_l1j<cut){
             numOfsignal++;
             numOfwgtsignal+=signal_weight; errsquareOfwgtsignal+=signal_weight*signal_weight;
          } 
          if(index==6 && signal_pt_sublepton>fixed_cuts[0]&&signal_pt_j2>fixed_cuts[1]&&fabs(signal_m_ll-91.2)>fixed_cuts[2]&&
             signal_m_l1jj<fixed_cuts[3] && signal_pt_sum>fixed_cuts[4]&&signal_mindR_l1j<fixed_cuts[5]&&signal_mindR_l2j<cut){
             numOfsignal++;
             numOfwgtsignal+=signal_weight; errsquareOfwgtsignal+=signal_weight*signal_weight;
          }
      }
      for(Long64_t entry=0; entry<promptSS->GetEntries();entry++) {
          promptSS->GetEntry(entry);
          if(promptSS_channel!=1)continue;
          if(promptSS_numOfjet<3)continue;
          if(index==0 && promptSS_pt_sublepton>cut){
             numOfpromptSS++;
             numOfwgtpromptSS+=promptSS_weight; errsquareOfwgtpromptSS+=promptSS_weight*promptSS_weight;
          }
          if(index==1 && promptSS_pt_sublepton>fixed_cuts[0] && promptSS_pt_j2>cut&&promptSS_m_jj_w<cut){
             numOfpromptSS++;
             numOfwgtpromptSS+=promptSS_weight; errsquareOfwgtpromptSS+=promptSS_weight*promptSS_weight;
          }
          if(index==2 && promptSS_pt_sublepton>fixed_cuts[0]&&promptSS_pt_j2>fixed_cuts[1]&&fabs(promptSS_m_ll-91.2)>cut){
             numOfpromptSS++;
             numOfwgtpromptSS+=promptSS_weight; errsquareOfwgtpromptSS+=promptSS_weight*promptSS_weight;
          }
          if(index==3 && promptSS_pt_sublepton>fixed_cuts[0]&&promptSS_pt_j2>fixed_cuts[1]&&fabs(promptSS_m_ll-91.2)>fixed_cuts[2]&&
             promptSS_m_l1jj<cut){
             numOfwgtpromptSS++;
             numOfpromptSS+=promptSS_weight; errsquareOfwgtpromptSS+=promptSS_weight*promptSS_weight;
          }
          if(index==4 && promptSS_pt_sublepton>fixed_cuts[0]&&promptSS_pt_j2>fixed_cuts[1]&&fabs(promptSS_m_ll-91.2)>fixed_cuts[2]&&
             promptSS_m_l1jj<fixed_cuts[3] && promptSS_pt_sum>cut){
             numOfpromptSS++;
             numOfwgtpromptSS+=promptSS_weight; errsquareOfwgtpromptSS+=promptSS_weight*promptSS_weight;
          }
          if(index==5 && promptSS_pt_sublepton>fixed_cuts[0]&&promptSS_pt_j2>fixed_cuts[1]&&fabs(promptSS_m_ll-91.2)>fixed_cuts[2]&&
             promptSS_m_l1jj<fixed_cuts[3] && promptSS_pt_sum>fixed_cuts[4]&&promptSS_mindR_l1j<cut){
             numOfpromptSS++;
             numOfwgtpromptSS+=promptSS_weight; errsquareOfwgtpromptSS+=promptSS_weight*promptSS_weight;
          }
          if(index==6 && promptSS_pt_sublepton>fixed_cuts[0]&&promptSS_pt_j2>fixed_cuts[1]&&fabs(promptSS_m_ll-91.2)>fixed_cuts[2]&&
             promptSS_m_l1jj<fixed_cuts[3] && promptSS_pt_sum>fixed_cuts[4]&&promptSS_mindR_l1j<fixed_cuts[5]&&promptSS_mindR_l2j<cut){
             numOfpromptSS++;
             numOfwgtpromptSS+=promptSS_weight; errsquareOfwgtpromptSS+=promptSS_weight*promptSS_weight;
          }
      }
      for(Long64_t entry=0; entry<Vgam->GetEntries();entry++) {
          Vgam->GetEntry(entry);
          if(Vgam_channel!=1)continue;
          if(Vgam_numOfjet<3)continue;
          if(index==0 && Vgam_pt_sublepton>cut){
             numOfVgam++;
             numOfwgtVgam+=Vgam_weight; errsquareOfwgtVgam+=Vgam_weight*Vgam_weight;
          }
          if(index==1 && Vgam_pt_sublepton>fixed_cuts[0] && Vgam_pt_j2>cut&&Vgam_m_jj_w<cut){
             numOfVgam++;
             numOfwgtVgam+=Vgam_weight; errsquareOfwgtVgam+=Vgam_weight*Vgam_weight;
          }
          if(index==2 && Vgam_pt_sublepton>fixed_cuts[0]&&Vgam_pt_j2>fixed_cuts[1]&&fabs(Vgam_m_ll-91.2)>cut){
             numOfVgam++;
             numOfwgtVgam+=Vgam_weight; errsquareOfwgtVgam+=Vgam_weight*Vgam_weight;
          }
          if(index==3 && Vgam_pt_sublepton>fixed_cuts[0]&&Vgam_pt_j2>fixed_cuts[1]&&fabs(Vgam_m_ll-91.2)>fixed_cuts[2]&&
             Vgam_m_l1jj<cut){
             numOfVgam++;
             numOfwgtVgam+=Vgam_weight; errsquareOfwgtVgam+=Vgam_weight*Vgam_weight;
          }
          if(index==4 && Vgam_pt_sublepton>fixed_cuts[0]&&Vgam_pt_j2>fixed_cuts[1]&&fabs(Vgam_m_ll-91.2)>fixed_cuts[2]&&
             Vgam_m_l1jj<fixed_cuts[3] && Vgam_pt_sum>cut){
             numOfVgam++;
             numOfwgtVgam+=Vgam_weight; errsquareOfwgtVgam+=Vgam_weight*Vgam_weight;
          }
          if(index==5 && Vgam_pt_sublepton>fixed_cuts[0]&&Vgam_pt_j2>fixed_cuts[1]&&fabs(Vgam_m_ll-91.2)>fixed_cuts[2]&&
             Vgam_m_l1jj<fixed_cuts[3] && Vgam_pt_sum>fixed_cuts[4]&&Vgam_mindR_l1j<cut){
             numOfVgam++;
             numOfwgtVgam+=Vgam_weight; errsquareOfwgtVgam+=Vgam_weight*Vgam_weight;
          }
          if(index==6 && Vgam_pt_sublepton>fixed_cuts[0]&&Vgam_pt_j2>fixed_cuts[1]&&fabs(Vgam_m_ll-91.2)>fixed_cuts[2]&&
             Vgam_m_l1jj<fixed_cuts[3] && Vgam_pt_sum>fixed_cuts[4]&&Vgam_mindR_l1j<fixed_cuts[5]&&Vgam_mindR_l2j<cut){
             numOfVgam++;
             numOfwgtVgam+=Vgam_weight; errsquareOfwgtVgam+=Vgam_weight*Vgam_weight;
          }
      }
      for(Long64_t entry=0; entry<QmisID->GetEntries();entry++) {
          QmisID->GetEntry(entry);
          if(QmisID_channel!=1)continue;
          if(QmisID_numOfjet<3)continue;
          if(index==0 && QmisID_pt_sublepton>cut){
             numOfQmisID++;
             numOfwgtQmisID+=QmisID_weight; errsquareOfwgtQmisID+=QmisID_weight*QmisID_weight;
          }
          if(index==1 && QmisID_pt_sublepton>fixed_cuts[0] && QmisID_pt_j2>cut&&QmisID_m_jj_w<cut){
             numOfQmisID++;
             numOfwgtQmisID+=QmisID_weight; errsquareOfwgtQmisID+=QmisID_weight*QmisID_weight;
          }
          if(index==2 && QmisID_pt_sublepton>fixed_cuts[0]&&QmisID_pt_j2>fixed_cuts[1]&&fabs(QmisID_m_ll-91.2)>cut){
             numOfQmisID++;
             numOfwgtQmisID+=QmisID_weight; errsquareOfwgtQmisID+=QmisID_weight*QmisID_weight;
          }
          if(index==3 && QmisID_pt_sublepton>fixed_cuts[0]&&QmisID_pt_j2>fixed_cuts[1]&&fabs(QmisID_m_ll-91.2)>fixed_cuts[2]&&
             QmisID_m_l1jj<cut){
             numOfQmisID++;
             numOfwgtQmisID+=QmisID_weight; errsquareOfwgtQmisID+=QmisID_weight*QmisID_weight;
          }
          if(index==4 && QmisID_pt_sublepton>fixed_cuts[0]&&QmisID_pt_j2>fixed_cuts[1]&&fabs(QmisID_m_ll-91.2)>fixed_cuts[2]&&
             QmisID_m_l1jj<fixed_cuts[3] && QmisID_pt_sum>cut){
             numOfQmisID++;
             numOfwgtQmisID+=QmisID_weight; errsquareOfwgtQmisID+=QmisID_weight*QmisID_weight;
          }
          if(index==5 && QmisID_pt_sublepton>fixed_cuts[0]&&QmisID_pt_j2>fixed_cuts[1]&&fabs(QmisID_m_ll-91.2)>fixed_cuts[2]&&
             QmisID_m_l1jj<fixed_cuts[3] && QmisID_pt_sum>fixed_cuts[4]&&QmisID_mindR_l1j<cut){
             numOfQmisID++;
             numOfwgtQmisID+=QmisID_weight; errsquareOfwgtQmisID+=QmisID_weight*QmisID_weight;
          }
          if(index==6 && QmisID_pt_sublepton>fixed_cuts[0]&&QmisID_pt_j2>fixed_cuts[1]&&fabs(QmisID_m_ll-91.2)>fixed_cuts[2]&&
             QmisID_m_l1jj<fixed_cuts[3] && QmisID_pt_sum>fixed_cuts[4]&&QmisID_mindR_l1j<fixed_cuts[5]&&QmisID_mindR_l2j<cut){
             numOfQmisID++;
             numOfwgtQmisID+=QmisID_weight; errsquareOfwgtQmisID+=QmisID_weight*QmisID_weight;
          }
      }
      for(Long64_t entry=0; entry<FFApp_data->GetEntries();entry++) {
          FFApp_data->GetEntry(entry);
          if(FFApp_data_channel!=1)continue;
          if(FFApp_data_numOfjet<3)continue;
          if(index==0 && FFApp_data_pt_sublepton>cut){
             numOfFFApp_data++;
             numOfwgtFFApp_data+=FFApp_data_weight; errsquareOfwgtFFApp_data+=FFApp_data_weight*FFApp_data_weight;
          }
          if(index==1 && FFApp_data_pt_sublepton>fixed_cuts[0] && FFApp_data_pt_j2>cut&&FFApp_data_m_jj_w<cut){
             numOfFFApp_data++;
             numOfwgtFFApp_data+=FFApp_data_weight; errsquareOfwgtFFApp_data+=FFApp_data_weight*FFApp_data_weight;
          }
          if(index==2 && FFApp_data_pt_sublepton>fixed_cuts[0]&&FFApp_data_pt_j2>fixed_cuts[1]&&fabs(FFApp_data_m_ll-91.2)>cut){
             numOfFFApp_data++;
             numOfwgtFFApp_data+=FFApp_data_weight; errsquareOfwgtFFApp_data+=FFApp_data_weight*FFApp_data_weight;
          }
          if(index==3 && FFApp_data_pt_sublepton>fixed_cuts[0]&&FFApp_data_pt_j2>fixed_cuts[1]&&fabs(FFApp_data_m_ll-91.2)>fixed_cuts[2]&&
             FFApp_data_m_l1jj<cut){
             numOfFFApp_data++;
             numOfwgtFFApp_data+=FFApp_data_weight; errsquareOfwgtFFApp_data+=FFApp_data_weight*FFApp_data_weight;
          }
          if(index==4 && FFApp_data_pt_sublepton>fixed_cuts[0]&&FFApp_data_pt_j2>fixed_cuts[1]&&fabs(FFApp_data_m_ll-91.2)>fixed_cuts[2]&&
             FFApp_data_m_l1jj<fixed_cuts[3] && FFApp_data_pt_sum>cut){
             numOfFFApp_data++;
             numOfwgtFFApp_data+=FFApp_data_weight; errsquareOfwgtFFApp_data+=FFApp_data_weight*FFApp_data_weight;
          }
          if(index==5 && FFApp_data_pt_sublepton>fixed_cuts[0]&&FFApp_data_pt_j2>fixed_cuts[1]&&fabs(FFApp_data_m_ll-91.2)>fixed_cuts[2]&&
             FFApp_data_m_l1jj<fixed_cuts[3] && FFApp_data_pt_sum>fixed_cuts[4]&&FFApp_data_mindR_l1j<cut){
             numOfFFApp_data++;
             numOfwgtFFApp_data+=FFApp_data_weight; errsquareOfwgtFFApp_data+=FFApp_data_weight*FFApp_data_weight;
          }
          if(index==6 && FFApp_data_pt_sublepton>fixed_cuts[0]&&FFApp_data_pt_j2>fixed_cuts[1]&&fabs(FFApp_data_m_ll-91.2)>fixed_cuts[2]&&
             FFApp_data_m_l1jj<fixed_cuts[3] && FFApp_data_pt_sum>fixed_cuts[4]&&FFApp_data_mindR_l1j<fixed_cuts[5]&&FFApp_data_mindR_l2j<cut){
             numOfFFApp_data++;
             numOfwgtFFApp_data+=FFApp_data_weight; errsquareOfwgtFFApp_data+=FFApp_data_weight*FFApp_data_weight;
          }
      }
      for(Long64_t entry=0; entry<FFApp_subtractions->GetEntries();entry++) {
          FFApp_subtractions->GetEntry(entry);
          if(FFApp_subtractions_channel!=1)continue;
          if(FFApp_subtractions_numOfjet<3)continue;
          if(index==0 && FFApp_subtractions_pt_sublepton>cut){
             numOfFFApp_subtractions++;
             numOfwgtFFApp_subtractions+=FFApp_subtractions_weight; errsquareOfwgtFFApp_subtractions+=FFApp_subtractions_weight*FFApp_subtractions_weight;
          }
          if(index==1 && FFApp_subtractions_pt_sublepton>fixed_cuts[0] && FFApp_subtractions_pt_j2>cut&&FFApp_subtractions_m_jj_w<cut){
             numOfFFApp_subtractions++;
             numOfwgtFFApp_subtractions+=FFApp_subtractions_weight;errsquareOfwgtFFApp_subtractions+=FFApp_subtractions_weight*FFApp_subtractions_weight;
          }
          if(index==2 && FFApp_subtractions_pt_sublepton>fixed_cuts[0]&&FFApp_subtractions_pt_j2>fixed_cuts[1]&&fabs(FFApp_subtractions_m_ll-91.2)>cut){
             numOfFFApp_subtractions++;
             numOfwgtFFApp_subtractions+=FFApp_subtractions_weight;errsquareOfwgtFFApp_subtractions+=FFApp_subtractions_weight*FFApp_subtractions_weight;
          }
          if(index==3 && FFApp_subtractions_pt_sublepton>fixed_cuts[0]&&FFApp_subtractions_pt_j2>fixed_cuts[1]&&fabs(FFApp_subtractions_m_ll-91.2)>fixed_cuts[2]&&
             FFApp_subtractions_m_l1jj<cut){
             numOfFFApp_subtractions++;
             numOfwgtFFApp_subtractions+=FFApp_subtractions_weight;errsquareOfwgtFFApp_subtractions+=FFApp_subtractions_weight*FFApp_subtractions_weight;
          }
          if(index==4 && FFApp_subtractions_pt_sublepton>fixed_cuts[0]&&FFApp_subtractions_pt_j2>fixed_cuts[1]&&fabs(FFApp_subtractions_m_ll-91.2)>fixed_cuts[2]&&
             FFApp_subtractions_m_l1jj<fixed_cuts[3] && FFApp_subtractions_pt_sum>cut){
             numOfFFApp_subtractions++;
             numOfwgtFFApp_subtractions+=FFApp_subtractions_weight;errsquareOfwgtFFApp_subtractions+=FFApp_subtractions_weight*FFApp_subtractions_weight;
          }
          if(index==5 && FFApp_subtractions_pt_sublepton>fixed_cuts[0]&&FFApp_subtractions_pt_j2>fixed_cuts[1]&&fabs(FFApp_subtractions_m_ll-91.2)>fixed_cuts[2]&&
             FFApp_subtractions_m_l1jj<fixed_cuts[3] && FFApp_subtractions_pt_sum>fixed_cuts[4]&&FFApp_subtractions_mindR_l1j<cut){
             numOfFFApp_subtractions++;
             numOfwgtFFApp_subtractions+=FFApp_subtractions_weight;errsquareOfwgtFFApp_subtractions+=FFApp_subtractions_weight*FFApp_subtractions_weight;
          }
          if(index==6 && FFApp_subtractions_pt_sublepton>fixed_cuts[0]&&FFApp_subtractions_pt_j2>fixed_cuts[1]&&fabs(FFApp_subtractions_m_ll-91.2)>fixed_cuts[2]&&
             FFApp_subtractions_m_l1jj<fixed_cuts[3] && FFApp_subtractions_pt_sum>fixed_cuts[4]&&FFApp_subtractions_mindR_l1j<fixed_cuts[5]&&FFApp_subtractions_mindR_l2j<cut){
             numOfFFApp_subtractions++;
             numOfwgtFFApp_subtractions+=FFApp_subtractions_weight;errsquareOfwgtFFApp_subtractions+=FFApp_subtractions_weight*FFApp_subtractions_weight;
          }
      }
 
      Double_t totalbkg=-numOfwgtFFApp_subtractions*lumi()+numOfwgtFFApp_data+numOfwgtQmisID+numOfwgtpromptSS*lumi()+numOfwgtVgam*lumi();
      Double_t tmpsig=numOfwgtsignal*lumi()/sqrt(totalbkg);
      if(tmpsig>tmp){
         Double_t sig=tmpsig;
         Double_t final_cut=cut; 
         Double_t final_weighted_signal=numOfwgtsignal*lumi(),errOfwgtsignal=sqrt(errsquareOfwgtsignal);Int_t final_signal=numOfsignal;
         Double_t final_weighted_QmisID=numOfwgtQmisID, errOfwgtQmisID=sqrt(errsquareOfwgtQmisID);Int_t final_QmisID=numOfQmisID;
         Double_t final_weighted_FFApp_subtractions=numOfwgtFFApp_subtractions*lumi(); Int_t final_FFApp_subtractions=numOfFFApp_subtractions;
         Double_t final_weighted_promptSS=numOfwgtpromptSS*lumi(),errOfwgtpromptSS=sqrt(errsquareOfwgtpromptSS); Int_t final_promptSS=numOfpromptSS;
         Double_t final_weighted_Vgam=numOfwgtVgam*lumi(),errOfwgtVgam=sqrt(errsquareOfwgtVgam);Int_t final_Vgam=numOfVgam;
         Double_t final_weighted_FFApp_data=numOfwgtFFApp_data;Int_t final_FFApp_data=numOfFFApp_data;
         Double_t errOffake=sqrt(errsquareOfwgtFFApp_subtractions*lumi()*lumi()+errsquareOfwgtFFApp_data);
         tmp=sig;
         fixed_cuts[index]=final_cut;
      }
  }
  
  //if(index==4)fixed_cuts[index]=1500;
  cout<<"---------------------------------------"<<endl;
  cout<<"vars"<<"["<<index<<"]: "<<setw(10)<<fixed_cuts[index]<<endl;
  cout<<"signal: "<<setw(5)<<final_weighted_signal<<"+-"<<errOfwgtsignal*lumi()<<setw(10)<<final_signal<<endl;
  cout<<"promptSS: "<<setw(5)<<final_weighted_promptSS<<"+-"<<errOfwgtpromptSS*lumi()<<setw(10)<<final_promptSS<<endl;
  cout<<"Vgam: "<<setw(5)<<final_weighted_Vgam<<"+-"<<errOfwgtVgam*lumi()<<setw(10)<<final_Vgam<<endl;
  cout<<"QmisID: "<<setw(5)<<final_weighted_QmisID<<"+-"<<errOfwgtQmisID<<setw(10)<<final_QmisID<<endl;
  cout<<"Fakes: "<<setw(5)<<final_weighted_FFApp_data-final_weighted_FFApp_subtractions<<"+-"<<errOffake<<setw(10)<<final_FFApp_data<<"-"<<
                  final_FFApp_subtractions<<endl;
  cout<<"s/sqrt(B): "<<setw(5)<<sig<<endl;
  }
//end of manin func
}
