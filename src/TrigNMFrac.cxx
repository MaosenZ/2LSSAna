//------------------------------------------------
//This macro is to draw fractions of both leptons matched trigger and just one lepton matched trigger for fakes
//------------------------------------------------
#include "TH1F.h"
#include "TCanvas.h"
#include "../../atlasstyle-00-03-05/AtlasStyle.C"
#include "../../atlasstyle-00-03-05/AtlasUtils.C"

void TrigNMFrac(){
  SetAtlasStyle();  
  TH1F *hist_MM=new TH1F("hist_MM","",3,0,3);//both lepton matched trigger
  TH1F *hist_NM=new TH1F("hist_NM","",3,0,3);//only one lepton match trigger
  THStack *hs=new THStack("hs","");
  
  hist_MM->SetBinContent(1,272.94);
  hist_MM->SetBinContent(2,243.44);
  hist_MM->SetBinContent(3,231.81);
  
  hist_NM->SetBinContent(1,45.34);
  hist_NM->SetBinContent(2,12.76);
  hist_NM->SetBinContent(3,100.88);
  /*hist_MM->SetBinContent(1,107.09);
  hist_MM->SetBinContent(2,117.50);
  hist_MM->SetBinContent(3,96.48);

  hist_NM->SetBinContent(1,20.29);
  hist_NM->SetBinContent(2,5.48);
  hist_NM->SetBinContent(3,41.76);*/

  hs->Add(hist_MM);
  hs->Add(hist_NM);
 
  hist_MM->SetLineColor(kRed);
  hist_NM->SetLineColor(kBlue);
  hist_MM->SetFillColor(kRed);
  hist_NM->SetFillColor(kBlue);

  TCanvas *c_hs=new TCanvas("c_hs","",1000,700);
  TLegend *leg=new TLegend(0.70,0.20,0.9,0.40);
  leg->AddEntry(hist_MM,"Trigger matched fakes","f");
  leg->AddEntry(hist_NM,"Trigger non-matched fakes","f");
  hs->Draw();
  hs->GetXaxis()->SetBinLabel(1,"ee");
  hs->GetXaxis()->SetBinLabel(2,"#mu#mu");
  hs->GetXaxis()->SetBinLabel(3,"e#mu");
  hs->GetYaxis()->SetTitle("Num. Of Fakes");
  leg->Draw("same");
  c_hs->SaveAs("FakesTrigCom_2jets.pdf");
}
