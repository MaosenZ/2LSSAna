#include "../inc/SampleHandler.h"
#include "TH1.h"
#include "TH1F.h"
#include "GHTBCs.cxx"
#include "lumi.cxx"

void FFcalculator_electron(){
  
  TFile *tmp_data=new TFile("temp/std_loosemu/hists_FFcal_1jets_datacombined.root");
  TFile *tmp_diboson=new TFile("temp/std_loosemu/hists_FFcal_1jets_diboson.root");
  TFile *tmp_ttV=new TFile("temp/std_loosemu/hists_FFcal_1jets_ttV.root");
  TFile *tmp_tV=new TFile("temp/std_loosemu/hists_FFcal_1jets_tV.root");
  TFile *tmp_ttH=new TFile("temp/std_loosemu/hists_FFcal_1jets_ttH.root");
  TFile *tmp_DY=new TFile("temp/std_loosemu/hists_FFcal_1jets_DY.root");
  TFile *tmp_Vgam=new TFile("temp/std_loosemu/hists_FFcal_1jets_Vgam.root");
  TFile *tmp_Zjets=new TFile("temp/std_loosemu/hists_FFcal_1jets_Zjets.root");
  TFile *tmp_ttbar=new TFile("temp/std_loosemu/hists_FFcal_1jets_ttbar.root");
  TFile *tmp_WW=new TFile("temp/std_loosemu/hists_FFcal_1jets_WW.root");
  TFile *tmp_QmisID=new TFile("temp/std_loosemu/hists_FFcal_QmisID_1jets_datacombined.root");
  //let's calculate fake factor of electrons!
   //get two id hists
  TString vars[2]={"eta","pt"};
  for(Int_t i=0;i<1;i++){
      TString var=vars[i];
      TString whichtouse1="hist_";whichtouse1 +=var;whichtouse1 +="_subelectron_ee";
  TH1* hist_eta_subelectron_ee_data=(TH1*)tmp_data->Get(whichtouse1);
  TH1* hist_eta_subelectron_ee_diboson=(TH1*)tmp_diboson->Get(whichtouse1);
  TH1* hist_eta_subelectron_ee_ttV=(TH1*)tmp_ttV->Get(whichtouse1);
  TH1* hist_eta_subelectron_ee_tV=(TH1*)tmp_tV->Get(whichtouse1);
  TH1* hist_eta_subelectron_ee_ttH=(TH1*)tmp_ttH->Get(whichtouse1);
  TH1* hist_eta_subelectron_ee_Vgam=(TH1*)tmp_Vgam->Get(whichtouse1);
  TH1* hist_eta_subelectron_ee_QmisID=(TH1*)tmp_QmisID->Get(whichtouse1);
   //get one id + one antiid
      TString whichtouse2="hist_";whichtouse2 +=var;whichtouse2 +="_antiidelectron_eantiide";
  TH1* hist_eta_antiidelectron_eantiide_data=(TH1*)tmp_data->Get(whichtouse2);
  TH1* hist_eta_antiidelectron_eantiide_diboson=(TH1*)tmp_diboson->Get(whichtouse2);
  TH1* hist_eta_antiidelectron_eantiide_ttV=(TH1*)tmp_ttV->Get(whichtouse2);
  TH1* hist_eta_antiidelectron_eantiide_tV=(TH1*)tmp_tV->Get(whichtouse2);
  TH1* hist_eta_antiidelectron_eantiide_ttH=(TH1*)tmp_ttH->Get(whichtouse2);
  TH1* hist_eta_antiidelectron_eantiide_Vgam=(TH1*)tmp_Vgam->Get(whichtouse2);
  TH1* hist_eta_antiidelectron_eantiide_ttbar=(TH1*)tmp_ttbar->Get(whichtouse2);
  TH1* hist_eta_antiidelectron_eantiide_Zjets=(TH1*)tmp_Zjets->Get(whichtouse2);
  TH1* hist_eta_antiidelectron_eantiide_DY=(TH1*)tmp_DY->Get(whichtouse2);
  TH1* hist_eta_antiidelectron_eantiide_WW=(TH1*)tmp_WW->Get(whichtouse2);
  
  hist_eta_subelectron_ee_diboson->Scale(lumi());
  hist_eta_subelectron_ee_ttV->Scale(lumi());
  hist_eta_subelectron_ee_tV->Scale(lumi());
  hist_eta_subelectron_ee_ttH->Scale(lumi());
  hist_eta_subelectron_ee_Vgam->Scale(lumi());//---
  hist_eta_antiidelectron_eantiide_diboson->Scale(lumi());
  hist_eta_antiidelectron_eantiide_ttV->Scale(lumi());
  hist_eta_antiidelectron_eantiide_tV->Scale(lumi());
  hist_eta_antiidelectron_eantiide_ttH->Scale(lumi());
  hist_eta_antiidelectron_eantiide_Vgam->Scale(lumi());
  hist_eta_antiidelectron_eantiide_ttbar->Scale(lumi());
  hist_eta_antiidelectron_eantiide_Zjets->Scale(lumi());
  hist_eta_antiidelectron_eantiide_DY->Scale(lumi());
  hist_eta_antiidelectron_eantiide_WW->Scale(lumi());
  cout<<hist_eta_antiidelectron_eantiide_data->GetEntries()<<endl;
  cout<<hist_eta_subelectron_ee_data->GetEntries();
  cout<<"hist_eta_antiidelectron_eantiide_data->GetBinContent(2): "<<hist_eta_antiidelectron_eantiide_data->GetBinContent(2)<<endl;
  cout<<"hist_eta_antiidelectron_eantiide_Zjets->GetBinContent(2): "<<hist_eta_antiidelectron_eantiide_Zjets->GetBinContent(2)<<endl;
  cout<<"hist_eta_antiidelectron_eantiide_diboson->GetBinContent(2): "<<hist_eta_antiidelectron_eantiide_diboson->GetBinContent(2)<<endl;
  cout<<"hist_eta_antiidelectron_eantiide_DY->GetBinContent(2): "<<hist_eta_antiidelectron_eantiide_DY->GetBinContent(2)<<endl;
  cout<<"hist_eta_antiidelectron_eantiide_ttV->GetBinContent(2): "<<hist_eta_antiidelectron_eantiide_ttV->GetBinContent(2)<<endl;
  cout<<"hist_eta_antiidelectron_eantiide_ttH->GetBinContent(2): "<<hist_eta_antiidelectron_eantiide_ttH->GetBinContent(2)<<endl;
  cout<<"hist_eta_antiidelectron_eantiide_tV->GetBinContent(2): "<<hist_eta_antiidelectron_eantiide_tV->GetBinContent(2)<<endl;
  cout<<"hist_eta_antiidelectron_eantiide_ttbar->GetBinContent(2): "<<hist_eta_antiidelectron_eantiide_ttbar->GetBinContent(2)<<endl;
  cout<<"hist_eta_antiidelectron_eantiide_Vgam->GetBinContent(2): "<<hist_eta_antiidelectron_eantiide_Vgam->GetBinContent(2)<<endl;
  /*cout<<"ee:"<<endl;
  cout<<"data: "<<hist_eta_subelectron_ee_data->GetBinContent(2)<<endl;
  cout<<"QmisID: "<<hist_eta_subelectron_ee_QmisID->GetBinContent(2)<<endl;
  cout<<"e+antiid e: "<<endl;
  cout<<"data: "<<hist_eta_antiidelectron_eantiide_data->GetBinContent(2)<<endl;  
  cout<<"Zjets: "<<hist_eta_antiidelectron_eantiide_Zjets->GetBinContent(2)<<endl;*/
  //print out counts for different samples
  cout<<"               Electron    "<<endl;
                    cout<<"id + id"<<"          "<<"id + antiid"<<endl;
  cout<<"+data  "<<GHTBCs(hist_eta_subelectron_ee_data)<<"                "<<GHTBCs(hist_eta_antiidelectron_eantiide_data)<<endl;
  cout<<"-diboson  "<<GHTBCs(hist_eta_subelectron_ee_diboson)<<"          "<<GHTBCs(hist_eta_antiidelectron_eantiide_diboson)<<endl;
  cout<<"-ttV  "<<GHTBCs(hist_eta_subelectron_ee_ttV)<<"          "<<GHTBCs(hist_eta_antiidelectron_eantiide_ttV)<<endl;
  cout<<"-tV  "<<GHTBCs(hist_eta_subelectron_ee_tV)<<"            "<<GHTBCs(hist_eta_antiidelectron_eantiide_tV)<<endl;
  cout<<"-ttH  "<<GHTBCs(hist_eta_subelectron_ee_ttH)<<"          "<<GHTBCs(hist_eta_antiidelectron_eantiide_ttH)<<endl;
  cout<<"-Vgam  "<<GHTBCs(hist_eta_subelectron_ee_Vgam)<<"          "<<GHTBCs(hist_eta_antiidelectron_eantiide_Vgam)<<endl;
  cout<<"-QmisID  "<<GHTBCs(hist_eta_subelectron_ee_QmisID)<<"          (ttbar) "<<GHTBCs(hist_eta_antiidelectron_eantiide_ttbar)<<endl;
  cout<<"                                                                 (Zjets) "<<GHTBCs(hist_eta_antiidelectron_eantiide_Zjets)<<endl;
  cout<<"                                                                 (DY) "<<GHTBCs(hist_eta_antiidelectron_eantiide_DY)<<endl;
  cout<<"                                                                 (WW) "<<GHTBCs(hist_eta_antiidelectron_eantiide_WW)<<endl;
  cout<<setiosflags(ios::fixed)<<setprecision(2);
  Float_t tt_data=GHTBCs(hist_eta_subelectron_ee_data), error_tt_data=statistic_error(hist_eta_subelectron_ee_data);
  Float_t tt_VV=GHTBCs(hist_eta_subelectron_ee_diboson), error_tt_VV=statistic_error(hist_eta_subelectron_ee_diboson); 
  Float_t tt_ttV=GHTBCs(hist_eta_subelectron_ee_ttV), error_tt_ttV=statistic_error(hist_eta_subelectron_ee_ttV); 
  Float_t tt_tV=GHTBCs(hist_eta_subelectron_ee_tV), error_tt_tV=statistic_error(hist_eta_subelectron_ee_tV); 
  Float_t tt_ttH=GHTBCs(hist_eta_subelectron_ee_ttH), error_tt_ttH=statistic_error(hist_eta_subelectron_ee_ttH); 
  Float_t tt_Vgam=GHTBCs(hist_eta_subelectron_ee_Vgam), error_tt_Vgam=statistic_error(hist_eta_subelectron_ee_Vgam); 
  Float_t tt_QmisID=GHTBCs(hist_eta_subelectron_ee_QmisID), error_tt_QmisID=statistic_error(hist_eta_subelectron_ee_QmisID); 
  
  Float_t tant_data=GHTBCs(hist_eta_antiidelectron_eantiide_data), error_tant_data=statistic_error(hist_eta_antiidelectron_eantiide_data); 
  Float_t tant_VV=GHTBCs(hist_eta_antiidelectron_eantiide_diboson), error_tant_VV=statistic_error(hist_eta_antiidelectron_eantiide_diboson);
  Float_t tant_ttV=GHTBCs(hist_eta_antiidelectron_eantiide_ttV), error_tant_ttV=statistic_error(hist_eta_antiidelectron_eantiide_ttV);
  Float_t tant_tV=GHTBCs(hist_eta_antiidelectron_eantiide_tV), error_tant_tV=statistic_error(hist_eta_antiidelectron_eantiide_tV);
  Float_t tant_ttH=GHTBCs(hist_eta_antiidelectron_eantiide_ttH), error_tant_ttH=statistic_error(hist_eta_antiidelectron_eantiide_ttH);
  Float_t tant_Vgam=GHTBCs(hist_eta_antiidelectron_eantiide_Vgam), error_tant_Vgam=statistic_error(hist_eta_antiidelectron_eantiide_Vgam);
  Float_t tant_ttbar=GHTBCs(hist_eta_antiidelectron_eantiide_ttbar), error_tant_ttbar=statistic_error(hist_eta_antiidelectron_eantiide_ttbar);
  Float_t tant_Zjets=GHTBCs(hist_eta_antiidelectron_eantiide_Zjets), error_tant_Zjets=statistic_error(hist_eta_antiidelectron_eantiide_Zjets);
  Float_t tant_DY=GHTBCs(hist_eta_antiidelectron_eantiide_DY), error_tant_DY=statistic_error(hist_eta_antiidelectron_eantiide_DY);
  Float_t tant_WW=GHTBCs(hist_eta_antiidelectron_eantiide_WW), error_tant_WW=statistic_error(hist_eta_antiidelectron_eantiide_WW);
  Float_t tant_QmisID=tant_ttbar+tant_Zjets+tant_DY+tant_WW, error_tant_QmisID=sqrt(error_tant_ttbar*error_tant_ttbar+
                      error_tant_Zjets*error_tant_Zjets+error_tant_DY*error_tant_DY+tant_WW*tant_WW);
  cout<<"              VV  "<<"  ttV  "<<"  tV  "<<"  ttH  "<<"  Vgam  "<<"  QmisID   "<<"  Data "<<endl;
  cout<<"ee          "<<"&"<<tt_VV<<"$\\pm$"<<error_tt_VV<<setw(5)<<"&"<<tt_ttV<<"$\\pm$"<<error_tt_ttV<<setw(5)<<"&"<<tt_tV<<"$\\pm$"<<
                      error_tt_tV<<setw(5)<<"&"<<tt_ttH<<"$\\pm$"<<error_tt_ttH<<setw(5)<<"&"<<tt_Vgam<<"$\\pm$"<<error_tt_Vgam<<setw(5)<<
                      "&"<<tt_QmisID<<"$\\pm$"<<error_tt_QmisID<<setw(5)<<"&"<<tt_data<<endl;
  cout<<"e+antiide   "<<"&"<<tant_VV<<"$\\pm$"<<error_tant_VV<<setw(5)<<"&"<<tant_ttV<<"$\\pm$"<<error_tant_ttV<<setw(5)<<"&"<<
                      tant_tV<<"$\\pm$"<<error_tant_tV<<setw(5)<<"&"<<tant_ttH<<"$\\pm$"<<error_tant_ttH<<setw(5)<<"&"<<tant_Vgam<<
                      "$\\pm$"<<error_tant_Vgam<<setw(5)<<"&"<<tant_QmisID<<"$\\pm$"<<error_tant_QmisID<<setw(5)<<"&"<<tant_data<<endl;
  hist_eta_subelectron_ee_data->Add(hist_eta_subelectron_ee_diboson,-1);
  hist_eta_subelectron_ee_data->Add(hist_eta_subelectron_ee_ttV,-1);
  hist_eta_subelectron_ee_data->Add(hist_eta_subelectron_ee_tV,-1);
  hist_eta_subelectron_ee_data->Add(hist_eta_subelectron_ee_ttH,-1);
  hist_eta_subelectron_ee_data->Add(hist_eta_subelectron_ee_Vgam,-1);
  hist_eta_subelectron_ee_data->Add(hist_eta_subelectron_ee_QmisID,-1);//---
  hist_eta_antiidelectron_eantiide_data->Add(hist_eta_antiidelectron_eantiide_diboson,-1); 
  hist_eta_antiidelectron_eantiide_data->Add(hist_eta_antiidelectron_eantiide_ttV,-1); 
  hist_eta_antiidelectron_eantiide_data->Add(hist_eta_antiidelectron_eantiide_tV,-1); 
  hist_eta_antiidelectron_eantiide_data->Add(hist_eta_antiidelectron_eantiide_ttH,-1); 
  hist_eta_antiidelectron_eantiide_data->Add(hist_eta_antiidelectron_eantiide_Vgam,-1); 
  hist_eta_antiidelectron_eantiide_data->Add(hist_eta_antiidelectron_eantiide_ttbar,-1); 
  hist_eta_antiidelectron_eantiide_data->Add(hist_eta_antiidelectron_eantiide_Zjets,-1); 
  hist_eta_antiidelectron_eantiide_data->Add(hist_eta_antiidelectron_eantiide_DY,-1); 
  hist_eta_antiidelectron_eantiide_data->Add(hist_eta_antiidelectron_eantiide_WW,-1); 
  cout<<"=left  "<<GHTBCs(hist_eta_subelectron_ee_data)<<"		"<<GHTBCs(hist_eta_antiidelectron_eantiide_data)<<endl;
  cout<<setiosflags(ios::fixed)<<setprecision(4);
  cout<<"       inclusive ff: "<<GHTBCs(hist_eta_subelectron_ee_data)/GHTBCs(hist_eta_antiidelectron_eantiide_data)<<"$\\pm$"<<
                               (GHTBCs(hist_eta_subelectron_ee_data)/GHTBCs(hist_eta_antiidelectron_eantiide_data))*sqrt(1/GHTBCs(hist_eta_subelectron_ee_data)+1/GHTBCs(hist_eta_antiidelectron_eantiide_data))<<endl;  
  hist_eta_subelectron_ee_data->SetLineColor(kRed);
  hist_eta_antiidelectron_eantiide_data->SetLineColor(kBlue);
  //hist_eta_antiidelectron_eantiide_data->Draw(); 
  //hist_eta_subelectron_ee_data->Draw("same"); 
  TFile *ff_output=new TFile("output/hist_ff_1jets.root","update");  
  TString hist_ff_output="hist_ff_";
  hist_ff_output += vars[i];
  hist_ff_output += "_antiidelectron";
  TH1 *hist_ff_eta_antiidelectron   =(TH1*)hist_eta_subelectron_ee_data->Clone(hist_ff_output);
  hist_ff_eta_antiidelectron->Divide(hist_eta_subelectron_ee_data,hist_eta_antiidelectron_eantiide_data,1,1,"");
  //hist_ff_eta_antiidelectron->Write();
  ff_output->Close();
  }
}
