#include "TH1.h"
#include "TH1F.h"
#include "TFile.h"
#include "TString.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "../../atlasstyle-00-03-05/AtlasStyle.C"
#include "lumi.cxx"
#include "GHTBCs.cxx"

void comparisons(){
  
  SetAtlasStyle();
  TFile *f1=new TFile("temp/hists_cutflow_3jets_nonres.root");
  TFile *f2_260=new TFile("temp/hists_cutflow_3jets_mH260.root");
  TFile *f2_300=new TFile("temp/hists_cutflow_3jets_mH300.root");
  TFile *f2_400=new TFile("temp/hists_cutflow_3jets_mH400.root");
  TFile *f2_500=new TFile("temp/hists_cutflow_3jets_mH500.root");
  TFile *f3=new TFile("temp/hists_cutflow_3jets_diboson.root");
  TFile *f4=new TFile("temp/hists_cutflow_3jets_ttV.root");
  TFile *f8=new TFile("temp/hists_cutflow_3jets_ttH.root");
  TFile *f5=new TFile("temp/hists_cutflow_3jets_tV.root");
  TFile *f6=new TFile("temp/hists_QmisID_3jets_datacombined.root");
  TFile *f7=new TFile("temp/hists_FFApp_3jets_datacombined.root");

  TString vars[]={"m_ll","met","m_all","m_jj_w","m_l1jj","mindR_l1j","mindR_l2j"};
  TString cates[3]={"ee","mumu","emu"};
  for(Int_t i=0;i<=2;i++){
      TString cate=cates[i];
      for(Int_t j=0;j<=6;j++){
          TString var=vars[j];
          TString hist="hist_";
          hist += var;
          hist += "_";
          hist += cate;
          
          TH1 *hist1=(TH1*)f1->Get(hist);
          TH1 *hist2_260=(TH1*)f2_260->Get(hist);
          TH1 *hist2_300=(TH1*)f2_300->Get(hist);
          TH1 *hist2_400=(TH1*)f2_400->Get(hist);
          TH1 *hist2_500=(TH1*)f2_500->Get(hist);
          TH1 *hist3=(TH1*)f3->Get(hist);
          TH1 *hist4=(TH1*)f4->Get(hist);
          TH1 *hist5=(TH1*)f5->Get(hist);
          TH1 *hist_QmisID;
          if(i!=1)hist_QmisID=(TH1*)f6->Get(hist);
          TH1 *hist_fake=(TH1*)f7->Get(hist);
          TH1 *hist6=(TH1*)f8->Get(hist);
          
          TH1 *hist_promptSS=(TH1*)hist3->Clone("hist_promptSS");
          hist_promptSS->Add(hist3);
          hist_promptSS->Add(hist4);
          hist_promptSS->Add(hist5);
          hist_promptSS->Add(hist6);
          //scale to lumi
          hist1->Scale(lumi());
          hist2_260->Scale(lumi());
          hist2_300->Scale(lumi());
          hist2_400->Scale(lumi());
          hist2_500->Scale(lumi());
          hist_promptSS->Scale(lumi());
          //add to total bkg
          TH1 *hist_bkg=(TH1*)hist_promptSS->Clone("hist_bkg");//total bkg
          if(i!=1)hist_bkg->Add(hist_QmisID);
          hist_bkg->Add(hist_fake);

          //get max y
          Float_t Ymaximum=0.;
          if(1.2*(GetMaxBinContent(hist1)/GHTBCs(hist1))>Ymaximum) Ymaximum=1.2*(GetMaxBinContent(hist1)/GHTBCs(hist1));
          if(1.2*(GetMaxBinContent(hist2_260)/GHTBCs(hist2_260))>Ymaximum) Ymaximum=1.2*(GetMaxBinContent(hist2_260)/GHTBCs(hist2_260)); 
          if(1.2*(GetMaxBinContent(hist2_300)/GHTBCs(hist2_300))>Ymaximum) Ymaximum=1.2*(GetMaxBinContent(hist2_300)/GHTBCs(hist2_300)); 
          if(1.2*(GetMaxBinContent(hist2_400)/GHTBCs(hist2_400))>Ymaximum) Ymaximum=1.2*(GetMaxBinContent(hist2_400)/GHTBCs(hist2_400)); 
          if(1.2*(GetMaxBinContent(hist2_500)/GHTBCs(hist2_500))>Ymaximum) Ymaximum=1.2*(GetMaxBinContent(hist2_500)/GHTBCs(hist2_500)); 
 if(1.2*(GetMaxBinContent(hist_promptSS)/GHTBCs(hist_promptSS))>Ymaximum) Ymaximum=1.2*(GetMaxBinContent(hist_promptSS)/GHTBCs(hist_promptSS));
 if(1.2*(GetMaxBinContent(hist_QmisID)/GHTBCs(hist_QmisID))>Ymaximum) Ymaximum=1.2*(GetMaxBinContent(hist_QmisID)/GHTBCs(hist_QmisID));
 if(1.2*(GetMaxBinContent(hist_fake)/GHTBCs(hist_fake))>Ymaximum) Ymaximum=1.2*(GetMaxBinContent(hist_fake)/GHTBCs(hist_fake));
 if(1.2*(GetMaxBinContent(hist_bkg)/GHTBCs(hist_bkg))>Ymaximum) Ymaximum=1.2*(GetMaxBinContent(hist_bkg)/GHTBCs(hist_bkg));
          Int_t nbins=hist2_260->GetNbinsX();
          Int_t xmin=0,xmax=hist2_260->GetBinWidth(1)*nbins+xmin;
          TH1F *frame=new TH1F("frame","",nbins,xmin,xmax);
          TCanvas *c=new TCanvas("c","",900,700);
          gStyle->SetLineWidth(3);
          hist1->SetLineColor(kRed+2);
          hist2_260->SetLineColor(kRed);
          hist2_300->SetLineColor(kBlue);
          hist2_400->SetLineColor(kGreen);
          hist2_500->SetLineColor(kViolet);
          hist_promptSS->SetLineColor(kCyan);
          hist_fake->SetLineColor(kPink);
          if(i!=1)hist_QmisID->SetLineColor(kOrange);
          hist_bkg->SetLineColor(kBlack);
          //hist_promptSS->SetLineStyle(2);
          //hist_fake->SetLineStyle(8);
          //hist_fake->SetLineStyle();
          //hist1->DrawNormalized();
          frame->GetXaxis()->SetTitle(var);          
          frame->GetYaxis()->SetRangeUser(0.,Ymaximum);
          frame->Draw();
          hist1->DrawNormalized("same");
          //hist2_260->DrawNormalized("same");          
          //hist2_300->DrawNormalized("same"); 
          //hist2_400->DrawNormalized("same"); 
          //hist2_500->DrawNormalized("same"); 
          //hist_promptSS->DrawNormalized("same"); 
          //hist_fake->DrawNormalized("same"); 
          //if(i!=1)hist_QmisID->DrawNormalized("same"); 
          hist_bkg->DrawNormalized("same");
          TLegend *leg_c= new TLegend(0.6,0.7,0.89,0.89);
          leg_c->SetNColumns(2);
          leg_c->SetFillStyle(0);
          leg_c->SetBorderSize(0);
          leg_c->SetNColumns(2);
          leg_c->SetFillStyle(0);
          leg_c->SetBorderSize(0);
          leg_c->SetTextFont(62);
          leg_c->SetTextSize(0.03);         
          leg_c->AddEntry(hist1,"non-res","l");
          //leg_c->AddEntry(hist2_260,"H260","l");
          //leg_c->AddEntry(hist2_300,"H300","l");
          //leg_c->AddEntry(hist2_400,"H400","l");
          //leg_c->AddEntry(hist2_500,"H500","l");
          //leg_c->AddEntry(hist_promptSS,"promptSS","l");
          //if(i!=1)leg_c->AddEntry(hist_QmisID,"QmisID","l");
          //leg_c->AddEntry(hist_fake,"Fakes","l");
          leg_c->AddEntry(hist_bkg,"total bkg","l");
          leg_c->Draw("same");          
          TString output_plot="output/plots/";
          output_plot += hist;
          output_plot += ".png";
          c->SaveAs(output_plot);         
      }
  }
}
