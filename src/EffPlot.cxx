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
  hist_hh_ee->SetBinContent(1,0.03/0.05);
  hist_hh_mumu->SetBinContent(1,0.03/0.09);
  hist_hh_emu->SetBinContent(1,0.05/0.14);
  //resonance hh
  //mH260
  hist_hh_ee->SetBinContent(2,0.44/0.75);
  hist_hh_mumu->SetBinContent(2,0.54/1.41);
  hist_hh_emu->SetBinContent(2,0.99/2.17);
  //mH300
  hist_hh_ee->SetBinContent(3,0.61/1.06);
  hist_hh_mumu->SetBinContent(3,1.46/2.23);
  hist_hh_emu->SetBinContent(3,1.99/3.27);
  //mH400
  hist_hh_ee->SetBinContent(4,0.81/1.85);
  hist_hh_mumu->SetBinContent(4,1.30/3.37);
  hist_hh_emu->SetBinContent(4,2.16/5.53);
  //mH500
  hist_hh_ee->SetBinContent(5,0.85/1.76);
  hist_hh_mumu->SetBinContent(5,1.40/3.03);
  hist_hh_emu->SetBinContent(5,1.91/4.85);
  //mX=280, S135
  hist_SS_ee->SetBinContent(1,1.86/3.19); 
  hist_SS_mumu->SetBinContent(1,4.43/6.95); 
  hist_SS_emu->SetBinContent(1,5.15/10.44); 
  //X300,S135
  hist_SS_ee->SetBinContent(2,2.10/3.66);
  hist_SS_mumu->SetBinContent(2,4.31/7.66);
  hist_SS_emu->SetBinContent(2,5.46/11.56);
  //X320,S135
  hist_SS_ee->SetBinContent(3,2.04/4.28);
  hist_SS_mumu->SetBinContent(3,3.96/8.64);
  hist_SS_emu->SetBinContent(3,5.37/12.94);
  //X340,S135
  hist_SS_ee->SetBinContent(4,2.42/3.14);
  hist_SS_mumu->SetBinContent(4,4.73/6.18);
  hist_SS_emu->SetBinContent(4,6.08/9.71);
  //X340,S145
  hist_SS_ee->SetBinContent(5,6.85/9.74);
  hist_SS_mumu->SetBinContent(5,14.28/19.98);
  hist_SS_emu->SetBinContent(5,15.95/29.44);
  //X340,S155
  hist_SS_ee->SetBinContent(6,13.38/19.27);
  hist_SS_mumu->SetBinContent(6,30.93/40.95);
  hist_SS_emu->SetBinContent(6,34.23/56.92);
  //X340,S165
  hist_SS_ee->SetBinContent(7,24.58/31.24);
  hist_SS_mumu->SetBinContent(7,54.17/66.07);
  hist_SS_emu->SetBinContent(7,66.49/95.90);

  hist_hh_ee->SetLineColor(kRed) ;
  hist_hh_mumu->SetLineColor(kBlue) ;
  hist_hh_emu->SetLineColor(kGreen) ;
  hist_hh_ee->GetXaxis()->SetBinLabel(1,"Non-resonant");
  hist_hh_ee->GetXaxis()->SetBinLabel(2,"mX=260 GeV");
  hist_hh_ee->GetXaxis()->SetBinLabel(3,"mX=300 GeV");
  hist_hh_ee->GetXaxis()->SetBinLabel(4,"mX=400 GeV");
  hist_hh_ee->GetXaxis()->SetBinLabel(5,"mX=500 GeV");
  //hist_hh_ee->GetXaxis()->LabelsOption("v");
  hist_hh_ee->GetYaxis()->SetTitle("Efficiency");
  hist_SS_ee->GetYaxis()->SetTitle("Efficiency");

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
  hist_hh_ee->SetMaximum(1.5);
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
  hist_SS_ee->SetMaximum(1.5);
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
