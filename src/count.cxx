#include <iostream>
#include "TFile.h"
#include "TH1.h"
#include "../inc/SampleHandler.h"
#include "lumi.cxx"
#include "GHTBCs.cxx"
void count(){
  TFile *temp_data=new TFile("temp/hists_FFApp_3jets_datacombined.root");
  TFile *temp_diboson=new TFile("temp/hists_FFApp_3jets_diboson.root");
  TFile *temp_ttV=new TFile("temp/hists_FFApp_3jets_ttV.root");
  TFile *temp_tV=new TFile("temp/hists_FFApp_3jets_tV.root");
  TFile *temp_ttH=new TFile("temp/hists_FFApp_3jets_ttH.root");
  TFile *temp_Vgam=new TFile("temp/hists_FFApp_3jets_Vgam.root");
  TFile *temp_QmisID_data=new TFile("temp/hists_QmisID_3jets_datacombined.root");
  //ee
  TH1* hist_eta_subelectron_ee_data=(TH1*)temp_data->Get("hist_eta_subelectron_ee");
  TH1* hist_eta_subelectron_ee_diboson=(TH1*)temp_diboson->Get("hist_eta_subelectron_ee");
  TH1* hist_eta_subelectron_ee_ttV=(TH1*)temp_ttV->Get("hist_eta_subelectron_ee");
  TH1* hist_eta_subelectron_ee_tV=(TH1*)temp_tV->Get("hist_eta_subelectron_ee");
  TH1* hist_eta_subelectron_ee_ttH=(TH1*)temp_ttH->Get("hist_eta_subelectron_ee");
  TH1* hist_eta_subelectron_ee_Vgam=(TH1*)temp_Vgam->Get("hist_eta_subelectron_ee");
  TH1* hist_eta_subelectron_ee_QmisID=(TH1*)temp_QmisID_data->Get("hist_eta_subelectron_ee");

  hist_eta_subelectron_ee_diboson->Scale(lumi());
  hist_eta_subelectron_ee_ttV->Scale(lumi());
  hist_eta_subelectron_ee_tV->Scale(lumi());
  hist_eta_subelectron_ee_ttH->Scale(lumi());
  hist_eta_subelectron_ee_Vgam->Scale(lumi());
  //mumu
    TH1* hist_eta_submuon_mumu_data=(TH1*)temp_data->Get("hist_eta_submuon_mumu");
  TH1* hist_eta_submuon_mumu_diboson=(TH1*)temp_diboson->Get("hist_eta_submuon_mumu");
  TH1* hist_eta_submuon_mumu_ttV=(TH1*)temp_ttV->Get("hist_eta_submuon_mumu");
  TH1* hist_eta_submuon_mumu_tV=(TH1*)temp_tV->Get("hist_eta_submuon_mumu");
  TH1* hist_eta_submuon_mumu_ttH=(TH1*)temp_ttH->Get("hist_eta_submuon_mumu");
  TH1* hist_eta_submuon_mumu_Vgam=(TH1*)temp_Vgam->Get("hist_eta_submuon_mumu");

  hist_eta_submuon_mumu_diboson->Scale(lumi());
  hist_eta_submuon_mumu_ttV->Scale(lumi());
  hist_eta_submuon_mumu_tV->Scale(lumi());
  hist_eta_submuon_mumu_ttH->Scale(lumi());
  hist_eta_submuon_mumu_Vgam->Scale(lumi());
  //emu
    TH1* hist_eta_muon_emu_data=(TH1*)temp_data->Get("hist_eta_muon_emu");
  TH1* hist_eta_muon_emu_diboson=(TH1*)temp_diboson->Get("hist_eta_muon_emu");
  TH1* hist_eta_muon_emu_ttV=(TH1*)temp_ttV->Get("hist_eta_muon_emu");
  TH1* hist_eta_muon_emu_tV=(TH1*)temp_tV->Get("hist_eta_muon_emu");
  TH1* hist_eta_muon_emu_ttH=(TH1*)temp_ttH->Get("hist_eta_muon_emu");
  TH1* hist_eta_muon_emu_Vgam=(TH1*)temp_Vgam->Get("hist_eta_muon_emu");
  TH1* hist_eta_electron_emu_QmisID=(TH1*)temp_QmisID_data->Get("hist_eta_electron_emu");

  hist_eta_muon_emu_diboson->Scale(lumi());
  hist_eta_muon_emu_ttV->Scale(lumi());
  hist_eta_muon_emu_tV->Scale(lumi());
  hist_eta_muon_emu_ttH->Scale(lumi());
  hist_eta_muon_emu_Vgam->Scale(lumi());
  Float_t data_count_ee=GHTBCs(hist_eta_subelectron_ee_data),data_count_ee_error=statistic_error(hist_eta_subelectron_ee_data);
  Float_t data_count_mumu=GHTBCs(hist_eta_submuon_mumu_data),data_count_mumu_error=statistic_error(hist_eta_submuon_mumu_data);
  Float_t data_count_emu=GHTBCs(hist_eta_muon_emu_data),data_count_emu_error=statistic_error(hist_eta_muon_emu_data);
  Float_t promptSS_count_ee=GHTBCs(hist_eta_subelectron_ee_diboson)+GHTBCs(hist_eta_subelectron_ee_ttV)+GHTBCs(hist_eta_subelectron_ee_tV)+GHTBCs(hist_eta_subelectron_ee_ttH);
  Float_t promptSS_count_mumu=GHTBCs(hist_eta_submuon_mumu_diboson)+GHTBCs(hist_eta_submuon_mumu_ttV)+GHTBCs(hist_eta_submuon_mumu_tV)+GHTBCs(hist_eta_submuon_mumu_ttH);
  Float_t promptSS_count_emu=GHTBCs(hist_eta_muon_emu_diboson)+GHTBCs(hist_eta_muon_emu_ttV)+GHTBCs(hist_eta_muon_emu_tV)+GHTBCs(hist_eta_muon_emu_ttH);

  Float_t promptSS_count_ee_error=sqrt(statistic_error(hist_eta_subelectron_ee_diboson)*statistic_error(hist_eta_subelectron_ee_diboson)+statistic_error(hist_eta_subelectron_ee_ttV)*statistic_error(hist_eta_subelectron_ee_ttV)+statistic_error(hist_eta_subelectron_ee_tV)*statistic_error(hist_eta_subelectron_ee_tV)+statistic_error(hist_eta_subelectron_ee_ttH)*statistic_error(hist_eta_subelectron_ee_ttH));

  Float_t promptSS_count_mumu_error=sqrt(statistic_error(hist_eta_submuon_mumu_diboson)*statistic_error(hist_eta_submuon_mumu_diboson)+statistic_error(hist_eta_submuon_mumu_ttV)*statistic_error(hist_eta_submuon_mumu_ttV)+statistic_error(hist_eta_submuon_mumu_tV)*statistic_error(hist_eta_submuon_mumu_tV)+statistic_error(hist_eta_submuon_mumu_ttH)*statistic_error(hist_eta_submuon_mumu_ttH));

  Float_t promptSS_count_emu_error=sqrt(statistic_error(hist_eta_muon_emu_diboson)*statistic_error(hist_eta_muon_emu_diboson)+statistic_error(hist_eta_muon_emu_ttV)*statistic_error(hist_eta_muon_emu_ttV)+statistic_error(hist_eta_muon_emu_tV)*statistic_error(hist_eta_muon_emu_tV)+statistic_error(hist_eta_muon_emu_ttH)*statistic_error(hist_eta_muon_emu_ttH));

  Float_t Vgam_count_ee=GHTBCs(hist_eta_subelectron_ee_Vgam),Vgam_count_ee_error=statistic_error(hist_eta_subelectron_ee_Vgam); 
  Float_t Vgam_count_mumu=GHTBCs(hist_eta_submuon_mumu_Vgam),Vgam_count_mumu_error=statistic_error(hist_eta_submuon_mumu_Vgam); 
  Float_t Vgam_count_emu=GHTBCs(hist_eta_muon_emu_Vgam),Vgam_count_emu_error=statistic_error(hist_eta_muon_emu_Vgam); 

  Float_t QmisID_count_ee=GHTBCs(hist_eta_subelectron_ee_QmisID),QmisID_count_ee_error=statistic_error(hist_eta_subelectron_ee_QmisID);
  Float_t QmisID_count_emu=GHTBCs(hist_eta_electron_emu_QmisID),QmisID_count_emu_error=statistic_error(hist_eta_electron_emu_QmisID);
  
  Float_t left_ee=data_count_ee-promptSS_count_ee-Vgam_count_ee-QmisID_count_ee;
  Float_t left_mumu=data_count_mumu-promptSS_count_mumu-Vgam_count_mumu;
  Float_t left_emu=data_count_emu-promptSS_count_emu-Vgam_count_emu-QmisID_count_emu;
  cout<<setw(12)<<"            ee            "<<"mumu                "<<"emu         "<<endl;
  cout<<"data"<<setw(10)<<data_count_ee<<"+-"<<data_count_ee_error<<setw(10)<<data_count_mumu<<"+-"<<data_count_mumu_error<<setw(10)<<
        setw(10)<<data_count_emu<<"+-"<<data_count_emu_error<<endl;
  cout<<"QmisID"<<setw(10)<<QmisID_count_ee<<"+-"<<QmisID_count_ee_error<<setw(10)<<"~"<<setw(10)<<setw(10)<<
        QmisID_count_emu<<"+-"<<QmisID_count_emu_error<<endl;
  cout<<"prompt SS"<<setw(10)<<promptSS_count_ee<<"+-"<<promptSS_count_ee_error<<setw(10)<<promptSS_count_mumu<<"+-"<<
        promptSS_count_mumu_error<<setw(10)<<setw(10)<<promptSS_count_emu<<"+-"<<promptSS_count_emu_error<<endl;
  cout<<"Vgam"<<setw(10)<<Vgam_count_ee<<"+-"<<Vgam_count_ee_error<<setw(10)<<Vgam_count_mumu<<"+-"<<Vgam_count_mumu_error<<
        setw(10)<<setw(10)<<Vgam_count_emu<<"+-"<<Vgam_count_emu_error<<endl;
  cout<<"left"<<setw(10)<<left_ee<<setw(10)<<left_mumu<<setw(10)<<left_emu<<endl;


}

