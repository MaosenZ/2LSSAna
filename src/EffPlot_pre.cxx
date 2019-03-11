#include "TH1F.h"
#include "../../atlasstyle-00-03-05/AtlasStyle.C"
#include "../../atlasstyle-00-03-05/AtlasUtils.C"
void EffPlot(){
  SetAtlasStyle();
  TH1F *hist_hh_ee=new TH1F("hist_hh_ee","",5,0,5);
  TH1F *hist_hh_mumu=new TH1F("hist_hh_mumu","",5,0,5);
  TH1F *hist_hh_emu=new TH1F("hist_hh_emu","",5,0,5);
  TH1F *hist_SS_ee=new TH1F("hist_SS_ee","",7,0,7);
  TH1F *hist_SS_mumu=new TH1F("hist_SS_mumu","",7,0,7);
  TH1F *hist_SS_emu=new TH1F("hist_SS_emu","",7,0,7);
  //nonres
  hist_hh_ee->SetBinContent(1,1.03);
  hist_hh_mumu->SetBinContent(1,1.91);
  hist_hh_emu->SetBinContent(1,2.99);
  //resonance hh
  //mH260
  hist_hh_ee->SetBinContent(2,0.5);
  hist_hh_mumu->SetBinContent(2,0.99);
  hist_hh_emu->SetBinContent(2,1.48);
  //mH300
  hist_hh_ee->SetBinContent(3,0.7);
  hist_hh_mumu->SetBinContent(3,1.46);
  hist_hh_emu->SetBinContent(3,2.21);
  //mH400
  hist_hh_ee->SetBinContent(4,0.81);
  hist_hh_mumu->SetBinContent(4,1.61);
  hist_hh_emu->SetBinContent(4,2.58);
  //mH500
  hist_hh_ee->SetBinContent(5,1.11);
  hist_hh_mumu->SetBinContent(5,2.15);
  hist_hh_emu->SetBinContent(5,3.31);
  //mX=280, S135
  hist_SS_ee->SetBinContent(1,0.71); 
  hist_SS_mumu->SetBinContent(1,1.60); 
  hist_SS_emu->SetBinContent(1,2.29); 
  //X300,S135
  hist_SS_ee->SetBinContent(2,0.82);
  hist_SS_mumu->SetBinContent(2,1.73);
  hist_SS_emu->SetBinContent(2,2.57);
  //X320,S135
  hist_SS_ee->SetBinContent(3,0.91);
  hist_SS_mumu->SetBinContent(3,1.91);
  hist_SS_emu->SetBinContent(3,2.80);
  //X340,S135
  hist_SS_ee->SetBinContent(4,0.68);
  hist_SS_mumu->SetBinContent(4,1.39);
  hist_SS_emu->SetBinContent(4,2.13);
  //X340,S145
  hist_SS_ee->SetBinContent(5,0.86);
  hist_SS_mumu->SetBinContent(5,1.71);
  hist_SS_emu->SetBinContent(5,2.61);
  //X340,S155
  hist_SS_ee->SetBinContent(6,0.96);
  hist_SS_mumu->SetBinContent(6,2.02);
  hist_SS_emu->SetBinContent(6,2.87);
  //X340,S165
  hist_SS_ee->SetBinContent(7,1.04);
  hist_SS_mumu->SetBinContent(7,2.36);
  hist_SS_emu->SetBinContent(7,3.35);

  hist_hh_ee->SetLineColor(kRed) ;
  hist_hh_mumu->SetLineColor(kBlue) ;
  hist_hh_emu->SetLineColor(kGreen) ;
  hist_hh_ee->GetXaxis()->SetBinLabel(1,"Non-resonant");
  hist_hh_ee->GetXaxis()->SetBinLabel(2,"mX=260 GeV");
  hist_hh_ee->GetXaxis()->SetBinLabel(3,"mX=300 GeV");
  hist_hh_ee->GetXaxis()->SetBinLabel(4,"mX=400 GeV");
  hist_hh_ee->GetXaxis()->SetBinLabel(5,"mX=500 GeV");
  //hist_hh_ee->GetXaxis()->LabelsOption("v");
  hist_hh_ee->GetYaxis()->SetTitle("Efficiency (%)");
  hist_SS_ee->GetYaxis()->SetTitle("Efficiency (%)");

  //SS
  hist_SS_ee->SetLineColor(kRed) ;
  hist_SS_mumu->SetLineColor(kBlue) ;
  hist_SS_emu->SetLineColor(kGreen) ;
  hist_SS_ee->GetXaxis()->SetBinLabel(1,"mX=280 GeV, mS=135 GeV");
  hist_SS_ee->GetXaxis()->SetBinLabel(2,"mX=300 GeV, mS=135 GeV");
  hist_SS_ee->GetXaxis()->SetBinLabel(3,"mX=320 GeV, mS=135 GeV");
  hist_SS_ee->GetXaxis()->SetBinLabel(4,"mX=340 GeV, mS=135 GeV");
  hist_SS_ee->GetXaxis()->SetBinLabel(5,"mX=340 GeV, mS=145 GeV");
  hist_SS_ee->GetXaxis()->SetBinLabel(6,"mX=340 GeV, mS=155 GeV");
  hist_SS_ee->GetXaxis()->SetBinLabel(7,"mX=340 GeV, mS=165 GeV");

  TCanvas *c_hh=new TCanvas("c_hh","",1000,700);
  gPad->SetLineWidth(2);
  gStyle->SetLineWidth(2);
  hist_hh_ee->SetMaximum(5);
  hist_hh_ee->SetMinimum(0.1);
  hist_hh_ee->Draw("");
  hist_hh_mumu->Draw("same");
  hist_hh_emu->Draw("same");
  TLegend *leg_hh= new TLegend(0.70,0.70,0.97,0.90);
  leg_hh->SetFillStyle(0);
  leg_hh->SetBorderSize(0);
  leg_hh->SetTextFont(62);
  leg_hh->SetTextSize(0.03); 
  leg_hh->AddEntry(hist_hh_ee,"ee","l");
  leg_hh->AddEntry(hist_hh_mumu,"#mu#mu","l");
  leg_hh->AddEntry(hist_hh_emu,"e#mu","l");
  leg_hh->Draw("same");

  //SS
  TCanvas *c_SS=new TCanvas("c_SS","",1000,700);
  TPad *pad=new TPad("pad","",0,0,1,1);
  pad->Draw();
  pad->SetRightMargin(0.13);
  //pad->SetLeftMargin(0.05);
  pad->cd();
  gPad->SetLineWidth(2);
  gStyle->SetLineWidth(2);
  hist_SS_ee->SetMaximum(5);
  hist_SS_ee->SetMinimum(0.1);
  hist_SS_ee->SetLabelSize(0.035,"X");
  hist_SS_ee->Draw("");
  hist_SS_mumu->Draw("same");
  hist_SS_emu->Draw("same");
  TLegend *leg_SS= new TLegend(0.70,0.70,0.97,0.90);
  leg_SS->SetFillStyle(0);
  leg_SS->SetBorderSize(0);
  leg_SS->SetTextFont(62);
  leg_SS->SetTextSize(0.03);
  leg_SS->AddEntry(hist_SS_ee,"ee","l");
  leg_SS->AddEntry(hist_SS_mumu,"#mu#mu","l");
  leg_SS->AddEntry(hist_SS_emu,"e#mu","l");
  leg_SS->Draw("same");
}
