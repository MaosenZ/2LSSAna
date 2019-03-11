#include "TROOT.h"
#include "TFile.h"
#include "THStack.h"
#include "TLegend.h"
#include "TAxis.h"
#include "TH1.h"
#include "TCanvas.h"
#include "../inc/SampleHandler.h"
#include "../src/GHTBCs.cxx"
#include "../../atlasstyle-00-03-05/AtlasStyle.C"
#include "../../atlasstyle-00-03-05/AtlasUtils.C"
#include "../src/lumi.cxx"

using namespace std;
int main(){
  SetAtlasStyle();
  //ATLASLabel(0.2,0.2,"Preliminary");
  //  gStyle->SetLegendFillColor(0);
  //
  SampleHandler data("data15");
  SampleHandler diboson("diboson");
  SampleHandler ttV("ttV");
  SampleHandler ttH("ttH");
  SampleHandler Wjets("Wjets");
  SampleHandler Zjets("Zjets");
  SampleHandler ttbar("ttbar");
  SampleHandler Vgam("Vgam");
  SampleHandler singletop("singletop");
  SampleHandler DY("DY");
  data.cutflow(); diboson.cutflow(); ttV.cutflow(); 
  ttH.cutflow(); Wjets.cutflow(); Zjets.cutflow(); ttbar.cutflow(); Vgam.cutflow(); singletop.cutflow(); DY.cutflow(); 
  TFile *f_data=new TFile("temp/hists_cutflow_data15.root");
  TFile *f_Wjets   =new TFile("temp/hists_cutflow_Wjets.root");
  TFile *f_Zjets    =new TFile("temp/hists_cutflow_Zjets.root");
  TFile *f_ttbar    =new TFile("temp/hists_cutflow_ttbar.root");
  TFile *f_Vgam    =new TFile("temp/hists_cutflow_Vgam.root");
  TFile *f_diboson    =new TFile("temp/hists_cutflow_diboson.root");
  TFile *f_ttH    =new TFile("temp/hists_cutflow_ttH.root");
  TFile *f_ttV    =new TFile("temp/hists_cutflow_ttV.root");
  TFile *f_sigletop    =new TFile("temp/hists_cutflow_singletop.root");
  TFile *f_DY    =new TFile("temp/hists_cutflow_DY.root");

  TString cates[]={"ee","mumu","emu"};
  TString vars[]={"m_ll","met"};
  for(Int_t i=0;i<3;i++){
      for(Int_t j=0;j<2;j++){
          TString cate=cates[i];
          TString var=vars[j];
          TString stack="hs_";stack+=var;stack+="_";stack+=cate;
          TString hist="hist_";hist+=var;hist+="_"; hist+=cate;
          TString output="output/nominal/";output+=var;output+="_";output+=cate;output+=".png";
  THStack *hs_m_ll_emu = new THStack(stack,"");
  hs_m_ll_emu->SetMinimum(0.01);
  hs_m_ll_emu->SetMaximum(1000);

  //TH1 *hist_m_ll_emu_signal           = (TH1*)f_signal->Get("m_ll");
  TH1 *hist_m_ll_emu_data    =(TH1*)f_data     ->Get(hist);
  TH1 *hist_m_ll_emu_Wjets   = (TH1*)f_Wjets   ->Get(hist);
  TH1 *hist_m_ll_emu_Zjets    = (TH1*)f_Zjets    ->Get(hist);  
  TH1 *hist_m_ll_emu_ttbar    = (TH1*)f_ttbar    ->Get(hist);  
  TH1 *hist_m_ll_emu_Vgam    = (TH1*)f_Vgam    ->Get(hist);  
  TH1 *hist_m_ll_emu_diboson    = (TH1*)f_diboson    ->Get(hist);  
  TH1 *hist_m_ll_emu_ttH    = (TH1*)f_ttH    ->Get(hist);  
  TH1 *hist_m_ll_emu_ttV    = (TH1*)f_ttV    ->Get(hist);  
  TH1 *hist_m_ll_emu_sigletop    = (TH1*)f_sigletop    ->Get(hist);  
  TH1 *hist_m_ll_emu_DY    = (TH1*)f_DY ->Get(hist);  

  hist_m_ll_emu_data           ->SetMarkerStyle(20);
  hist_m_ll_emu_data           ->GetXaxis()->SetTitle("m_ll_emu");
  hist_m_ll_emu_data           ->SetMarkerColor(kBlack);
  hist_m_ll_emu_data->GetYaxis()->SetTitle("Entries");
  //hist_m_ll_emu_signal->SetLineWidth(2);
  //hist_m_ll_emu_signal->SetLineColor(kRed+1);
  hist_m_ll_emu_Wjets   ->SetFillColor(2);  
  hist_m_ll_emu_Zjets    ->SetFillColor(3); 
  hist_m_ll_emu_ttbar    ->SetFillColor(4); 
  hist_m_ll_emu_Vgam    ->SetFillColor(5); 
  hist_m_ll_emu_diboson    ->SetFillColor(6); 
  //hist_m_ll_emu_WW    ->SetFillColor(7); 
  //hist_m_ll_emu_ZZ    ->SetFillColor(8); 
  hist_m_ll_emu_ttH    ->SetFillColor(11); 
  hist_m_ll_emu_ttV    ->SetFillColor(40); 
  hist_m_ll_emu_sigletop    ->SetFillColor(18); 
  hist_m_ll_emu_DY    ->SetFillColor(32); 
  //hist_m_ll_emu_VH    ->SetFillColor(1); 
  
  //Double_t signal_entries=hist_m_ll_emu_signal->GetEntries();
  hist_m_ll_emu_Wjets   ->Scale(lumi());  
  hist_m_ll_emu_Zjets    ->Scale(lumi()); 
  hist_m_ll_emu_ttbar    ->Scale(lumi()); 
  hist_m_ll_emu_Vgam    ->Scale(lumi()); 
  hist_m_ll_emu_diboson    ->Scale(lumi()); 
  //hist_m_ll_emu_WW    ->Scale(3209); 
  //hist_m_ll_emu_ZZ    ->Scale(3209); 
  hist_m_ll_emu_ttH    ->Scale(lumi()); 
  hist_m_ll_emu_ttV    ->Scale(lumi()); 
  hist_m_ll_emu_sigletop    ->Scale(lumi()); 
  hist_m_ll_emu_DY    ->Scale(lumi()); 
  //hist_m_ll_emu_VH    ->Scale(lumi()); 
  //hist_m_ll_emu_signal->Scale(119*0.324*0.324*2*lumi()/signal_entries); 
  cout<<"data: "<<GHTBCs(hist_m_ll_emu_data)<<endl;
  cout<<"Wjets: "<<GHTBCs(hist_m_ll_emu_Wjets)<<endl;
  cout<<"Zjets: "<<GHTBCs(hist_m_ll_emu_Zjets)<<endl;
  cout<<"ttbar: "<<GHTBCs(hist_m_ll_emu_ttbar)<<endl;
  cout<<"Vgam: "<<GHTBCs(hist_m_ll_emu_Vgam)<<endl;
  cout<<"diboson: "<<GHTBCs(hist_m_ll_emu_diboson)<<endl;
  cout<<"ttV: "<<GHTBCs(hist_m_ll_emu_ttV)<<endl;
  cout<<"sigletop: "<<GHTBCs(hist_m_ll_emu_sigletop)<<endl;
  cout<<"DY: "<<GHTBCs(hist_m_ll_emu_DY)<<endl;
  hs_m_ll_emu->Add(hist_m_ll_emu_sigletop     );
  hs_m_ll_emu->Add(hist_m_ll_emu_ttH     );
  hs_m_ll_emu->Add(hist_m_ll_emu_DY     );
  //hs_m_ll_emu->Add(hist_m_ll_emu_VH     );
  hs_m_ll_emu->Add(hist_m_ll_emu_ttV     );
  hs_m_ll_emu->Add(hist_m_ll_emu_Vgam     );
  hs_m_ll_emu->Add(hist_m_ll_emu_diboson     );
  hs_m_ll_emu->Add(hist_m_ll_emu_Wjets     );
  hs_m_ll_emu->Add(hist_m_ll_emu_ttbar    );
  hs_m_ll_emu->Add(hist_m_ll_emu_Zjets     );
  /*hs_m_ll_emu->Add(hist_m_ll_emu_Zjets     );
  hs_m_ll_emu->Add(hist_m_ll_emu_ttbar     );
  hs_m_ll_emu->Add(hist_m_ll_emu_diboson     );
  hs_m_ll_emu->Add(hist_m_ll_emu_ttV     );
  hs_m_ll_emu->Add(hist_m_ll_emu_ttH     );
  hs_m_ll_emu->Add(hist_m_ll_emu_Vgam     );
  hs_m_ll_emu->Add(hist_m_ll_emu_DY     );
  hs_m_ll_emu->Add(hist_m_ll_emu_sigletop     );*/
  //hs_m_ll_emu->Add(hist_m_ll_emu_Wjets    );

 
  TCanvas *cs_m_ll_ee = new TCanvas();
  TPad *pad1 = new TPad("pad1", "pad1", 0.00, 0.35, 1.00, 1.00);
  TPad *pad2 = new TPad("pad2", "pad2", 0.00, 0.00, 1.00, 0.30);
  pad1->SetMargin(0.12, 0.03, 0.22, 0.035); // L R B T
  pad2->SetMargin(0.12, 0.03, 0.15, 0.03);
  pad1->SetMargin(0.12, 0.03, 0.22, 0.035); // L R B T
  pad2->SetMargin(0.12, 0.03, 0.15, 0.03);
  pad1->SetBorderMode(0);
  pad1->SetFrameFillStyle(4000);
  pad1->SetFillStyle(4000);
  pad2->SetFillStyle(4000);
  pad2->SetBorderMode(0);
  pad2->SetFrameFillStyle(4000);

  pad1->SetBottomMargin(0.01); // Upper and lower plot are joined
  pad1->SetTopMargin(0.1);
  pad1->SetBorderMode(0);

  pad1->SetTickx();
  pad1->SetTicky();         // Vertical grid
  pad1->Draw();             // Draw the upper pad: pad1
  //gPad->cd();      
  pad1->SetLogy();
  pad1->cd();
  TLegend *leg= new TLegend(0.78,0.50,0.88,0.88);
  //leg->AddEntry(hist_m_ll_emu_signal   ,"signal","l");
  leg->AddEntry(hist_m_ll_emu_Zjets   ,"Zjets  ","f");  
  leg->AddEntry(hist_m_ll_emu_ttbar    ,"ttbar   ","f"); 
  leg->AddEntry(hist_m_ll_emu_Wjets    ,"Wjets   ","f"); 
  leg->AddEntry(hist_m_ll_emu_diboson    ,"diboson   ","f"); 
  leg->AddEntry(hist_m_ll_emu_Vgam    ,"Vgam   ","f"); 
  leg->AddEntry(hist_m_ll_emu_DY    ,"DY","f");
  leg->AddEntry(hist_m_ll_emu_ttV    ,"ttV","f"); 
  leg->AddEntry(hist_m_ll_emu_sigletop    ,"singletop","f"); 
  leg->AddEntry(hist_m_ll_emu_ttH    ,"ttH","f");
  //hs_m_ll_emu->GetYaxis()->SetLabelSize(0.1);
  //hs_m_ll_emu->GetXaxis()->SetLabelSize(0);
  hist_m_ll_emu_data->GetYaxis()->SetTitleSize(0.1);
  hs_m_ll_emu->Draw();
  hist_m_ll_emu_data->Draw("EO same");
  //hist_m_ll_emu_signal->Draw("HIST same");
  leg->Draw("HIST SAME");
  ATLAS_LABEL(0.23, 0.68 ); 
  myText( 0.37, 0.68 , 1, "Internal");
  myText( 0.23, 0.79 , 1, "#sqrt{s} = 13 TeV");
  myText( 0.43, 0.79 , 1, "#int L dt = 3.2 fb^{-1}");

  
  cs_m_ll_emu->cd();          // Go back to the main canvas before defining pad2
  TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.33);
 // pad2->SetTopMargin(0.00001);
  pad2->SetBottomMargin(0.3);
  pad2->SetBorderMode(0);
  pad2->SetTickx(); // vertical grid
  pad2->SetTicky();
  pad2->Draw();
  pad2->cd(); 
  Int_t Nbins=hist_m_ll_emu_data->GetNbinsX();
  Int_t Xmaximum=(hist_m_ll_emu_data->GetBinWidth(1)) *Nbins;
  Int_t Ymaximum=2;double total_data=0,total_MC=0,total_MC_error=0;
  //Int_t Nbins=200;
  Double_t m_ll[200],m_ll_error[200]; double ratio[200], ratio_error[200];
  for(int i=0;i<Nbins;i++){
     m_ll[i]=(i+0.5)*(hist_m_ll_emu_data->GetBinWidth(i));
     m_ll_error[i]=hist_m_ll_emu_data->GetBinWidth(i)/2;
     Double_t data_bincontent=hist_m_ll_emu_data->GetBinContent(i+1);total_data+=data_bincontent;
     Double_t MC_bincontent=(hist_m_ll_emu_Zjets->GetBinContent(i+1)+hist_m_ll_emu_ttbar->GetBinContent(i+1)+
                            hist_m_ll_emu_Wjets->GetBinContent(i+1)+hist_m_ll_emu_Vgam->GetBinContent(i+1)+
                            hist_m_ll_emu_ttV->GetBinContent(i+1)+hist_m_ll_emu_sigletop->GetBinContent(i+1)+
                            hist_m_ll_emu_DY->GetBinContent(i+1)+hist_m_ll_emu_diboson->GetBinContent(i+1)+
                            hist_m_ll_emu_ttH->GetBinContent(i+1));total_MC+=MC_bincontent;
     if(data_bincontent==0 || MC_bincontent==0){
        ratio[i]=0;
        ratio_error[i]=0;
     }
     else{
        Double_t data_binerror=hist_m_ll_emu_data->GetBinError(i);
        Double_t MC_binerror=sqrt(MC_bincontent);
        total_MC_error+=(MC_binerror*MC_binerror);
        cout<<"data_bincontent: "<<data_bincontent;
        cout<<" MC_bincontent: "<<MC_bincontent<<endl;
        ratio[i]=(double)data_bincontent/(double)MC_bincontent;
        //cout<<"(double)MC_bincontent/(double)data_bincontent: "<<(double)data_bincontent/(double)MC_bincontent<<endl;
        //ratio[i]=1.0;
        //ratio_error[i]=sqrt(data_binerror/data_bincontent + MC_binerror / MC_bincontent);
        ratio_error[i]=data_binerror/MC_bincontent;
        if(ratio_error[i]>2)Ymaximum=ratio_error[i]*1.5;
     }
  }
  cout<<"total data: "<<total_data; cout<<"    total MC:"<<total_MC;cout<<"  total MC error: "<<sqrt(total_MC_error)<<endl;
  TGraphErrors *Graph_ratio=new TGraphErrors(20,m_ll,ratio,m_ll_error,ratio_error);
  TLine *line1 = new TLine(0, 1, Xmaximum, 1);
  TLine *line2 = new TLine(0, 2, Xmaximum, 2);
  line1->SetLineStyle(2);
  line2->SetLineStyle(2);
  line1->SetLineWidth(2);
  line2->SetLineWidth(2);
  Graph_ratio->GetXaxis()->SetTitleSize(0.10);
  //Graph_ratio->GetYaxis()->CenterTitle();
  Graph_ratio->GetYaxis()->SetTitleSize(0.08);
  Graph_ratio->GetYaxis()->SetTitleOffset(0.35);
  Graph_ratio->GetXaxis()->SetTitleOffset(0.7);
  Graph_ratio->GetXaxis()->SetLabelSize(0.1);
  Graph_ratio->GetYaxis()->SetLabelSize(0.1);
  Graph_ratio->GetXaxis()->SetLimits(0,Xmaximum);
  Graph_ratio->GetYaxis()->SetLimits(0,2.);
  Graph_ratio->SetLineStyle(1);
  Graph_ratio->SetMarkerStyle(20);
  Graph_ratio->GetXaxis()->SetTitle("m_ll");
  Graph_ratio->SetTitle("");
  Graph_ratio->GetYaxis()->SetTitle("data/MC");
  Graph_ratio->Draw("ap");
  line1->Draw("same");
  line2->Draw("same");
  cs_m_ll_emu->SaveAs(output);
  }
  }
  return 0;
}
