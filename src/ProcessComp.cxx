#include "TFile.h"
#include "TH1.h"
#include "TH1F.h"
#include "GHTBCs.cxx"
#include "lumi.cxx"
#include "readFF.cxx"
void ProcessComp(){
 
  TFile *tmp_data=new TFile("temp/std_nominalMC/hists_FFcal_1jets_datacombined.root"); 
  TFile *tmp_diboson=new TFile("temp/std_nominalMC/hists_FFcal_1jets_diboson.root");
  TFile *tmp_ttV=new TFile("temp/std_nominalMC/hists_FFcal_1jets_ttV.root");
  TFile *tmp_tV=new TFile("temp/std_nominalMC/hists_FFcal_1jets_tV.root");
  TFile *tmp_ttH=new TFile("temp/std_nominalMC/hists_FFcal_1jets_ttH.root");
  TFile *tmp_DY=new TFile("temp/std_nominalMC/hists_FFcal_1jets_DY.root");
  TFile *tmp_WW=new TFile("temp/std_nominalMC/hists_FFcal_1jets_WW.root");
  TFile *tmp_Vgam=new TFile("temp/std_nominalMC/hists_FFcal_1jets_Vgam.root");
  TFile *tmp_Zjets=new TFile("temp/std_nominalMC/hists_FFcal_1jets_Zjets.root");
  TFile *tmp_Wjets=new TFile("temp/std_nominalMC/hists_FFcal_1jets_Wjets.root");
  TFile *tmp_ttbar=new TFile("temp/std_nominalMC/hists_FFcal_1jets_ttbar.root");
  TFile *tmp_signal=new TFile("temp/std_nominalMC/hists_FFcal_1jets_H340_S165.root");
 
  if(1==1){ 
  TH1* hist_eta_ee_data=(TH1*)tmp_data->Get("hist_eta_subelectron_ee");
  TH1* hist_eta_ee_diboson=(TH1*)tmp_diboson->Get("hist_eta_subelectron_ee");
  TH1* hist_eta_ee_ttV=(TH1*)tmp_ttV->Get("hist_eta_subelectron_ee");
  TH1* hist_eta_ee_tV=(TH1*)tmp_tV->Get("hist_eta_subelectron_ee");
  TH1* hist_eta_ee_ttH=(TH1*)tmp_ttH->Get("hist_eta_subelectron_ee");
  TH1* hist_eta_ee_DY=(TH1*)tmp_DY->Get("hist_eta_subelectron_ee");
  TH1* hist_eta_ee_WW=(TH1*)tmp_WW->Get("hist_eta_subelectron_ee");
  TH1* hist_eta_ee_Vgam=(TH1*)tmp_Vgam->Get("hist_eta_subelectron_ee");
  TH1* hist_eta_ee_Zjets=(TH1*)tmp_Zjets->Get("hist_eta_subelectron_ee");
  TH1* hist_eta_ee_Wjets=(TH1*)tmp_Wjets->Get("hist_eta_subelectron_ee");
  TH1* hist_eta_ee_ttbar=(TH1*)tmp_ttbar->Get("hist_eta_subelectron_ee");
  TH1* hist_eta_ee_signal=(TH1*)tmp_signal->Get("hist_eta_subelectron_ee");

  TH1* hist_eta_ee_data_noff=(TH1*)tmp_data->Get("hist_eta_antiidelectron_eantiide");
  TH1* hist_eta_ee_diboson_noff=(TH1*)tmp_diboson->Get("hist_eta_antiidelectron_eantiide");
  TH1* hist_eta_ee_ttV_noff=(TH1*)tmp_ttV->Get("hist_eta_antiidelectron_eantiide");
  TH1* hist_eta_ee_tV_noff=(TH1*)tmp_tV->Get("hist_eta_antiidelectron_eantiide");
  TH1* hist_eta_ee_ttH_noff=(TH1*)tmp_ttH->Get("hist_eta_antiidelectron_eantiide");
  TH1* hist_eta_ee_DY_noff=(TH1*)tmp_DY->Get("hist_eta_antiidelectron_eantiide");
  TH1* hist_eta_ee_WW_noff=(TH1*)tmp_WW->Get("hist_eta_antiidelectron_eantiide");
  TH1* hist_eta_ee_Vgam_noff=(TH1*)tmp_Vgam->Get("hist_eta_antiidelectron_eantiide");
  TH1* hist_eta_ee_Zjets_noff=(TH1*)tmp_Zjets->Get("hist_eta_antiidelectron_eantiide");
  TH1* hist_eta_ee_Wjets_noff=(TH1*)tmp_Wjets->Get("hist_eta_antiidelectron_eantiide");
  TH1* hist_eta_ee_ttbar_noff=(TH1*)tmp_ttbar->Get("hist_eta_antiidelectron_eantiide");
  TH1* hist_eta_ee_signal_noff=(TH1*)tmp_signal->Get("hist_eta_antiidelectron_eantiide");

  hist_eta_ee_diboson->Scale(lumi());
  hist_eta_ee_ttV->Scale(lumi());
  hist_eta_ee_tV->Scale(lumi());
  hist_eta_ee_ttH->Scale(lumi());
  hist_eta_ee_Vgam->Scale(lumi());
  hist_eta_ee_Zjets->Scale(lumi());
  hist_eta_ee_Wjets->Scale(lumi());
  hist_eta_ee_DY->Scale(lumi());
  hist_eta_ee_WW->Scale(lumi());
  hist_eta_ee_ttbar->Scale(lumi());
  hist_eta_ee_signal->Scale(lumi()*10*500*0.08842);
 
  hist_eta_ee_diboson_noff->Scale(lumi());
  hist_eta_ee_ttV_noff->Scale(lumi());
  hist_eta_ee_tV_noff->Scale(lumi());
  hist_eta_ee_ttH_noff->Scale(lumi());
  hist_eta_ee_Vgam_noff->Scale(lumi());
  hist_eta_ee_Zjets_noff->Scale(lumi());
  hist_eta_ee_Wjets_noff->Scale(lumi());
  hist_eta_ee_DY_noff->Scale(lumi());
  hist_eta_ee_WW_noff->Scale(lumi());
  hist_eta_ee_ttbar_noff->Scale(lumi());
  hist_eta_ee_signal_noff->Scale(lumi()*10*500*0.08842);
  //
  Float_t num_data=GHTBCs(hist_eta_ee_data), error_num_data=statistic_error(hist_eta_ee_data);
  Float_t num_VV=GHTBCs(hist_eta_ee_diboson), error_num_VV=statistic_error(hist_eta_ee_diboson);
  Float_t num_ttV=GHTBCs(hist_eta_ee_ttV), error_num_ttV=statistic_error(hist_eta_ee_ttV);
  Float_t num_tV=GHTBCs(hist_eta_ee_tV), error_num_tV=statistic_error(hist_eta_ee_tV);
  Float_t num_ttH=GHTBCs(hist_eta_ee_ttH), error_num_ttH=statistic_error(hist_eta_ee_ttH);
  Float_t num_Vgam=GHTBCs(hist_eta_ee_Vgam), error_num_Vgam=statistic_error(hist_eta_ee_Vgam);
  Float_t num_ttbar=GHTBCs(hist_eta_ee_ttbar), error_num_ttbar=statistic_error(hist_eta_ee_ttbar);
  Float_t num_Zjets=GHTBCs(hist_eta_ee_Zjets), error_num_Zjets=statistic_error(hist_eta_ee_Zjets);
  Float_t num_Wjets=GHTBCs(hist_eta_ee_Wjets), error_num_Wjets=statistic_error(hist_eta_ee_Wjets);
  Float_t num_DY=GHTBCs(hist_eta_ee_DY), error_num_DY=statistic_error(hist_eta_ee_DY);
  Float_t num_WW=GHTBCs(hist_eta_ee_WW), error_num_WW=statistic_error(hist_eta_ee_WW);
  Float_t num_signal=GHTBCs(hist_eta_ee_signal), error_num_signal=statistic_error(hist_eta_ee_signal);

  Float_t num_promptSS=num_VV+num_ttV+num_tV+num_ttH, error_num_promptSS=sqrt(pow(error_num_VV,2)+pow(error_num_ttV,2)+pow(error_num_tV,2)+pow(error_num_ttH,2));
  Float_t num_Zgam=num_Zjets+num_DY, error_num_Zgam=sqrt(pow(error_num_Zjets,2)+pow(error_num_DY,2));
  Float_t num_totalbkg=num_promptSS+num_Zgam+num_Vgam+num_Wjets+num_ttbar, error_num_totalbkg=sqrt(pow(num_promptSS,2)+pow(num_Zgam,2)+pow(num_Vgam,2)+pow(num_Wjets,2)+pow(num_ttbar,2));

  Float_t num_data_noff=GHTBCs(hist_eta_ee_data_noff), error_num_data_noff=statistic_error(hist_eta_ee_data_noff);
  Float_t num_VV_noff=GHTBCs(hist_eta_ee_diboson_noff), error_num_VV_noff=statistic_error(hist_eta_ee_diboson_noff);
  Float_t num_ttV_noff=GHTBCs(hist_eta_ee_ttV_noff), error_num_ttV_noff=statistic_error(hist_eta_ee_ttV_noff);
  Float_t num_tV_noff=GHTBCs(hist_eta_ee_tV_noff), error_num_tV_noff=statistic_error(hist_eta_ee_tV_noff);
  Float_t num_ttH_noff=GHTBCs(hist_eta_ee_ttH_noff), error_num_ttH_noff=statistic_error(hist_eta_ee_ttH_noff);
  Float_t num_Vgam_noff=GHTBCs(hist_eta_ee_Vgam_noff), error_num_Vgam_noff=statistic_error(hist_eta_ee_Vgam_noff);
  Float_t num_ttbar_noff=GHTBCs(hist_eta_ee_ttbar_noff), error_num_ttbar_noff=statistic_error(hist_eta_ee_ttbar_noff);
  Float_t num_Zjets_noff=GHTBCs(hist_eta_ee_Zjets_noff), error_num_Zjets_noff=statistic_error(hist_eta_ee_Zjets_noff);
  Float_t num_Wjets_noff=GHTBCs(hist_eta_ee_Wjets_noff), error_num_Wjets_noff=statistic_error(hist_eta_ee_Wjets_noff);
  Float_t num_DY_noff=GHTBCs(hist_eta_ee_DY_noff), error_num_DY_noff=statistic_error(hist_eta_ee_DY_noff);
  Float_t num_WW_noff=GHTBCs(hist_eta_ee_WW_noff), error_num_WW_noff=statistic_error(hist_eta_ee_WW_noff);
  Float_t num_signal_noff=GHTBCs(hist_eta_ee_signal_noff), error_num_signal_noff=statistic_error(hist_eta_ee_signal_noff);

  Float_t num_promptSS_noff=num_VV_noff+num_ttV_noff+num_tV_noff+num_ttH_noff, error_num_promptSS_noff=sqrt(pow(error_num_VV_noff,2)+pow(error_num_ttV_noff,2)+pow(error_num_tV_noff,2)+pow(error_num_ttH_noff,2));
  Float_t num_Zgam_noff=num_Zjets_noff+num_DY_noff, error_num_Zgam_noff=sqrt(pow(error_num_Zjets_noff,2)+pow(error_num_DY_noff,2));
  Float_t num_totalbkg_noff=num_promptSS_noff+num_Zgam_noff+num_Vgam_noff+num_Wjets_noff+num_ttbar_noff, error_num_totalbkg_noff=sqrt(pow(num_promptSS_noff,2)+pow(num_Zgam_noff,2)+pow(num_Vgam_noff,2)+pow(num_Wjets_noff,2)+pow(num_ttbar_noff,2));
  cout<<setiosflags(ios::fixed)<<setprecision(2);
  cout<<"$ee$ "<<"&"<<num_promptSS<<"$\\pm$"<<error_num_promptSS<<setw(5)<<"&"<<num_Vgam<<"$\\pm$"<<error_num_Vgam<<setw(5)<<"&"<<num_Zgam<<"$\\pm$"<<error_num_Zgam<<setw(5)<<"&"<<num_WW<<"$\\pm$"<<error_num_WW<<setw(5)<<"&"<<num_ttbar<<"$\\pm$"<<error_num_ttbar<<setw(5)<<"&"<<num_Wjets<<"$\\pm$"<<error_num_Wjets<<setw(5)<<"&"<<num_totalbkg<<"$\\pm$"<<error_num_totalbkg<<setw(5)<<"&"<<num_data<<setw(5)<<"&"<<num_signal<<"$\\pm$"<<error_num_signal<<endl;
  cout<<"$e\\cancel{e}$ "<<"&"<<num_promptSS_noff<<"$\\pm$"<<error_num_promptSS_noff<<setw(5)<<"&"<<num_Vgam_noff<<"$\\pm$"<<error_num_Vgam_noff<<setw(5)<<"&"<<num_Zgam_noff<<"$\\pm$"<<error_num_Zgam_noff<<setw(5)<<"&"<<num_WW_noff<<"$\\pm$"<<error_num_WW_noff<<setw(5)<<"&"<<num_ttbar_noff<<"$\\pm$"<<error_num_ttbar_noff<<setw(5)<<"&"<<num_Wjets_noff<<"$\\pm$"<<error_num_Wjets_noff<<setw(5)<<"&"<<num_totalbkg_noff<<"$\\pm$"<<error_num_totalbkg_noff<<setw(5)<<"&"<<num_data_noff<<setw(5)<<"&"<<num_signal_noff<<"$\\pm$"<<error_num_signal_noff<<endl;
  }

  if(1==1){ 
  TH1* hist_eta_mumu_data=(TH1*)tmp_data->Get("hist_eta_submuon_mumu");
  TH1* hist_eta_mumu_diboson=(TH1*)tmp_diboson->Get("hist_eta_submuon_mumu");
  TH1* hist_eta_mumu_ttV=(TH1*)tmp_ttV->Get("hist_eta_submuon_mumu");
  TH1* hist_eta_mumu_tV=(TH1*)tmp_tV->Get("hist_eta_submuon_mumu");
  TH1* hist_eta_mumu_ttH=(TH1*)tmp_ttH->Get("hist_eta_submuon_mumu");
  TH1* hist_eta_mumu_DY=(TH1*)tmp_DY->Get("hist_eta_submuon_mumu");
  TH1* hist_eta_mumu_WW=(TH1*)tmp_WW->Get("hist_eta_submuon_mumu");
  TH1* hist_eta_mumu_Vgam=(TH1*)tmp_Vgam->Get("hist_eta_submuon_mumu");
  TH1* hist_eta_mumu_Zjets=(TH1*)tmp_Zjets->Get("hist_eta_submuon_mumu");
  TH1* hist_eta_mumu_Wjets=(TH1*)tmp_Wjets->Get("hist_eta_submuon_mumu");
  TH1* hist_eta_mumu_ttbar=(TH1*)tmp_ttbar->Get("hist_eta_submuon_mumu");
  TH1* hist_eta_mumu_signal=(TH1*)tmp_signal->Get("hist_eta_submuon_mumu");

  TH1* hist_eta_mumu_data_noff=(TH1*)tmp_data->Get("hist_eta_antiidmuon_muantiidmu");
  TH1* hist_eta_mumu_diboson_noff=(TH1*)tmp_diboson->Get("hist_eta_antiidmuon_muantiidmu");
  TH1* hist_eta_mumu_ttV_noff=(TH1*)tmp_ttV->Get("hist_eta_antiidmuon_muantiidmu");
  TH1* hist_eta_mumu_tV_noff=(TH1*)tmp_tV->Get("hist_eta_antiidmuon_muantiidmu");
  TH1* hist_eta_mumu_ttH_noff=(TH1*)tmp_ttH->Get("hist_eta_antiidmuon_muantiidmu");
  TH1* hist_eta_mumu_DY_noff=(TH1*)tmp_DY->Get("hist_eta_antiidmuon_muantiidmu");
  TH1* hist_eta_mumu_WW_noff=(TH1*)tmp_WW->Get("hist_eta_antiidmuon_muantiidmu");
  TH1* hist_eta_mumu_Vgam_noff=(TH1*)tmp_Vgam->Get("hist_eta_antiidmuon_muantiidmu");
  TH1* hist_eta_mumu_Zjets_noff=(TH1*)tmp_Zjets->Get("hist_eta_antiidmuon_muantiidmu");
  TH1* hist_eta_mumu_Wjets_noff=(TH1*)tmp_Wjets->Get("hist_eta_antiidmuon_muantiidmu");
  TH1* hist_eta_mumu_ttbar_noff=(TH1*)tmp_ttbar->Get("hist_eta_antiidmuon_muantiidmu");
  TH1* hist_eta_mumu_signal_noff=(TH1*)tmp_signal->Get("hist_eta_antiidmuon_muantiidmu");

  hist_eta_mumu_diboson->Scale(lumi());
  hist_eta_mumu_ttV->Scale(lumi());
  hist_eta_mumu_tV->Scale(lumi());
  hist_eta_mumu_ttH->Scale(lumi());
  hist_eta_mumu_Vgam->Scale(lumi());
  hist_eta_mumu_Zjets->Scale(lumi());
  hist_eta_mumu_Wjets->Scale(lumi());
  hist_eta_mumu_DY->Scale(lumi());
  hist_eta_mumu_WW->Scale(lumi());
  hist_eta_mumu_ttbar->Scale(lumi());
  hist_eta_mumu_signal->Scale(lumi()*10*500*0.08842);
 
  hist_eta_mumu_diboson_noff->Scale(lumi());
  hist_eta_mumu_ttV_noff->Scale(lumi());
  hist_eta_mumu_tV_noff->Scale(lumi());
  hist_eta_mumu_ttH_noff->Scale(lumi());
  hist_eta_mumu_Vgam_noff->Scale(lumi());
  hist_eta_mumu_Zjets_noff->Scale(lumi());
  hist_eta_mumu_Wjets_noff->Scale(lumi());
  hist_eta_mumu_DY_noff->Scale(lumi());
  hist_eta_mumu_WW_noff->Scale(lumi());
  hist_eta_mumu_ttbar_noff->Scale(lumi());
  hist_eta_mumu_signal_noff->Scale(lumi()*10*500*0.08842);
  //
  Float_t num_data=GHTBCs(hist_eta_mumu_data), error_num_data=statistic_error(hist_eta_mumu_data);
  Float_t num_VV=GHTBCs(hist_eta_mumu_diboson), error_num_VV=statistic_error(hist_eta_mumu_diboson);
  Float_t num_ttV=GHTBCs(hist_eta_mumu_ttV), error_num_ttV=statistic_error(hist_eta_mumu_ttV);
  Float_t num_tV=GHTBCs(hist_eta_mumu_tV), error_num_tV=statistic_error(hist_eta_mumu_tV);
  Float_t num_ttH=GHTBCs(hist_eta_mumu_ttH), error_num_ttH=statistic_error(hist_eta_mumu_ttH);
  Float_t num_Vgam=GHTBCs(hist_eta_mumu_Vgam), error_num_Vgam=statistic_error(hist_eta_mumu_Vgam);
  Float_t num_ttbar=GHTBCs(hist_eta_mumu_ttbar), error_num_ttbar=statistic_error(hist_eta_mumu_ttbar);
  Float_t num_Zjets=GHTBCs(hist_eta_mumu_Zjets), error_num_Zjets=statistic_error(hist_eta_mumu_Zjets);
  Float_t num_Wjets=GHTBCs(hist_eta_mumu_Wjets), error_num_Wjets=statistic_error(hist_eta_mumu_Wjets);
  Float_t num_DY=GHTBCs(hist_eta_mumu_DY), error_num_DY=statistic_error(hist_eta_mumu_DY);
  Float_t num_WW=GHTBCs(hist_eta_mumu_WW), error_num_WW=statistic_error(hist_eta_mumu_WW);
  Float_t num_signal=GHTBCs(hist_eta_mumu_signal), error_num_signal=statistic_error(hist_eta_mumu_signal);

  Float_t num_promptSS=num_VV+num_ttV+num_tV+num_ttH, error_num_promptSS=sqrt(pow(error_num_VV,2)+pow(error_num_ttV,2)+pow(error_num_tV,2)+pow(error_num_ttH,2));
  Float_t num_Zgam=num_Zjets+num_DY, error_num_Zgam=sqrt(pow(error_num_Zjets,2)+pow(error_num_DY,2));
  Float_t num_totalbkg=num_promptSS+num_Zgam+num_Vgam+num_Wjets+num_ttbar, error_num_totalbkg=sqrt(pow(num_promptSS,2)+pow(num_Zgam,2)+pow(num_Vgam,2)+pow(num_Wjets,2)+pow(num_ttbar,2));

  Float_t num_data_noff=GHTBCs(hist_eta_mumu_data_noff), error_num_data_noff=statistic_error(hist_eta_mumu_data_noff);
  Float_t num_VV_noff=GHTBCs(hist_eta_mumu_diboson_noff), error_num_VV_noff=statistic_error(hist_eta_mumu_diboson_noff);
  Float_t num_ttV_noff=GHTBCs(hist_eta_mumu_ttV_noff), error_num_ttV_noff=statistic_error(hist_eta_mumu_ttV_noff);
  Float_t num_tV_noff=GHTBCs(hist_eta_mumu_tV_noff), error_num_tV_noff=statistic_error(hist_eta_mumu_tV_noff);
  Float_t num_ttH_noff=GHTBCs(hist_eta_mumu_ttH_noff), error_num_ttH_noff=statistic_error(hist_eta_mumu_ttH_noff);
  Float_t num_Vgam_noff=GHTBCs(hist_eta_mumu_Vgam_noff), error_num_Vgam_noff=statistic_error(hist_eta_mumu_Vgam_noff);
  Float_t num_ttbar_noff=GHTBCs(hist_eta_mumu_ttbar_noff), error_num_ttbar_noff=statistic_error(hist_eta_mumu_ttbar_noff);
  Float_t num_Zjets_noff=GHTBCs(hist_eta_mumu_Zjets_noff), error_num_Zjets_noff=statistic_error(hist_eta_mumu_Zjets_noff);
  Float_t num_Wjets_noff=GHTBCs(hist_eta_mumu_Wjets_noff), error_num_Wjets_noff=statistic_error(hist_eta_mumu_Wjets_noff);
  Float_t num_DY_noff=GHTBCs(hist_eta_mumu_DY_noff), error_num_DY_noff=statistic_error(hist_eta_mumu_DY_noff);
  Float_t num_WW_noff=GHTBCs(hist_eta_mumu_WW_noff), error_num_WW_noff=statistic_error(hist_eta_mumu_WW_noff);
  Float_t num_signal_noff=GHTBCs(hist_eta_mumu_signal_noff), error_num_signal_noff=statistic_error(hist_eta_mumu_signal_noff);

  Float_t num_promptSS_noff=num_VV_noff+num_ttV_noff+num_tV_noff+num_ttH_noff, error_num_promptSS_noff=sqrt(pow(error_num_VV_noff,2)+pow(error_num_ttV_noff,2)+pow(error_num_tV_noff,2)+pow(error_num_ttH_noff,2));
  Float_t num_Zgam_noff=num_Zjets_noff+num_DY_noff, error_num_Zgam_noff=sqrt(pow(error_num_Zjets_noff,2)+pow(error_num_DY_noff,2));
  Float_t num_totalbkg_noff=num_promptSS_noff+num_Zgam_noff+num_Vgam_noff+num_Wjets_noff+num_ttbar_noff, error_num_totalbkg_noff=sqrt(pow(num_promptSS_noff,2)+pow(num_Zgam_noff,2)+pow(num_Vgam_noff,2)+pow(num_Wjets_noff,2)+pow(num_ttbar_noff,2));
  cout<<setiosflags(ios::fixed)<<setprecision(2);
  cout<<"$\\mu\\mu$ "<<"&"<<num_promptSS<<"$\\pm$"<<error_num_promptSS<<setw(5)<<"&"<<num_Vgam<<"$\\pm$"<<error_num_Vgam<<setw(5)<<"&"<<num_Zgam<<"$\\pm$"<<error_num_Zgam<<setw(5)<<"&"<<num_WW<<"$\\pm$"<<error_num_WW<<setw(5)<<"&"<<num_ttbar<<"$\\pm$"<<error_num_ttbar<<setw(5)<<"&"<<num_Wjets<<"$\\pm$"<<error_num_Wjets<<setw(5)<<"&"<<num_totalbkg<<"$\\pm$"<<error_num_totalbkg<<setw(5)<<"&"<<num_data<<setw(5)<<"&"<<num_signal<<"$\\pm$"<<error_num_signal<<endl;
  cout<<"$\\mu\\cancel{\\mu}$ "<<"&"<<num_promptSS_noff<<"$\\pm$"<<error_num_promptSS_noff<<setw(5)<<"&"<<num_Vgam_noff<<"$\\pm$"<<error_num_Vgam_noff<<setw(5)<<"&"<<num_Zgam_noff<<"$\\pm$"<<error_num_Zgam_noff<<setw(5)<<"&"<<num_WW_noff<<"$\\pm$"<<error_num_WW_noff<<setw(5)<<"&"<<num_ttbar_noff<<"$\\pm$"<<error_num_ttbar_noff<<setw(5)<<"&"<<num_Wjets_noff<<"$\\pm$"<<error_num_Wjets_noff<<setw(5)<<"&"<<num_totalbkg_noff<<"$\\pm$"<<error_num_totalbkg_noff<<setw(5)<<"&"<<num_data_noff<<setw(5)<<"&"<<num_signal_noff<<"$\\pm$"<<error_num_signal_noff<<endl;
  }
  //end mumu

  if(1==1){ 
  TH1* hist_eta_emu_data=(TH1*)tmp_data->Get("hist_eta_electron_emu");
  TH1* hist_eta_emu_diboson=(TH1*)tmp_diboson->Get("hist_eta_electron_emu");
  TH1* hist_eta_emu_ttV=(TH1*)tmp_ttV->Get("hist_eta_electron_emu");
  TH1* hist_eta_emu_tV=(TH1*)tmp_tV->Get("hist_eta_electron_emu");
  TH1* hist_eta_emu_ttH=(TH1*)tmp_ttH->Get("hist_eta_electron_emu");
  TH1* hist_eta_emu_DY=(TH1*)tmp_DY->Get("hist_eta_electron_emu");
  TH1* hist_eta_emu_WW=(TH1*)tmp_WW->Get("hist_eta_electron_emu");
  TH1* hist_eta_emu_Vgam=(TH1*)tmp_Vgam->Get("hist_eta_electron_emu");
  TH1* hist_eta_emu_Zjets=(TH1*)tmp_Zjets->Get("hist_eta_electron_emu");
  TH1* hist_eta_emu_Wjets=(TH1*)tmp_Wjets->Get("hist_eta_electron_emu");
  TH1* hist_eta_emu_ttbar=(TH1*)tmp_ttbar->Get("hist_eta_electron_emu");
  TH1* hist_eta_emu_signal=(TH1*)tmp_signal->Get("hist_eta_electron_emu");

  TH1* hist_eta_emu_data_noff=(TH1*)tmp_data->Get("hist_eta_antiidelectron_antiidemu");
  TH1* hist_eta_emu_diboson_noff=(TH1*)tmp_diboson->Get("hist_eta_antiidelectron_antiidemu");
  TH1* hist_eta_emu_ttV_noff=(TH1*)tmp_ttV->Get("hist_eta_antiidelectron_antiidemu");
  TH1* hist_eta_emu_tV_noff=(TH1*)tmp_tV->Get("hist_eta_antiidelectron_antiidemu");
  TH1* hist_eta_emu_ttH_noff=(TH1*)tmp_ttH->Get("hist_eta_antiidelectron_antiidemu");
  TH1* hist_eta_emu_DY_noff=(TH1*)tmp_DY->Get("hist_eta_antiidelectron_antiidemu");
  TH1* hist_eta_emu_WW_noff=(TH1*)tmp_WW->Get("hist_eta_antiidelectron_antiidemu");
  TH1* hist_eta_emu_Vgam_noff=(TH1*)tmp_Vgam->Get("hist_eta_antiidelectron_antiidemu");
  TH1* hist_eta_emu_Zjets_noff=(TH1*)tmp_Zjets->Get("hist_eta_antiidelectron_antiidemu");
  TH1* hist_eta_emu_Wjets_noff=(TH1*)tmp_Wjets->Get("hist_eta_antiidelectron_antiidemu");
  TH1* hist_eta_emu_ttbar_noff=(TH1*)tmp_ttbar->Get("hist_eta_antiidelectron_antiidemu");
  TH1* hist_eta_emu_signal_noff=(TH1*)tmp_signal->Get("hist_eta_antiidelectron_antiidemu");

  TH1* hist_eta_emu_data_noff2=(TH1*)tmp_data->Get("hist_eta_antiidmuon_eantiidmu");
  TH1* hist_eta_emu_diboson_noff2=(TH1*)tmp_diboson->Get("hist_eta_antiidmuon_eantiidmu");
  TH1* hist_eta_emu_ttV_noff2=(TH1*)tmp_ttV->Get("hist_eta_antiidmuon_eantiidmu");
  TH1* hist_eta_emu_tV_noff2=(TH1*)tmp_tV->Get("hist_eta_antiidmuon_eantiidmu");
  TH1* hist_eta_emu_ttH_noff2=(TH1*)tmp_ttH->Get("hist_eta_antiidmuon_eantiidmu");
  TH1* hist_eta_emu_DY_noff2=(TH1*)tmp_DY->Get("hist_eta_antiidmuon_eantiidmu");
  TH1* hist_eta_emu_WW_noff2=(TH1*)tmp_WW->Get("hist_eta_antiidmuon_eantiidmu");
  TH1* hist_eta_emu_Vgam_noff2=(TH1*)tmp_Vgam->Get("hist_eta_antiidmuon_eantiidmu");
  TH1* hist_eta_emu_Zjets_noff2=(TH1*)tmp_Zjets->Get("hist_eta_antiidmuon_eantiidmu");
  TH1* hist_eta_emu_Wjets_noff2=(TH1*)tmp_Wjets->Get("hist_eta_antiidmuon_eantiidmu");
  TH1* hist_eta_emu_ttbar_noff2=(TH1*)tmp_ttbar->Get("hist_eta_antiidmuon_eantiidmu");
  TH1* hist_eta_emu_signal_noff2=(TH1*)tmp_signal->Get("hist_eta_antiidmuon_eantiidmu");

  hist_eta_emu_diboson->Scale(lumi());
  hist_eta_emu_ttV->Scale(lumi());
  hist_eta_emu_tV->Scale(lumi());
  hist_eta_emu_ttH->Scale(lumi());
  hist_eta_emu_Vgam->Scale(lumi());
  hist_eta_emu_Zjets->Scale(lumi());
  hist_eta_emu_Wjets->Scale(lumi());
  hist_eta_emu_DY->Scale(lumi());
  hist_eta_emu_WW->Scale(lumi());
  hist_eta_emu_ttbar->Scale(lumi());
  hist_eta_emu_signal->Scale(lumi()*10*500*0.08842);
 
  hist_eta_emu_diboson_noff->Scale(lumi());
  hist_eta_emu_ttV_noff->Scale(lumi());
  hist_eta_emu_tV_noff->Scale(lumi());
  hist_eta_emu_ttH_noff->Scale(lumi());
  hist_eta_emu_Vgam_noff->Scale(lumi());
  hist_eta_emu_Zjets_noff->Scale(lumi());
  hist_eta_emu_Wjets_noff->Scale(lumi());
  hist_eta_emu_DY_noff->Scale(lumi());
  hist_eta_emu_WW_noff->Scale(lumi());
  hist_eta_emu_ttbar_noff->Scale(lumi());
  hist_eta_emu_signal_noff->Scale(lumi()*10*500*0.08842);

  hist_eta_emu_diboson_noff2->Scale(lumi());
  hist_eta_emu_ttV_noff2->Scale(lumi());
  hist_eta_emu_tV_noff2->Scale(lumi());
  hist_eta_emu_ttH_noff2->Scale(lumi());
  hist_eta_emu_Vgam_noff2->Scale(lumi());
  hist_eta_emu_Zjets_noff2->Scale(lumi());
  hist_eta_emu_Wjets_noff2->Scale(lumi());
  hist_eta_emu_DY_noff2->Scale(lumi());
  hist_eta_emu_WW_noff2->Scale(lumi());
  hist_eta_emu_ttbar_noff2->Scale(lumi());
  hist_eta_emu_signal_noff2->Scale(lumi()*10*500*0.08842);
  //
  Float_t num_data=GHTBCs(hist_eta_emu_data), error_num_data=statistic_error(hist_eta_emu_data);
  Float_t num_VV=GHTBCs(hist_eta_emu_diboson), error_num_VV=statistic_error(hist_eta_emu_diboson);
  Float_t num_ttV=GHTBCs(hist_eta_emu_ttV), error_num_ttV=statistic_error(hist_eta_emu_ttV);
  Float_t num_tV=GHTBCs(hist_eta_emu_tV), error_num_tV=statistic_error(hist_eta_emu_tV);
  Float_t num_ttH=GHTBCs(hist_eta_emu_ttH), error_num_ttH=statistic_error(hist_eta_emu_ttH);
  Float_t num_Vgam=GHTBCs(hist_eta_emu_Vgam), error_num_Vgam=statistic_error(hist_eta_emu_Vgam);
  Float_t num_ttbar=GHTBCs(hist_eta_emu_ttbar), error_num_ttbar=statistic_error(hist_eta_emu_ttbar);
  Float_t num_Zjets=GHTBCs(hist_eta_emu_Zjets), error_num_Zjets=statistic_error(hist_eta_emu_Zjets);
  Float_t num_Wjets=GHTBCs(hist_eta_emu_Wjets), error_num_Wjets=statistic_error(hist_eta_emu_Wjets);
  Float_t num_DY=GHTBCs(hist_eta_emu_DY), error_num_DY=statistic_error(hist_eta_emu_DY);
  Float_t num_WW=GHTBCs(hist_eta_emu_WW), error_num_WW=statistic_error(hist_eta_emu_WW);
  Float_t num_signal=GHTBCs(hist_eta_emu_signal), error_num_signal=statistic_error(hist_eta_emu_signal);

  Float_t num_promptSS=num_VV+num_ttV+num_tV+num_ttH, error_num_promptSS=sqrt(pow(error_num_VV,2)+pow(error_num_ttV,2)+pow(error_num_tV,2)+pow(error_num_ttH,2));
  Float_t num_Zgam=num_Zjets+num_DY, error_num_Zgam=sqrt(pow(error_num_Zjets,2)+pow(error_num_DY,2));
  Float_t num_totalbkg=num_promptSS+num_Zgam+num_Vgam+num_Wjets+num_ttbar, error_num_totalbkg=sqrt(pow(num_promptSS,2)+pow(num_Zgam,2)+pow(num_Vgam,2)+pow(num_Wjets,2)+pow(num_ttbar,2));

  Float_t num_data_noff=GHTBCs(hist_eta_emu_data_noff), error_num_data_noff=statistic_error(hist_eta_emu_data_noff);
  Float_t num_VV_noff=GHTBCs(hist_eta_emu_diboson_noff), error_num_VV_noff=statistic_error(hist_eta_emu_diboson_noff);
  Float_t num_ttV_noff=GHTBCs(hist_eta_emu_ttV_noff), error_num_ttV_noff=statistic_error(hist_eta_emu_ttV_noff);
  Float_t num_tV_noff=GHTBCs(hist_eta_emu_tV_noff), error_num_tV_noff=statistic_error(hist_eta_emu_tV_noff);
  Float_t num_ttH_noff=GHTBCs(hist_eta_emu_ttH_noff), error_num_ttH_noff=statistic_error(hist_eta_emu_ttH_noff);
  Float_t num_Vgam_noff=GHTBCs(hist_eta_emu_Vgam_noff), error_num_Vgam_noff=statistic_error(hist_eta_emu_Vgam_noff);
  Float_t num_ttbar_noff=GHTBCs(hist_eta_emu_ttbar_noff), error_num_ttbar_noff=statistic_error(hist_eta_emu_ttbar_noff);
  Float_t num_Zjets_noff=GHTBCs(hist_eta_emu_Zjets_noff), error_num_Zjets_noff=statistic_error(hist_eta_emu_Zjets_noff);
  Float_t num_Wjets_noff=GHTBCs(hist_eta_emu_Wjets_noff), error_num_Wjets_noff=statistic_error(hist_eta_emu_Wjets_noff);
  Float_t num_DY_noff=GHTBCs(hist_eta_emu_DY_noff), error_num_DY_noff=statistic_error(hist_eta_emu_DY_noff);
  Float_t num_WW_noff=GHTBCs(hist_eta_emu_WW_noff), error_num_WW_noff=statistic_error(hist_eta_emu_WW_noff);
  Float_t num_signal_noff=GHTBCs(hist_eta_emu_signal_noff), error_num_signal_noff=statistic_error(hist_eta_emu_signal_noff);

  Float_t num_promptSS_noff=num_VV_noff+num_ttV_noff+num_tV_noff+num_ttH_noff, error_num_promptSS_noff=sqrt(pow(error_num_VV_noff,2)+pow(error_num_ttV_noff,2)+pow(error_num_tV_noff,2)+pow(error_num_ttH_noff,2));
  Float_t num_Zgam_noff=num_Zjets_noff+num_DY_noff, error_num_Zgam_noff=sqrt(pow(error_num_Zjets_noff,2)+pow(error_num_DY_noff,2));
  Float_t num_totalbkg_noff=num_promptSS_noff+num_Zgam_noff+num_Vgam_noff+num_Wjets_noff+num_ttbar_noff, error_num_totalbkg_noff=sqrt(pow(num_promptSS_noff,2)+pow(num_Zgam_noff,2)+pow(num_Vgam_noff,2)+pow(num_Wjets_noff,2)+pow(num_ttbar_noff,2));

  Float_t num_data_noff2=GHTBCs(hist_eta_emu_data_noff2), error_num_data_noff2=statistic_error(hist_eta_emu_data_noff2);
  Float_t num_VV_noff2=GHTBCs(hist_eta_emu_diboson_noff2), error_num_VV_noff2=statistic_error(hist_eta_emu_diboson_noff2);
  Float_t num_ttV_noff2=GHTBCs(hist_eta_emu_ttV_noff2), error_num_ttV_noff2=statistic_error(hist_eta_emu_ttV_noff2);
  Float_t num_tV_noff2=GHTBCs(hist_eta_emu_tV_noff2), error_num_tV_noff2=statistic_error(hist_eta_emu_tV_noff2);
  Float_t num_ttH_noff2=GHTBCs(hist_eta_emu_ttH_noff2), error_num_ttH_noff2=statistic_error(hist_eta_emu_ttH_noff2);
  Float_t num_Vgam_noff2=GHTBCs(hist_eta_emu_Vgam_noff2), error_num_Vgam_noff2=statistic_error(hist_eta_emu_Vgam_noff2);
  Float_t num_ttbar_noff2=GHTBCs(hist_eta_emu_ttbar_noff2), error_num_ttbar_noff2=statistic_error(hist_eta_emu_ttbar_noff2);
  Float_t num_Zjets_noff2=GHTBCs(hist_eta_emu_Zjets_noff2), error_num_Zjets_noff2=statistic_error(hist_eta_emu_Zjets_noff2);
  Float_t num_Wjets_noff2=GHTBCs(hist_eta_emu_Wjets_noff2), error_num_Wjets_noff2=statistic_error(hist_eta_emu_Wjets_noff2);
  Float_t num_DY_noff2=GHTBCs(hist_eta_emu_DY_noff2), error_num_DY_noff2=statistic_error(hist_eta_emu_DY_noff2);
  Float_t num_WW_noff2=GHTBCs(hist_eta_emu_WW_noff2), error_num_WW_noff2=statistic_error(hist_eta_emu_WW_noff2);
  Float_t num_signal_noff2=GHTBCs(hist_eta_emu_signal_noff2), error_num_signal_noff2=statistic_error(hist_eta_emu_signal_noff2);

  Float_t num_promptSS_noff2=num_VV_noff2+num_ttV_noff2+num_tV_noff2+num_ttH_noff2, error_num_promptSS_noff2=sqrt(pow(error_num_VV_noff2,2)+pow(error_num_ttV_noff2,2)+pow(error_num_tV_noff2,2)+pow(error_num_ttH_noff2,2));
  Float_t num_Zgam_noff2=num_Zjets_noff2+num_DY_noff2, error_num_Zgam_noff2=sqrt(pow(error_num_Zjets_noff2,2)+pow(error_num_DY_noff2,2));
  Float_t num_totalbkg_noff2=num_promptSS_noff2+num_Zgam_noff2+num_Vgam_noff2+num_Wjets_noff2+num_ttbar_noff2, error_num_totalbkg_noff2=sqrt(pow(num_promptSS_noff2,2)+pow(num_Zgam_noff2,2)+pow(num_Vgam_noff2,2)+pow(num_Wjets_noff2,2)+pow(num_ttbar_noff2,2));
  cout<<setiosflags(ios::fixed)<<setprecision(2);
  cout<<"$e\\mu$ "<<"&"<<num_promptSS<<"$\\pm$"<<error_num_promptSS<<setw(5)<<"&"<<num_Vgam<<"$\\pm$"<<error_num_Vgam<<setw(5)<<"&"<<num_Zgam<<"$\\pm$"<<error_num_Zgam<<setw(5)<<"&"<<num_WW<<"$\\pm$"<<error_num_WW<<setw(5)<<"&"<<num_ttbar<<"$\\pm$"<<error_num_ttbar<<setw(5)<<"&"<<num_Wjets<<"$\\pm$"<<error_num_Wjets<<setw(5)<<"&"<<num_totalbkg<<"$\\pm$"<<error_num_totalbkg<<setw(5)<<"&"<<num_data<<setw(5)<<"&"<<num_signal<<"$\\pm$"<<error_num_signal<<endl;
  cout<<"$\\cancel{e}\\mu$ "<<"&"<<num_promptSS_noff<<"$\\pm$"<<error_num_promptSS_noff<<setw(5)<<"&"<<num_Vgam_noff<<"$\\pm$"<<error_num_Vgam_noff<<setw(5)<<"&"<<num_Zgam_noff<<"$\\pm$"<<error_num_Zgam_noff<<setw(5)<<"&"<<num_WW_noff<<"$\\pm$"<<error_num_WW_noff<<setw(5)<<"&"<<num_ttbar_noff<<"$\\pm$"<<error_num_ttbar_noff<<setw(5)<<"&"<<num_Wjets_noff<<"$\\pm$"<<error_num_Wjets_noff<<setw(5)<<"&"<<num_totalbkg_noff<<"$\\pm$"<<error_num_totalbkg_noff<<setw(5)<<"&"<<num_data_noff<<setw(5)<<"&"<<num_signal_noff<<"$\\pm$"<<error_num_signal_noff<<endl;
  cout<<"$e\\cancel{\\mu}$ "<<"&"<<num_promptSS_noff2<<"$\\pm$"<<error_num_promptSS_noff2<<setw(5)<<"&"<<num_Vgam_noff2<<"$\\pm$"<<error_num_Vgam_noff2<<setw(5)<<"&"<<num_Zgam_noff2<<"$\\pm$"<<error_num_Zgam_noff2<<setw(5)<<"&"<<num_WW_noff2<<"$\\pm$"<<error_num_WW_noff2<<setw(5)<<"&"<<num_ttbar_noff2<<"$\\pm$"<<error_num_ttbar_noff2<<setw(5)<<"&"<<num_Wjets_noff2<<"$\\pm$"<<error_num_Wjets_noff2<<setw(5)<<"&"<<num_totalbkg_noff2<<"$\\pm$"<<error_num_totalbkg_noff2<<setw(5)<<"&"<<num_data_noff2<<setw(5)<<"&"<<num_signal_noff2<<"$\\pm$"<<error_num_signal_noff2<<endl;
  }
}
