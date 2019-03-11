#define SampleHandler_cxx
#include "../inc/SampleHandler.h"
#include "../inc/Lepton.h"
#include "LeptonClassifier.cxx"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include "variables.cxx"
#include "readFF.cxx"
#include "LHAPDF/LHAPDF.h"
#include "LHAPDF/Reweighting.h"
//#include "lumi.cxx"
//                              Attention::  dataset==1!!!
//                              FFcal_2jets <2!!
void SampleHandler::Loop(TString config)
{ 
  if(fChain == 0) return;
  datasetType=1;
  //read fake factor
  TFile *ff_file;
  //nominal
  if(config=="FFApp_2jets")ff_file=new TFile("output/hist_ff_1jets.root");
  if(config=="FFApp_3jets")ff_file=new TFile("output/hist_ff_2jets.root");
  if(config=="FFQmis_2jets")ff_file=new TFile("output/hist_ff_1jets.root");
  if(config=="FFQmis_3jets")ff_file=new TFile("output/hist_ff_2jets.root");
  //to read fake factors estimated from ttbar  or Wjets MC, which is for Clousure test
  TString ff_CT_file="output/hist_ff";
  if(config=="CT_FFApp_2jets") ff_file=new TFile(ff_CT_file+"_1jets_"+dataset+".root");
  if(config=="CT_FFApp_3jets") ff_file=new TFile(ff_CT_file+"_2jets_"+dataset+".root");
  //if(config=="CT_FFApp_2jets"&&dataset=="Wjets") ff_file=new TFile("output/hist_ff_1jets_Wjets.root");
  //if(config=="CT_FFApp_3jets"&&dataset=="Wjets") ff_file=new TFile("output/hist_ff_2jets_Wjets.root");
  TH1* hist_ff_eta_antiidelectron;
  TH1* hist_ff_eta_antiidmuon;
  if(config.Contains("FFApp")||config.Contains("FFQmis")){
     hist_ff_eta_antiidelectron=(TH1*)ff_file->Get("hist_ff_eta_antiidelectron");
     hist_ff_eta_antiidmuon=(TH1*)ff_file->Get("hist_ff_eta_antiidmuon");
  }
  float ff_ele, ff_mu;
  readFF(ff_ele,ff_mu,config);
  cout<<"-----------";
  cout<<ff_ele<<" "<<ff_mu<<endl;
  /*ifstream ff_file;
  if(config.Contains("FFApp")||config.Contains("FFQmis")){
     if(config.Contains("2jets")) ff_file("ff_1jets.txt",ifstream::in);
     if(config.Contains("3jets")) ff_file("ff_2jets.txt",ifstream::in);
     string line;
     while(getline(ff_file,line)){
        char dsid[200];float tmp_val;
        const char* readline=line.c_str();
        sscanf(readline,"%s %f",dsid,tmp_val);
        if(dsid=="ff_ele")ff_ele=tmp_val;
        if(dsid=="ff_mu")ff_mu=tmp_val;
     }
  }*/
  //read QmisID rates
  TH2 *hist_QmisID;
  if(config.Contains("QmisID")||config.Contains("FFQmis")){
     TFile *f_QmisID=new TFile("output/Rates_Tight_FixedCutTight.root");
     hist_QmisID=(TH2*)f_QmisID->Get("LikelihoodEtaPtTight");
  }
  //output file
  //for data-driven estimations and nominal selections
  TString output="/scratchfs/atlas/zhoums/2LSSAna_output/temp/hists_";
  if(config=="FFcal_1jets") output+=config; // == 1jet
  if(config=="FFcal_2jets") output+=config; // 1<=Njet<=2
  if(config=="FFcal_QmisID_1jets") output+=config; //==1jet, OS
  if(config=="FFcal_QmisID_2jets") output+=config; //1<=Njet<=2,OS 
  if(config=="FFApp_2jets") output+=config;        //==2jets
  if(config=="FFApp_3jets") output+=config;        //>=3jets
  if(config=="FFQmis_2jets") output+=config;        //==2jets
  if(config=="FFQmis_3jets") output+=config;        //>=3jets
  if(config=="QmisID_2jets") output+=config; //==2jets
  if(config=="QmisID_3jets") output+=config; //>=3jets
  //for closure test
  if(config=="CT_FFcal_1jets") output+=config; // == 1jet
  if(config=="CT_FFcal_2jets") output+=config; // 1<=Njet<=2
  if(config=="CT_FFApp_2jets") output+=config;   //==2jets
  if(config=="CT_FFApp_3jets") output+=config;  //>=3jets

  if(config.Contains("CT"))datasetType=1;

  if(!config.Contains("jets")){
    cout<<"enter valid config!!"<<endl;
    return ;
  }
  output += "_";
  output += dataset;
  output += ".root";
  TFile *output_file=new TFile(output,"recreate");
  //book histograms
  Float_t eta_bins_ele[6] = {0,0.6,1.37,1.52,2.0,2.50};                          
  Float_t eta_bins_mu[4] = {0,0.6,1.7,2.50};                          
  Float_t pt_bins_ele[4]  = {20,25,30,1000};
  Float_t pt_bins_mu[4]  = {20,25,30,1000};
  TH1::SetDefaultSumw2();
  TH1F *hist_eta_subelectron_ee=new TH1F("hist_eta_subelectron_ee","",5,eta_bins_ele);
  TH1F *hist_pt_subelectron_ee=new TH1F("hist_pt_subelectron_ee","",3,pt_bins_ele);
  TH2F *hist_eta_pt_electron_ee=new TH2F("hist_eta_pt_electron_ee","",5,eta_bins_ele,3,pt_bins_ele);
  TH1F *hist_eta_submuon_mumu=new TH1F("hist_eta_submuon_mumu","",3,eta_bins_mu);
  TH1F *hist_pt_submuon_mumu=new TH1F("hist_pt_submuon_mumu","",3,pt_bins_mu);
  TH2F *hist_eta_pt_muon_mumu=new TH2F("hist_eta_pt_muon_mumu","",3,eta_bins_mu,3,pt_bins_mu);
  TH1F *hist_eta_electron_emu=new TH1F("hist_eta_electron_emu","",5,eta_bins_ele);
  TH1F *hist_pt_electron_emu=new TH1F("hist_pt_electron_emu","",3,pt_bins_ele);
  TH2F *hist_eta_pt_electron_emu=new TH2F("hist_eta_pt_electron_emu","",5,eta_bins_ele,3,pt_bins_ele);
  TH1F *hist_eta_muon_emu=new TH1F("hist_eta_muon_emu","",3,eta_bins_mu);
  TH1F *hist_pt_muon_emu=new TH1F("hist_pt_muon_emu","",3,pt_bins_mu);
  TH2F *hist_eta_pt_muon_emu=new TH2F("hist_eta_pt_muon_emu","",3,eta_bins_mu,3,pt_bins_mu);
  
  TH1F *hist_eta_antiidelectron_eantiide=new TH1F("hist_eta_antiidelectron_eantiide","",5,eta_bins_ele);
  TH1F *hist_eta_antiidelectron_eantiide_noff=new TH1F("hist_eta_antiidelectron_eantiide_noff","",5,eta_bins_ele);
  TH1F *hist_eta_antiidelectron_antiideantiide=new TH1F("hist_eta_antiidelectron_antiideantiide","",5,eta_bins_ele);
  TH1F *hist_pt_antiidelectron_eantiide=new TH1F("hist_pt_antiidelectron_eantiide","",3,pt_bins_ele);
  TH1F *hist_pt_antiidelectron_eantiide_noff=new TH1F("hist_pt_antiidelectron_eantiide_noff","",3,pt_bins_ele);
  TH2F *hist_eta_pt_antiidelectron_eantiide=new TH2F("hist_eta_pt_antiidelectron_eantiide","",5,eta_bins_ele,3,pt_bins_ele);
  TH1F *hist_eta_antiidmuon_muantiidmu=new TH1F("hist_eta_antiidmuon_muantiidmu","",3,eta_bins_mu);
  TH1F *hist_eta_antiidmuon_muantiidmu_noff=new TH1F("hist_eta_antiidmuon_muantiidmu_noff","",3,eta_bins_mu);
  TH1F *hist_eta_antiidmuon_antiidmuantiidmu=new TH1F("hist_eta_antiidmuon_antiidmuantiidmu","",3,eta_bins_mu);
  TH1F *hist_pt_antiidmuon_muantiidmu=new TH1F("hist_pt_antiidmuon_muantiidmu","",3,pt_bins_mu);
  TH1F *hist_pt_antiidmuon_muantiidmu_noff=new TH1F("hist_pt_antiidmuon_muantiidmu_noff","",3,pt_bins_mu);
  TH2F *hist_eta_pt_antiidmuon_muantiidmu=new TH2F("hist_eta_pt_antiidmuon_muantiidmu","",3,eta_bins_mu,3,pt_bins_mu);
  TH1F *hist_eta_antiidelectron_antiidemu=new TH1F("hist_eta_antiidelectron_antiidemu","",5,eta_bins_ele);
  TH1F *hist_eta_antiidelectron_antiidemu_noff=new TH1F("hist_eta_antiidelectron_antiidemu_noff","",5,eta_bins_ele);
  TH1F *hist_pt_antiidelectron_antiidemu=new TH1F("hist_pt_antiidelectron_antiidemu","",3,pt_bins_ele);
  TH1F *hist_pt_antiidelectron_antiidemu_noff=new TH1F("hist_pt_antiidelectron_antiidemu_noff","",3,pt_bins_ele);
  TH2F *hist_eta_pt_antiidelectron_antiidemu=new TH2F("hist_eta_pt_antiidelectron_antiidemu","",5,eta_bins_ele,3,pt_bins_ele);
  TH1F *hist_eta_antiidmuon_eantiidmu=new TH1F("hist_eta_antiidmuon_eantiidmu","",3,eta_bins_mu);
  TH1F *hist_eta_antiidmuon_eantiidmu_noff=new TH1F("hist_eta_antiidmuon_eantiidmu_noff","",3,eta_bins_mu);
  TH1F *hist_pt_antiidmuon_eantiidmu=new TH1F("hist_pt_antiidmuon_eantiidmu","",3,pt_bins_mu); 
  TH1F *hist_pt_antiidmuon_eantiidmu_noff=new TH1F("hist_pt_antiidmuon_eantiidmu_noff","",3,pt_bins_mu); 
  TH2F *hist_eta_pt_antiidmuon_eantiidmu=new TH2F("hist_eta_pt_antiidmuon_eantiidmu","",3,eta_bins_mu,3,pt_bins_mu);
  TH1F *hist_eta_antiidelectron_antiideantiidmu=new TH1F("hist_eta_antiidelectron_antiideantiidmu","",5,eta_bins_ele);

  TH1F *hist_test_antiidelectron=new TH1F("hist_test_antiidelectron","",200,0,1000);
  TH1F *hist_test_antiidmuon=new TH1F("hist_test_antiidmuon","",200,0,1000);
  TH1F *hist_m_ll_ee=new TH1F("hist_m_ll_ee","",10,0,200);
  TH1F *hist_met_ee=new TH1F("hist_met_ee","",10,0,200);
  TH1F *hist_m_ll_mumu=new TH1F("hist_m_ll_mumu","",10,0,200);
  TH1F *hist_met_mumu=new TH1F("hist_met_mumu","",10,0,200);
  TH1F *hist_m_ll_emu=new TH1F("hist_m_ll_emu","",10,0,200);
  TH1F *hist_met_emu=new TH1F("hist_met_emu","",10,0,200);
  TH1F *hist_m_ll_eantiide=new TH1F("hist_m_ll_eantiide","",10,0,200);
  TH1F *hist_met_eantiide=new TH1F("hist_met_eantiide","",10,0,200);
  TH1F *hist_m_ll_muantiidmu=new TH1F("hist_m_ll_muantiidmu","",10,0,200);
  TH1F *hist_met_muantiidmu=new TH1F("hist_met_muantiidmu","",10,0,200);
  TH1F *hist_m_ll_eantiidmu=new TH1F("hist_m_ll_eantiidmu","",10,0,200);
  TH1F *hist_m_ll_antiidemu=new TH1F("hist_m_ll_antiidemu","",10,0,200);
  TH1F *hist_met_antiidemu=new TH1F("hist_met_antiidemu","",10,0,200);
  TH1F *hist_met_eantiidmu=new TH1F("hist_met_eantiidmu","",10,0,200);
  //Loop events
  Long64_t nentries = fChain->GetEntries();
  cout<<"total evts: "<<nentries<<endl;
  Int_t nTotalEle(0),nTotalMu(0), nLeadFakeEle(0), nLeadFakeMu(0), nSubFakeEle(0), nSubFakeMu(0);
  for(Long64_t jentry=0; jentry<nentries;jentry++) {
      fChain->GetEntry(jentry);
      if(jentry%500000==0)cout<<jentry<<" evts analyzed"<<endl;
      //determine common selection
      if(!dilep_type)continue;//type must be defined!!!otherwise loose objects not passing OB will enter!
      if(config.Contains("QmisID") && (total_charge!=0))continue;//reject SS
      if(config.Contains("FFQmis") && (total_charge!=0))continue;//reject SS
      if( ((!config.Contains("Qmis"))&&(!config.Contains("CT"))) && (abs(total_charge)!=2)) continue; //reject OS
      //to reject bjets
      if( nJets_OR_MV2c10_70>0)continue;
      vector<TLorentzVector>jetVec;
      Int_t nBjets=0;
      for(unsigned int i=0;i<jet_pt->size();i++){
          float pt=(*(jet_pt))[i],phi=(*(jet_phi))[i],eta=(*(jet_eta))[i],E=(*jet_E)[i];
          if((*jet_passOR)[i]){
             TLorentzVector tmp;tmp.SetPtEtaPhiE(pt,eta,phi,E);
             jetVec.push_back(tmp);
             if((*jet_flavor_weight_MV2c10)[i]>0.6459)nBjets++;
          }
      }
      //if(nBjets>=1)continue;
      //MET
      if(MET_RefFinal_et<10000)continue; 
      //#jet determinations
      if( (config.Contains("FFcal_1jets")||config=="FFcal_QmisID_1jets") && (nJets_OR!=1))continue;
      if( (config.Contains("FFcal_2jets")||config=="FFcal_QmisID_2jets") && (nJets_OR<2))continue;
      if( (config.Contains("FFApp_2jets")||config=="QmisID_2jets"||config=="FFQmis_2jets") && (nJets_OR<2))continue;
      if( (config.Contains("FFApp_3jets")||config=="QmisID_3jets"||config=="FFQmis_3jets") && (nJets_OR<3))continue;
      Char_t lep_isQMisID_0, lep_isQMisID_1;
      lep_isQMisID_0=(lep_truthPdgId_0+lep_ID_0==0)?true : false;
      lep_isQMisID_1=(lep_truthPdgId_1+lep_ID_1==0)?true : false;
      Char_t matchDLTll01,lep_isTrigMatchAny_0, lep_isTrigMatchAny_1;
      matchDLTll01=lep_isTrigMatchDLT_0&&lep_isTrigMatchDLT_1&&max(lep_Pt_0,lep_Pt_1)>(abs(lep_ID_0*lep_ID_1)==169)*((RunYear==2015)*19e3+(RunYear==2016)*23e3);
      lep_isTrigMatchAny_0=(lep_isTrigMatch_0||matchDLTll01)?true:false;
      lep_isTrigMatchAny_1=(lep_isTrigMatch_1||matchDLTll01)?true:false;
      //dedicated for closure test of fake factor. As ttbar MC includes full-lep channel, to reject QmisID
      //if(config.Contains("CT")&&(lep_isQMisID_0||lep_isQMisID_1))continue;
      //push objects to vector
      vector<Lepton>electron; vector<Lepton>lepton; 
      vector<TLorentzVector>electronVec; vector<TLorentzVector>leptonVec;
      vector<Lepton>muon; vector<TLorentzVector>muonVec;

      TLorentzVector tmp; 
      if(lep_Pt_0<lep_Pt_1)cout<<"nani"<<endl;
      tmp.SetPtEtaPhiM(lep_Pt_0,lep_Eta_0,lep_Phi_0,0); leptonVec.push_back(tmp);
      Lepton tmplepton1(lep_ID_0,lep_Pt_0,lep_Eta_0,lep_Phi_0,lep_isTightLH_0,lep_isTight_0,lep_isolationFixedCutTight_0,
                       lep_isolationFixedCutTightTrackOnly_0,lep_isTrigMatchAny_0,lep_truthOrigin_0,lep_truthType_0,lep_isTruthMatched_0,
                       lep_isQMisID_0,lep_sigd0PV_0,lep_Z0SinTheta_0,lep_topoEtcone20_0,lep_ptVarcone20_0,lep_isolationLoose_0,
                       lep_ChargeIDBDTTight_0,lep_PromptLeptonIso_TagWeight_0,lep_isolationLooseTrackOnly_0);
      lepton.push_back(tmplepton1);
      if(fabs(lep_ID_0)==11){electron.push_back(tmplepton1); electronVec.push_back(tmp);}
      if(fabs(lep_ID_0)==13){muon.push_back(tmplepton1); muonVec.push_back(tmp);}

      tmp.SetPtEtaPhiM(lep_Pt_1,lep_Eta_1,lep_Phi_1,0); leptonVec.push_back(tmp);
      Lepton tmplepton2(lep_ID_1,lep_Pt_1,lep_Eta_1,lep_Phi_1,lep_isTightLH_1,lep_isTight_1,lep_isolationFixedCutTight_1,
                        lep_isolationFixedCutTightTrackOnly_1,lep_isTrigMatchAny_1,lep_truthOrigin_1,lep_truthType_1,lep_isTruthMatched_1,
                        lep_isQMisID_1,lep_sigd0PV_1,lep_Z0SinTheta_1,lep_topoEtcone20_1,lep_ptVarcone20_1,lep_isolationLoose_1,
                       lep_ChargeIDBDTTight_1,lep_PromptLeptonIso_TagWeight_1,lep_isolationLooseTrackOnly_1);
      lepton.push_back(tmplepton2);
      if(fabs(lep_ID_1)==11){electron.push_back(tmplepton2); electronVec.push_back(tmp);}
      if(fabs(lep_ID_1)==13){muon.push_back(tmplepton2); muonVec.push_back(tmp);}
      //
      /*vector<TLorentzVector>jetVec;
      for(unsigned int i=0;i<jet_pt->size();i++){
          float pt=(*(jet_pt))[i],phi=(*(jet_phi))[i],eta=(*(jet_eta))[i],E=(*jet_E)[i];
          if((*jet_passTauOR)[i]){
             TLorentzVector tmp;tmp.SetPtEtaPhiE(pt,eta,phi,E);
             jetVec.push_back(tmp);
          }
      }*/
      //divide two leptons into id+id, id+anti-id,
      //for id+id, tag first one leading lepton based on pt; for id+anti-id, tag fisrt one id, second anti-id
      if(lepton.size()!=2)continue;
      Float_t lep_matchTrig_pt=0;
      Int_t category=0; //ee:1, e+antiid e: 2; mm:11, m+antiid m:12; em: 21, antiid e + m:22, e + antiid m: 23
      if(LeptonClassifier(datasetType,&(lepton[0]))==1 && LeptonClassifier(datasetType,&(lepton[1]))==1 &&
          (lepton[0].matched_Trigger==1 || lepton[1].matched_Trigger==1)  ){
          Lepton tmplepton=lepton[0];
          if(electron.size()==2)category=1;
          if(muon.size()==2)category=11;
          if(electron.size()==1&&muon.size()==1)category=21;
      }
      if(LeptonClassifier(datasetType,&(lepton[1]))==1&&lepton[1].matched_Trigger==1&&LeptonClassifier(datasetType,&(lepton[0]))==2 ){
      //if(LeptonClassifier(datasetType,&(lepton[1]))==2&&LeptonClassifier(datasetType,&(lepton[0]))==2&&
         Lepton tmplepton=lepton[0];
         tmplepton=lepton[0]; lepton[0]=lepton[1]; lepton[1]=tmplepton;
         if(electron.size()==2)category=2;
         if(muon.size()==2)category=12;
         if(fabs(lepton[0].ID)==13&&fabs(lepton[1].ID)==11)category=22;
         if(fabs(lepton[0].ID)==11&&fabs(lepton[1].ID==13))category=23;
      }
      if(LeptonClassifier(datasetType,&(lepton[0]))==1&&lepton[0].matched_Trigger==1&&LeptonClassifier(datasetType,&(lepton[1]))==2 ){
      //if(LeptonClassifier(datasetType,&(lepton[0]))==2&&LeptonClassifier(datasetType,&(lepton[1]))==2&&
         if(electron.size()==2)category=2;
         if(muon.size()==2)category=12;
         if(fabs(lepton[0].ID)==13&&fabs(lepton[1].ID)==11)category=22;
         if(fabs(lepton[0].ID)==11&&fabs(lepton[1].ID==13))category=23;
      }
      //define common selection
      bool common_selection;
      common_selection=(lep_Pt_0>30000 && lep_Pt_1>20000) && (leptonVec[0] + leptonVec[1]).M()>15000;
      if(!common_selection)continue;
      //try muon pt > 25 GeV
      if( (category==11 || category==12 ) && lep_Pt_1<25000) continue;
      //define Z veto, which can be used in fake estimation
      bool applyZveto=fabs((leptonVec[0] + leptonVec[1]).M()-91200)<10000;
      //if((category==2||category==1)&&applyZveto)continue;
      //if((category==2||category==1)&&fabs((leptonVec[0] + leptonVec[1]).M()-91200)<10000)cout<<".........."<<endl;
      //read QmisID rates
      Double_t weight=n_weight_tight;
      if((category==1||category==21) && config.Contains("QmisID")){//only assign QmisID rates for OS events
          Double_t temp_weight=1.0;
          if(category==1){
            double temp_pt_1=electron[0].pt/1000.;
            double temp_pt_2=electron[1].pt/1000.;
            if(temp_pt_1>hist_QmisID->GetYaxis()->GetXmax()) temp_pt_1=hist_QmisID->GetYaxis()->GetXmax()*0.999;
            if(temp_pt_2>hist_QmisID->GetYaxis()->GetXmax()) temp_pt_2=hist_QmisID->GetYaxis()->GetXmax()*0.999;
            double fake_1=hist_QmisID->GetBinContent(hist_QmisID->FindBin(fabs(electron[0].eta),temp_pt_1));
                         // +hist_QmisID->GetBinError(hist_QmisID->FindBin(fabs(electron[0].eta),temp_pt_1));
            double fake_2=hist_QmisID->GetBinContent(hist_QmisID->FindBin(fabs(electron[1].eta),temp_pt_2));
                        // +hist_QmisID->GetBinError(hist_QmisID->FindBin(fabs(electron[1].eta),temp_pt_2));
            temp_weight=(fake_1+fake_2-2*fake_1*fake_2)/(1-fake_1-fake_2+2*fake_1*fake_2);
          }
          if(category==21){
             double temp_pt_1=electron[0].pt/1000.;
             if(temp_pt_1>hist_QmisID->GetYaxis()->GetXmax()) temp_pt_1=hist_QmisID->GetYaxis()->GetXmax()*0.999;
             double fake_1=hist_QmisID->GetBinContent(hist_QmisID->FindBin(fabs(electron[0].eta),temp_pt_1));
                          // +hist_QmisID->GetBinError(hist_QmisID->FindBin(fabs(electron[0].eta),temp_pt_1));
             temp_weight=fake_1/(1.0-fake_1);
          }
          weight=n_weight_tight*temp_weight;
      }
      //read fake factor
      double weightxx;
      if(config.Contains("FFApp")){
         if(category==2 || category==22){//e+antiid e , antiid e + m
            double temp_pt=fabs(lepton[1].pt)/1000.;
            if(temp_pt>=1000) temp_pt=999;
            //double temp_weight=hist_ff_eta_antiidelectron->GetBinContent(hist_ff_eta_antiidelectron->FindBin(fabs(lepton[1].eta)));
            double temp_weight=ff_ele;
	    weight=n_weight_tight*temp_weight;
         }
         //end of 2/22 cate
         if(category==12 || category==23){//m+antiid m, e+antiid m
            double temp_pt=fabs(lepton[1].pt)/1000.;
            if(temp_pt>=1000) temp_pt=999;
            //double temp_weight=hist_ff_eta_antiidmuon->GetBinContent(hist_ff_eta_antiidmuon->GetXaxis()->FindBin(fabs(lepton[1].eta)));
               //       hist_ff_eta_antiidmuon->FindBin(temp_pt));
            double temp_weight=ff_mu;
            weight=n_weight_tight*temp_weight;
            weightxx=n_weight_tight;
         }
         //end of 12/23 cate
      }
      //to know weighted FFQmis events before applying fake factor
      if(config.Contains("FFQmis")&&category==23){
         double temp_pt_1=electron[0].pt/1000.;
         if(temp_pt_1>hist_QmisID->GetYaxis()->GetXmax()) temp_pt_1=hist_QmisID->GetYaxis()->GetXmax()*0.999;
         double fake_1=hist_QmisID->GetBinContent(hist_QmisID->FindBin(fabs(electron[0].eta),temp_pt_1));
         Double_t temp_weight=fake_1/(1.0-fake_1);
         double temp_pt_2=muon[0].pt/1000.;
         if(temp_pt_2>=1000) temp_pt_2=999;
         //double temp_ff=hist_ff_eta_antiidmuon->GetBinContent(hist_ff_eta_antiidmuon->GetXaxis()->FindBin(fabs(lepton[1].eta)));
//                        hist_ff_eta_antiidmuon->FindBin(temp_pt_2));
         double temp_ff=ff_mu;
         weight=temp_weight*temp_ff;
         weightxx=n_weight_tight*temp_weight;
      }
      //ee
      if(category==1 ){
       /*  if(!lep_isPrompt_0) {
            hist_eta_subelectron_ee->Fill(fabs(lepton[0].eta),weight);
            hist_pt_subelectron_ee->Fill(fabs(lepton[0].pt)/1000.,weight);
         }
         if(!lep_isPrompt_1) {
            hist_eta_subelectron_ee->Fill(fabs(lepton[1].eta),weight);
            hist_pt_subelectron_ee->Fill(fabs(lepton[1].pt)/1000.,weight);
         }*/
         hist_eta_subelectron_ee->Fill(fabs(lepton[1].eta),weight);
         hist_pt_subelectron_ee->Fill(fabs(lepton[1].pt)/1000.,weight);
         hist_m_ll_ee->Fill((leptonVec[0] + leptonVec[1]).M()/1000.,weight);
         hist_met_ee->Fill(MET_RefFinal_et/1000.,weight);
      }
      if(category==2){
         nTotalEle++;
         if(lepton[1].pt>lepton[0].pt) nLeadFakeEle++;
         if(lepton[1].pt<lepton[0].pt) nSubFakeEle++;
         hist_eta_antiidelectron_eantiide->Fill(fabs(lepton[1].eta),weight);
         hist_pt_antiidelectron_eantiide->Fill(fabs(lepton[1].pt)/1000.,weight);
         hist_test_antiidelectron->Fill(fabs(lepton[1].pt)/1000.,weight);
         hist_m_ll_eantiide->Fill((leptonVec[0] + leptonVec[1]).M()/1000.,weight);
         hist_met_eantiide->Fill(MET_RefFinal_et/1000.,weight);
         //to get total weighted events before applying fake factor
         hist_eta_antiidelectron_eantiide_noff->Fill(fabs(lepton[1].eta),n_weight_tight);
         hist_pt_antiidelectron_eantiide_noff->Fill(fabs(lepton[1].pt)/1000.,n_weight_tight);
      }
      //mumu
      if(category==11){
       /*  if(!lep_isPrompt_0){
         hist_eta_submuon_mumu->Fill(fabs(lepton[0].eta),weight);
         hist_pt_submuon_mumu->Fill(fabs(lepton[0].pt)/1000.,weight);
         }
         if(!lep_isPrompt_1){
         hist_eta_submuon_mumu->Fill(fabs(lepton[1].eta),weight);
         hist_pt_submuon_mumu->Fill(fabs(lepton[1].pt)/1000.,weight);
         }*/
         hist_eta_submuon_mumu->Fill(fabs(lepton[1].eta),weight);
         hist_pt_submuon_mumu->Fill(fabs(lepton[1].pt)/1000.,weight);
         hist_eta_pt_muon_mumu->Fill(fabs(lepton[1].eta),fabs(lepton[1].pt)/1000.,weight);
         hist_m_ll_mumu->Fill((leptonVec[0] + leptonVec[1]).M()/1000.,weight);
         hist_met_mumu->Fill(MET_RefFinal_et/1000.,weight);
      }
      if(category==12){
         nTotalMu++;
         if(lepton[1].pt>lepton[0].pt) nLeadFakeMu++;
         if(lepton[1].pt<lepton[0].pt) nSubFakeMu++;
         hist_eta_antiidmuon_muantiidmu->Fill(fabs(lepton[1].eta),weight);
         hist_pt_antiidmuon_muantiidmu->Fill(fabs(lepton[1].pt)/1000.,weight);
         hist_eta_pt_antiidmuon_muantiidmu->Fill(fabs(lepton[1].eta),fabs(lepton[1].pt)/1000.,weight);
         hist_test_antiidmuon->Fill(fabs(lepton[1].pt)/1000.,weight);
         hist_m_ll_muantiidmu->Fill((leptonVec[0] + leptonVec[1]).M()/1000.,weight);
         hist_met_muantiidmu->Fill(MET_RefFinal_et/1000.,weight);
         //to get total weighted events before applying fake factor
         hist_eta_antiidmuon_muantiidmu_noff->Fill(fabs(lepton[1].eta),n_weight_tight);
         hist_pt_antiidmuon_muantiidmu_noff->Fill(fabs(lepton[1].pt)/1000.,n_weight_tight);
      }
      //emu
      if(category==21){
         hist_eta_electron_emu->Fill(fabs(electron[0].eta),weight);
         hist_pt_electron_emu->Fill(fabs(electron[0].pt)/1000.,weight);
         hist_eta_pt_electron_emu->Fill(fabs(electron[0].eta),fabs(electron[0].pt)/1000.,weight);
         hist_eta_muon_emu->Fill(fabs(muon[0].eta),weight);
         hist_pt_muon_emu->Fill(fabs(muon[0].pt)/1000.,weight);
         hist_eta_pt_muon_emu->Fill(fabs(electron[0].eta),fabs(muon[0].pt)/1000.,weight);
         hist_m_ll_emu->Fill((electronVec[0] + muonVec[0]).M()/1000.,weight);
         hist_met_emu->Fill(MET_RefFinal_et/1000.,weight);
      }
      if(category==23){
         hist_eta_antiidmuon_eantiidmu->Fill(fabs(muon[0].eta),weight);
         hist_pt_antiidmuon_eantiidmu->Fill(fabs(muon[0].pt)/1000.,weight);
         hist_eta_pt_antiidmuon_eantiidmu->Fill(fabs(muon[0].eta),fabs(muon[0].pt)/1000.,weight);
         hist_m_ll_eantiidmu->Fill((electronVec[0] + muonVec[0]).M()/1000.,weight);
         hist_met_eantiidmu->Fill(MET_RefFinal_et/1000.,weight);
         //to get total weighted events before applying fake factor
         hist_eta_antiidmuon_eantiidmu_noff->Fill(fabs(muon[0].eta),weightxx);
         hist_pt_antiidmuon_eantiidmu_noff->Fill(fabs(muon[0].pt)/1000.,weightxx);
      }
      if(category==22){
         hist_eta_antiidelectron_antiidemu->Fill(fabs(electron[0].eta),weight);
         hist_pt_antiidelectron_antiidemu->Fill(fabs(electron[0].pt)/1000.,weight);
         hist_eta_pt_antiidelectron_antiidemu->Fill(fabs(electron[0].eta),fabs(electron[0].pt)/1000.,weight);
         hist_m_ll_antiidemu->Fill((electronVec[0] + muonVec[0]).M()/1000.,weight);
         hist_met_antiidemu->Fill(MET_RefFinal_et/1000.,weight);
         //to get total weighted events before applying fake factor
         hist_eta_antiidelectron_antiidemu_noff->Fill(fabs(electron[0].eta),n_weight_tight);
         hist_pt_antiidelectron_antiidemu_noff->Fill(fabs(electron[0].pt)/1000.,n_weight_tight);
      }
  }//end entry loop
  cout<<"         "<<"Ele "<<"   Mu"<<endl;
  cout<<"Total    "<<nTotalEle<<"   "<<nTotalMu<<endl;
  cout<<"LeadFake "<<nLeadFakeEle<<"   "<<nLeadFakeMu<<endl;
  cout<<"SubFake  "<<nSubFakeEle<<"   "<<nSubFakeMu<<endl;
  hist_test_antiidelectron->Write();
  hist_test_antiidmuon->Write();
  hist_eta_subelectron_ee->Write();
  hist_pt_subelectron_ee            ->Write();
  hist_eta_submuon_mumu             ->Write();
  hist_pt_submuon_mumu              ->Write();
  hist_eta_pt_muon_mumu              ->Write();
  hist_eta_electron_emu             ->Write();
  hist_pt_electron_emu              ->Write();
  hist_eta_pt_electron_emu              ->Write();
  hist_eta_muon_emu                 ->Write();
  hist_pt_muon_emu                  ->Write();
  hist_eta_pt_muon_emu                  ->Write();
                                    
  hist_eta_antiidelectron_eantiide  ->Write();
  hist_eta_antiidelectron_antiideantiide  ->Write();
  hist_pt_antiidelectron_eantiide   ->Write();
  hist_eta_antiidmuon_muantiidmu    ->Write();
  hist_eta_antiidmuon_antiidmuantiidmu    ->Write();
  hist_pt_antiidmuon_muantiidmu     ->Write();
  hist_eta_pt_antiidmuon_muantiidmu     ->Write();
  hist_eta_antiidelectron_antiidemu ->Write();
  hist_pt_antiidelectron_antiidemu  ->Write();
  hist_eta_pt_antiidelectron_antiidemu  ->Write();
  hist_eta_antiidmuon_eantiidmu     ->Write();
  hist_eta_antiidelectron_antiideantiidmu ->Write();
  hist_pt_antiidmuon_eantiidmu      ->Write();
  hist_eta_pt_antiidmuon_eantiidmu      ->Write();
 
  hist_eta_antiidelectron_eantiide_noff->Write();
  hist_pt_antiidelectron_eantiide_noff->Write();
  hist_eta_antiidmuon_muantiidmu_noff->Write();
  hist_pt_antiidmuon_muantiidmu_noff->Write();
  hist_eta_antiidmuon_eantiidmu_noff->Write();
  hist_pt_antiidmuon_eantiidmu_noff->Write();
  hist_eta_antiidelectron_antiidemu_noff->Write();
  hist_pt_antiidelectron_antiidemu_noff->Write();

  hist_m_ll_ee->Write();
  hist_met_ee->Write();
  hist_m_ll_mumu->Write();
  hist_met_mumu->Write();
  hist_m_ll_emu->Write();
  hist_met_emu->Write();
  hist_m_ll_eantiide->Write();
  hist_met_eantiide->Write();
  hist_m_ll_muantiidmu->Write();
  hist_met_muantiidmu->Write();
  hist_m_ll_antiidemu->Write();
  hist_m_ll_eantiidmu->Write();
  hist_met_eantiidmu->Write();
  hist_met_antiidemu->Write();
  output_file->Close();
}

void SampleHandler::cutflow(Int_t Njets){
  if (fChain == 0) return;
  Long64_t nentries = fChain->GetEntries();
  cout<<nentries<<endl;
  Int_t numOfinput=0,numOfpassTightLeptons=0,numOfpasstriggerMatch=0,numOfpassSS=0,numOfpassNjet=0,numOfpassBveto=0,numOfpassMET=0, 
        numOfpassDY=0,numOfpassZveto=0;
  Double_t numOfwgtinput=0,numOfwgtpassTightLeptons=0,numOfwgtpasstriggerMatch=0,numOfwgtpassSS=0,numOfwgtpassNjet=0,numOfwgtpassBveto=0,numOfwgtpassMET=0, numOfwgtpassDY=0,numOfwgtpassZveto;
  Double_t numOfwgtpassNjet_ee=0, numOfwgtpassNjet_mumu=0, numOfwgtpassNjet_emu=0;
  Double_t numOfwgtpassNjet_ee2=0, numOfwgtpassNjet_mumu2=0, numOfwgtpassNjet_emu2=0;
  for(Long64_t jentry=0; jentry<nentries;jentry++){
      fChain->GetEntry(jentry);
      if(!dilep_type)continue;
      Char_t lep_isQMisID_0, lep_isQMisID_1;
      lep_isQMisID_0=(lep_truthPdgId_0+lep_ID_0==0)?true : false;
      lep_isQMisID_1=(lep_truthPdgId_1+lep_ID_1==0)?true : false;
      Char_t matchDLTll01,lep_isTrigMatchAny_0, lep_isTrigMatchAny_1;
      matchDLTll01=lep_isTrigMatchDLT_0&&lep_isTrigMatchDLT_1&&max(lep_Pt_0,lep_Pt_1)>(abs(lep_ID_0*lep_ID_1)==169)*((RunYear==2015)*19e3+(RunYear==2016)*23e3);
      lep_isTrigMatchAny_0=(lep_isTrigMatch_0||matchDLTll01)?true:false;
      lep_isTrigMatchAny_1=(lep_isTrigMatch_1||matchDLTll01)?true:false;
      vector<Lepton>electron; vector<Lepton>lepton;
      vector<TLorentzVector>electronVec; vector<TLorentzVector>leptonVec;
      vector<Lepton>muon; vector<TLorentzVector>muonVec;
      TLorentzVector tmp;
      Float_t lep_matchTrig_pt=0;
      tmp.SetPtEtaPhiM(lep_Pt_0,lep_Eta_0,lep_Phi_0,0); leptonVec.push_back(tmp);
      Lepton tmplepton1(lep_ID_0,lep_Pt_0,lep_Eta_0,lep_Phi_0,lep_isTightLH_0,lep_isTight_0,lep_isolationFixedCutTight_0,
                       lep_isolationFixedCutTightTrackOnly_0,lep_isTrigMatchAny_0,lep_truthOrigin_0,lep_truthType_0,lep_isTruthMatched_0,
                       lep_isQMisID_0,lep_sigd0PV_0,lep_Z0SinTheta_0,lep_topoEtcone20_0,lep_ptVarcone20_0,lep_isolationLoose_0,
                       lep_ChargeIDBDTTight_0,lep_PromptLeptonIso_TagWeight_0,lep_isolationLooseTrackOnly_0);
      lepton.push_back(tmplepton1);
      if(fabs(lep_ID_0)==11){electron.push_back(tmplepton1); electronVec.push_back(tmp);}
      if(fabs(lep_ID_0)==13){muon.push_back(tmplepton1); muonVec.push_back(tmp);}

      tmp.SetPtEtaPhiM(lep_Pt_1,lep_Eta_1,lep_Phi_1,0); leptonVec.push_back(tmp);
      Lepton tmplepton2(lep_ID_1,lep_Pt_1,lep_Eta_1,lep_Phi_1,lep_isTightLH_1,lep_isTight_1,lep_isolationFixedCutTight_1,
                        lep_isolationFixedCutTightTrackOnly_1,lep_isTrigMatchAny_1,lep_truthOrigin_1,lep_truthType_1,lep_isTruthMatched_1,
                        lep_isQMisID_1,lep_sigd0PV_1,lep_Z0SinTheta_1,lep_topoEtcone20_1,lep_ptVarcone20_1,lep_isolationLoose_1,
                       lep_ChargeIDBDTTight_1,lep_PromptLeptonIso_TagWeight_1,lep_isolationLooseTrackOnly_1);
      lepton.push_back(tmplepton2);
      if(fabs(lep_ID_1)==11){electron.push_back(tmplepton2); electronVec.push_back(tmp);}
      if(fabs(lep_ID_1)==13){muon.push_back(tmplepton2); muonVec.push_back(tmp);}
      //
      vector<TLorentzVector>jetVec;
      for(unsigned int i=0;i<jet_pt->size();i++){
          float pt=(*(jet_pt))[i],phi=(*(jet_phi))[i],eta=(*(jet_eta))[i],E=(*jet_E)[i];
          if((*jet_passOR)[i]){
             TLorentzVector tmp;tmp.SetPtEtaPhiE(pt,eta,phi,E);
             jetVec.push_back(tmp);
          }
      }
      //input
      numOfinput++; numOfwgtinput+=n_weight_tight;
      //two tight SS leptons
      if(lepton.size()!=2)continue;
      if(abs(total_charge)!=2)continue;
      /*cout<<"----------------"<<endl;
      cout<<(int)lep_isQMisID_0<<endl;
      cout<<(int)lep_isQMisID_1<<endl;*/
      if( !(LeptonClassifier(datasetType,&(lepton[0]))==1 && LeptonClassifier(datasetType,&(lepton[1]))==1 &&
            (lepton[0].matched_Trigger || lepton[1].matched_Trigger) ) )
           continue;
          numOfpassTightLeptons++;numOfwgtpassTightLeptons+=n_weight_tight;
      //pt_l1>30GeV, >=1 lepton matches trigger
      if( !(lep_Pt_0>30000 && lep_Pt_1>20000))continue;
         numOfpasstriggerMatch++;numOfwgtpasstriggerMatch+=n_weight_tight;
      //B veto
      if(nJets_OR_MV2c10_70>0)continue;numOfpassBveto++;numOfwgtpassBveto+=n_weight_tight;
      //MET>10GeV
      if(MET_RefFinal_et<10000)continue;numOfpassMET++;numOfwgtpassMET+=n_weight_tight;
      //M_ll>15GeV
      if((leptonVec[0] + leptonVec[1]).M()<15000) continue; numOfpassDY++; numOfwgtpassDY+=n_weight_tight;
      //Z veto
      if(abs(lepton[0].ID)==11&&abs(lepton[1].ID)==11&&fabs((leptonVec[0] + leptonVec[1]).M()-91200)<10000) continue;
      numOfpassZveto++; numOfwgtpassZveto+=n_weight_tight; 
      //Njet>=2/3
      if(((nJets_OR<2)&&Njets==2)||(nJets_OR<3&&Njets==3))continue;numOfpassNjet++;numOfwgtpassNjet+=n_weight_tight;
      cout<<"EventNumber: "<<EventNumber<<endl;
      if(abs(lepton[0].ID)==11&&abs(lepton[1].ID)==11) {numOfwgtpassNjet_ee+=n_weight_tight; numOfwgtpassNjet_ee2+=n_weight_tight*n_weight_tight;}
      if(abs(lepton[0].ID)==13&&abs(lepton[1].ID)==13){ numOfwgtpassNjet_mumu+=n_weight_tight; numOfwgtpassNjet_mumu2+=n_weight_tight*n_weight_tight;}
      if((abs(lepton[0].ID)==11&&abs(lepton[1].ID)==13) || (abs(lepton[0].ID)==13&&abs(lepton[1].ID)==11)) {
          numOfwgtpassNjet_emu+=n_weight_tight;
          numOfwgtpassNjet_emu2+=n_weight_tight*n_weight_tight;
      }
      //B veto
      /*Int_t numOfbjet=0;
      for(unsigned int i=0;i<jet_flavor_weight_MV2c10->size();i++){
          if((*jet_flavor_weight_MV2c10)[i]>0.8244 && (*jet_passTauOR)[i])numOfbjet++;
      }
      if(numOfbjet>0)continue;*/
  }
  cout<<setw(10)<<"cut flow"<<setw(10)<<endl;
  double scale_factor=36.1;
  cout<<"----------------------------------------------------"<<endl;
  cout<<"input:        "<<setw(2)<<numOfinput<<setw(15)<<numOfwgtinput*scale_factor<<endl;
  cout<<"TightLeptons: "<<setw(2)<<numOfpassTightLeptons<<setw(15)<<numOfwgtpassTightLeptons<<endl;
  cout<<"pt_l1, match: "<<setw(2)<<numOfpasstriggerMatch<<setw(15)<<numOfwgtpasstriggerMatch*scale_factor<<endl;
  cout<<"B veto:       "<<setw(2)<<numOfpassBveto<<setw(15)<<numOfwgtpassBveto*scale_factor<<endl;
  cout<<"MET:          "<<setw(2)<<numOfpassMET<<setw(15)<<numOfwgtpassMET*scale_factor<<endl;
  cout<<"DY:           "<<setw(2)<<numOfpassDY<<setw(15)<<numOfwgtpassDY*scale_factor<<endl;
  cout<<"Zveto:        "<<setw(2)<<numOfpassZveto<<setw(15)<<numOfwgtpassZveto*scale_factor<<endl;
  cout<<"Njet:         "<<setw(2)<<numOfpassNjet<<setw(15)<<numOfwgtpassNjet*scale_factor<<endl;
  cout<<"    ee         mumu          emu"<<endl;
  cout<<numOfwgtpassNjet_ee*scale_factor<<"+-"<<sqrt(numOfwgtpassNjet_ee2)*scale_factor<<"    "<<numOfwgtpassNjet_mumu*scale_factor<<"+-"<<sqrt(numOfwgtpassNjet_mumu2)*scale_factor<<"    "<<numOfwgtpassNjet_emu*scale_factor<<"+-"<<sqrt(numOfwgtpassNjet_emu2)*scale_factor<<endl;
  //cout<<""<<"&"
}
void SampleHandler::makeNtuple(TString config,TString CRSel){
  
  if (fChain == 0) return;  
  //if((CRSel.Contains("CR")||CRSel.Contains("preselection")) && config.Contains("nominal")) datasetType=1;//only for nominal running, not FFApp etc
  bool doSystematics=true;
  TString output;
  output="/scratchfs/atlas/zhoums/2LSSAna_output/output/";
  output += CRSel;
  if(config.Contains("2jets")) output += "/2jets";
  if(config.Contains("3jets")) output += "/3jets";
  //output += config;
  if(config.Contains("nominal"))output +="/miniNtuple_";
  if(config.Contains("QmisID"))output +="/miniNtuple_QmisID_";
  if(config.Contains("FFQmis"))output +="/miniNtuple_FFQmis_";
  if(config.Contains("FFApp"))output +="/miniNtuple_FFApp_";
  /*if(doSystematics){
     output="/scratchfs/atlas/zhoums/2LSSAna_output/output/Systematics/";
     output+=SysSrc;
     output+="/miniNtuple_";
  }*/
  output += dataset;
  output += ".root";

  //read QmisID rates
  Float_t QmisID_fr[6][4];
  TFile *f_QmisID=new TFile("output/Rates_Tight_FixedCutTight.root");
  TH2 *hist_QmisID=(TH2*)f_QmisID->Get("LikelihoodEtaPtTight");
  //read fake factors
  TFile *ff_file;
  if(config.Contains("2jets"))ff_file=new TFile("output/hist_ff_1jets.root");
  if(config.Contains("3jets"))ff_file=new TFile("output/hist_ff_2jets.root");
  TH2* hist_ff_eta_antiidelectron;
  TH2* hist_ff_eta_antiidmuon;
  if(!config.Contains("nominal")){
     hist_ff_eta_antiidelectron=(TH2*)ff_file->Get("hist_ff_pt_antiidelectron");
     hist_ff_eta_antiidmuon=(TH2*)ff_file->Get("hist_ff_pt_antiidmuon");
  }
  float ff_ele, ff_mu;
  readFF(ff_ele,ff_mu,config);
  cout<<ff_ele<<" "<<ff_mu<<endl;
  TFile *output_file=new TFile(output,"recreate");
  TTree *tree=new TTree("Tree","vars");
  Float_t m_ll,m_jj,m_j1j2,m_j1j3,m_j2j3,MET,pt_leadinglepton,pt_sublepton, eta_leadinglepton, eta_sublepton,pt_j1,pt_j2,m_jj_w,m_l1jj,m_all,pt_vecsum,pt_sum,mindR_l1j,mindR_l2j,Mt,m_l1j,m_l2j,RMS,
          ChargeIDBDTTight_0,PromptLeptonIso_TagWeight_0, ChargeIDBDTTight_1,PromptLeptonIso_TagWeight_1;
  Double_t weight; Int_t channel,numOfjet, n_category;
  Int_t n_truthOrigin_0;
  Int_t n_truthOrigin_1;
  Double_t        n_pileupEventWeight_UP;
  Double_t        n_pileupEventWeight_DOWN;
  Float_t         n_MV2c10_70_EventWeight_B0_up;
  Float_t         n_MV2c10_70_EventWeight_B0_down;
  Float_t         n_MV2c10_70_EventWeight_B1_up;
  Float_t         n_MV2c10_70_EventWeight_B1_down;
  Float_t         n_MV2c10_70_EventWeight_B2_up;
  Float_t         n_MV2c10_70_EventWeight_B2_down;
  Float_t         n_MV2c10_70_EventWeight_B3_up;
  Float_t         n_MV2c10_70_EventWeight_B3_down;
  Float_t         n_MV2c10_70_EventWeight_B4_up;
  Float_t         n_MV2c10_70_EventWeight_B4_down;
  Float_t         n_MV2c10_70_EventWeight_B5_up;
  Float_t         n_MV2c10_70_EventWeight_B5_down;
  Float_t         n_MV2c10_70_EventWeight_C0_up;
  Float_t         n_MV2c10_70_EventWeight_C0_down;
  Float_t         n_MV2c10_70_EventWeight_C1_up;
  Float_t         n_MV2c10_70_EventWeight_C1_down;
  Float_t         n_MV2c10_70_EventWeight_C2_up;
  Float_t         n_MV2c10_70_EventWeight_C2_down;
  Float_t         n_MV2c10_70_EventWeight_C3_up;
  Float_t         n_MV2c10_70_EventWeight_C3_down;
  Float_t         n_MV2c10_70_EventWeight_Light0_up;
  Float_t         n_MV2c10_70_EventWeight_Light0_down;
  Float_t         n_MV2c10_70_EventWeight_Light1_up;
  Float_t         n_MV2c10_70_EventWeight_Light1_down;
  Float_t         n_MV2c10_70_EventWeight_Light2_up;
  Float_t         n_MV2c10_70_EventWeight_Light2_down;
  Float_t         n_MV2c10_70_EventWeight_Light3_up;
  Float_t         n_MV2c10_70_EventWeight_Light3_down;
  Float_t         n_MV2c10_70_EventWeight_Light4_up;
  Float_t         n_MV2c10_70_EventWeight_Light4_down;
  Float_t         n_MV2c10_70_EventWeight_Light5_up;
  Float_t         n_MV2c10_70_EventWeight_Light5_down;
  Float_t         n_MV2c10_70_EventWeight_Light6_up;
  Float_t         n_MV2c10_70_EventWeight_Light6_down;
  Float_t         n_MV2c10_70_EventWeight_Light7_up;
  Float_t         n_MV2c10_70_EventWeight_Light7_down;
  Float_t         n_MV2c10_70_EventWeight_Light8_up;
  Float_t         n_MV2c10_70_EventWeight_Light8_down;
  Float_t         n_MV2c10_70_EventWeight_Light9_up;
  Float_t         n_MV2c10_70_EventWeight_Light9_down;
  Float_t         n_MV2c10_70_EventWeight_Light10_up;
  Float_t         n_MV2c10_70_EventWeight_Light10_down;
  Float_t         n_MV2c10_70_EventWeight_Light11_up;
  Float_t         n_MV2c10_70_EventWeight_Light11_down;
  Float_t         n_MV2c10_70_EventWeight_Light12_up;
  Float_t         n_MV2c10_70_EventWeight_Light12_down;
  Float_t         n_MV2c10_70_EventWeight_Light13_up;
  Float_t         n_MV2c10_70_EventWeight_Light13_down;
  Float_t         n_MV2c10_70_EventWeight_Light14_up;
  Float_t         n_MV2c10_70_EventWeight_Light14_down;
  Float_t         n_MV2c10_70_EventWeight_Light15_up;
  Float_t         n_MV2c10_70_EventWeight_Light15_down;
  Float_t         n_MV2c10_70_EventWeight_extrapolation_up;
  Float_t         n_MV2c10_70_EventWeight_extrapolation_down;
  Float_t         n_MV2c10_70_EventWeight_extrapolation_from_charm_up;
  Float_t         n_MV2c10_70_EventWeight_extrapolation_from_charm_down;
  Double_t        n_JVT_EventWeight_UP;
  Double_t        n_JVT_EventWeight_DOWN;
  Float_t         n_lepSFTrigLoose;
  Float_t         n_lepSFTrigTight;//nominal
  Float_t         n_lepSFObjLoose;
  Float_t         n_lepSFObjTight;//nominal
  Float_t         n_lepSFTrigTight_EL_SF_Trigger_UP;
  Float_t         n_lepSFTrigTight_EL_SF_Trigger_DOWN;
  Float_t         n_lepSFObjTight_EL_SF_Reco_UP;
  Float_t         n_lepSFObjTight_EL_SF_Reco_DOWN;
  Float_t         n_lepSFObjTight_EL_SF_ID_UP;
  Float_t         n_lepSFObjTight_EL_SF_ID_DOWN;
  Float_t         n_lepSFObjTight_EL_SF_Isol_UP;
  Float_t         n_lepSFObjTight_EL_SF_Isol_DOWN;
  Float_t         n_lepSFTrigTight_MU_SF_Trigger_STAT_UP;
  Float_t         n_lepSFTrigTight_MU_SF_Trigger_STAT_DOWN;
  Float_t         n_lepSFTrigTight_MU_SF_Trigger_SYST_UP;
  Float_t         n_lepSFTrigTight_MU_SF_Trigger_SYST_DOWN;
  Float_t         n_lepSFObjTight_MU_SF_ID_STAT_UP;
  Float_t         n_lepSFObjTight_MU_SF_ID_STAT_DOWN;
  Float_t         n_lepSFObjTight_MU_SF_ID_SYST_UP;
  Float_t         n_lepSFObjTight_MU_SF_ID_SYST_DOWN;
  Float_t         n_lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP;
  Float_t         n_lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN;
  Float_t         n_lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP;
  Float_t         n_lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN;
  Float_t         n_lepSFObjTight_MU_SF_Isol_STAT_UP;
  Float_t         n_lepSFObjLoose_MU_SF_Isol_STAT_DOWN;
  Float_t         n_lepSFObjTight_MU_SF_Isol_STAT_DOWN;
  Float_t         n_lepSFObjTight_MU_SF_Isol_SYST_UP;
  Float_t         n_lepSFObjTight_MU_SF_Isol_SYST_DOWN;
  Float_t         n_lepSFObjTight_MU_SF_TTVA_STAT_UP;
  Float_t         n_lepSFObjTight_MU_SF_TTVA_STAT_DOWN;
  Float_t         n_lepSFObjTight_MU_SF_TTVA_SYST_UP;
  Float_t         n_lepSFObjTight_MU_SF_TTVA_SYST_DOWN;
  Double_t        n_PDF_UP; 
  Double_t        n_PDF_DOWN; 
  tree->Branch("pileupEventWeight_UP"                                 ,&n_pileupEventWeight_UP);                                 
  tree->Branch("pileupEventWeight_DOWN"                               ,&n_pileupEventWeight_DOWN);
  tree->Branch("MV2c10_70_EventWeight_B0_up"                          ,&n_MV2c10_70_EventWeight_B0_up);
  tree->Branch("MV2c10_70_EventWeight_B0_down"                        ,&n_MV2c10_70_EventWeight_B0_down);
  tree->Branch("MV2c10_70_EventWeight_B1_up"                          ,&n_MV2c10_70_EventWeight_B1_up);
  tree->Branch("MV2c10_70_EventWeight_B1_down"                        ,&n_MV2c10_70_EventWeight_B1_down);
  tree->Branch("MV2c10_70_EventWeight_B2_up"                          ,&n_MV2c10_70_EventWeight_B2_up);
  tree->Branch("MV2c10_70_EventWeight_B2_down"                        ,&n_MV2c10_70_EventWeight_B2_down);
  tree->Branch("MV2c10_70_EventWeight_B3_up"                          ,&n_MV2c10_70_EventWeight_B3_up);
  tree->Branch("MV2c10_70_EventWeight_B3_down"                        ,&n_MV2c10_70_EventWeight_B3_down);
  tree->Branch("MV2c10_70_EventWeight_B4_up"                          ,&n_MV2c10_70_EventWeight_B4_up);
  tree->Branch("MV2c10_70_EventWeight_B4_down"                        ,&n_MV2c10_70_EventWeight_B4_down);
  tree->Branch("MV2c10_70_EventWeight_B5_up"                          ,&n_MV2c10_70_EventWeight_B5_up);
  tree->Branch("MV2c10_70_EventWeight_B5_down"                        ,&n_MV2c10_70_EventWeight_B5_down);
  tree->Branch("MV2c10_70_EventWeight_C0_up"                          ,&n_MV2c10_70_EventWeight_C0_up);
  tree->Branch("MV2c10_70_EventWeight_C0_down"                        ,&n_MV2c10_70_EventWeight_C0_down);
  tree->Branch("MV2c10_70_EventWeight_C1_up"                          ,&n_MV2c10_70_EventWeight_C1_up);
  tree->Branch("MV2c10_70_EventWeight_C1_down"                        ,&n_MV2c10_70_EventWeight_C1_down);
  tree->Branch("MV2c10_70_EventWeight_C2_up"                          ,&n_MV2c10_70_EventWeight_C2_up);
  tree->Branch("MV2c10_70_EventWeight_C2_down"                        ,&n_MV2c10_70_EventWeight_C2_down);
  tree->Branch("MV2c10_70_EventWeight_C3_up"                          ,&n_MV2c10_70_EventWeight_C3_up);
  tree->Branch("MV2c10_70_EventWeight_C3_down"                        ,&n_MV2c10_70_EventWeight_C3_down);
  tree->Branch("MV2c10_70_EventWeight_Light0_up"                      ,&n_MV2c10_70_EventWeight_Light0_up);
  tree->Branch("MV2c10_70_EventWeight_Light0_down"                    ,&n_MV2c10_70_EventWeight_Light0_down);
  tree->Branch("MV2c10_70_EventWeight_Light1_up"                      ,&n_MV2c10_70_EventWeight_Light1_up);
  tree->Branch("MV2c10_70_EventWeight_Light1_down"                    ,&n_MV2c10_70_EventWeight_Light1_down);
  tree->Branch("MV2c10_70_EventWeight_Light2_up"                      ,&n_MV2c10_70_EventWeight_Light2_up);
  tree->Branch("MV2c10_70_EventWeight_Light2_down"                    ,&n_MV2c10_70_EventWeight_Light2_down);
  tree->Branch("MV2c10_70_EventWeight_Light3_up"                      ,&n_MV2c10_70_EventWeight_Light3_up);
  tree->Branch("MV2c10_70_EventWeight_Light3_down"                    ,&n_MV2c10_70_EventWeight_Light3_down);
  tree->Branch("MV2c10_70_EventWeight_Light4_up"                      ,&n_MV2c10_70_EventWeight_Light4_up);
  tree->Branch("MV2c10_70_EventWeight_Light4_down"                    ,&n_MV2c10_70_EventWeight_Light4_down);
  tree->Branch("MV2c10_70_EventWeight_Light5_up"                      ,&n_MV2c10_70_EventWeight_Light5_up);
  tree->Branch("MV2c10_70_EventWeight_Light5_down"                    ,&n_MV2c10_70_EventWeight_Light5_down);
  tree->Branch("MV2c10_70_EventWeight_Light6_up"                      ,&n_MV2c10_70_EventWeight_Light6_up);
  tree->Branch("MV2c10_70_EventWeight_Light6_down"                    ,&n_MV2c10_70_EventWeight_Light6_down);
  tree->Branch("MV2c10_70_EventWeight_Light7_up"                      ,&n_MV2c10_70_EventWeight_Light7_up);
  tree->Branch("MV2c10_70_EventWeight_Light7_down"                    ,&n_MV2c10_70_EventWeight_Light7_down);
  tree->Branch("MV2c10_70_EventWeight_Light8_up"                      ,&n_MV2c10_70_EventWeight_Light8_up);
  tree->Branch("MV2c10_70_EventWeight_Light8_down"                    ,&n_MV2c10_70_EventWeight_Light8_down);
  tree->Branch("MV2c10_70_EventWeight_Light9_up"                      ,&n_MV2c10_70_EventWeight_Light9_up);
  tree->Branch("MV2c10_70_EventWeight_Light9_down"                    ,&n_MV2c10_70_EventWeight_Light9_down);
  tree->Branch("MV2c10_70_EventWeight_Light10_up"                     ,&n_MV2c10_70_EventWeight_Light10_up);
  tree->Branch("MV2c10_70_EventWeight_Light10_down"                   ,&n_MV2c10_70_EventWeight_Light10_down);
  tree->Branch("MV2c10_70_EventWeight_Light11_up"                     ,&n_MV2c10_70_EventWeight_Light11_up);
  tree->Branch("MV2c10_70_EventWeight_Light11_down"                   ,&n_MV2c10_70_EventWeight_Light11_down);
  tree->Branch("MV2c10_70_EventWeight_Light12_up"                     ,&n_MV2c10_70_EventWeight_Light12_up);
  tree->Branch("MV2c10_70_EventWeight_Light12_down"                   ,&n_MV2c10_70_EventWeight_Light12_down);
  tree->Branch("MV2c10_70_EventWeight_Light13_up"                     ,&n_MV2c10_70_EventWeight_Light13_up);
  tree->Branch("MV2c10_70_EventWeight_Light13_down"                   ,&n_MV2c10_70_EventWeight_Light13_down);
  tree->Branch("MV2c10_70_EventWeight_Light14_up"                     ,&n_MV2c10_70_EventWeight_Light14_up);
  tree->Branch("MV2c10_70_EventWeight_Light14_down"                   ,&n_MV2c10_70_EventWeight_Light14_down);
  tree->Branch("MV2c10_70_EventWeight_Light15_up"                     ,&n_MV2c10_70_EventWeight_Light15_up);
  tree->Branch("MV2c10_70_EventWeight_Light15_down"                   ,&n_MV2c10_70_EventWeight_Light15_down);
  tree->Branch("MV2c10_70_EventWeight_extrapolation_up"               ,&n_MV2c10_70_EventWeight_extrapolation_up);
  tree->Branch("MV2c10_70_EventWeight_extrapolation_down"             ,&n_MV2c10_70_EventWeight_extrapolation_down);
  tree->Branch("MV2c10_70_EventWeight_extrapolation_from_charm_up"    ,&n_MV2c10_70_EventWeight_extrapolation_from_charm_up);
  tree->Branch("MV2c10_70_EventWeight_extrapolation_from_charm_down"  ,&n_MV2c10_70_EventWeight_extrapolation_from_charm_down);
  tree->Branch("JVT_EventWeight_UP"                                   ,&n_JVT_EventWeight_UP);
  tree->Branch("JVT_EventWeight_DOWN"                                 ,&n_JVT_EventWeight_DOWN);
  tree->Branch("lepSFTrigLoose"                                       ,&n_lepSFTrigLoose);
  tree->Branch("lepSFTrigTight"                                       ,&n_lepSFTrigTight);
  tree->Branch("lepSFObjLoose"                                        ,&n_lepSFObjLoose);
  tree->Branch("lepSFObjTight"                                        ,&n_lepSFObjTight);
  tree->Branch("lepSFTrigTight_EL_SF_Trigger_UP"                      ,&n_lepSFTrigTight_EL_SF_Trigger_UP);
  tree->Branch("lepSFTrigTight_EL_SF_Trigger_DOWN"                    ,&n_lepSFTrigTight_EL_SF_Trigger_DOWN);
  tree->Branch("lepSFObjTight_EL_SF_Reco_UP"                          ,&n_lepSFObjTight_EL_SF_Reco_UP);
  tree->Branch("lepSFObjTight_EL_SF_Reco_DOWN"                        ,&n_lepSFObjTight_EL_SF_Reco_DOWN);
  tree->Branch("lepSFObjTight_EL_SF_ID_UP"                            ,&n_lepSFObjTight_EL_SF_ID_UP);
  tree->Branch("lepSFObjTight_EL_SF_ID_DOWN"                          ,&n_lepSFObjTight_EL_SF_ID_DOWN);
  tree->Branch("lepSFObjTight_EL_SF_Isol_UP"                          ,&n_lepSFObjTight_EL_SF_Isol_UP);
  tree->Branch("lepSFObjTight_EL_SF_Isol_DOWN"                        ,&n_lepSFObjTight_EL_SF_Isol_DOWN);
  tree->Branch("lepSFTrigTight_MU_SF_Trigger_STAT_UP"                 ,&n_lepSFTrigTight_MU_SF_Trigger_STAT_UP);
  tree->Branch("lepSFTrigTight_MU_SF_Trigger_STAT_DOWN"               ,&n_lepSFTrigTight_MU_SF_Trigger_STAT_DOWN);
  tree->Branch("lepSFTrigTight_MU_SF_Trigger_SYST_UP"                 ,&n_lepSFTrigTight_MU_SF_Trigger_SYST_UP);
  tree->Branch("lepSFTrigTight_MU_SF_Trigger_SYST_DOWN"               ,&n_lepSFTrigTight_MU_SF_Trigger_SYST_DOWN);
  tree->Branch("lepSFObjTight_MU_SF_ID_STAT_UP"                       ,&n_lepSFObjTight_MU_SF_ID_STAT_UP);
  tree->Branch("lepSFObjTight_MU_SF_ID_STAT_DOWN"                     ,&n_lepSFObjTight_MU_SF_ID_STAT_DOWN);
  tree->Branch("lepSFObjTight_MU_SF_ID_SYST_UP"                       ,&n_lepSFObjTight_MU_SF_ID_SYST_UP);
  tree->Branch("lepSFObjTight_MU_SF_ID_SYST_DOWN"                     ,&n_lepSFObjTight_MU_SF_ID_SYST_DOWN);
  tree->Branch("lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP"                 ,&n_lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP);
  tree->Branch("lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN"               ,&n_lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN);
  tree->Branch("lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP"                 ,&n_lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP);
  tree->Branch("lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN"               ,&n_lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN);
  tree->Branch("lepSFObjTight_MU_SF_Isol_STAT_UP"                     ,&n_lepSFObjTight_MU_SF_Isol_STAT_UP);
  tree->Branch("lepSFObjLoose_MU_SF_Isol_STAT_DOWN"                   ,&n_lepSFObjLoose_MU_SF_Isol_STAT_DOWN);
  tree->Branch("lepSFObjTight_MU_SF_Isol_STAT_DOWN"                   ,&n_lepSFObjTight_MU_SF_Isol_STAT_DOWN);
  tree->Branch("lepSFObjTight_MU_SF_Isol_SYST_UP"                     ,&n_lepSFObjTight_MU_SF_Isol_SYST_UP);
  tree->Branch("lepSFObjTight_MU_SF_Isol_SYST_DOWN"                   ,&n_lepSFObjTight_MU_SF_Isol_SYST_DOWN);
  tree->Branch("lepSFObjTight_MU_SF_TTVA_STAT_UP"                     ,&n_lepSFObjTight_MU_SF_TTVA_STAT_UP);
  tree->Branch("lepSFObjTight_MU_SF_TTVA_STAT_DOWN"                   ,&n_lepSFObjTight_MU_SF_TTVA_STAT_DOWN);
  tree->Branch("lepSFObjTight_MU_SF_TTVA_SYST_UP"                     ,&n_lepSFObjTight_MU_SF_TTVA_SYST_UP);
  tree->Branch("lepSFObjTight_MU_SF_TTVA_SYST_DOWN"                   ,&n_lepSFObjTight_MU_SF_TTVA_SYST_DOWN);
  tree->Branch("PDF_UP", &n_PDF_UP);
  tree->Branch("PDF_DOWN", &n_PDF_DOWN);
  
  TString component;
  tree->Branch("m_ll",&m_ll);
  tree->Branch("m_jj",&m_jj);
  tree->Branch("m_j1j2",&m_j1j2);
  tree->Branch("m_j1j3",&m_j1j3);
  tree->Branch("m_j2j3",&m_j2j3);
  tree->Branch("MET",&MET);
  tree->Branch("pt_leadinglepton",&pt_leadinglepton);
  tree->Branch("pt_sublepton",&pt_sublepton);
  tree->Branch("eta_leadinglepton",&eta_leadinglepton);
  tree->Branch("eta_sublepton",&eta_sublepton);
  tree->Branch("pt_j1",&pt_j1);
  tree->Branch("pt_j2",&pt_j2);
  tree->Branch("m_jj_w",&m_jj_w);
  tree->Branch("m_l1jj",&m_l1jj);
  tree->Branch("m_all",&m_all);
  tree->Branch("pt_sum",&pt_sum);
  tree->Branch("pt_vecsum",&pt_vecsum);
  tree->Branch("mindR_l1j",&mindR_l1j);
  tree->Branch("m_l1j",&m_l1j);
  tree->Branch("mindR_l2j",&mindR_l2j);
  tree->Branch("RMS",&RMS);
  tree->Branch("m_l2j",&m_l2j);
  tree->Branch("Mt",&Mt);
  tree->Branch("weight",&weight);
  tree->Branch("channel",&channel);
  tree->Branch("category",&n_category);
  tree->Branch("component",&component);
  tree->Branch("numOfjet",&numOfjet);
  tree->Branch("ChargeIDBDTTight_0",&ChargeIDBDTTight_0);
  tree->Branch("ChargeIDBDTTight_1",&ChargeIDBDTTight_1);
  tree->Branch("PromptLeptonIso_TagWeight_0",&PromptLeptonIso_TagWeight_0);
  tree->Branch("PromptLeptonIso_TagWeight_1",&PromptLeptonIso_TagWeight_1);
  tree->Branch("truthOrigin_0",&n_truthOrigin_0);
  tree->Branch("truthOrigin_1",&n_truthOrigin_1);
  Long64_t nentries = fChain->GetEntries();
  cout<<"total evts: "<<nentries<<endl;
  const LHAPDF::PDFSet ct10_set("PDF4LHC15_nlo_30");
  const std::vector<LHAPDF::PDF*> pdfs = ct10_set.mkPDFs();
  for(Long64_t jentry=0; jentry<nentries;jentry++){
      fChain->GetEntry(jentry);
      if(jentry%500000==0)
       cout<<jentry<<" evts analyzed"<<endl;
      //determine common selection
      if(!dilep_type)continue;//type must be defined!!!otherwise loose objects not passing OB will enter!
      
      if( (config.Contains("Qmis")||CRSel.Contains("CR")) && (total_charge!=0))continue;//reject SS
      if( ((!config.Contains("Qmis"))&&(!CRSel.Contains("CR"))) && (abs(total_charge)!=2)) continue; //reject OS

      //to reject bjets
      if( (CRSel=="preselection"||CRSel=="ZjetsCR") && nJets_OR_MV2c10_70>0)continue;
      if(CRSel=="ttbarCR" && nJets_OR_MV2c10_70<2) continue;

      if(MET_RefFinal_et<10000)continue; 
      if( (config.Contains("2jets") && CRSel!="ZjetsCR" && CRSel!="ttbarCR") && nJets_OR<2)continue;
      if(CRSel=="ZjetsCR" && nJets_OR<1) continue;
      if( (config.Contains("3jets") && CRSel!="ZjetsCR" && CRSel!="ttbarCR") && nJets_OR<3)continue;
      Char_t lep_isQMisID_0, lep_isQMisID_1;
      lep_isQMisID_0=(lep_truthPdgId_0+lep_ID_0==0)?true : false;
      lep_isQMisID_1=(lep_truthPdgId_1+lep_ID_1==0)?true : false;
      Char_t matchDLTll01,lep_isTrigMatchAny_0, lep_isTrigMatchAny_1;
      matchDLTll01=lep_isTrigMatchDLT_0&&lep_isTrigMatchDLT_1&&max(lep_Pt_0,lep_Pt_1)>(abs(lep_ID_0*lep_ID_1)==169)*((RunYear==2015)*19e3+(RunYear==2016)*23e3);
      lep_isTrigMatchAny_0=(lep_isTrigMatch_0||matchDLTll01)?true:false;
      lep_isTrigMatchAny_1=(lep_isTrigMatch_1||matchDLTll01)?true:false;
      //retreive objects
      vector<Lepton>electron; vector<Lepton>lepton;
      vector<TLorentzVector>electronVec; vector<TLorentzVector>leptonVec;
      vector<Lepton>muon; vector<TLorentzVector>muonVec;

      TLorentzVector tmp;
      tmp.SetPtEtaPhiM(lep_Pt_0,lep_Eta_0,lep_Phi_0,0); leptonVec.push_back(tmp);
      Lepton tmplepton1(lep_ID_0,lep_Pt_0,lep_Eta_0,lep_Phi_0,lep_isTightLH_0,lep_isTight_0,lep_isolationFixedCutTight_0,
                       lep_isolationFixedCutTightTrackOnly_0,lep_isTrigMatchAny_0,lep_truthOrigin_0,lep_truthType_0,lep_isTruthMatched_0,
                       lep_isQMisID_0,lep_sigd0PV_0,lep_Z0SinTheta_0,lep_topoEtcone20_0,lep_ptVarcone20_0,lep_isolationLoose_0,
                       lep_ChargeIDBDTTight_0,lep_PromptLeptonIso_TagWeight_0,lep_isolationLooseTrackOnly_0);
      lepton.push_back(tmplepton1);
      if(fabs(lep_ID_0)==11){electron.push_back(tmplepton1); electronVec.push_back(tmp);}
      if(fabs(lep_ID_0)==13){muon.push_back(tmplepton1); muonVec.push_back(tmp);}

      tmp.SetPtEtaPhiM(lep_Pt_1,lep_Eta_1,lep_Phi_1,0); leptonVec.push_back(tmp);
      Lepton tmplepton2(lep_ID_1,lep_Pt_1,lep_Eta_1,lep_Phi_1,lep_isTightLH_1,lep_isTight_1,lep_isolationFixedCutTight_1,
                        lep_isolationFixedCutTightTrackOnly_1,lep_isTrigMatchAny_1,lep_truthOrigin_1,lep_truthType_1,lep_isTruthMatched_1,
                        lep_isQMisID_1,lep_sigd0PV_1,lep_Z0SinTheta_1,lep_topoEtcone20_1,lep_ptVarcone20_1,lep_isolationLoose_1,
                       lep_ChargeIDBDTTight_1,lep_PromptLeptonIso_TagWeight_1,lep_isolationLooseTrackOnly_1);
      lepton.push_back(tmplepton2);
      if(fabs(lep_ID_1)==11){electron.push_back(tmplepton2); electronVec.push_back(tmp);}
      if(fabs(lep_ID_1)==13){muon.push_back(tmplepton2); muonVec.push_back(tmp);}
      //
      vector<TLorentzVector>jetVec;
      for(unsigned int i=0;i<jet_pt->size();i++){
          float pt=((*jet_pt))[i],phi=((*jet_phi))[i],eta=((*jet_eta))[i],E=(*jet_E)[i];
          if((*jet_passOR)[i]){
             TLorentzVector tmp;tmp.SetPtEtaPhiE(pt,eta,phi,E);
             jetVec.push_back(tmp);
          }
      }
      TLorentzVector metVec;
      if(MET_RefFinal_et)metVec.SetPtEtaPhiE(MET_RefFinal_et,0,MET_RefFinal_phi,MET_RefFinal_et);
      else metVec.SetPtEtaPhiE(0,0,0,0);
      //divide two leptons into id+id, id+anti-id,
      //for id+id, tag first one leading lepton based on pt; for id+anti-id, tag fisrt one id, second anti-id
      if(lepton.size()!=2)continue;
      Float_t lep_matchTrig_pt=0;
      Int_t category=0; //ee:1, e+antiid e: 2; mm:11, m+antiid m:12; em: 21, antiid e + m:22, e + antiid m: 23
      if(LeptonClassifier(datasetType,&(lepton[0]))==1 && LeptonClassifier(datasetType,&(lepton[1]))==1 &&
         (lepton[0].matched_Trigger==1 || lepton[1].matched_Trigger==1)){
          Lepton tmplepton=lepton[0];
          if(lepton[0].pt<lepton[1].pt){tmplepton=lepton[0]; lepton[0]=lepton[1]; lepton[1]=tmplepton;}
          if(electron.size()==2)category=1;
          if(muon.size()==2)category=11;
          if(electron.size()==1&&muon.size()==1)category=21;
      }
      if(LeptonClassifier(datasetType,&(lepton[1]))==1&&lepton[1].matched_Trigger==1&&LeptonClassifier(datasetType,&(lepton[0]))==2){
         Lepton tmplepton=lepton[0];
         tmplepton=lepton[0]; lepton[0]=lepton[1]; lepton[1]=tmplepton;
         if(electron.size()==2)category=2;
         if(muon.size()==2)category=12;
         if(fabs(lepton[0].ID)==13&&fabs(lepton[1].ID)==11)category=22;
         if(fabs(lepton[0].ID)==11&&fabs(lepton[1].ID==13))category=23;
      }
      if(LeptonClassifier(datasetType,&(lepton[0]))==1&&lepton[0].matched_Trigger==1&&LeptonClassifier(datasetType,&(lepton[1]))==2){
         if(electron.size()==2)category=2;
         if(muon.size()==2)category=12;
         if(fabs(lepton[0].ID)==13&&fabs(lepton[1].ID)==11)category=22;
         if(fabs(lepton[0].ID)==11&&fabs(lepton[1].ID==13))category=23;
      }
      //define common selection
      bool common_selection;
      common_selection=(lep_Pt_0>30000 && lep_Pt_1>20000) && (leptonVec[0] + leptonVec[1]).M()>15000 ;
      if(!common_selection)continue;
      //if( (category==11 || category==12 ) && lep_Pt_1<25000) continue;
      //define Z veto, which can be used in fake estimation
      bool applyZveto;
      if(CRSel=="preselection")applyZveto=fabs((leptonVec[0] + leptonVec[1]).M()-91200)<10000;
      if(CRSel=="ttbarCR") applyZveto=fabs((leptonVec[0] + leptonVec[1]).M()-91200)<20000;
      if(CRSel=="ZjetsCR") applyZveto=fabs((leptonVec[0] + leptonVec[1]).M()-91200)>45000;
      if((category==2||category==1)&&CRSel=="preselection"&&applyZveto)continue;
      if(CRSel!="preselection" && (category==1||category==11) &&applyZveto) continue;
      //if((category==2||category==1)&&fabs((leptonVec[0] + leptonVec[1]).M()-91200)<10000)cout<<".........."<<endl;
      //read QmisID rates
      weight=n_weight_tight;
      //weight=n_weight_tight*mcWeightOrg*pileupEventWeight_090*lepSFObjTight*lepSFTrigTight*JVT_EventWeight*SherpaNJetWeight*MV2c10_70_EventWeight;//0.0022 only for HSS
      if(dataset.Contains("S135")) weight*=10*500*0.0135;
      if(dataset.Contains("S145")) weight*=10*500*0.03454;
      if(dataset.Contains("S155")) weight*=10*500*0.06049;
      if(dataset.Contains("S165")) weight*=10*500*0.08842;
      if((category==1||category==21) && config.Contains("QmisID")){//only assign QmisID rates for OS events
          Double_t temp_weight=1.0;
         if(category==1){
            double temp_pt_1=electron[0].pt/1000.;
            double temp_pt_2=electron[1].pt/1000.;
            if(temp_pt_1>hist_QmisID->GetYaxis()->GetXmax()) temp_pt_1=hist_QmisID->GetYaxis()->GetXmax()*0.999;
            if(temp_pt_2>hist_QmisID->GetYaxis()->GetXmax()) temp_pt_2=hist_QmisID->GetYaxis()->GetXmax()*0.999;
            double fake_1=hist_QmisID->GetBinContent(hist_QmisID->FindBin(fabs(electron[0].eta),temp_pt_1));
            double fake_2=hist_QmisID->GetBinContent(hist_QmisID->FindBin(fabs(electron[1].eta),temp_pt_2));
            temp_weight=(fake_1+fake_2-2*fake_1*fake_2)/(1-fake_1-fake_2+2*fake_1*fake_2);
         }
         if(category==21){
            double temp_pt_1=electron[0].pt/1000.;
            if(temp_pt_1>hist_QmisID->GetYaxis()->GetXmax()) temp_pt_1=hist_QmisID->GetYaxis()->GetXmax()*0.999;
            double fake_1=hist_QmisID->GetBinContent(hist_QmisID->FindBin(fabs(electron[0].eta),temp_pt_1));
            temp_weight=fake_1/(1.0-fake_1);
         }
         weight=n_weight_tight*temp_weight;
      }
      //read fake factor
      if(config.Contains("FFApp")){
         if(category==2 || category==22){//e+antiid e, antiid e + m
            double temp_pt=fabs(lepton[1].pt)/1000.;
            if(temp_pt>=1000) temp_pt=999;
            //double temp_weight=hist_ff_eta_antiidelectron->GetBinContent(hist_ff_eta_antiidelectron->FindBin(temp_pt));
            double temp_weight=ff_ele;
            weight=n_weight_tight*temp_weight;
         }//end of 2/22 cate
         if(category==12 || category==23){//m+antiid m, e+antiid m
            double temp_pt=fabs(lepton[1].pt)/1000.;
            if(temp_pt>=1000) temp_pt=999;
            //double temp_weight=hist_ff_eta_antiidmuon->GetBinContent(hist_ff_eta_antiidmuon->FindBin(temp_pt));
            double temp_weight=ff_mu;
            weight=n_weight_tight*temp_weight;
         }//end of 12/23 cate
      }
      if(config.Contains("FFQmis")&&category==23){
         double temp_pt_1=electron[0].pt/1000.;
         if(temp_pt_1>hist_QmisID->GetYaxis()->GetXmax()) temp_pt_1=hist_QmisID->GetYaxis()->GetXmax()*0.999;
         double fake_1=hist_QmisID->GetBinContent(hist_QmisID->FindBin(fabs(electron[0].eta),temp_pt_1));
         Double_t temp_weight=fake_1/(1.0-fake_1);
         double temp_pt=fabs(lepton[1].pt)/1000.;
         if(temp_pt>=1000) temp_pt=999;
         //double temp_ff=hist_ff_eta_antiidmuon->GetBinContent(hist_ff_eta_antiidmuon->FindBin(temp_pt));
         double temp_ff=ff_mu;
         weight=n_weight_tight*temp_weight*temp_ff;
      }
      //determine compoment
      Float_t Lumi=36.1;
      if(config.Contains("FFApp")){
         component="fake";
         if(dataset!="datacombined") weight=-weight*Lumi;
         else weight=weight;
      }
      if(config.Contains("FFQmis")){
         component="fake";
         weight=-weight;
      }
      if(config.Contains("nominal")){
         if(dataset=="datacombined") { component="data"; weight=weight;}
         else { component=dataset; weight=weight*Lumi;}
      }
      if(config.Contains("QmisID")){ component="QmisID"; weight=weight;}

      numOfjet=nJets_OR;
      m_ll=(leptonVec[0] + leptonVec[1]).M()/1000.;
      pt_j1=(*jet_pt)[0]/1000.;
      pt_j2=(*jet_pt)[1]/1000.;
      m_jj=f_m_jj(&jetVec)/1000.;
      m_j1j2=f_m_j1j2(&jetVec)/1000.;
      if(config.Contains("3jets")) {
         m_j1j3=f_m_j1j3(&jetVec)/1000.;
         m_j2j3=f_m_j2j3(&jetVec)/1000.;
      }
      MET=MET_RefFinal_et/1000.;
      m_all=f_m_all(&leptonVec,&jetVec,&metVec)/1000.;
      Mt=f_Mt(&leptonVec,&jetVec,&metVec)/1000.;
      pt_vecsum=f_pt_vecsum(&leptonVec,&jetVec,&metVec)/1000.;
      pt_sum=f_pt_sum(&leptonVec,&jetVec,&metVec)/1000.;
      m_l1jj=f_m_l1jj(&leptonVec,&jetVec)/1000.;
      m_jj_w=f_m_jj_w(&leptonVec,&jetVec)/1000.;
      mindR_l1j=f_mindR_l1j(&leptonVec,&jetVec);
      mindR_l2j=f_mindR_l2j(&leptonVec,&jetVec);
      m_l1j=f_m_l1j(&leptonVec,&jetVec)/1000.;
      m_l2j=f_m_l2j(&leptonVec,&jetVec)/1000.;
      RMS=f_RMS(&leptonVec,&jetVec,&metVec);
      ChargeIDBDTTight_0=lep_ChargeIDBDTTight_0;
      ChargeIDBDTTight_1=lep_ChargeIDBDTTight_1;
      PromptLeptonIso_TagWeight_0=lep_PromptLeptonIso_TagWeight_0;
      PromptLeptonIso_TagWeight_1=lep_PromptLeptonIso_TagWeight_1;
      n_truthOrigin_0=lep_truthOrigin_0;
      n_truthOrigin_1=lep_truthOrigin_1;
      //retrieve signal PDF uncertainty
      //const LHAPDF::PDFSet ct10_set("PDF4LHC15_nlo_30");
      //const std::vector<LHAPDF::PDF*> pdfs = ct10_set.mkPDFs(); // pointers to PDF set members
      std::vector<double> pdfweights;
      for(size_t imem = 0; imem <= ct10_set.size()-1; imem++) {
           pdfweights.push_back( LHAPDF::weightxxQ2( (*m_mcevt_pdf_PDGID1)[0], (*m_mcevt_pdf_PDGID2)[0], (*m_mcevt_pdf_X1)[0], 
                           (*m_mcevt_pdf_X2)[0], (*m_mcevt_pdf_Q)[0], pdfs[0], pdfs[imem] )  ); 
           // one event weight for each error in the set including the nominal
      }
        // for each bin in each distribution do
      std::vector<double> bin_contents = pdfweights; // bin content for each error in the set including the nominal
      const LHAPDF::PDFUncertainty ct10_prediction = ct10_set.uncertainty(bin_contents, -1); // -1 => same C.L. as set
      double pdfnominal_value = ct10_prediction.central;
      double pdfuncertainty_up = ct10_prediction.errplus;
      double pdfuncertainty_down =  ct10_prediction.errminus;  
      n_PDF_UP = pdfnominal_value + pdfuncertainty_up;
      n_PDF_DOWN = pdfnominal_value - pdfuncertainty_down;
      //cout<<"pdf uncer. "<<pdfnominal_value<<" "<<pdfuncertainty_up<<" "<<pdfuncertainty_down<<endl;
      //if(doSystematics && SystematicType=="EventWeight"){
      if(doSystematics ){
         
         n_pileupEventWeight_UP=                                       pileupEventWeight_UP;
         n_pileupEventWeight_DOWN=                                     pileupEventWeight_DOWN;
         n_MV2c10_70_EventWeight_B0_up=                                MV2c10_70_EventWeight_B0_up;
         n_MV2c10_70_EventWeight_B0_down=                              MV2c10_70_EventWeight_B0_down;
         n_MV2c10_70_EventWeight_B1_up=                                MV2c10_70_EventWeight_B1_up;
         n_MV2c10_70_EventWeight_B1_down=                              MV2c10_70_EventWeight_B1_down;
         n_MV2c10_70_EventWeight_B2_up=                                MV2c10_70_EventWeight_B2_up;
         n_MV2c10_70_EventWeight_B2_down=                              MV2c10_70_EventWeight_B2_down;
         n_MV2c10_70_EventWeight_B3_up=                                MV2c10_70_EventWeight_B3_up;
         n_MV2c10_70_EventWeight_B3_down=                              MV2c10_70_EventWeight_B3_down;
         n_MV2c10_70_EventWeight_B4_up=                                MV2c10_70_EventWeight_B4_up;
         n_MV2c10_70_EventWeight_B4_down=                              MV2c10_70_EventWeight_B4_down;
         n_MV2c10_70_EventWeight_B5_up=                                MV2c10_70_EventWeight_B5_up;
         n_MV2c10_70_EventWeight_B5_down=                              MV2c10_70_EventWeight_B5_down;
         n_MV2c10_70_EventWeight_C0_up=                                MV2c10_70_EventWeight_C0_up;
         n_MV2c10_70_EventWeight_C0_down=                              MV2c10_70_EventWeight_C0_down;
         n_MV2c10_70_EventWeight_C1_up=                                MV2c10_70_EventWeight_C1_up;
         n_MV2c10_70_EventWeight_C1_down=                              MV2c10_70_EventWeight_C1_down;
         n_MV2c10_70_EventWeight_C2_up=                                MV2c10_70_EventWeight_C2_up;
         n_MV2c10_70_EventWeight_C2_down=                              MV2c10_70_EventWeight_C2_down;
         n_MV2c10_70_EventWeight_C3_up=                                MV2c10_70_EventWeight_C3_up;
         n_MV2c10_70_EventWeight_C3_down=                              MV2c10_70_EventWeight_C3_down;
         n_MV2c10_70_EventWeight_Light0_up=                            MV2c10_70_EventWeight_Light0_up;
         n_MV2c10_70_EventWeight_Light0_down=                          MV2c10_70_EventWeight_Light0_down;
         n_MV2c10_70_EventWeight_Light1_up=                            MV2c10_70_EventWeight_Light1_up;
         n_MV2c10_70_EventWeight_Light1_down=                          MV2c10_70_EventWeight_Light1_down;
         n_MV2c10_70_EventWeight_Light2_up=                            MV2c10_70_EventWeight_Light2_up;
         n_MV2c10_70_EventWeight_Light2_down=                          MV2c10_70_EventWeight_Light2_down;
         n_MV2c10_70_EventWeight_Light3_up=                            MV2c10_70_EventWeight_Light3_up;
         n_MV2c10_70_EventWeight_Light3_down=                          MV2c10_70_EventWeight_Light3_down;
         n_MV2c10_70_EventWeight_Light4_up=                            MV2c10_70_EventWeight_Light4_up;
         n_MV2c10_70_EventWeight_Light4_down=                          MV2c10_70_EventWeight_Light4_down;
         n_MV2c10_70_EventWeight_Light5_up=                            MV2c10_70_EventWeight_Light5_up;
         n_MV2c10_70_EventWeight_Light5_down=                          MV2c10_70_EventWeight_Light5_down;
         n_MV2c10_70_EventWeight_Light6_up=                            MV2c10_70_EventWeight_Light6_up;
         n_MV2c10_70_EventWeight_Light6_down=                          MV2c10_70_EventWeight_Light6_down;
         n_MV2c10_70_EventWeight_Light7_up=                            MV2c10_70_EventWeight_Light7_up;
         n_MV2c10_70_EventWeight_Light7_down=                          MV2c10_70_EventWeight_Light7_down;
         n_MV2c10_70_EventWeight_Light8_up=                            MV2c10_70_EventWeight_Light8_up;
         n_MV2c10_70_EventWeight_Light8_down=                          MV2c10_70_EventWeight_Light8_down;
         n_MV2c10_70_EventWeight_Light9_up=                            MV2c10_70_EventWeight_Light9_up;
         n_MV2c10_70_EventWeight_Light9_down=                          MV2c10_70_EventWeight_Light9_down;
         n_MV2c10_70_EventWeight_Light10_up=                           MV2c10_70_EventWeight_Light10_up;
         n_MV2c10_70_EventWeight_Light10_down=                         MV2c10_70_EventWeight_Light10_down;
         n_MV2c10_70_EventWeight_Light11_up=                           MV2c10_70_EventWeight_Light11_up;
         n_MV2c10_70_EventWeight_Light11_down=                         MV2c10_70_EventWeight_Light11_down;
         n_MV2c10_70_EventWeight_Light12_up=                           MV2c10_70_EventWeight_Light12_up;
         n_MV2c10_70_EventWeight_Light12_down=                         MV2c10_70_EventWeight_Light12_down;
         n_MV2c10_70_EventWeight_Light13_up=                           MV2c10_70_EventWeight_Light13_up;
         n_MV2c10_70_EventWeight_Light13_down=                         MV2c10_70_EventWeight_Light13_down;
         n_MV2c10_70_EventWeight_Light14_up=                           MV2c10_70_EventWeight_Light14_up;
         n_MV2c10_70_EventWeight_Light14_down=                         MV2c10_70_EventWeight_Light14_down;
         n_MV2c10_70_EventWeight_Light15_up=                           MV2c10_70_EventWeight_Light15_up;
         n_MV2c10_70_EventWeight_Light15_down=                         MV2c10_70_EventWeight_Light15_down;
         n_MV2c10_70_EventWeight_extrapolation_up=                     MV2c10_70_EventWeight_extrapolation_up;
         n_MV2c10_70_EventWeight_extrapolation_down=                   MV2c10_70_EventWeight_extrapolation_down;
         n_MV2c10_70_EventWeight_extrapolation_from_charm_up=          MV2c10_70_EventWeight_extrapolation_from_charm_up;
         n_MV2c10_70_EventWeight_extrapolation_from_charm_down=        MV2c10_70_EventWeight_extrapolation_from_charm_down;
         n_JVT_EventWeight_UP=                                         JVT_EventWeight_UP;
         n_JVT_EventWeight_DOWN=                                       JVT_EventWeight_DOWN;
         n_lepSFTrigLoose=                                             lepSFTrigLoose;
         n_lepSFTrigTight=                                             lepSFTrigTight;
         n_lepSFObjLoose=                                              lepSFObjLoose;
         n_lepSFObjTight=                                              lepSFObjTight;
         n_lepSFTrigTight_EL_SF_Trigger_UP=                            lepSFTrigTight_EL_SF_Trigger_UP;
         n_lepSFTrigTight_EL_SF_Trigger_DOWN=                          lepSFTrigTight_EL_SF_Trigger_DOWN;
         n_lepSFObjTight_EL_SF_Reco_UP=                                lepSFObjTight_EL_SF_Reco_UP;
         n_lepSFObjTight_EL_SF_Reco_DOWN=                              lepSFObjTight_EL_SF_Reco_DOWN;
         n_lepSFObjTight_EL_SF_ID_UP=                                  lepSFObjTight_EL_SF_ID_UP;
         n_lepSFObjTight_EL_SF_ID_DOWN=                                lepSFObjTight_EL_SF_ID_DOWN;
         n_lepSFObjTight_EL_SF_Isol_UP=                                lepSFObjTight_EL_SF_Isol_UP;
         n_lepSFObjTight_EL_SF_Isol_DOWN=                              lepSFObjTight_EL_SF_Isol_DOWN;
         n_lepSFTrigTight_MU_SF_Trigger_STAT_UP=                       lepSFTrigTight_MU_SF_Trigger_STAT_UP;
         n_lepSFTrigTight_MU_SF_Trigger_STAT_DOWN=                     lepSFTrigTight_MU_SF_Trigger_STAT_DOWN;
         n_lepSFTrigTight_MU_SF_Trigger_SYST_UP=                       lepSFTrigTight_MU_SF_Trigger_SYST_UP;
         n_lepSFTrigTight_MU_SF_Trigger_SYST_DOWN=                     lepSFTrigTight_MU_SF_Trigger_SYST_DOWN;
         n_lepSFObjTight_MU_SF_ID_STAT_UP=                             lepSFObjTight_MU_SF_ID_STAT_UP;
         n_lepSFObjTight_MU_SF_ID_STAT_DOWN=                           lepSFObjTight_MU_SF_ID_STAT_DOWN;
         n_lepSFObjTight_MU_SF_ID_SYST_UP=                             lepSFObjTight_MU_SF_ID_SYST_UP;
         n_lepSFObjTight_MU_SF_ID_SYST_DOWN=                           lepSFObjTight_MU_SF_ID_SYST_DOWN;
         n_lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP=                       lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP;
         n_lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN=                     lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN;
         n_lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP=                       lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP;
         n_lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN=                     lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN;
         n_lepSFObjTight_MU_SF_Isol_STAT_UP=                           lepSFObjTight_MU_SF_Isol_STAT_UP;
         n_lepSFObjLoose_MU_SF_Isol_STAT_DOWN=                         lepSFObjLoose_MU_SF_Isol_STAT_DOWN;
         n_lepSFObjTight_MU_SF_Isol_STAT_DOWN=                         lepSFObjTight_MU_SF_Isol_STAT_DOWN;
         n_lepSFObjTight_MU_SF_Isol_SYST_UP=                           lepSFObjTight_MU_SF_Isol_SYST_UP;
         n_lepSFObjTight_MU_SF_Isol_SYST_DOWN=                         lepSFObjTight_MU_SF_Isol_SYST_DOWN;
         n_lepSFObjTight_MU_SF_TTVA_STAT_UP=                           lepSFObjTight_MU_SF_TTVA_STAT_UP;
         n_lepSFObjTight_MU_SF_TTVA_STAT_DOWN=                         lepSFObjTight_MU_SF_TTVA_STAT_DOWN;
         n_lepSFObjTight_MU_SF_TTVA_SYST_UP=                           lepSFObjTight_MU_SF_TTVA_SYST_UP;
         n_lepSFObjTight_MU_SF_TTVA_SYST_DOWN=                         lepSFObjTight_MU_SF_TTVA_SYST_DOWN;
      }
      if(lepton[1].pt > lepton[0].pt) {
         pt_leadinglepton=lepton[1].pt/1000.;
         pt_sublepton=lepton[0].pt/1000.;
         eta_leadinglepton=lepton[1].eta;
         eta_sublepton=lepton[0].eta;
      }
      if(lepton[0].pt > lepton[1].pt){
         pt_leadinglepton=lepton[0].pt/1000.;
         pt_sublepton=lepton[1].pt/1000.;
         eta_leadinglepton=lepton[0].eta;
         eta_sublepton=lepton[1].eta;
      }
      n_category=category;
      if(config.Contains("nominal")){
         if(category==1){channel=1; tree->Fill();}
         if(category==11){channel=2; tree->Fill();}
         if(category==21){channel=3; tree->Fill();}
      }
      if(config.Contains("QmisID")){
         if(category==1){channel=1; tree->Fill();}
         if(category==21){channel=3; tree->Fill();}
      }
      if(config.Contains("FFQmis")){
         if(category==23){channel=3; tree->Fill();}
      }
      if(config.Contains("FFApp")){
         if(category==2) {channel=1; tree->Fill();}
         if(category==12&&datasetType!=3) {channel=2; tree->Fill();}//fill mumu fakes, no ttbar Zjets WW or DY
         if((category==22||category==23)&&datasetType!=3){channel=3; tree->Fill();}
         if(category==22&&datasetType==3){channel=3; tree->Fill();}
      }
  }//end entry loop
  tree->Write();
  output_file->Close();
  //avoid memory leak
  //delete tree; 
  delete output_file;
  //delete hist_ff_eta_antiidmuon;
  //delete hist_ff_eta_antiidelectron;
  //delete hist_QmisID;
  delete f_QmisID;
}
