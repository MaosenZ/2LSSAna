#include "TFile.h"
#include "TCanvas.h"
#include "../../atlasstyle-00-03-05/AtlasStyle.C"
#include "../../atlasstyle-00-03-05/AtlasUtils.C"

void ff_plot(){
  SetAtlasStyle();
  
  TFile *ff=new TFile("output/hist_ff_2jets.root");

  TH1 *hist_ff_pt_ele =(TH1*)ff->Get("hist_ff_pt_antiidelectron");
  TH1 *hist_ff_pt_mu =(TH1*)ff->Get("hist_ff_pt_antiidmuon");
  TH1 *hist_ff_eta_ele =(TH1*)ff->Get("hist_ff_eta_antiidelectron");
  TH1 *hist_ff_eta_mu =(TH1*)ff->Get("hist_ff_eta_antiidmuon");

  //TH1F *frame_pt=new TH1F("frame_pt","",1,0,1000);
  //frame_pt->GetYaxis()->SetTitle("Fake factor");
  //frame_pt->GetXaxis()->SetTitle("p_{T}");

  TCanvas *c_ff_pt_ele=new TCanvas("c_ff_pt_ele","",900,800);
  gStyle->SetLineWidth(2);
  gPad->SetLineWidth(2);
  gPad->SetLogx();
  //frame_pt->Draw();
  hist_ff_pt_ele->GetYaxis()->SetTitle("Fake factor");
  hist_ff_pt_ele->GetXaxis()->SetTitle("p_{T}");
  hist_ff_pt_ele->SetMinimum(0.);
  hist_ff_pt_ele->SetMaximum(1.);
  hist_ff_pt_ele->Draw();
  c_ff_pt_ele->SaveAs("ff_pt_ele.pdf");

  TCanvas *c_ff_pt_mu=new TCanvas("c_ff_pt_mu","",900,800);
  gStyle->SetLineWidth(2);
  gPad->SetLineWidth(2);
  gPad->SetLogx();
  hist_ff_pt_mu->GetYaxis()->SetTitle("Fake factor");
  hist_ff_pt_mu->GetXaxis()->SetTitle("p_{T}");
  hist_ff_pt_mu->SetMinimum(0.);
  hist_ff_pt_mu->SetMaximum(2.);
  hist_ff_pt_mu->Draw(); 
  c_ff_pt_mu->SaveAs("ff_pt_mu.pdf");

  TCanvas *c_ff_eta_ele=new TCanvas("c_ff_eta_ele","",900,800);
  gStyle->SetLineWidth(2);
  gPad->SetLineWidth(2);
  hist_ff_eta_ele->GetYaxis()->SetTitle("Fake factor");
  hist_ff_eta_ele->GetXaxis()->SetTitle("|#eta|");
  hist_ff_eta_ele->SetMinimum(0.); 
  hist_ff_eta_ele->SetMaximum(1.);
  hist_ff_eta_ele->SetBinContent(3,0);
  hist_ff_eta_ele->SetBinError(3,0);
  hist_ff_eta_ele->GetXaxis()->SetRangeUser(0,2.5); 
  hist_ff_eta_ele->Draw();
  c_ff_eta_ele->SaveAs("ff_eta_ele.pdf");

  TCanvas *c_ff_eta_mu=new TCanvas("c_ff_eta_mu","",900,800);
  gStyle->SetLineWidth(2);
  gPad->SetLineWidth(2);
  hist_ff_eta_mu->GetYaxis()->SetTitle("Fake factor");
  hist_ff_eta_mu->GetXaxis()->SetTitle("|#eta|");
  hist_ff_eta_mu->SetMinimum(0.);
  hist_ff_eta_mu->SetMaximum(1.);
  hist_ff_eta_mu->Draw();
  c_ff_eta_mu->SaveAs("ff_eta_mu.pdf");
}
