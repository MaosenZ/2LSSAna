#include "TFile.h"
#include "TH1.h"
#include "TH1F.h"
#include "GHTBCs.cxx"
#include "lumi.cxx"
#include "readFF.cxx"
void FFApp(Int_t category){//1 ee, 2 mumu, 3 emu
  //calculate jet fakes in ee channel
  //low mass
  //Float_t ff_ele=0.5401, ff_mu=0.5033, sys_ele=0.5345, sys_mu=0.4318;
  //high mass
  //Float_t ff_ele=0.5472, ff_mu=0.4544, sys_ele=0.6066, sys_mu=0.5667;
  Float_t ff_ele, ff_mu;
  readFF(ff_ele,ff_mu,"FFApp_3jets");
  std::cout<<ff_ele<<" "<<ff_mu<<std::endl;
  TFile *tmp_data=new TFile("temp/hists_FFApp_3jets_datacombined.root");
  TFile *tmp_diboson=new TFile("temp/hists_FFApp_3jets_diboson.root");
  TFile *tmp_ttV=new TFile("temp/hists_FFApp_3jets_ttV.root");
  TFile *tmp_tV=new TFile("temp/hists_FFApp_3jets_tV.root");
  TFile *tmp_ttH=new TFile("temp/hists_FFApp_3jets_ttH.root");
  TFile *tmp_DY=new TFile("temp/hists_FFApp_3jets_DY.root");
  TFile *tmp_WW=new TFile("temp/hists_FFApp_3jets_WW.root");
  TFile *tmp_Vgam=new TFile("temp/hists_FFApp_3jets_Vgam.root");
  TFile *tmp_FFQmis=new TFile("temp/hists_FFQmis_3jets_datacombined.root");
  TFile *tmp_Zjets=new TFile("temp/hists_FFApp_3jets_Zjets.root");
  TFile *tmp_ttbar=new TFile("temp/hists_FFApp_3jets_ttbar.root");
 
  TFile *output=new TFile("temp/hists_fakes.root","recreate");//to save fakes contributions
  
  TString vars[]={"eta","pt","m_ll","met","m_all","m_jj_w","m_l1jj","mindR_l1j","mindR_l2j"};TString var;
  TString whichtouse_ele,whichtouse_ele_noff;
  TString output_ee;
  for(Int_t i=0;i<=0;i++){
     if(i<2){
        var=vars[i];
        whichtouse_ele="hist_";whichtouse_ele+=var; whichtouse_ele+="_antiidelectron_eantiide";
        whichtouse_ele_noff="hist_";whichtouse_ele_noff+=var; whichtouse_ele_noff+="_antiidelectron_eantiide_noff";
     }
     if(i>=2){
        var=vars[i];
        whichtouse_ele="hist_";whichtouse_ele+=var;whichtouse_ele+="_eantiide";
        output_ee="hist_";output_ee+=var;output_ee+="_ee";
     }
  if(category==0 || category==1){
  TH1* hist_eta_electron_ee_data=(TH1*)tmp_data->Get(whichtouse_ele);
  TH1* hist_eta_electron_ee_diboson=(TH1*)tmp_diboson->Get(whichtouse_ele);
  TH1* hist_eta_electron_ee_ttV=(TH1*)tmp_ttV->Get(whichtouse_ele);
  TH1* hist_eta_electron_ee_tV=(TH1*)tmp_tV->Get(whichtouse_ele);
  TH1* hist_eta_electron_ee_ttH=(TH1*)tmp_ttH->Get(whichtouse_ele);
  TH1* hist_eta_electron_ee_DY=(TH1*)tmp_DY->Get(whichtouse_ele);
  TH1* hist_eta_electron_ee_WW=(TH1*)tmp_WW->Get(whichtouse_ele);
  TH1* hist_eta_electron_ee_Vgam=(TH1*)tmp_Vgam->Get(whichtouse_ele);
  TH1* hist_eta_electron_ee_Zjets=(TH1*)tmp_Zjets->Get(whichtouse_ele);
  TH1* hist_eta_electron_ee_ttbar=(TH1*)tmp_ttbar->Get(whichtouse_ele);

  TH1* hist_eta_electron_ee_data_noff=(TH1*)tmp_data->Get(whichtouse_ele_noff);
  TH1* hist_eta_electron_ee_diboson_noff=(TH1*)tmp_diboson->Get(whichtouse_ele_noff);
  TH1* hist_eta_electron_ee_ttV_noff=(TH1*)tmp_ttV->Get(whichtouse_ele_noff);
  TH1* hist_eta_electron_ee_tV_noff=(TH1*)tmp_tV->Get(whichtouse_ele_noff);
  TH1* hist_eta_electron_ee_ttH_noff=(TH1*)tmp_ttH->Get(whichtouse_ele_noff);
  TH1* hist_eta_electron_ee_DY_noff=(TH1*)tmp_DY->Get(whichtouse_ele_noff);
  TH1* hist_eta_electron_ee_WW_noff=(TH1*)tmp_WW->Get(whichtouse_ele_noff);
  TH1* hist_eta_electron_ee_Vgam_noff=(TH1*)tmp_Vgam->Get(whichtouse_ele_noff);
  TH1* hist_eta_electron_ee_Zjets_noff=(TH1*)tmp_Zjets->Get(whichtouse_ele_noff);
  TH1* hist_eta_electron_ee_ttbar_noff=(TH1*)tmp_ttbar->Get(whichtouse_ele_noff);

  hist_eta_electron_ee_diboson->Scale(lumi());
  hist_eta_electron_ee_ttV->Scale(lumi());
  hist_eta_electron_ee_tV->Scale(lumi());
  hist_eta_electron_ee_ttH->Scale(lumi());
  hist_eta_electron_ee_Vgam->Scale(lumi());
  hist_eta_electron_ee_Zjets->Scale(lumi());
  hist_eta_electron_ee_DY->Scale(lumi());
  hist_eta_electron_ee_WW->Scale(lumi());
  hist_eta_electron_ee_ttbar->Scale(lumi());
 
  hist_eta_electron_ee_diboson_noff->Scale(lumi());
  hist_eta_electron_ee_ttV_noff->Scale(lumi());
  hist_eta_electron_ee_tV_noff->Scale(lumi());
  hist_eta_electron_ee_ttH_noff->Scale(lumi());
  hist_eta_electron_ee_Vgam_noff->Scale(lumi());
  hist_eta_electron_ee_Zjets_noff->Scale(lumi());
  hist_eta_electron_ee_DY_noff->Scale(lumi());
  hist_eta_electron_ee_WW_noff->Scale(lumi());
  hist_eta_electron_ee_ttbar_noff->Scale(lumi());
  //
  Float_t num_data=GHTBCs(hist_eta_electron_ee_data_noff), error_num_data=statistic_error(hist_eta_electron_ee_data_noff);
  Float_t num_VV=GHTBCs(hist_eta_electron_ee_diboson_noff), error_num_VV=statistic_error(hist_eta_electron_ee_diboson_noff);
  Float_t num_ttV=GHTBCs(hist_eta_electron_ee_ttV_noff), error_num_ttV=statistic_error(hist_eta_electron_ee_ttV_noff);
  Float_t num_tV=GHTBCs(hist_eta_electron_ee_tV_noff), error_num_tV=statistic_error(hist_eta_electron_ee_tV_noff);
  Float_t num_ttH=GHTBCs(hist_eta_electron_ee_ttH_noff), error_num_ttH=statistic_error(hist_eta_electron_ee_ttH_noff);
  Float_t num_Vgam=GHTBCs(hist_eta_electron_ee_Vgam_noff), error_num_Vgam=statistic_error(hist_eta_electron_ee_Vgam_noff);
  Float_t num_ttbar=GHTBCs(hist_eta_electron_ee_ttbar_noff), error_num_ttbar=statistic_error(hist_eta_electron_ee_ttbar_noff);
  Float_t num_Zjets=GHTBCs(hist_eta_electron_ee_Zjets_noff), error_num_Zjets=statistic_error(hist_eta_electron_ee_Zjets_noff);
  Float_t num_DY=GHTBCs(hist_eta_electron_ee_DY_noff), error_num_DY=statistic_error(hist_eta_electron_ee_DY_noff);
  Float_t num_WW=GHTBCs(hist_eta_electron_ee_WW_noff), error_num_WW=statistic_error(hist_eta_electron_ee_WW_noff);
  Float_t num_QmisID=num_ttbar+num_Zjets+num_DY+num_WW, error_num_QmisID=sqrt(error_num_ttbar*error_num_ttbar+
                      error_num_Zjets*error_num_Zjets+error_num_DY*error_num_DY+error_num_WW*error_num_WW);
  cout<<setiosflags(ios::fixed)<<setprecision(2);
  cout<<"e+antiide   "<<"&"<<num_VV<<"$\\pm$"<<error_num_VV<<setw(5)<<"&"<<num_ttV<<"$\\pm$"<<error_num_ttV<<setw(5)<<"&"<<
                      num_tV<<"$\\pm$"<<error_num_tV<<setw(5)<<"&"<<num_ttH<<"$\\pm$"<<error_num_ttH<<setw(5)<<"&"<<num_Vgam<<
                      "$\\pm$"<<error_num_Vgam<<setw(5)<<"&"<<num_QmisID<<"$\\pm$"<<error_num_QmisID<<setw(5)<<"&"<<num_data<<
                      "$\\pm$"<<error_num_data<<endl;
  hist_eta_electron_ee_data->Add(hist_eta_electron_ee_diboson,-1);
  hist_eta_electron_ee_data->Add(hist_eta_electron_ee_ttV,-1);
  hist_eta_electron_ee_data->Add(hist_eta_electron_ee_tV,-1);
  hist_eta_electron_ee_data->Add(hist_eta_electron_ee_ttH,-1);
  hist_eta_electron_ee_data->Add(hist_eta_electron_ee_Vgam,-1);
  hist_eta_electron_ee_data->Add(hist_eta_electron_ee_Zjets,-1);
  hist_eta_electron_ee_data->Add(hist_eta_electron_ee_DY,-1);
  hist_eta_electron_ee_data->Add(hist_eta_electron_ee_WW,-1);
  hist_eta_electron_ee_data->Add(hist_eta_electron_ee_ttbar,-1);

  hist_eta_electron_ee_data_noff->Add(hist_eta_electron_ee_diboson_noff,-1);
  hist_eta_electron_ee_data_noff->Add(hist_eta_electron_ee_ttV_noff,-1);
  hist_eta_electron_ee_data_noff->Add(hist_eta_electron_ee_tV_noff,-1);
  hist_eta_electron_ee_data_noff->Add(hist_eta_electron_ee_ttH_noff,-1);
  hist_eta_electron_ee_data_noff->Add(hist_eta_electron_ee_Vgam_noff,-1);
  hist_eta_electron_ee_data_noff->Add(hist_eta_electron_ee_Zjets_noff,-1);
  hist_eta_electron_ee_data_noff->Add(hist_eta_electron_ee_DY_noff,-1);
  hist_eta_electron_ee_data_noff->Add(hist_eta_electron_ee_WW_noff,-1);
  hist_eta_electron_ee_data_noff->Add(hist_eta_electron_ee_ttbar_noff,-1);
  if(i<2){
     cout<<"ee jet fakes: "<<GHTBCs(hist_eta_electron_ee_data)<<"$\\pm$"<<ff_ele*sqrt(GHTBCs(hist_eta_electron_ee_data_noff))<<endl;
     cout<<"ee no ff: "<<GHTBCs(hist_eta_electron_ee_data_noff)<<"+-"<<statistic_error(hist_eta_electron_ee_data_noff)<<endl;
     cout<<"overall scale factor: "<<GHTBCs(hist_eta_electron_ee_data)/GHTBCs(hist_eta_electron_ee_data_noff)<<endl;
  }
  if(i>1){
     TH1* hist=(TH1*)hist_eta_electron_ee_data->Clone(output_ee);
     hist->Write();
  }
  }//end ee
  TString whichtouse_mu,whichtouse_mu_noff;
   TString output_mumu;
  if(i<2){
        var=vars[i];
        whichtouse_mu="hist_";whichtouse_mu+=var; whichtouse_mu+="_antiidmuon_muantiidmu";
        whichtouse_mu_noff="hist_";whichtouse_mu_noff+=var; whichtouse_mu_noff+="_antiidmuon_muantiidmu_noff";
     }
     if(i>=2){
        var=vars[i];
        whichtouse_mu="hist_";whichtouse_mu+=var;whichtouse_mu+="_muantiidmu";
        output_mumu="hist_";output_mumu+=var;output_mumu+="_mumu";
     }
  if(category==0 || category==2){
       TH1* hist_eta_muon_mumu_data=(TH1*)tmp_data->Get(whichtouse_mu);
  TH1* hist_eta_muon_mumu_diboson=(TH1*)tmp_diboson->Get(whichtouse_mu);
  TH1* hist_eta_muon_mumu_ttV=(TH1*)tmp_ttV->Get(whichtouse_mu);
  TH1* hist_eta_muon_mumu_tV=(TH1*)tmp_tV->Get(whichtouse_mu);
  TH1* hist_eta_muon_mumu_ttH=(TH1*)tmp_ttH->Get(whichtouse_mu);
  TH1* hist_eta_muon_mumu_Vgam=(TH1*)tmp_Vgam->Get(whichtouse_mu);
  TH1* hist_eta_muon_mumu_data_noff=(TH1*)tmp_data->Get(whichtouse_mu_noff);
  TH1* hist_eta_muon_mumu_diboson_noff=(TH1*)tmp_diboson->Get(whichtouse_mu_noff);
  TH1* hist_eta_muon_mumu_ttV_noff=(TH1*)tmp_ttV->Get(whichtouse_mu_noff);
  TH1* hist_eta_muon_mumu_tV_noff=(TH1*)tmp_tV->Get(whichtouse_mu_noff);
  TH1* hist_eta_muon_mumu_ttH_noff=(TH1*)tmp_ttH->Get(whichtouse_mu_noff);
  TH1* hist_eta_muon_mumu_Vgam_noff=(TH1*)tmp_Vgam->Get(whichtouse_mu_noff);

  hist_eta_muon_mumu_diboson->Scale(lumi());
  hist_eta_muon_mumu_ttV->Scale(lumi());
  hist_eta_muon_mumu_tV->Scale(lumi());
  hist_eta_muon_mumu_ttH->Scale(lumi());
  hist_eta_muon_mumu_Vgam->Scale(lumi());
  hist_eta_muon_mumu_diboson_noff->Scale(lumi());
  hist_eta_muon_mumu_ttV_noff->Scale(lumi());
  hist_eta_muon_mumu_tV_noff->Scale(lumi());
  hist_eta_muon_mumu_ttH_noff->Scale(lumi());
  hist_eta_muon_mumu_Vgam_noff->Scale(lumi());
  //
  Float_t num_data=GHTBCs(hist_eta_muon_mumu_data_noff), error_num_data=statistic_error(hist_eta_muon_mumu_data_noff);
  Float_t num_VV=GHTBCs(hist_eta_muon_mumu_diboson_noff), error_num_VV=statistic_error(hist_eta_muon_mumu_diboson_noff);
  Float_t num_ttV=GHTBCs(hist_eta_muon_mumu_ttV_noff), error_num_ttV=statistic_error(hist_eta_muon_mumu_ttV_noff);
  Float_t num_tV=GHTBCs(hist_eta_muon_mumu_tV_noff), error_num_tV=statistic_error(hist_eta_muon_mumu_tV_noff);
  Float_t num_ttH=GHTBCs(hist_eta_muon_mumu_ttH_noff), error_num_ttH=statistic_error(hist_eta_muon_mumu_ttH_noff);
  Float_t num_Vgam=GHTBCs(hist_eta_muon_mumu_Vgam_noff), error_num_Vgam=statistic_error(hist_eta_muon_mumu_Vgam_noff);
  cout<<"mu+antiidmu   "<<"&"<<num_VV<<"$\\pm$"<<error_num_VV<<setw(5)<<"&"<<num_ttV<<"$\\pm$"<<error_num_ttV<<setw(5)<<"&"<<
                      num_tV<<"$\\pm$"<<error_num_tV<<setw(5)<<"&"<<num_ttH<<"$\\pm$"<<error_num_ttH<<setw(5)<<"&"<<num_Vgam<<
                      "$\\pm$"<<error_num_Vgam<<setw(5)<<"&"<<"-"<<setw(5)<<"&"<<num_data<<"$\\pm$"<<error_num_data<<endl;
 
  hist_eta_muon_mumu_data->Add(hist_eta_muon_mumu_diboson,-1);
  hist_eta_muon_mumu_data->Add(hist_eta_muon_mumu_ttV,-1);
  hist_eta_muon_mumu_data->Add(hist_eta_muon_mumu_tV,-1);
  hist_eta_muon_mumu_data->Add(hist_eta_muon_mumu_ttH,-1);
  hist_eta_muon_mumu_data->Add(hist_eta_muon_mumu_Vgam,-1);
  hist_eta_muon_mumu_data_noff->Add(hist_eta_muon_mumu_diboson_noff,-1);
  hist_eta_muon_mumu_data_noff->Add(hist_eta_muon_mumu_ttV_noff,-1);
  hist_eta_muon_mumu_data_noff->Add(hist_eta_muon_mumu_tV_noff,-1);
  hist_eta_muon_mumu_data_noff->Add(hist_eta_muon_mumu_ttH_noff,-1);
  hist_eta_muon_mumu_data_noff->Add(hist_eta_muon_mumu_Vgam_noff,-1);
  if(i<2){
     cout<<"mumu jet fakes: "<<GHTBCs(hist_eta_muon_mumu_data)<<"$\\pm$"<<ff_mu*sqrt(GHTBCs(hist_eta_muon_mumu_data_noff))<<endl;
     cout<<"mumu jet fakes no ff: "<<GHTBCs(hist_eta_muon_mumu_data_noff)<<"+-"<<statistic_error(hist_eta_muon_mumu_data_noff)<<endl;
     cout<<"overall scale factor: "<<GHTBCs(hist_eta_muon_mumu_data)/GHTBCs(hist_eta_muon_mumu_data_noff)<<endl;   
  }
  if(i>1){
    TH1* hist=(TH1*)hist_eta_muon_mumu_data->Clone(output_mumu);
    hist->Write();
  }
  }
  TString whichtouse_emu1,whichtouse_emu1_noff;
  TString whichtouse_emu2,whichtouse_emu2_noff;
  TString output_emu;
  if(i<2){
      whichtouse_emu1="hist_";whichtouse_emu1+=var; whichtouse_emu1+="_antiidelectron_antiidemu";
      whichtouse_emu1_noff="hist_";whichtouse_emu1_noff+=var; whichtouse_emu1_noff+="_antiidelectron_antiidemu_noff";
      whichtouse_emu2="hist_";whichtouse_emu2+=var; whichtouse_emu2+="_antiidmuon_eantiidmu";
      whichtouse_emu2_noff="hist_";whichtouse_emu2_noff+=var; whichtouse_emu2_noff+="_antiidmuon_eantiidmu_noff";
  }
  if(i>1){
     whichtouse_emu1="hist_";whichtouse_emu1+=var;whichtouse_emu1+="_antiidemu";
     whichtouse_emu2="hist_";whichtouse_emu2+=var;whichtouse_emu2+="_eantiidmu";
     output_emu="hist_";output_emu+=var;output_emu+="_emu";
  }
  if(category==0 || category==3){
  //antiidemu
       TH1* hist_eta_antiidelectron_antiidemu_data=(TH1*)tmp_data->Get(whichtouse_emu1);
  TH1* hist_eta_antiidelectron_antiidemu_diboson=(TH1*)tmp_diboson->Get(whichtouse_emu1);
  TH1* hist_eta_antiidelectron_antiidemu_ttV=(TH1*)tmp_ttV->Get(whichtouse_emu1);
  TH1* hist_eta_antiidelectron_antiidemu_tV=(TH1*)tmp_tV->Get(whichtouse_emu1);
  TH1* hist_eta_antiidelectron_antiidemu_ttH=(TH1*)tmp_ttH->Get(whichtouse_emu1);
  TH1* hist_eta_antiidelectron_antiidemu_Vgam=(TH1*)tmp_Vgam->Get(whichtouse_emu1);
  TH1* hist_eta_antiidelectron_antiidemu_Zjets=(TH1*)tmp_Zjets->Get(whichtouse_emu1);
  TH1* hist_eta_antiidelectron_antiidemu_DY=(TH1*)tmp_DY->Get(whichtouse_emu1);
  TH1* hist_eta_antiidelectron_antiidemu_WW=(TH1*)tmp_WW->Get(whichtouse_emu1);
  TH1* hist_eta_antiidelectron_antiidemu_ttbar=(TH1*)tmp_ttbar->Get(whichtouse_emu1);
  TH1* hist_eta_antiidelectron_antiidemu_data_noff=(TH1*)tmp_data->Get(whichtouse_emu1_noff);
  TH1* hist_eta_antiidelectron_antiidemu_diboson_noff=(TH1*)tmp_diboson->Get(whichtouse_emu1_noff);
  TH1* hist_eta_antiidelectron_antiidemu_ttV_noff=(TH1*)tmp_ttV->Get(whichtouse_emu1_noff);
  TH1* hist_eta_antiidelectron_antiidemu_tV_noff=(TH1*)tmp_tV->Get(whichtouse_emu1_noff);
  TH1* hist_eta_antiidelectron_antiidemu_ttH_noff=(TH1*)tmp_ttH->Get(whichtouse_emu1_noff);
  TH1* hist_eta_antiidelectron_antiidemu_Vgam_noff=(TH1*)tmp_Vgam->Get(whichtouse_emu1_noff);
  TH1* hist_eta_antiidelectron_antiidemu_Zjets_noff=(TH1*)tmp_Zjets->Get(whichtouse_emu1_noff);
  TH1* hist_eta_antiidelectron_antiidemu_DY_noff=(TH1*)tmp_DY->Get(whichtouse_emu1_noff);
  TH1* hist_eta_antiidelectron_antiidemu_WW_noff=(TH1*)tmp_WW->Get(whichtouse_emu1_noff);
  TH1* hist_eta_antiidelectron_antiidemu_ttbar_noff=(TH1*)tmp_ttbar->Get(whichtouse_emu1_noff);

  hist_eta_antiidelectron_antiidemu_diboson->Scale(lumi());
  hist_eta_antiidelectron_antiidemu_ttV->Scale(lumi());
  hist_eta_antiidelectron_antiidemu_tV->Scale(lumi());
  hist_eta_antiidelectron_antiidemu_ttH->Scale(lumi());
  hist_eta_antiidelectron_antiidemu_Vgam->Scale(lumi());
  hist_eta_antiidelectron_antiidemu_Zjets->Scale(lumi());
  hist_eta_antiidelectron_antiidemu_DY->Scale(lumi());
  hist_eta_antiidelectron_antiidemu_WW->Scale(lumi());
  hist_eta_antiidelectron_antiidemu_ttbar->Scale(lumi());
  hist_eta_antiidelectron_antiidemu_diboson_noff->Scale(lumi());
  hist_eta_antiidelectron_antiidemu_ttV_noff->Scale(lumi());
  hist_eta_antiidelectron_antiidemu_tV_noff->Scale(lumi());
  hist_eta_antiidelectron_antiidemu_ttH_noff->Scale(lumi());
  hist_eta_antiidelectron_antiidemu_Vgam_noff->Scale(lumi());
  hist_eta_antiidelectron_antiidemu_Zjets_noff->Scale(lumi());
  hist_eta_antiidelectron_antiidemu_DY_noff->Scale(lumi());
  hist_eta_antiidelectron_antiidemu_WW_noff->Scale(lumi());
  hist_eta_antiidelectron_antiidemu_ttbar_noff->Scale(lumi());
  //
  Float_t antiemu_data=GHTBCs(hist_eta_antiidelectron_antiidemu_data_noff), error_antiemu_data=statistic_error(hist_eta_antiidelectron_antiidemu_data_noff);
  Float_t antiemu_VV=GHTBCs(hist_eta_antiidelectron_antiidemu_diboson_noff), error_antiemu_VV=statistic_error(hist_eta_antiidelectron_antiidemu_diboson_noff);
  Float_t antiemu_ttV=GHTBCs(hist_eta_antiidelectron_antiidemu_ttV_noff), error_antiemu_ttV=statistic_error(hist_eta_antiidelectron_antiidemu_ttV_noff);
  Float_t antiemu_tV=GHTBCs(hist_eta_antiidelectron_antiidemu_tV_noff), error_antiemu_tV=statistic_error(hist_eta_antiidelectron_antiidemu_tV_noff);
  Float_t antiemu_ttH=GHTBCs(hist_eta_antiidelectron_antiidemu_ttH_noff), error_antiemu_ttH=statistic_error(hist_eta_antiidelectron_antiidemu_ttH_noff);
  Float_t antiemu_Vgam=GHTBCs(hist_eta_antiidelectron_antiidemu_Vgam_noff), error_antiemu_Vgam=statistic_error(hist_eta_antiidelectron_antiidemu_Vgam_noff);
  Float_t antiemu_ttbar=GHTBCs(hist_eta_antiidelectron_antiidemu_ttbar_noff), error_antiemu_ttbar=statistic_error(hist_eta_antiidelectron_antiidemu_ttbar_noff);
  Float_t antiemu_Zjets=GHTBCs(hist_eta_antiidelectron_antiidemu_Zjets_noff), error_antiemu_Zjets=statistic_error(hist_eta_antiidelectron_antiidemu_Zjets_noff);
  Float_t antiemu_DY=GHTBCs(hist_eta_antiidelectron_antiidemu_DY_noff), error_antiemu_DY=statistic_error(hist_eta_antiidelectron_antiidemu_DY_noff);
  Float_t antiemu_WW=GHTBCs(hist_eta_antiidelectron_antiidemu_WW_noff), error_antiemu_WW=statistic_error(hist_eta_antiidelectron_antiidemu_WW_noff);
  Float_t antiemu_QmisID=antiemu_ttbar+antiemu_Zjets+antiemu_DY+antiemu_WW, error_antiemu_QmisID=sqrt(error_antiemu_ttbar*error_antiemu_ttbar+
                      error_antiemu_Zjets*error_antiemu_Zjets+error_antiemu_DY*error_antiemu_DY+error_antiemu_WW*error_antiemu_WW);
  cout<<"antiide+mu   "<<"&"<<antiemu_VV<<"$\\pm$"<<error_antiemu_VV<<setw(5)<<"&"<<antiemu_ttV<<"$\\pm$"<<error_antiemu_ttV<<setw(5)<<"&"<<
                      antiemu_tV<<"$\\pm$"<<error_antiemu_tV<<setw(5)<<"&"<<antiemu_ttH<<"$\\pm$"<<error_antiemu_ttH<<setw(5)<<"&"<<
                      antiemu_Vgam<<"$\\pm$"<<error_antiemu_Vgam<<setw(5)<<"&"<<antiemu_QmisID<<"$\\pm$"<<error_antiemu_QmisID<<setw(5)<<
                      "&"<<antiemu_data<<"$\\pm$"<<error_antiemu_data<<endl;
  hist_eta_antiidelectron_antiidemu_data->Add(hist_eta_antiidelectron_antiidemu_diboson,-1);
  hist_eta_antiidelectron_antiidemu_data->Add(hist_eta_antiidelectron_antiidemu_ttV,-1);
  hist_eta_antiidelectron_antiidemu_data->Add(hist_eta_antiidelectron_antiidemu_tV,-1);
  hist_eta_antiidelectron_antiidemu_data->Add(hist_eta_antiidelectron_antiidemu_ttH,-1);
  hist_eta_antiidelectron_antiidemu_data->Add(hist_eta_antiidelectron_antiidemu_Vgam,-1);
  hist_eta_antiidelectron_antiidemu_data->Add(hist_eta_antiidelectron_antiidemu_Zjets,-1);
  hist_eta_antiidelectron_antiidemu_data->Add(hist_eta_antiidelectron_antiidemu_DY,-1);
  hist_eta_antiidelectron_antiidemu_data->Add(hist_eta_antiidelectron_antiidemu_WW,-1);
  hist_eta_antiidelectron_antiidemu_data->Add(hist_eta_antiidelectron_antiidemu_ttbar,-1);
  hist_eta_antiidelectron_antiidemu_data_noff->Add(hist_eta_antiidelectron_antiidemu_diboson_noff,-1);
  hist_eta_antiidelectron_antiidemu_data_noff->Add(hist_eta_antiidelectron_antiidemu_ttV_noff,-1);
  hist_eta_antiidelectron_antiidemu_data_noff->Add(hist_eta_antiidelectron_antiidemu_tV_noff,-1);
  hist_eta_antiidelectron_antiidemu_data_noff->Add(hist_eta_antiidelectron_antiidemu_ttH_noff,-1);
  hist_eta_antiidelectron_antiidemu_data_noff->Add(hist_eta_antiidelectron_antiidemu_Vgam_noff,-1);
  hist_eta_antiidelectron_antiidemu_data_noff->Add(hist_eta_antiidelectron_antiidemu_Zjets_noff,-1);
  hist_eta_antiidelectron_antiidemu_data_noff->Add(hist_eta_antiidelectron_antiidemu_DY_noff,-1);
  hist_eta_antiidelectron_antiidemu_data_noff->Add(hist_eta_antiidelectron_antiidemu_WW_noff,-1);
  hist_eta_antiidelectron_antiidemu_data_noff->Add(hist_eta_antiidelectron_antiidemu_ttbar_noff,-1);
  //for write
  TH1* hist=(TH1*)hist_eta_antiidelectron_antiidemu_data->Clone(output_emu);
  //eantiidmu
       TH1* hist_eta_antiidmuon_eantiidmu_data=(TH1*)tmp_data->Get(whichtouse_emu2);
  TH1* hist_eta_antiidmuon_eantiidmu_diboson=(TH1*)tmp_diboson->Get(whichtouse_emu2);
  TH1* hist_eta_antiidmuon_eantiidmu_ttV=(TH1*)tmp_ttV->Get(whichtouse_emu2);
  TH1* hist_eta_antiidmuon_eantiidmu_tV=(TH1*)tmp_tV->Get(whichtouse_emu2);
  TH1* hist_eta_antiidmuon_eantiidmu_ttH=(TH1*)tmp_ttH->Get(whichtouse_emu2);
  TH1* hist_eta_antiidmuon_eantiidmu_Vgam=(TH1*)tmp_Vgam->Get(whichtouse_emu2);
  TH1* hist_eta_antiidmuon_eantiidmu_FFQmis=(TH1*)tmp_FFQmis->Get(whichtouse_emu2);
  TH1* hist_eta_antiidmuon_eantiidmu_data_noff=(TH1*)tmp_data->Get(whichtouse_emu2_noff);
  TH1* hist_eta_antiidmuon_eantiidmu_diboson_noff=(TH1*)tmp_diboson->Get(whichtouse_emu2_noff);
  TH1* hist_eta_antiidmuon_eantiidmu_ttV_noff=(TH1*)tmp_ttV->Get(whichtouse_emu2_noff);
  TH1* hist_eta_antiidmuon_eantiidmu_tV_noff=(TH1*)tmp_tV->Get(whichtouse_emu2_noff);
  TH1* hist_eta_antiidmuon_eantiidmu_ttH_noff=(TH1*)tmp_ttH->Get(whichtouse_emu2_noff);
  TH1* hist_eta_antiidmuon_eantiidmu_Vgam_noff=(TH1*)tmp_Vgam->Get(whichtouse_emu2_noff);
  TH1* hist_eta_antiidmuon_eantiidmu_FFQmis_noff=(TH1*)tmp_FFQmis->Get(whichtouse_emu2_noff);
  hist_eta_antiidmuon_eantiidmu_diboson->Scale(lumi());
  hist_eta_antiidmuon_eantiidmu_ttV->Scale(lumi());
  hist_eta_antiidmuon_eantiidmu_tV->Scale(lumi());
  hist_eta_antiidmuon_eantiidmu_ttH->Scale(lumi());
  hist_eta_antiidmuon_eantiidmu_Vgam->Scale(lumi());
  hist_eta_antiidmuon_eantiidmu_diboson_noff->Scale(lumi());
  hist_eta_antiidmuon_eantiidmu_ttV_noff->Scale(lumi());
  hist_eta_antiidmuon_eantiidmu_tV_noff->Scale(lumi());
  hist_eta_antiidmuon_eantiidmu_ttH_noff->Scale(lumi());
  hist_eta_antiidmuon_eantiidmu_Vgam_noff->Scale(lumi());
  Float_t eantimu_data=GHTBCs(hist_eta_antiidmuon_eantiidmu_data_noff), error_eantimu_data=statistic_error(hist_eta_antiidmuon_eantiidmu_data_noff);
  Float_t eantimu_VV=GHTBCs(hist_eta_antiidmuon_eantiidmu_diboson_noff), error_eantimu_VV=statistic_error(hist_eta_antiidmuon_eantiidmu_diboson_noff);
  Float_t eantimu_ttV=GHTBCs(hist_eta_antiidmuon_eantiidmu_ttV_noff), error_eantimu_ttV=statistic_error(hist_eta_antiidmuon_eantiidmu_ttV_noff);
  Float_t eantimu_tV=GHTBCs(hist_eta_antiidmuon_eantiidmu_tV_noff), error_eantimu_tV=statistic_error(hist_eta_antiidmuon_eantiidmu_tV_noff);
  Float_t eantimu_ttH=GHTBCs(hist_eta_antiidmuon_eantiidmu_ttH_noff), error_eantimu_ttH=statistic_error(hist_eta_antiidmuon_eantiidmu_ttH_noff);
  Float_t eantimu_Vgam=GHTBCs(hist_eta_antiidmuon_eantiidmu_Vgam_noff), error_eantimu_Vgam=statistic_error(hist_eta_antiidmuon_eantiidmu_Vgam_noff);
  Float_t eantimu_QmisID=GHTBCs(hist_eta_antiidmuon_eantiidmu_FFQmis_noff), error_eantimu_QmisID=statistic_error(hist_eta_antiidmuon_eantiidmu_FFQmis_noff);
  cout<<"e+antiidmu   "<<"&"<<eantimu_VV<<"$\\pm$"<<error_eantimu_VV<<setw(5)<<"&"<<eantimu_ttV<<"$\\pm$"<<error_eantimu_ttV<<setw(5)<<"&"<<
                      eantimu_tV<<"$\\pm$"<<error_eantimu_tV<<setw(5)<<"&"<<eantimu_ttH<<"$\\pm$"<<error_eantimu_ttH<<setw(5)<<"&"<<
                      eantimu_Vgam<<"$\\pm$"<<error_eantimu_Vgam<<setw(5)<<"&"<<eantimu_QmisID<<"$\\pm$"<<error_eantimu_QmisID<<setw(5)<<
                      "&"<<eantimu_data<<"$\\pm$"<<error_eantimu_data<<endl;
  hist_eta_antiidmuon_eantiidmu_data->Add(hist_eta_antiidmuon_eantiidmu_diboson,-1);
  hist_eta_antiidmuon_eantiidmu_data->Add(hist_eta_antiidmuon_eantiidmu_ttV,-1);
  hist_eta_antiidmuon_eantiidmu_data->Add(hist_eta_antiidmuon_eantiidmu_tV,-1);
  hist_eta_antiidmuon_eantiidmu_data->Add(hist_eta_antiidmuon_eantiidmu_ttH,-1);
  hist_eta_antiidmuon_eantiidmu_data->Add(hist_eta_antiidmuon_eantiidmu_Vgam,-1);
  hist_eta_antiidmuon_eantiidmu_data->Add(hist_eta_antiidmuon_eantiidmu_FFQmis,-1);
  hist_eta_antiidmuon_eantiidmu_data_noff->Add(hist_eta_antiidmuon_eantiidmu_diboson_noff,-1);
  hist_eta_antiidmuon_eantiidmu_data_noff->Add(hist_eta_antiidmuon_eantiidmu_ttV_noff,-1);
  hist_eta_antiidmuon_eantiidmu_data_noff->Add(hist_eta_antiidmuon_eantiidmu_tV_noff,-1);
  hist_eta_antiidmuon_eantiidmu_data_noff->Add(hist_eta_antiidmuon_eantiidmu_ttH_noff,-1);
  hist_eta_antiidmuon_eantiidmu_data_noff->Add(hist_eta_antiidmuon_eantiidmu_Vgam_noff,-1);
  hist_eta_antiidmuon_eantiidmu_data_noff->Add(hist_eta_antiidmuon_eantiidmu_FFQmis_noff,-1);
  if(i>1){
     hist->Add(hist_eta_antiidmuon_eantiidmu_data);
     hist->Write();
  }
  Float_t fakes_error_emu=sqrt( pow(ff_ele*sqrt(GHTBCs(hist_eta_antiidelectron_antiidemu_data_noff)),2) +
                                pow(ff_mu*sqrt(GHTBCs(hist_eta_antiidmuon_eantiidmu_data_noff)),2) );
  if(i<2){
   cout<<"emu jet fakes: "<<GHTBCs(hist_eta_antiidelectron_antiidemu_data)+GHTBCs(hist_eta_antiidmuon_eantiidmu_data)<<"$\\pm$"<<fakes_error_emu<<
       " where antiidemu: "<<GHTBCs(hist_eta_antiidelectron_antiidemu_data)<<" and eantiidmu: "<<GHTBCs(hist_eta_antiidmuon_eantiidmu_data)<<endl;
   cout<<"antiidemu no ff: "<<GHTBCs(hist_eta_antiidelectron_antiidemu_data_noff)<<endl;
   cout<<"eantiidmu no ff: "<<GHTBCs(hist_eta_antiidmuon_eantiidmu_data_noff)<<endl;
   cout<<"overall scale factor in antiidemu: "<<(GHTBCs(hist_eta_antiidelectron_antiidemu_data))
                                /(GHTBCs(hist_eta_antiidelectron_antiidemu_data_noff))<<endl;
   cout<<"overall scale factor in eantiidmu: "<<GHTBCs(hist_eta_antiidmuon_eantiidmu_data)/GHTBCs(hist_eta_antiidmuon_eantiidmu_data_noff)<<endl;
   cout<<"overall scale factor in emu: "<<(GHTBCs(hist_eta_antiidelectron_antiidemu_data)+GHTBCs(hist_eta_antiidmuon_eantiidmu_data))/
                                   (GHTBCs(hist_eta_antiidelectron_antiidemu_data_noff)+GHTBCs(hist_eta_antiidmuon_eantiidmu_data_noff))<<endl;
  }
  }
  }
  output->Close();
}
