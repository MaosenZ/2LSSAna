#include <iostream>
#include "TFile.h"
#include "TH1.h"
#include "../inc/SampleHandler.h"
#include "THStack.h"
#include "lumi.cxx"
#include "../../atlasstyle-00-03-05/AtlasStyle.C"
#include "../../atlasstyle-00-03-05/AtlasUtils.C"
void DataMC(){
   SetAtlasStyle();
  TFile *temp_data=new TFile("temp/hists_FFApp_2jets_datacombined.root");
  TFile *temp_diboson=new TFile("temp/hists_FFApp_2jets_diboson.root");
  TFile *temp_ttV=new TFile("temp/hists_FFApp_2jets_ttV.root");
  TFile *temp_tV=new TFile("temp/hists_FFApp_2jets_tV.root");
  TFile *temp_ttH=new TFile("temp/hists_FFApp_2jets_ttH.root");
  TFile *temp_Vgam=new TFile("temp/hists_FFApp_2jets_Vgam.root");
  TFile *temp_fake=new TFile("temp/hists_fakes.root");
  TFile *temp_QmisID_data=new TFile("temp/hists_FFApp_QmisID_2jets_datacombined.root");
  
  TString cates[]={"ee","mumu","emu"};
  TString vars[]={"m_ll","met","m_all","m_jj_w","m_l1jj","mindR_l1j","mindR_l2j"};
  TString titles[]={"M_{ll}","MET","m_all","M_{jj}^{w}","M_{l1jj}","#DeltaR_{min}(l1,j)","#DeltaR_{min}(l2,j)"};
  Float_t average_ff[]={0.307,0.319,0.313};
  Float_t ff_sys[]={0.27,0.56,0.6};
  for(Int_t k=0;k<3;k++){
  for(Int_t j=0;j<2;j++){
      TString cate=cates[k];
      TString var=vars[j];
      TString whichtouse1="hist_";whichtouse1+=var;whichtouse1+="_";whichtouse1+=cate;
      TString title=titles[j];
      TString outputdir="output/stacks/hs_";outputdir+=var;outputdir+="_";outputdir+=cate;outputdir+=".png";
      TString stack="hs_";stack+=var;stack+=cate;
  //ee
  THStack *hs_var_ee = new THStack(stack,"");
  hs_var_ee->SetMinimum(1);
  hs_var_ee->SetMaximum(10000);

  TH1* hist_var_ee_data=(TH1*)temp_data->Get(whichtouse1);
  TH1* hist_var_ee_diboson=(TH1*)temp_diboson->Get(whichtouse1);
  TH1* hist_var_ee_ttV=(TH1*)temp_ttV->Get(whichtouse1);
  TH1* hist_var_ee_tV=(TH1*)temp_tV->Get(whichtouse1);
  TH1* hist_var_ee_ttH=(TH1*)temp_ttH->Get(whichtouse1);
  TH1* hist_var_ee_Vgam=(TH1*)temp_Vgam->Get(whichtouse1);
  TH1* hist_var_ee_fake=(TH1*)temp_fake->Get(whichtouse1);
  TH1 *hist_var_ee_QmisID;
  if(k!=1)hist_var_ee_QmisID=(TH1*)temp_QmisID_data->Get(whichtouse1);
  if(k==1)hist_var_ee_QmisID=0;

  hist_var_ee_diboson->Scale(lumi());
  hist_var_ee_ttV->Scale(lumi());
  hist_var_ee_tV->Scale(lumi());
  hist_var_ee_ttH->Scale(lumi());
  hist_var_ee_Vgam->Scale(lumi());
  
  hist_var_ee_data->SetMarkerStyle(20);
  hist_var_ee_data->SetMarkerColor(kBlack);
  hist_var_ee_data->GetYaxis()->SetTitle("Entries");
  hist_var_ee_diboson->SetFillColor(2);
  hist_var_ee_ttV->SetFillColor(3);
  hist_var_ee_tV->SetFillColor(4);
  hist_var_ee_ttH->SetFillColor(5);
  hist_var_ee_Vgam->SetFillColor(8);
  hist_var_ee_fake->SetFillColor(6);
  if(k!=1)hist_var_ee_QmisID->SetFillColor(7);
  
  hs_var_ee->Add(hist_var_ee_diboson);
  hs_var_ee->Add(hist_var_ee_ttV);
  hs_var_ee->Add(hist_var_ee_tV);
  hs_var_ee->Add(hist_var_ee_ttH);
  hs_var_ee->Add(hist_var_ee_Vgam);
  hs_var_ee->Add(hist_var_ee_fake);
  if(k!=1)hs_var_ee->Add(hist_var_ee_QmisID);
  
  TCanvas *cs_m_ll_ee = new TCanvas("cs_m_ll_ee","",900,900);
  TPad *pad1=new TPad("pad1","pad1",0,0.33,1,1.0);
  pad1->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad1->SetTopMargin(0.05);
  gStyle->SetLineWidth(2);
  gPad->SetLineWidth(2);
  pad1->SetLogy();
  pad1->SetTickx();
  pad1->SetTicky();
  pad1->Draw();
  pad1->cd();
  TLegend *leg= new TLegend(0.72,0.70,0.97,0.90);
  leg->SetNColumns(2);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetTextFont(62);
  leg->SetTextSize(0.03);
  leg->AddEntry(hist_var_ee_data,"Data","l");
  leg->AddEntry(hist_var_ee_diboson,"VV","f");
  leg->AddEntry(hist_var_ee_ttV,"ttV","f");
  leg->AddEntry(hist_var_ee_tV,"tV","f");
  leg->AddEntry(hist_var_ee_ttH,"ttH","f");
  leg->AddEntry(hist_var_ee_Vgam,"V#gamma","f");
  if(k!=1)leg->AddEntry(hist_var_ee_QmisID,"QmisID","f");
  leg->AddEntry(hist_var_ee_fake,"Fakes","f");
  hist_var_ee_data->GetYaxis()->SetTitleSize(0.05);
  hist_var_ee_data->GetYaxis()->SetTitleOffset(0.5);
  cout<<hist_var_ee_data->GetYaxis()->GetTitleOffset()<<endl;;
  hs_var_ee->Draw();
  hist_var_ee_data->Draw("EO SAME");
  leg->Draw("HIST SAME");
  ATLAS_LABEL(0.20, 0.78 );
  myText( 0.36, 0.78 , 1, "Internal");
  myText( 0.17, 0.85 , 1, "#sqrt{s} = 13 TeV");
  myText( 0.35, 0.85 , 1, "2015+2016 #int L dt = 13.2 fb^{-1}");
  
  Int_t Nbins=hist_var_ee_data->GetNbinsX();
  Int_t Xmaximum=(hist_var_ee_data->GetBinWidth(1)) *Nbins;
  Int_t Ymaximum=2;
  Float_t varx[200],varx_error[200]; Float_t ratio[200], ratio_error[200];
  Float_t stack_x[200],stack_x_error[200];Float_t stack_y[200],stack_y_error[200];
  for(int i=0;i<Nbins;i++){
     varx[i]=(i+0.5)*(hist_var_ee_data->GetBinWidth(1));
     stack_x[i]=(i+0.5)*(hist_var_ee_data->GetBinWidth(1));
     varx_error[i]=hist_var_ee_data->GetBinWidth(1)/2.;
     stack_x_error[i]=hist_var_ee_data->GetBinWidth(1)/2.;
     Float_t data_bincontent=hist_var_ee_data->GetBinContent(i+1);
     Float_t MC_bincontent;
     Float_t fake_count=hist_var_ee_fake->GetBinContent(i+1);
     
     if(k!=1) MC_bincontent=hist_var_ee_ttV->GetBinContent(i+1)+hist_var_ee_tV->GetBinContent(i+1)+
                           +hist_var_ee_diboson->GetBinContent(i+1)+hist_var_ee_ttH->GetBinContent(i+1)+hist_var_ee_Vgam->GetBinContent(i+1)+
                           hist_var_ee_QmisID->GetBinContent(i+1)+hist_var_ee_fake->GetBinContent(i+1); 
     if(k==1) MC_bincontent=hist_var_ee_ttV->GetBinContent(i+1)+hist_var_ee_tV->GetBinContent(i+1)+
                            hist_var_ee_diboson->GetBinContent(i+1)+hist_var_ee_ttH->GetBinContent(i+1)+hist_var_ee_Vgam->GetBinContent(i+1)+
                            hist_var_ee_fake->GetBinContent(i+1);
     stack_y[i]=MC_bincontent;
     stack_y_error[i]=sqrt(pow(average_ff[k]*sqrt(fake_count),2)+pow((MC_bincontent-fake_count),2)+pow(ff_sys[k]*average_ff[k]*fake_count,2));         
     if(data_bincontent==0 || MC_bincontent==0){
        ratio[i]=0;
        ratio_error[i]=0;
     }
     else{
        Float_t data_binerror=hist_var_ee_data->GetBinError(i+1);
        ratio[i]=data_bincontent/MC_bincontent;
        ratio_error[i]=data_binerror/MC_bincontent;
        if(ratio_error[i]>2)Ymaximum=ratio_error[i]*1.5;
     }
  }
  TGraphErrors *gr_stack=new TGraphErrors(Nbins,stack_x,stack_y,stack_x_error,stack_y_error);
  gr_stack->SetFillColor(6);
  gr_stack->SetFillStyle(3004);
  gr_stack->Draw("2 same");
  
  cs_m_ll_ee->cd();
  TPad *pad2 = new TPad("pad2", "pad2", 0, 0.01, 1, 0.33);
  pad2->SetBottomMargin(0.25);
  pad2->SetTickx(); // vertical grid
  pad2->SetTicky();
  pad2->Draw();
  pad2->cd();
  //             
  TGraphErrors *gr=new TGraphErrors(Nbins,varx,ratio,varx_error,ratio_error);
  gr->GetYaxis()->SetTitle("Data/Bkg");
  gr->GetXaxis()->SetTitle(title);
  gr->GetXaxis()->SetLabelSize(0.10);
  gr->GetXaxis()->SetLabelOffset(0.03);
  gr->GetXaxis()->SetTitleSize(0.1);
  gr->GetXaxis()->SetTitleOffset(1.);
  gr->GetYaxis()->SetLabelSize(0.1);
  gr->GetYaxis()->SetTitleSize(0.1);
  gr->GetYaxis()->SetTitleOffset(0.5);
  gr->GetYaxis()->SetNdivisions(505);
  gr->SetMarkerSize(0.5);
  gr->GetXaxis()->SetRangeUser(0,200);
  gr->GetYaxis()->SetRangeUser(0,2);
  gr->Draw("AP");
  TLine* line=new TLine();
  line->DrawLine(hist_var_ee_data->GetXaxis()->GetXmin(),1.0,hist_var_ee_data->GetXaxis()->GetXmax(),1.0);
  line->SetLineColor(kBlack);
  line->SetLineStyle(kDashed);
  line->DrawLine(hist_var_ee_data->GetXaxis()->GetXmin(),0.5,hist_var_ee_data->GetXaxis()->GetXmax(),0.5);
  line->DrawLine(hist_var_ee_data->GetXaxis()->GetXmin(),1.5,hist_var_ee_data->GetXaxis()->GetXmax(),1.5);
  cs_m_ll_ee->SaveAs(outputdir);
 }
 } 
}
