#include "../inc/SampleHandler.h"
#include "GHTBCs.cxx"
#include "TH1.h"
#include "TH1F.h"
#include "lumi.cxx"
void FFcalculator_muon(){
  
  TFile *tmp_data=new TFile("temp/std_loosemu/hists_FFcal_1jets_datacombined.root");
  TFile *tmp_diboson=new TFile("temp/std_loosemu/hists_FFcal_1jets_diboson.root");
  TFile *tmp_ttV=new TFile("temp/std_loosemu/hists_FFcal_1jets_ttV.root");
  TFile *tmp_tV=new TFile("temp/std_loosemu/hists_FFcal_1jets_tV.root");
  TFile *tmp_ttH=new TFile("temp/std_loosemu/hists_FFcal_1jets_ttH.root");
  TFile *tmp_Vgam=new TFile("temp/std_loosemu/hists_FFcal_1jets_Vgam.root");

  //first let's calculate fake factor of muons, which is much simpler!
   //get two id hists
  TString vars[3]={"eta","pt","eta_pt"};
  for(Int_t i=0;i<1;i++){
      TString var=vars[i];
      TString whichtouse1="hist_";whichtouse1 +=var;whichtouse1 +="_submuon_mumu";
  TH1* hist_eta_submuon_mumu_data=(TH1*)tmp_data->Get(whichtouse1);
  TH1* hist_eta_submuon_mumu_diboson=(TH1*)tmp_diboson->Get(whichtouse1);
  TH1* hist_eta_submuon_mumu_ttV=(TH1*)tmp_ttV->Get(whichtouse1);
  TH1* hist_eta_submuon_mumu_tV=(TH1*)tmp_tV->Get(whichtouse1);
  TH1* hist_eta_submuon_mumu_ttH=(TH1*)tmp_ttH->Get(whichtouse1);
  TH1* hist_eta_submuon_mumu_Vgam=(TH1*)tmp_Vgam->Get(whichtouse1);
   //get one id + one antiid
      TString whichtouse2="hist_";whichtouse2 +=var;whichtouse2 +="_antiidmuon_muantiidmu";
  TH1* hist_eta_antiidmuon_muantiidmu_data=(TH1*)tmp_data->Get(whichtouse2);
  TH1* hist_eta_antiidmuon_muantiidmu_diboson=(TH1*)tmp_diboson->Get(whichtouse2);
  TH1* hist_eta_antiidmuon_muantiidmu_ttV=(TH1*)tmp_ttV->Get(whichtouse2);
  TH1* hist_eta_antiidmuon_muantiidmu_tV=(TH1*)tmp_tV->Get(whichtouse2);
  TH1* hist_eta_antiidmuon_muantiidmu_ttH=(TH1*)tmp_ttH->Get(whichtouse2);
  TH1* hist_eta_antiidmuon_muantiidmu_Vgam=(TH1*)tmp_Vgam->Get(whichtouse2);
  
  hist_eta_submuon_mumu_diboson->Scale(lumi());
  hist_eta_submuon_mumu_ttV->Scale(lumi());
  hist_eta_submuon_mumu_tV->Scale(lumi());
  hist_eta_submuon_mumu_ttH->Scale(lumi());
  hist_eta_submuon_mumu_Vgam->Scale(lumi());//---
  hist_eta_antiidmuon_muantiidmu_diboson->Scale(lumi());
  hist_eta_antiidmuon_muantiidmu_ttV->Scale(lumi());
  hist_eta_antiidmuon_muantiidmu_tV->Scale(lumi());
  hist_eta_antiidmuon_muantiidmu_ttH->Scale(lumi());
  hist_eta_antiidmuon_muantiidmu_Vgam->Scale(lumi());
  //print out counts for different samples
  cout<<"		Muon	"<<endl;
                    cout<<"id + id"<<"		"<<"id + antiid"<<endl;
  cout<<"+data  "<<GHTBCs(hist_eta_submuon_mumu_data)<<"		"<<GHTBCs(hist_eta_antiidmuon_muantiidmu_data)<<endl;
  cout<<"-diboson  "<<GHTBCs(hist_eta_submuon_mumu_diboson)<<"		"<<GHTBCs(hist_eta_antiidmuon_muantiidmu_diboson)<<endl;
  cout<<"-ttV  "<<GHTBCs(hist_eta_submuon_mumu_ttV)<<"		"<<GHTBCs(hist_eta_antiidmuon_muantiidmu_ttV)<<endl;
  cout<<"-tV  "<<GHTBCs(hist_eta_submuon_mumu_tV)<<"		"<<GHTBCs(hist_eta_antiidmuon_muantiidmu_tV)<<endl;
  cout<<"-ttH  "<<GHTBCs(hist_eta_submuon_mumu_ttH)<<"		"<<GHTBCs(hist_eta_antiidmuon_muantiidmu_ttH)<<endl;
  cout<<"-Vgam  "<<GHTBCs(hist_eta_submuon_mumu_Vgam)<<"		"<<GHTBCs(hist_eta_antiidmuon_muantiidmu_Vgam)<<endl;
  cout<<setiosflags(ios::fixed)<<setprecision(2);
  Float_t tt_data=GHTBCs(hist_eta_submuon_mumu_data), error_tt_data=statistic_error(hist_eta_submuon_mumu_data);
  Float_t tt_VV=GHTBCs(hist_eta_submuon_mumu_diboson), error_tt_VV=statistic_error(hist_eta_submuon_mumu_diboson);
  Float_t tt_ttV=GHTBCs(hist_eta_submuon_mumu_ttV), error_tt_ttV=statistic_error(hist_eta_submuon_mumu_ttV);
  Float_t tt_tV=GHTBCs(hist_eta_submuon_mumu_tV), error_tt_tV=statistic_error(hist_eta_submuon_mumu_tV);
  Float_t tt_ttH=GHTBCs(hist_eta_submuon_mumu_ttH), error_tt_ttH=statistic_error(hist_eta_submuon_mumu_ttH);
  Float_t tt_Vgam=GHTBCs(hist_eta_submuon_mumu_Vgam), error_tt_Vgam=statistic_error(hist_eta_submuon_mumu_Vgam);

  Float_t tant_data=GHTBCs(hist_eta_antiidmuon_muantiidmu_data), error_tant_data=statistic_error(hist_eta_antiidmuon_muantiidmu_data);
  Float_t tant_VV=GHTBCs(hist_eta_antiidmuon_muantiidmu_diboson), error_tant_VV=statistic_error(hist_eta_antiidmuon_muantiidmu_diboson);
  Float_t tant_ttV=GHTBCs(hist_eta_antiidmuon_muantiidmu_ttV), error_tant_ttV=statistic_error(hist_eta_antiidmuon_muantiidmu_ttV);
  Float_t tant_tV=GHTBCs(hist_eta_antiidmuon_muantiidmu_tV), error_tant_tV=statistic_error(hist_eta_antiidmuon_muantiidmu_tV);
  Float_t tant_ttH=GHTBCs(hist_eta_antiidmuon_muantiidmu_ttH), error_tant_ttH=statistic_error(hist_eta_antiidmuon_muantiidmu_ttH);
  Float_t tant_Vgam=GHTBCs(hist_eta_antiidmuon_muantiidmu_Vgam), error_tant_Vgam=statistic_error(hist_eta_antiidmuon_muantiidmu_Vgam);
  cout<<"              VV  "<<"  ttV  "<<"  tV  "<<"  ttH  "<<"  Vgam  "<<"  Data "<<endl;
  cout<<"mumu          "<<"&"<<tt_VV<<"$\\pm$"<<error_tt_VV<<setw(5)<<"&"<<tt_ttV<<"$\\pm$"<<error_tt_ttV<<setw(5)<<"&"<<tt_tV<<"$\\pm$"<<
                      error_tt_tV<<setw(5)<<"&"<<tt_ttH<<"$\\pm$"<<error_tt_ttH<<setw(5)<<"&"<<tt_Vgam<<"$\\pm$"<<error_tt_Vgam<<
                      setw(5)<<"&"<<tt_data<<endl;
  cout<<"mu+antiidmu   "<<"&"<<tant_VV<<"$\\pm$"<<error_tant_VV<<setw(5)<<"&"<<tant_ttV<<"$\\pm$"<<error_tant_ttV<<setw(5)<<"&"<<
                      tant_tV<<"$\\pm$"<<error_tant_tV<<setw(5)<<"&"<<tant_ttH<<"$\\pm$"<<error_tant_ttH<<setw(5)<<"&"<<tant_Vgam<<
                      "$\\pm$"<<error_tant_Vgam<<setw(5)<<"&"<<tant_data<<endl;
  hist_eta_submuon_mumu_data->Add(hist_eta_submuon_mumu_diboson,-1);
  hist_eta_submuon_mumu_data->Add(hist_eta_submuon_mumu_ttV,-1);
  hist_eta_submuon_mumu_data->Add(hist_eta_submuon_mumu_tV,-1);
  hist_eta_submuon_mumu_data->Add(hist_eta_submuon_mumu_ttH,-1);
  hist_eta_submuon_mumu_data->Add(hist_eta_submuon_mumu_Vgam,-1);//---
  hist_eta_antiidmuon_muantiidmu_data->Add(hist_eta_antiidmuon_muantiidmu_diboson,-1); 
  hist_eta_antiidmuon_muantiidmu_data->Add(hist_eta_antiidmuon_muantiidmu_ttV,-1); 
  hist_eta_antiidmuon_muantiidmu_data->Add(hist_eta_antiidmuon_muantiidmu_tV,-1); 
  hist_eta_antiidmuon_muantiidmu_data->Add(hist_eta_antiidmuon_muantiidmu_ttH,-1); 
  hist_eta_antiidmuon_muantiidmu_data->Add(hist_eta_antiidmuon_muantiidmu_Vgam,-1); 
  cout<<"=left "<<GHTBCs(hist_eta_submuon_mumu_data)<<"                "<<GHTBCs(hist_eta_antiidmuon_muantiidmu_data)<<endl; 
  cout<<setiosflags(ios::fixed)<<setprecision(4);
  cout<<"	inclusive ff: "<<GHTBCs(hist_eta_submuon_mumu_data)/GHTBCs(hist_eta_antiidmuon_muantiidmu_data)<<"$\\pm$"<<
                     (GHTBCs(hist_eta_submuon_mumu_data)/GHTBCs(hist_eta_antiidmuon_muantiidmu_data))*sqrt(1/GHTBCs(hist_eta_submuon_mumu_data)+1/GHTBCs(hist_eta_antiidmuon_muantiidmu_data))<<endl;;
  hist_eta_antiidmuon_muantiidmu_data->SetLineColor(kBlue); 
  hist_eta_submuon_mumu_data->SetLineColor(kRed);
  //hist_eta_antiidmuon_muantiidmu_data->Draw(); 
  //hist_eta_submuon_mumu_data->Draw("same"); 
  TFile *ff_output=new TFile("output/hist_ff_1jets.root","update");
  TString hist_ff_output="hist_ff_";
  hist_ff_output += vars[i];
  hist_ff_output += "_antiidmuon";
  TH1 *hist_ff_eta_antiidmuon   =(TH1*)hist_eta_submuon_mumu_data->Clone(hist_ff_output);
  hist_ff_eta_antiidmuon->Divide(hist_eta_submuon_mumu_data,hist_eta_antiidmuon_muantiidmu_data,1,1,"");
  //hist_ff_eta_antiidmuon->Write();
  ff_output->Close();
  }
} 
