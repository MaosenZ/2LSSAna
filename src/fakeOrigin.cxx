#include "TFile.h"
#include "TChain.h"
#include "TTree.h"
#include "THStack.h"
#include "TCanvas.h"
#include "TLegend.h"
#include <iostream>
#include "../../atlasstyle-00-03-05/AtlasStyle.C"
#include "../../atlasstyle-00-03-05/AtlasUtils.C"
using namespace std;

void fakeOrigin(){

  SetAtlasStyle();
  TChain *chain=new TChain("Tree");

  chain->Add("output/fakeOrigin/3jets/miniNtuple_FFApp_ttbar.root");
  chain->Add("output/fakeOrigin/3jets/miniNtuple_FFApp_Wjets.root");
  chain->Add("output/fakeOrigin/3jets/miniNtuple_ttbar.root");
  chain->Add("output/fakeOrigin/3jets/miniNtuple_Wjets.root");

  TH1F *hist_phcon=new TH1F("hist_phcon","",6,0,6);
  TH1F *hist_unknown=new TH1F("hist_unknown","",6,0,6); 
  TH1F *hist_bmes=new TH1F("hist_bmes","",6,0,6); 
  TH1F *hist_bbar=new TH1F("hist_bbar","",6,0,6); 
  TH1F *hist_cmes=new TH1F("hist_cmes","",6,0,6); 
  TH1F *hist_cbar=new TH1F("hist_cbar","",6,0,6); 
  TH1F *hist_ccbarmes=new TH1F("hist_ccbarmes","",6,0,6); 
  TH1F *hist_dalitz=new TH1F("hist_dalitz","",6,0,6); 
  TH1F *hist_lightmes=new TH1F("hist_lightmes","",6,0,6); 
  TH1F *hist_pionk=new TH1F("hist_pionk","",6,0,6); 
  TH1F *hist_other=new TH1F("hist_other","",6,0,6); 
  THStack *hs = new THStack("hs","");
  TH1F *frame=new TH1F("frame","",6,0,6);
  Int_t truthOrigin;
  Int_t channel;
  Double_t weight;
  TString *component=0;
 
  chain->SetBranchAddress("truthOrigin_1",&truthOrigin);
  chain->SetBranchAddress("channel",&channel);
  chain->SetBranchAddress("weight",&weight);
  chain->SetBranchAddress("component",&component);

  Double_t phcon_ee_CR(0),unknown_ee_CR(0),bmes_ee_CR(0),bbar_ee_CR(0),cmes_ee_CR(0),cbar_ee_CR(0),
           ccbarmes_ee_CR(0),dalitz_ee_CR(0),lightmes_ee_CR(0),pionk_ee_CR(0),other_ee_CR(0);
  Double_t phcon_ee_CR2(0),phcon_ee_SR2(2), B_ee_CR2(0), B_ee_SR2(0);
  Double_t phcon_mumu_CR(0),unknown_mumu_CR(0),bmes_mumu_CR(0),bbar_mumu_CR(0),cmes_mumu_CR(0),cbar_mumu_CR(0),
           ccbarmes_mumu_CR(0),dalitz_mumu_CR(0),lightmes_mumu_CR(0),pionk_mumu_CR(0),other_mumu_CR(0);
  Double_t phcon_emu_CR(0),unknown_emu_CR(0),bmes_emu_CR(0),bbar_emu_CR(0),cmes_emu_CR(0),cbar_emu_CR(0),
           ccbarmes_emu_CR(0),dalitz_emu_CR(0),lightmes_emu_CR(0),pionk_emu_CR(0),other_emu_CR(0);
  Double_t phcon_mumu_CR2(0),phcon_mumu_SR2(2), B_mumu_CR2(0), B_mumu_SR2(0);

  Double_t phcon_ee_SR(0),unknown_ee_SR(0),bmes_ee_SR(0),bbar_ee_SR(0),cmes_ee_SR(0),cbar_ee_SR(0),
           ccbarmes_ee_SR(0),dalitz_ee_SR(0),lightmes_ee_SR(0),pionk_ee_SR(0),other_ee_SR(0);
  Double_t phcon_mumu_SR(0),unknown_mumu_SR(0),bmes_mumu_SR(0),bbar_mumu_SR(0),cmes_mumu_SR(0),cbar_mumu_SR(0),
           ccbarmes_mumu_SR(0),dalitz_mumu_SR(0),lightmes_mumu_SR(0),pionk_mumu_SR(0),other_mumu_SR(0);
  Double_t phcon_emu_SR(0),unknown_emu_SR(0),bmes_emu_SR(0),bbar_emu_SR(0),cmes_emu_SR(0),cbar_emu_SR(0),
           ccbarmes_emu_SR(0),dalitz_emu_SR(0),lightmes_emu_SR(0),pionk_emu_SR(0),other_emu_SR(0);
  Double_t total_ee_CR(0), total_mumu_CR(0), total_emu_CR(0);
  Double_t total_ee_CR2(0), total_mumu_CR2(0), total_emu_CR2(0);
  Double_t total_ee_SR(0), total_mumu_SR(0), total_emu_SR(0);
  Double_t total_ee_SR2(0), total_mumu_SR2(0), total_emu_SR2(0);
  Int_t entries;
  entries=chain->GetEntries();

  for(Int_t entry=0;entry<entries;entry++){
      chain->GetEntry(entry);
      if(*component=="fake"){
         if(channel==1){
            total_ee_CR+=-weight;
            total_ee_CR2+=-weight*(-weight);
            switch(truthOrigin){
                   case 0 :{ unknown_ee_CR+=-weight;break;}    
                   case 5 :{ phcon_ee_CR+=-weight; phcon_ee_CR2+=weight*weight;break;}    
                   case 6 :{ dalitz_ee_CR+=-weight;break;}    
                   case 23 :{ lightmes_ee_CR+=-weight;break;}    
                   case 25 :{ cmes_ee_CR+=-weight;break;}    
                   case 26 :{ bmes_ee_CR+=-weight; B_ee_CR2+=weight*weight;break;}    
                   case 27 :{ ccbarmes_ee_CR+=-weight;break;}    
                   case 32 :{ cbar_ee_CR+=-weight;break;}    
                   case 33 :{ bbar_ee_CR+=-weight; B_ee_CR2+=weight*weight;break;}    
                   case 34 :{ pionk_ee_CR+=-weight;break;}    
                   case 35 :{ pionk_ee_CR+=-weight;break;} 
                   default : {other_ee_CR+=-weight;}   
            }
         }//end of ee
         if(channel==2){
            total_mumu_CR+=-weight;
            total_mumu_CR2+=-weight*(-weight);
            switch(truthOrigin){
                   case 0 :{ unknown_mumu_CR+=-weight;break;}
                   case 5 :{ phcon_mumu_CR+=-weight; phcon_mumu_CR2+=weight*weight;break;}
                   case 6 :{ dalitz_mumu_CR+=-weight;break;}
                   case 23 :{ lightmes_mumu_CR+=-weight;break;}
                   case 25 :{ cmes_mumu_CR+=-weight;break;}
                   case 26 :{ bmes_mumu_CR+=-weight;B_mumu_CR2+=weight*weight;break;}
                   case 27 :{ ccbarmes_mumu_CR+=-weight;break;}
                   case 32 :{ cbar_mumu_CR+=-weight;break;}
                   case 33 :{ bbar_mumu_CR+=-weight;B_mumu_CR2+=weight*weight;break;}
                   case 34 :{ pionk_mumu_CR+=-weight;break;}
                   case 35 :{ pionk_mumu_CR+=-weight;break;}
                   default : {other_mumu_CR+=-weight;}
            }
         }//end of mumu
         if(channel==3){
            total_emu_CR+=-weight;
            total_emu_CR2+=-weight*(-weight);
            switch(truthOrigin){
                   case 0 :{ unknown_emu_CR+=-weight;break;}
                   case 5 :{ phcon_emu_CR+=-weight;break;}
                   case 6 :{ dalitz_emu_CR+=-weight;break;}
                   case 23 :{ lightmes_emu_CR+=-weight;break;}
                   case 25 :{ cmes_emu_CR+=-weight;break;}
                   case 26 :{ bmes_emu_CR+=-weight;break;}
                   case 27 :{ ccbarmes_emu_CR+=-weight;break;}
                   case 32 :{ cbar_emu_CR+=-weight;break;}
                   case 33 :{ bbar_emu_CR+=-weight;break;}
                   case 34 :{ pionk_emu_CR+=-weight;break;}
                   case 35 :{ pionk_emu_CR+=-weight;break;}
                   default : {other_emu_CR+=-weight;}
            }
         }//end of emu
      }//end of if fake
      else{
         if(channel==1){
            total_ee_SR+=weight;
            total_ee_SR2+=weight*weight;
            switch(truthOrigin){
                   case 0 :{ unknown_ee_SR+=weight;break;}    
                   case 5 :{ phcon_ee_SR+=weight;phcon_ee_SR2+=weight*weight;break;}    
                   case 6 :{ dalitz_ee_SR+=weight;break;}    
                   case 23 :{ lightmes_ee_SR+=weight;break;}    
                   case 25 :{ cmes_ee_SR+=weight;break;}    
                   case 26 :{ bmes_ee_SR+=weight;B_ee_SR2+=weight*weight;break;}    
                   case 27 :{ ccbarmes_ee_SR+=weight;break;}    
                   case 32 :{ cbar_ee_SR+=weight;break;}    
                   case 33 :{ bbar_ee_SR+=weight;B_ee_SR2+=weight*weight;break;}    
                   case 34 :{ pionk_ee_SR+=weight;break;}    
                   case 35 :{ pionk_ee_SR+=weight;break;} 
                   default : {other_ee_SR+=weight;}   
            }
         }//end of ee
         if(channel==2){
            total_mumu_SR+=weight;
            total_mumu_SR2+=weight*weight;
            switch(truthOrigin){
                   case 0 :{ unknown_mumu_SR+=weight;break;}
                   case 5 :{ phcon_mumu_SR+=weight;phcon_mumu_SR2+=weight*weight;break;}
                   case 6 :{ dalitz_mumu_SR+=weight;break;}
                   case 23 :{ lightmes_mumu_SR+=weight;break;}
                   case 25 :{ cmes_mumu_SR+=weight;break;}
                   case 26 :{ bmes_mumu_SR+=weight;B_mumu_SR2+=weight*weight;break;}
                   case 27 :{ ccbarmes_mumu_SR+=weight;break;}
                   case 32 :{ cbar_mumu_SR+=weight;break;}
                   case 33 :{ bbar_mumu_SR+=weight;B_mumu_SR2+=weight*weight;break;}
                   case 34 :{ pionk_mumu_SR+=weight;break;}
                   case 35 :{ pionk_mumu_SR+=weight;break;}
                   default : {other_mumu_SR+=weight;}
            }
         }//end of mumu
         if(channel==3){
            total_emu_SR+=weight;
            total_emu_SR2+=weight*weight;
            switch(truthOrigin){
                   case 0 :{ unknown_emu_SR+=weight;break;}
                   case 5 :{ phcon_emu_SR+=weight;break;}
                   case 6 :{ dalitz_emu_SR+=weight;break;}
                   case 23 :{ lightmes_emu_SR+=weight;break;}
                   case 25 :{ cmes_emu_SR+=weight;break;}
                   case 26 :{ bmes_emu_SR+=weight;break;}
                   case 27 :{ ccbarmes_emu_SR+=weight;break;}
                   case 32 :{ cbar_emu_SR+=weight;break;}
                   case 33 :{ bbar_emu_SR+=weight;break;}
                   case 34 :{ pionk_emu_SR+=weight;break;}
                   case 35 :{ pionk_emu_SR+=weight;break;}
                   default : {other_emu_SR+=weight;}
            }
         }//end of emu
      }//end of SR
  }//end of tree
  
  //calculate fractions
  hist_phcon   ->SetBinContent(1,phcon_ee_CR/total_ee_CR); 
  hist_phcon   ->SetBinContent(2,phcon_ee_SR/total_ee_SR); 
  hist_phcon   ->SetBinContent(3,phcon_mumu_CR/total_mumu_CR); 
  hist_phcon   ->SetBinContent(4,phcon_mumu_SR/total_mumu_SR); 
  hist_phcon   ->SetBinContent(5,phcon_emu_CR/total_emu_CR); 
  hist_phcon   ->SetBinContent(6,phcon_emu_SR/total_emu_SR);

  hist_unknown   ->SetBinContent(1,unknown_ee_CR/total_ee_CR);
  hist_unknown   ->SetBinContent(2,unknown_ee_SR/total_ee_SR);
  hist_unknown   ->SetBinContent(3,unknown_mumu_CR/total_mumu_CR);
  hist_unknown   ->SetBinContent(4,unknown_mumu_SR/total_mumu_SR);
  hist_unknown   ->SetBinContent(5,unknown_emu_CR/total_emu_CR);
  hist_unknown   ->SetBinContent(6,unknown_emu_SR/total_emu_SR); 

  hist_bmes   ->SetBinContent(1,bmes_ee_CR/total_ee_CR);
  hist_bmes   ->SetBinContent(2,bmes_ee_SR/total_ee_SR);
  hist_bmes   ->SetBinContent(3,bmes_mumu_CR/total_mumu_CR);
  hist_bmes   ->SetBinContent(4,bmes_mumu_SR/total_mumu_SR);
  hist_bmes   ->SetBinContent(5,bmes_emu_CR/total_emu_CR);
  hist_bmes   ->SetBinContent(6,bmes_emu_SR/total_emu_SR);

  hist_bbar   ->SetBinContent(1,bbar_ee_CR/total_ee_CR);
  hist_bbar   ->SetBinContent(2,bbar_ee_SR/total_ee_SR);
  hist_bbar   ->SetBinContent(3,bbar_mumu_CR/total_mumu_CR);
  hist_bbar   ->SetBinContent(4,bbar_mumu_SR/total_mumu_SR);
  hist_bbar   ->SetBinContent(5,bbar_emu_CR/total_emu_CR);
  hist_bbar   ->SetBinContent(6,bbar_emu_SR/total_emu_SR);

  hist_cmes   ->SetBinContent(1,cmes_ee_CR/total_ee_CR);
  hist_cmes   ->SetBinContent(2,cmes_ee_SR/total_ee_SR);
  hist_cmes   ->SetBinContent(3,cmes_mumu_CR/total_mumu_CR);
  hist_cmes   ->SetBinContent(4,cmes_mumu_SR/total_mumu_SR);
  hist_cmes   ->SetBinContent(5,cmes_emu_CR/total_emu_CR);
  hist_cmes   ->SetBinContent(6,cmes_emu_SR/total_emu_SR);

  hist_cbar   ->SetBinContent(1,cbar_ee_CR/total_ee_CR);
  hist_cbar   ->SetBinContent(2,cbar_ee_SR/total_ee_SR);
  hist_cbar   ->SetBinContent(3,cbar_mumu_CR/total_mumu_CR);
  hist_cbar   ->SetBinContent(4,cbar_mumu_SR/total_mumu_SR);
  hist_cbar   ->SetBinContent(5,cbar_emu_CR/total_emu_CR);
  hist_cbar   ->SetBinContent(6,cbar_emu_SR/total_emu_SR);

  hist_ccbarmes   ->SetBinContent(1,ccbarmes_ee_CR/total_ee_CR);
  hist_ccbarmes   ->SetBinContent(2,ccbarmes_ee_SR/total_ee_SR);
  hist_ccbarmes   ->SetBinContent(3,ccbarmes_mumu_CR/total_mumu_CR);
  hist_ccbarmes   ->SetBinContent(4,ccbarmes_mumu_SR/total_mumu_SR);
  hist_ccbarmes   ->SetBinContent(5,ccbarmes_emu_CR/total_emu_CR);
  hist_ccbarmes   ->SetBinContent(6,ccbarmes_emu_SR/total_emu_SR);

  hist_dalitz   ->SetBinContent(1,dalitz_ee_CR/total_ee_CR);
  hist_dalitz   ->SetBinContent(2,dalitz_ee_SR/total_ee_SR);
  hist_dalitz   ->SetBinContent(3,dalitz_mumu_CR/total_mumu_CR);
  hist_dalitz   ->SetBinContent(4,dalitz_mumu_SR/total_mumu_SR);
  hist_dalitz   ->SetBinContent(5,dalitz_emu_CR/total_emu_CR);
  hist_dalitz   ->SetBinContent(6,dalitz_emu_SR/total_emu_SR);

  hist_lightmes   ->SetBinContent(1,lightmes_ee_CR/total_ee_CR);
  hist_lightmes   ->SetBinContent(2,lightmes_ee_SR/total_ee_SR);
  hist_lightmes   ->SetBinContent(3,lightmes_mumu_CR/total_mumu_CR);
  hist_lightmes   ->SetBinContent(4,lightmes_mumu_SR/total_mumu_SR);
  hist_lightmes   ->SetBinContent(5,lightmes_emu_CR/total_emu_CR);
  hist_lightmes   ->SetBinContent(6,lightmes_emu_SR/total_emu_SR);

  hist_pionk   ->SetBinContent(1,pionk_ee_CR/total_ee_CR);
  hist_pionk   ->SetBinContent(2,pionk_ee_SR/total_ee_SR);
  hist_pionk   ->SetBinContent(3,pionk_mumu_CR/total_mumu_CR);
  hist_pionk   ->SetBinContent(4,pionk_mumu_SR/total_mumu_SR);
  hist_pionk   ->SetBinContent(5,pionk_emu_CR/total_emu_CR);
  hist_pionk   ->SetBinContent(6,pionk_emu_SR/total_emu_SR);

  hist_other   ->SetBinContent(1,other_ee_CR/total_ee_CR);
  hist_other   ->SetBinContent(2,other_ee_SR/total_ee_SR);
  hist_other   ->SetBinContent(3,other_mumu_CR/total_mumu_CR);
  hist_other   ->SetBinContent(4,other_mumu_SR/total_mumu_SR);
  hist_other   ->SetBinContent(5,other_emu_CR/total_emu_CR);
  hist_other   ->SetBinContent(6,other_emu_SR/total_emu_SR);

  hist_phcon->SetFillColor(kYellow);
  hist_unknown->SetFillColor(38);
  hist_bmes->SetFillColor(kRed);
  hist_bbar->SetFillColor(kRed+2);
  hist_cmes->SetFillColor(kBlue);
  hist_cbar->SetFillColor(kBlue+2);
  hist_ccbarmes->SetFillColor(kBlue-6);
  hist_dalitz->SetFillColor(7);
  hist_lightmes->SetFillColor(9);
  hist_pionk->SetFillColor(8);
  hist_other->SetFillColor(kOrange);
  cout<<"total: "<<total_ee_CR<<endl;;
  cout<<"sum:   "<<phcon_ee_CR/total_ee_CR+unknown_ee_CR/total_ee_CR+bmes_ee_CR/total_ee_CR+bbar_ee_CR/total_ee_CR+cmes_ee_CR/total_ee_CR+cbar_ee_CR/total_ee_CR+ccbarmes_ee_CR/total_ee_CR+dalitz_ee_CR/total_ee_CR+lightmes_ee_CR/total_ee_CR+pionk_ee_CR/total_ee_CR+other_ee_CR/total_ee_CR<<endl;
  cout<<"sum:   "<<hist_phcon->GetBinContent(1) + hist_unknown->GetBinContent(1) + hist_bmes->GetBinContent(1) +
  hist_bbar->GetBinContent(1) + hist_cmes->GetBinContent(1) + hist_cbar->GetBinContent(1) + hist_ccbarmes->GetBinContent(1) + hist_dalitz->GetBinContent(1) + hist_lightmes->GetBinContent(1) + hist_pionk->GetBinContent(1) + hist_other->GetBinContent(1)<<endl;
  cout<<"$$$$$$$$----FF CHECK: $$$$$$$$$$"<<endl;
  cout<<"ele ff: "<<(total_ee_SR+phcon_ee_SR)/(total_ee_CR+phcon_ee_CR)<<"$\\pm$"<<(total_ee_SR/total_ee_CR)*sqrt(total_ee_SR2/pow(total_ee_SR,2)+total_ee_CR2/pow(total_ee_CR,2))<<endl;
  cout<<"mu ff: "<<total_mumu_SR/total_mumu_CR<<"$\\pm$"<<(total_mumu_SR/total_mumu_CR)*sqrt(total_mumu_SR2/pow(total_mumu_SR,2)+total_mumu_CR2/pow(total_mumu_CR,2))<<endl;
  //cout<<"ele ph ff: "<<phcon_ee_SR/phcon_ee_CR<<"$\\pm$"<<(phcon_ee_SR/phcon_ee_CR)*sqrt(phcon_ee_SR2/pow())<<endl;
  cout<<"$$$$$$$$----END FF CHECK: $$$$$$$$$$"<<endl;
  cout<<"phcon_ee_CR: "<<phcon_ee_CR<<endl;
  cout<<"unknown_ee_CR: "<<unknown_ee_CR<<endl;
  cout<<"bmes_ee_CR: "<<bmes_ee_CR<<endl;
  cout<<"bbar_ee_CR: "<<bbar_ee_CR<<endl;
  cout<<"cmes_ee_CR: "<<cmes_ee_CR<<endl;
  cout<<"cbar_ee_CR: "<<cbar_ee_CR<<endl;
  cout<<"ccbarmes_ee_CR: "<<ccbarmes_ee_CR<<endl;
  cout<<"dalitz_ee_CR: "<<dalitz_ee_CR<<endl;
  cout<<"lightmes_ee_CR: "<<lightmes_ee_CR<<endl;
  cout<<"pionk_ee_CR: "<<pionk_ee_CR<<endl;
  cout<<"other_ee_CR: "<<other_ee_CR<<endl;
  hist_phcon->SetLineColor(kYellow);
  hist_unknown->SetLineColor(38);
  hist_bmes->SetLineColor(kRed);
  hist_bbar->SetLineColor(kRed+2);
  hist_cmes->SetLineColor(kBlue);
  hist_cbar->SetLineColor(kBlue+2);
  hist_ccbarmes->SetLineColor(kBlue-6);
  hist_dalitz->SetLineColor(7);
  hist_lightmes->SetLineColor(9);
  hist_pionk->SetLineColor(8);
  hist_other->SetLineColor(kOrange);

  hs->Add(hist_phcon);
  hs->Add(hist_bmes);
  hs->Add(hist_bbar);
  hs->Add(hist_cmes);
  hs->Add(hist_cbar);
  hs->Add(hist_ccbarmes);
  hs->Add(hist_lightmes);
  hs->Add(hist_dalitz);
  hs->Add(hist_pionk);
  hs->Add(hist_other);
  hs->Add(hist_unknown);

  TCanvas *c_hs=new TCanvas("c_hs","",1000,700); 
  gPad->SetTicks(); 
  TLegend *leg_SS= new TLegend(0.70,0.20,0.9,0.50);
  //leg_SS->SetFillStyle(0);
  leg_SS->SetBorderSize(0);
  leg_SS->SetTextFont(62);
  leg_SS->SetTextSize(0.03);
  leg_SS->AddEntry(hist_phcon,"#gamma conversion","f"); 
  leg_SS->AddEntry(hist_bmes,"BottomMeson","f"); 
  leg_SS->AddEntry(hist_bbar,"BottomBaryon","f"); 
  leg_SS->AddEntry(hist_cmes,"CharmedMeson","f"); 
  leg_SS->AddEntry(hist_cbar,"CharmedBaryon","f"); 
  leg_SS->AddEntry(hist_ccbarmes,"CCbarMeson","f"); 
  leg_SS->AddEntry(hist_lightmes,"LightMeson","f"); 
  leg_SS->AddEntry(hist_dalitz,"DalitzDecay","f"); 
  leg_SS->AddEntry(hist_pionk,"#pi/#kappa Decay","f");
  leg_SS->AddEntry(hist_other,"Others","f");
  leg_SS->AddEntry(hist_unknown,"Unknown","f");
  hs->Draw();
  //hs->Draw("same") ;
  hs->GetYaxis()->SetTitle("The fractions of fake lepton origin");
  hs->GetXaxis()->SetBinLabel(1,"e#slash{e}");
  hs->GetXaxis()->SetBinLabel(2,"ee");
  hs->GetXaxis()->SetBinLabel(3,"#mu#slash{#mu}");
  hs->GetXaxis()->SetBinLabel(4,"#mu#mu");
  hs->GetXaxis()->SetBinLabel(5,"e#slash{#mu}+#slash{e}#mu");
  hs->GetXaxis()->SetBinLabel(6,"e#mu");
  leg_SS->Draw("same");
  //c_hs->SaveAs("fakeOrigin_2jets_Wjets.pdf");
}
