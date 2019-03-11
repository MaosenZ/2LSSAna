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
#include "TLine.h"
#include "../../atlasstyle-00-03-05/AtlasStyle.C"
#include "../../atlasstyle-00-03-05/AtlasUtils.C"
using namespace std;
using namespace TMath;
void nominal(){
   SetAtlasStyle();
  //Get trees and variables 
  TString vars[]={"pt_leadinglepton","pt_j1","m_ll","MET","pt_sublepton","pt_j2","m_jj","m_jj_w","m_l1jj","mindR_l1j","mindR_l2j","pt_sum","m_all","Mt","m_l1j","m_l2j","RMS","numOfjet"};
  TString vars_titles[]={"pT(l#lower[0.5]{1})","pT(j#lower[0.5]{1})","M(ll)","#slash{E}_{T}","Pt(l_{2})","Pt(j_{2})","M(jj)","M(jj)^{w}","M(l_{1}jj)","#DeltaR_{min}(l_{1},j)","#DeltaR_{min}(l_{2},j)","Pt(all)^{vec}","M(all)","Mt","M(l_{1}j)","M(l_{2}j)","RMS","Njet"};

  TFile *f_ttV=new TFile("output/nominal/miniNtuple_ttV.root");
  TFile *f_tV=new TFile("output/nominal/miniNtuple_tV.root");
  TFile *f_ttH=new TFile("output/nominal/miniNtuple_ttH.root");
  TFile *f_DY=new TFile("output/nominal/miniNtuple_DY.root");
  TFile *f_Zjets=new TFile("output/nominal/miniNtuple_Zjets.root");
  TFile *f_data=new TFile("output/nominal/miniNtuple_datacombined.root");
  TFile *f_diboson=new TFile("output/nominal/miniNtuple_diboson.root");
  TFile *f_Vgam=new TFile("output/nominal/miniNtuple_Vgam.root");
  TFile *f_ttbar=new TFile("output/nominal/miniNtuple_ttbar.root");
  TFile *f_Wjets=new TFile("output/nominal/miniNtuple_Wjets.root");
  //TFile *f_Zjets=new TFile("/scratchfs/atlas/zhoums/2LSSAna_output/output/ZjetsCR/miniNtuple_Zjets.root");
  
  TTree *ttV=(TTree*)f_ttV->Get("Tree");
  TTree *tV=(TTree*)f_tV->Get("Tree");
  TTree *ttH=(TTree*)f_ttH->Get("Tree");
  TTree *DY=(TTree*)f_DY->Get("Tree");
  //TTree *Zjets=(TTree*)f_Zjets->Get("Tree");
  TTree *data=(TTree*)f_data->Get("Tree");
  TTree *diboson=(TTree*)f_diboson->Get("Tree");
  TTree *Vgam=(TTree*)f_Vgam->Get("Tree");
  TTree *ttbar=(TTree*)f_ttbar->Get("Tree");
  TTree *Wjets=(TTree*)f_Wjets->Get("Tree");
  TTree *Zjets=(TTree*)f_Zjets->Get("Tree");
  for(Int_t index=17;index<18;index++){
      Int_t ttV_var,tV_var,ttH_var,DY_var,Zjets_var,data_var,
              diboson_var,Vgam_var,ttbar_var,Wjets_var;
      Double_t ttV_weight,tV_weight,ttH_weight,DY_weight,Zjets_weight,data_weight,diboson_weight,
               Vgam_weight,ttbar_weight,Wjets_weight;
      Int_t ttV_channel,tV_channel,ttH_channel,DY_channel,Zjets_channel,data_channel,diboson_channel,
            Vgam_channel,ttbar_channel,Wjets_channel;
      TString var=vars[index], varx_title=vars_titles[index] ;
      TString output_ee_png="output/nominal_plots/"; output_ee_png+=var; output_ee_png+="_ee.png";
      TString output_ee_pdf="output/nominal_plots/"; output_ee_pdf+=var; output_ee_pdf+="_ee.pdf";
      TString output_mumu_png="output/nominal_plots/"; output_mumu_png+=var; output_mumu_png+="_mumu.png";
      TString output_mumu_pdf="output/nominal_plots/"; output_mumu_pdf+=var; output_mumu_pdf+="_mumu.pdf";
      TString output_emu_png="output/nominal_plots/"; output_emu_png+=var; output_emu_png+="_emu.png";
      TString output_emu_pdf="output/nominal_plots/"; output_emu_pdf+=var; output_emu_pdf+="_emu.pdf";
      Int_t Nbins, xmin, xmax;
      if(index<=7 || index==11 ||index==14 || index==15){ Nbins=40; xmin=0; xmax=200;}
      if(index==8){ Nbins=50; xmin=0; xmax=500;}
      if(index==9||index==10||index==16){ Nbins=30; xmin=0; xmax=6;}
      if(index>=12 && index<=13){  Nbins=100; xmin=0; xmax=1000;}
      if(index==17){Nbins=10;xmin=0;xmax=10;}
      cout<<"var: "<<var<<endl;
      ttV->SetBranchAddress(var,&ttV_var);
      tV->SetBranchAddress(var,&tV_var);
      ttH->SetBranchAddress(var,&ttH_var);
      DY->SetBranchAddress(var,&DY_var);
      Zjets->SetBranchAddress(var,&Zjets_var);
      data->SetBranchAddress(var,&data_var);
      diboson->SetBranchAddress(var,&diboson_var);
      Vgam->SetBranchAddress(var,&Vgam_var);
      ttbar->SetBranchAddress(var,&ttbar_var);
      Wjets->SetBranchAddress(var,&Wjets_var);
      
      ttV->SetBranchAddress("weight",&ttV_weight);
      tV->SetBranchAddress("weight",&tV_weight);
      ttH->SetBranchAddress("weight",&ttH_weight);
      DY->SetBranchAddress("weight",&DY_weight);
      Zjets->SetBranchAddress("weight",&Zjets_weight);
      data->SetBranchAddress("weight",&data_weight);
      diboson->SetBranchAddress("weight",&diboson_weight);
      Vgam->SetBranchAddress("weight",&Vgam_weight);
      ttbar->SetBranchAddress("weight",&ttbar_weight);
      Wjets->SetBranchAddress("weight",&Wjets_weight);
      
      ttV->SetBranchAddress("channel",&ttV_channel);
      tV->SetBranchAddress("channel",&tV_channel);
      ttH->SetBranchAddress("channel",&ttH_channel);
      DY->SetBranchAddress("channel",&DY_channel);
      Zjets->SetBranchAddress("channel",&Zjets_channel);
      data->SetBranchAddress("channel",&data_channel);
      diboson->SetBranchAddress("channel",&diboson_channel);
      Vgam->SetBranchAddress("channel",&Vgam_channel);
      ttbar->SetBranchAddress("channel",&ttbar_channel);
      Wjets->SetBranchAddress("channel",&Wjets_channel);
      
      TH1F *frame_ee=new TH1F("frame_ee","",Nbins,xmin,xmax);
      THStack *hs_ee=new THStack("hs_ee","");
      TH1F *hist_ttV_ee=new TH1F("hist_ttV_ee","",Nbins,xmin,xmax);
      TH1F *hist_tV_ee=new TH1F("hist_tV_ee","",Nbins,xmin,xmax);
      TH1F *hist_ttH_ee=new TH1F("hist_ttH_ee","",Nbins,xmin,xmax);
      TH1F *hist_DY_ee=new TH1F("hist_DY_ee","",Nbins,xmin,xmax);
      TH1F *hist_Zjets_ee=new TH1F("hist_Zjets_ee","",Nbins,xmin,xmax);
      TH1F *hist_data_ee=new TH1F("hist_data_ee","",Nbins,xmin,xmax);
      TH1F *hist_diboson_ee=new TH1F("hist_diboson_ee","",Nbins,xmin,xmax);
      TH1F *hist_Vgam_ee=new TH1F("hist_Vgam_ee","",Nbins,xmin,xmax);
      TH1F *hist_ttbar_ee=new TH1F("hist_ttbar_ee","",Nbins,xmin,xmax);
      TH1F *hist_Wjets_ee=new TH1F("hist_Wjets_ee","",Nbins,xmin,xmax);
      TH1F *frame_mumu=new TH1F("frame_mumu","",Nbins,xmin,xmax);
      THStack *hs_mumu=new THStack("hs_mumu","");
      TH1F *hist_ttV_mumu=new TH1F("hist_ttV_mumu","",Nbins,xmin,xmax);
      TH1F *hist_tV_mumu=new TH1F("hist_tV_mumu","",Nbins,xmin,xmax);
      TH1F *hist_ttH_mumu=new TH1F("hist_ttH_mumu","",Nbins,xmin,xmax);
      TH1F *hist_DY_mumu=new TH1F("hist_DY_mumu","",Nbins,xmin,xmax);
      TH1F *hist_Zjets_mumu=new TH1F("hist_Zjets_mumu","",Nbins,xmin,xmax);
      TH1F *hist_data_mumu=new TH1F("hist_data_mumu","",Nbins,xmin,xmax);
      TH1F *hist_diboson_mumu=new TH1F("hist_diboson_mumu","",Nbins,xmin,xmax);
      TH1F *hist_Vgam_mumu=new TH1F("hist_Vgam_mumu","",Nbins,xmin,xmax);
      TH1F *hist_ttbar_mumu=new TH1F("hist_ttbar_mumu","",Nbins,xmin,xmax);
      TH1F *hist_Wjets_mumu=new TH1F("hist_Wjets_mumu","",Nbins,xmin,xmax);
      TH1F *frame_emu=new TH1F("frame_emu","",Nbins,xmin,xmax);
      THStack *hs_emu=new THStack("hs_emu","");
      TH1F *hist_ttV_emu=new TH1F("hist_ttV_emu","",Nbins,xmin,xmax);
      TH1F *hist_tV_emu=new TH1F("hist_tV_emu","",Nbins,xmin,xmax);
      TH1F *hist_ttH_emu=new TH1F("hist_ttH_emu","",Nbins,xmin,xmax);
      TH1F *hist_DY_emu=new TH1F("hist_DY_emu","",Nbins,xmin,xmax);
      TH1F *hist_Zjets_emu=new TH1F("hist_Zjets_emu","",Nbins,xmin,xmax);
      TH1F *hist_data_emu=new TH1F("hist_data_emu","",Nbins,xmin,xmax);
      TH1F *hist_diboson_emu=new TH1F("hist_diboson_emu","",Nbins,xmin,xmax);
      TH1F *hist_Vgam_emu=new TH1F("hist_Vgam_emu","",Nbins,xmin,xmax);
      TH1F *hist_ttbar_emu=new TH1F("hist_ttbar_emu","",Nbins,xmin,xmax);
      TH1F *hist_Wjets_emu=new TH1F("hist_Wjets_emu","",Nbins,xmin,xmax);
      
      Float_t Lumi=1; Double_t sf_ee=1, sf_mumu=1, sf_emu=1;
      for(Long64_t entry=0; entry<ttV->GetEntries();entry++) {
          ttV->GetEntry(entry);
          if(ttV_channel==1) hist_ttV_ee->Fill(ttV_var,ttV_weight*Lumi*sf_ee);
          if(ttV_channel==2) hist_ttV_mumu->Fill(ttV_var,ttV_weight*Lumi*sf_mumu);
          if(ttV_channel==3) hist_ttV_emu->Fill(ttV_var,ttV_weight*Lumi*sf_emu);
      }
      for(Long64_t entry=0; entry<tV->GetEntries();entry++) {
          tV->GetEntry(entry);
          if(tV_channel==1) hist_tV_ee->Fill(tV_var,tV_weight*Lumi*sf_ee);
          if(tV_channel==2) hist_tV_mumu->Fill(tV_var,tV_weight*Lumi*sf_mumu);
          if(tV_channel==3) hist_tV_emu->Fill(tV_var,tV_weight*Lumi*sf_emu);
      }
      for(Long64_t entry=0; entry<ttH->GetEntries();entry++) {
          ttH->GetEntry(entry);
          if(ttH_channel==1) hist_ttH_ee->Fill(ttH_var,ttH_weight*Lumi*sf_ee);
          if(ttH_channel==2) hist_ttH_mumu->Fill(ttH_var,ttH_weight*Lumi*sf_mumu);
          if(ttH_channel==3) hist_ttH_emu->Fill(ttH_var,ttH_weight*Lumi*sf_emu);
      }
      for(Long64_t entry=0; entry<DY->GetEntries();entry++) {
          DY->GetEntry(entry);
          if(DY_channel==1) hist_DY_ee->Fill(DY_var,DY_weight*Lumi*sf_ee);
          if(DY_channel==2) hist_DY_mumu->Fill(DY_var,DY_weight*Lumi*sf_mumu);
          if(DY_channel==3) hist_DY_emu->Fill(DY_var,DY_weight*Lumi*sf_emu);
      }
      for(Long64_t entry=0; entry<data->GetEntries();entry++) {
          data->GetEntry(entry);
          if(data_channel==1) hist_data_ee->Fill(data_var,data_weight);
          if(data_channel==2) hist_data_mumu->Fill(data_var,data_weight);
          if(data_channel==3) hist_data_emu->Fill(data_var,data_weight);
      }
      for(Long64_t entry=0; entry<diboson->GetEntries();entry++) {
          diboson->GetEntry(entry);
          if(diboson_channel==1) hist_diboson_ee->Fill(diboson_var,diboson_weight*Lumi);
          if(diboson_channel==2) hist_diboson_mumu->Fill(diboson_var,diboson_weight*Lumi);
          if(diboson_channel==3) hist_diboson_emu->Fill(diboson_var,diboson_weight*Lumi);
      }
      for(Long64_t entry=0; entry<Vgam->GetEntries();entry++) {
          Vgam->GetEntry(entry);
          if(Vgam_channel==1) hist_Vgam_ee->Fill(Vgam_var,Vgam_weight*Lumi);
          if(Vgam_channel==2) hist_Vgam_mumu->Fill(Vgam_var,Vgam_weight*Lumi);
          if(Vgam_channel==3) hist_Vgam_emu->Fill(Vgam_var,Vgam_weight*Lumi);
      }
      for(Long64_t entry=0; entry<ttbar->GetEntries();entry++) {
          ttbar->GetEntry(entry);
          if(ttbar_channel==1) hist_ttbar_ee->Fill(ttbar_var,ttbar_weight*Lumi);
          if(ttbar_channel==2) hist_ttbar_mumu->Fill(ttbar_var,ttbar_weight*Lumi);
          if(ttbar_channel==3) hist_ttbar_emu->Fill(ttbar_var,ttbar_weight*Lumi);
      }
      for(Long64_t entry=0; entry<Wjets->GetEntries();entry++) {
          Wjets->GetEntry(entry);
          if(Wjets_channel==1) hist_Wjets_ee->Fill(Wjets_var,Wjets_weight*Lumi);
          if(Wjets_channel==2) hist_Wjets_mumu->Fill(Wjets_var,Wjets_weight*Lumi);
          if(Wjets_channel==3) hist_Wjets_emu->Fill(Wjets_var,Wjets_weight*Lumi);
      }
      for(Long64_t entry=0; entry<Zjets->GetEntries();entry++) {
          Zjets->GetEntry(entry);
          if(Zjets_channel==1) hist_Zjets_ee->Fill(Zjets_var,Zjets_weight*Lumi);
          if(Zjets_channel==2) hist_Zjets_mumu->Fill(Zjets_var,Zjets_weight*Lumi);
          if(Zjets_channel==3) hist_Zjets_emu->Fill(Zjets_var,Zjets_weight*Lumi);
      }
      //----------------------------------------------------------------------------------
      // do some delcarations before drawing plots
      //----------------------------------------------------------------------------------
      // add hists to hs, ee
      hist_Wjets_ee->SetFillColor(40);
      hist_diboson_ee->SetFillColor(6);
      hist_Vgam_ee->SetFillColor(49);
      hist_ttbar_ee->SetFillColor(47);
      hist_ttV_ee->SetFillColor(kRed);
      hist_tV_ee->SetFillColor(kBlue);
      hist_ttH_ee->SetFillColor(kGreen);
      hist_DY_ee->SetFillColor(43);
      hist_Zjets_ee->SetFillColor(7);
      hist_Wjets_ee->SetLineColor(40);
      hist_diboson_ee->SetLineColor(6);
      hist_Vgam_ee->SetLineColor(49);
      hist_ttbar_ee->SetLineColor(47);
      hist_ttV_ee->SetLineColor(kRed);
      hist_tV_ee->SetLineColor(kBlue);
      hist_ttH_ee->SetLineColor(kGreen);
      hist_DY_ee->SetLineColor(43);
      hist_Zjets_ee->SetLineColor(7);
      hs_ee->Add(hist_diboson_ee); 
      hs_ee->Add(hist_ttV_ee); 
      hs_ee->Add(hist_tV_ee); 
      hs_ee->Add(hist_ttH_ee); 
      hs_ee->Add(hist_Vgam_ee);
      hs_ee->Add(hist_DY_ee);
      hs_ee->Add(hist_ttbar_ee);
      hs_ee->Add(hist_Wjets_ee); 
      hs_ee->Add(hist_Zjets_ee); 
      Double_t varx[200],varx_error[200],ratio_ee[200],ratio_error_ee[200];
      Double_t ratio_bkg_ee[200],ratio_error_bkg_ee[200];
      Double_t stack_ee[200],stack_error_ee[200];
      //mumu
      hist_Wjets_mumu->SetFillColor(40);
      hist_diboson_mumu->SetFillColor(6);
      hist_Vgam_mumu->SetFillColor(49);
      hist_ttbar_mumu->SetFillColor(47);
      hist_ttV_mumu->SetFillColor(kRed);
      hist_tV_mumu->SetFillColor(kBlue);
      hist_ttH_mumu->SetFillColor(kGreen);
      hist_DY_mumu->SetFillColor(43);
      hist_Zjets_mumu->SetFillColor(7);
      hist_Wjets_mumu->SetLineColor(40);
      hist_diboson_mumu->SetLineColor(6);
      hist_Vgam_mumu->SetLineColor(49);
      hist_ttbar_mumu->SetLineColor(47);
      hist_ttV_mumu->SetLineColor(kRed);
      hist_tV_mumu->SetLineColor(kBlue);
      hist_ttH_mumu->SetLineColor(kGreen);
      hist_DY_mumu->SetLineColor(43);
      hist_Zjets_mumu->SetLineColor(7);
      hs_mumu->Add(hist_diboson_mumu);
      hs_mumu->Add(hist_ttV_mumu); 
      hs_mumu->Add(hist_tV_mumu);   
      hs_mumu->Add(hist_ttH_mumu);  
      hs_mumu->Add(hist_Vgam_mumu);
      hs_mumu->Add(hist_DY_mumu);
      hs_mumu->Add(hist_ttbar_mumu);
      hs_mumu->Add(hist_Wjets_mumu); 
      hs_mumu->Add(hist_Zjets_mumu);
      Double_t ratio_mumu[200],ratio_error_mumu[200];
      Double_t ratio_bkg_mumu[200],ratio_error_bkg_mumu[200];
      Double_t stack_mumu[200],stack_error_mumu[200];
      //emu
      hist_Wjets_emu->SetFillColor(40);
      hist_diboson_emu->SetFillColor(6);
      hist_Vgam_emu->SetFillColor(49);
      hist_ttbar_emu->SetFillColor(47);
      hist_ttV_emu->SetFillColor(kRed);
      hist_tV_emu->SetFillColor(kBlue);
      hist_ttH_emu->SetFillColor(kGreen);
      hist_DY_emu->SetFillColor(43);
      hist_Zjets_emu->SetFillColor(7);
      hist_Wjets_emu->SetLineColor(40);
      hist_diboson_emu->SetLineColor(6);
      hist_Vgam_emu->SetLineColor(49);
      hist_ttbar_emu->SetLineColor(47);
      hist_ttV_emu->SetLineColor(kRed);
      hist_tV_emu->SetLineColor(kBlue);
      hist_ttH_emu->SetLineColor(kGreen);
      hist_DY_emu->SetLineColor(43);
      hist_Zjets_emu->SetLineColor(7);
      hs_emu->Add(hist_diboson_emu);
      hs_emu->Add(hist_ttV_emu); 
      hs_emu->Add(hist_tV_emu);   
      hs_emu->Add(hist_ttH_emu);  
      hs_emu->Add(hist_Vgam_emu);
      hs_emu->Add(hist_DY_emu);
      hs_emu->Add(hist_ttbar_emu);
      hs_emu->Add(hist_Wjets_emu); 
      hs_emu->Add(hist_Zjets_emu);
      Double_t ratio_emu[200],ratio_error_emu[200];
      Double_t ratio_bkg_emu[200],ratio_error_bkg_emu[200];
      Double_t stack_emu[200],stack_error_emu[200];
      //get ratios, errors, etc..ee
      for(Int_t bin=0;bin<Nbins;bin++){
          //ratio, mean values, width, first determined here, commonly used for 3 channels
          varx[bin]=(bin+0.5)*(hist_Wjets_ee->GetBinWidth(1));
          varx_error[bin]=(hist_Wjets_ee->GetBinWidth(1))/2.;
          //data, bkg bincontents and errors
          Double_t bincontent_data=hist_data_ee->GetBinContent(bin+1);
          Double_t binerror_data=hist_data_ee->GetBinError(bin+1);
          Double_t bincontent_bkg=((TH1*)(hs_ee->GetStack()->Last()))->GetBinContent(bin+1);
          Double_t binerror_bkg=((TH1*)(hs_ee->GetStack()->Last()))->GetBinError(bin+1);
          //to get bkg errors
          stack_ee[bin]=bincontent_bkg; stack_error_ee[bin]=binerror_bkg;
          //ratio plot: mean values, data error, bkg error
          ratio_ee[bin]=bincontent_data/bincontent_bkg;
          ratio_error_ee[bin]=binerror_data/bincontent_bkg;
          ratio_bkg_ee[bin]=1.;
          ratio_error_bkg_ee[bin]=binerror_bkg/bincontent_bkg;
          if(stack_ee[bin]!=stack_ee[bin]) stack_ee[bin]=0;
          if(stack_error_ee[bin]!=stack_error_ee[bin]) stack_error_ee[bin]=0;
          if(ratio_ee[bin]!=ratio_ee[bin]) ratio_ee[bin]=0;
          if(ratio_error_ee[bin]!=ratio_error_ee[bin]) ratio_error_ee[bin]=0;
          if(ratio_error_bkg_ee[bin]!=ratio_error_bkg_ee[bin]) ratio_error_bkg_ee[bin]=0;

      }
      //mumu
      for(Int_t bin=0;bin<Nbins;bin++){
          //data, bkg bincontents and errors
          Double_t bincontent_data=hist_data_mumu->GetBinContent(bin+1);
          Double_t binerror_data=hist_data_mumu->GetBinError(bin+1);
          Double_t bincontent_bkg=((TH1*)(hs_mumu->GetStack()->Last()))->GetBinContent(bin+1);
          Double_t binerror_bkg=((TH1*)(hs_mumu->GetStack()->Last()))->GetBinError(bin+1);
          //to get bkg errors
          stack_mumu[bin]=bincontent_bkg; stack_error_mumu[bin]=binerror_bkg;
          //ratio plot: mean values, data error, bkg error
          ratio_mumu[bin]=bincontent_data/bincontent_bkg;
          ratio_error_mumu[bin]=binerror_data/bincontent_bkg;
          ratio_bkg_mumu[bin]=1.;
          ratio_error_bkg_mumu[bin]=binerror_bkg/bincontent_bkg;
          if(stack_mumu[bin]!=stack_mumu[bin]) stack_mumu[bin]=0;
          if(stack_error_mumu[bin]!=stack_error_mumu[bin]) stack_error_mumu[bin]=0;
          if(ratio_mumu[bin]!=ratio_mumu[bin]) ratio_mumu[bin]=0;
          if(ratio_error_mumu[bin]!=ratio_error_mumu[bin]) ratio_error_mumu[bin]=0;
          if(ratio_error_bkg_mumu[bin]!=ratio_error_bkg_mumu[bin]) ratio_error_bkg_mumu[bin]=0;

      }
      //emu
      for(Int_t bin=0;bin<Nbins;bin++){
          //data, bkg bincontents and errors
          Double_t bincontent_data=hist_data_emu->GetBinContent(bin+1);
          Double_t binerror_data=hist_data_emu->GetBinError(bin+1);
          Double_t bincontent_bkg=((TH1*)(hs_emu->GetStack()->Last()))->GetBinContent(bin+1);
          Double_t binerror_bkg=((TH1*)(hs_emu->GetStack()->Last()))->GetBinError(bin+1);
          //to get bkg errors
          stack_emu[bin]=bincontent_bkg; stack_error_emu[bin]=binerror_bkg;
          //ratio plot: mean values, data error, bkg error
          ratio_emu[bin]=bincontent_data/bincontent_bkg;
          ratio_error_emu[bin]=binerror_data/bincontent_bkg;
          ratio_bkg_emu[bin]=1.;
          ratio_error_bkg_emu[bin]=binerror_bkg/bincontent_bkg;
          if(stack_emu[bin]!=stack_emu[bin]) stack_emu[bin]=0;
          if(stack_error_emu[bin]!=stack_error_emu[bin]) stack_error_emu[bin]=0;
          if(ratio_emu[bin]!=ratio_emu[bin]) ratio_emu[bin]=0;
          if(ratio_error_emu[bin]!=ratio_error_emu[bin]) ratio_error_emu[bin]=0;
          if(ratio_error_bkg_emu[bin]!=ratio_error_bkg_emu[bin]) ratio_error_bkg_emu[bin]=0;

      }
      //-----------------------------------------------------------------------------
      //draw plots
      //-----------------------------------------------------------------------------
      Double_t Ymaximum_ee=0, Ymaximum_mumu=0, Ymaximum_emu=0;
      Ymaximum_ee=1.5*GetMaxBinContent(hist_data_ee);
      Ymaximum_mumu=1.5*GetMaxBinContent(hist_data_mumu);
      Ymaximum_emu=1.5*GetMaxBinContent(hist_data_emu);
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
      leg_ee->AddEntry(hist_data_ee,"Data","lp");
      leg_ee->AddEntry(hist_diboson_ee,"VV","f");
      leg_ee->AddEntry(hist_ttV_ee,"ttV","f");
      leg_ee->AddEntry(hist_tV_ee,"tV","f");
      leg_ee->AddEntry(hist_ttH_ee,"ttH","f");
      leg_ee->AddEntry(hist_Vgam_ee,"V#gamma","f");
      leg_ee->AddEntry(hist_DY_ee,"DY","f");
      leg_ee->AddEntry(hist_ttbar_ee,"t#bar{t}","f");
      leg_ee->AddEntry(hist_Wjets_ee,"Wjets","f");
      leg_ee->AddEntry(hist_Zjets_ee,"Zjets","f");
      frame_ee->SetMaximum(Ymaximum_ee);
      frame_ee->SetMinimum(0.001);
      frame_ee->GetYaxis()->SetTitleSize(0.06);
      frame_ee->GetYaxis()->SetTitleOffset(1);
      frame_ee->GetYaxis()->SetTitle("Num. Of Events");
      frame_ee->Draw();
      hs_ee->Draw("hist same");
      hist_data_ee->Draw("e same");
      leg_ee->Draw("same");
      myText(0.55, 0.87, 1, "ee");
      ATLAS_LABEL(0.20, 0.87 );
      myText( 0.31, 0.87 , 1, "Internal");
      myText( 0.20, 0.78 , 1, "#sqrt{s} = 13 TeV");
      myText( 0.37, 0.78 , 1, "#intLdt = 36.1 fb^{-1}");
      TGraphErrors *gr_stack_ee=new TGraphErrors(Nbins,varx,stack_ee,varx_error,stack_error_ee);
      gr_stack_ee->SetFillColor(6);
      gStyle->SetHatchesLineWidth(1);
      gr_stack_ee->SetFillStyle(3254);
      gr_stack_ee->Draw("2");
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
      gr_ee->GetXaxis()->SetTitleSize(0.15);
      gr_ee->GetXaxis()->SetTitleOffset(0.8);
      gr_ee->GetYaxis()->SetLabelSize(0.1);
      gr_ee->GetYaxis()->SetTitleSize(0.14);
      gr_ee->GetYaxis()->SetTitleOffset(0.40);
      gr_ee->GetYaxis()->SetNdivisions(505);
      gr_ee->SetMarkerSize(0.4);
      gr_ee->SetMarkerStyle(20);
      gr_ee->GetXaxis()->SetRangeUser(xmin,xmax);
      gr_ee->GetYaxis()->SetRangeUser(0,2.1);
      gr_ee->Draw("AP0");
      TLine* line_ee=new TLine();
      line_ee->DrawLine(xmin,1.0,xmax,1.0);
      line_ee->SetLineColor(kBlack);
      line_ee->SetLineStyle(kDashed);
      line_ee->DrawLine(xmin,0.5,xmax,0.5);
      line_ee->DrawLine(xmin,1.5,xmax,1.5);
      TGraphErrors *gr_ratio_bkg_ee=new TGraphErrors(Nbins,varx,ratio_bkg_ee,varx_error,ratio_error_bkg_ee);
      gr_ratio_bkg_ee->SetFillColor(6);
      gr_ratio_bkg_ee->SetFillStyle(3254);
      gr_ratio_bkg_ee->Draw("2");
      c_hist_ee->Update();
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
      leg_mumu->AddEntry(hist_data_mumu,"Data","lp");
      leg_mumu->AddEntry(hist_diboson_mumu,"VV","f");
      leg_mumu->AddEntry(hist_ttV_mumu,"ttV","f");
      leg_mumu->AddEntry(hist_tV_mumu,"tV","f");
      leg_mumu->AddEntry(hist_ttH_mumu,"ttH","f");
      leg_mumu->AddEntry(hist_Vgam_mumu,"V#gamma","f");
      leg_mumu->AddEntry(hist_DY_mumu,"DY","f");
      leg_mumu->AddEntry(hist_ttbar_mumu,"t#bar{t}","f");
      leg_mumu->AddEntry(hist_Wjets_mumu,"Wjets","f");
      leg_mumu->AddEntry(hist_Zjets_mumu,"Zjets","f");
      frame_mumu->SetMaximum(Ymaximum_mumu);
      frame_mumu->SetMinimum(0.001);
      frame_mumu->GetYaxis()->SetTitleSize(0.06);
      frame_mumu->GetYaxis()->SetTitleOffset(1);
      frame_mumu->GetYaxis()->SetTitle("Num. Of Events");
      frame_mumu->Draw();
      hs_mumu->Draw("hist same");
      hist_data_mumu->Draw("e same");
      leg_mumu->Draw("same");
      myText(0.55, 0.87, 1, "#mu#mu");
      ATLAS_LABEL(0.20, 0.87 );
      myText( 0.31, 0.87 , 1, "Internal");
      myText( 0.20, 0.78 , 1, "#sqrt{s} = 13 TeV");
      myText( 0.37, 0.78 , 1, "#intLdt = 36.1 fb^{-1}");
      TGraphErrors *gr_stack_mumu=new TGraphErrors(Nbins,varx,stack_mumu,varx_error,stack_error_mumu);
      gr_stack_mumu->SetFillColor(6);
      gr_stack_mumu->SetFillStyle(3254);
      gr_stack_mumu->Draw("2");
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
      gr_mumu->GetXaxis()->SetTitleSize(0.15);
      gr_mumu->GetXaxis()->SetTitleOffset(0.8);
      gr_mumu->GetYaxis()->SetLabelSize(0.1);
      gr_mumu->GetYaxis()->SetTitleSize(0.14);
      gr_mumu->GetYaxis()->SetTitleOffset(0.40);
      gr_mumu->GetYaxis()->SetNdivisions(505);
      gr_mumu->SetMarkerSize(0.4);
      gr_mumu->SetMarkerStyle(20);
      gr_mumu->GetXaxis()->SetRangeUser(xmin,xmax);
      gr_mumu->GetYaxis()->SetRangeUser(0,2.1);
      gr_mumu->Draw("AP0");
      TLine* line_mumu=new TLine();
      line_mumu->DrawLine(xmin,1.0,xmax,1.0);
      line_mumu->SetLineColor(kBlack);
      line_mumu->SetLineStyle(kDashed);
      line_mumu->DrawLine(xmin,0.5,xmax,0.5);
      line_mumu->DrawLine(xmin,1.5,xmax,1.5);
      TGraphErrors *gr_ratio_bkg_mumu=new TGraphErrors(Nbins,varx,ratio_bkg_mumu,varx_error,ratio_error_bkg_mumu);
      gr_ratio_bkg_mumu->SetFillColor(6);
      gr_ratio_bkg_mumu->SetFillStyle(3254);
      gr_ratio_bkg_mumu->Draw("2");
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
      leg_emu->AddEntry(hist_data_emu,"Data","lp");
      leg_emu->AddEntry(hist_diboson_emu,"VV","f");
      leg_emu->AddEntry(hist_ttV_emu,"ttV","f");
      leg_emu->AddEntry(hist_tV_emu,"tV","f");
      leg_emu->AddEntry(hist_ttH_emu,"ttH","f");
      leg_emu->AddEntry(hist_Vgam_emu,"V#gamma","f");
      leg_emu->AddEntry(hist_DY_emu,"DY","f");
      leg_emu->AddEntry(hist_ttbar_emu,"t#bar{t}","f");
      leg_emu->AddEntry(hist_Wjets_emu,"Wjets","f");
      leg_emu->AddEntry(hist_Zjets_emu,"Zjets","f");
      frame_emu->SetMaximum(Ymaximum_emu);
      frame_emu->SetMinimum(0.001);
      frame_emu->GetYaxis()->SetTitleSize(0.06);
      frame_emu->GetYaxis()->SetTitleOffset(1);
      frame_emu->GetYaxis()->SetTitle("Num. Of Events");
      frame_emu->Draw();
      hs_emu->Draw("hist same");
      hist_data_emu->Draw("e same");
      leg_emu->Draw("same");
      myText(0.55, 0.87, 1, "e#mu");
      ATLAS_LABEL(0.20, 0.87 );
      myText( 0.31, 0.87 , 1, "Internal");
      myText( 0.20, 0.78 , 1, "#sqrt{s} = 13 TeV");
      myText( 0.37, 0.78 , 1, "#intLdt = 36.1 fb^{-1}");
      TGraphErrors *gr_stack_emu=new TGraphErrors(Nbins,varx,stack_emu,varx_error,stack_error_emu);
      gr_stack_emu->SetFillColor(6);
      gr_stack_emu->SetFillStyle(3254);
      gr_stack_emu->Draw("2");
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
      gr_emu->GetXaxis()->SetTitleSize(0.15);
      gr_emu->GetXaxis()->SetTitleOffset(0.8);
      gr_emu->GetYaxis()->SetLabelSize(0.1);
      gr_emu->GetYaxis()->SetTitleSize(0.14);
      gr_emu->GetYaxis()->SetTitleOffset(0.40);
      gr_emu->GetYaxis()->SetNdivisions(505);
      gr_emu->SetMarkerSize(0.4);
      gr_emu->SetMarkerStyle(20);
      gr_emu->GetXaxis()->SetRangeUser(xmin,xmax);
      gr_emu->GetYaxis()->SetRangeUser(0,2.1);
      gr_emu->Draw("AP0");
      TLine* line_emu=new TLine();
      line_emu->DrawLine(xmin,1.0,xmax,1.0);
      line_emu->SetLineColor(kBlack);
      line_emu->SetLineStyle(kDashed);
      line_emu->DrawLine(xmin,0.5,xmax,0.5);
      line_emu->DrawLine(xmin,1.5,xmax,1.5);
      TGraphErrors *gr_ratio_bkg_emu=new TGraphErrors(Nbins,varx,ratio_bkg_emu,varx_error,ratio_error_bkg_emu);
      gr_ratio_bkg_emu->SetFillColor(6);
      gr_ratio_bkg_emu->SetFillStyle(3254);
      gr_ratio_bkg_emu->Draw("2");
      //c_hist_emu->SaveAs(output_emu_png);
      c_hist_emu->SaveAs(output_emu_pdf);

      //delete 
      delete frame_ee;
      delete hs_ee;
      delete hist_ttV_ee;
      delete hist_tV_ee;
      delete hist_ttH_ee;
      delete hist_DY_ee;
      delete hist_Zjets_ee;
      delete hist_data_ee;
      delete hist_diboson_ee;
      delete hist_Vgam_ee;
      delete hist_ttbar_ee;
      delete hist_Wjets_ee;
      delete frame_mumu;
      delete hs_mumu;
      delete hist_ttV_mumu;
      delete hist_tV_mumu;
      delete hist_ttH_mumu;
      delete hist_DY_mumu;
      delete hist_Zjets_mumu;
      delete hist_data_mumu;
      delete hist_diboson_mumu;
      delete hist_Vgam_mumu;
      delete hist_ttbar_mumu;
      delete hist_Wjets_mumu;
      delete frame_emu;
      delete hs_emu;
      delete hist_ttV_emu;
      delete hist_tV_emu;
      delete hist_ttH_emu;
      delete hist_DY_emu;
      delete hist_Zjets_emu;
      delete hist_data_emu;
      delete hist_diboson_emu;
      delete hist_Vgam_emu;
      delete hist_ttbar_emu;
      delete hist_Wjets_emu;
      delete c_hist_ee;
      delete c_hist_mumu;
      delete c_hist_emu;
      ttV               ->ResetBranchAddresses();
      tV                ->ResetBranchAddresses();
      ttH	 	   ->ResetBranchAddresses();
      DY		   ->ResetBranchAddresses();
      data		   ->ResetBranchAddresses();
      diboson		   ->ResetBranchAddresses();
      Vgam	  	   ->ResetBranchAddresses();
      ttbar	           ->ResetBranchAddresses();
      Wjets	   ->ResetBranchAddresses();
      Zjets   ->ResetBranchAddresses();
  }//end of loop   
//end of manin func
}
