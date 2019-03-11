#include "TFile.h"
#include "TCanvas.h"
#include "TH1F.h"
#include <iostream>
#include "GHTBCs.cxx"
#include "../../atlasstyle-00-03-05/AtlasStyle.C"
#include "../../atlasstyle-00-03-05/AtlasUtils.C"
#include <vector>
#include <map>
using namespace std;

void Check_Jetpt(){
  SetAtlasStyle();
  TString masspoints[]={"mH260","mH300","mH400","mH500","nonres"};
  map<TString,vector<int> >numOfjets;

  for(int index=0;index<5;index++){
  TString input="/publicfs/atlas/atlasnew/higgs/hgg/zhoums/4W/v27.01/nominal/ntuples_";
  input+=masspoints[index]+".root";;
  TFile *f=new TFile(input);
  TTree *tree=(TTree*)f->Get("Tree");

  TH1F *frame       =new TH1F("frame","",40,0,200);  
  TH1F *hist_jet1_pt=new TH1F("hist_jet1_pt","",40,0,200);
  TH1F *hist_jet2_pt=new TH1F("hist_jet2_pt","",40,0,200);
  TH1F *hist_jet3_pt=new TH1F("hist_jet3_pt","",40,0,200);
  TH1F *hist_jet4_pt=new TH1F("hist_jet4_pt","",40,0,200);
   
  vector<float>*jet_pt=0; 
  int numOfBtagjet;
  int isSS;
  vector<char>    *jet_passOR=0;
  
  tree->SetBranchAddress("jet_pt",&jet_pt);
  tree->SetBranchAddress("jet_passOR",&jet_passOR);
  //tree->SetBranchAddress("numOfBtagjet",&numOfBtagjet);
  //tree->SetBranchAddress("n_isSS",&isSS);
  Int_t numOftotal=0,numOfpass=0,numOf3jet=0,numOf2jet=0,numOf4jet=0;
  for(Int_t i=0;i<tree->GetEntries();i++){
      tree->GetEntry(i);
      //if(isSS!=1)continue;
      //if(numOfBtagjet>0)continue;
      if(jet_pt->size()==3 && (*jet_pt)[2]>25e3)numOf3jet++;
      if(jet_pt->size()==2 && (*jet_pt)[1]>25e3)numOf2jet++;
      if(jet_pt->size()>=4 && (*jet_pt)[3]>25e3)numOf4jet++;
      numOftotal++;
      hist_jet1_pt->Fill((*jet_pt)[0]/1000.);
      hist_jet2_pt->Fill((*jet_pt)[1]/1000.);
      hist_jet3_pt->Fill((*jet_pt)[2]/1000.);
      hist_jet4_pt->Fill((*jet_pt)[3]/1000.);
      if((*jet_pt)[2]>25e3)numOfpass++;
      int numOfjet=0;
      for(unsigned int j=0;j<jet_pt->size();j++){
          if((*jet_passOR)[j])numOfjet++;
      }
      numOfjets[masspoints[index]].push_back(numOfjet);
  }
  cout<<"numOftotal: "<<numOftotal<<endl;
  cout<<"numOfpass: "<<numOfpass<<endl;
  cout<<"numOf2jet: "<<numOf2jet<<endl;
  cout<<"numOf3jet: "<<numOf3jet<<endl;
  cout<<"numOf4jet: "<<numOf4jet<<endl;
  TCanvas *c_hist_jet_pt=new TCanvas("c_hist_jet_pt","",900,700);
  gPad->SetTicks();
  gStyle->SetLineWidth(2);
  gPad->SetLineWidth(2);
  gStyle->SetOptStat("");
  hist_jet1_pt->SetLineColor(2);
  hist_jet2_pt->SetLineColor(3);
  hist_jet3_pt->SetLineColor(4);
  hist_jet4_pt->SetLineColor(6);
  frame->GetXaxis()->SetTitle("Jet pT [GeV]");
  frame->GetXaxis()->CenterTitle();
  frame->GetYaxis()->CenterTitle();
  frame->GetYaxis()->SetTitle("N / 5 [GeV]");
  Float_t Ymaximum=1.2*GetMaxBinContent(hist_jet4_pt);
  frame->SetMaximum(Ymaximum);
  frame->Draw();
  hist_jet1_pt->Draw("same");
  hist_jet2_pt->Draw("same");
  hist_jet3_pt->Draw("same");
  hist_jet4_pt->Draw("same");
  TLegend *leg=new TLegend(0.72,0.60,0.97,0.80);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetTextFont(62);
  leg->SetTextSize(0.03);
  leg->AddEntry(hist_jet1_pt,"1st Jet","l");
  leg->AddEntry(hist_jet2_pt,"2nd Jet","l");
  leg->AddEntry(hist_jet3_pt,"3rd Jet","l");
  leg->AddEntry(hist_jet4_pt,"4th Jet","l");
  leg->Draw("same");
  //myText(0.45, 0.83, 1, "X (500 GeV)#rightarrow hh #rightarrow WW#lower[-0.3]{*}WW#lower[-0.3]{*}");
  myText(0.50, 0.83, 1, "hh #rightarrow WW#lower[-0.3]{*}WW#lower[-0.3]{*}");
  TLine* line=new TLine();
  line->SetLineStyle(kDashed);
  line->SetLineColor(kRed);
  line->DrawLine(25,0,25,Ymaximum);
  line->DrawLine(10,0,10,Ymaximum);
  TString outputFile="pt_jet_";
  outputFile+=masspoints[index]+".pdf";
  //c_hist_jet_pt->SaveAs(outputFile);
  }
  TH1F *hist_mH260=new TH1F("hist_mH260","hist_mH260",10,0,10);
  TH1F *hist_mH300=new TH1F("hist_mH300","hist_mH300",10,0,10);
  TH1F *hist_mH400=new TH1F("hist_mH400","hist_mH400",10,0,10);
  TH1F *hist_mH500=new TH1F("hist_mH500","hist_mH500",10,0,10);
  TH1F *hist_nonres=new TH1F("hist_nonres","hist_nonres",10,0,10);
  for(unsigned int k=0;k<numOfjets["mH260"].size();k++) hist_mH260->Fill((numOfjets["mH260"])[k]);
  for(unsigned int k=0;k<numOfjets["mH300"].size();k++) hist_mH300->Fill((numOfjets["mH300"])[k]);
  for(unsigned int k=0;k<numOfjets["mH400"].size();k++) hist_mH400->Fill((numOfjets["mH400"])[k]);
  for(unsigned int k=0;k<numOfjets["mH500"].size();k++) hist_mH500->Fill((numOfjets["mH500"])[k]);
  for(unsigned int k=0;k<numOfjets["nonres"].size();k++) hist_nonres->Fill((numOfjets["nonres"])[k]);
  TCanvas *c_numOfjets=new TCanvas("c_hist_numOfjets","",900,700);
  gPad->SetTicks();
  gStyle->SetLineWidth(2);
  gPad->SetLineWidth(2);
  gStyle->SetOptStat("");
  hist_mH260->SetLineColor(2);
  hist_mH300->SetLineColor(3);
  hist_mH400->SetLineColor(4);
  hist_mH500->SetLineColor(6);
  hist_nonres->SetLineColor(9);
  hist_mH260->GetXaxis()->SetTitle("Num. Of Jet");
  hist_mH260->GetXaxis()->CenterTitle();
  hist_mH260->GetYaxis()->CenterTitle();
  hist_mH260->GetYaxis()->SetTitle("Normalized");
  hist_mH260->DrawNormalized(); 
  hist_mH300->DrawNormalized("same");
  hist_mH400->DrawNormalized("same");
  hist_mH500->DrawNormalized("same");
  hist_nonres->DrawNormalized("same");
  TLegend *legN=new TLegend(0.70,0.60,0.97,0.80);
  legN->SetFillStyle(0);
  legN->SetBorderSize(0);
  legN->SetTextFont(62);
  legN->SetTextSize(0.03);
  legN->AddEntry(hist_mH260,"mX=260 GeV","l");
  legN->AddEntry(hist_mH300,"mX=300 GeV","l");
  legN->AddEntry(hist_mH400,"mX=400 GeV","l");
  legN->AddEntry(hist_mH500,"mX=500 GeV","l");
  legN->AddEntry(hist_nonres,"Non-resonant","l");
  legN->Draw("same");
  myText(0.60, 0.83, 1, "hh #rightarrow WW#lower[-0.3]{*}WW#lower[-0.3]{*}");
  c_numOfjets->SaveAs("numOfjet_sig.pdf");
  /*map<TString,vector<int> >::iterator it;
  for(it=numOfjets.begin();it!=numOfjets.end();++it){
      for(unsigned int k=0;k<(it->second).size();k++)
          hist_mH260->Fill((it->second)[k]);
  }*/
}
