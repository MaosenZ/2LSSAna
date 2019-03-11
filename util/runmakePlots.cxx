#include "../inc/miniNtuple.h"
#include "THStack.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "../src/GHTBCs.cxx"
#include "../../atlasstyle-00-03-05/AtlasStyle.C"
#include "../../atlasstyle-00-03-05/AtlasUtils.C"
#include <iomanip>

int main(int argc, char *argv[]){
  SetAtlasStyle();
  string masspoint=argv[1]; 
  Float_t ff_ele, ff_mu, sys_ele, sys_mu;
  if(masspoint=="mH260" || masspoint=="mH300" || masspoint=="H280_S135" || masspoint=="H300_S135" || masspoint=="H320_S135"){
         ff_ele=0.5401; ff_mu=0.5033; sys_ele=0.6309; sys_mu=0.6455;
  }
  else if(masspoint=="mH400" || masspoint=="mH500" || masspoint=="nonres" || masspoint=="H340_S135" || masspoint=="H340_S145"
               || masspoint=="H340_S155" || masspoint=="H340_S165"){
         ff_ele=0.5472; ff_mu=0.4544; sys_ele=0.6918; sys_mu=0.7179;
  } 
 
  miniNtuple signal(masspoint,masspoint,"Data-driven"); 
  miniNtuple data(masspoint,"datacombined","Data-driven"); 
  miniNtuple QmisID(masspoint,"QmisID","Data-driven"); 
  miniNtuple Vgam(masspoint,"Vgam","Data-driven"); 
  miniNtuple promptSS(masspoint,"promptSS","Data-driven"); 
  miniNtuple fake(masspoint,"fake","Data-driven"); 
  TString var=argv[2],varx_title;
  Float_t Nbins, xmin, xmax;
  if(var=="m_ll") {Nbins=15; xmin=0; xmax=300; varx_title="M(ll)";}
  if(var=="m_l1jj") {Nbins=14; xmin=0; xmax=700; varx_title="M(l#lower[0.5]{1}jj)";}
  if(var=="mindR_l1j"){ Nbins=14; xmin=0; xmax=3.5; varx_title="#DeltaR_{min}(l#lower[0.5]{1},j)";}
  if(var=="mindR_l2j"){ Nbins=14; xmin=0; xmax=3.5;varx_title="#DeltaR_{min}(l#lower[0.5]{2},j)";}
  if(var=="m_all") {Nbins=30; xmin=0; xmax=1500;varx_title="M(all)";}
      TString output_ee_pdf="/scratchfs/atlas/zhoums/2LSSAna_output/output/SigOpt/"; output_ee_pdf+=masspoint+"_";output_ee_pdf+=var; output_ee_pdf+="_ee.pdf";
      TString output_mumu_pdf="/scratchfs/atlas/zhoums/2LSSAna_output/output/SigOpt/"; output_mumu_pdf+=masspoint+"_"; output_mumu_pdf+=var; output_mumu_pdf+="_mumu.pdf";
      TString output_emu_pdf="/scratchfs/atlas/zhoums/2LSSAna_output/output/SigOpt/"; output_emu_pdf+=masspoint+"_";  output_emu_pdf+=var; output_emu_pdf+="_emu.pdf";
      TString output_yield_pdf="/scratchfs/atlas/zhoums/2LSSAna_output/output/";
      output_yield_pdf+=masspoint+"_yield.pdf";
  //for Jason, to save to root file
  TString outrootname="/scratchfs/atlas/zhoums/2LSSAna_output/output/SigOpt/";
  outrootname+=masspoint+"_allcuts.root";
  TFile *outroot=new TFile(outrootname,"recreate");

  TH1::SetDefaultSumw2();
  TH1F *frame_ee=new TH1F("frame_ee","",Nbins,xmin,xmax);
  THStack *hs_ee=new THStack("hs_ee","");
  TH1F *hist_data_ee=new TH1F("hist_data_ee","",Nbins,xmin,xmax);
  TH1F *hist_signal_ee=new TH1F("hist_signal_ee","",Nbins,xmin,xmax);
  TH1F *hist_promptSS_ee=new TH1F("hist_promptSS_ee","",Nbins,xmin,xmax);
  TH1F *hist_Vgam_ee=new TH1F("hist_Vgam_ee","",Nbins,xmin,xmax);
  TH1F *hist_QmisID_ee=new TH1F("hist_QmisID_ee","",Nbins,xmin,xmax);
  TH1F *hist_fake_ee=new TH1F("hist_fake_ee","",Nbins,xmin,xmax);
  
  TH1F *frame_mumu=new TH1F("frame_mumu","",Nbins,xmin,xmax);
  THStack *hs_mumu=new THStack("hs_mumu","");
  TH1F *hist_data_mumu=new TH1F("hist_data_mumu","",Nbins,xmin,xmax);
  TH1F *hist_signal_mumu=new TH1F("hist_signal_mumu","",Nbins,xmin,xmax);
  TH1F *hist_promptSS_mumu=new TH1F("hist_promptSS_mumu","",Nbins,xmin,xmax);
  TH1F *hist_Vgam_mumu=new TH1F("hist_Vgam_mumu","",Nbins,xmin,xmax);
  TH1F *hist_QmisID_mumu=new TH1F("hist_QmisID_mumu","",Nbins,xmin,xmax);
  TH1F *hist_fake_mumu=new TH1F("hist_fake_mumu","",Nbins,xmin,xmax);

  TH1F *frame_emu=new TH1F("frame_emu","",Nbins,xmin,xmax);
  THStack *hs_emu=new THStack("hs_emu","");
  TH1F *hist_data_emu=new TH1F("hist_data_emu","",Nbins,xmin,xmax);
  TH1F *hist_signal_emu=new TH1F("hist_signal_emu","",Nbins,xmin,xmax);
  TH1F *hist_promptSS_emu=new TH1F("hist_promptSS_emu","",Nbins,xmin,xmax);
  TH1F *hist_Vgam_emu=new TH1F("hist_Vgam_emu","",Nbins,xmin,xmax);
  TH1F *hist_QmisID_emu=new TH1F("hist_QmisID_emu","",Nbins,xmin,xmax);
  TH1F *hist_fake_emu=new TH1F("hist_fake_emu","",Nbins,xmin,xmax);
  TH1F *hist_fake_antiemu=new TH1F("hist_fake_antiemu","",Nbins,xmin,xmax);
  TH1F *hist_fake_eantimu=new TH1F("hist_fake_eantimu","",Nbins,xmin,xmax);

  //for event yields plots
  TH1F *frame_ratio_yield=new TH1F("hist_ratio_yield","",3,0,3);
  TH1F *frame_yield=new TH1F("frame_yield","",3,0,3);
  THStack *hs_yield=new THStack("hs_yield",""); 
  TH1F *hist_data=new TH1F("hist_data","",3,0,3);
  TH1F *hist_signal=new TH1F("hist_signal","",3,0,3);
  TH1F *hist_promptSS=new TH1F("hist_promptSS","",3,0,3);
  TH1F *hist_QmisID=new TH1F("hist_QmisID","",3,0,3);
  TH1F *hist_fake=new TH1F("hist_fake","",3,0,3);
  TH1F *hist_Vgam=new TH1F("hist_Vgam","",3,0,3);

  //no worry, hist_fake_antiemu,hist_fake_eantimu, will only be filled in fake
  data.makeTH1Fs(hist_data_ee,hist_data_mumu,hist_data_emu,hist_fake_antiemu,hist_fake_eantimu,Nbins,xmin,xmax,var);
  signal.makeTH1Fs(hist_signal_ee,hist_signal_mumu,hist_signal_emu,hist_fake_antiemu,hist_fake_eantimu,Nbins,xmin,xmax,var);
  if(masspoint=="nonres") {
     hist_signal_ee->Scale(33.41/1000);
     hist_signal_mumu->Scale(33.41/1000);
     hist_signal_mumu->Scale(33.41/1000);
  }
  cout<<"data done"<<endl;
  promptSS.makeTH1Fs(hist_promptSS_ee,hist_promptSS_mumu,hist_promptSS_emu,hist_fake_antiemu,hist_fake_eantimu,Nbins,xmin,xmax,var);
  cout<<"promptSS done"<<endl;
  Vgam.makeTH1Fs(hist_Vgam_ee,hist_Vgam_mumu,hist_Vgam_emu,hist_fake_antiemu,hist_fake_eantimu,Nbins,xmin,xmax,var);
  cout<<"Vgam done"<<endl;
  QmisID.makeTH1Fs(hist_QmisID_ee,hist_QmisID_mumu,hist_QmisID_emu,hist_fake_antiemu,hist_fake_eantimu,Nbins,xmin,xmax,var);
  cout<<"QmisID done"<<endl;
  fake.makeTH1Fs(hist_fake_ee,hist_fake_mumu,hist_fake_emu,hist_fake_antiemu,hist_fake_eantimu,Nbins,xmin,xmax,var);
  cout<<"fake done"<<endl;
  hist_data_ee->Write();
  hist_data_mumu->Write();
  hist_data_emu->Write();
  hist_fake_antiemu->Write();
  hist_fake_eantimu->Write();
  hist_signal_ee->Write();
  hist_signal_mumu->Write();
  hist_signal_emu->Write();
  hist_promptSS_ee->Write();
  hist_promptSS_mumu->Write();
  hist_promptSS_emu->Write();
  hist_Vgam_ee->Write();
  hist_Vgam_mumu->Write();
  hist_Vgam_emu->Write();
  hist_QmisID_ee->Write();
  hist_QmisID_mumu->Write();
  hist_QmisID_emu->Write();
  hist_fake_ee->Write();
  hist_fake_mumu->Write();
  hist_fake_emu->Write();
  //outroot->Close();
  //add
  //----------------------------------------------------------------------------------
      // do some delcarations before drawing plots
      //----------------------------------------------------------------------------------
      // add hists to hs, ee
      hist_fake_ee->SetFillColor(40);
      hist_promptSS_ee->SetFillColor(43);
      hist_Vgam_ee->SetFillColor(49);
      hist_QmisID_ee->SetFillColor(47);
      hist_fake_ee->SetLineColor(40);
      hist_promptSS_ee->SetLineColor(43);
      hist_Vgam_ee->SetLineColor(49);
      hist_QmisID_ee->SetLineColor(47);
      hs_ee->Add(hist_promptSS_ee);
      hs_ee->Add(hist_Vgam_ee);
      hs_ee->Add(hist_QmisID_ee);
      //hs_ee->Add(hist_fake_ee); //add it later,first calculate total error as we should estimate the uncertainty for fakes separately. 
      Double_t varx[200],varx_error[200],ratio_ee[200],ratio_error_ee[200];
      Double_t ratio_bkg_ee[200],ratio_error_bkg_ee[200];
      Double_t stack_ee[200],stack_error_ee[200];
      //mumu
      hist_fake_mumu->SetFillColor(40);
      hist_promptSS_mumu->SetFillColor(43);
      hist_Vgam_mumu->SetFillColor(49);
      hist_fake_mumu->SetLineColor(40);
      hist_promptSS_mumu->SetLineColor(43);
      hist_Vgam_mumu->SetLineColor(49);
      hs_mumu->Add(hist_promptSS_mumu);
      hs_mumu->Add(hist_Vgam_mumu);
      //hs_mumu->Add(hist_fake_mumu);
      Double_t ratio_mumu[200],ratio_error_mumu[200];
      Double_t ratio_bkg_mumu[200],ratio_error_bkg_mumu[200];
      Double_t stack_mumu[200],stack_error_mumu[200];
      //emu
      hist_fake_emu->SetFillColor(40);
      hist_promptSS_emu->SetFillColor(43);
      hist_Vgam_emu->SetFillColor(49);
      hist_QmisID_emu->SetFillColor(47);
      hist_fake_emu->SetLineColor(40);
      hist_promptSS_emu->SetLineColor(43);
      hist_Vgam_emu->SetLineColor(49);
      hist_QmisID_emu->SetLineColor(47);
      hs_emu->Add(hist_promptSS_emu);
      hs_emu->Add(hist_Vgam_emu);
      hs_emu->Add(hist_QmisID_emu);
      //hs_emu->Add(hist_fake_emu);
      Double_t ratio_emu[200],ratio_error_emu[200];
      Double_t ratio_bkg_emu[200],ratio_error_bkg_emu[200];
      Double_t stack_emu[200],stack_error_emu[200];
      //----------------------------------------------------------------------------------
      // count
      //----------------------------------------------------------------------------------
      cout<<setw(5)<<"ee"<<setw(10)<<"mm"<<setw(10)<<"em"<<endl;
      cout<<setiosflags(ios::fixed)<<setprecision(2);
      double err_fake_ee(0), err_fake_mumu(0), err_fake_emu(0),
             err_totalbkg_ee(0), err_totalbkg_mumu(0), err_totalbkg_emu(0),
             err_Vgam_ee(0), err_Vgam_mumu(0), err_Vgam_emu(0),
             err_QmisID_ee(0), err_QmisID_mumu(0), err_QmisID_emu(0),
             err_predicted_ee(0), err_predicted_mumu(0), err_predicted_emu(0),
             err_data_ee(0), err_data_mumu(0), err_data_emu(0),
             err_predicted_ee_nofake(0), err_predicted_mumu_nofake(0), err_predicted_emu_nofake(0);
      double integral_fake_ee(0), integral_fake_mumu(0), integral_fake_emu(0),
             integral_totalbkg_ee(0), integral_totalbkg_mumu(0), integral_totalbkg_emu(0),
             integral_Vgam_ee(0), integral_Vgam_mumu(0), integral_Vgam_emu(0),
             integral_QmisID_ee(0), integral_QmisID_mumu(0), integral_QmisID_emu(0),
             integral_predicted_ee(0), integral_predicted_mumu(0), integral_predicted_emu(0),
             integral_data_ee(0), integral_data_mumu(0), integral_data_emu(0);
      integral_fake_ee=hist_fake_ee->Integral(0,Nbins+1);
      integral_fake_mumu=hist_fake_mumu->Integral(0,Nbins+1);
      integral_fake_emu=hist_fake_emu->Integral(0,Nbins+1);
      err_fake_ee=sqrt(pow(sys_ele*integral_fake_ee,2)+integral_fake_ee*ff_ele);
      err_fake_mumu=sqrt(pow(sys_mu*integral_fake_mumu,2)+integral_fake_mumu*ff_mu);
      Double_t num_eantimu=hist_fake_eantimu->Integral(0,Nbins+1);
      Double_t num_antiemu=hist_fake_antiemu->Integral(0,Nbins+1);
      err_fake_emu=sqrt(pow(sys_mu*num_eantimu,2)+ff_mu*num_eantimu +
                    pow(sys_ele*num_antiemu,2)+ff_ele*num_antiemu);
      integral_totalbkg_ee=hist_promptSS_ee->IntegralAndError(0,Nbins+1,err_totalbkg_ee);
      integral_totalbkg_mumu=hist_promptSS_mumu->IntegralAndError(0,Nbins+1,err_totalbkg_mumu);
      integral_totalbkg_emu=hist_promptSS_emu->IntegralAndError(0,Nbins+1,err_totalbkg_emu);
      integral_Vgam_ee=hist_Vgam_ee->IntegralAndError(0,Nbins+1,err_Vgam_ee);
      integral_Vgam_mumu=hist_Vgam_mumu->IntegralAndError(0,Nbins+1,err_Vgam_mumu);
      integral_Vgam_emu=hist_Vgam_emu->IntegralAndError(0,Nbins+1,err_Vgam_emu);
      integral_QmisID_ee=hist_QmisID_ee->IntegralAndError(0,Nbins+1,err_QmisID_ee);
      integral_QmisID_mumu=hist_QmisID_mumu->IntegralAndError(0,Nbins+1,err_QmisID_mumu);
      integral_QmisID_emu=hist_QmisID_emu->IntegralAndError(0,Nbins+1,err_QmisID_emu);
      integral_predicted_ee=((TH1*)(hs_ee->GetStack()->Last()))->IntegralAndError(0,Nbins+1,err_predicted_ee_nofake)+
                            hist_fake_ee->Integral(0,Nbins+1);;
      integral_predicted_mumu=((TH1*)(hs_mumu->GetStack()->Last()))->IntegralAndError(0,Nbins+1,err_predicted_mumu_nofake)+
                            hist_fake_mumu->Integral(0,Nbins+1);
      integral_predicted_emu=((TH1*)(hs_emu->GetStack()->Last()))->IntegralAndError(0,Nbins+1,err_predicted_emu_nofake)+
                            hist_fake_emu->Integral(0,Nbins+1);
      err_predicted_ee=sqrt(pow(err_predicted_ee_nofake,2)+pow(err_fake_ee,2));
      err_predicted_mumu=sqrt(pow(err_predicted_mumu_nofake,2)+pow(err_fake_mumu,2));
      err_predicted_emu=sqrt(pow(err_predicted_emu_nofake,2)+pow(err_fake_emu,2));
      integral_data_ee=hist_data_ee->IntegralAndError(0,Nbins+1,err_data_ee);
      integral_data_mumu=hist_data_mumu->IntegralAndError(0,Nbins+1,err_data_mumu);
      integral_data_emu=hist_data_emu->IntegralAndError(0,Nbins+1,err_data_emu);
      cout<<"Jet fakes "<<setw(8)<<"&"<<integral_fake_ee<<"$\\pm$"<<err_fake_ee<<setw(10)<<
                          setw(8)<<"&"<<integral_fake_mumu<<"$\\pm$"<<err_fake_mumu<<setw(10)<<
                          setw(8)<<"&"<<integral_fake_emu<<"$\\pm$"<<err_fake_emu<<setw(10)<<endl;
      cout<<"PromptSS "<<setw(8)<<"&"<<integral_totalbkg_ee<<"$\\pm$"<<err_totalbkg_ee<<setw(10)<<
                          setw(8)<<"&"<<integral_totalbkg_mumu<<"$\\pm$"<<err_totalbkg_mumu<<setw(10)<<
                          setw(8)<<"&"<<integral_totalbkg_emu<<"$\\pm$"<<err_totalbkg_emu<<setw(10)<<endl;
      cout<<"$V+\\gamma$ "<<setw(8)<<"&"<<integral_Vgam_ee<<"$\\pm$"<<err_Vgam_ee<<setw(10)<<
                          setw(8)<<"&"<<integral_Vgam_mumu<<"$\\pm$"<<err_Vgam_mumu<<setw(10)<<
                          setw(8)<<"&"<<integral_Vgam_emu<<"$\\pm$"<<err_Vgam_emu<<setw(10)<<endl;
      cout<<"QmisID "<<setw(8)<<"&"<<integral_QmisID_ee<<"$\\pm$"<<err_QmisID_ee<<setw(10)<<
                        setw(8)<<"&"<<integral_QmisID_mumu<<"$\\pm$"<<err_QmisID_mumu<<setw(10)<<
                        setw(8)<<"&"<<integral_QmisID_emu<<"$\\pm$"<<err_QmisID_emu<<setw(10)<<endl;
      cout<<"Total predicted "<<setw(8)<<"&"<<integral_predicted_ee<<"$\\pm$"<<err_predicted_ee<<setw(10)<<
                                 setw(8)<<"&"<<integral_predicted_mumu<<"$\\pm$"<<err_predicted_mumu<<setw(10)<<
                                 setw(8)<<"&"<<integral_predicted_emu<<"$\\pm$"<< err_predicted_emu<<endl;
      cout<<"Observed "<<setw(8)<<"&"<<integral_data_ee<<"$\\pm$"<<err_data_ee<<setw(10)<<
                          setw(8)<<"&"<<integral_data_mumu<<"$\\pm$"<<err_data_mumu<<setw(10)<<
                          setw(8)<<"&"<<integral_data_emu<<"$\\pm$"<<err_data_emu<<setw(10)<<endl;
      //fill event yield plots
      hist_fake->SetFillColor(40);
      hist_promptSS->SetFillColor(43);
      hist_Vgam->SetFillColor(49);
      hist_QmisID->SetFillColor(47);
      hist_fake->SetLineColor(40);
      hist_promptSS->SetLineColor(43);
      hist_Vgam->SetLineColor(49);
      hist_QmisID->SetLineColor(47);
 
      hist_data->SetBinContent(1,integral_data_ee);
      hist_data->SetBinContent(2,integral_data_mumu);
      hist_data->SetBinContent(3,integral_data_emu);
      hist_data->SetBinError(1,sqrt(integral_data_ee));
      hist_data->SetBinError(2,sqrt(integral_data_mumu));
      hist_data->SetBinError(3,sqrt(integral_data_emu));
      hist_promptSS->SetBinContent(1,integral_totalbkg_ee);
      hist_promptSS->SetBinContent(2,integral_totalbkg_mumu);
      hist_promptSS->SetBinContent(3,integral_totalbkg_emu);
      hist_fake->SetBinContent(1,integral_fake_ee);
      hist_fake->SetBinContent(2,integral_fake_mumu);
      hist_fake->SetBinContent(3,integral_fake_emu);
      hist_QmisID->SetBinContent(1,integral_QmisID_ee);
      hist_QmisID->SetBinContent(3,integral_QmisID_emu);
      double integral_signal_ee=hist_signal_ee->Integral(0,Nbins+1);
      double integral_signal_mumu=hist_signal_mumu->Integral(0,Nbins+1);
      double integral_signal_emu=hist_signal_emu->Integral(0,Nbins+1);
      hist_signal->SetBinContent(1,integral_signal_ee);
      hist_signal->SetBinContent(2,integral_signal_mumu);
      hist_signal->SetBinContent(3,integral_signal_emu);
      hist_Vgam->SetBinContent(1,integral_Vgam_ee);
      hist_Vgam->SetBinContent(2,integral_Vgam_mumu);
      hist_Vgam->SetBinContent(3,integral_Vgam_emu);
      hs_yield->Add(hist_promptSS);
      hs_yield->Add(hist_Vgam);
      hs_yield->Add(hist_QmisID);
      hs_yield->Add(hist_fake);
      //get ratios, errors, etc..ee
      for(Int_t bin=0;bin<Nbins;bin++){
          //ratio, mean values, width, first determined here, commonly used for 3 channels
          varx[bin]=xmin+(0.5+bin)*(hist_fake_ee->GetBinWidth(1));
          varx_error[bin]=(hist_fake_ee->GetBinWidth(1))/2.;
          //data, bkg bincontents and errors
          Double_t bincontent_data=hist_data_ee->GetBinContent(bin+1);
          Double_t binerror_data=hist_data_ee->GetBinError(bin+1);
          Double_t bincontent_bkg_nofake=hist_promptSS_ee->GetBinContent(bin+1)+hist_Vgam_ee->GetBinContent(bin+1)+
                                   hist_QmisID_ee->GetBinContent(bin+1);
          Double_t bincontent_bkg_fake=hist_fake_ee->GetBinContent(bin+1);
          Double_t bincontent_bkg=bincontent_bkg_nofake+bincontent_bkg_fake;
          Double_t binerror_bkg_nofake=sqrt( pow(hist_promptSS_ee->GetBinError(bin+1),2)+pow(hist_Vgam_ee->GetBinError(bin+1),2) +
                                 pow(hist_QmisID_ee->GetBinError(bin+1),2) );
          Double_t binerror_fake=sqrt(pow(sys_ele*bincontent_bkg_fake,2)+ff_ele*bincontent_bkg_fake);
          Double_t binerror_bkg=0;
          if(binerror_fake!=binerror_fake && binerror_bkg_nofake>=0.0) binerror_bkg=binerror_bkg_nofake;
          if(binerror_fake>=0.0 && binerror_bkg_nofake!=binerror_bkg_nofake) binerror_bkg=binerror_fake;
          if(binerror_fake>=0.0 && binerror_bkg_nofake>=0.0)  binerror_bkg=sqrt(pow(binerror_bkg_nofake,2)+pow(binerror_fake,2));
          //to get bkg errors
          stack_ee[bin]=bincontent_bkg; stack_error_ee[bin]=binerror_bkg;
          //ratio plot: mean values, data error, bkg error
          ratio_ee[bin]=bincontent_data/bincontent_bkg;
          ratio_error_ee[bin]=binerror_data/bincontent_bkg;
          ratio_bkg_ee[bin]=1.;
          ratio_error_bkg_ee[bin]=binerror_bkg/bincontent_bkg;
          if(stack_ee[bin]!=stack_ee[bin]) stack_ee[bin]=0;
          if(stack_error_ee[bin]!=stack_error_ee[bin]) stack_error_ee[bin]=0;
          if(ratio_ee[bin]!=ratio_ee[bin]) ratio_ee[bin]=0;
          if(ratio_error_ee[bin]!=ratio_error_ee[bin]) ratio_error_ee[bin]=0;
          if(ratio_error_bkg_ee[bin]!=ratio_error_bkg_ee[bin]) ratio_error_bkg_ee[bin]=0;
      }
            //mumu
      for(Int_t bin=0;bin<Nbins;bin++){
          //data, bkg bincontents and errors
          Double_t bincontent_data=hist_data_mumu->GetBinContent(bin+1);
          Double_t binerror_data=hist_data_mumu->GetBinError(bin+1);
          Double_t bincontent_bkg_nofake=hist_promptSS_mumu->GetBinContent(bin+1)+hist_Vgam_mumu->GetBinContent(bin+1);
          Double_t bincontent_bkg_fake=hist_fake_mumu->GetBinContent(bin+1);
          Double_t bincontent_bkg=bincontent_bkg_nofake+bincontent_bkg_fake;
          //Double_t binerror_bkg_nofake=((TH1*)(hs_mumu->GetStack()->Last()))->GetBinError(bin+1);//wrong!!
          Double_t binerror_bkg_nofake=sqrt( pow(hist_promptSS_mumu->GetBinError(bin+1),2)+pow(hist_Vgam_mumu->GetBinError(bin+1),2));
          Double_t binerror_fake=sqrt(pow(sys_mu*bincontent_bkg_fake,2)+ff_mu*bincontent_bkg_fake);
          Double_t binerror_bkg=0;
          if(binerror_fake!=binerror_fake && binerror_bkg_nofake>=0.0) binerror_bkg=binerror_bkg_nofake;
          if(binerror_fake>=0.0 && binerror_bkg_nofake!=binerror_bkg_nofake) binerror_bkg=binerror_fake;
          if(binerror_fake>=0.0 && binerror_bkg_nofake>=0.0)  binerror_bkg=sqrt(pow(binerror_bkg_nofake,2)+pow(binerror_fake,2));
          //to get bkg errors
          stack_mumu[bin]=bincontent_bkg; stack_error_mumu[bin]=binerror_bkg;
          //ratio plot: mean values, data error, bkg error
          ratio_mumu[bin]=bincontent_data/bincontent_bkg;
          ratio_error_mumu[bin]=binerror_data/bincontent_bkg;
          ratio_bkg_mumu[bin]=1.;
          ratio_error_bkg_mumu[bin]=binerror_bkg/bincontent_bkg;
          /*cout<<"<<<<<<<<<<<<<<<<<<<<<<"<<endl;
          cout<<bincontent_data<<" : "<<bincontent_bkg<<" : "<<ratio_mumu[bin]<<endl;
          cout<<binerror_data<<" : "<<binerror_bkg<<" : "<<ratio_error_mumu[bin]<<endl;
          cout<<">>>>>>>>>>>>>>>>>>>>>>"<<endl;*/
          if(stack_mumu[bin]!=stack_mumu[bin]) stack_mumu[bin]=0;
          if(stack_error_mumu[bin]!=stack_error_mumu[bin]) stack_error_mumu[bin]=0;
          if(ratio_mumu[bin]!=ratio_mumu[bin]) ratio_mumu[bin]=0;
          if(ratio_error_mumu[bin]!=ratio_error_mumu[bin]) ratio_error_mumu[bin]=0;
          if(ratio_error_bkg_mumu[bin]!=ratio_error_bkg_mumu[bin]) ratio_error_bkg_mumu[bin]=0;
      }
            //emu
      for(Int_t bin=0;bin<Nbins;bin++){
          //data, bkg bincontents and errors
          Double_t bincontent_data=hist_data_emu->GetBinContent(bin+1);
          Double_t binerror_data=hist_data_emu->GetBinError(bin+1);
          Double_t bincontent_bkg_nofake=hist_promptSS_emu->GetBinContent(bin+1)+hist_Vgam_emu->GetBinContent(bin+1)+                                        hist_QmisID_emu->GetBinContent(bin+1);
          Double_t bincontent_bkg_fake_antiemu=hist_fake_antiemu->GetBinContent(bin+1);
          Double_t bincontent_bkg_fake_eantimu=hist_fake_eantimu->GetBinContent(bin+1);
          Double_t bincontent_bkg_fake=hist_fake_emu->GetBinContent(bin+1);
          Double_t bincontent_bkg=bincontent_bkg_nofake+bincontent_bkg_fake;
          Double_t binerror_bkg_nofake=sqrt( pow(hist_promptSS_emu->GetBinError(bin+1),2)+pow(hist_Vgam_emu->GetBinError(bin+1),2) +                                      pow(hist_QmisID_emu->GetBinError(bin+1),2) );;
          Double_t binerror_bkg_fake=sqrt(pow(sys_ele*bincontent_bkg_fake_antiemu,2)+ff_ele*bincontent_bkg_fake_antiemu +
                                         pow(sys_mu*bincontent_bkg_fake_eantimu,2)+ff_mu*bincontent_bkg_fake_eantimu);
          Double_t binerror_bkg=0;
          if(binerror_bkg_fake!=binerror_bkg_fake && binerror_bkg_nofake>=0.0) binerror_bkg=binerror_bkg_nofake;
          if(binerror_bkg_fake>=0.0 && binerror_bkg_nofake!=binerror_bkg_nofake) binerror_bkg=binerror_bkg_fake;
          if(binerror_bkg_fake>=0.0 && binerror_bkg_nofake>=0.0)  binerror_bkg=sqrt(pow(binerror_bkg_nofake,2)+pow(binerror_bkg_fake,2));
          //to get bkg errors
          stack_emu[bin]=bincontent_bkg; stack_error_emu[bin]=binerror_bkg;
          //ratio plot: mean values, data error, bkg error
          ratio_emu[bin]=bincontent_data/bincontent_bkg;
          ratio_error_emu[bin]=binerror_data/bincontent_bkg;
          ratio_bkg_emu[bin]=1.;
          ratio_error_bkg_emu[bin]=binerror_bkg/bincontent_bkg;
          if(stack_emu[bin]!=stack_emu[bin]) stack_emu[bin]=0;
          if(stack_error_emu[bin]!=stack_error_emu[bin]) stack_error_emu[bin]=0;
          if(ratio_emu[bin]!=ratio_emu[bin]) ratio_emu[bin]=0;
          if(ratio_error_emu[bin]!=ratio_error_emu[bin]) ratio_error_emu[bin]=0;
          if(ratio_error_bkg_emu[bin]!=ratio_error_bkg_emu[bin]) ratio_error_bkg_emu[bin]=0;
      }
      hs_ee->Add(hist_fake_ee);
      hs_mumu->Add(hist_fake_mumu);
      hs_emu->Add(hist_fake_emu);
      //-----------------------------------------------------------------------------
      //draw plots
      //-----------------------------------------------------------------------------
      Double_t Ymaximum_ee=0, Ymaximum_mumu=0, Ymaximum_emu=0;
      Ymaximum_ee=2.0*GetMaxBinContent(hist_data_ee);
      if(Ymaximum_ee<2.0*GetMaxBinContent(hs_ee))Ymaximum_ee=2.0*GetMaxBinContent(hs_ee);
      Ymaximum_mumu=2.0*GetMaxBinContent(hist_data_mumu);
      if(Ymaximum_mumu<2.0*GetMaxBinContent(hs_mumu))Ymaximum_mumu=2.0*GetMaxBinContent(hs_mumu);
      Ymaximum_emu=2.0*GetMaxBinContent(hist_data_emu);
      if(Ymaximum_emu<2.0*GetMaxBinContent(hs_emu))Ymaximum_emu=2.0*GetMaxBinContent(hs_emu);
      Float_t sum_data_ee=hist_data_ee->Integral(0,Nbins+1);
      Float_t sum_data_mumu=hist_data_mumu->Integral(0,Nbins+1);
      Float_t sum_data_emu=hist_data_emu->Integral(0,Nbins+1);
      /*Float_t sum_nonres_ee=hist_nonres_ee->Integral(0,Nbins+1);
      Float_t sum_nonres_mumu=hist_nonres_mumu->Integral(0,Nbins+1);
      Float_t sum_nonres_emu=hist_nonres_emu->Integral(0,Nbins+1);
      Float_t sum_mH260_ee=hist_mH260_ee->Integral(0,Nbins+1);
      Float_t sum_mH260_mumu=hist_mH260_mumu->Integral(0,Nbins+1);
      Float_t sum_mH260_emu=hist_mH260_emu->Integral(0,Nbins+1);
      Float_t sum_H280_S135_ee=hist_H280_S135_ee->Integral(0,Nbins+1);
      Float_t sum_H280_S135_mumu=hist_H280_S135_mumu->Integral(0,Nbins+1);
      Float_t sum_H280_S135_emu=hist_H280_S135_emu->Integral(0,Nbins+1);
      Float_t sum_mH400_ee=hist_mH400_ee->Integral(0,Nbins+1);
      Float_t sum_mH400_mumu=hist_mH400_mumu->Integral(0,Nbins+1);
      Float_t sum_mH400_emu=hist_mH400_emu->Integral(0,Nbins+1);
      Float_t sum_mH500_ee=hist_mH500_ee->Integral(0,Nbins+1);
      Float_t sum_mH500_mumu=hist_mH500_mumu->Integral(0,Nbins+1);
      Float_t sum_mH500_emu=hist_mH500_emu->Integral(0,Nbins+1);
      Float_t sum_mH300_ee=hist_mH300_ee->Integral(0,Nbins+1);
      Float_t sum_mH300_mumu=hist_mH300_mumu->Integral(0,Nbins+1);
      Float_t sum_mH300_emu=hist_mH300_emu->Integral(0,Nbins+1);
      Float_t sum_H340_S135_ee=hist_H340_S135_ee->Integral(0,Nbins+1);
      Float_t sum_H340_S135_mumu=hist_H340_S135_mumu->Integral(0,Nbins+1);
      Float_t sum_H340_S135_emu=hist_H340_S135_emu->Integral(0,Nbins+1);
      Float_t sum_H340_S165_ee=hist_H340_S165_ee->Integral(0,Nbins+1);
      Float_t sum_H340_S165_mumu=hist_H340_S165_mumu->Integral(0,Nbins+1);
      Float_t sum_H340_S165_emu=hist_H340_S165_emu->Integral(0,Nbins+1);
      hist_nonres_ee->Scale(sum_data_ee*0.5/sum_nonres_ee);
      hist_nonres_mumu->Scale(sum_data_mumu*0.5/sum_nonres_mumu);
      hist_nonres_emu->Scale(sum_data_emu*0.5/sum_nonres_emu);
      hist_mH260_ee->Scale(sum_data_ee*0.5/sum_mH260_ee);
      hist_mH260_mumu->Scale(sum_data_mumu*0.5/sum_mH260_mumu);
      hist_mH260_emu->Scale(sum_data_emu*0.5/sum_mH260_emu);
      hist_mH300_ee->Scale(sum_data_ee*0.5/sum_mH300_ee);
      hist_mH300_mumu->Scale(sum_data_mumu*0.5/sum_mH300_mumu);
      hist_mH300_emu->Scale(sum_data_emu*0.5/sum_mH300_emu);
      hist_H280_S135_ee->Scale(sum_data_ee*0.5/sum_H280_S135_ee);
      hist_H280_S135_mumu->Scale(sum_data_mumu*0.5/sum_H280_S135_mumu);
      hist_H280_S135_emu->Scale(sum_data_emu*0.5/sum_H280_S135_emu);
      hist_mH400_ee->Scale(sum_data_ee*0.5/sum_mH400_ee);
      hist_mH400_mumu->Scale(sum_data_mumu*0.5/sum_mH400_mumu);
      hist_mH400_emu->Scale(sum_data_emu*0.5/sum_mH400_emu);
      hist_mH500_ee->Scale(sum_data_ee*0.5/sum_mH500_ee);
      hist_mH500_mumu->Scale(sum_data_mumu*0.5/sum_mH500_mumu);
      hist_mH500_emu->Scale(sum_data_emu*0.5/sum_mH500_emu);
      hist_H340_S135_ee->Scale(sum_data_ee*0.5/sum_H340_S135_ee);
      hist_H340_S135_mumu->Scale(sum_data_mumu*0.5/sum_H340_S135_mumu);
      hist_H340_S135_emu->Scale(sum_data_emu*0.5/sum_H340_S135_emu);
      hist_H340_S165_ee->Scale(sum_data_ee*0.5/sum_H340_S165_ee);
      hist_H340_S165_mumu->Scale(sum_data_mumu*0.5/sum_H340_S165_mumu);
      hist_H340_S165_emu->Scale(sum_data_emu*0.5/sum_H340_S165_emu);*/
      //ee
      TCanvas *c_hist_ee=new TCanvas("c_hist_ee","",900,800);
      gStyle->SetLineWidth(2);
      gPad->SetLineWidth(2);
      TPad *pad1_ee=new TPad("pad1_ee","pad1_ee",0,0.33,1,1.0);
      pad1_ee->SetBottomMargin(0.0); // Upper and lower plot are joined
      pad1_ee->SetTopMargin(0.05);
      pad1_ee->Draw();
      pad1_ee->cd();
      TLegend *leg_ee= new TLegend(0.60,0.45,0.97,0.90);
      leg_ee->SetFillStyle(0);
      leg_ee->SetBorderSize(0);
      leg_ee->SetTextFont(62);
      leg_ee->SetTextSize(0.03);
      leg_ee->AddEntry(hist_signal_ee,"Signal","l");
      /*leg_ee->AddEntry(hist_mH300_ee,"mX=300 GeV","l");
      leg_ee->AddEntry(hist_mH400_ee,"mX=400 GeV","l");
      leg_ee->AddEntry(hist_mH500_ee,"mX=500 GeV","l");
      leg_ee->AddEntry(hist_nonres_ee,"Non-resonant","l");
      leg_ee->AddEntry(hist_H280_S135_ee,"mX=280 GeV, mS=135 GeV","l");
      leg_ee->AddEntry(hist_H340_S135_ee,"mX=340 GeV, mS=135 GeV","l");
      leg_ee->AddEntry(hist_H340_S165_ee,"mX=340 GeV, mS=165 GeV","l");*/
      leg_ee->AddEntry(hist_data_ee,"Data","lp");
      leg_ee->AddEntry(hist_promptSS_ee,"promptSS","f");
      leg_ee->AddEntry(hist_Vgam_ee,"V#gamma","f");
      leg_ee->AddEntry(hist_QmisID_ee,"QmisID","f");
      leg_ee->AddEntry(hist_fake_ee,"Fakes","f");
      frame_ee->SetMaximum(Ymaximum_ee);
      frame_ee->SetMinimum(0.1);
      frame_ee->GetYaxis()->SetTitleSize(0.06);
      frame_ee->GetYaxis()->SetTitleOffset(1);
      frame_ee->GetYaxis()->SetTitle("Num. Of Events");
      hist_signal_ee->SetLineColor(kRed);
      /*hist_mH300_ee->SetLineColor(kGreen);
      hist_mH400_ee->SetLineColor(7);
      hist_mH500_ee->SetLineColor(kBlue);
      hist_nonres_ee->SetLineColor(9);
      hist_H280_S135_ee->SetLineColor(kOrange);
      hist_H340_S135_ee->SetLineColor(8);
      hist_H340_S165_ee->SetLineColor(38);
      hist_H280_S135_ee->SetLineStyle(4);
      hist_H340_S135_ee->SetLineStyle(6);
      hist_H340_S165_ee->SetLineStyle(8);*/
      frame_ee->Draw();
      hs_ee->Draw("histsame");      
      hist_signal_ee->Draw("histsame");
      /*hist_mH300_ee->Draw("histsame");
      hist_mH400_ee->Draw("histsame");
      hist_mH500_ee->Draw("histsame");
      hist_nonres_ee->Draw("histsame");
      hist_H280_S135_ee->Draw("histsame");
      hist_H340_S135_ee->Draw("histsame");
      hist_H340_S165_ee->Draw("histsame");*/
      hist_data_ee->Draw("e same");
      ATLAS_LABEL(0.20, 0.87 );
      myText( 0.31, 0.87 , 1, "Internal");
      myText( 0.20, 0.78 , 1, "#sqrt{s} = 13 TeV");
      myText( 0.37, 0.78 , 1, "#intLdt = 36.1 fb^{-1}");
      myText(0.55, 0.87, 1, "ee");
      TGraphErrors *gr_stack_ee=new TGraphErrors(Nbins,varx,stack_ee,varx_error,stack_error_ee);
      gr_stack_ee->SetFillColor(6);
      gr_stack_ee->SetLineColor(6);
      gStyle->SetHatchesLineWidth(1);
      gr_stack_ee->SetFillStyle(3254);
      gr_stack_ee->Draw("2");
      leg_ee->AddEntry(gr_stack_ee,"Stat.+Syst.","f");
      leg_ee->Draw("same");
      c_hist_ee->Update();
      //pad2, for ratio
      c_hist_ee->cd();
      TPad *pad2_ee = new TPad("pad2_ee", "pad2_ee", 0, 0.01, 1, 0.33);
      pad2_ee->SetTopMargin(0);
      pad2_ee->SetBottomMargin(0.30);
      pad2_ee->SetTicks(); // vertical grid
      pad2_ee->Draw();
      pad2_ee->cd();
      TGraphErrors *gr_ee=new TGraphErrors(Nbins,varx,ratio_ee,varx_error,ratio_error_ee);
      gr_ee->GetYaxis()->SetTitle("Data/Bkg");
      gr_ee->GetXaxis()->SetTitle(varx_title);
      gr_ee->GetXaxis()->SetLabelSize(0.1);
      gr_ee->GetXaxis()->SetLabelOffset(0.025);
      gr_ee->GetXaxis()->SetTitleSize(0.13);
      gr_ee->GetXaxis()->SetTitleOffset(1.);
      gr_ee->GetYaxis()->SetLabelSize(0.1);
      gr_ee->GetYaxis()->SetTitleSize(0.14);
      gr_ee->GetYaxis()->SetTitleOffset(0.40);
      gr_ee->GetYaxis()->SetNdivisions(505);
      gr_ee->SetMarkerSize(0.4);
      gr_ee->SetMarkerStyle(20);
      gr_ee->GetXaxis()->SetRangeUser(xmin,xmax);
      gr_ee->GetYaxis()->SetRangeUser(0,2.1);
      gr_ee->Draw("AP0 same");
      TLine* line_ee=new TLine();
      line_ee->DrawLine(xmin,1.0,xmax,1.0);
      line_ee->SetLineColor(kBlack);
      line_ee->SetLineStyle(kDashed);
      line_ee->DrawLine(xmin,0.5,xmax,0.5);
      line_ee->DrawLine(xmin,1.5,xmax,1.5);
      TGraphErrors *gr_ratio_bkg_ee=new TGraphErrors(Nbins,varx,ratio_bkg_ee,varx_error,ratio_error_bkg_ee);
      gr_ratio_bkg_ee->SetFillColor(6);
      gr_ratio_bkg_ee->SetFillStyle(3254);
      gr_ratio_bkg_ee->Draw("2 same");
      c_hist_ee->SaveAs(output_ee_pdf);
      //c_hist_ee->SaveAs(output_ee_eps);
      //mumu 
      TCanvas *c_hist_mumu=new TCanvas("c_hist_mumu","",900,800);
      gStyle->SetLineWidth(2);  
      gPad->SetLineWidth(2);
      TPad *pad1_mumu=new TPad("pad1_mumu","pad1_mumu",0,0.33,1,1.0);
      pad1_mumu->SetBottomMargin(0.0); // Upper and lower plot are joined
      pad1_mumu->SetTopMargin(0.05);
      pad1_mumu->Draw();
      pad1_mumu->cd();
      TLegend *leg_mumu= new TLegend(0.6,0.50,0.97,0.90);
      leg_mumu->SetFillStyle(0);
      leg_mumu->SetBorderSize(0);
      leg_mumu->SetTextFont(62);
      leg_mumu->SetTextSize(0.03);
      leg_mumu->AddEntry(hist_signal_mumu,"Signal","l");
      /*leg_mumu->AddEntry(hist_mH300_mumu,"mX=300 GeV","l");
      leg_mumu->AddEntry(hist_mH400_mumu,"mX=400 GeV","l");
      leg_mumu->AddEntry(hist_mH500_mumu,"mX=500 GeV","l");
      leg_mumu->AddEntry(hist_nonres_mumu,"Non-resonant","l");
      leg_mumu->AddEntry(hist_H280_S135_mumu,"mX=280 GeV, mS=135 GeV","l");
      leg_mumu->AddEntry(hist_H340_S135_mumu,"mX=340 GeV, mS=135 GeV","l");
      leg_mumu->AddEntry(hist_H340_S165_mumu,"mX=340 GeV, mS=165 GeV","l");*/
      leg_mumu->AddEntry(hist_data_mumu,"Data","lp");
      leg_mumu->AddEntry(hist_promptSS_mumu,"promptSS","f");
      leg_mumu->AddEntry(hist_Vgam_mumu,"V#gamma","f");
      //leg_mumu->AddEntry(hist_QmisID_mumu,"QmisID","f");
      leg_mumu->AddEntry(hist_fake_mumu,"Fakes","f");
      frame_mumu->SetMaximum(Ymaximum_mumu);
      frame_mumu->SetMinimum(0.1);
      frame_mumu->GetYaxis()->SetTitleSize(0.06);
      frame_mumu->GetYaxis()->SetTitleOffset(1);
      frame_mumu->GetYaxis()->SetTitle("Num. Of Events");
      hist_signal_mumu->SetLineColor(kRed);
      /*hist_mH300_mumu->SetLineColor(kGreen);
      hist_mH400_mumu->SetLineColor(7);
      hist_mH500_mumu->SetLineColor(kBlue);
      hist_nonres_mumu->SetLineColor(9);
      hist_H280_S135_mumu->SetLineColor(kOrange);
      hist_H340_S135_mumu->SetLineColor(8);
      hist_H340_S165_mumu->SetLineColor(38);
      hist_H280_S135_mumu->SetLineStyle(4);
      hist_H340_S135_mumu->SetLineStyle(6);
      hist_H340_S165_mumu->SetLineStyle(8);*/
      frame_mumu->Draw();
      hs_mumu->Draw("histsame");
      hist_signal_mumu->Draw("histsame");
      /*hist_H280_S135_mumu->Draw("histsame");
      hist_mH300_mumu->Draw("histsame");
      hist_mH400_mumu->Draw("histsame");
      hist_mH500_mumu->Draw("histsame");
      hist_nonres_mumu->Draw("histsame");
      hist_H340_S135_mumu->Draw("histsame");
      hist_H340_S165_mumu->Draw("histsame");*/
      hist_data_mumu->Draw("e same");
      ATLAS_LABEL(0.20, 0.87 );
      myText( 0.31, 0.87 , 1, "Internal");
      myText( 0.20, 0.78 , 1, "#sqrt{s} = 13 TeV");
      myText( 0.37, 0.78 , 1, "#intLdt = 36.1 fb^{-1}");
      myText(0.55, 0.87, 1, "#mu#mu");
      TGraphErrors *gr_stack_mumu=new TGraphErrors(Nbins,varx,stack_mumu,varx_error,stack_error_mumu);
      gr_stack_mumu->SetFillColor(6);
      gr_stack_mumu->SetLineColor(6);
      gr_stack_mumu->SetFillStyle(3254);
      gr_stack_mumu->Draw("2");
      leg_mumu->AddEntry(gr_stack_mumu,"Stat.+Syst.","f");
      leg_mumu->Draw("same");
      c_hist_mumu->Update();
      //pad2, for ratio
      c_hist_mumu->cd();
      TPad *pad2_mumu = new TPad("pad2_mumu", "pad2_mumu", 0, 0.01, 1, 0.33);
      pad2_mumu->SetTopMargin(0);
      pad2_mumu->SetBottomMargin(0.30);
      pad2_mumu->SetTicks(); // vertical grid
      pad2_mumu->Draw();
      pad2_mumu->cd();
      TGraphErrors *gr_mumu=new TGraphErrors(Nbins,varx,ratio_mumu,varx_error,ratio_error_mumu);
      gr_mumu->GetYaxis()->SetTitle("Data/Bkg");
      gr_mumu->GetXaxis()->SetTitle(varx_title);
      gr_mumu->GetXaxis()->SetLabelSize(0.1);
      gr_mumu->GetXaxis()->SetLabelOffset(0.025);
      gr_mumu->GetXaxis()->SetTitleSize(0.13);
      gr_mumu->GetXaxis()->SetTitleOffset(1.);
      gr_mumu->GetYaxis()->SetLabelSize(0.1);
      gr_mumu->GetYaxis()->SetTitleSize(0.14);
      gr_mumu->GetYaxis()->SetTitleOffset(0.40);
      gr_mumu->GetYaxis()->SetNdivisions(505);
      gr_mumu->SetMarkerSize(0.4);
      gr_mumu->SetMarkerStyle(20);
      gr_mumu->GetXaxis()->SetRangeUser(xmin,xmax);
      gr_mumu->GetYaxis()->SetRangeUser(0,2.1);
      gr_mumu->Draw("AP0"); //0 option make sure points outside range to be drawn
      pad2_mumu->Update();
      TLine* line_mumu=new TLine();
      line_mumu->DrawLine(xmin,1.0,xmax,1.0);
      line_mumu->SetLineColor(kBlack);
      line_mumu->SetLineStyle(kDashed);
      line_mumu->DrawLine(xmin,0.5,xmax,0.5);
      line_mumu->DrawLine(xmin,1.5,xmax,1.5);
      TGraphErrors *gr_ratio_bkg_mumu=new TGraphErrors(Nbins,varx,ratio_bkg_mumu,varx_error,ratio_error_bkg_mumu);
      gr_ratio_bkg_mumu->SetFillColor(6);
      gr_ratio_bkg_mumu->SetFillStyle(3254);
      gr_ratio_bkg_mumu->Draw("2");
      //c_hist_mumu->SaveAs(output_mumu_eps);
      c_hist_mumu->SaveAs(output_mumu_pdf);
      //emu 
      TCanvas *c_hist_emu=new TCanvas("c_hist_emu","",900,800);
      gStyle->SetLineWidth(2);  
      gPad->SetLineWidth(2);
      TPad *pad1_emu=new TPad("pad1_emu","pad1_emu",0,0.33,1,1.0);
      pad1_emu->SetBottomMargin(0.0); // Upper and lower plot are joined
      pad1_emu->SetTopMargin(0.05);
      pad1_emu->Draw();
      pad1_emu->cd();
      TLegend *leg_emu= new TLegend(0.60,0.50,0.97,0.90);
      leg_emu->SetFillStyle(0);
      leg_emu->SetBorderSize(0);
      leg_emu->SetTextFont(62);
      leg_emu->SetTextSize(0.03);
      leg_emu->AddEntry(hist_signal_emu,"Signal","l");
      /*leg_emu->AddEntry(hist_mH300_emu,"mX=300 GeV","l");
      leg_emu->AddEntry(hist_mH400_emu,"mX=400 GeV","l");
      leg_emu->AddEntry(hist_mH500_emu,"mX=500 GeV","l");
      leg_emu->AddEntry(hist_nonres_emu,"Non-resonant","l");
      leg_emu->AddEntry(hist_H280_S135_emu,"mX=280 GeV, mS=135 GeV","l");
      leg_emu->AddEntry(hist_H340_S135_emu,"mX=340 GeV, mS=135 GeV","l");
      leg_emu->AddEntry(hist_H340_S165_emu,"mX=340 GeV, mS=165 GeV","l");*/
      leg_emu->AddEntry(hist_data_emu,"Data","lp");
      leg_emu->AddEntry(hist_promptSS_emu,"promptSS","f");
      leg_emu->AddEntry(hist_Vgam_emu,"V#gamma","f");
      leg_emu->AddEntry(hist_QmisID_emu,"QmisID","f");
      leg_emu->AddEntry(hist_fake_emu,"Fakes","f");
      frame_emu->SetMaximum(Ymaximum_emu);
      frame_emu->SetMinimum(0.1);
      frame_emu->GetYaxis()->SetTitleSize(0.06);
      frame_emu->GetYaxis()->SetTitleOffset(1);
      frame_emu->GetYaxis()->SetTitle("Num. Of Events");
      hist_signal_emu->SetLineColor(kRed);
      /*hist_mH300_emu->SetLineColor(kGreen);
      hist_mH400_emu->SetLineColor(7);
      hist_mH500_emu->SetLineColor(kBlue);
      hist_nonres_emu->SetLineColor(9);
      hist_H280_S135_emu->SetLineColor(kOrange);
      hist_H340_S135_emu->SetLineColor(8);
      hist_H340_S165_emu->SetLineColor(38);
      hist_H280_S135_emu->SetLineStyle(4);
      hist_H340_S135_emu->SetLineStyle(6);
      hist_H340_S165_emu->SetLineStyle(8);*/
      frame_emu->Draw();
      hs_emu->Draw("histsame");
      hist_signal_emu->Draw("histsame");
      /*hist_H280_S135_emu->Draw("histsame");
      hist_mH300_emu->Draw("histsame");
      hist_H340_S135_emu->Draw("histsame");
      hist_mH400_emu->Draw("histsame");
      hist_mH500_emu->Draw("histsame");
      hist_nonres_emu->Draw("histsame");
      hist_H340_S165_emu->Draw("histsame");*/
      hist_data_emu->Draw("e same");
      ATLAS_LABEL(0.20, 0.87 );
      myText( 0.31, 0.87 , 1, "Internal");
      myText( 0.20, 0.78 , 1, "#sqrt{s} = 13 TeV");
      myText( 0.37, 0.78 , 1, "#intLdt = 36.1 fb^{-1}");
       myText(0.55, 0.87, 1, "e#mu");
      TGraphErrors *gr_stack_emu=new TGraphErrors(Nbins,varx,stack_emu,varx_error,stack_error_emu);
      gr_stack_emu->SetFillColor(6);
      gr_stack_emu->SetLineColor(6);
      gr_stack_emu->SetFillStyle(3254);
      gr_stack_emu->Draw("2 same");
      leg_emu->AddEntry(gr_stack_emu,"Stat.+Syst.","f");
      leg_emu->Draw("same");
      c_hist_emu->Update();
      //pad2, for ratio
      c_hist_emu->cd();
      TPad *pad2_emu = new TPad("pad2_emu", "pad2_emu", 0, 0.01, 1, 0.33);
      pad2_emu->SetTopMargin(0);
      pad2_emu->SetBottomMargin(0.30);
      pad2_emu->SetTicks(); // vertical grid
      pad2_emu->Draw();
      pad2_emu->cd();
      TGraphErrors *gr_emu=new TGraphErrors(Nbins,varx,ratio_emu,varx_error,ratio_error_emu);
      gr_emu->GetYaxis()->SetTitle("Data/Bkg");
      gr_emu->GetXaxis()->SetTitle(varx_title);
      gr_emu->GetXaxis()->SetLabelSize(0.1);
      gr_emu->GetXaxis()->SetLabelOffset(0.025);
      gr_emu->GetXaxis()->SetTitleSize(0.13);
      gr_emu->GetXaxis()->SetTitleOffset(1.);
      gr_emu->GetYaxis()->SetLabelSize(0.1);
      gr_emu->GetYaxis()->SetTitleSize(0.14);
      gr_emu->GetYaxis()->SetTitleOffset(0.40);
      gr_emu->GetYaxis()->SetNdivisions(505);
      gr_emu->SetMarkerSize(0.4);
      gr_emu->SetMarkerStyle(20);
      gr_emu->GetXaxis()->SetRangeUser(xmin,xmax);
      gr_emu->GetYaxis()->SetRangeUser(0,2.1);
      gr_emu->Draw("AP0 same");
      TLine* line_emu=new TLine();
      line_emu->DrawLine(xmin,1.0,xmax,1.0);
      line_emu->SetLineColor(kBlack);
      line_emu->SetLineStyle(kDashed);
      line_emu->DrawLine(xmin,0.5,xmax,0.5);
      line_emu->DrawLine(xmin,1.5,xmax,1.5);
      TGraphErrors *gr_ratio_bkg_emu=new TGraphErrors(Nbins,varx,ratio_bkg_emu,varx_error,ratio_error_bkg_emu);
      gr_ratio_bkg_emu->SetFillColor(6);
      gr_ratio_bkg_emu->SetFillStyle(3254);
      gr_ratio_bkg_emu->Draw("2 same");
      //c_hist_emu->SaveAs(output_emu_eps);
      c_hist_emu->SaveAs(output_emu_pdf);
  
      //event yield plot
      double Ymaximum_yield=hist_data->GetBinContent(3)*3;
      Double_t varx_yield[3],varx_yield_error[3],ratio_yield[3],ratio_yield_error[3];
      Double_t ratio_bkg_yield[3],ratio_bkg_yield_error[3];
      Double_t stack_yield[3],stack_yield_error[3];
      for(Int_t bin=0;bin<3;bin++){
          //ratio, mean values, width, first determined here, commonly used for 3 channels
          varx_yield[bin]=0.5+bin;
          varx_yield_error[bin]=0.5;
          //data, bkg bincontents and errors
          Double_t bincontent_data=hist_data->GetBinContent(bin+1);
          Double_t binerror_data=hist_data->GetBinError(bin+1);
          Double_t bincontent_bkg_nofake=hist_promptSS->GetBinContent(bin+1)+hist_Vgam->GetBinContent(bin+1)+
                                   hist_QmisID->GetBinContent(bin+1);
          Double_t bincontent_bkg_fake=hist_fake->GetBinContent(bin+1);
          Double_t bincontent_bkg=bincontent_bkg_nofake+bincontent_bkg_fake;
          Double_t binerror_bkg_nofake=sqrt( pow(hist_promptSS->GetBinError(bin+1),2)+
                                       pow(hist_Vgam->GetBinError(bin+1),2) +
                                       pow(hist_QmisID->GetBinError(bin+1),2) );
          Double_t binerror_fake=sqrt(pow(sys_mu*bincontent_bkg_fake,2)+ff_ele*bincontent_bkg_fake);
          Double_t binerror_bkg=0;
          if(binerror_fake!=binerror_fake && binerror_bkg_nofake>=0.0) binerror_bkg=binerror_bkg_nofake;
          if(binerror_fake>=0.0 && binerror_bkg_nofake!=binerror_bkg_nofake) binerror_bkg=binerror_fake;
          if(binerror_fake>=0.0 && binerror_bkg_nofake>=0.0)  binerror_bkg=sqrt(pow(binerror_bkg_nofake,2)+pow(binerror_fake,2));
          //to get bkg errors
          stack_yield[bin]=bincontent_bkg; stack_yield_error[bin]=binerror_bkg;
          //ratio plot: mean values, data error, bkg error
          ratio_yield[bin]=bincontent_data/bincontent_bkg;
          ratio_yield_error[bin]=binerror_data/bincontent_bkg;
          ratio_bkg_yield[bin]=1.;
          ratio_bkg_yield_error[bin]=binerror_bkg/bincontent_bkg;
          if(stack_yield[bin]!=stack_yield[bin]) stack_yield[bin]=0;
          if(stack_yield_error[bin]!=stack_yield_error[bin]) stack_yield_error[bin]=0;
          if(ratio_yield[bin]!=ratio_yield[bin]) ratio_yield[bin]=0;
          if(ratio_yield_error[bin]!=ratio_yield_error[bin]) ratio_yield_error[bin]=0;
          if(ratio_bkg_yield_error[bin]!=ratio_bkg_yield_error[bin]) ratio_bkg_yield_error[bin]=0;
      }
      TCanvas *c_hist_yield=new TCanvas("c_hist_yield","",900,800);
      gStyle->SetLineWidth(2);
      gPad->SetLineWidth(2);
      //TPad *pad1_yield=new TPad("pad1_yield","pad1_yield",0,0.33,1,1.0);
      //pad1_yield->SetBottomMargin(0.0); // Upper and lower plot are joined
      //pad1_yield->SetTopMargin(0.05);
      //pad1_yield->Draw();
      //pad1_yield->cd();
      TLegend *leg_yield= new TLegend(0.70,0.55,0.97,0.90);
      leg_yield->SetFillStyle(0);
      leg_yield->SetBorderSize(0);
      leg_yield->SetTextFont(62);
      leg_yield->SetTextSize(0.03);
      leg_yield->AddEntry(hist_signal,"Signal","l");
      leg_yield->AddEntry(hist_data,"Data","lp");
      leg_yield->AddEntry(hist_promptSS,"promptSS","f");
      leg_yield->AddEntry(hist_Vgam,"V#gamma","f");
      leg_yield->AddEntry(hist_QmisID,"QmisID","f");
      leg_yield->AddEntry(hist_fake,"Fakes","f");
      frame_yield->GetXaxis()->SetBinLabel(1,"ee");
      frame_yield->GetXaxis()->SetBinLabel(2,"#mu#mu");
      frame_yield->GetXaxis()->SetBinLabel(3,"e#mu");
      frame_yield->SetMaximum(Ymaximum_yield);
      frame_yield->SetMinimum(0.1);
      frame_yield->GetYaxis()->SetTitleSize(0.06);
      frame_yield->GetYaxis()->SetTitleOffset(1);
      frame_yield->GetYaxis()->SetTitle("Num. Of Events");
      hist_signal->SetLineColor(kRed);
      frame_yield->Draw();
      hs_yield->Draw("histsame");      
      hist_signal->Draw("histsame");
      hist_data->Draw("E same");
      cout<<"hist_data->GetOption();"<<hist_data->GetOption()<<endl;
      ATLAS_LABEL(0.20, 0.87 );
      myText( 0.35, 0.87 , 1, "Internal");
      myText( 0.20, 0.78 , 1, "#sqrt{s} = 13 TeV");
      myText( 0.45, 0.78 , 1, "#intLdt = 36.1 fb^{-1}");
      //myText(0.55, 0.87, 1, "ee");
      TGraphErrors *gr_stack_yield=new TGraphErrors(3,varx_yield,stack_yield,varx_yield_error,stack_yield_error);
      gr_stack_yield->SetFillColor(6);
      gr_stack_yield->SetLineColor(6);
      gStyle->SetHatchesLineWidth(1);
      gr_stack_yield->SetFillStyle(3254);
      gr_stack_yield->Draw("2");
      leg_yield->AddEntry(gr_stack_yield,"Stat.+Syst.","f");
      leg_yield->Draw("same");
      c_hist_yield->Update();
      //pad2, for ratio
      /*c_hist_yield->cd();
      TPad *pad2_yield = new TPad("pad2_yield", "pad2_yield", 0, 0.01, 1, 0.33);
      pad2_yield->SetTopMargin(0);
      pad2_yield->SetBottomMargin(0.30);
      pad2_yield->SetTicks(); // vertical grid
      pad2_yield->Draw();
      pad2_yield->cd();
      frame_ratio_yield->GetYaxis()->SetTitle("Data/Bkg");
      frame_ratio_yield->GetXaxis()->SetBinLabel(1,"ee");
      frame_ratio_yield->GetXaxis()->SetBinLabel(2,"#mu#mu");
      frame_ratio_yield->GetXaxis()->SetBinLabel(3,"e#mu");
      frame_ratio_yield->GetXaxis()->SetLabelSize(0.1);
      frame_ratio_yield->GetXaxis()->SetLabelOffset(0.025);
      frame_ratio_yield->GetXaxis()->SetTitleSize(0.13);
      frame_ratio_yield->GetXaxis()->SetTitleOffset(1.);
      frame_ratio_yield->GetYaxis()->SetLabelSize(0.1);
      frame_ratio_yield->GetYaxis()->SetTitleSize(0.14);
      frame_ratio_yield->GetYaxis()->SetTitleOffset(0.40);
      frame_ratio_yield->GetYaxis()->SetNdivisions(505);
      frame_ratio_yield->GetYaxis()->SetRangeUser(0,2.1);
      frame_ratio_yield->Draw();
      TGraphErrors *gr_yield=new TGraphErrors(3,varx_yield,ratio_yield,varx_yield_error,ratio_yield_error);
      gr_yield->SetMarkerSize(0.4);
      gr_yield->SetMarkerStyle(20);
      gr_yield->Draw("AP0 same");
      TLine* line_yield=new TLine();
      line_yield->DrawLine(0,1.0,3,1.0);
      line_yield->SetLineColor(kBlack);
      line_yield->SetLineStyle(kDashed);
      line_yield->DrawLine(0,0.5,3,0.5);
      line_yield->DrawLine(0,1.5,3,1.5);
      TGraphErrors *gr_ratio_bkg_yield=new TGraphErrors(3,varx_yield,ratio_bkg_yield,varx_yield_error,ratio_bkg_yield_error);
      gr_ratio_bkg_yield->SetFillColor(6);
      gr_ratio_bkg_yield->SetFillStyle(3254);
      gr_ratio_bkg_yield->Draw("2 same");*/
      c_hist_yield->SaveAs(output_yield_pdf);

      outroot->Close();
  return 0;
}
