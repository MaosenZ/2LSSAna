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
void getSystematics(TString masspoint,Int_t input_channel){
  SetAtlasStyle();
  //low mass
  Float_t ff_ele=0.23, ff_mu=0.41, sys_ele=0.544, sys_mu=0.609;
                           //dR_l1j m_ll m_l1jj m_all
  Float_t fixed_cuts_min[4],fixed_cuts_max[4];
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
  TFile *f_signal;
  if(masspoint=="mH260")f_signal=new TFile("output/dataMC_2jets/miniNtuple_mH260.root");
  if(masspoint=="mH300")f_signal=new TFile("output/dataMC_2jets/miniNtuple_mH300.root");
  if((masspoint != "mH260")  && (masspoint!= "mH300") ) cout<<"Error input "<<endl;
  TFile *f_prompt=new TFile("output/dataMC_2jets/miniNtuple_prompt.root");

  TTree *signal=(TTree*)f_signal->Get("Tree");
  TTree *data=(TTree*)f_data->Get("Tree");
  TTree *prompt=(TTree*)f_prompt->Get("Tree");
  Float_t signal_m_ll,prompt_m_ll,data_m_ll;
  Float_t signal_m_l1jj,prompt_m_l1jj,data_m_l1jj;
  Float_t signal_m_all,prompt_m_all,data_m_all;
  Float_t signal_mindR_l1j,prompt_mindR_l1j,data_mindR_l1j;
  Float_t signal_mindR_l2j,prompt_mindR_l2j,data_mindR_l2j;
  Double_t signal_weight,prompt_weight,data_weight;
  Int_t signal_channel,prompt_channel,data_channel;
  Int_t signal_numOfjet,prompt_numOfjet,data_numOfjet;

  signal->SetBranchAddress("m_ll",&signal_m_ll);
  data->SetBranchAddress("m_ll",&data_m_ll);
  prompt->SetBranchAddress("m_ll",&prompt_m_ll);

  signal->SetBranchAddress("m_l1jj",&signal_m_l1jj);
  data->SetBranchAddress("m_l1jj",&data_m_l1jj);
  prompt->SetBranchAddress("m_l1jj",&prompt_m_l1jj);

  signal->SetBranchAddress("m_all",&signal_m_all);
  data->SetBranchAddress("m_all",&data_m_all);
  prompt->SetBranchAddress("m_all",&prompt_m_all);

  signal->SetBranchAddress("mindR_l1j",&signal_mindR_l1j);
  data->SetBranchAddress("mindR_l1j",&data_mindR_l1j);
  prompt->SetBranchAddress("mindR_l1j",&prompt_mindR_l1j);

  signal->SetBranchAddress("mindR_l2j",&signal_mindR_l2j);
  data->SetBranchAddress("mindR_l2j",&data_mindR_l2j);
  prompt->SetBranchAddress("mindR_l2j",&prompt_mindR_l2j);

  signal->SetBranchAddress("weight",&signal_weight);
  data->SetBranchAddress("weight",&data_weight);
  prompt->SetBranchAddress("weight",&prompt_weight);

  signal->SetBranchAddress("channel",&signal_channel);
  data->SetBranchAddress("channel",&data_channel);
  prompt->SetBranchAddress("channel",&prompt_channel);

  signal->SetBranchAddress("numOfjet",&signal_numOfjet);
  data->SetBranchAddress("numOfjet",&data_numOfjet);
  prompt->SetBranchAddress("numOfjet",&prompt_numOfjet);

  Int_t numOfsignal[4]={0},numOfpromptSS[4]={0},  numOfVgam[4]={0},numOfQmisID[4]={0}, numOffake[4]={0},numOfprompt[4]={0};
  Double_t numOfwgtdata[4]={0},numOfwgtsignal[4]={0},numOfwgtpromptSS[4]={0},  numOfwgtVgam[4]={0},numOfwgtQmisID[4]={0}, numOfwgtfake[4]={0},
           numOfwgtprompt[4]={0};
  Double_t Err2Ofwgtdata[4]={0},Err2Ofwgtsignal[4]={0},Err2OfwgtpromptSS[4]={0},  Err2OfwgtVgam[4]={0},Err2OfwgtQmisID[4]={0};
  Double_t sigs[4]={0}, sigpurs[4]={0},numOfwgteantimu[4]={0},numOfwgtantiemu[4]={0};
  Double_t wgtdata[4],wgtpromptSS[4],wgtVgam[4],wgtQmisID[4],wgtfakes[4],wgtprompt[4],wgtpredicted[4],wgtsignal[4];
  Double_t errdata[4],errpromptSS[4],errVgam[4],errQmisID[4],errfakes[4],errfakes_stat[4],errfakes_syst[4],errpredicted[4],errprompt[4],errsignal[4];
      for(Long64_t entry=0; entry<signal->GetEntries();entry++) {
          signal->GetEntry(entry);
          if(input_channel==3 && signal_channel!=3)continue;
          if(input_channel==2 && signal_channel!=2)continue;
          if(input_channel==1 && signal_channel!=1)continue;
          if(signal_mindR_l1j>fixed_cuts_min[0]&&signal_mindR_l1j<fixed_cuts_max[0] &&
                         signal_m_ll>fixed_cuts_min[1]&&signal_m_ll<fixed_cuts_max[1] &&
                         signal_m_l1jj>fixed_cuts_min[2]&&signal_m_l1jj<fixed_cuts_max[2] &&
                         signal_m_all>fixed_cuts_min[3]&&signal_m_all<fixed_cuts_max[3]){
             numOfsignal[index]++;
             numOfwgtsignal[index]+=signal_weight; Err2Ofwgtsignal[index]+=signal_weight*signal_weight;
          }
      }
      for(Long64_t entry=0; entry<prompt->GetEntries();entry++) {
          prompt->GetEntry(entry);
          if(input_channel==3 && prompt_channel!=3)continue;
          if(input_channel==2 && prompt_channel!=2)continue;
          if(input_channel==1 && prompt_channel!=1)continue;
          if(prompt_mindR_l1j>fixed_cuts_min[0]&&prompt_mindR_l1j<fixed_cuts_max[0] &&
                        prompt_m_ll>fixed_cuts_min[1]&&prompt_m_ll<fixed_cuts_max[1] &&
                         prompt_m_l1jj>fixed_cuts_min[2]&&prompt_m_l1jj<fixed_cuts_max[2] &&
                         prompt_m_all>fixed_cuts_min[3]&&prompt_m_all<fixed_cuts_max[3]){
              numOfprompt[index]++;
              numOfwgtprompt[index]+=prompt_weight;
          }
      }

      wgtsignal[index]=numOfwgtsignal[index];
      wgtprompt[index]=numOfwgtprompt[index];
      wgtpromptSS[index]=numOfwgtpromptSS[index];
      wgtVgam[index]=numOfwgtVgam[index];
      wgtQmisID[index]=numOfwgtQmisID[index];
      wgtfakes[index]=numOfwgtfake[index];
      wgtpredicted[index]=wgtsignal[index]+wgtprompt[index];
      sigs[index]=numOfwgtsignal[index]/sqrt(wgtprompt[index]);
      sigpurs[index]=numOfwgtsignal[index]/(wgtprompt[index]);
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
      errprompt[index]=sqrt(Err2OfwgtpromptSS[index]+Err2OfwgtVgam[index]+ Err2OfwgtQmisID[index]+errfakes[index]*errfakes[index]);
      errpredicted[index]=sqrt(Err2Ofwgtsignal[index]+Err2OfwgtpromptSS[index]+Err2OfwgtVgam[index]+ Err2OfwgtQmisID[index]+
                               errfakes[index]*errfakes[index]);
      errdata[index]=sqrt(Err2Ofwgtdata[index]);
      errsignal[index]=sqrt(Err2Ofwgtsignal[index]);
      cout<<"s/sqrt(B): "<<sigs[index]<<endl;
  for(int j=0;j<4;j++){numOfdata[j]=0; errdata[j]=0;}
  ofstream outfile;
  TString channel_name;
  if(input_channel==1) channel_name="ee";
  if(input_channel==2) channel_name="mumu";
  if(input_channel==3) channel_name="emu";
  outfile.open(channel_name+"_"+masspoint+".txt",ios::trunc);
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
  }
  cout<<"---------------------------------------"<<endl;
  cout<<setiosflags(ios::fixed)<<setprecision(2);
  cout<<"                           &promptSS"<<setw(3)<<"  &$V+\\gamma$"<<setw(3)<<"  &QmisID"<<setw(3)<<"  &Fakes"<<"  &Total bkg"<<"  &signal"<<"  &Total predicted"<<"  &Observed"<<"  \\\\  "<<"  s/sqrt(B)"<<endl;
  cout<<"\\hline"<<endl;
  cout<<"\\hline"<<endl;
  cout<<"$\\Delta R_{min}(l\_{1},j)$ "<<"&"<<wgtpromptSS[0]<<"$\\pm$"<<errpromptSS[0]<<setw(3)<<"&"<<wgtVgam[0]<<"$\\pm$"<<errVgam[0]<<setw(3)<<"&"<<wgtQmisID[0]<<"$\\pm$"<<errQmisID[0]<<setw(3)<<"&"<<wgtfakes[0]<<"$\\pm$"<<errfakes[0]<<setw(3)<<"&"<<wgtprompt[0]<<"$\\pm$"<<errprompt[0]<<setw(3)<<"&"<<wgtsignal[0]<<"$\\pm$"<<errsignal[0]<<setw(3)<<"&"<<wgtpredicted[0]<<"$\\pm$"<<errpredicted[0]<<setw(3)<<"&"<<numOfdata[0]<<"\\\\"<<endl;
  cout<<"\\hline"<<endl;
  cout<<"$M(\\ell\\ell)$            "<<"&"<<wgtpromptSS[1]<<"$\\pm$"<<errpromptSS[1]<<setw(3)<<"&"<<wgtVgam[1]<<"$\\pm$"<<errVgam[1]<<setw(3)<<"&"<<wgtQmisID[1]<<"$\\pm$"<<errQmisID[1]<<setw(3)<<"&"<<wgtfakes[1]<<"$\\pm$"<<errfakes[1]<<setw(3)<<"&"<<wgtprompt[1]<<"$\\pm$"<<errprompt[1]<<setw(3)<<"&"<<wgtsignal[1]<<"$\\pm$"<<errsignal[1]<<setw(3)<<"&"<<wgtpredicted[1]<<"$\\pm$"<<errpredicted[1]<<setw(3)<<"&"<<numOfdata[1]<<"\\\\"<<endl;
  cout<<"\\hline"<<endl;
  cout<<"$M(l\_{1}jj)$             "<<"&"<<wgtpromptSS[2]<<"$\\pm$"<<errpromptSS[2]<<setw(3)<<"&"<<wgtVgam[2]<<"$\\pm$"<<errVgam[2]<<setw(3)<<"&"<<wgtQmisID[2]<<"$\\pm$"<<errQmisID[2]<<setw(3)<<"&"<<wgtfakes[2]<<"$\\pm$"<<errfakes[2]<<setw(3)<<"&"<<wgtprompt[2]<<"$\\pm$"<<errprompt[2]<<setw(3)<<"&"<<wgtsignal[2]<<"$\\pm$"<<errsignal[2]<<setw(3)<<"&"<<wgtpredicted[2]<<"$\\pm$"<<errpredicted[2]<<setw(3)<<"&"<<numOfdata[2]<<"\\\\"<<endl;
  cout<<"\\hline"<<endl;
  cout<<"$M(all)$                  "<<"&"<<wgtpromptSS[3]<<"$\\pm$"<<errpromptSS[3]<<setw(3)<<"&"<<wgtVgam[3]<<"$\\pm$"<<errVgam[3]<<setw(3)<<"&"<<wgtQmisID[3]<<"$\\pm$"<<errQmisID[3]<<setw(3)<<"&"<<wgtfakes[3]<<"$\\pm$"<<errfakes[3]<<setw(3)<<"&"<<wgtprompt[3]<<"$\\pm$"<<errprompt[3]<<setw(3)<<"&"<<wgtsignal[3]<<"$\\pm$"<<errsignal[3]<<setw(3)<<"&"<<wgtpredicted[3]<<"$\\pm$"<<errpredicted[3]<<setw(3)<<"&"<<numOfdata[3]<<"\\\\"<<endl;
  cout<<"\\hline"<<endl;
  cout<<"\\hline"<<endl;
  cout<<"---------------------------------------"<<endl;
  
//end of manin func
}
