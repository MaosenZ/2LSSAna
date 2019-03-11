#include "TCanvas.h"
#include "TH1.h"
#include "TFile.h"
#include "TTree.h"
#include "TStyle.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooHistPdf.h"
#include <algorithm>
#include <iostream>
#include "TString.h"
#include <vector>
#include <map>
#include "lumi.cxx"
#include "GHTBCs.cxx"
#include "../../atlasstyle-00-03-05/AtlasStyle.C"
#include "../../atlasstyle-00-03-05/AtlasUtils.C"
using namespace std;
using namespace TMath;
//variables to be used
TString vars[]={"pt_leadinglepton","pt_sublepton","pt_j1","pt_j2","m_ll","m_jj_w","MET","m_jj","m_l1jj","mindR_l1j","mindR_l2j",
                  "pt_vecsum","pt_sum","m_all","Mt","m_l1j","m_l2j","RMS","numOfjet"};
TString vars_titles[]={"Pt(l_{1})","Pt(l_{2})","Pt(j_{1})","Pt(j_{2})","M(ll)","M(jj)^{w}","#slash{E}_{T}","M(jj)","M(l_{1}jj)",
                         "#DeltaR_{min}(l_{1},j)","#DeltaR_{min}(l_{2},j)","Pt(all)^{vec}","Pt(all)","M(all)","Mt","M(l_{1}j)","M(l_{2}j)",
                       "RMS","Njet"};
//number of pseudo events
Int_t Nevents=10000;
//normalization factor
Double_t Nfakes_ee, Nfakes_mumu, Nfakes_emu;    
//to store values of each variable of pseudo events
map<TString,vector<float> > variables_ee;
map<TString,vector<float> > variables_mumu;
map<TString,vector<float> > variables_emu;

void makePseudoFakeTree(TString var){
  //gROOT->Reset(); 
  TFile *f_FFApp_data=new TFile("output/dataMC_3jets/miniNtuple_FFApp_datacombined.root");
  TFile *f_FFQmis=new TFile("output/dataMC_3jets/miniNtuple_FFQmis_datacombined.root");
  TFile *f_FFApp_subtractions_QmisID=new TFile("output/dataMC_3jets/miniNtuple_FFApp_subtractions_QmisID.root");
  TFile *f_FFApp_subtractions_promptSS=new TFile("output/dataMC_3jets/miniNtuple_FFApp_subtractions_promptSS.root");

  TTree *FFApp_data=(TTree*)f_FFApp_data->Get("Tree");
  TTree *FFQmis=(TTree*)f_FFQmis->Get("Tree");
  TTree *FFApp_subtractions_QmisID=(TTree*)f_FFApp_subtractions_QmisID->Get("Tree");
  TTree *FFApp_subtractions_promptSS=(TTree*)f_FFApp_subtractions_promptSS->Get("Tree");
  
  Float_t  FFApp_data_var,FFApp_subtractions_QmisID_var,FFApp_subtractions_promptSS_var,FFQmis_var;
  Double_t FFApp_data_weight,FFApp_subtractions_QmisID_weight,FFApp_subtractions_promptSS_weight, FFQmis_weight;
  Int_t FFApp_data_channel,FFApp_subtractions_QmisID_channel,FFApp_subtractions_promptSS_channel, FFQmis_channel;
  Int_t FFApp_data_numOfjet,FFApp_subtractions_QmisID_numOfjet,FFApp_subtractions_promptSS_numOfjet, FFQmis_numOfjet;
              
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

  FFQmis->SetBranchAddress(var,&FFQmis_var);
  FFApp_data->SetBranchAddress(var,&FFApp_data_var);
  FFApp_subtractions_QmisID->SetBranchAddress(var,&FFApp_subtractions_QmisID_var);
  FFApp_subtractions_promptSS->SetBranchAddress(var,&FFApp_subtractions_promptSS_var);

  FFApp_data->SetBranchAddress("weight",&FFApp_data_weight);
  FFQmis->SetBranchAddress("weight",&FFQmis_weight);
  FFApp_subtractions_QmisID->SetBranchAddress("weight",&FFApp_subtractions_QmisID_weight);
  FFApp_subtractions_promptSS->SetBranchAddress("weight",&FFApp_subtractions_promptSS_weight);

  FFApp_data->SetBranchAddress("channel",&FFApp_data_channel);
  FFQmis->SetBranchAddress("channel",&FFQmis_channel);
  FFApp_subtractions_QmisID->SetBranchAddress("channel",&FFApp_subtractions_QmisID_channel);
  FFApp_subtractions_promptSS->SetBranchAddress("channel",&FFApp_subtractions_promptSS_channel);
 
  TH1F *hist_fake_ee=new TH1F("hist_fake_ee","",Nbins,xmin,xmax);
  TH1F *hist_fake_mumu=new TH1F("hist_fake_mumu","",Nbins,xmin,xmax);
  TH1F *hist_fake_emu=new TH1F("hist_fake_emu","",Nbins,xmin,xmax);

  Float_t Lumi=lumi(); 
  for(Long64_t entry=0; entry<FFApp_data->GetEntries();entry++) {
      FFApp_data->GetEntry(entry);
      if(FFApp_data_channel==1) hist_fake_ee->Fill(FFApp_data_var,FFApp_data_weight);
      if(FFApp_data_channel==2) hist_fake_mumu->Fill(FFApp_data_var,FFApp_data_weight);
      if(FFApp_data_channel==3) hist_fake_emu->Fill(FFApp_data_var,FFApp_data_weight);
  }
  for(Long64_t entry=0; entry<FFApp_subtractions_QmisID->GetEntries();entry++) {
      FFApp_subtractions_QmisID->GetEntry(entry);
      if(FFApp_subtractions_QmisID_channel==1) hist_fake_ee->Fill(FFApp_subtractions_QmisID_var,-FFApp_subtractions_QmisID_weight*Lumi);
      if(FFApp_subtractions_QmisID_channel==3) hist_fake_emu->Fill(FFApp_subtractions_QmisID_var,-FFApp_subtractions_QmisID_weight*Lumi);
  }
  for(Long64_t entry=0; entry<FFQmis->GetEntries();entry++) {
      FFQmis->GetEntry(entry);
      if(FFQmis_channel==3) hist_fake_emu->Fill(FFQmis_var,-FFQmis_weight);
  }
  for(Long64_t entry=0; entry<FFApp_subtractions_promptSS->GetEntries();entry++) {
      FFApp_subtractions_promptSS->GetEntry(entry);
      if(FFApp_subtractions_promptSS_channel==1) hist_fake_ee->Fill(FFApp_subtractions_promptSS_var,-FFApp_subtractions_promptSS_weight*Lumi);
      if(FFApp_subtractions_promptSS_channel==2) hist_fake_mumu->Fill(FFApp_subtractions_promptSS_var,-FFApp_subtractions_promptSS_weight*Lumi);
      if(FFApp_subtractions_promptSS_channel==3) hist_fake_emu->Fill(FFApp_subtractions_promptSS_var,-FFApp_subtractions_promptSS_weight*Lumi);
  }
  Nfakes_ee=(double)hist_fake_ee->Integral(0,Nbins+1);
  Nfakes_mumu=(double)hist_fake_mumu->Integral(0,Nbins+1);
  Nfakes_emu=(double)hist_fake_emu->Integral(0,Nbins+1);
  cout<<"Nfakes_ee: "<<Nfakes_ee<<endl;
  cout<<"Nfakes_mumu: "<<Nfakes_mumu<<endl;
  cout<<"Nfakes_emu: "<<Nfakes_emu<<endl;
  //first smooth the fake hists
  hist_fake_ee->Smooth();
  hist_fake_mumu->Smooth();
  hist_fake_emu->Smooth();
  RooRealVar variable = RooRealVar("variable",var,xmin,xmax);
  RooDataSet::setDefaultStorageType(RooAbsData::Tree);
  //ee
  RooPlot* frame_ee = variable.frame(Nbins) ;
  RooDataHist* histdata_ee=new RooDataHist("histdata_ee","histdata_ee",RooArgList(variable),hist_fake_ee);
  RooHistPdf histpdf_ee("histpdf_ee","histpdf_ee",variable,*histdata_ee,2);
  RooDataSet *pseudodata_ee = histpdf_ee.generate(RooArgSet(variable),Nevents); 
  TCanvas *c_ee=new TCanvas("c_ee","c_ee",900,700);
  hist_fake_ee->Draw();
  c_ee->SaveAs("output/fakes_plots/"+var+"_ee.png");
  //mumu
  RooPlot* frame_mumu = variable.frame(Nbins) ;
  RooDataHist* histdata_mumu=new RooDataHist("histdata_mumu","histdata_mumu",RooArgList(variable),hist_fake_mumu);
  RooHistPdf histpdf_mumu("histpdf_mumu","histpdf_mumu",variable,*histdata_mumu,2);
  RooDataSet *pseudodata_mumu = histpdf_mumu.generate(RooArgSet(variable),Nevents);
  RooArgSet* pdfObs = histpdf_mumu.getObservables(pseudodata_mumu) ;
  TCanvas *c_mumu=new TCanvas("c_mumu","c_mumu",900,700);
  hist_fake_mumu->Draw();
  c_mumu->SaveAs("output/fakes_plots/"+var+"_mumu.png");
  //emu
  RooDataHist* histdata_emu=new RooDataHist("histdata_emu","histdata_emu",RooArgList(variable),hist_fake_emu);
  RooHistPdf histpdf_emu("histpdf_emu","histpdf_emu",variable,*histdata_emu,2);
  RooDataSet *pseudodata_emu = histpdf_emu.generate(RooArgSet(variable),Nevents);
  TCanvas *c_emu=new TCanvas("c_emu","c_emu",900,700);
  hist_fake_emu->Draw();
  c_emu->SaveAs("output/fakes_plots/"+var+"_emu.png");
  //save pseudo events to root files
  TFile *PseudoFakes_ee=new TFile("temp/PseudoFakes_ee.root","recreate");
  TTree* tree_ee=(TTree*)pseudodata_ee->tree();
  tree_ee->Write();
  PseudoFakes_ee->Close();
  
  TFile *PseudoFakes_mumu=new TFile("temp/PseudoFakes_mumu.root","recreate");
  TTree* tree_mumu=(TTree*)pseudodata_mumu->tree();
  tree_mumu->Write();
  PseudoFakes_mumu->Close();

  TFile *PseudoFakes_emu=new TFile("temp/PseudoFakes_emu.root","recreate");
  TTree* tree_emu=(TTree*)pseudodata_emu->tree();
  tree_emu->Write();
  PseudoFakes_emu->Close();
  
  FFApp_data->ResetBranchAddresses();
  FFApp_subtractions_QmisID->ResetBranchAddresses();
  FFApp_subtractions_promptSS->ResetBranchAddresses();
  FFQmis->ResetBranchAddresses();
}

void makePseudoFakes(Int_t index){
  
  //to generate pseudo events
  TString var=vars[index];
  makePseudoFakeTree(var);
   
  TFile *f_ee=new TFile("temp/PseudoFakes_ee.root");
  TFile *f_mumu=new TFile("temp/PseudoFakes_mumu.root");
  TFile *f_emu=new TFile("temp/PseudoFakes_emu.root");
  
  TTree* tree_ee=(TTree*)f_ee->Get("histpdf_eeData");
  TTree* tree_mumu=(TTree*)f_mumu->Get("histpdf_mumuData");
  TTree* tree_emu=(TTree*)f_emu->Get("histpdf_emuData");
  
  Double_t variable_ee;
  tree_ee->SetBranchAddress("variable",&variable_ee);
  Double_t variable_mumu;
  tree_mumu->SetBranchAddress("variable",&variable_mumu);
  Double_t variable_emu;
  tree_emu->SetBranchAddress("variable",&variable_emu);
  
  TString name=var;
  for(Int_t entry=0;entry<tree_ee->GetEntries();entry++){
      tree_ee->GetEntry(entry);
      variables_ee[name].push_back(variable_ee);
  }
  for(Int_t entry=0;entry<tree_mumu->GetEntries();entry++){
      tree_mumu->GetEntry(entry);
      variables_mumu[name].push_back(variable_mumu);
  }
  for(Int_t entry=0;entry<tree_emu->GetEntries();entry++){
      tree_emu->GetEntry(entry);
      variables_emu[name].push_back(variable_emu);
  }
  tree_ee->ResetBranchAddresses();
  tree_mumu->ResetBranchAddresses();
  tree_emu->ResetBranchAddresses();
}

void savePseudoFakes(){
  //make fakes for each variable
  for(Int_t i=0;i<18;i++) {
      cout<<"-------------------------------------------------------"<<endl;
      cout<<"                "<<vars[i]<<endl;
      cout<<"-------------------------------------------------------"<<endl;
      makePseudoFakes(i);
  }
  //save fakes to output
  TFile *PseudoFakes=new TFile("PseudoFakes.root","recreate");
  TTree *output_tree=new TTree("Tree","Tree");
  Float_t m_ll,m_jj,MET,pt_leadinglepton,pt_sublepton,pt_j1,pt_j2,m_jj_w,m_l1jj,m_all,pt_vecsum,pt_sum,mindR_l1j,mindR_l2j,Mt,m_l1j,
          m_l2j,RMS;
  Double_t weight; Int_t channel,numOfjet;
  output_tree->Branch("m_ll",&m_ll);
  output_tree->Branch("m_jj",&m_jj);
  output_tree->Branch("MET",&MET);
  output_tree->Branch("pt_leadinglepton",&pt_leadinglepton);
  output_tree->Branch("pt_sublepton",&pt_sublepton);
  output_tree->Branch("pt_j1",&pt_j1);
  output_tree->Branch("pt_j2",&pt_j2);
  output_tree->Branch("m_jj_w",&m_jj_w);
  output_tree->Branch("m_l1jj",&m_l1jj);
  output_tree->Branch("m_all",&m_all);
  output_tree->Branch("pt_sum",&pt_sum);
  output_tree->Branch("pt_vecsum",&pt_vecsum);
  output_tree->Branch("mindR_l1j",&mindR_l1j);
  output_tree->Branch("m_l1j",&m_l1j);
  output_tree->Branch("mindR_l2j",&mindR_l2j);
  output_tree->Branch("RMS",&RMS);
  output_tree->Branch("m_l2j",&m_l2j);
  output_tree->Branch("Mt",&Mt);
  output_tree->Branch("weight",&weight);
  output_tree->Branch("channel",&channel);
  output_tree->Branch("numOfjet",&numOfjet);
  //begin fill
  for(Int_t entry=0;entry<Nevents;entry++){
      channel=1;
      weight=Nfakes_ee/Nevents;
      pt_leadinglepton=variables_ee["pt_leadinglepton"][entry];
      pt_sublepton=variables_ee["pt_sublepton"][entry];
      pt_j1=variables_ee["pt_j1"][entry];
      pt_j2=variables_ee["pt_j2"][entry];
      m_ll=variables_ee["m_ll"][entry];
      m_jj_w=variables_ee["m_jj_w"][entry];
      MET=variables_ee["MET"][entry];
      m_jj=variables_ee["m_jj"][entry];
      m_l1jj=variables_ee["m_l1jj"][entry];
      mindR_l1j=variables_ee["mindR_l1j"][entry];
      mindR_l2j=variables_ee["mindR_l2j"][entry];
      pt_sum=variables_ee["pt_sum"][entry];
      pt_vecsum=variables_ee["pt_vecsum"][entry];
      m_all=variables_ee["m_all"][entry];
      Mt=variables_ee["Mt"][entry];
      m_l1j=variables_ee["m_l1j"][entry];
      m_l2j=variables_ee["m_l2j"][entry];
      RMS=variables_ee["RMS"][entry];
      //numOfjet=variables_ee["numOfjet"][entry];
      output_tree->Fill();
  }
  for(Int_t entry=0;entry<Nevents;entry++){
      channel=2;
      weight=Nfakes_mumu/Nevents;
      pt_leadinglepton=variables_mumu["pt_leadinglepton"][entry];
      pt_sublepton=variables_mumu["pt_sublepton"][entry];
      pt_j1=variables_mumu["pt_j1"][entry];
      pt_j2=variables_mumu["pt_j2"][entry];
      m_ll=variables_mumu["m_ll"][entry];
      m_jj_w=variables_mumu["m_jj_w"][entry];
      MET=variables_mumu["MET"][entry];
      m_jj=variables_mumu["m_jj"][entry];
      m_l1jj=variables_mumu["m_l1jj"][entry];
      mindR_l1j=variables_mumu["mindR_l1j"][entry];
      mindR_l2j=variables_mumu["mindR_l2j"][entry];
      pt_sum=variables_mumu["pt_sum"][entry];
      pt_vecsum=variables_mumu["pt_vecsum"][entry];
      m_all=variables_mumu["m_all"][entry];
      Mt=variables_mumu["Mt"][entry];
      m_l1j=variables_mumu["m_l1j"][entry];
      m_l2j=variables_mumu["m_l2j"][entry];
      RMS=variables_mumu["RMS"][entry];
      //numOfjet=variables_mumu["numOfjet"][entry];
      output_tree->Fill();
  }
  for(Int_t entry=0;entry<Nevents;entry++){
      channel=3;
      weight=Nfakes_emu/Nevents;
      pt_leadinglepton=variables_emu["pt_leadinglepton"][entry];
      pt_sublepton=variables_emu["pt_sublepton"][entry];
      pt_j1=variables_emu["pt_j1"][entry];
      pt_j2=variables_emu["pt_j2"][entry];
      m_ll=variables_emu["m_ll"][entry];
      m_jj_w=variables_emu["m_jj_w"][entry];
      MET=variables_emu["MET"][entry];
      m_jj=variables_emu["m_jj"][entry];
      m_l1jj=variables_emu["m_l1jj"][entry];
      mindR_l1j=variables_emu["mindR_l1j"][entry];
      mindR_l2j=variables_emu["mindR_l2j"][entry];
      pt_sum=variables_emu["pt_sum"][entry];
      pt_vecsum=variables_emu["pt_vecsum"][entry];
      m_all=variables_emu["m_all"][entry];
      Mt=variables_emu["Mt"][entry];
      m_l1j=variables_emu["m_l1j"][entry];
      m_l2j=variables_emu["m_l2j"][entry];
      RMS=variables_emu["RMS"][entry];
      //numOfjet=variables_emu["numOfjet"][entry];
      output_tree->Fill();
  }
  //write output
  output_tree->Write();
  PseudoFakes->Close();  
}
