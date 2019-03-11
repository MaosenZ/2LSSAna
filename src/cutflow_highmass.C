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
void cutflow_highmass(TString masspoint, Int_t input_channel){
  //high mass
  Float_t ff_ele=0.5472, ff_mu=0.4544, sys_ele=0.6918, sys_mu=0.7179;
  //Get trees and variables 
                           //dR_l2j dR_l1j m_ll m_l1jj
  Float_t fixed_cuts_min[4],fixed_cuts_max[4];
  TString output_data_file_name="../HistFactory/data/";
  output_data_file_name+=masspoint;
  string inputCutsFile="output/SigOpt/";
  inputCutsFile+=masspoint; inputCutsFile+="_";
  if(input_channel==1) {inputCutsFile+="ee.txt"; output_data_file_name+="_ee.root";}
  if(input_channel==2) {inputCutsFile+="mumu.txt"; output_data_file_name+="_mumu.root";}
  if(input_channel==3) {inputCutsFile+="emu.txt"; output_data_file_name+="_emu.root";}
  ifstream ff_file(inputCutsFile.c_str(),ifstream::in);
  string line;
  int k=0;
  while(getline(ff_file,line)){
     const char* readline=line.c_str();
     float lower_cut,higher_cut;
     sscanf(readline,"%f %f",&lower_cut,&higher_cut);
     fixed_cuts_min[k]=lower_cut;
     fixed_cuts_max[k]=higher_cut;
     k++;
     cout<<lower_cut<<" "<<higher_cut<<endl;
  }

  TFile *f_signal;
  if(masspoint=="mH400")f_signal=new TFile("output/dataMC_3jets/miniNtuple_mH400.root");
  if(masspoint=="mH500")f_signal=new TFile("output/dataMC_3jets/miniNtuple_mH500.root");
  if(masspoint=="nonres")f_signal=new TFile("output/dataMC_3jets/miniNtuple_nonres.root");
  if((masspoint != "mH400")  && (masspoint!= "mH500") && (masspoint!="nonres")) cout<<"Error input "<<endl;
  TFile *f_data=new TFile("output/dataMC_3jets/miniNtuple_datacombined.root");
  TFile *f_totalbkg=new TFile("output/dataMC_3jets/miniNtuple_totalbkg.root");

   TTree *signal=(TTree*)f_signal->Get("Tree");
  TTree *data=(TTree*)f_data->Get("Tree");
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
  data->SetBranchAddress("MET",&data_met);
  totalbkg->SetBranchAddress("MET",&totalbkg_met);

  signal->SetBranchAddress("m_ll",&signal_m_ll);
  data->SetBranchAddress("m_ll",&data_m_ll);
  totalbkg->SetBranchAddress("m_ll",&totalbkg_m_ll);

  signal->SetBranchAddress("m_l1jj",&signal_m_l1jj);
  data->SetBranchAddress("m_l1jj",&data_m_l1jj);
  totalbkg->SetBranchAddress("m_l1jj",&totalbkg_m_l1jj);

  signal->SetBranchAddress("m_all",&signal_m_all);
  data->SetBranchAddress("m_all",&data_m_all);
  totalbkg->SetBranchAddress("m_all",&totalbkg_m_all);

  signal->SetBranchAddress("mindR_l1j",&signal_mindR_l1j);
  data->SetBranchAddress("mindR_l1j",&data_mindR_l1j);
  totalbkg->SetBranchAddress("mindR_l1j",&totalbkg_mindR_l1j);

  signal->SetBranchAddress("mindR_l2j",&signal_mindR_l2j);
  data->SetBranchAddress("mindR_l2j",&data_mindR_l2j);
  totalbkg->SetBranchAddress("mindR_l2j",&totalbkg_mindR_l2j);

  signal->SetBranchAddress("weight",&signal_weight);
  data->SetBranchAddress("weight",&data_weight);
  totalbkg->SetBranchAddress("weight",&totalbkg_weight);

  signal->SetBranchAddress("channel",&signal_channel);
  data->SetBranchAddress("channel",&data_channel);
  totalbkg->SetBranchAddress("channel",&totalbkg_channel);

  signal->SetBranchAddress("category",&signal_category);
  data->SetBranchAddress("category",&data_category);
  totalbkg->SetBranchAddress("category",&totalbkg_category);

  signal->SetBranchAddress("numOfjet",&signal_numOfjet);
  data->SetBranchAddress("numOfjet",&data_numOfjet);
  totalbkg->SetBranchAddress("numOfjet",&totalbkg_numOfjet);

  signal->SetBranchAddress("component",&signal_component);
  data->SetBranchAddress("component",&data_component);
  totalbkg->SetBranchAddress("component",&totalbkg_component);

  Int_t numOfdata[4]={0},numOfsignal[4]={0},numOfpromptSS[4]={0},  numOfVgam[4]={0},numOfQmisID[4]={0}, numOffake[4]={0},numOftotalbkg[4]={0};
  Double_t numOfwgtdata[4]={0},numOfwgtsignal[4]={0},numOfwgtpromptSS[4]={0},  numOfwgtVgam[4]={0},numOfwgtQmisID[4]={0}, numOfwgtfake[4]={0},
           numOfwgttotalbkg[4]={0};
  Double_t Err2Ofwgtdata[4]={0},Err2Ofwgtsignal[4]={0},Err2OfwgtpromptSS[4]={0},  Err2OfwgtVgam[4]={0},Err2OfwgtQmisID[4]={0};
  Double_t sigs[4]={0}, sigpurs[4]={0},numOfwgteantimu[4]={0},numOfwgtantiemu[4]={0};
  Double_t wgtdata[4],wgtpromptSS[4],wgtVgam[4],wgtQmisID[4],wgtfakes[4],wgttotalbkg[4],wgtpredicted[4],wgtsignal[4];
  Double_t errdata[4],errpromptSS[4],errVgam[4],errQmisID[4],errfakes[4],errfakes_stat[4],errfakes_syst[4],errpredicted[4],errtotalbkg[4],errsignal[4],errtotalbkg_stat[4],errtotalbkg_syst_nonfakes[4];
  Double_t  sf_signal=1;//0.03341;
  for(Int_t index=0;index<4;index++){
      for(Long64_t entry=0; entry<signal->GetEntries();entry++) {
          signal->GetEntry(entry);
          if(input_channel==3 && signal_channel!=3)continue;
          if(input_channel==2 && signal_channel!=2)continue;
          if(input_channel==1 && signal_channel!=1)continue;
          if(index==0 &&signal_mindR_l2j>fixed_cuts_min[0]&&signal_mindR_l2j<fixed_cuts_max[0]){
             numOfsignal[index]++;
             numOfwgtsignal[index]+=signal_weight*sf_signal; Err2Ofwgtsignal[index]+=signal_weight*signal_weight*sf_signal*sf_signal;
          }
          if(index==1 && signal_mindR_l2j>fixed_cuts_min[0]&&signal_mindR_l2j<fixed_cuts_max[0] &&
                         signal_mindR_l1j>fixed_cuts_min[1]&&signal_mindR_l1j<fixed_cuts_max[1]){
             numOfsignal[index]++;
             numOfwgtsignal[index]+=signal_weight*sf_signal; Err2Ofwgtsignal[index]+=signal_weight*signal_weight*sf_signal*sf_signal;
          }
          if(index==2 &&signal_mindR_l2j>fixed_cuts_min[0]&&signal_mindR_l2j<fixed_cuts_max[0] &&
                        signal_mindR_l1j>fixed_cuts_min[1]&&signal_mindR_l1j<fixed_cuts_max[1] &&
                         signal_m_ll>fixed_cuts_min[2]&&signal_m_ll<fixed_cuts_max[2]){
             numOfsignal[index]++;
             numOfwgtsignal[index]+=signal_weight*sf_signal; Err2Ofwgtsignal[index]+=signal_weight*signal_weight*sf_signal*sf_signal;
          }
          if(index==3&&signal_mindR_l2j>fixed_cuts_min[0]&&signal_mindR_l2j<fixed_cuts_max[0] &&
                        signal_mindR_l1j>fixed_cuts_min[1]&&signal_mindR_l1j<fixed_cuts_max[1] &&
                         signal_m_ll>fixed_cuts_min[2]&&signal_m_ll<fixed_cuts_max[2] && 
                         signal_m_l1jj>fixed_cuts_min[3]&&signal_m_l1jj<fixed_cuts_max[3]){
              numOfsignal[index]++;
             numOfwgtsignal[index]+=signal_weight*sf_signal; Err2Ofwgtsignal[index]+=signal_weight*signal_weight*sf_signal*sf_signal;
          }
      }
      for(Long64_t entry=0; entry<data->GetEntries();entry++) {
          data->GetEntry(entry);
          if(input_channel==3 && data_channel!=3)continue;
          if(input_channel==2 && data_channel!=2)continue;
          if(input_channel==1 && data_channel!=1)continue;
          if(index==0 &&data_mindR_l2j>fixed_cuts_min[0]&&data_mindR_l2j<fixed_cuts_max[0]){
             numOfdata[index]++;
             numOfwgtdata[index]+=data_weight; Err2Ofwgtdata[index]+=data_weight*data_weight;
          }
          if(index==1 && data_mindR_l2j>fixed_cuts_min[0]&&data_mindR_l2j<fixed_cuts_max[0] &&
                         data_mindR_l1j>fixed_cuts_min[1]&&data_mindR_l1j<fixed_cuts_max[1]){
             numOfdata[index]++;
             numOfwgtdata[index]+=data_weight; Err2Ofwgtdata[index]+=data_weight*data_weight;
          }
          if(index==2 &&data_mindR_l2j>fixed_cuts_min[0]&&data_mindR_l2j<fixed_cuts_max[0] &&
                        data_mindR_l1j>fixed_cuts_min[1]&&data_mindR_l1j<fixed_cuts_max[1] &&
                         data_m_ll>fixed_cuts_min[2]&&data_m_ll<fixed_cuts_max[2]){
             numOfdata[index]++;
             numOfwgtdata[index]+=data_weight; Err2Ofwgtdata[index]+=data_weight*data_weight;
          }
          if(index==3&&data_mindR_l2j>fixed_cuts_min[0]&&data_mindR_l2j<fixed_cuts_max[0] &&
                        data_mindR_l1j>fixed_cuts_min[1]&&data_mindR_l1j<fixed_cuts_max[1] &&
                         data_m_ll>fixed_cuts_min[2]&&data_m_ll<fixed_cuts_max[2] &&
                         data_m_l1jj>fixed_cuts_min[3]&&data_m_l1jj<fixed_cuts_max[3]){
              numOfdata[index]++;
             numOfwgtdata[index]+=data_weight; Err2Ofwgtdata[index]+=data_weight*data_weight;
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
      errtotalbkg_stat[index]=sqrt(Err2OfwgtpromptSS[index]+Err2OfwgtVgam[index]+ Err2OfwgtQmisID[index]+pow(errfakes_stat[index],2));
      errtotalbkg_syst_nonfakes[index]=sqrt(pow(0.3*wgtpromptSS[index],2)+pow(0.33*wgtQmisID[index],2)+pow(0.5*wgtVgam[index],2));
      errpredicted[index]=sqrt(Err2Ofwgtsignal[index]+Err2OfwgtpromptSS[index]+Err2OfwgtVgam[index]+ Err2OfwgtQmisID[index]+
                               errfakes[index]*errfakes[index]);
      errdata[index]=sqrt(Err2Ofwgtdata[index]);
      errsignal[index]=sqrt(Err2Ofwgtsignal[index]);
      cout<<"s/sqrt(B): "<<sigs[index]<<endl;
  }//end of loop
  //TString blind_numOfdata[4];
  //for(int j=0;j<4;j++){blind_numOfdata[j]="blinded"; errdata[j]=0;}
  ofstream outfile;
  outfile.setf(ios::fixed, ios::floatfield);
  outfile.precision(3);
  TString channel_name="output/SigOpt/cutflow_SigOpt_";
  if(input_channel==1) channel_name+="ee";
  if(input_channel==2) channel_name+="mumu";
  if(input_channel==3) channel_name+="emu";
  outfile.open(channel_name+"_"+masspoint+".tex",ios::trunc);
  /*double statup_Vgam, statdw_Vgam;
  if(wgtVgam[3]==0){statup_Vgam=0; statdw_Vgam=0; }
  else {statdw_Vgam=1-errVgam[3]/wgtVgam[3]; statup_Vgam=1+errVgam[3]/wgtVgam[3];}
  if(input_channel!=2){
outfile<<"NSIG "<<wgtsignal[3]<<"\n"<<"STATUPSIG "<<1+errsignal[3]/wgtsignal[3]<<"\n"<<"STATDWSIG "<<1-errsignal[3]/wgtsignal[3]<<"\n"<<
"NPROMPT "<<wgtpromptSS[3]<<"\n"<<"STATUPPROMPT "<<1+errpromptSS[3]/wgtpromptSS[3]<<"\n"<<"STATDWPROMPT "<<1-errpromptSS[3]/wgtpromptSS[3]<<
"\n"<<"NVGAM "<<wgtVgam[3]<<"\n"<<"STATUPVGAM "<<statup_Vgam<<"\n"<<"STATDWVGAM "<<statdw_Vgam<<"\n"<<
"NQMISID "<<wgtQmisID[3]<<"\n"<<"STATUPQMISID "<<1+errQmisID[3]/wgtQmisID[3]<<"\n"<<"STATDWQMISID "<<1-errQmisID[3]/wgtQmisID[3]<<"\n"<<
"NFAKES "<<wgtfakes[3]<<"\n"<<"STATUPFAKES "<<1+errfakes_stat[3]/wgtfakes[3]<<"\n"<<"STATDWFAKES "<<1-errfakes_stat[3]/wgtfakes[3]<<"\n"<<"SYSTUPFAKES "<<1+errfakes_syst[3]/wgtfakes[3]<<"\n"<<"SYSTDWFAKES "<<1-errfakes_syst[3]/wgtfakes[3];}
  if(input_channel==2){
     outfile<<"NSIG "<<wgtsignal[3]<<"\n"<<"STATUPSIG "<<1+errsignal[3]/wgtsignal[3]<<"\n"<<"STATDWSIG "<<1-errsignal[3]/wgtsignal[3]<<"\n"<<
"NPROMPT "<<wgtpromptSS[3]<<"\n"<<"STATUPPROMPT "<<1+errpromptSS[3]/wgtpromptSS[3]<<"\n"<<"STATDWPROMPT "<<1-errpromptSS[3]/wgtpromptSS[3]<<
"\n"<<"NVGAM "<<wgtVgam[3]<<"\n"<<"STATUPVGAM "<<statup_Vgam<<"\n"<<"STATDWVGAM "<<statdw_Vgam<<"\n"<<
"NFAKES "<<wgtfakes[3]<<"\n"<<"STATUPFAKES "<<1+errfakes_stat[3]/wgtfakes[3]<<"\n"<<"STATDWFAKES "<<1-errfakes_stat[3]/wgtfakes[3]<<"\n"<<"SYSTUPFAKES "<<1+errfakes_syst[3]/wgtfakes[3]<<"\n"<<"SYSTDWFAKES "<<1-errfakes_syst[3]/wgtfakes[3];
  }*/
  outfile<<"\\begin{table}[h]"<<"\n";
  outfile<<"\\begin{center}"<<"\n";
  outfile<<"\\scriptsize"<<"\n";
  outfile<<"\\begin{tabular}{c|cccc|cc|c}"<<"\n";
  outfile<<"\\hline"<<"\n";
  outfile<<"\\hline"<<"\n";
  outfile<<"                           &promptSS"<<setw(3)<<"  &$V+\\gamma$"<<setw(3)<<"  &QmisID"<<setw(3)<<"  &Fakes"<<"  &Total bkg"<<"  &Observed"<<"  &signal"<<"  \\\\  "<<"\n";
  outfile<<"\\hline"<<"\n";
  outfile<<"$\\Delta R_{min}(l\_{2},j)$ "<<"&"<<wgtpromptSS[0]<<"$\\pm$"<<errpromptSS[0]<<"(stat.)$\\pm$"<<0.3*wgtpromptSS[0]<<"(syst.)"<<setw(3)<<"&"<<wgtVgam[0]<<"$\\pm$"<<errVgam[0]<<"(stat.)$\\pm$"<<0.5*wgtVgam[0]<<"(syst.)"<<setw(3)<<"&"<<wgtQmisID[0]<<"$\\pm$"<<errQmisID[0]<<"(stat.)$\\pm$"<<0.33*wgtQmisID[0]<<"(syst.)"<<setw(3)<<"&"<<wgtfakes[0]<<"$\\pm$"<<errfakes_stat[0]<<"(stat.)$\\pm$"<<errfakes_syst[0]<<"(syst.)"<<setw(3)<<"&"<<wgttotalbkg[0]<<"$\\pm$"<<errtotalbkg_stat[0]<<"(stat.)$\\mp$"<<errtotalbkg_syst_nonfakes[0]<<"(syst1.)$\\pm$"<<errfakes_syst[0]<<"(syst2.)"<<setw(3)<<"&"<<numOfdata[0]<<setw(3)<<"&"<<wgtsignal[0]<<"$\\pm$"<<errsignal[0]<<"\\\\"<<"\n";
  outfile<<"\\hline"<<"\n";
  outfile<<"$\\Delta R_{min}(l\_{1},j)$ "<<"&"<<wgtpromptSS[1]<<"$\\pm$"<<errpromptSS[1]<<"(stat.)$\\pm$"<<0.3*wgtpromptSS[1]<<"(syst.)"<<setw(3)<<"&"<<wgtVgam[1]<<"$\\pm$"<<errVgam[1]<<"(stat.)$\\pm$"<<0.5*wgtVgam[1]<<"(syst.)"<<setw(3)<<"&"<<wgtQmisID[1]<<"$\\pm$"<<errQmisID[1]<<"(stat.)$\\pm$"<<0.33*wgtQmisID[1]<<"(syst.)"<<setw(3)<<"&"<<wgtfakes[1]<<"$\\pm$"<<errfakes_stat[1]<<"(stat.)$\\pm$"<<errfakes_syst[1]<<"(syst.)"<<setw(3)<<"&"<<wgttotalbkg[1]<<"$\\pm$"<<errtotalbkg_stat[1]<<"(stat.)$\\mp$"<<errtotalbkg_syst_nonfakes[1]<<"(syst1.)$\\pm$"<<errfakes_syst[1]<<"(syst2.)"<<setw(3)<<"&"<<numOfdata[1]<<setw(3)<<"&"<<wgtsignal[1]<<"$\\pm$"<<errsignal[1]<<"\\\\"<<"\n";
  outfile<<"\\hline"<<"\n";
  outfile<<"$M(\\ell\\ell)$ "<<"&"<<wgtpromptSS[2]<<"$\\pm$"<<errpromptSS[2]<<"(stat.)$\\pm$"<<0.3*wgtpromptSS[2]<<"(syst.)"<<setw(3)<<"&"<<wgtVgam[2]<<"$\\pm$"<<errVgam[2]<<"(stat.)$\\pm$"<<0.5*wgtVgam[2]<<"(syst.)"<<setw(3)<<"&"<<wgtQmisID[2]<<"$\\pm$"<<errQmisID[2]<<"(stat.)$\\pm$"<<0.33*wgtQmisID[2]<<"(syst.)"<<setw(3)<<"&"<<wgtfakes[2]<<"$\\pm$"<<errfakes_stat[2]<<"(stat.)$\\pm$"<<errfakes_syst[2]<<"(syst.)"<<setw(3)<<"&"<<wgttotalbkg[2]<<"$\\pm$"<<errtotalbkg_stat[2]<<"(stat.)$\\mp$"<<errtotalbkg_syst_nonfakes[2]<<"(syst1.)$\\pm$"<<errfakes_syst[2]<<"(syst2.)"<<setw(3)<<"&"<<numOfdata[2]<<setw(3)<<"&"<<wgtsignal[2]<<"$\\pm$"<<errsignal[2]<<"\\\\"<<"\n";
  outfile<<"\\hline"<<"\n";
  outfile<<"$M(l\_{1}jj)$ "<<"&"<<wgtpromptSS[3]<<"$\\pm$"<<errpromptSS[3]<<"(stat.)$\\pm$"<<0.3*wgtpromptSS[3]<<"(syst.)"<<setw(3)<<"&"<<wgtVgam[3]<<"$\\pm$"<<errVgam[3]<<"(stat.)$\\pm$"<<0.5*wgtVgam[3]<<"(syst.)"<<setw(3)<<"&"<<wgtQmisID[3]<<"$\\pm$"<<errQmisID[3]<<"(stat.)$\\pm$"<<0.33*wgtQmisID[3]<<"(syst.)"<<setw(3)<<"&"<<wgtfakes[3]<<"$\\pm$"<<errfakes_stat[3]<<"(stat.)$\\pm$"<<errfakes_syst[3]<<"(syst.)"<<setw(3)<<"&"<<wgttotalbkg[3]<<"$\\pm$"<<errtotalbkg_stat[3]<<"(stat.)$\\mp$"<<errtotalbkg_syst_nonfakes[3]<<"(syst1.)$\\pm$"<<errfakes_syst[3]<<"(syst2.)"<<setw(3)<<"&"<<numOfdata[3]<<setw(3)<<"&"<<wgtsignal[3]<<"$\\pm$"<<errsignal[3]<<"\\\\"<<"\n";
  outfile<<"\\hline"<<"\n";
  outfile<<"\\hline"<<"\n";
  outfile<<"\\end{tabular}"<<"\n";
  outfile<<"\\end{center}"<<"\n";

  TFile *output_data_file=new TFile(output_data_file_name,"recreate");
  TH1F *hist_unity=new TH1F("unity","",1,0,1);
  TH1F *hist_data=new TH1F("data","",1,0,1);
  hist_unity->SetBinContent(1,1);
  hist_data->SetBinContent(1,numOfdata[3]);
  hist_unity->Write();
  hist_data->Write();
  output_data_file->Close();
//end of manin func
}
