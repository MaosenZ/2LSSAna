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
#include "../../atlasstyle-00-03-05/AtlasStyle.C"
#include "../../atlasstyle-00-03-05/AtlasUtils.C"
using namespace std;
using namespace TMath;
void cutflow(){
  SetAtlasStyle();
  //Get trees and variables 
                           //MET  m_ll dR_l2j dR_l1j m_l1jj m_all
  Float_t fixed_cuts_min[6]={15,  70,  -1,  -1,   -1,   -1};
  Float_t fixed_cuts_max[6]={9999,9999 ,1.3,0.9,  300, 1000};

  TFile *f_signal=new TFile("output/dataMC_3jets/miniNtuple_nonres.root");
  TFile *f_data=new TFile("output/dataMC_3jets/miniNtuple_datacombined.root");
  TFile *f_promptSS=new TFile("output/dataMC_3jets/miniNtuple_promptSS.root");
  TFile *f_Vgam=new TFile("output/dataMC_3jets/miniNtuple_Vgam.root");
  TFile *f_QmisID=new TFile("output/dataMC_3jets/miniNtuple_QmisID_datacombined.root");
  TFile *f_FFApp_data=new TFile("output/dataMC_3jets/miniNtuple_FFApp_datacombined.root");
  TFile *f_FFQmis=new TFile("output/dataMC_3jets/miniNtuple_FFQmis_datacombined.root");
  TFile *f_FFApp_subtractions_QmisID=new TFile("output/dataMC_3jets/miniNtuple_FFApp_subtractions_QmisID.root");
  TFile *f_FFApp_subtractions_promptSS=new TFile("output/dataMC_3jets/miniNtuple_FFApp_subtractions_promptSS.root");

   TTree *signal=(TTree*)f_signal->Get("Tree");
  TTree *data=(TTree*)f_data->Get("Tree");
  TTree *promptSS=(TTree*)f_promptSS->Get("Tree");
  TTree *Vgam=(TTree*)f_Vgam->Get("Tree");
  TTree *QmisID=(TTree*)f_QmisID->Get("Tree");
  TTree *FFApp_data=(TTree*)f_FFApp_data->Get("Tree");
  TTree *FFQmis=(TTree*)f_FFQmis->Get("Tree");
  TTree *FFApp_subtractions_QmisID=(TTree*)f_FFApp_subtractions_QmisID->Get("Tree");
  TTree *FFApp_subtractions_promptSS=(TTree*)f_FFApp_subtractions_promptSS->Get("Tree");
  Float_t signal_met,promptSS_met,Vgam_met,QmisID_met,FFApp_data_met,FFApp_subtractions_promptSS_met,data_met,
          FFApp_subtractions_QmisID_met;
  Float_t signal_m_ll,promptSS_m_ll,Vgam_m_ll,QmisID_m_ll,FFApp_data_m_ll,FFApp_subtractions_promptSS_m_ll,data_m_ll,
          FFApp_subtractions_QmisID_m_ll;
  Float_t signal_m_l1jj,promptSS_m_l1jj,Vgam_m_l1jj,QmisID_m_l1jj,FFApp_data_m_l1jj,FFApp_subtractions_promptSS_m_l1jj,data_m_l1jj,
          FFApp_subtractions_QmisID_m_l1jj;
  Float_t signal_m_all,promptSS_m_all,Vgam_m_all,QmisID_m_all,FFApp_data_m_all,FFApp_subtractions_promptSS_m_all,data_m_all,
          FFApp_subtractions_QmisID_m_all;
  Float_t signal_mindR_l1j,promptSS_mindR_l1j,Vgam_mindR_l1j,QmisID_mindR_l1j,FFApp_data_mindR_l1j,FFApp_subtractions_promptSS_mindR_l1j,data_mindR_l1j,FFApp_subtractions_QmisID_mindR_l1j;
  Float_t signal_mindR_l2j,promptSS_mindR_l2j,Vgam_mindR_l2j,QmisID_mindR_l2j,FFApp_data_mindR_l2j,FFApp_subtractions_promptSS_mindR_l2j,data_mindR_l2j,FFApp_subtractions_QmisID_mindR_l2j;
  Double_t signal_weight,promptSS_weight,Vgam_weight,QmisID_weight,FFApp_data_weight,FFApp_subtractions_promptSS_weight,data_weight,
           FFApp_subtractions_QmisID_weight;
  Int_t signal_channel,promptSS_channel,Vgam_channel,QmisID_channel,FFApp_data_channel,FFApp_subtractions_promptSS_channel,data_channel,FFApp_subtractions_QmisID_channel;
  Int_t signal_numOfjet,promptSS_numOfjet,Vgam_numOfjet,QmisID_numOfjet,FFApp_data_numOfjet,FFApp_subtractions_promptSS_numOfjet,data_numOfjet,FFApp_subtractions_QmisID_numOfjet;

  signal->SetBranchAddress("MET",&signal_met);
  data->SetBranchAddress("MET",&data_met);
  promptSS->SetBranchAddress("MET",&promptSS_met);
  Vgam->SetBranchAddress("MET",&Vgam_met);
  QmisID->SetBranchAddress("MET",&QmisID_met);
  FFApp_data->SetBranchAddress("MET",&FFApp_data_met);
  FFApp_subtractions_promptSS->SetBranchAddress("MET",&FFApp_subtractions_promptSS_met);
  FFApp_subtractions_QmisID->SetBranchAddress("MET",&FFApp_subtractions_QmisID_met);

  signal->SetBranchAddress("m_ll",&signal_m_ll);
  data->SetBranchAddress("m_ll",&data_m_ll);
  promptSS->SetBranchAddress("m_ll",&promptSS_m_ll);
  Vgam->SetBranchAddress("m_ll",&Vgam_m_ll);
  QmisID->SetBranchAddress("m_ll",&QmisID_m_ll);
  FFApp_data->SetBranchAddress("m_ll",&FFApp_data_m_ll);
  FFApp_subtractions_promptSS->SetBranchAddress("m_ll",&FFApp_subtractions_promptSS_m_ll);
  FFApp_subtractions_QmisID->SetBranchAddress("m_ll",&FFApp_subtractions_QmisID_m_ll);

  signal->SetBranchAddress("m_l1jj",&signal_m_l1jj);
  data->SetBranchAddress("m_l1jj",&data_m_l1jj);
  promptSS->SetBranchAddress("m_l1jj",&promptSS_m_l1jj);
  Vgam->SetBranchAddress("m_l1jj",&Vgam_m_l1jj);
  QmisID->SetBranchAddress("m_l1jj",&QmisID_m_l1jj);
  FFApp_data->SetBranchAddress("m_l1jj",&FFApp_data_m_l1jj);
  FFApp_subtractions_promptSS->SetBranchAddress("m_l1jj",&FFApp_subtractions_promptSS_m_l1jj);
  FFApp_subtractions_QmisID->SetBranchAddress("m_l1jj",&FFApp_subtractions_QmisID_m_l1jj);

  signal->SetBranchAddress("m_all",&signal_m_all);
  data->SetBranchAddress("m_all",&data_m_all);
  promptSS->SetBranchAddress("m_all",&promptSS_m_all);
  Vgam->SetBranchAddress("m_all",&Vgam_m_all);
  QmisID->SetBranchAddress("m_all",&QmisID_m_all);
  FFApp_data->SetBranchAddress("m_all",&FFApp_data_m_all);
  FFApp_subtractions_promptSS->SetBranchAddress("m_all",&FFApp_subtractions_promptSS_m_all);
  FFApp_subtractions_QmisID->SetBranchAddress("m_all",&FFApp_subtractions_QmisID_m_all);

  signal->SetBranchAddress("mindR_l1j",&signal_mindR_l1j);
  data->SetBranchAddress("mindR_l1j",&data_mindR_l1j);
  promptSS->SetBranchAddress("mindR_l1j",&promptSS_mindR_l1j);
  Vgam->SetBranchAddress("mindR_l1j",&Vgam_mindR_l1j);
  QmisID->SetBranchAddress("mindR_l1j",&QmisID_mindR_l1j);
  FFApp_data->SetBranchAddress("mindR_l1j",&FFApp_data_mindR_l1j);
  FFApp_subtractions_promptSS->SetBranchAddress("mindR_l1j",&FFApp_subtractions_promptSS_mindR_l1j);
  FFApp_subtractions_QmisID->SetBranchAddress("mindR_l1j",&FFApp_subtractions_QmisID_mindR_l1j);

  signal->SetBranchAddress("mindR_l2j",&signal_mindR_l2j);
  data->SetBranchAddress("mindR_l2j",&data_mindR_l2j);
  promptSS->SetBranchAddress("mindR_l2j",&promptSS_mindR_l2j);
  Vgam->SetBranchAddress("mindR_l2j",&Vgam_mindR_l2j);
  QmisID->SetBranchAddress("mindR_l2j",&QmisID_mindR_l2j);
  FFApp_data->SetBranchAddress("mindR_l2j",&FFApp_data_mindR_l2j);
  FFApp_subtractions_promptSS->SetBranchAddress("mindR_l2j",&FFApp_subtractions_promptSS_mindR_l2j);
  FFApp_subtractions_QmisID->SetBranchAddress("mindR_l2j",&FFApp_subtractions_QmisID_mindR_l2j);

  signal->SetBranchAddress("weight",&signal_weight);
  data->SetBranchAddress("weight",&data_weight);
  promptSS->SetBranchAddress("weight",&promptSS_weight);
  Vgam->SetBranchAddress("weight",&Vgam_weight);
  QmisID->SetBranchAddress("weight",&QmisID_weight);
  FFApp_data->SetBranchAddress("weight",&FFApp_data_weight);
  FFApp_subtractions_promptSS->SetBranchAddress("weight",&FFApp_subtractions_promptSS_weight);
  FFApp_subtractions_QmisID->SetBranchAddress("weight",&FFApp_subtractions_QmisID_weight);

  signal->SetBranchAddress("channel",&signal_channel);
  data->SetBranchAddress("channel",&data_channel);
  promptSS->SetBranchAddress("channel",&promptSS_channel);
  Vgam->SetBranchAddress("channel",&Vgam_channel);
  QmisID->SetBranchAddress("channel",&QmisID_channel);
  FFApp_data->SetBranchAddress("channel",&FFApp_data_channel);
  FFApp_subtractions_promptSS->SetBranchAddress("channel",&FFApp_subtractions_promptSS_channel);
  FFApp_subtractions_QmisID->SetBranchAddress("channel",&FFApp_subtractions_QmisID_channel);

  signal->SetBranchAddress("numOfjet",&signal_numOfjet);
  data->SetBranchAddress("numOfjet",&data_numOfjet);
  promptSS->SetBranchAddress("numOfjet",&promptSS_numOfjet);
  Vgam->SetBranchAddress("numOfjet",&Vgam_numOfjet);
  QmisID->SetBranchAddress("numOfjet",&QmisID_numOfjet);
  FFApp_data->SetBranchAddress("numOfjet",&FFApp_data_numOfjet);
  FFApp_subtractions_promptSS->SetBranchAddress("numOfjet",&FFApp_subtractions_promptSS_numOfjet);
  FFApp_subtractions_QmisID->SetBranchAddress("numOfjet",&FFApp_subtractions_QmisID_numOfjet);

  Int_t numOfdata[6]={0},numOfsignal[6]={0},numOfpromptSS[6]={0},  numOfVgam[6]={0},numOfQmisID[6]={0},numOfFFApp_subtractions_promptSS[6]={0},
         numOfFFApp_data[6]={0}, numOfFFApp_subtractions_QmisID[6]={0};
  Double_t numOfwgtdata[6]={0},numOfwgtsignal[6]={0},numOfwgtpromptSS[6]={0},  numOfwgtVgam[6]={0},numOfwgtQmisID[6]={0},
           numOfwgtFFApp_subtractions_promptSS[6]={0},numOfwgtFFApp_data[6]={0},numOfwgtFFApp_subtractions_QmisID[6]={0};
  Double_t Err2Ofwgtdata[6]={0},Err2Ofwgtsignal[6]={0},Err2OfwgtpromptSS[6]={0},  Err2OfwgtVgam[6]={0},Err2OfwgtQmisID[6]={0},
            Err2OfwgtFFApp_subtractions_promptSS[6]={0},Err2OfwgtFFApp_data[6]={0},Err2OfwgtFFApp_subtractions_QmisID[6]={0};
  Double_t sigs[6]={0}, sigpurs[6]={0},totalbkg[6]={0};
  Double_t wgtdata[6],wgtpromptSS[6],wgtVgam[6],wgtQmisID[6],wgtfakes[6],wgtpredicted[6],wgtdata[6],wgtsignal[6];
  Double_t errdata[6],errpromptSS[6],errVgam[6],errQmisID[6],errfakes[6],errpredicted[6],errtotalbkg[6],errdata[6],errsignal[6];
  for(Int_t index=0;index<6;index++){
      for(Long64_t entry=0; entry<signal->GetEntries();entry++) {
          signal->GetEntry(entry);
          if(signal_channel!=3)continue;
          if(index==0 &&signal_met>fixed_cuts_min[0]&&signal_met<fixed_cuts_max[0]){
             numOfsignal[index]++;
             numOfwgtsignal[index]+=signal_weight; Err2Ofwgtsignal[index]+=signal_weight*signal_weight;
          }
          if(index==1 && signal_met>fixed_cuts_min[0]&&signal_met<fixed_cuts_max[0] &&
                         signal_m_ll>fixed_cuts_min[1]&&signal_m_ll<fixed_cuts_max[1]){
             numOfsignal[index]++;
             numOfwgtsignal[index]+=signal_weight; Err2Ofwgtsignal[index]+=signal_weight*signal_weight;
          }
          if(index==2 &&signal_met>fixed_cuts_min[0]&&signal_met<fixed_cuts_max[0] &&
                         signal_m_ll>fixed_cuts_min[1]&&signal_m_ll<fixed_cuts_max[1] &&
                         signal_mindR_l2j>fixed_cuts_min[2]&&signal_mindR_l2j<fixed_cuts_max[2]){
             numOfsignal[index]++;
             numOfwgtsignal[index]+=signal_weight; Err2Ofwgtsignal[index]+=signal_weight*signal_weight;

          }
          if(index==3&& signal_met>fixed_cuts_min[0]&&signal_met<fixed_cuts_max[0] &&
                         signal_m_ll>fixed_cuts_min[1]&&signal_m_ll<fixed_cuts_max[1] &&
                         signal_mindR_l2j>fixed_cuts_min[2]&&signal_mindR_l2j<fixed_cuts_max[2] &&
                         signal_mindR_l1j>fixed_cuts_min[3]&&signal_mindR_l1j<fixed_cuts_max[3]){
              numOfsignal[index]++;
             numOfwgtsignal[index]+=signal_weight; Err2Ofwgtsignal[index]+=signal_weight*signal_weight;
          }
          if(index==4&& signal_met>fixed_cuts_min[0]&&signal_met<fixed_cuts_max[0] &&
                         signal_m_ll>fixed_cuts_min[1]&&signal_m_ll<fixed_cuts_max[1] &&
                         signal_mindR_l2j>fixed_cuts_min[2]&&signal_mindR_l2j<fixed_cuts_max[2] &&
                         signal_mindR_l1j>fixed_cuts_min[3]&&signal_mindR_l1j<fixed_cuts_max[3] &&
                         signal_m_l1jj>fixed_cuts_min[4]&&signal_m_l1jj<fixed_cuts_max[4] ){
             numOfsignal[index]++;
             numOfwgtsignal[index]+=signal_weight; Err2Ofwgtsignal[index]+=signal_weight*signal_weight;
          }
          if(index==5 && signal_met>fixed_cuts_min[0]&&signal_met<fixed_cuts_max[0] &&
                         signal_m_ll>fixed_cuts_min[1]&&signal_m_ll<fixed_cuts_max[1] &&
                         signal_mindR_l2j>fixed_cuts_min[2]&&signal_mindR_l2j<fixed_cuts_max[2] &&
                         signal_mindR_l1j>fixed_cuts_min[3]&&signal_mindR_l1j<fixed_cuts_max[3] &&
                         signal_m_l1jj>fixed_cuts_min[4]&&signal_m_l1jj<fixed_cuts_max[4] &&
                         signal_m_all>fixed_cuts_min[5]&&signal_m_all<fixed_cuts_max[5]){
             numOfsignal[index]++;
             numOfwgtsignal[index]+=signal_weight; Err2Ofwgtsignal[index]+=signal_weight*signal_weight;
          } 
      }

      for(Long64_t entry=0; entry<data->GetEntries();entry++) {
          data->GetEntry(entry);
          if(data_channel!=3)continue;
          if(index==0 &&data_met>fixed_cuts_min[0]&&data_met<fixed_cuts_max[0]){
             numOfdata[index]++;
             numOfwgtdata[index]+=data_weight; Err2Ofwgtdata[index]+=data_weight*data_weight;
          }
          if(index==1 && data_met>fixed_cuts_min[0]&&data_met<fixed_cuts_max[0] &&
                         data_m_ll>fixed_cuts_min[1]&&data_m_ll<fixed_cuts_max[1]){
             numOfdata[index]++;
             numOfwgtdata[index]+=data_weight; Err2Ofwgtdata[index]+=data_weight*data_weight;
          }
          if(index==2 &&data_met>fixed_cuts_min[0]&&data_met<fixed_cuts_max[0] &&
                         data_m_ll>fixed_cuts_min[1]&&data_m_ll<fixed_cuts_max[1] &&
                         data_mindR_l2j>fixed_cuts_min[2]&&data_mindR_l2j<fixed_cuts_max[2]){
             numOfdata[index]++;
             numOfwgtdata[index]+=data_weight; Err2Ofwgtdata[index]+=data_weight*data_weight;

          }
          if(index==3&& data_met>fixed_cuts_min[0]&&data_met<fixed_cuts_max[0] &&
                         data_m_ll>fixed_cuts_min[1]&&data_m_ll<fixed_cuts_max[1] &&
                         data_mindR_l2j>fixed_cuts_min[2]&&data_mindR_l2j<fixed_cuts_max[2] &&
                         data_mindR_l1j>fixed_cuts_min[3]&&data_mindR_l1j<fixed_cuts_max[3]){
              numOfdata[index]++;
             numOfwgtdata[index]+=data_weight; Err2Ofwgtdata[index]+=data_weight*data_weight;
          }
          if(index==4&& data_met>fixed_cuts_min[0]&&data_met<fixed_cuts_max[0] &&
                         data_m_ll>fixed_cuts_min[1]&&data_m_ll<fixed_cuts_max[1] &&
                         data_mindR_l2j>fixed_cuts_min[2]&&data_mindR_l2j<fixed_cuts_max[2] &&
                         data_mindR_l1j>fixed_cuts_min[3]&&data_mindR_l1j<fixed_cuts_max[3] &&
                         data_m_l1jj>fixed_cuts_min[4]&&data_m_l1jj<fixed_cuts_max[4] ){
             numOfdata[index]++;
             numOfwgtdata[index]+=data_weight; Err2Ofwgtdata[index]+=data_weight*data_weight;
          }
          if(index==5 && data_met>fixed_cuts_min[0]&&data_met<fixed_cuts_max[0] &&
                         data_m_ll>fixed_cuts_min[1]&&data_m_ll<fixed_cuts_max[1] &&
                         data_mindR_l2j>fixed_cuts_min[2]&&data_mindR_l2j<fixed_cuts_max[2] &&
                         data_mindR_l1j>fixed_cuts_min[3]&&data_mindR_l1j<fixed_cuts_max[3] &&
                         data_m_l1jj>fixed_cuts_min[4]&&data_m_l1jj<fixed_cuts_max[4] &&
                         data_m_all>fixed_cuts_min[5]&&data_m_all<fixed_cuts_max[5]){
             numOfdata[index]++;
             numOfwgtdata[index]+=data_weight; Err2Ofwgtdata[index]+=data_weight*data_weight;
          } 
      }
      
      for(Long64_t entry=0; entry<promptSS->GetEntries();entry++) {
          promptSS->GetEntry(entry);
          if(promptSS_channel!=3)continue;
          if(index==0 &&promptSS_met>fixed_cuts_min[0]&&promptSS_met<fixed_cuts_max[0]){
             numOfpromptSS[index]++;
             numOfwgtpromptSS[index]+=promptSS_weight; Err2OfwgtpromptSS[index]+=promptSS_weight*promptSS_weight;
          }
          if(index==1 && promptSS_met>fixed_cuts_min[0]&&promptSS_met<fixed_cuts_max[0] &&
                         promptSS_m_ll>fixed_cuts_min[1]&&promptSS_m_ll<fixed_cuts_max[1]){
             numOfpromptSS[index]++;
             numOfwgtpromptSS[index]+=promptSS_weight; Err2OfwgtpromptSS[index]+=promptSS_weight*promptSS_weight;
          }
          if(index==2 &&promptSS_met>fixed_cuts_min[0]&&promptSS_met<fixed_cuts_max[0] &&
                         promptSS_m_ll>fixed_cuts_min[1]&&promptSS_m_ll<fixed_cuts_max[1] &&
                         promptSS_mindR_l2j>fixed_cuts_min[2]&&promptSS_mindR_l2j<fixed_cuts_max[2]){
             numOfpromptSS[index]++;
             numOfwgtpromptSS[index]+=promptSS_weight; Err2OfwgtpromptSS[index]+=promptSS_weight*promptSS_weight;

          }
          if(index==3&& promptSS_met>fixed_cuts_min[0]&&promptSS_met<fixed_cuts_max[0] &&
                         promptSS_m_ll>fixed_cuts_min[1]&&promptSS_m_ll<fixed_cuts_max[1] &&
                         promptSS_mindR_l2j>fixed_cuts_min[2]&&promptSS_mindR_l2j<fixed_cuts_max[2] &&
                         promptSS_mindR_l1j>fixed_cuts_min[3]&&promptSS_mindR_l1j<fixed_cuts_max[3]){
              numOfpromptSS[index]++;
             numOfwgtpromptSS[index]+=promptSS_weight; Err2OfwgtpromptSS[index]+=promptSS_weight*promptSS_weight;
          }
          if(index==4&& promptSS_met>fixed_cuts_min[0]&&promptSS_met<fixed_cuts_max[0] &&
                         promptSS_m_ll>fixed_cuts_min[1]&&promptSS_m_ll<fixed_cuts_max[1] &&
                         promptSS_mindR_l2j>fixed_cuts_min[2]&&promptSS_mindR_l2j<fixed_cuts_max[2] &&
                         promptSS_mindR_l1j>fixed_cuts_min[3]&&promptSS_mindR_l1j<fixed_cuts_max[3] &&
                         promptSS_m_l1jj>fixed_cuts_min[4]&&promptSS_m_l1jj<fixed_cuts_max[4] ){
             numOfpromptSS[index]++;
             numOfwgtpromptSS[index]+=promptSS_weight; Err2OfwgtpromptSS[index]+=promptSS_weight*promptSS_weight;
          }
          if(index==5 && promptSS_met>fixed_cuts_min[0]&&promptSS_met<fixed_cuts_max[0] &&
                         promptSS_m_ll>fixed_cuts_min[1]&&promptSS_m_ll<fixed_cuts_max[1] &&
                         promptSS_mindR_l2j>fixed_cuts_min[2]&&promptSS_mindR_l2j<fixed_cuts_max[2] &&
                         promptSS_mindR_l1j>fixed_cuts_min[3]&&promptSS_mindR_l1j<fixed_cuts_max[3] &&
                         promptSS_m_l1jj>fixed_cuts_min[4]&&promptSS_m_l1jj<fixed_cuts_max[4] &&
                         promptSS_m_all>fixed_cuts_min[5]&&promptSS_m_all<fixed_cuts_max[5]){
             numOfpromptSS[index]++;
             numOfwgtpromptSS[index]+=promptSS_weight; Err2OfwgtpromptSS[index]+=promptSS_weight*promptSS_weight;
          } 
      }
      
      for(Long64_t entry=0; entry<Vgam->GetEntries();entry++) {
          Vgam->GetEntry(entry);
          if(Vgam_channel!=3)continue;
          if(index==0 &&Vgam_met>fixed_cuts_min[0]&&Vgam_met<fixed_cuts_max[0]){
             numOfVgam[index]++;
             numOfwgtVgam[index]+=Vgam_weight; Err2OfwgtVgam[index]+=Vgam_weight*Vgam_weight;
          }
          if(index==1 && Vgam_met>fixed_cuts_min[0]&&Vgam_met<fixed_cuts_max[0] &&
                         Vgam_m_ll>fixed_cuts_min[1]&&Vgam_m_ll<fixed_cuts_max[1]){
             numOfVgam[index]++;
             numOfwgtVgam[index]+=Vgam_weight; Err2OfwgtVgam[index]+=Vgam_weight*Vgam_weight;
          }
          if(index==2 &&Vgam_met>fixed_cuts_min[0]&&Vgam_met<fixed_cuts_max[0] &&
                         Vgam_m_ll>fixed_cuts_min[1]&&Vgam_m_ll<fixed_cuts_max[1] &&
                         Vgam_mindR_l2j>fixed_cuts_min[2]&&Vgam_mindR_l2j<fixed_cuts_max[2]){
             numOfVgam[index]++;
             numOfwgtVgam[index]+=Vgam_weight; Err2OfwgtVgam[index]+=Vgam_weight*Vgam_weight;

          }
          if(index==3&& Vgam_met>fixed_cuts_min[0]&&Vgam_met<fixed_cuts_max[0] &&
                         Vgam_m_ll>fixed_cuts_min[1]&&Vgam_m_ll<fixed_cuts_max[1] &&
                         Vgam_mindR_l2j>fixed_cuts_min[2]&&Vgam_mindR_l2j<fixed_cuts_max[2] &&
                         Vgam_mindR_l1j>fixed_cuts_min[3]&&Vgam_mindR_l1j<fixed_cuts_max[3]){
              numOfVgam[index]++;
             numOfwgtVgam[index]+=Vgam_weight; Err2OfwgtVgam[index]+=Vgam_weight*Vgam_weight;
          }
          if(index==4&& Vgam_met>fixed_cuts_min[0]&&Vgam_met<fixed_cuts_max[0] &&
                         Vgam_m_ll>fixed_cuts_min[1]&&Vgam_m_ll<fixed_cuts_max[1] &&
                         Vgam_mindR_l2j>fixed_cuts_min[2]&&Vgam_mindR_l2j<fixed_cuts_max[2] &&
                         Vgam_mindR_l1j>fixed_cuts_min[3]&&Vgam_mindR_l1j<fixed_cuts_max[3] &&
                         Vgam_m_l1jj>fixed_cuts_min[4]&&Vgam_m_l1jj<fixed_cuts_max[4] ){
             numOfVgam[index]++;
             numOfwgtVgam[index]+=Vgam_weight; Err2OfwgtVgam[index]+=Vgam_weight*Vgam_weight;
          }
          if(index==5 && Vgam_met>fixed_cuts_min[0]&&Vgam_met<fixed_cuts_max[0] &&
                         Vgam_m_ll>fixed_cuts_min[1]&&Vgam_m_ll<fixed_cuts_max[1] &&
                         Vgam_mindR_l2j>fixed_cuts_min[2]&&Vgam_mindR_l2j<fixed_cuts_max[2] &&
                         Vgam_mindR_l1j>fixed_cuts_min[3]&&Vgam_mindR_l1j<fixed_cuts_max[3] &&
                         Vgam_m_l1jj>fixed_cuts_min[4]&&Vgam_m_l1jj<fixed_cuts_max[4] &&
                         Vgam_m_all>fixed_cuts_min[5]&&Vgam_m_all<fixed_cuts_max[5]){
             numOfVgam[index]++;
             numOfwgtVgam[index]+=Vgam_weight; Err2OfwgtVgam[index]+=Vgam_weight*Vgam_weight;
          } 
      }
        
      for(Long64_t entry=0; entry<QmisID->GetEntries();entry++) {
          QmisID->GetEntry(entry);
          if(QmisID_channel!=3)continue;
          if(index==0 &&QmisID_met>fixed_cuts_min[0]&&QmisID_met<fixed_cuts_max[0]){
             numOfQmisID[index]++;
             numOfwgtQmisID[index]+=QmisID_weight; Err2OfwgtQmisID[index]+=QmisID_weight*QmisID_weight;
          }
          if(index==1 && QmisID_met>fixed_cuts_min[0]&&QmisID_met<fixed_cuts_max[0] &&
                         QmisID_m_ll>fixed_cuts_min[1]&&QmisID_m_ll<fixed_cuts_max[1]){
             numOfQmisID[index]++;
             numOfwgtQmisID[index]+=QmisID_weight; Err2OfwgtQmisID[index]+=QmisID_weight*QmisID_weight;
          }
          if(index==2 &&QmisID_met>fixed_cuts_min[0]&&QmisID_met<fixed_cuts_max[0] &&
                         QmisID_m_ll>fixed_cuts_min[1]&&QmisID_m_ll<fixed_cuts_max[1] &&
                         QmisID_mindR_l2j>fixed_cuts_min[2]&&QmisID_mindR_l2j<fixed_cuts_max[2]){
             numOfQmisID[index]++;
             numOfwgtQmisID[index]+=QmisID_weight; Err2OfwgtQmisID[index]+=QmisID_weight*QmisID_weight;

          }
          if(index==3&& QmisID_met>fixed_cuts_min[0]&&QmisID_met<fixed_cuts_max[0] &&
                         QmisID_m_ll>fixed_cuts_min[1]&&QmisID_m_ll<fixed_cuts_max[1] &&
                         QmisID_mindR_l2j>fixed_cuts_min[2]&&QmisID_mindR_l2j<fixed_cuts_max[2] &&
                         QmisID_mindR_l1j>fixed_cuts_min[3]&&QmisID_mindR_l1j<fixed_cuts_max[3]){
              numOfQmisID[index]++;
             numOfwgtQmisID[index]+=QmisID_weight; Err2OfwgtQmisID[index]+=QmisID_weight*QmisID_weight;
          }
          if(index==4&& QmisID_met>fixed_cuts_min[0]&&QmisID_met<fixed_cuts_max[0] &&
                         QmisID_m_ll>fixed_cuts_min[1]&&QmisID_m_ll<fixed_cuts_max[1] &&
                         QmisID_mindR_l2j>fixed_cuts_min[2]&&QmisID_mindR_l2j<fixed_cuts_max[2] &&
                         QmisID_mindR_l1j>fixed_cuts_min[3]&&QmisID_mindR_l1j<fixed_cuts_max[3] &&
                         QmisID_m_l1jj>fixed_cuts_min[4]&&QmisID_m_l1jj<fixed_cuts_max[4] ){
             numOfQmisID[index]++;
             numOfwgtQmisID[index]+=QmisID_weight; Err2OfwgtQmisID[index]+=QmisID_weight*QmisID_weight;
          }
          if(index==5 && QmisID_met>fixed_cuts_min[0]&&QmisID_met<fixed_cuts_max[0] &&
                         QmisID_m_ll>fixed_cuts_min[1]&&QmisID_m_ll<fixed_cuts_max[1] &&
                         QmisID_mindR_l2j>fixed_cuts_min[2]&&QmisID_mindR_l2j<fixed_cuts_max[2] &&
                         QmisID_mindR_l1j>fixed_cuts_min[3]&&QmisID_mindR_l1j<fixed_cuts_max[3] &&
                         QmisID_m_l1jj>fixed_cuts_min[4]&&QmisID_m_l1jj<fixed_cuts_max[4] &&
                         QmisID_m_all>fixed_cuts_min[5]&&QmisID_m_all<fixed_cuts_max[5]){
             numOfQmisID[index]++;
             numOfwgtQmisID[index]+=QmisID_weight; Err2OfwgtQmisID[index]+=QmisID_weight*QmisID_weight;
          } 
      }
      
      for(Long64_t entry=0; entry<FFApp_data->GetEntries();entry++) {
          FFApp_data->GetEntry(entry);
          if(FFApp_data_channel!=3)continue;
          if(index==0 &&FFApp_data_met>fixed_cuts_min[0]&&FFApp_data_met<fixed_cuts_max[0]){
             numOfFFApp_data[index]++;
             numOfwgtFFApp_data[index]+=FFApp_data_weight; Err2OfwgtFFApp_data[index]+=FFApp_data_weight*FFApp_data_weight;
          }
          if(index==1 && FFApp_data_met>fixed_cuts_min[0]&&FFApp_data_met<fixed_cuts_max[0] &&
                         FFApp_data_m_ll>fixed_cuts_min[1]&&FFApp_data_m_ll<fixed_cuts_max[1]){
             numOfFFApp_data[index]++;
             numOfwgtFFApp_data[index]+=FFApp_data_weight; Err2OfwgtFFApp_data[index]+=FFApp_data_weight*FFApp_data_weight;
          }
          if(index==2 &&FFApp_data_met>fixed_cuts_min[0]&&FFApp_data_met<fixed_cuts_max[0] &&
                         FFApp_data_m_ll>fixed_cuts_min[1]&&FFApp_data_m_ll<fixed_cuts_max[1] &&
                         FFApp_data_mindR_l2j>fixed_cuts_min[2]&&FFApp_data_mindR_l2j<fixed_cuts_max[2]){
             numOfFFApp_data[index]++;
             numOfwgtFFApp_data[index]+=FFApp_data_weight; Err2OfwgtFFApp_data[index]+=FFApp_data_weight*FFApp_data_weight;

          }
          if(index==3&& FFApp_data_met>fixed_cuts_min[0]&&FFApp_data_met<fixed_cuts_max[0] &&
                         FFApp_data_m_ll>fixed_cuts_min[1]&&FFApp_data_m_ll<fixed_cuts_max[1] &&
                         FFApp_data_mindR_l2j>fixed_cuts_min[2]&&FFApp_data_mindR_l2j<fixed_cuts_max[2] &&
                         FFApp_data_mindR_l1j>fixed_cuts_min[3]&&FFApp_data_mindR_l1j<fixed_cuts_max[3]){
              numOfFFApp_data[index]++;
             numOfwgtFFApp_data[index]+=FFApp_data_weight; Err2OfwgtFFApp_data[index]+=FFApp_data_weight*FFApp_data_weight;
          }
          if(index==4&& FFApp_data_met>fixed_cuts_min[0]&&FFApp_data_met<fixed_cuts_max[0] &&
                         FFApp_data_m_ll>fixed_cuts_min[1]&&FFApp_data_m_ll<fixed_cuts_max[1] &&
                         FFApp_data_mindR_l2j>fixed_cuts_min[2]&&FFApp_data_mindR_l2j<fixed_cuts_max[2] &&
                         FFApp_data_mindR_l1j>fixed_cuts_min[3]&&FFApp_data_mindR_l1j<fixed_cuts_max[3] &&
                         FFApp_data_m_l1jj>fixed_cuts_min[4]&&FFApp_data_m_l1jj<fixed_cuts_max[4] ){
             numOfFFApp_data[index]++;
             numOfwgtFFApp_data[index]+=FFApp_data_weight; Err2OfwgtFFApp_data[index]+=FFApp_data_weight*FFApp_data_weight;
          }
          if(index==5 && FFApp_data_met>fixed_cuts_min[0]&&FFApp_data_met<fixed_cuts_max[0] &&
                         FFApp_data_m_ll>fixed_cuts_min[1]&&FFApp_data_m_ll<fixed_cuts_max[1] &&
                         FFApp_data_mindR_l2j>fixed_cuts_min[2]&&FFApp_data_mindR_l2j<fixed_cuts_max[2] &&
                         FFApp_data_mindR_l1j>fixed_cuts_min[3]&&FFApp_data_mindR_l1j<fixed_cuts_max[3] &&
                         FFApp_data_m_l1jj>fixed_cuts_min[4]&&FFApp_data_m_l1jj<fixed_cuts_max[4] &&
                         FFApp_data_m_all>fixed_cuts_min[5]&&FFApp_data_m_all<fixed_cuts_max[5]){
             numOfFFApp_data[index]++;
             numOfwgtFFApp_data[index]+=FFApp_data_weight; Err2OfwgtFFApp_data[index]+=FFApp_data_weight*FFApp_data_weight;
          } 
      }
      
      for(Long64_t entry=0; entry<FFApp_subtractions_QmisID->GetEntries();entry++) {
          FFApp_subtractions_QmisID->GetEntry(entry);
          if(FFApp_subtractions_QmisID_channel!=3)continue;
          if(index==0 &&FFApp_subtractions_QmisID_met>fixed_cuts_min[0]&&FFApp_subtractions_QmisID_met<fixed_cuts_max[0]){
             numOfFFApp_subtractions_QmisID[index]++;
             numOfwgtFFApp_subtractions_QmisID[index]+=FFApp_subtractions_QmisID_weight; Err2OfwgtFFApp_subtractions_QmisID[index]+=FFApp_subtractions_QmisID_weight*FFApp_subtractions_QmisID_weight;
          }
          if(index==1 && FFApp_subtractions_QmisID_met>fixed_cuts_min[0]&&FFApp_subtractions_QmisID_met<fixed_cuts_max[0] &&
                         FFApp_subtractions_QmisID_m_ll>fixed_cuts_min[1]&&FFApp_subtractions_QmisID_m_ll<fixed_cuts_max[1]){
             numOfFFApp_subtractions_QmisID[index]++;
             numOfwgtFFApp_subtractions_QmisID[index]+=FFApp_subtractions_QmisID_weight; Err2OfwgtFFApp_subtractions_QmisID[index]+=FFApp_subtractions_QmisID_weight*FFApp_subtractions_QmisID_weight;
          }
          if(index==2 &&FFApp_subtractions_QmisID_met>fixed_cuts_min[0]&&FFApp_subtractions_QmisID_met<fixed_cuts_max[0] &&
                         FFApp_subtractions_QmisID_m_ll>fixed_cuts_min[1]&&FFApp_subtractions_QmisID_m_ll<fixed_cuts_max[1] &&
                         FFApp_subtractions_QmisID_mindR_l2j>fixed_cuts_min[2]&&FFApp_subtractions_QmisID_mindR_l2j<fixed_cuts_max[2]){
             numOfFFApp_subtractions_QmisID[index]++;
             numOfwgtFFApp_subtractions_QmisID[index]+=FFApp_subtractions_QmisID_weight; Err2OfwgtFFApp_subtractions_QmisID[index]+=FFApp_subtractions_QmisID_weight*FFApp_subtractions_QmisID_weight;

          }
          if(index==3&& FFApp_subtractions_QmisID_met>fixed_cuts_min[0]&&FFApp_subtractions_QmisID_met<fixed_cuts_max[0] &&
                         FFApp_subtractions_QmisID_m_ll>fixed_cuts_min[1]&&FFApp_subtractions_QmisID_m_ll<fixed_cuts_max[1] &&
                         FFApp_subtractions_QmisID_mindR_l2j>fixed_cuts_min[2]&&FFApp_subtractions_QmisID_mindR_l2j<fixed_cuts_max[2] &&
                         FFApp_subtractions_QmisID_mindR_l1j>fixed_cuts_min[3]&&FFApp_subtractions_QmisID_mindR_l1j<fixed_cuts_max[3]){
              numOfFFApp_subtractions_QmisID[index]++;
             numOfwgtFFApp_subtractions_QmisID[index]+=FFApp_subtractions_QmisID_weight; Err2OfwgtFFApp_subtractions_QmisID[index]+=FFApp_subtractions_QmisID_weight*FFApp_subtractions_QmisID_weight;
          }
          if(index==4&& FFApp_subtractions_QmisID_met>fixed_cuts_min[0]&&FFApp_subtractions_QmisID_met<fixed_cuts_max[0] &&
                         FFApp_subtractions_QmisID_m_ll>fixed_cuts_min[1]&&FFApp_subtractions_QmisID_m_ll<fixed_cuts_max[1] &&
                         FFApp_subtractions_QmisID_mindR_l2j>fixed_cuts_min[2]&&FFApp_subtractions_QmisID_mindR_l2j<fixed_cuts_max[2] &&
                         FFApp_subtractions_QmisID_mindR_l1j>fixed_cuts_min[3]&&FFApp_subtractions_QmisID_mindR_l1j<fixed_cuts_max[3] &&
                         FFApp_subtractions_QmisID_m_l1jj>fixed_cuts_min[4]&&FFApp_subtractions_QmisID_m_l1jj<fixed_cuts_max[4] ){
             numOfFFApp_subtractions_QmisID[index]++;
             numOfwgtFFApp_subtractions_QmisID[index]+=FFApp_subtractions_QmisID_weight; Err2OfwgtFFApp_subtractions_QmisID[index]+=FFApp_subtractions_QmisID_weight*FFApp_subtractions_QmisID_weight;
          }
          if(index==5 && FFApp_subtractions_QmisID_met>fixed_cuts_min[0]&&FFApp_subtractions_QmisID_met<fixed_cuts_max[0] &&
                         FFApp_subtractions_QmisID_m_ll>fixed_cuts_min[1]&&FFApp_subtractions_QmisID_m_ll<fixed_cuts_max[1] &&
                         FFApp_subtractions_QmisID_mindR_l2j>fixed_cuts_min[2]&&FFApp_subtractions_QmisID_mindR_l2j<fixed_cuts_max[2] &&
                         FFApp_subtractions_QmisID_mindR_l1j>fixed_cuts_min[3]&&FFApp_subtractions_QmisID_mindR_l1j<fixed_cuts_max[3] &&
                         FFApp_subtractions_QmisID_m_l1jj>fixed_cuts_min[4]&&FFApp_subtractions_QmisID_m_l1jj<fixed_cuts_max[4] &&
                         FFApp_subtractions_QmisID_m_all>fixed_cuts_min[5]&&FFApp_subtractions_QmisID_m_all<fixed_cuts_max[5]){
             numOfFFApp_subtractions_QmisID[index]++;
             numOfwgtFFApp_subtractions_QmisID[index]+=FFApp_subtractions_QmisID_weight; Err2OfwgtFFApp_subtractions_QmisID[index]+=FFApp_subtractions_QmisID_weight*FFApp_subtractions_QmisID_weight;
          } 
      }
      
      for(Long64_t entry=0; entry<FFApp_subtractions_promptSS->GetEntries();entry++) {
          FFApp_subtractions_promptSS->GetEntry(entry);
          if(FFApp_subtractions_promptSS_channel!=3)continue;
          if(index==0 &&FFApp_subtractions_promptSS_met>fixed_cuts_min[0]&&FFApp_subtractions_promptSS_met<fixed_cuts_max[0]){
             numOfFFApp_subtractions_promptSS[index]++;
             numOfwgtFFApp_subtractions_promptSS[index]+=FFApp_subtractions_promptSS_weight; Err2OfwgtFFApp_subtractions_promptSS[index]+=FFApp_subtractions_promptSS_weight*FFApp_subtractions_promptSS_weight;
          }
          if(index==1 && FFApp_subtractions_promptSS_met>fixed_cuts_min[0]&&FFApp_subtractions_promptSS_met<fixed_cuts_max[0] &&
                         FFApp_subtractions_promptSS_m_ll>fixed_cuts_min[1]&&FFApp_subtractions_promptSS_m_ll<fixed_cuts_max[1]){
             numOfFFApp_subtractions_promptSS[index]++;
             numOfwgtFFApp_subtractions_promptSS[index]+=FFApp_subtractions_promptSS_weight; Err2OfwgtFFApp_subtractions_promptSS[index]+=FFApp_subtractions_promptSS_weight*FFApp_subtractions_promptSS_weight;
          }
          if(index==2 &&FFApp_subtractions_promptSS_met>fixed_cuts_min[0]&&FFApp_subtractions_promptSS_met<fixed_cuts_max[0] &&
                         FFApp_subtractions_promptSS_m_ll>fixed_cuts_min[1]&&FFApp_subtractions_promptSS_m_ll<fixed_cuts_max[1] &&
                         FFApp_subtractions_promptSS_mindR_l2j>fixed_cuts_min[2]&&FFApp_subtractions_promptSS_mindR_l2j<fixed_cuts_max[2]){
             numOfFFApp_subtractions_promptSS[index]++;
             numOfwgtFFApp_subtractions_promptSS[index]+=FFApp_subtractions_promptSS_weight; Err2OfwgtFFApp_subtractions_promptSS[index]+=FFApp_subtractions_promptSS_weight*FFApp_subtractions_promptSS_weight;

          }
          if(index==3&& FFApp_subtractions_promptSS_met>fixed_cuts_min[0]&&FFApp_subtractions_promptSS_met<fixed_cuts_max[0] &&
                         FFApp_subtractions_promptSS_m_ll>fixed_cuts_min[1]&&FFApp_subtractions_promptSS_m_ll<fixed_cuts_max[1] &&
                         FFApp_subtractions_promptSS_mindR_l2j>fixed_cuts_min[2]&&FFApp_subtractions_promptSS_mindR_l2j<fixed_cuts_max[2] &&
                         FFApp_subtractions_promptSS_mindR_l1j>fixed_cuts_min[3]&&FFApp_subtractions_promptSS_mindR_l1j<fixed_cuts_max[3]){
              numOfFFApp_subtractions_promptSS[index]++;
             numOfwgtFFApp_subtractions_promptSS[index]+=FFApp_subtractions_promptSS_weight; Err2OfwgtFFApp_subtractions_promptSS[index]+=FFApp_subtractions_promptSS_weight*FFApp_subtractions_promptSS_weight;
          }
          if(index==4&& FFApp_subtractions_promptSS_met>fixed_cuts_min[0]&&FFApp_subtractions_promptSS_met<fixed_cuts_max[0] &&
                         FFApp_subtractions_promptSS_m_ll>fixed_cuts_min[1]&&FFApp_subtractions_promptSS_m_ll<fixed_cuts_max[1] &&
                         FFApp_subtractions_promptSS_mindR_l2j>fixed_cuts_min[2]&&FFApp_subtractions_promptSS_mindR_l2j<fixed_cuts_max[2] &&
                         FFApp_subtractions_promptSS_mindR_l1j>fixed_cuts_min[3]&&FFApp_subtractions_promptSS_mindR_l1j<fixed_cuts_max[3] &&
                         FFApp_subtractions_promptSS_m_l1jj>fixed_cuts_min[4]&&FFApp_subtractions_promptSS_m_l1jj<fixed_cuts_max[4] ){
             numOfFFApp_subtractions_promptSS[index]++;
             numOfwgtFFApp_subtractions_promptSS[index]+=FFApp_subtractions_promptSS_weight; Err2OfwgtFFApp_subtractions_promptSS[index]+=FFApp_subtractions_promptSS_weight*FFApp_subtractions_promptSS_weight;
          }
          if(index==5 && FFApp_subtractions_promptSS_met>fixed_cuts_min[0]&&FFApp_subtractions_promptSS_met<fixed_cuts_max[0] &&
                         FFApp_subtractions_promptSS_m_ll>fixed_cuts_min[1]&&FFApp_subtractions_promptSS_m_ll<fixed_cuts_max[1] &&
                         FFApp_subtractions_promptSS_mindR_l2j>fixed_cuts_min[2]&&FFApp_subtractions_promptSS_mindR_l2j<fixed_cuts_max[2] &&
                         FFApp_subtractions_promptSS_mindR_l1j>fixed_cuts_min[3]&&FFApp_subtractions_promptSS_mindR_l1j<fixed_cuts_max[3] &&
                         FFApp_subtractions_promptSS_m_l1jj>fixed_cuts_min[4]&&FFApp_subtractions_promptSS_m_l1jj<fixed_cuts_max[4] &&
                         FFApp_subtractions_promptSS_m_all>fixed_cuts_min[5]&&FFApp_subtractions_promptSS_m_all<fixed_cuts_max[5]){
             numOfFFApp_subtractions_promptSS[index]++;
             numOfwgtFFApp_subtractions_promptSS[index]+=FFApp_subtractions_promptSS_weight; Err2OfwgtFFApp_subtractions_promptSS[index]+=FFApp_subtractions_promptSS_weight*FFApp_subtractions_promptSS_weight;
          } 
      }
      wgtsignal[index]=numOfwgtsignal[index]*lumi();
      totalbkg[index]=-numOfwgtFFApp_subtractions_promptSS[index]*lumi()-numOfwgtFFApp_subtractions_QmisID[index]*lumi()+
                       numOfwgtFFApp_data[index]+numOfwgtQmisID[index]+numOfwgtpromptSS[index]*lumi()+numOfwgtVgam[index]*lumi();
      wgtpromptSS[index]=numOfwgtpromptSS[index]*lumi();
      wgtVgam[index]=numOfwgtVgam[index]*lumi();
      wgtQmisID[index]=numOfwgtQmisID[index];
      wgtfakes[index]=-numOfwgtFFApp_subtractions_promptSS[index]*lumi()-numOfwgtFFApp_subtractions_QmisID[index]*lumi()+
                       numOfwgtFFApp_data[index];
      wgtpredicted[index]=wgtsignal[index]+totalbkg[index];
      sigs[index]=numOfwgtsignal[index]*lumi()/sqrt(totalbkg[index]);
      sigpurs[index]=numOfwgtsignal[index]*lumi()/(totalbkg[index]);
      errpromptSS[index]=sqrt(Err2OfwgtpromptSS[index])*lumi();
      errVgam[index]=sqrt(Err2OfwgtpromptSS[index])*lumi();
      errQmisID[index]=sqrt(Err2OfwgtQmisID[index]);
      errfakes[index]=sqrt(Err2OfwgtFFApp_subtractions_promptSS[index]*lumi()*lumi()+Err2OfwgtFFApp_subtractions_QmisID[index]*lumi()*lumi()+
                           Err2OfwgtFFApp_data[index]);
      errtotalbkg[index]=sqrt(Err2OfwgtpromptSS[index]*lumi()*lumi()+Err2OfwgtVgam[index]*lumi()*lumi()+
                              Err2OfwgtQmisID[index]+errfakes[index]*errfakes[index]);
      errpredicted[index]=sqrt(Err2Ofwgtsignal[index]*lumi()*lumi()+Err2OfwgtpromptSS[index]*lumi()*lumi()+Err2OfwgtVgam[index]*lumi()*lumi()+
                              Err2OfwgtQmisID[index]+errfakes[index]*errfakes[index]);
      errdata[index]=sqrt(Err2Ofwgtdata[index]);
      errsignal[index]=sqrt(Err2Ofwgtsignal[index])*lumi();
  }//end of loop
  for(int j=0;j<6;j++){numOfdata[j]=0; errdata[j]=0;}
  cout<<"---------------------------------------"<<endl;
  cout<<setiosflags(ios::fixed)<<setprecision(2);
  cout<<"                           &promptSS"<<setw(3)<<"  &$V+\\gamma$"<<setw(3)<<"  &QmisID"<<setw(3)<<"  &Fakes"<<"  &Total bkg"<<"  &signal"<<"  &Total predicted"<<"  &Observed"<<"  \\\\  "<<"  s/sqrt(B)"<<endl;
  cout<<"\\hline"<<endl;
  cout<<"MET                      "<<"&"<<wgtpromptSS[0]<<"$\\pm$"<<errpromptSS[0]<<setw(3)<<"&"<<wgtVgam[0]<<"$\\pm$"<<errVgam[0]<<setw(3)<<"&"<<wgtQmisID[0]<<"$\\pm$"<<errQmisID[0]<<setw(3)<<"&"<<wgtfakes[0]<<"$\\pm$"<<errfakes[0]<<setw(3)<<"&"<<totalbkg[0]<<"$\\pm$"<<errtotalbkg[0]<<setw(3)<<"&"<<wgtsignal[0]<<"$\\pm$"<<errsignal[0]<<setw(3)<<"&"<<wgtpredicted[0]<<"$\\pm$"<<errpredicted[0]<<setw(3)<<"&"<<numOfdata[0]<<"$\\pm$"<<errdata[0]<<" \\\\  "<<sigs[0]<<endl;
  cout<<"\\hline"<<endl;
  cout<<"$M(\\ell\\ell)$          "<<"&"<<wgtpromptSS[1]<<"$\\pm$"<<errpromptSS[1]<<setw(3)<<"&"<<wgtVgam[1]<<"$\\pm$"<<errVgam[1]<<setw(3)<<"&"<<wgtQmisID[1]<<"$\\pm$"<<errQmisID[1]<<setw(3)<<"&"<<wgtfakes[1]<<"$\\pm$"<<errfakes[1]<<setw(3)<<"&"<<totalbkg[1]<<"$\\pm$"<<errtotalbkg[1]<<setw(3)<<"&"<<wgtsignal[1]<<"$\\pm$"<<errsignal[1]<<setw(3)<<"&"<<wgtpredicted[1]<<"$\\pm$"<<errpredicted[1]<<setw(3)<<"&"<<numOfdata[1]<<"$\\pm$"<<errdata[1]<<" \\\\  "<<sigs[1]<<endl;
  cout<<"\\hline"<<endl;
  cout<<"$\\Delta R_{min}(l\_{2},j)$ "<<"&"<<wgtpromptSS[2]<<"$\\pm$"<<errpromptSS[2]<<setw(3)<<"&"<<wgtVgam[2]<<"$\\pm$"<<errVgam[2]<<setw(3)<<"&"<<wgtQmisID[2]<<"$\\pm$"<<errQmisID[2]<<setw(3)<<"&"<<wgtfakes[2]<<"$\\pm$"<<errfakes[2]<<setw(3)<<"&"<<totalbkg[2]<<"$\\pm$"<<errtotalbkg[2]<<setw(3)<<"&"<<wgtsignal[2]<<"$\\pm$"<<errsignal[2]<<setw(3)<<"&"<<wgtpredicted[2]<<"$\\pm$"<<errpredicted[2]<<setw(3)<<"&"<<numOfdata[2]<<"$\\pm$"<<errdata[2]<<" \\\\  "<<sigs[2]<<endl;
  cout<<"\\hline"<<endl;
  cout<<"$\\Delta R_{min}(l\_{1},j)$ "<<"&"<<wgtpromptSS[3]<<"$\\pm$"<<errpromptSS[3]<<setw(3)<<"&"<<wgtVgam[3]<<"$\\pm$"<<errVgam[3]<<setw(3)<<"&"<<wgtQmisID[3]<<"$\\pm$"<<errQmisID[3]<<setw(3)<<"&"<<wgtfakes[3]<<"$\\pm$"<<errfakes[3]<<setw(3)<<"&"<<totalbkg[3]<<"$\\pm$"<<errtotalbkg[3]<<setw(3)<<"&"<<wgtsignal[3]<<"$\\pm$"<<errsignal[3]<<setw(3)<<"&"<<wgtpredicted[3]<<"$\\pm$"<<errpredicted[3]<<setw(3)<<"&"<<numOfdata[3]<<"$\\pm$"<<errdata[3]<<" \\\\  "<<sigs[3]<<endl;
  cout<<"\\hline"<<endl;
  cout<<"$M(l\_{1}jj)$            "<<"&"<<wgtpromptSS[4]<<"$\\pm$"<<errpromptSS[4]<<setw(3)<<"&"<<wgtVgam[4]<<"$\\pm$"<<errVgam[4]<<setw(3)<<"&"<<wgtQmisID[4]<<"$\\pm$"<<errQmisID[4]<<setw(3)<<"&"<<wgtfakes[4]<<"$\\pm$"<<errfakes[4]<<setw(3)<<"&"<<totalbkg[4]<<"$\\pm$"<<errtotalbkg[4]<<setw(3)<<"&"<<wgtsignal[4]<<"$\\pm$"<<errsignal[4]<<setw(3)<<"&"<<wgtpredicted[4]<<"$\\pm$"<<errpredicted[4]<<setw(3)<<"&"<<numOfdata[4]<<"$\\pm$"<<errdata[4]<<" \\\\  "<<sigs[4]<<endl;
  cout<<"\\hline"<<endl;
  cout<<"$M(all)$                 "<<"&"<<wgtpromptSS[5]<<"$\\pm$"<<errpromptSS[5]<<setw(3)<<"&"<<wgtVgam[5]<<"$\\pm$"<<errVgam[5]<<setw(3)<<"&"<<wgtQmisID[5]<<"$\\pm$"<<errQmisID[5]<<setw(3)<<"&"<<wgtfakes[5]<<"$\\pm$"<<errfakes[5]<<setw(3)<<"&"<<totalbkg[5]<<"$\\pm$"<<errtotalbkg[5]<<setw(3)<<"&"<<wgtsignal[5]<<"$\\pm$"<<errsignal[5]<<setw(3)<<"&"<<wgtpredicted[5]<<"$\\pm$"<<errpredicted[5]<<setw(3)<<"&"<<numOfdata[5]<<"$\\pm$"<<errdata[5]<<" \\\\  "<<sigs[5]<<endl;
  cout<<"\\hline"<<endl;
  cout<<"---------------------------------------"<<endl;
  
//end of manin func
}
