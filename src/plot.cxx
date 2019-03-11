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
#include "THStack.h"
#include "TFile.h"
#include "TTree.h"
#include "TStyle.h"
#include <iostream>
#include "TString.h"
#include <vector>
#include "lumi.cxx"
#include "GHTBCs.cxx"
#include "../../atlasstyle-00-03-05/AtlasStyle.C"
#include "../../atlasstyle-00-03-05/AtlasUtils.C"
using namespace std;
using namespace TMath;
void plot(){
   SetAtlasStyle();
  //Get trees and variables 
  //low mass
  Float_t ff_ele=0.5401, ff_mu=0.5033, sys_ele=0.6309, sys_mu=0.6455;
  //high mass
  //Float_t ff_ele=0.5472, ff_mu=0.4544, sys_ele=0.6918, sys_mu=0.7179;
  TString vars[]={"pt_leadinglepton","pt_sublepton","pt_j1","pt_j2","m_ll","m_jj_w","MET","m_jj","m_l1jj","mindR_l1j","mindR_l2j","pt_vecsum",
                   "pt_sum","m_all","Mt","m_l1j","m_l2j","RMS","ChargeIDBDTTight_0","ChargeIDBDTTight_1",
                   "PromptLeptonIso_TagWeight_0","PromptLeptonIso_TagWeight_1","numOfjet"};
  TString vars_titles[]={"Pt(l_{1})","Pt(l_{2})","Pt(j_{1})","Pt(j_{2})","M(ll)","M(jj)^{w}","#slash{E}_{T}","M(jj)","M(l_{1}jj)","#DeltaR_{min}(l_{1},j)","#DeltaR_{min}(l_{2},j)","Pt(all)^{vec}","Pt(all)","M(all)","Mt","M(l_{1}j)","M(l_{2}j)","RMS","ChargeIDBDTTight_0","ChargeIDBDTTight_1","PromptLeptonIso_TagWeight_0","PromptLeptonIso_TagWeight_1","Njet"};

  TFile *f_nonres=new TFile("output/dataMC_2jets/miniNtuple_nonres.root");
  TFile *f_mH260=new TFile("output/dataMC_2jets/miniNtuple_mH260.root");
  TFile *f_mH300=new TFile("output/dataMC_2jets/miniNtuple_mH300.root");
  TFile *f_mH400=new TFile("output/dataMC_2jets/miniNtuple_mH400.root");
  TFile *f_mH500=new TFile("output/dataMC_2jets/miniNtuple_mH500.root");
  TFile *f_data=new TFile("output/dataMC_2jets/miniNtuple_datacombined.root");
  TFile *f_totalbkg=new TFile("output/dataMC_2jets/miniNtuple_totalbkg.root");
  
  TTree *nonres=(TTree*)f_nonres->Get("Tree");
  TTree *mH260=(TTree*)f_mH260->Get("Tree");
  TTree *mH300=(TTree*)f_mH300->Get("Tree");
  TTree *mH400=(TTree*)f_mH400->Get("Tree");
  TTree *mH500=(TTree*)f_mH500->Get("Tree");
  TTree *data=(TTree*)f_data->Get("Tree");
  TTree *totalbkg=(TTree*)f_totalbkg->Get("Tree");
  for(Int_t index=13;index<14;index++){
      Float_t nonres_var,mH260_var,mH300_var,mH400_var,mH500_var,data_var,totalbkg_var;
      Double_t nonres_weight,mH260_weight,mH300_weight,mH400_weight,mH500_weight,data_weight,totalbkg_weight;
      Int_t nonres_channel,mH260_channel,mH300_channel,mH400_channel,mH500_channel,data_channel,totalbkg_channel;
      Int_t nonres_category,mH260_category,mH300_category,mH400_category,mH500_category,data_category,totalbkg_category;
      Int_t nonres_numOfjet,mH260_numOfjet,mH300_numOfjet,mH400_numOfjet,mH500_numOfjet,data_numOfjet,totalbkg_numOfjet;
      TString *nonres_component=0,*mH260_component=0,*mH300_component=0,*mH400_component=0,
              *mH500_component=0,*data_component=0,*totalbkg_component=0;
      TString var=vars[index], varx_title=vars_titles[index] ;
      TString output_ee_png="output/dataMC_2jets_plots/"; output_ee_png+=var; output_ee_png+="_ee.png";
      TString output_ee_pdf="output/dataMC_2jets_plots/"; output_ee_pdf+=var; output_ee_pdf+="_ee.pdf";
      TString output_mumu_png="output/dataMC_2jets_plots/"; output_mumu_png+=var; output_mumu_png+="_mumu.png";
      TString output_mumu_pdf="output/dataMC_2jets_plots/"; output_mumu_pdf+=var; output_mumu_pdf+="_mumu.pdf";
      TString output_emu_png="output/dataMC_2jets_plots/"; output_emu_png+=var; output_emu_png+="_emu.png";
      TString output_emu_pdf="output/dataMC_2jets_plots/"; output_emu_pdf+=var; output_emu_pdf+="_emu.pdf";
      /*Int_t Nbins, xmin, xmax;
      if(index<=6 || index==11 ||index==14 || index==15){ Nbins=10; xmin=0; xmax=200;}
      if(index==8||index==7){ Nbins=10; xmin=0; xmax=500;}
      if(index==9||index==10||index==16){ Nbins=10; xmin=0; xmax=6;}
      if(index>=12 && index<=13){  Nbins=10; xmin=0; xmax=1000;}
      if(index==17){Nbins=10; xmin=0; xmax=10;}*/
      Int_t Nbins, xmin, xmax;
      if(var=="pt_leadinglepton") {Nbins=50; xmin=0; xmax=500;}
      if(var=="pt_sublepton") {Nbins=50; xmin=0; xmax=500;}
      if(var=="pt_j1") {Nbins=50; xmin=0; xmax=500;}
      if(var=="pt_j2") {Nbins=50; xmin=0; xmax=500;}
      if(var=="m_ll") {Nbins=50; xmin=0; xmax=500;}
      if(var=="m_jj_w"){ Nbins=50; xmin=0; xmax=500;}
      if(var=="MET") {Nbins=50; xmin=0; xmax=500;}
      if(var=="m_jj") {Nbins=20; xmin=0; xmax=1000;}
      if(var=="m_l1jj") {Nbins=20; xmin=0; xmax=1000;}
      if(var=="mindR_l1j"){ Nbins=20; xmin=0; xmax=5;}
      if(var=="mindR_l2j"){ Nbins=20; xmin=0; xmax=5;}
      if(var=="pt_vecsum"){ Nbins=50; xmin=0; xmax=500;}
      if(var=="pt_sum") {Nbins=30; xmin=0; xmax=1500;}
      if(var=="m_all") {Nbins=30; xmin=0; xmax=1500;}
      if(var=="Mt") {Nbins=30; xmin=0; xmax=1500;}
      if(var=="m_l1j"){ Nbins=20; xmin=0; xmax=1000;}
      if(var=="m_l2j"){ Nbins=20; xmin=0; xmax=1000;}
      if(var=="RMS") {Nbins=20; xmin=0; xmax=5;}
      if(var=="numOfjet") {Nbins=10; xmin=0; xmax=10;}
      if(var.Contains("Weight")||var.Contains("Charge")) {Nbins=24; xmin=-1.2; xmax=1.2;}
      cout<<"var: "<<var<<endl;
      nonres->SetBranchAddress(var,&nonres_var);
      mH260->SetBranchAddress(var,&mH260_var);
      mH300->SetBranchAddress(var,&mH300_var);
      mH400->SetBranchAddress(var,&mH400_var);
      mH500->SetBranchAddress(var,&mH500_var);
      data->SetBranchAddress(var,&data_var);
      totalbkg->SetBranchAddress(var,&totalbkg_var);
      
      nonres->SetBranchAddress("weight",&nonres_weight);
      mH260->SetBranchAddress("weight",&mH260_weight);
      mH300->SetBranchAddress("weight",&mH300_weight);
      mH400->SetBranchAddress("weight",&mH400_weight);
      mH500->SetBranchAddress("weight",&mH500_weight);
      data->SetBranchAddress("weight",&data_weight);
      totalbkg->SetBranchAddress("weight",&totalbkg_weight);
      
      nonres->SetBranchAddress("channel",&nonres_channel);
      mH260->SetBranchAddress("channel",&mH260_channel);
      mH300->SetBranchAddress("channel",&mH300_channel);
      mH400->SetBranchAddress("channel",&mH400_channel);
      mH500->SetBranchAddress("channel",&mH500_channel);
      data->SetBranchAddress("channel",&data_channel);
      totalbkg->SetBranchAddress("channel",&totalbkg_channel);
    
      nonres->SetBranchAddress("category",&nonres_category);
      mH260->SetBranchAddress("category",&mH260_category);
      mH300->SetBranchAddress("category",&mH300_category);
      mH400->SetBranchAddress("category",&mH400_category);
      mH500->SetBranchAddress("category",&mH500_category);
      data->SetBranchAddress("category",&data_category);
      totalbkg->SetBranchAddress("category",&totalbkg_category);

      nonres->SetBranchAddress("component",&nonres_component);
      mH260->SetBranchAddress("component",&mH260_component);
      mH300->SetBranchAddress("component",&mH300_component);
      mH400->SetBranchAddress("component",&mH400_component);
      mH500->SetBranchAddress("component",&mH500_component);
      //data->SetBranchAddress("component",&data_component);
      totalbkg->SetBranchAddress("component",&totalbkg_component);
      /*nonres->SetBranchAddress("numOfjet",&nonres_numOfjet);
      mH260->SetBranchAddress("numOfjet",&mH260_numOfjet);
      mH300->SetBranchAddress("numOfjet",&mH300_numOfjet);
      mH400->SetBranchAddress("numOfjet",&mH400_numOfjet);
      mH500->SetBranchAddress("numOfjet",&mH500_numOfjet);
      data->SetBranchAddress("numOfjet",&data_numOfjet);
      totalbkg->SetBranchAddress("numOfjet",&totalbkg_numOfjet);
      Vgam->SetBranchAddress("numOfjet",&Vgam_numOfjet);
      QmisID->SetBranchAddress("numOfjet",&QmisID_numOfjet);
      FFApp_data->SetBranchAddress("numOfjet",&FFApp_data_numOfjet);
      FFApp_subtractions_QmisID->SetBranchAddress("numOfjet",&FFApp_subtractions_QmisID_numOfjet);*/
      TH1::SetDefaultSumw2();
      TH1F *frame_ee=new TH1F("frame_ee","",Nbins,xmin,xmax);
      THStack *hs_ee=new THStack("hs_ee","");
      TH1F *hist_nonres_ee=new TH1F("hist_nonres_ee","",Nbins,xmin,xmax);
      TH1F *hist_mH260_ee=new TH1F("hist_mH260_ee","",Nbins,xmin,xmax);
      TH1F *hist_mH300_ee=new TH1F("hist_mH300_ee","",Nbins,xmin,xmax);
      TH1F *hist_mH400_ee=new TH1F("hist_mH400_ee","",Nbins,xmin,xmax);
      TH1F *hist_mH500_ee=new TH1F("hist_mH500_ee","",Nbins,xmin,xmax);
      TH1F *hist_data_ee=new TH1F("hist_data_ee","",Nbins,xmin,xmax);
      TH1F *hist_promptSS_ee=new TH1F("hist_promptSS_ee","",Nbins,xmin,xmax);
      TH1F *hist_Vgam_ee=new TH1F("hist_Vgam_ee","",Nbins,xmin,xmax);
      TH1F *hist_QmisID_ee=new TH1F("hist_QmisID_ee","",Nbins,xmin,xmax);
      TH1F *hist_fake_ee=new TH1F("hist_fake_ee","",Nbins,xmin,xmax);
      TH1F *frame_mumu=new TH1F("frame_mumu","",Nbins,xmin,xmax);
      THStack *hs_mumu=new THStack("hs_mumu","");
      TH1F *hist_nonres_mumu=new TH1F("hist_nonres_mumu","",Nbins,xmin,xmax);
      TH1F *hist_mH260_mumu=new TH1F("hist_mH260_mumu","",Nbins,xmin,xmax);
      TH1F *hist_mH300_mumu=new TH1F("hist_mH300_mumu","",Nbins,xmin,xmax);
      TH1F *hist_mH400_mumu=new TH1F("hist_mH400_mumu","",Nbins,xmin,xmax);
      TH1F *hist_mH500_mumu=new TH1F("hist_mH500_mumu","",Nbins,xmin,xmax);
      TH1F *hist_data_mumu=new TH1F("hist_data_mumu","",Nbins,xmin,xmax);
      TH1F *hist_promptSS_mumu=new TH1F("hist_promptSS_mumu","",Nbins,xmin,xmax);
      TH1F *hist_Vgam_mumu=new TH1F("hist_Vgam_mumu","",Nbins,xmin,xmax);
      TH1F *hist_QmisID_mumu=new TH1F("hist_QmisID_mumu","",Nbins,xmin,xmax);
      TH1F *hist_fake_mumu=new TH1F("hist_fake_mumu","",Nbins,xmin,xmax);
      TH1F *frame_emu=new TH1F("frame_emu","",Nbins,xmin,xmax);
      THStack *hs_emu=new THStack("hs_emu","");
      TH1F *hist_nonres_emu=new TH1F("hist_nonres_emu","",Nbins,xmin,xmax);
      TH1F *hist_mH260_emu=new TH1F("hist_mH260_emu","",Nbins,xmin,xmax);
      TH1F *hist_mH300_emu=new TH1F("hist_mH300_emu","",Nbins,xmin,xmax);
      TH1F *hist_mH400_emu=new TH1F("hist_mH400_emu","",Nbins,xmin,xmax);
      TH1F *hist_mH500_emu=new TH1F("hist_mH500_emu","",Nbins,xmin,xmax);
      TH1F *hist_data_emu=new TH1F("hist_data_emu","",Nbins,xmin,xmax);
      TH1F *hist_promptSS_emu=new TH1F("hist_promptSS_emu","",Nbins,xmin,xmax);
      TH1F *hist_Vgam_emu=new TH1F("hist_Vgam_emu","",Nbins,xmin,xmax);
      TH1F *hist_QmisID_emu=new TH1F("hist_QmisID_emu","",Nbins,xmin,xmax);
      TH1F *hist_fake_emu=new TH1F("hist_fake_emu","",Nbins,xmin,xmax);
      TH1F *hist_fake_antiemu=new TH1F("hist_fake_antiemu","",Nbins,xmin,xmax);
      TH1F *hist_fake_eantimu=new TH1F("hist_fake_eantimu","",Nbins,xmin,xmax);
      
      Float_t Lumi=lumi(); Double_t sf_ee=1, sf_mumu=1, sf_emu=1;
      Double_t num_antiemu(0), num_eantimu(0);
      for(Long64_t entry=0; entry<nonres->GetEntries();entry++) {
          nonres->GetEntry(entry);
          //if(nonres_numOfjet<3)continue;
          if(nonres_channel==1) hist_nonres_ee->Fill(nonres_var,nonres_weight*sf_ee);
          if(nonres_channel==2) hist_nonres_mumu->Fill(nonres_var,nonres_weight*sf_mumu);
          if(nonres_channel==3) hist_nonres_emu->Fill(nonres_var,nonres_weight*sf_emu);
      }
      for(Long64_t entry=0; entry<mH260->GetEntries();entry++) {
          mH260->GetEntry(entry);
          //if(mH260_numOfjet<3)continue;
          if(mH260_channel==1) hist_mH260_ee->Fill(mH260_var,mH260_weight*sf_ee);
          if(mH260_channel==2) hist_mH260_mumu->Fill(mH260_var,mH260_weight*sf_mumu);
          if(mH260_channel==3) hist_mH260_emu->Fill(mH260_var,mH260_weight*sf_emu);
      }
      for(Long64_t entry=0; entry<mH300->GetEntries();entry++) {
          mH300->GetEntry(entry);
          //if(mH300_numOfjet<3)continue;
          if(mH300_channel==1) hist_mH300_ee->Fill(mH300_var,mH300_weight*sf_ee);
          if(mH300_channel==2) hist_mH300_mumu->Fill(mH300_var,mH300_weight*sf_mumu);
          if(mH300_channel==3) hist_mH300_emu->Fill(mH300_var,mH300_weight*sf_emu);
      }
      for(Long64_t entry=0; entry<mH400->GetEntries();entry++) {
          mH400->GetEntry(entry);
          //if(mH400_numOfjet<3)continue;
          if(mH400_channel==1) hist_mH400_ee->Fill(mH400_var,mH400_weight*sf_ee);
          if(mH400_channel==2) hist_mH400_mumu->Fill(mH400_var,mH400_weight*sf_mumu);
          if(mH400_channel==3) hist_mH400_emu->Fill(mH400_var,mH400_weight*sf_emu);
      }
      for(Long64_t entry=0; entry<mH500->GetEntries();entry++) {
          mH500->GetEntry(entry);
          //if(mH500_numOfjet<3)continue;
          if(mH500_channel==1) hist_mH500_ee->Fill(mH500_var,mH500_weight*sf_ee);
          if(mH500_channel==2) hist_mH500_mumu->Fill(mH500_var,mH500_weight*sf_mumu);
          if(mH500_channel==3) hist_mH500_emu->Fill(mH500_var,mH500_weight*sf_emu);
      }
      for(Long64_t entry=0; entry<data->GetEntries();entry++) {
          data->GetEntry(entry);
          if(data_channel==1) hist_data_ee->Fill(data_var,data_weight);
          if(data_channel==2) hist_data_mumu->Fill(data_var,data_weight);
          if(data_channel==3) hist_data_emu->Fill(data_var,data_weight);
      }
      Long64_t nentries=totalbkg->GetEntries();
      cout<<"total bkg entries: "<<nentries<<endl;
      for(Long64_t entry=0; entry<nentries;entry++) {
          totalbkg->GetEntry(entry);
          //if(totalbkg_numOfjet<3)continue;
          if(totalbkg_channel==1){
             if((*totalbkg_component)=="Vgam")hist_Vgam_ee->Fill(totalbkg_var,totalbkg_weight);
             if((*totalbkg_component)=="QmisID")hist_QmisID_ee->Fill(totalbkg_var,totalbkg_weight);
             if((*totalbkg_component)=="fake") hist_fake_ee->Fill(totalbkg_var,totalbkg_weight);
             if((*totalbkg_component)!="Vgam"&&(*totalbkg_component)!="QmisID"&&(*totalbkg_component)!="fake") 
                 hist_promptSS_ee->Fill(totalbkg_var,totalbkg_weight);
          }
          if(totalbkg_channel==2){
             if((*totalbkg_component)=="QmisID")hist_QmisID_mumu->Fill(totalbkg_var,totalbkg_weight);
             if((*totalbkg_component)=="Vgam")hist_Vgam_mumu->Fill(totalbkg_var,totalbkg_weight);
             if((*totalbkg_component)=="fake"&&(*totalbkg_component)!="ttbar"&&(*totalbkg_component)!="Zjets"&& 
                       (*totalbkg_component)!="DY") hist_fake_mumu->Fill(totalbkg_var,totalbkg_weight);
             if((*totalbkg_component)!="Vgam"&&(*totalbkg_component)!="QmisID"&&(*totalbkg_component)!="fake")
              hist_promptSS_mumu->Fill(totalbkg_var,totalbkg_weight);
          }
          if(totalbkg_channel==3) {
             if((*totalbkg_component)=="Vgam")hist_Vgam_emu->Fill(totalbkg_var,totalbkg_weight);
             if((*totalbkg_component)=="QmisID")hist_QmisID_emu->Fill(totalbkg_var,totalbkg_weight);
             if((*totalbkg_component)=="fake") {
                hist_fake_emu->Fill(totalbkg_var,totalbkg_weight);
                if(totalbkg_category==22){ num_antiemu+=totalbkg_weight; hist_fake_antiemu->Fill(totalbkg_var,totalbkg_weight);}
                if(totalbkg_category==23){num_eantimu+=totalbkg_weight; hist_fake_eantimu->Fill(totalbkg_var,totalbkg_weight);}
             }
             if((*totalbkg_component)!="Vgam"&&(*totalbkg_component)!="QmisID"&&(*totalbkg_component)!="fake") 
              hist_promptSS_emu->Fill(totalbkg_var,totalbkg_weight);
          }
      }
      //scale singal to data
      Float_t sum_data_ee=hist_data_ee->Integral(0,Nbins+1);
      Float_t sum_data_mumu=hist_data_mumu->Integral(0,Nbins+1);
      Float_t sum_data_emu=hist_data_emu->Integral(0,Nbins+1);
      Float_t sum_nonres_ee=hist_nonres_ee->Integral(0,Nbins+1);
      Float_t sum_nonres_mumu=hist_nonres_mumu->Integral(0,Nbins+1);
      Float_t sum_nonres_emu=hist_nonres_emu->Integral(0,Nbins+1);
      Float_t sum_mH260_ee=hist_mH260_ee->Integral(0,Nbins+1);
      Float_t sum_mH260_mumu=hist_mH260_mumu->Integral(0,Nbins+1);
      Float_t sum_mH260_emu=hist_mH260_emu->Integral(0,Nbins+1);
      Float_t sum_mH300_ee=hist_mH300_ee->Integral(0,Nbins+1);
      Float_t sum_mH300_mumu=hist_mH300_mumu->Integral(0,Nbins+1);
      Float_t sum_mH300_emu=hist_mH300_emu->Integral(0,Nbins+1);
      Float_t sum_mH400_ee=hist_mH400_ee->Integral(0,Nbins+1);
      Float_t sum_mH400_mumu=hist_mH400_mumu->Integral(0,Nbins+1);
      Float_t sum_mH400_emu=hist_mH400_emu->Integral(0,Nbins+1);
      Float_t sum_mH500_ee=hist_mH500_ee->Integral(0,Nbins+1);
      Float_t sum_mH500_mumu=hist_mH500_mumu->Integral(0,Nbins+1);
      Float_t sum_mH500_emu=hist_mH500_emu->Integral(0,Nbins+1);
      hist_nonres_ee->Scale(sum_data_ee/sum_nonres_ee);
      hist_nonres_mumu->Scale(sum_data_mumu/sum_nonres_mumu);
      hist_nonres_emu->Scale(sum_data_emu/sum_nonres_emu);
      hist_mH260_ee->Scale(sum_data_ee/sum_mH260_ee);
      hist_mH260_mumu->Scale(sum_data_mumu/sum_mH260_mumu);
      hist_mH260_emu->Scale(sum_data_emu/sum_mH260_emu);
      hist_mH300_ee->Scale(sum_data_ee/sum_mH300_ee);
      hist_mH300_mumu->Scale(sum_data_mumu/sum_mH300_mumu);
      hist_mH300_emu->Scale(sum_data_emu/sum_mH300_emu);
      hist_mH400_ee->Scale(sum_data_ee/sum_mH400_ee);
      hist_mH400_mumu->Scale(sum_data_mumu/sum_mH400_mumu);
      hist_mH400_emu->Scale(sum_data_emu/sum_mH400_emu);
      hist_mH500_ee->Scale(sum_data_ee/sum_mH500_ee);
      hist_mH500_mumu->Scale(sum_data_mumu/sum_mH500_mumu);
      hist_mH500_emu->Scale(sum_data_emu/sum_mH500_emu);
      //----------------------------------------------------------------------------------
      // do some delcarations before drawing plots
      //----------------------------------------------------------------------------------
      // add hists to hs, ee
      hist_fake_ee->SetFillColor(40);
      hist_promptSS_ee->SetFillColor(43);
      hist_Vgam_ee->SetFillColor(49);
      hist_QmisID_ee->SetFillColor(47);
      hist_fake_ee->SetLineColor(40);
      hist_promptSS_ee->SetLineColor(43);
      hist_Vgam_ee->SetLineColor(49);
      hist_QmisID_ee->SetLineColor(47);
      hs_ee->Add(hist_promptSS_ee); 
      hs_ee->Add(hist_Vgam_ee); 
      hs_ee->Add(hist_QmisID_ee); 
      //hs_ee->Add(hist_fake_ee); //add it later,first calculate total error as we should estimate the uncertainty for fakes separately.
      Float_t varx[200],varx_error[200],ratio_ee[200],ratio_error_ee[200];
      Float_t ratio_bkg_ee[200],ratio_error_bkg_ee[200];
      Float_t stack_ee[200],stack_error_ee[200];
      //mumu
      hist_fake_mumu->SetFillColor(40);
      hist_promptSS_mumu->SetFillColor(43);
      hist_Vgam_mumu->SetFillColor(49);
      hist_fake_mumu->SetLineColor(40);
      hist_promptSS_mumu->SetLineColor(43);
      hist_Vgam_mumu->SetLineColor(49);
      hs_mumu->Add(hist_promptSS_mumu);
      hs_mumu->Add(hist_Vgam_mumu);    
      //hs_mumu->Add(hist_fake_mumu); 
      Float_t ratio_mumu[200],ratio_error_mumu[200];
      Float_t ratio_bkg_mumu[200],ratio_error_bkg_mumu[200];
      Float_t stack_mumu[200],stack_error_mumu[200];
      //emu
      hist_fake_emu->SetFillColor(40);
      hist_promptSS_emu->SetFillColor(43);
      hist_Vgam_emu->SetFillColor(49);
      hist_QmisID_emu->SetFillColor(47);
      hist_fake_emu->SetLineColor(40);
      hist_promptSS_emu->SetLineColor(43);
      hist_Vgam_emu->SetLineColor(49);
      hist_QmisID_emu->SetLineColor(47);
      hs_emu->Add(hist_promptSS_emu);
      hs_emu->Add(hist_Vgam_emu);    
      hs_emu->Add(hist_QmisID_emu);
      //hs_emu->Add(hist_fake_emu); 
      Float_t ratio_emu[200],ratio_error_emu[200];
      Float_t ratio_bkg_emu[200],ratio_error_bkg_emu[200];
      Float_t stack_emu[200],stack_error_emu[200];
      //----------------------------------------------------------------------------------
      // count
      //----------------------------------------------------------------------------------
      cout<<setw(5)<<"ee"<<setw(10)<<"mm"<<setw(10)<<"em"<<endl;
      cout<<setiosflags(ios::fixed)<<setprecision(2);
      double err_fake_ee(0), err_fake_mumu(0), err_fake_emu(0),
             err_promptSS_ee(0), err_promptSS_mumu(0), err_promptSS_emu(0),
             err_Vgam_ee(0), err_Vgam_mumu(0), err_Vgam_emu(0),
             err_QmisID_ee(0), err_QmisID_mumu(0), err_QmisID_emu(0),
             err_predicted_ee(0), err_predicted_mumu(0), err_predicted_emu(0),
             err_data_ee(0), err_data_mumu(0), err_data_emu(0),
             err_predicted_ee_nofake(0), err_predicted_mumu_nofake(0), err_predicted_emu_nofake(0);
      double integral_fake_ee(0), integral_fake_mumu(0), integral_fake_emu(0),
             integral_promptSS_ee(0), integral_promptSS_mumu(0), integral_promptSS_emu(0),
             integral_Vgam_ee(0), integral_Vgam_mumu(0), integral_Vgam_emu(0),
             integral_QmisID_ee(0), integral_QmisID_mumu(0), integral_QmisID_emu(0),
             integral_predicted_ee(0), integral_predicted_mumu(0), integral_predicted_emu(0),
             integral_data_ee(0), integral_data_mumu(0), integral_data_emu(0);
      integral_fake_ee=hist_fake_ee->Integral(0,Nbins+1);
      integral_fake_mumu=hist_fake_mumu->Integral(0,Nbins+1);
      integral_fake_emu=hist_fake_emu->Integral(0,Nbins+1);
      err_fake_ee=sqrt(pow(sys_ele*integral_fake_ee,2)+integral_fake_ee*ff_ele);
      err_fake_mumu=sqrt(pow(sys_mu*integral_fake_mumu,2)+integral_fake_mumu*ff_mu);
      num_eantimu=hist_fake_eantimu->Integral(0,Nbins+1);
      num_antiemu=hist_fake_antiemu->Integral(0,Nbins+1);
      err_fake_emu=sqrt(pow(sys_mu*num_eantimu,2)+ff_mu*num_eantimu + 
                    pow(sys_ele*num_antiemu,2)+ff_ele*num_antiemu);
      integral_promptSS_ee=hist_promptSS_ee->IntegralAndError(0,Nbins+1,err_promptSS_ee);
      integral_promptSS_mumu=hist_promptSS_mumu->IntegralAndError(0,Nbins+1,err_promptSS_mumu);
      integral_promptSS_emu=hist_promptSS_emu->IntegralAndError(0,Nbins+1,err_promptSS_emu);
      integral_Vgam_ee=hist_Vgam_ee->IntegralAndError(0,Nbins+1,err_Vgam_ee);
      integral_Vgam_mumu=hist_Vgam_mumu->IntegralAndError(0,Nbins+1,err_Vgam_mumu);
      integral_Vgam_emu=hist_Vgam_emu->IntegralAndError(0,Nbins+1,err_Vgam_emu);
      integral_QmisID_ee=hist_QmisID_ee->IntegralAndError(0,Nbins+1,err_QmisID_ee);
      integral_QmisID_mumu=hist_QmisID_mumu->IntegralAndError(0,Nbins+1,err_QmisID_mumu);
      integral_QmisID_emu=hist_QmisID_emu->IntegralAndError(0,Nbins+1,err_QmisID_emu);
      integral_predicted_ee=((TH1*)(hs_ee->GetStack()->Last()))->IntegralAndError(0,Nbins+1,err_predicted_ee_nofake)+
                            hist_fake_ee->Integral(0,Nbins+1);; 
      integral_predicted_mumu=((TH1*)(hs_mumu->GetStack()->Last()))->IntegralAndError(0,Nbins+1,err_predicted_mumu_nofake)+
                            hist_fake_mumu->Integral(0,Nbins+1);
      integral_predicted_emu=((TH1*)(hs_emu->GetStack()->Last()))->IntegralAndError(0,Nbins+1,err_predicted_emu_nofake)+
                            hist_fake_emu->Integral(0,Nbins+1);
      err_predicted_ee=sqrt(pow(err_predicted_ee_nofake,2)+pow(err_fake_ee,2));
      err_predicted_mumu=sqrt(pow(err_predicted_mumu_nofake,2)+pow(err_fake_mumu,2));
      err_predicted_emu=sqrt(pow(err_predicted_emu_nofake,2)+pow(err_fake_emu,2));
      integral_data_ee=hist_data_ee->IntegralAndError(0,Nbins+1,err_data_ee);
      integral_data_mumu=hist_data_mumu->IntegralAndError(0,Nbins+1,err_data_mumu);
      integral_data_emu=hist_data_emu->IntegralAndError(0,Nbins+1,err_data_emu);
      cout<<"Jet fakes "<<setw(8)<<"&"<<integral_fake_ee<<"$\\pm$"<<err_fake_ee<<setw(10)<<
                          setw(8)<<"&"<<integral_fake_mumu<<"$\\pm$"<<err_fake_mumu<<setw(10)<<
                          setw(8)<<"&"<<integral_fake_emu<<"$\\pm$"<<err_fake_emu<<setw(10)<<endl;
      cout<<"PromptSS "<<setw(8)<<"&"<<integral_promptSS_ee<<"$\\pm$"<<err_promptSS_ee<<setw(10)<<
                          setw(8)<<"&"<<integral_promptSS_mumu<<"$\\pm$"<<err_promptSS_mumu<<setw(10)<<      
                          setw(8)<<"&"<<integral_promptSS_emu<<"$\\pm$"<<err_promptSS_emu<<setw(10)<<endl;
      cout<<"$V+\\gamma$ "<<setw(8)<<"&"<<integral_Vgam_ee<<"$\\pm$"<<err_Vgam_ee<<setw(10)<<  
                          setw(8)<<"&"<<integral_Vgam_mumu<<"$\\pm$"<<err_Vgam_mumu<<setw(10)<<       
                          setw(8)<<"&"<<integral_Vgam_emu<<"$\\pm$"<<err_Vgam_emu<<setw(10)<<endl;
      cout<<"QmisID "<<setw(8)<<"&"<<integral_QmisID_ee<<"$\\pm$"<<err_QmisID_ee<<setw(10)<<
                        setw(8)<<"&"<<integral_QmisID_mumu<<"$\\pm$"<<err_QmisID_mumu<<setw(10)<<   
                        setw(8)<<"&"<<integral_QmisID_emu<<"$\\pm$"<<err_QmisID_emu<<setw(10)<<endl;
      cout<<"Total backgrounds "<<setw(8)<<"&"<<integral_predicted_ee<<"$\\pm$"<<err_predicted_ee<<setw(10)<<     
                                 setw(8)<<"&"<<integral_predicted_mumu<<"$\\pm$"<<err_predicted_mumu<<setw(10)<<
                                 setw(8)<<"&"<<integral_predicted_emu<<"$\\pm$"<< err_predicted_emu<<endl; 
      cout<<"Observed "<<setw(8)<<"&"<<integral_data_ee<< 
                          setw(8)<<"&"<<integral_data_mumu<<    
                          setw(8)<<"&"<<integral_data_emu<<endl;
      //get ratios, errors, etc..ee
      for(Int_t bin=0;bin<Nbins;bin++){
          //ratio, mean values, width, first determined here, commonly used for 3 channels
          varx[bin]=xmin+(bin+0.5)*(hist_fake_ee->GetBinWidth(1));
          varx_error[bin]=(hist_fake_ee->GetBinWidth(1))/2.;
          //data, bkg bincontents and errors
          Float_t bincontent_data=hist_data_ee->GetBinContent(bin+1);
          Float_t binerror_data=hist_data_ee->GetBinError(bin+1);
          Float_t bincontent_bkg_nofake=((TH1*)(hs_ee->GetStack()->Last()))->GetBinContent(bin+1);
          Float_t bincontent_bkg_fake=hist_fake_ee->GetBinContent(bin+1);
          Float_t bincontent_bkg=bincontent_bkg_nofake+bincontent_bkg_fake;
          Float_t binerror_bkg_nofake=((TH1*)(hs_ee->GetStack()->Last()))->GetBinError(bin+1);
          Float_t binerror_fake=sqrt(pow(sys_ele*bincontent_bkg_fake,2)+ff_ele*bincontent_bkg_fake);
          Float_t binerror_bkg=sqrt(pow(binerror_bkg_nofake,2)+pow(binerror_fake,2));
          //to get bkg errors
          stack_ee[bin]=bincontent_bkg; stack_error_ee[bin]=binerror_bkg;
          //ratio plot: mean values, data error, bkg error
          ratio_ee[bin]=bincontent_data/bincontent_bkg;
          ratio_error_ee[bin]=binerror_data/bincontent_bkg;
          ratio_bkg_ee[bin]=1.;
          ratio_error_bkg_ee[bin]=binerror_bkg/bincontent_bkg;
      }
      //mumu
      for(Int_t bin=0;bin<Nbins;bin++){
          //data, bkg bincontents and errors
          Float_t bincontent_data=hist_data_mumu->GetBinContent(bin+1);
          Float_t binerror_data=hist_data_mumu->GetBinError(bin+1);
          Float_t bincontent_bkg_nofake=((TH1*)(hs_mumu->GetStack()->Last()))->GetBinContent(bin+1);
          Float_t bincontent_bkg_fake=hist_fake_mumu->GetBinContent(bin+1);
          Float_t bincontent_bkg=bincontent_bkg_nofake+bincontent_bkg_fake;
          Float_t binerror_bkg_nofake=((TH1*)(hs_mumu->GetStack()->Last()))->GetBinError(bin+1);
          Float_t binerror_fake=sqrt(pow(sys_mu*bincontent_bkg_fake,2)+ff_mu*bincontent_bkg_fake);
          Float_t binerror_bkg=sqrt(pow(binerror_bkg_nofake,2)+pow(binerror_fake,2));
          //to get bkg errors
          stack_mumu[bin]=bincontent_bkg; stack_error_mumu[bin]=binerror_bkg;
          //ratio plot: mean values, data error, bkg error
          ratio_mumu[bin]=bincontent_data/bincontent_bkg;
          ratio_error_mumu[bin]=binerror_data/bincontent_bkg;
          ratio_bkg_mumu[bin]=1.;
          ratio_error_bkg_mumu[bin]=binerror_bkg/bincontent_bkg;
      }
      //emu
      for(Int_t bin=0;bin<Nbins;bin++){
          //data, bkg bincontents and errors
          Float_t bincontent_data=hist_data_emu->GetBinContent(bin+1);
          Float_t binerror_data=hist_data_emu->GetBinError(bin+1);
          Float_t bincontent_bkg_nofake=((TH1*)(hs_emu->GetStack()->Last()))->GetBinContent(bin+1);
          Float_t bincontent_bkg_fake_antiemu=hist_fake_antiemu->GetBinContent(bin+1);
          Float_t bincontent_bkg_fake_eantimu=hist_fake_eantimu->GetBinContent(bin+1);
          Float_t bincontent_bkg_fake=hist_fake_emu->GetBinContent(bin+1);
          Float_t bincontent_bkg=bincontent_bkg_nofake+bincontent_bkg_fake;
          Float_t binerror_bkg_nofake=((TH1*)(hs_emu->GetStack()->Last()))->GetBinError(bin+1);
          Float_t binerror_bkg_fake=sqrt(pow(sys_ele*bincontent_bkg_fake_antiemu,2)+ff_ele*bincontent_bkg_fake_antiemu +
                                         pow(sys_mu*bincontent_bkg_fake_eantimu,2)+ff_mu*bincontent_bkg_fake_eantimu);
          Float_t binerror_bkg=sqrt(pow(binerror_bkg_nofake,2)+pow(binerror_bkg_fake,2));
          //to get bkg errors
          stack_emu[bin]=bincontent_bkg; stack_error_emu[bin]=binerror_bkg;
          //ratio plot: mean values, data error, bkg error
          ratio_emu[bin]=bincontent_data/bincontent_bkg;
          ratio_error_emu[bin]=binerror_data/bincontent_bkg;
          ratio_bkg_emu[bin]=1.;
          ratio_error_bkg_emu[bin]=binerror_bkg/bincontent_bkg;
      }
      hs_ee->Add(hist_fake_ee);
      hs_mumu->Add(hist_fake_mumu);
      hs_emu->Add(hist_fake_emu);
      //-----------------------------------------------------------------------------
      //draw plots
      //-----------------------------------------------------------------------------
      Double_t Ymaximum_ee=0, Ymaximum_mumu=0, Ymaximum_emu=0;
      Ymaximum_ee=1.5*GetMaxBinContent(hist_data_ee);
      if(Ymaximum_ee<1.5*GetMaxBinContent(hs_ee))Ymaximum_ee=1.5*GetMaxBinContent(hs_ee);
      Ymaximum_mumu=1.5*GetMaxBinContent(hist_data_mumu);
      if(Ymaximum_mumu<1.5*GetMaxBinContent(hs_mumu))Ymaximum_mumu=1.5*GetMaxBinContent(hs_mumu);
      Ymaximum_emu=1.5*GetMaxBinContent(hist_data_emu);
      if(Ymaximum_emu<1.5*GetMaxBinContent(hs_emu))Ymaximum_emu=1.5*GetMaxBinContent(hs_emu);
      //ee
      TCanvas *c_hist_ee=new TCanvas("c_hist_ee","",900,800);
      gStyle->SetLineWidth(2);  
      gPad->SetLineWidth(2);
      TPad *pad1_ee=new TPad("pad1_ee","pad1_ee",0,0.33,1,1.0);
      pad1_ee->SetBottomMargin(0.0); // Upper and lower plot are joined
      pad1_ee->SetTopMargin(0.05);
      pad1_ee->Draw();
      pad1_ee->cd();
      TLegend *leg_ee= new TLegend(0.75,0.50,0.97,0.90);
      leg_ee->SetFillStyle(0);
      leg_ee->SetBorderSize(0);
      leg_ee->SetTextFont(62);
      leg_ee->SetTextSize(0.03);
      leg_ee->AddEntry(hist_nonres_ee,"non-res","l");
      leg_ee->AddEntry(hist_mH260_ee,"H260","l");
      leg_ee->AddEntry(hist_mH300_ee,"H300","l");
      leg_ee->AddEntry(hist_mH400_ee,"H400","l");
      leg_ee->AddEntry(hist_mH500_ee,"H500","l");
      leg_ee->AddEntry(hist_data_ee,"Data","lp");
      leg_ee->AddEntry(hist_promptSS_ee,"PromptSS","f");
      leg_ee->AddEntry(hist_Vgam_ee,"V#gamma","f");
      leg_ee->AddEntry(hist_QmisID_ee,"QmisID","f");
      leg_ee->AddEntry(hist_fake_ee,"Fakes","f");
      frame_ee->SetMaximum(Ymaximum_ee);
      frame_ee->SetMinimum(0.001);
      frame_ee->GetYaxis()->SetTitleSize(0.06);
      frame_ee->GetYaxis()->SetTitleOffset(1);
      frame_ee->GetYaxis()->SetTitle("Num. Of Events");
      hist_nonres_ee->SetLineColor(kRed);
      hist_mH260_ee->SetLineColor(kBlue);
      hist_mH300_ee->SetLineColor(kGreen);
      hist_mH400_ee->SetLineColor(6);
      hist_mH500_ee->SetLineColor(7);
      frame_ee->Draw();
      hs_ee->Draw("histsame");
      hist_nonres_ee->Draw("histsame");
      hist_mH260_ee->Draw("histsame");
      hist_mH300_ee->Draw("histsame");
      hist_mH400_ee->Draw("histsame");
      hist_mH500_ee->Draw("histsame");
      hist_data_ee->Draw("e same");
      leg_ee->Draw("same");
      myText(0.55, 0.87, 1, "ee");
      ATLAS_LABEL(0.20, 0.87 );
      myText( 0.31, 0.87 , 1, "Internal");
      myText( 0.20, 0.78 , 1, "#sqrt{s} = 13 TeV");
      myText( 0.37, 0.78 , 1, "#intLdt = 36.1 fb^{-1}");
      TGraphErrors *gr_stack_ee=new TGraphErrors(Nbins,varx,stack_ee,varx_error,stack_error_ee);
      gr_stack_ee->SetFillColor(6);
      gStyle->SetHatchesLineWidth(3);
      gr_stack_ee->SetFillStyle(3004);
      gr_stack_ee->Draw("2 same");
      c_hist_ee->Update();
      //pad2, for ratio
      c_hist_ee->cd();
      TPad *pad2_ee = new TPad("pad2_ee", "pad2_ee", 0, 0.01, 1, 0.33);
      pad2_ee->SetTopMargin(0);
      pad2_ee->SetBottomMargin(0.30);
      pad2_ee->SetTicks(); // vertical grid
      pad2_ee->Draw();
      pad2_ee->cd();
      TGraphErrors *gr_ee=new TGraphErrors(Nbins,varx,ratio_ee,varx_error,ratio_error_ee);
      gr_ee->GetYaxis()->SetTitle("Data/Bkg");
      gr_ee->GetXaxis()->SetTitle(varx_title);
      gr_ee->GetXaxis()->SetLabelSize(0.1);
      gr_ee->GetXaxis()->SetLabelOffset(0.025);
      gr_ee->GetXaxis()->SetTitleSize(0.13);
      gr_ee->GetXaxis()->SetTitleOffset(1.);
      gr_ee->GetYaxis()->SetLabelSize(0.1);
      gr_ee->GetYaxis()->SetTitleSize(0.14);
      gr_ee->GetYaxis()->SetTitleOffset(0.40);
      gr_ee->GetYaxis()->SetNdivisions(505);
      gr_ee->SetMarkerSize(0.4);
      gr_ee->SetMarkerStyle(20);
      gr_ee->GetXaxis()->SetRangeUser(xmin,xmax);
      gr_ee->GetYaxis()->SetRangeUser(0,2.1);
      gr_ee->Draw("AP same");
      TLine* line_ee=new TLine();
      line_ee->DrawLine(xmin,1.0,xmax,1.0);
      line_ee->SetLineColor(kBlack);
      line_ee->SetLineStyle(kDashed);
      line_ee->DrawLine(xmin,0.5,xmax,0.5);
      line_ee->DrawLine(xmin,1.5,xmax,1.5);
      TGraphErrors *gr_ratio_bkg_ee=new TGraphErrors(Nbins,varx,ratio_bkg_ee,varx_error,ratio_error_bkg_ee);
      gr_ratio_bkg_ee->SetFillColor(6);
      gr_ratio_bkg_ee->SetFillStyle(3004);
      gr_ratio_bkg_ee->Draw("2 same");
      //c_hist_ee->SaveAs(output_ee_png);
      c_hist_ee->SaveAs(output_ee_pdf);
      //mumu 
      TCanvas *c_hist_mumu=new TCanvas("c_hist_mumu","",900,800);
      gStyle->SetLineWidth(2);  
      gPad->SetLineWidth(2);
      TPad *pad1_mumu=new TPad("pad1_mumu","pad1_mumu",0,0.33,1,1.0);
      pad1_mumu->SetBottomMargin(0.0); // Upper and lower plot are joined
      pad1_mumu->SetTopMargin(0.05);
      pad1_mumu->Draw();
      pad1_mumu->cd();
      TLegend *leg_mumu= new TLegend(0.75,0.50,0.97,0.90);
      leg_mumu->SetFillStyle(0);
      leg_mumu->SetBorderSize(0);
      leg_mumu->SetTextFont(62);
      leg_mumu->SetTextSize(0.03);
      leg_mumu->AddEntry(hist_nonres_mumu,"non-res","l");
      leg_mumu->AddEntry(hist_mH260_mumu,"H260","l");
      leg_mumu->AddEntry(hist_mH300_mumu,"H300","l");
      leg_mumu->AddEntry(hist_mH400_mumu,"H400","l");
      leg_mumu->AddEntry(hist_mH500_mumu,"H500","l");
      leg_mumu->AddEntry(hist_data_mumu,"Data","lp");
      leg_mumu->AddEntry(hist_promptSS_mumu,"PromptSS","f");
      leg_mumu->AddEntry(hist_Vgam_mumu,"V#gamma","f");
      //leg_mumu->AddEntry(hist_QmisID_mumu,"QmisID","f");
      leg_mumu->AddEntry(hist_fake_mumu,"Fakes","f");
      frame_mumu->SetMaximum(Ymaximum_mumu);
      frame_mumu->SetMinimum(0.001);
      frame_mumu->GetYaxis()->SetTitleSize(0.06);
      frame_mumu->GetYaxis()->SetTitleOffset(1);
      frame_mumu->GetYaxis()->SetTitle("Num. Of Events");
      hist_nonres_mumu->SetLineColor(kRed);
      hist_mH260_mumu->SetLineColor(kBlue);
      hist_mH300_mumu->SetLineColor(kGreen);
      hist_mH400_mumu->SetLineColor(6);
      hist_mH500_mumu->SetLineColor(7);
      frame_mumu->Draw();
      hs_mumu->Draw("histsame");
      hist_nonres_mumu->Draw("histsame");
      hist_mH260_mumu->Draw("histsame");
      hist_mH300_mumu->Draw("histsame");
      hist_mH400_mumu->Draw("histsame");
      hist_mH500_mumu->Draw("histsame");
      hist_data_mumu->Draw("e same");
      leg_mumu->Draw("same");
      myText(0.55, 0.87, 1, "#mu#mu");
      ATLAS_LABEL(0.20, 0.87 );
      myText( 0.31, 0.87 , 1, "Internal");
      myText( 0.20, 0.78 , 1, "#sqrt{s} = 13 TeV");
      myText( 0.37, 0.78 , 1, "#intLdt = 36.1 fb^{-1}");
      TGraphErrors *gr_stack_mumu=new TGraphErrors(Nbins,varx,stack_mumu,varx_error,stack_error_mumu);
      gr_stack_mumu->SetFillColor(6);
      gr_stack_mumu->SetFillStyle(3004);
      gr_stack_mumu->Draw("2 same");
      c_hist_mumu->Update();
      //pad2, for ratio
      c_hist_mumu->cd();
      TPad *pad2_mumu = new TPad("pad2_mumu", "pad2_mumu", 0, 0.01, 1, 0.33);
      pad2_mumu->SetTopMargin(0);
      pad2_mumu->SetBottomMargin(0.30);
      pad2_mumu->SetTicks(); // vertical grid
      pad2_mumu->Draw();
      pad2_mumu->cd();
      TGraphErrors *gr_mumu=new TGraphErrors(Nbins,varx,ratio_mumu,varx_error,ratio_error_mumu);
      gr_mumu->GetYaxis()->SetTitle("Data/Bkg");
      gr_mumu->GetXaxis()->SetTitle(varx_title);
      gr_mumu->GetXaxis()->SetLabelSize(0.1);
      gr_mumu->GetXaxis()->SetLabelOffset(0.025);
      gr_mumu->GetXaxis()->SetTitleSize(0.13);
      gr_mumu->GetXaxis()->SetTitleOffset(1.);
      gr_mumu->GetYaxis()->SetLabelSize(0.1);
      gr_mumu->GetYaxis()->SetTitleSize(0.14);
      gr_mumu->GetYaxis()->SetTitleOffset(0.40);
      gr_mumu->GetYaxis()->SetNdivisions(505);
      gr_mumu->SetMarkerSize(0.4);
      gr_mumu->SetMarkerStyle(20);
      gr_mumu->GetXaxis()->SetRangeUser(xmin,xmax);
      gr_mumu->GetYaxis()->SetRangeUser(0,2.1);
      gr_mumu->Draw("AP same");
      TLine* line_mumu=new TLine();
      line_mumu->DrawLine(xmin,1.0,xmax,1.0);
      line_mumu->SetLineColor(kBlack);
      line_mumu->SetLineStyle(kDashed);
      line_mumu->DrawLine(xmin,0.5,xmax,0.5);
      line_mumu->DrawLine(xmin,1.5,xmax,1.5);
      TGraphErrors *gr_ratio_bkg_mumu=new TGraphErrors(Nbins,varx,ratio_bkg_mumu,varx_error,ratio_error_bkg_mumu);
      gr_ratio_bkg_mumu->SetFillColor(6);
      gr_ratio_bkg_mumu->SetFillStyle(3004);
      gr_ratio_bkg_mumu->Draw("2 same");
      //c_hist_mumu->SaveAs(output_mumu_png);
      c_hist_mumu->SaveAs(output_mumu_pdf);
      //emu 
      TCanvas *c_hist_emu=new TCanvas("c_hist_emu","",900,800);
      gStyle->SetLineWidth(2);  
      gPad->SetLineWidth(2);
      TPad *pad1_emu=new TPad("pad1_emu","pad1_emu",0,0.33,1,1.0);
      pad1_emu->SetBottomMargin(0.0); // Upper and lower plot are joined
      pad1_emu->SetTopMargin(0.05);
      pad1_emu->Draw();
      pad1_emu->cd();
      TLegend *leg_emu= new TLegend(0.75,0.50,0.97,0.90);
      leg_emu->SetFillStyle(0);
      leg_emu->SetBorderSize(0);
      leg_emu->SetTextFont(62);
      leg_emu->SetTextSize(0.03);
      leg_emu->AddEntry(hist_nonres_emu,"non-res","l");
      leg_emu->AddEntry(hist_mH260_emu,"H260","l");
      leg_emu->AddEntry(hist_mH300_emu,"H300","l");
      leg_emu->AddEntry(hist_mH400_emu,"H400","l");
      leg_emu->AddEntry(hist_mH500_emu,"H500","l");
      leg_emu->AddEntry(hist_data_emu,"Data","lp");
      leg_emu->AddEntry(hist_promptSS_emu,"PromptSS","f");
      leg_emu->AddEntry(hist_Vgam_emu,"V#gamma","f");
      leg_emu->AddEntry(hist_QmisID_emu,"QmisID","f");
      leg_emu->AddEntry(hist_fake_emu,"Fakes","f");
      frame_emu->SetMaximum(Ymaximum_emu);
      frame_emu->SetMinimum(0.001);
      frame_emu->GetYaxis()->SetTitleSize(0.06);
      frame_emu->GetYaxis()->SetTitleOffset(1);
      frame_emu->GetYaxis()->SetTitle("Num. Of Events");
      hist_nonres_emu->SetLineColor(kRed);
      hist_mH260_emu->SetLineColor(kBlue);
      hist_mH300_emu->SetLineColor(kGreen);
      hist_mH400_emu->SetLineColor(6);
      hist_mH500_emu->SetLineColor(7);
      frame_emu->Draw();
      hs_emu->Draw("histsame");
      hist_nonres_emu->Draw("histsame");
      hist_mH260_emu->Draw("histsame");
      hist_mH300_emu->Draw("histsame");
      hist_mH400_emu->Draw("histsame");
      hist_mH500_emu->Draw("histsame");
      hist_data_emu->Draw("e same");
      leg_emu->Draw("same");
      ATLAS_LABEL(0.20, 0.87 );
      myText(0.55, 0.87, 1, "e#mu");
      myText( 0.31, 0.87 , 1, "Internal");
      myText( 0.20, 0.78 , 1, "#sqrt{s} = 13 TeV");
      myText( 0.37, 0.78 , 1, "#intLdt = 36.1 fb^{-1}");
      TGraphErrors *gr_stack_emu=new TGraphErrors(Nbins,varx,stack_emu,varx_error,stack_error_emu);
      gr_stack_emu->SetFillColor(6);
      gr_stack_emu->SetFillStyle(3004);
      gr_stack_emu->Draw("2 same");
      c_hist_emu->Update();
      //pad2, for ratio
      c_hist_emu->cd();
      TPad *pad2_emu = new TPad("pad2_emu", "pad2_emu", 0, 0.01, 1, 0.33);
      pad2_emu->SetTopMargin(0);
      pad2_emu->SetBottomMargin(0.30);
      pad2_emu->SetTicks(); // vertical grid
      pad2_emu->Draw();
      pad2_emu->cd();
      TGraphErrors *gr_emu=new TGraphErrors(Nbins,varx,ratio_emu,varx_error,ratio_error_emu);
      gr_emu->GetYaxis()->SetTitle("Data/Bkg");
      gr_emu->GetXaxis()->SetTitle(varx_title);
      gr_emu->GetXaxis()->SetLabelSize(0.1);
      gr_emu->GetXaxis()->SetLabelOffset(0.025);
      gr_emu->GetXaxis()->SetTitleSize(0.13);
      gr_emu->GetXaxis()->SetTitleOffset(1.);
      gr_emu->GetYaxis()->SetLabelSize(0.1);
      gr_emu->GetYaxis()->SetTitleSize(0.14);
      gr_emu->GetYaxis()->SetTitleOffset(0.40);
      gr_emu->GetYaxis()->SetNdivisions(505);
      gr_emu->SetMarkerSize(0.4);
      gr_emu->SetMarkerStyle(20);
      gr_emu->GetXaxis()->SetRangeUser(xmin,xmax);
      gr_emu->GetYaxis()->SetRangeUser(0,2.1);
      gr_emu->Draw("AP same");
      TLine* line_emu=new TLine();
      line_emu->DrawLine(xmin,1.0,xmax,1.0);
      line_emu->SetLineColor(kBlack);
      line_emu->SetLineStyle(kDashed);
      line_emu->DrawLine(xmin,0.5,xmax,0.5);
      line_emu->DrawLine(xmin,1.5,xmax,1.5);
      TGraphErrors *gr_ratio_bkg_emu=new TGraphErrors(Nbins,varx,ratio_bkg_emu,varx_error,ratio_error_bkg_emu);
      gr_ratio_bkg_emu->SetFillColor(6);
      gr_ratio_bkg_emu->SetFillStyle(3004);
      gr_ratio_bkg_emu->Draw("2 same");
      //c_hist_emu->SaveAs(output_emu_png);
      c_hist_emu->SaveAs(output_emu_pdf);

      //delete 
      /*delete frame_ee;
      delete hs_ee;
      delete hist_nonres_ee;
      delete hist_mH260_ee;
      delete hist_mH300_ee;
      delete hist_mH400_ee;
      delete hist_mH500_ee;
      delete hist_data_ee;
      delete hist_promptSS_ee;
      delete hist_Vgam_ee;
      delete hist_QmisID_ee;
      delete hist_fake_ee;
      delete frame_mumu;
      delete hs_mumu;
      delete hist_nonres_mumu;
      delete hist_mH260_mumu;
      delete hist_mH300_mumu;
      delete hist_mH400_mumu;
      delete hist_mH500_mumu;
      delete hist_data_mumu;
      delete hist_promptSS_mumu;
      delete hist_Vgam_mumu;
      delete hist_QmisID_mumu;
      delete hist_fake_mumu;
      delete frame_emu;
      delete hs_emu;
      delete hist_nonres_emu;
      delete hist_mH260_emu;
      delete hist_mH300_emu;
      delete hist_mH400_emu;
      delete hist_mH500_emu;
      delete hist_data_emu;
      delete hist_promptSS_emu;
      delete hist_Vgam_emu;
      delete hist_QmisID_emu;
      delete hist_fake_emu;
      delete c_hist_ee;
      delete c_hist_mumu;
      delete c_hist_emu;
      nonres               ->ResetBranchAddresses();
      mH260                ->ResetBranchAddresses();
      mH300	 	   ->ResetBranchAddresses();
      mH400		   ->ResetBranchAddresses();
      mH500		   ->ResetBranchAddresses();
      data		   ->ResetBranchAddresses();
      totalbkg		   ->ResetBranchAddresses();*/
  }//end of loop   
//end of manin func
}
