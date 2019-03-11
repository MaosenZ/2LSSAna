#include "TGraphErrors.h"
#include "TCanvas.h"
#include "../../atlasstyle-00-03-05/AtlasStyle.C"
#include "../../atlasstyle-00-03-05/AtlasUtils.C"

void ff_Njet(){
  SetAtlasStyle();
  
  Double_t ffs_ele[]={0.5401,0.5643,0.7433};
  Double_t ffs_ele_err[]={0.5401*0.5345,0.0498,0.0746};
  Double_t ffs_mu[]={0.5033,0.3929,0.2165}; 
  Double_t ffs_mu_err[]={0.5033*0.4318,0.0479,0.0312}; 

  Double_t varx[]={0.5,1.5,2.5};
  Double_t varx_err[]={0.5,0.5,0.5}; 
  TH1F *frame =new TH1F("frame","",3,0,3);
  TH1F *hist_ff_ele =new TH1F("hist_ff_ele","",3,0,3);
  TH1F *hist_ff_mu =new TH1F("hist_ff_mu","",3,0,3);
/*data
  hist_ff_ele->SetBinContent(1,0.5401);
  hist_ff_ele->SetBinContent(2,0.5643);
  hist_ff_ele->SetBinContent(3,0.7433);
  hist_ff_ele->SetBinError(1,0.5401*0.5345);
  hist_ff_ele->SetBinError(2,0.0498);
  hist_ff_ele->SetBinError(3,0.0746);

  hist_ff_mu->SetBinContent(1,0.5033);
  hist_ff_mu->SetBinContent(2,0.3929);
  hist_ff_mu->SetBinContent(3,0.2165);
  hist_ff_mu->SetBinError(1,0.5033*0.4318);
  hist_ff_mu->SetBinError(2,0.0479);
  hist_ff_mu->SetBinError(3,0.0312);*/
  hist_ff_ele->SetBinContent(1,0.3152);
  hist_ff_ele->SetBinContent(2,0.3374);
  hist_ff_ele->SetBinContent(3,0.3482);
  hist_ff_ele->SetBinError(1,0.1154);
  hist_ff_ele->SetBinError(2,0.1161);
  hist_ff_ele->SetBinError(3,0.1023);

  hist_ff_mu->SetBinContent(1,0.1217);
  hist_ff_mu->SetBinContent(2,0.1612);
  hist_ff_mu->SetBinContent(3,0.1251);
  hist_ff_mu->SetBinError(1,0.0402);
  hist_ff_mu->SetBinError(2,0.0434);
  hist_ff_mu->SetBinError(3,0.0306);

  TCanvas *c_gr_ele=new TCanvas("c_gr_ele","",900,800);
  gStyle->SetLineWidth(2);
  gPad->SetLineWidth(2);
  hist_ff_ele->GetYaxis()->SetTitle("Fake factor");
  hist_ff_ele->GetXaxis()->SetBinLabel(1,"1#leq N_{jet}#leq2");
  hist_ff_ele->GetXaxis()->SetBinLabel(2,"N_{jet}=3");
  hist_ff_ele->GetXaxis()->SetBinLabel(3,"N_{jet}#geq4");
  hist_ff_ele->SetMinimum(0.);
  hist_ff_ele->SetMaximum(1.);
  hist_ff_ele->Draw("E");

  TCanvas *c_gr_mu=new TCanvas("c_gr_mu","",900,800);
  gStyle->SetLineWidth(2);
  gPad->SetLineWidth(2);
  hist_ff_mu->GetYaxis()->SetTitle("Fake factor");
  hist_ff_mu->GetXaxis()->SetBinLabel(1,"1#leq N_{jet}=1#leq2");
  hist_ff_mu->GetXaxis()->SetBinLabel(2,"N_{jet}=3");
  hist_ff_mu->GetXaxis()->SetBinLabel(3,"N_{jet}#geq4");
  hist_ff_mu->SetMinimum(0.);
  hist_ff_mu->SetMaximum(1.);
  hist_ff_mu->Draw("E"); 
  //TGraphErrors *gr_mu=new TGraphErrors(3,varx,ffs_mu,varx_err,ffs_mu_err);
  //gr_mu->Draw("AP0 same");
}
