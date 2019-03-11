//-------------------------------------------------------------------------------------------
// This script is to define cut-flow of hh->WWWW, using ntuples after hh4Wanalysis.C.
// Also can be used to draw plots
// Author: Maosen Zhou (maosen.zhou@cern.ch)
// Date: 2/Jan/2017
// --to scan different cuts to define best cuts
//   vars to be used: m_l1jj, mindR_l1j, mindR_l2j 
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
void simu_scan(){

  TString vars[]={"m_l1jj","mindR_l1j","mindR_l2j"};

  TFile *f_signal=new TFile("output/dataMC_2jets~/miniNtuple_mH260.root");
  TFile *f_data=new TFile("output/dataMC_2jets~/miniNtuple_datacombined.root");
  TFile *f_promptSS=new TFile("output/dataMC_2jets~/miniNtuple_promptSS.root");
  TFile *f_Vgam=new TFile("output/dataMC_2jets~/miniNtuple_Vgam.root");
  TFile *f_QmisID=new TFile("output/dataMC_2jets~/miniNtuple_QmisID_datacombined.root");
  TFile *f_FFApp_data=new TFile("output/dataMC_2jets~/miniNtuple_FFApp_datacombined.root");
  TFile *f_FFQmis=new TFile("output/dataMC_2jets~/miniNtuple_FFQmis_datacombined.root");
  TFile *f_FFApp_subtractions_QmisID=new TFile("output/dataMC_2jets~/miniNtuple_FFApp_subtractions_QmisID.root");
  TFile *f_FFApp_subtractions_promptSS=new TFile("output/dataMC_2jets~/miniNtuple_FFApp_subtractions_promptSS.root");
  
  TTree *signal=(TTree*)f_signal->Get("Tree");
  TTree *data=(TTree*)f_data->Get("Tree");
  TTree *promptSS=(TTree*)f_promptSS->Get("Tree");
  TTree *Vgam=(TTree*)f_Vgam->Get("Tree");
  TTree *QmisID=(TTree*)f_QmisID->Get("Tree");
  TTree *FFApp_data=(TTree*)f_FFApp_data->Get("Tree");
  TTree *FFQmis=(TTree*)f_FFQmis->Get("Tree");
  TTree *FFApp_subtractions_QmisID=(TTree*)f_FFApp_subtractions_QmisID->Get("Tree");
  TTree *FFApp_subtractions_promptSS=(TTree*)f_FFApp_subtractions_promptSS->Get("Tree");

  Float_t signal_m_l1jj,data_m_l1jj,promptSS_m_l1jj,Vgam_m_l1jj,QmisID_m_l1jj,FFApp_data_m_l1jj,FFQmis_m_l1jj,
          FFApp_subtractions_QmisID_m_l1jj,FFApp_subtractions_promptSS_m_l1jj;
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
  
  signal->SetBranchAddress("m_l1jj",&signal_m_l1jj);
  data->SetBranchAddress("m_l1jj",&data_m_l1jj);
  promptSS->SetBranchAddress("m_l1jj",&promptSS_m_l1jj);
  Vgam->SetBranchAddress("m_l1jj",&Vgam_m_l1jj);
  QmisID->SetBranchAddress("m_l1jj",&QmisID_m_l1jj);
  FFApp_data->SetBranchAddress("m_l1jj",&FFApp_data_m_l1jj);
  FFQmis->SetBranchAddress("m_l1jj",&FFQmis_m_l1jj);
  FFApp_subtractions_QmisID->SetBranchAddress("m_l1jj",&FFApp_subtractions_QmisID_m_l1jj);
  FFApp_subtractions_promptSS->SetBranchAddress("m_l1jj",&FFApp_subtractions_promptSS_m_l1jj);
  
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

  Double_t sigs[25][25][20];
  Float_t mindR_l2j_cut[25], mindR_l1j_cut[25], m_l1jj_cut[20];
  for(Int_t i=0;i<25;i++) mindR_l2j_cut[i]=0.5+0.1*i;
  for(Int_t i=0;i<25;i++) mindR_l1j_cut[i]=0.5+0.1*i;
  for(Int_t i=0;i<20;i++) m_l1jj_cut[i]=50+10*i;
  
  Int_t numOfsignal[25][25][20]={0},numOfpromptSS[25][25][20]={0}, numOfVgam[25][25][20]={0}, numOfVgam[25][25][20]={0},
        numOfQmisID[25][25][20]={0}, numOfFFQmis[25][25][20]={0},numOfFFApp_subtractions_QmisID[25][25][20]={0}, 
        numOfFFApp_subtractions_promptSS[25][25][20]={0}, numOfFFApp_data[25][25][20]={0};
  Double_t numOfwgtsignal[25][25][20]={0},numOfwgtpromptSS[25][25][20]={0}, numOfwgtVgam[25][25][20]={0}, numOfwgtVgam[25][25][20]={0},
           numOfwgtQmisID[25][25][20]={0},numOfwgtFFQmis[25][25][20]={0}, numOfwgtFFApp_subtractions_QmisID[25][25][20]={0},
           numOfwgtFFApp_subtractions_promptSS[25][25][20]={0},numOfwgtFFApp_data[25][25][20]={0};
  Double_t errOfwgtsignal[25][25][20]={0},errOfwgtpromptSS[25][25][20]={0}, errOfwgtVgam[25][25][20]={0}, errOfwgtVgam[25][25][20]={0},
           errOfwgtQmisID[25][25][20]={0},errOfwgtFFQmis[25][25][20]={0}, errOfwgtFFApp_subtractions_QmisID[25][25][20]={0},
           errOfwgtFFApp_subtractions_promptSS[25][25][20]={0},errOfwgtFFApp_data[25][25][20]={0};
  Double_t totalbkg[25][25][20]={0};
  Double_t numOfwgtfakes[25][25][20]={0};
  Double_t ErrOfwgtfakes[25][25][20]={0};
  for(Int_t i=0;i<25;i++){
      for(Int_t j=0;j<25;j++){
          for(Int_t k=0;k<20;k++){
              for(Long64_t entry=0; entry<signal->GetEntries();entry++) {
                  signal->GetEntry(entry);
                  if(signal_channel!=3)continue;
                  if(signal_numOfjet<2)continue;
                  if(signal_mindR_l2j<mindR_l2j_cut[i]&&signal_mindR_l1j<mindR_l1j_cut[j]&&signal_m_l1jj<m_l1jj_cut[k]){
                     numOfsignal[i][j][k] ++;
                     numOfwgtsignal[i][j][k] += signal_weight; errOfwgtsignal[i][j][k] += signal_weight*signal_weight;
                  }
              }
              for(Long64_t entry=0; entry<promptSS->GetEntries();entry++) {
                  promptSS->GetEntry(entry);
                  if(promptSS_channel!=3)continue;
                  if(promptSS_numOfjet<2)continue;
                  if(promptSS_mindR_l2j<mindR_l2j_cut[i]&&promptSS_mindR_l1j<mindR_l1j_cut[j]&&promptSS_m_l1jj<m_l1jj_cut[k]){
                     numOfpromptSS[i][j][k] ++;
                     numOfwgtpromptSS[i][j][k] += promptSS_weight; errOfwgtpromptSS[i][j][k] += promptSS_weight*promptSS_weight;
                  }
              }
              for(Long64_t entry=0; entry<Vgam->GetEntries();entry++) {
                  Vgam->GetEntry(entry);
                  if(Vgam_channel!=3)continue;
                  if(Vgam_numOfjet<2)continue;
                  if(Vgam_mindR_l2j<mindR_l2j_cut[i]&&Vgam_mindR_l1j<mindR_l1j_cut[j]&&Vgam_m_l1jj<m_l1jj_cut[k]){
                     numOfVgam[i][j][k] ++;
                     numOfwgtVgam[i][j][k] += Vgam_weight; errOfwgtVgam[i][j][k] += Vgam_weight*Vgam_weight;
                  }
              }
              for(Long64_t entry=0; entry<QmisID->GetEntries();entry++) {
                  QmisID->GetEntry(entry);
                  if(QmisID_channel!=3)continue;
                  if(QmisID_numOfjet<2)continue;
                  if(QmisID_mindR_l2j<mindR_l2j_cut[i]&&QmisID_mindR_l1j<mindR_l1j_cut[j]&&QmisID_m_l1jj<m_l1jj_cut[k]){
                     numOfQmisID[i][j][k] ++;
                     numOfwgtQmisID[i][j][k] += QmisID_weight; errOfwgtQmisID[i][j][k] += QmisID_weight*QmisID_weight;
                  }
              }
              for(Long64_t entry=0; entry<FFApp_data->GetEntries();entry++) {
                  FFApp_data->GetEntry(entry);
                  if(FFApp_data_channel!=3)continue;
                  if(FFApp_data_numOfjet<2)continue;
                  if(FFApp_data_mindR_l2j<mindR_l2j_cut[i]&&FFApp_data_mindR_l1j<mindR_l1j_cut[j]&&FFApp_data_m_l1jj<m_l1jj_cut[k]){
                     numOfFFApp_data[i][j][k] ++;
                     numOfwgtFFApp_data[i][j][k] += FFApp_data_weight; errOfwgtFFApp_data[i][j][k] += FFApp_data_weight*FFApp_data_weight;
                  }
              }
              for(Long64_t entry=0; entry<FFQmis->GetEntries();entry++) {
                  FFQmis->GetEntry(entry);
                  if(FFQmis_channel!=3)continue;
                  if(FFQmis_numOfjet<2)continue;
                  if(FFQmis_mindR_l2j<mindR_l2j_cut[i]&&FFQmis_mindR_l1j<mindR_l1j_cut[j]&&FFQmis_m_l1jj<m_l1jj_cut[k]){
                     numOfFFQmis[i][j][k] ++;
                     numOfwgtFFQmis[i][j][k] += FFQmis_weight;
                     errOfwgtFFQmis[i][j][k] += FFQmis_weight*FFQmis_weight;
                  }
              }
              for(Long64_t entry=0; entry<FFApp_subtractions_QmisID->GetEntries();entry++) {
                  FFApp_subtractions_QmisID->GetEntry(entry);
                  if(FFApp_subtractions_QmisID_channel!=3)continue;
                  if(FFApp_subtractions_QmisID_numOfjet<2)continue;
                  if(FFApp_subtractions_QmisID_mindR_l2j<mindR_l2j_cut[i]&&FFApp_subtractions_QmisID_mindR_l1j<mindR_l1j_cut[j]&&FFApp_subtractions_QmisID_m_l1jj<m_l1jj_cut[k]){
                     numOfFFApp_subtractions_QmisID[i][j][k] ++;
                     numOfwgtFFApp_subtractions_QmisID[i][j][k] += FFApp_subtractions_QmisID_weight;
                     errOfwgtFFApp_subtractions_QmisID[i][j][k] += FFApp_subtractions_QmisID_weight*FFApp_subtractions_QmisID_weight;
                  }
              }
              for(Long64_t entry=0; entry<FFApp_subtractions_promptSS->GetEntries();entry++) {
                  FFApp_subtractions_promptSS->GetEntry(entry);
                  if(FFApp_subtractions_promptSS_channel!=3)continue;
                  if(FFApp_subtractions_promptSS_numOfjet<2)continue;
                  if(FFApp_subtractions_promptSS_mindR_l2j<mindR_l2j_cut[i]&&FFApp_subtractions_promptSS_mindR_l1j<mindR_l1j_cut[j]&&FFApp_subtractions_promptSS_m_l1jj<m_l1jj_cut[k]){
                     numOfFFApp_subtractions_promptSS[i][j][k] ++;
                     numOfwgtFFApp_subtractions_promptSS[i][j][k] += FFApp_subtractions_promptSS_weight;
                     errOfwgtFFApp_subtractions_promptSS[i][j][k] += FFApp_subtractions_promptSS_weight*FFApp_subtractions_promptSS_weight;
                  }
              }
              numOfwgtfakes[i][j][k] = numOfwgtFFApp_data[i][j][k]-numOfwgtFFApp_subtractions_promptSS[i][j][k]*lumi()-
                                        numOfwgtFFApp_subtractions_QmisID[i][j][k]*lumi()-numOfwgtFFQmis[i][j][k];
              ErrOfwgtfakes[i][j][k] = sqrt(errOfwgtFFApp_data[i][j][k] + errOfwgtFFQmis[i][j][k] +
                                        errOfwgtFFApp_subtractions_QmisID[i][j][k]*lumi()*lumi() +
                                        errOfwgtFFApp_subtractions_promptSS[i][j][k]*lumi()*lumi());
              totalbkg[i][j][k]=numOfwgtQmisID[i][j][k] + numOfwgtpromptSS[i][j][k]*lumi()+numOfwgtVgam[i][j][k]*lumi()+
                                numOfwgtFFApp_data[i][j][k]-numOfwgtFFApp_subtractions_promptSS[i][j][k]*lumi()-
                                numOfwgtFFApp_subtractions_QmisID[i][j][k]*lumi()-numOfwgtFFQmis[i][j][k];
              Double_t tmpsig=numOfwgtsignal[i][j][k]*lumi()/sqrt(totalbkg[i][j][k]);
              sigs[i][j][k]=tmpsig; 
          }//end of innermost loop  
      }//end of second loop   
  }//end of outlier loop
  //find maximum significance value and cout index
  double tmp=0;
  float final_mindR_l2j_cut, final_mindR_l1j_cut, final_m_l1jj_cut;
  Int_t index1, index2, index3;
  for(int i=0;i<25;i++){
      for(int j=0;j<25;j++){
          for(int k=0;k<20;k++){
              if( (sigs[i][j][k]==sigs[i][j][k] && sigs[i][j][k]!=sigs[i][j][k]+1.) && //exclude infinity
                  numOfwgtfakes[i][j][k]>0 && ErrOfwgtfakes[i][j][k]/numOfwgtfakes[i][j][k]<2. &&//ensure fakes larger than 0, avoid fluctuations
                  sigs[i][j][k]>tmp ) tmp=sigs[i][j][k];
          }
      }
  }
  for(int i=0;i<25;i++){
      for(int j=0;j<25;j++){
          for(int k=0;k<20;k++){
              if( (sigs[i][j][k]==sigs[i][j][k] && sigs[i][j][k]!=sigs[i][j][k]+1.) && //exclude infinity
                  numOfwgtfakes[i][j][k]>0 && ErrOfwgtfakes[i][j][k]/numOfwgtfakes[i][j][k]<2. &&//ensure fakes larger than 0, avoid fluctuations
                  sigs[i][j][k]==tmp ) {
                  cout<<"maximum significance "<<tmp<<endl;
                  index1=i; 
                  index2=j; 
                  index3=k; 
                  cout<<"i j k == "<<i<<" "<<j<<" "<<k<<endl;
                  final_mindR_l2j_cut=mindR_l2j_cut[i];
                  final_mindR_l1j_cut=mindR_l1j_cut[j];
                  final_m_l1jj_cut=m_l1jj_cut[k];
                  cout<<"mindR_l2j mindR_l1j m_l1jj == "<<final_mindR_l2j_cut<<" "<<final_mindR_l1j_cut<<" "<<final_m_l1jj_cut<<endl;
              }
          }
      }
  }
  cout<<"---------------------------------------"<<endl;
  Double_t final_weighted_signal=numOfwgtsignal[index1][index2][index3]*lumi(); Int_t final_signal=numOfsignal[index1][index2][index3];
         Double_t final_weighted_QmisID=numOfwgtQmisID[index1][index2][index3]; Int_t final_QmisID=numOfQmisID[index1][index2][index3];
         Double_t final_weighted_FFQmis=numOfwgtFFQmis[index1][index2][index3]; Int_t final_FFQmis=numOfFFQmis[index1][index2][index3];
         Double_t final_weighted_FFApp_subtractions_QmisID=numOfwgtFFApp_subtractions_QmisID[index1][index2][index3]*lumi();
                  Int_t final_FFApp_subtractions_QmisID=numOfFFApp_subtractions_QmisID[index1][index2][index3];
         Double_t final_weighted_FFApp_subtractions_promptSS=numOfwgtFFApp_subtractions_promptSS[index1][index2][index3]*lumi();
                  Int_t final_FFApp_subtractions_promptSS=numOfFFApp_subtractions_promptSS[index1][index2][index3];
         Double_t final_weighted_promptSS=numOfwgtpromptSS[index1][index2][index3]*lumi();
                  Int_t final_promptSS=numOfpromptSS[index1][index2][index3];
         Double_t final_weighted_Vgam=numOfwgtVgam[index1][index2][index3]*lumi();Int_t final_Vgam=numOfVgam[index1][index2][index3];
         Double_t final_weighted_FFApp_data=numOfwgtFFApp_data[index1][index2][index3]; 
                  Int_t final_FFApp_data=numOfFFApp_data[index1][index2][index3];
         Double_t final_total_bkg=totalbkg[index1][index2][index3];

         Double_t ErrOfpromptSS=sqrt(errOfwgtpromptSS[index1][index2][index3])*lumi(), 
                  ErrOfVgam=sqrt(errOfwgtVgam[index1][index2][index3])*lumi(), 
                  ErrOfQmisID=sqrt(errOfwgtQmisID[index1][index2][index3]);
         Double_t ErrOffake=sqrt(errOfwgtFFApp_data[index1][index2][index3] + errOfwgtFFQmis[index1][index2][index3] + 
                             errOfwgtFFApp_subtractions_QmisID[index1][index2][index3]*lumi()*lumi() +
                             errOfwgtFFApp_subtractions_promptSS[index1][index2][index3]*lumi()*lumi());
         Double_t ErrOfsignal=sqrt(errOfwgtsignal[index1][index2][index3])*lumi();
         Double_t final_total_bkg_err=sqrt(errOfwgtpromptSS[index1][index2][index3]*lumi()*lumi() + 
                                       errOfwgtVgam[index1][index2][index3]*lumi()*lumi() + errOfwgtQmisID[index1][index2][index3] + 
                                       ErrOffake*ErrOffake);
         Double_t predicted=totalbkg[index1][index2][index3] + numOfwgtsignal[index1][index2][index3]*lumi();
         Double_t predicted_err=sqrt(errOfwgtpromptSS[index1][index2][index3]*lumi()*lumi() + 
                                 errOfwgtVgam[index1][index2][index3]*lumi()*lumi() + errOfwgtQmisID[index1][index2][index3] + 
                                 ErrOffake*ErrOffake + errOfwgtsignal[index1][index2][index3]*lumi()*lumi());

  cout<<"signal: "<<setw(5)<<final_weighted_signal<<"+-"<<ErrOfsignal<<setw(10)<<final_signal<<endl;
  cout<<"promptSS: "<<setw(5)<<final_weighted_promptSS<<"+-"<<ErrOfpromptSS<<setw(10)<<final_promptSS<<endl;
  cout<<"Vgam: "<<setw(5)<<final_weighted_Vgam<<"+-"<<ErrOfVgam<<setw(10)<<final_Vgam<<endl;
  cout<<"QmisID: "<<setw(5)<<final_weighted_QmisID<<"+-"<<ErrOfQmisID<<setw(10)<<final_QmisID<<endl;
  cout<<"Fakes: "<<setw(5)<<(final_weighted_FFApp_data-final_weighted_FFApp_subtractions_promptSS-final_weighted_FFApp_subtractions_QmisID-final_weighted_FFQmis)<<"+-"<<ErrOffake<<setw(10)<<final_FFApp_data<<"-"<<final_FFApp_subtractions_promptSS<<"-"<<final_FFApp_subtractions_QmisID<<"-"<<final_FFQmis<<endl;
  cout<<"total bkg: "<<setw(5)<<final_total_bkg<<"+-"<<final_total_bkg_err<<endl;
  cout<<"predicted: "<<setw(5)<<predicted<<"+-"<<predicted_err<<endl;
  cout<<"s/sqrt(B): "<<setw(5)<<sigs[index1][index2][index3]<<endl;
//end of manin func
}
