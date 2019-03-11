//-------------------------------------------------------------------------------------------
// This script is to define cut-flow of hh->WWWW, using ntuples after hh4Wanalysis.C.
// Also can be used to draw plots
// Author: Maosen Zhou (maosen.zhou@cern.ch)
// Date: 25/Sep/2016
// --to scan different cuts to define best cuts
//   vars to be used: mindR_l1j, mindR_l2j, mindR_l2j 
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
#include "../../atlasstyle-00-03-05/AtlasStyle.C"
#include "../../atlasstyle-00-03-05/AtlasUtils.C"
using namespace std;
using namespace TMath;
void checkContamination_highmass(TString masspoint,Int_t input_channel){
  SetAtlasStyle();
  //low mass
  Float_t ff_ele=0.23, ff_mu=0.41, sys_ele=0.544, sys_mu=0.609;
                           //dR_l2j dR_l1j mindR_l1j m_ll
  Float_t fixed_cuts_min[4]={0}, fixed_cuts_max[4]={0};
  string inputCutsFile="output/SigOpt/";
  inputCutsFile+=masspoint; inputCutsFile+="_";
  if(input_channel==1)inputCutsFile+="ee.txt";
  if(input_channel==2)inputCutsFile+="mumu.txt";
  if(input_channel==3)inputCutsFile+="emu.txt";
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
 
  TFile *f_mH260=new TFile("output/dataMC_3jets/miniNtuple_mH260.root");
  TFile *f_mH300=new TFile("output/dataMC_3jets/miniNtuple_mH300.root");
  TFile *f_mH400=new TFile("output/dataMC_3jets/miniNtuple_mH400.root");
  TFile *f_mH500=new TFile("output/dataMC_3jets/miniNtuple_mH500.root");
  TFile *f_nonres=new TFile("output/dataMC_3jets/miniNtuple_nonres.root");
  TFile *f_data=new TFile("output/dataMC_3jets/miniNtuple_datacombined.root");
  TFile *f_totalbkg=new TFile("output/dataMC_3jets/miniNtuple_totalbkg.root");

   TTree *mH260=(TTree*)f_mH260->Get("Tree");
   TTree *mH300=(TTree*)f_mH300->Get("Tree");
   TTree *mH400=(TTree*)f_mH400->Get("Tree");
   TTree *mH500=(TTree*)f_mH500->Get("Tree");
   TTree *nonres=(TTree*)f_nonres->Get("Tree");
  TTree *data=(TTree*)f_data->Get("Tree");
  TTree *totalbkg=(TTree*)f_totalbkg->Get("Tree");
  Float_t mH260_met,mH300_met,mH400_met,mH500_met,nonres_met,totalbkg_met,data_met;
  Float_t mH260_mindR_l1j,mH300_mindR_l1j,mH400_mindR_l1j,mH500_mindR_l1j,nonres_mindR_l1j,totalbkg_mindR_l1j,data_mindR_l1j;
  Float_t mH260_m_ll,mH300_m_ll,mH400_m_ll,mH500_m_ll,nonres_m_ll,totalbkg_m_ll,data_m_ll;
  Float_t mH260_m_l1jj,mH300_m_l1jj,mH400_m_l1jj,mH500_m_l1jj,nonres_m_l1jj,totalbkg_m_l1jj,data_m_l1jj;
  Float_t mH260_mindR_l2j,mH300_mindR_l2j,mH400_mindR_l2j,mH500_mindR_l2j,nonres_mindR_l2j,totalbkg_mindR_l2j,data_mindR_l2j;
  Float_t mH260_mindR_l2j,mH300_mindR_l2j,mH400_mindR_l2j,mH500_mindR_l2j,nonres_mindR_l2j,totalbkg_mindR_l2j,data_mindR_l2j;
  Double_t mH260_weight,mH300_weight,mH400_weight,mH500_weight,nonres_weight,totalbkg_weight,data_weight;
  Int_t mH260_channel,mH300_channel,mH400_channel,mH500_channel,nonres_channel,totalbkg_channel,data_channel;
  Int_t mH260_category,mH300_category,mH400_category,mH500_category,nonres_category,totalbkg_category,data_category;
  Int_t mH260_numOfjet,mH300_numOfjet,mH400_numOfjet,mH500_numOfjet,nonres_numOfjet,totalbkg_numOfjet,data_numOfjet;
  TString *mH260_component=0, *mH300_component,*mH400_component,*mH500_component,*nonres_component,*data_component=0, *totalbkg_component=0;

  mH260->SetBranchAddress("MET",&mH260_met);
  mH300->SetBranchAddress("MET",&mH300_met);
  mH400->SetBranchAddress("MET",&mH400_met);
  mH500->SetBranchAddress("MET",&mH500_met);
  nonres->SetBranchAddress("MET",&nonres_met);
  data->SetBranchAddress("MET",&data_met);
  totalbkg->SetBranchAddress("MET",&totalbkg_met);

  mH260->SetBranchAddress("mindR_l1j",&mH260_mindR_l1j);
  mH300->SetBranchAddress("mindR_l1j",&mH300_mindR_l1j);
  mH400->SetBranchAddress("mindR_l1j",&mH400_mindR_l1j);
  mH500->SetBranchAddress("mindR_l1j",&mH500_mindR_l1j);
  nonres->SetBranchAddress("mindR_l1j",&nonres_mindR_l1j);
  data->SetBranchAddress("mindR_l1j",&data_mindR_l1j);
  totalbkg->SetBranchAddress("mindR_l1j",&totalbkg_mindR_l1j);

  mH260->SetBranchAddress("m_ll",&mH260_m_ll);
  mH300->SetBranchAddress("m_ll",&mH300_m_ll);
  mH400->SetBranchAddress("m_ll",&mH400_m_ll);
  mH500->SetBranchAddress("m_ll",&mH500_m_ll);
  nonres->SetBranchAddress("m_ll",&nonres_m_ll);
  data->SetBranchAddress("m_ll",&data_m_ll);
  totalbkg->SetBranchAddress("m_ll",&totalbkg_m_ll);

  mH260->SetBranchAddress("m_l1jj",&mH260_m_l1jj);
  mH300->SetBranchAddress("m_l1jj",&mH300_m_l1jj);
  mH400->SetBranchAddress("m_l1jj",&mH400_m_l1jj);
  mH500->SetBranchAddress("m_l1jj",&mH500_m_l1jj);
  nonres->SetBranchAddress("m_l1jj",&nonres_m_l1jj);
  data->SetBranchAddress("m_l1jj",&data_m_l1jj);
  totalbkg->SetBranchAddress("m_l1jj",&totalbkg_m_l1jj);

  mH260->SetBranchAddress("mindR_l2j",&mH260_mindR_l2j);
  mH300->SetBranchAddress("mindR_l2j",&mH300_mindR_l2j);
  mH400->SetBranchAddress("mindR_l2j",&mH400_mindR_l2j);
  mH500->SetBranchAddress("mindR_l2j",&mH500_mindR_l2j);
  nonres->SetBranchAddress("mindR_l2j",&nonres_mindR_l2j);
  data->SetBranchAddress("mindR_l2j",&data_mindR_l2j);
  totalbkg->SetBranchAddress("mindR_l2j",&totalbkg_mindR_l2j);

  mH260->SetBranchAddress("mindR_l2j",&mH260_mindR_l2j);
  mH300->SetBranchAddress("mindR_l2j",&mH300_mindR_l2j);
  mH400->SetBranchAddress("mindR_l2j",&mH400_mindR_l2j);
  mH500->SetBranchAddress("mindR_l2j",&mH500_mindR_l2j);
  nonres->SetBranchAddress("mindR_l2j",&nonres_mindR_l2j);
  data->SetBranchAddress("mindR_l2j",&data_mindR_l2j);
  totalbkg->SetBranchAddress("mindR_l2j",&totalbkg_mindR_l2j);

  mH260->SetBranchAddress("weight",&mH260_weight);
  mH300->SetBranchAddress("weight",&mH300_weight);
  mH400->SetBranchAddress("weight",&mH400_weight);
  mH500->SetBranchAddress("weight",&mH500_weight);
  nonres->SetBranchAddress("weight",&nonres_weight);
  data->SetBranchAddress("weight",&data_weight);
  totalbkg->SetBranchAddress("weight",&totalbkg_weight);

  mH260->SetBranchAddress("channel",&mH260_channel);
  mH300->SetBranchAddress("channel",&mH300_channel);
  mH400->SetBranchAddress("channel",&mH400_channel);
  mH500->SetBranchAddress("channel",&mH500_channel);
  nonres->SetBranchAddress("channel",&nonres_channel);
  data->SetBranchAddress("channel",&data_channel);
  totalbkg->SetBranchAddress("channel",&totalbkg_channel);

  mH260->SetBranchAddress("category",&mH260_category);
  mH300->SetBranchAddress("category",&mH300_category);
  mH400->SetBranchAddress("category",&mH400_category);
  mH500->SetBranchAddress("category",&mH500_category);
  nonres->SetBranchAddress("category",&nonres_category);
  data->SetBranchAddress("category",&data_category);
  totalbkg->SetBranchAddress("category",&totalbkg_category);

  mH260->SetBranchAddress("numOfjet",&mH260_numOfjet);
  mH300->SetBranchAddress("numOfjet",&mH300_numOfjet);
  mH400->SetBranchAddress("numOfjet",&mH400_numOfjet);
  mH500->SetBranchAddress("numOfjet",&mH500_numOfjet);
  nonres->SetBranchAddress("numOfjet",&nonres_numOfjet);
  data->SetBranchAddress("numOfjet",&data_numOfjet);
  totalbkg->SetBranchAddress("numOfjet",&totalbkg_numOfjet);

  mH260->SetBranchAddress("component",&mH260_component);
  mH300->SetBranchAddress("component",&mH300_component);
  mH400->SetBranchAddress("component",&mH400_component);
  mH500->SetBranchAddress("component",&mH500_component);
  nonres->SetBranchAddress("component",&nonres_component);
  data->SetBranchAddress("component",&data_component);
  totalbkg->SetBranchAddress("component",&totalbkg_component);

  Int_t numOfdata[4]={0},numOfmH260[4]={0},numOfmH300[4]={0},numOfmH400[4]={0},numOfmH500[4]={0},numOfnonres[4]={0},numOfpromptSS[4]={0},  numOfVgam[4]={0},numOfQmisID[4]={0}, numOffake[4]={0},numOftotalbkg[4]={0};
  Double_t numOfwgtdata[4]={0},numOfwgtmH260[4]={0},numOfwgtmH300[4]={0},numOfwgtmH400[4]={0},numOfwgtmH500[4]={0},numOfwgtnonres[4]={0},
           numOfwgtpromptSS[4]={0},  numOfwgtVgam[4]={0},numOfwgtQmisID[4]={0}, numOfwgtfake[4]={0},  numOfwgttotalbkg[4]={0};
  Double_t Err2Ofwgtdata[4]={0},Err2OfwgtmH260[4]={0},Err2OfwgtmH300[4]={0},Err2OfwgtmH400[4]={0},Err2OfwgtmH500[4]={0},Err2Ofwgtnonres[4]={0},Err2OfwgtpromptSS[4]={0},  Err2OfwgtVgam[4]={0},Err2OfwgtQmisID[4]={0};
  Double_t sigs[4]={0}, sigpurs[4]={0},numOfwgteantimu[4]={0},numOfwgtantiemu[4]={0};
  Double_t wgtdata[4],wgtpromptSS[4],wgtVgam[4],wgtQmisID[4],wgtfakes[4],wgttotalbkg[4],wgtpredicted[4],wgtmH260[4],wgtmH300[4],wgtmH400[4],
           wgtmH500[4],wgtnonres[4];
  Double_t errdata[4],errpromptSS[4],errVgam[4],errQmisID[4],errfakes[4],errfakes_stat[4],errfakes_syst[4],errpredicted[4],errtotalbkg[4],
           errmH260[4],errmH300[4],errmH400[4],errmH500[4],errnonres[4];
  for(Int_t index=0;index<4;index++){
      for(Long64_t entry=0; entry<mH260->GetEntries();entry++) {
          mH260->GetEntry(entry);
          if(input_channel==3 && mH260_channel!=3)continue;
          if(input_channel==2 && mH260_channel!=2)continue;
          if(input_channel==1 && mH260_channel!=1)continue;
          if(index==0 &&mH260_mindR_l2j>fixed_cuts_min[0]&&mH260_mindR_l2j<fixed_cuts_max[0]){
             numOfmH260[index]++;
             numOfwgtmH260[index]+=mH260_weight; Err2OfwgtmH260[index]+=mH260_weight*mH260_weight;
          }
          if(index==1 && mH260_mindR_l2j>fixed_cuts_min[0]&&mH260_mindR_l2j<fixed_cuts_max[0] &&
                         mH260_mindR_l1j>fixed_cuts_min[1]&&mH260_mindR_l1j<fixed_cuts_max[1]){
             numOfmH260[index]++;
             numOfwgtmH260[index]+=mH260_weight; Err2OfwgtmH260[index]+=mH260_weight*mH260_weight;
          }
          if(index==2 && mH260_mindR_l2j>fixed_cuts_min[0]&&mH260_mindR_l2j<fixed_cuts_max[0] &&
                         mH260_mindR_l1j>fixed_cuts_min[1]&&mH260_mindR_l1j<fixed_cuts_max[1] &&
                         mH260_m_ll>fixed_cuts_min[2]&&mH260_m_ll<fixed_cuts_max[2]){
             numOfmH260[index]++;
             numOfwgtmH260[index]+=mH260_weight; Err2OfwgtmH260[index]+=mH260_weight*mH260_weight;
          }
          if(index==3&&mH260_mindR_l2j>fixed_cuts_min[0]&&mH260_mindR_l2j<fixed_cuts_max[0] &&
                         mH260_mindR_l1j>fixed_cuts_min[1]&&mH260_mindR_l1j<fixed_cuts_max[1] &&
                         mH260_m_ll>fixed_cuts_min[2]&&mH260_m_ll<fixed_cuts_max[2] &&
                         mH260_m_l1jj>fixed_cuts_min[3]&&mH260_m_l1jj<fixed_cuts_max[3]){
              numOfmH260[index]++;
             numOfwgtmH260[index]+=mH260_weight; Err2OfwgtmH260[index]+=mH260_weight*mH260_weight;
          }
      }
      for(Long64_t entry=0; entry<mH300->GetEntries();entry++) {
          mH300->GetEntry(entry);
          if(input_channel==3 && mH300_channel!=3)continue;
          if(input_channel==2 && mH300_channel!=2)continue;
          if(input_channel==1 && mH300_channel!=1)continue;
          if(index==0 &&mH300_mindR_l2j>fixed_cuts_min[0]&&mH300_mindR_l2j<fixed_cuts_max[0]){
             numOfmH300[index]++;
             numOfwgtmH300[index]+=mH300_weight; Err2OfwgtmH300[index]+=mH300_weight*mH300_weight;
          }
          if(index==1 && mH300_mindR_l2j>fixed_cuts_min[0]&&mH300_mindR_l2j<fixed_cuts_max[0] &&
                         mH300_mindR_l1j>fixed_cuts_min[1]&&mH300_mindR_l1j<fixed_cuts_max[1]){
             numOfmH300[index]++;
             numOfwgtmH300[index]+=mH300_weight; Err2OfwgtmH300[index]+=mH300_weight*mH300_weight;
          }
          if(index==2 && mH300_mindR_l2j>fixed_cuts_min[0]&&mH300_mindR_l2j<fixed_cuts_max[0] &&
                         mH300_mindR_l1j>fixed_cuts_min[1]&&mH300_mindR_l1j<fixed_cuts_max[1] &&
                         mH300_m_ll>fixed_cuts_min[2]&&mH300_m_ll<fixed_cuts_max[2]){
             numOfmH300[index]++;
             numOfwgtmH300[index]+=mH300_weight; Err2OfwgtmH300[index]+=mH300_weight*mH300_weight;
          }
          if(index==3&&mH300_mindR_l2j>fixed_cuts_min[0]&&mH300_mindR_l2j<fixed_cuts_max[0] &&
                         mH300_mindR_l1j>fixed_cuts_min[1]&&mH300_mindR_l1j<fixed_cuts_max[1] &&
                         mH300_m_ll>fixed_cuts_min[2]&&mH300_m_ll<fixed_cuts_max[2] &&
                         mH300_m_l1jj>fixed_cuts_min[3]&&mH300_m_l1jj<fixed_cuts_max[3]){
              numOfmH300[index]++;
             numOfwgtmH300[index]+=mH300_weight; Err2OfwgtmH300[index]+=mH300_weight*mH300_weight;
          }
      }
      for(Long64_t entry=0; entry<mH400->GetEntries();entry++) {
          mH400->GetEntry(entry);
          if(input_channel==3 && mH400_channel!=3)continue;
          if(input_channel==2 && mH400_channel!=2)continue;
          if(input_channel==1 && mH400_channel!=1)continue;
          if(index==0 &&mH400_mindR_l2j>fixed_cuts_min[0]&&mH400_mindR_l2j<fixed_cuts_max[0]){
             numOfmH400[index]++;
             numOfwgtmH400[index]+=mH400_weight; Err2OfwgtmH400[index]+=mH400_weight*mH400_weight;
          }
          if(index==1 && mH400_mindR_l2j>fixed_cuts_min[0]&&mH400_mindR_l2j<fixed_cuts_max[0] &&
                         mH400_mindR_l1j>fixed_cuts_min[1]&&mH400_mindR_l1j<fixed_cuts_max[1]){
             numOfmH400[index]++;
             numOfwgtmH400[index]+=mH400_weight; Err2OfwgtmH400[index]+=mH400_weight*mH400_weight;
          }
          if(index==2 && mH400_mindR_l2j>fixed_cuts_min[0]&&mH400_mindR_l2j<fixed_cuts_max[0] &&
                         mH400_mindR_l1j>fixed_cuts_min[1]&&mH400_mindR_l1j<fixed_cuts_max[1] &&
                         mH400_m_ll>fixed_cuts_min[2]&&mH400_m_ll<fixed_cuts_max[2]){
             numOfmH400[index]++;
             numOfwgtmH400[index]+=mH400_weight; Err2OfwgtmH400[index]+=mH400_weight*mH400_weight;
          }
          if(index==3&&mH400_mindR_l2j>fixed_cuts_min[0]&&mH400_mindR_l2j<fixed_cuts_max[0] &&
                         mH400_mindR_l1j>fixed_cuts_min[1]&&mH400_mindR_l1j<fixed_cuts_max[1] &&
                         mH400_m_ll>fixed_cuts_min[2]&&mH400_m_ll<fixed_cuts_max[2] &&
                         mH400_m_l1jj>fixed_cuts_min[3]&&mH400_m_l1jj<fixed_cuts_max[3]){
              numOfmH400[index]++;
             numOfwgtmH400[index]+=mH400_weight; Err2OfwgtmH400[index]+=mH400_weight*mH400_weight;
          }
      }
      for(Long64_t entry=0; entry<mH500->GetEntries();entry++) {
          mH500->GetEntry(entry);
          if(input_channel==3 && mH500_channel!=3)continue;
          if(input_channel==2 && mH500_channel!=2)continue;
          if(input_channel==1 && mH500_channel!=1)continue;
          if(index==0 &&mH500_mindR_l2j>fixed_cuts_min[0]&&mH500_mindR_l2j<fixed_cuts_max[0]){
             numOfmH500[index]++;
             numOfwgtmH500[index]+=mH500_weight; Err2OfwgtmH500[index]+=mH500_weight*mH500_weight;
          }
          if(index==1 && mH500_mindR_l2j>fixed_cuts_min[0]&&mH500_mindR_l2j<fixed_cuts_max[0] &&
                         mH500_mindR_l1j>fixed_cuts_min[1]&&mH500_mindR_l1j<fixed_cuts_max[1]){
             numOfmH500[index]++;
             numOfwgtmH500[index]+=mH500_weight; Err2OfwgtmH500[index]+=mH500_weight*mH500_weight;
          }
          if(index==2 && mH500_mindR_l2j>fixed_cuts_min[0]&&mH500_mindR_l2j<fixed_cuts_max[0] &&
                         mH500_mindR_l1j>fixed_cuts_min[1]&&mH500_mindR_l1j<fixed_cuts_max[1] &&
                         mH500_m_ll>fixed_cuts_min[2]&&mH500_m_ll<fixed_cuts_max[2]){
             numOfmH500[index]++;
             numOfwgtmH500[index]+=mH500_weight; Err2OfwgtmH500[index]+=mH500_weight*mH500_weight;
          }
          if(index==3&&mH500_mindR_l2j>fixed_cuts_min[0]&&mH500_mindR_l2j<fixed_cuts_max[0] &&
                         mH500_mindR_l1j>fixed_cuts_min[1]&&mH500_mindR_l1j<fixed_cuts_max[1] &&
                         mH500_m_ll>fixed_cuts_min[2]&&mH500_m_ll<fixed_cuts_max[2] &&
                         mH500_m_l1jj>fixed_cuts_min[3]&&mH500_m_l1jj<fixed_cuts_max[3]){
              numOfmH500[index]++;
             numOfwgtmH500[index]+=mH500_weight; Err2OfwgtmH500[index]+=mH500_weight*mH500_weight;
          }
      }
      for(Long64_t entry=0; entry<nonres->GetEntries();entry++) {
          nonres->GetEntry(entry);
          if(input_channel==3 && nonres_channel!=3)continue;
          if(input_channel==2 && nonres_channel!=2)continue;
          if(input_channel==1 && nonres_channel!=1)continue;
          if(index==0 &&nonres_mindR_l2j>fixed_cuts_min[0]&&nonres_mindR_l2j<fixed_cuts_max[0]){
             numOfnonres[index]++;
             numOfwgtnonres[index]+=nonres_weight; Err2Ofwgtnonres[index]+=nonres_weight*nonres_weight;
          }
          if(index==1 && nonres_mindR_l2j>fixed_cuts_min[0]&&nonres_mindR_l2j<fixed_cuts_max[0] &&
                         nonres_mindR_l1j>fixed_cuts_min[1]&&nonres_mindR_l1j<fixed_cuts_max[1]){
             numOfnonres[index]++;
             numOfwgtnonres[index]+=nonres_weight; Err2Ofwgtnonres[index]+=nonres_weight*nonres_weight;
          }
          if(index==2 && nonres_mindR_l2j>fixed_cuts_min[0]&&nonres_mindR_l2j<fixed_cuts_max[0] &&
                         nonres_mindR_l1j>fixed_cuts_min[1]&&nonres_mindR_l1j<fixed_cuts_max[1] &&
                         nonres_m_ll>fixed_cuts_min[2]&&nonres_m_ll<fixed_cuts_max[2]){
             numOfnonres[index]++;
             numOfwgtnonres[index]+=nonres_weight; Err2Ofwgtnonres[index]+=nonres_weight*nonres_weight;
          }
          if(index==3&&nonres_mindR_l2j>fixed_cuts_min[0]&&nonres_mindR_l2j<fixed_cuts_max[0] &&
                         nonres_mindR_l1j>fixed_cuts_min[1]&&nonres_mindR_l1j<fixed_cuts_max[1] &&
                         nonres_m_ll>fixed_cuts_min[2]&&nonres_m_ll<fixed_cuts_max[2] &&
                         nonres_m_l1jj>fixed_cuts_min[3]&&nonres_m_l1jj<fixed_cuts_max[3]){
              numOfnonres[index]++;
             numOfwgtnonres[index]+=nonres_weight; Err2Ofwgtnonres[index]+=nonres_weight*nonres_weight;
          }
      }
      /*
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
                         data_m_ll>fixed_cuts_min[2]&&data_m_ll<fixed_cuts_max[2] ){
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
      }*/
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
      double wgtsignal[4];
      if(masspoint=="mH260")wgtsignal[index]=numOfwgtmH260[index];
      if(masspoint=="mH300")wgtsignal[index]=numOfwgtmH300[index];
      if(masspoint=="mH400")wgtsignal[index]=numOfwgtmH400[index];
      if(masspoint=="mH500")wgtsignal[index]=numOfwgtmH500[index];
      if(masspoint=="nonres")wgtsignal[index]=numOfwgtnonres[index];
      sigs[index]=wgtsignal[index]/sqrt(numOfwgttotalbkg[index]);
      /*wgtsignal[index]=numOfwgtsignal[index];
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
      if(input_channel==3){
         errfakes[index]=sqrt(pow(sys_ele*numOfwgtantiemu[index],2)+ff_ele*numOfwgtantiemu[index]+
                                                pow(sys_mu*numOfwgteantimu[index],2)+ ff_mu*numOfwgteantimu[index]);
         errfakes_stat[index]=sqrt(ff_ele*numOfwgtantiemu[index]+ff_mu*numOfwgteantimu[index]);
         errfakes_syst[index]=sqrt(pow(sys_ele*numOfwgtantiemu[index],2)+pow(sys_mu*numOfwgteantimu[index],2));
      }
      errtotalbkg[index]=sqrt(Err2OfwgtpromptSS[index]+Err2OfwgtVgam[index]+ Err2OfwgtQmisID[index]+errfakes[index]*errfakes[index]);
      errpredicted[index]=sqrt(Err2Ofwgtsignal[index]+Err2OfwgtpromptSS[index]+Err2OfwgtVgam[index]+ Err2OfwgtQmisID[index]+
                               errfakes[index]*errfakes[index]);
      errdata[index]=sqrt(Err2Ofwgtdata[index]);
      errsignal[index]=sqrt(Err2Ofwgtsignal[index]);*/
      cout<<"s/sqrt(B): "<<sigs[index]<<endl;
  }//end of loop
  /*for(int j=0;j<4;j++){numOfdata[j]=0; errdata[j]=0;}
  ofstream outfile;
  TString channel_name;
  if(input_channel==1) channel_name="ee";
  if(input_channel==2) channel_name="mumu";
  if(input_channel==3) channel_name="emu";
  //outfile.open(channel_name+"_"+masspoint+".txt",ios::trunc);
  double statup_Vgam, statdw_Vgam;
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
  cout<<"---------------------------------------"<<endl;
  cout<<setiosflags(ios::fixed)<<setprecision(3);
  /*cout<<"                           &promptSS"<<setw(3)<<"  &$V+\\gamma$"<<setw(3)<<"  &QmisID"<<setw(3)<<"  &Fakes"<<"  &Total bkg"<<"  &signal"<<"  &Total predicted"<<"  &Observed"<<"  \\\\  "<<"  s/sqrt(B)"<<endl;
  cout<<"\\hline"<<endl;
  cout<<"\\hline"<<endl;
  cout<<"$\\Delta R_{min}(l\_{1},j)$ "<<"&"<<wgtpromptSS[0]<<"$\\pm$"<<errpromptSS[0]<<setw(3)<<"&"<<wgtVgam[0]<<"$\\pm$"<<errVgam[0]<<setw(3)<<"&"<<wgtQmisID[0]<<"$\\pm$"<<errQmisID[0]<<setw(3)<<"&"<<wgtfakes[0]<<"$\\pm$"<<errfakes[0]<<setw(3)<<"&"<<wgttotalbkg[0]<<"$\\pm$"<<errtotalbkg[0]<<setw(3)<<"&"<<wgtsignal[0]<<"$\\pm$"<<errsignal[0]<<setw(3)<<"&"<<wgtpredicted[0]<<"$\\pm$"<<errpredicted[0]<<setw(3)<<"&"<<numOfdata[0]<<"\\\\"<<endl;
  cout<<"\\hline"<<endl;
  cout<<"$M(\\ell\\ell)$            "<<"&"<<wgtpromptSS[1]<<"$\\pm$"<<errpromptSS[1]<<setw(3)<<"&"<<wgtVgam[1]<<"$\\pm$"<<errVgam[1]<<setw(3)<<"&"<<wgtQmisID[1]<<"$\\pm$"<<errQmisID[1]<<setw(3)<<"&"<<wgtfakes[1]<<"$\\pm$"<<errfakes[1]<<setw(3)<<"&"<<wgttotalbkg[1]<<"$\\pm$"<<errtotalbkg[1]<<setw(3)<<"&"<<wgtsignal[1]<<"$\\pm$"<<errsignal[1]<<setw(3)<<"&"<<wgtpredicted[1]<<"$\\pm$"<<errpredicted[1]<<setw(3)<<"&"<<numOfdata[1]<<"\\\\"<<endl;
  cout<<"\\hline"<<endl;
  cout<<"$M(l\_{1}jj)$             "<<"&"<<wgtpromptSS[2]<<"$\\pm$"<<errpromptSS[2]<<setw(3)<<"&"<<wgtVgam[2]<<"$\\pm$"<<errVgam[2]<<setw(3)<<"&"<<wgtQmisID[2]<<"$\\pm$"<<errQmisID[2]<<setw(3)<<"&"<<wgtfakes[2]<<"$\\pm$"<<errfakes[2]<<setw(3)<<"&"<<wgttotalbkg[2]<<"$\\pm$"<<errtotalbkg[2]<<setw(3)<<"&"<<wgtsignal[2]<<"$\\pm$"<<errsignal[2]<<setw(3)<<"&"<<wgtpredicted[2]<<"$\\pm$"<<errpredicted[2]<<setw(3)<<"&"<<numOfdata[2]<<"\\\\"<<endl;
  cout<<"\\hline"<<endl;
  cout<<"$M(all)$                  "<<"&"<<wgtpromptSS[3]<<"$\\pm$"<<errpromptSS[3]<<setw(3)<<"&"<<wgtVgam[3]<<"$\\pm$"<<errVgam[3]<<setw(3)<<"&"<<wgtQmisID[3]<<"$\\pm$"<<errQmisID[3]<<setw(3)<<"&"<<wgtfakes[3]<<"$\\pm$"<<errfakes[3]<<setw(3)<<"&"<<wgttotalbkg[3]<<"$\\pm$"<<errtotalbkg[3]<<setw(3)<<"&"<<wgtsignal[3]<<"$\\pm$"<<errsignal[3]<<setw(3)<<"&"<<wgtpredicted[3]<<"$\\pm$"<<errpredicted[3]<<setw(3)<<"&"<<numOfdata[3]<<"\\\\"<<endl;
  cout<<"\\hline"<<endl;
  cout<<"\\hline"<<endl;
  cout<<"---------------------------------------"<<endl;*/
  cout<<"&"<<numOfwgtmH260[3]<<"$\\pm$"<<sqrt(Err2OfwgtmH260[3])<<setw(3)<<
      "&"<<numOfwgtmH300[3]<<"$\\pm$"<<sqrt(Err2OfwgtmH300[3])<<setw(3)<<
      "&"<<numOfwgtmH400[3]<<"$\\pm$"<<sqrt(Err2OfwgtmH400[3])<<setw(3)<<
      "&"<<numOfwgtmH500[3]<<"$\\pm$"<<sqrt(Err2OfwgtmH500[3])<<setw(3)<<
      "&"<<numOfwgtnonres[3]<<"$\\pm$"<<sqrt(Err2Ofwgtnonres[3])<<"    \\\\"<<endl;
//end of manin func
}
