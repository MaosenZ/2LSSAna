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
#include <fstream>
#include <sstream>
#include "TString.h"
#include <vector>
#include "lumi.cxx"
#include <iomanip>
#include "TMath.h"
using namespace std;
using namespace TMath;
Float_t sigScan_HSS(TString masspoint, Int_t input_channel,Float_t fixed_cuts_min[],Float_t fixed_cuts_max[]){
  //high mass
  Float_t ff_ele=0.4790, ff_mu=0.4221, sys_ele=0.2906, sys_mu=0.2731;
                           //dR_l2j dR_l1j m_ll m_l1jj
  //set initial values 

  TFile *f_signal;
  if(masspoint=="H340_S135")f_signal=new TFile("output/dataMC_3jets/miniNtuple_H340_S135.root");
  if(masspoint=="H340_S145")f_signal=new TFile("output/dataMC_3jets/miniNtuple_H340_S145.root");
  if(masspoint=="H340_S155")f_signal=new TFile("output/dataMC_3jets/miniNtuple_H340_S155.root");
  if(masspoint=="H340_S165")f_signal=new TFile("output/dataMC_3jets/miniNtuple_H340_S165.root");

  if(masspoint=="H280_S135")f_signal=new TFile("output/dataMC_2jets/miniNtuple_H280_S135.root");
  if(masspoint=="H300_S135")f_signal=new TFile("output/dataMC_2jets/miniNtuple_H300_S135.root");
  if(masspoint=="H320_S135")f_signal=new TFile("output/dataMC_2jets/miniNtuple_H320_S135.root");

  TFile *f_totalbkg=new TFile("output/dataMC_3jets/miniNtuple_totalbkg.root");

   TTree *signal=(TTree*)f_signal->Get("Tree");
  TTree *totalbkg=(TTree*)f_totalbkg->Get("Tree");
  Float_t signal_met,totalbkg_met,data_met;
  Float_t signal_m_ll,totalbkg_m_ll,data_m_ll;
  Float_t signal_m_l1jj,totalbkg_m_l1jj,data_m_l1jj;
  Float_t signal_m_all,totalbkg_m_all,data_m_all;
  Float_t signal_mindR_l1j,totalbkg_mindR_l1j,data_mindR_l1j;
  Float_t signal_mindR_l2j,totalbkg_mindR_l2j,data_mindR_l2j;
  Double_t signal_weight,totalbkg_weight,data_weight;
  Int_t signal_channel,totalbkg_channel,data_channel;
  Int_t signal_category,totalbkg_category,data_category;
  Int_t signal_numOfjet,totalbkg_numOfjet,data_numOfjet;
  TString *signal_component=0, *data_component=0, *totalbkg_component=0;

  signal->SetBranchAddress("MET",&signal_met);
  totalbkg->SetBranchAddress("MET",&totalbkg_met);

  signal->SetBranchAddress("m_ll",&signal_m_ll);
  totalbkg->SetBranchAddress("m_ll",&totalbkg_m_ll);

  signal->SetBranchAddress("m_l1jj",&signal_m_l1jj);
  totalbkg->SetBranchAddress("m_l1jj",&totalbkg_m_l1jj);

  signal->SetBranchAddress("m_all",&signal_m_all);
  totalbkg->SetBranchAddress("m_all",&totalbkg_m_all);

  signal->SetBranchAddress("mindR_l1j",&signal_mindR_l1j);
  totalbkg->SetBranchAddress("mindR_l1j",&totalbkg_mindR_l1j);

  signal->SetBranchAddress("mindR_l2j",&signal_mindR_l2j);
  totalbkg->SetBranchAddress("mindR_l2j",&totalbkg_mindR_l2j);

  signal->SetBranchAddress("weight",&signal_weight);
  totalbkg->SetBranchAddress("weight",&totalbkg_weight);

  signal->SetBranchAddress("channel",&signal_channel);
  totalbkg->SetBranchAddress("channel",&totalbkg_channel);

  signal->SetBranchAddress("category",&signal_category);
  totalbkg->SetBranchAddress("category",&totalbkg_category);

  signal->SetBranchAddress("numOfjet",&signal_numOfjet);
  totalbkg->SetBranchAddress("numOfjet",&totalbkg_numOfjet);

  signal->SetBranchAddress("component",&signal_component);
  totalbkg->SetBranchAddress("component",&totalbkg_component);

  Int_t numOfdata[4]={0},numOfsignal[4]={0},numOfpromptSS[4]={0},  numOfVgam[4]={0},numOfQmisID[4]={0}, numOffake[4]={0},numOftotalbkg[4]={0};
  Double_t numOfwgtdata[4]={0},numOfwgtsignal[4]={0},numOfwgtpromptSS[4]={0},  numOfwgtVgam[4]={0},numOfwgtQmisID[4]={0}, numOfwgtfake[4]={0},
           numOfwgttotalbkg[4]={0};
  Double_t Err2Ofwgtdata[4]={0},Err2Ofwgtsignal[4]={0},Err2OfwgtpromptSS[4]={0},  Err2OfwgtVgam[4]={0},Err2OfwgtQmisID[4]={0};
  Double_t sigs[4]={0}, sigpurs[4]={0},numOfwgteantimu[4]={0},numOfwgtantiemu[4]={0};
  Double_t wgtdata[4],wgtpromptSS[4],wgtVgam[4],wgtQmisID[4],wgtfakes[4],wgttotalbkg[4],wgtpredicted[4],wgtsignal[4];
  Double_t errdata[4],errpromptSS[4],errVgam[4],errQmisID[4],errfakes[4],errfakes_stat[4],errfakes_syst[4],errpredicted[4],errtotalbkg[4],errsignal[4];
  for(Int_t index=0;index<4;index++){
      for(Long64_t entry=0; entry<signal->GetEntries();entry++) {
          signal->GetEntry(entry);
          if(input_channel==3 && signal_channel!=3)continue;
          if(input_channel==2 && signal_channel!=2)continue;
          if(input_channel==1 && signal_channel!=1)continue;
          if(signal_mindR_l2j>fixed_cuts_min[0]&&signal_mindR_l2j<fixed_cuts_max[0] &&
                        signal_mindR_l1j>fixed_cuts_min[1]&&signal_mindR_l1j<fixed_cuts_max[1] &&
                         signal_m_ll>fixed_cuts_min[2]&&signal_m_ll<fixed_cuts_max[2] && 
                         signal_m_l1jj>fixed_cuts_min[3]&&signal_m_l1jj<fixed_cuts_max[3]){
             numOfsignal[index]++;
             numOfwgtsignal[index]+=signal_weight; Err2Ofwgtsignal[index]+=signal_weight*signal_weight;
          }
      }
      for(Long64_t entry=0; entry<totalbkg->GetEntries();entry++) {
          totalbkg->GetEntry(entry);
          if(input_channel==3 && totalbkg_channel!=3)continue;
          if(input_channel==2 && totalbkg_channel!=2)continue;
          if(input_channel==1 && totalbkg_channel!=1)continue;
          if(index==0 &&totalbkg_mindR_l2j>fixed_cuts_min[0]&&totalbkg_mindR_l2j<fixed_cuts_max[0]){
             numOftotalbkg[index]++;
             numOfwgttotalbkg[index]+=totalbkg_weight; 
             if((*totalbkg_component)=="QmisID") {
                 numOfQmisID[index]++;
                 numOfwgtQmisID[index]+=totalbkg_weight; Err2OfwgtQmisID[index]+=totalbkg_weight*totalbkg_weight;
             }
             if((*totalbkg_component)=="Vgam") {
                 numOfVgam[index]++;
                 numOfwgtVgam[index]+=totalbkg_weight; Err2OfwgtVgam[index]+=totalbkg_weight*totalbkg_weight;
             }
             if((*totalbkg_component)=="fake") {
                 numOffake[index]++;
                 numOfwgtfake[index]+=totalbkg_weight; 
                 if(totalbkg_category==22) numOfwgtantiemu[index]+=totalbkg_weight;
                 if(totalbkg_category==23) numOfwgteantimu[index]+=totalbkg_weight;
             }
             if((*totalbkg_component)!="Vgam"&&(*totalbkg_component)!="QmisID"&&(*totalbkg_component)!="fake"){
                 numOfpromptSS[index]++;
                 numOfwgtpromptSS[index]+=totalbkg_weight;
                 Err2OfwgtpromptSS[index]+=totalbkg_weight*totalbkg_weight;
             }
          }
          if(index==1 && totalbkg_mindR_l2j>fixed_cuts_min[0]&&totalbkg_mindR_l2j<fixed_cuts_max[0] &&
                         totalbkg_mindR_l1j>fixed_cuts_min[1]&&totalbkg_mindR_l1j<fixed_cuts_max[1]){
             numOftotalbkg[index]++;
             numOfwgttotalbkg[index]+=totalbkg_weight;
             if((*totalbkg_component)=="QmisID") {
                 numOfQmisID[index]++;
                 numOfwgtQmisID[index]+=totalbkg_weight; Err2OfwgtQmisID[index]+=totalbkg_weight*totalbkg_weight;
             }
             if((*totalbkg_component)=="Vgam") { 
                 numOfVgam[index]++;
                 numOfwgtVgam[index]+=totalbkg_weight; Err2OfwgtVgam[index]+=totalbkg_weight*totalbkg_weight;
             }
             if((*totalbkg_component)=="fake") {
                 numOffake[index]++;
                 numOfwgtfake[index]+=totalbkg_weight; 
                 if(totalbkg_category==22) numOfwgtantiemu[index]+=totalbkg_weight;
                 if(totalbkg_category==23) numOfwgteantimu[index]+=totalbkg_weight;
             }
             if((*totalbkg_component)!="Vgam"&&(*totalbkg_component)!="QmisID"&&(*totalbkg_component)!="fake"){
                 numOfpromptSS[index]++;
                 numOfwgtpromptSS[index]+=totalbkg_weight;
                 Err2OfwgtpromptSS[index]+=totalbkg_weight*totalbkg_weight;
             }
          }
          if(index==2 &&totalbkg_mindR_l2j>fixed_cuts_min[0]&&totalbkg_mindR_l2j<fixed_cuts_max[0] &&
                        totalbkg_mindR_l1j>fixed_cuts_min[1]&&totalbkg_mindR_l1j<fixed_cuts_max[1] &&
                         totalbkg_m_ll>fixed_cuts_min[2]&&totalbkg_m_ll<fixed_cuts_max[2]){
             numOftotalbkg[index]++;
             numOfwgttotalbkg[index]+=totalbkg_weight;
             if((*totalbkg_component)=="QmisID") {
                 numOfQmisID[index]++;
                 numOfwgtQmisID[index]+=totalbkg_weight; Err2OfwgtQmisID[index]+=totalbkg_weight*totalbkg_weight;
             }
             if((*totalbkg_component)=="Vgam") { 
                 numOfVgam[index]++;
                 numOfwgtVgam[index]+=totalbkg_weight; Err2OfwgtVgam[index]+=totalbkg_weight*totalbkg_weight;
             }
             if((*totalbkg_component)=="fake") {
                 numOffake[index]++;
                 numOfwgtfake[index]+=totalbkg_weight; 
                 if(totalbkg_category==22) numOfwgtantiemu[index]+=totalbkg_weight;
                 if(totalbkg_category==23) numOfwgteantimu[index]+=totalbkg_weight;
             }
             if((*totalbkg_component)!="Vgam"&&(*totalbkg_component)!="QmisID"&&(*totalbkg_component)!="fake"){
                 numOfpromptSS[index]++;
                 numOfwgtpromptSS[index]+=totalbkg_weight;
                 Err2OfwgtpromptSS[index]+=totalbkg_weight*totalbkg_weight;
             }
          }
          if(index==3&&totalbkg_mindR_l2j>fixed_cuts_min[0]&&totalbkg_mindR_l2j<fixed_cuts_max[0] &&
                        totalbkg_mindR_l1j>fixed_cuts_min[1]&&totalbkg_mindR_l1j<fixed_cuts_max[1] &&
                         totalbkg_m_ll>fixed_cuts_min[2]&&totalbkg_m_ll<fixed_cuts_max[2] &&
                         totalbkg_m_l1jj>fixed_cuts_min[3]&&totalbkg_m_l1jj<fixed_cuts_max[3]){
              numOftotalbkg[index]++;
              numOfwgttotalbkg[index]+=totalbkg_weight;
              if((*totalbkg_component)=="QmisID") {
                 numOfQmisID[index]++;
                 numOfwgtQmisID[index]+=totalbkg_weight; Err2OfwgtQmisID[index]+=totalbkg_weight*totalbkg_weight;
             }
             if((*totalbkg_component)=="Vgam") { 
                 numOfVgam[index]++;
                 numOfwgtVgam[index]+=totalbkg_weight; Err2OfwgtVgam[index]+=totalbkg_weight*totalbkg_weight;
             }
             if((*totalbkg_component)=="fake") {
                 numOffake[index]++;
                 numOfwgtfake[index]+=totalbkg_weight; 
                 if(totalbkg_category==22) numOfwgtantiemu[index]+=totalbkg_weight;
                 if(totalbkg_category==23) numOfwgteantimu[index]+=totalbkg_weight;
             }
             if((*totalbkg_component)!="Vgam"&&(*totalbkg_component)!="QmisID"&&(*totalbkg_component)!="fake"){
                 numOfpromptSS[index]++;
                 numOfwgtpromptSS[index]+=totalbkg_weight;
                 Err2OfwgtpromptSS[index]+=totalbkg_weight*totalbkg_weight;
             }
          }
      }

      wgtsignal[index]=numOfwgtsignal[index];
      wgttotalbkg[index]=numOfwgttotalbkg[index];
      wgtpromptSS[index]=numOfwgtpromptSS[index];
      wgtVgam[index]=numOfwgtVgam[index];
      wgtQmisID[index]=numOfwgtQmisID[index];
      wgtfakes[index]=numOfwgtfake[index];
      wgtpredicted[index]=wgtsignal[index]+wgttotalbkg[index];
      sigs[index]=numOfwgtsignal[index]/sqrt(wgttotalbkg[index]);
      sigpurs[index]=numOfwgtsignal[index]/(wgttotalbkg[index]);
      errpromptSS[index]=sqrt(Err2OfwgtpromptSS[index]);
      errVgam[index]=sqrt(Err2OfwgtVgam[index]);
      errQmisID[index]=sqrt(Err2OfwgtQmisID[index]);
      if(input_channel==1) {
         errfakes[index]=sqrt(pow(sys_ele*numOfwgtfake[index],2)+ff_ele*numOfwgtfake[index]);
         errfakes_stat[index]=sqrt(ff_ele*numOfwgtfake[index]);
         errfakes_syst[index]=sys_ele*numOfwgtfake[index];
      }
      if(input_channel==2){
          errfakes[index]=sqrt(pow(sys_mu*numOfwgtfake[index],2)+ff_mu*numOfwgtfake[index]);
          errfakes_stat[index]=sqrt(ff_mu*numOfwgtfake[index]);
         errfakes_syst[index]=sys_mu*numOfwgtfake[index];
      }
      if(input_channel==3) {
         errfakes[index]=sqrt(pow(sys_ele*numOfwgtantiemu[index],2)+ff_ele*numOfwgtantiemu[index]+
                              pow(sys_mu*numOfwgteantimu[index],2)+ ff_mu*numOfwgteantimu[index]);
         errfakes_stat[index]=sqrt(ff_ele*numOfwgtantiemu[index]+ff_mu*numOfwgteantimu[index]);
         errfakes_syst[index]=sqrt(pow(sys_ele*numOfwgtantiemu[index],2)+pow(sys_mu*numOfwgteantimu[index],2));
      }
      errtotalbkg[index]=sqrt(Err2OfwgtpromptSS[index]+Err2OfwgtVgam[index]+ Err2OfwgtQmisID[index]+errfakes[index]*errfakes[index]);
      errpredicted[index]=sqrt(Err2Ofwgtsignal[index]+Err2OfwgtpromptSS[index]+Err2OfwgtVgam[index]+ Err2OfwgtQmisID[index]+
                               errfakes[index]*errfakes[index]);
      errdata[index]=sqrt(Err2Ofwgtdata[index]);
      errsignal[index]=sqrt(Err2Ofwgtsignal[index]);
  }//end of loop
  Float_t significance=sigs[3];  
  return significance;
//end of manin func
}
