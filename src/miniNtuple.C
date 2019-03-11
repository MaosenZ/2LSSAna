#define miniNtuple_cxx
#include "../inc/miniNtuple.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "passOptCuts.cxx"
#include <map>
#include <cmath>

map<string,NomErr2> miniNtuple::GetSysts()
{
   map<string,NomErr2> yields;
   if (fChain == 0) return yields;

   Long64_t nentries = fChain->GetEntries();
   cout<<nentries<<endl;
   string channels[]={"ee","mumu","emu"};
   //for file 
   int index=0;//file index
   TString currentFileName="#", tmpName="#";
   string SysSrc, type, addtype;
   for(Long64_t jentry=0; jentry<nentries;jentry++) {
       fChain->GetEntry(jentry); 
       //to know which file is looping, this is needed for NonEventWeight Type systematics, as there are many files added in the chain.
       currentFileName=fChain->GetFile()->GetName();
       
       TString whichfile=currentFileName;
       //print current file
       if(currentFileName!=tmpName){
          tmpName=currentFileName;
          index++;
          cout<<jentry<<endl;
          cout<<tmpName<<endl;
          //retrieve name of NonEventWeight type syst.
          if(SystematicType=="NonEventWeight"){
             for(unsigned int k=0;k<SysSrcs.size();k++){
                 if(tmpName.Contains(SysSrcs[k])) {SysSrc=SysSrcs[k]; cout<<"SysName: "<<SysSrc<<endl;}
             }
          }
       }
       for(int j=0;j<3;j++){//3 channels
           //if( (((masspoint=="mH260"||masspoint=="mH300"||masspoint=="H280_S135"||masspoint=="H300_S135"||masspoint=="H320_S135")&&numOfjet>=2)||((masspoint=="mH400"||masspoint=="mH500"||masspoint=="H340_S135"||masspoint=="H340_S145"||masspoint=="H340_S155"||masspoint=="H340_S165"
           if( (((masspoint=="mH260"||masspoint=="mH300"||masspoint=="mH400"||masspoint=="H280_S135"||masspoint=="H300_S135"||masspoint=="H320_S135")&&numOfjet>=2)||((masspoint=="mH500"||masspoint=="H340_S135"||masspoint=="H340_S145"||masspoint=="H340_S155"||masspoint=="H340_S165"// for interpolation
                ||masspoint=="nonres")&&numOfjet>=3)) && //Njet division
               passOptCuts(masspoint,channels[j],mindR_l1j, mindR_l2j,m_ll,m_l1jj,m_all) && //pass Opt cuts
               channel==j+1) {//constraint corresponding channel,1, ee, 2, mumu, 3, emu
               //set names of each category
               if(SystematicType=="EventWeight"){
                  type=channels[j]+"_"+sample;
                  yields[type].Nom+=weight;
                  yields[type].Err2+=weight*weight;
                  yields[type+"_pileupEventWeight_UP"].Nom+=                                     pileupEventWeight_UP*weight;
                  yields[type+"_pileupEventWeight_DOWN"].Nom+=                                   pileupEventWeight_DOWN*weight;
                  yields[type+"_MV2c10_70_EventWeight_B0_UP"].Nom+=                              MV2c10_70_EventWeight_B0_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_B0_DOWN"].Nom+=                            MV2c10_70_EventWeight_B0_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_B1_UP"].Nom+=                              MV2c10_70_EventWeight_B1_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_B1_DOWN"].Nom+=                            MV2c10_70_EventWeight_B1_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_B2_UP"].Nom+=                              MV2c10_70_EventWeight_B2_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_B2_DOWN"].Nom+=                            MV2c10_70_EventWeight_B2_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_B3_UP"].Nom+=                              MV2c10_70_EventWeight_B3_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_B3_DOWN"].Nom+=                            MV2c10_70_EventWeight_B3_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_B4_UP"].Nom+=                              MV2c10_70_EventWeight_B4_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_B4_DOWN"].Nom+=                            MV2c10_70_EventWeight_B4_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_B5_UP"].Nom+=                              MV2c10_70_EventWeight_B5_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_B5_DOWN"].Nom+=                            MV2c10_70_EventWeight_B5_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_C0_UP"].Nom+=                              MV2c10_70_EventWeight_C0_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_C0_DOWN"].Nom+=                            MV2c10_70_EventWeight_C0_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_C1_UP"].Nom+=                              MV2c10_70_EventWeight_C1_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_C1_DOWN"].Nom+=                            MV2c10_70_EventWeight_C1_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_C2_UP"].Nom+=                              MV2c10_70_EventWeight_C2_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_C2_DOWN"].Nom+=                            MV2c10_70_EventWeight_C2_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_C3_UP"].Nom+=                              MV2c10_70_EventWeight_C3_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_C3_DOWN"].Nom+=                            MV2c10_70_EventWeight_C3_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light0_UP"].Nom+=                          MV2c10_70_EventWeight_Light0_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light0_DOWN"].Nom+=                        MV2c10_70_EventWeight_Light0_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light1_UP"].Nom+=                          MV2c10_70_EventWeight_Light1_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light1_DOWN"].Nom+=                        MV2c10_70_EventWeight_Light1_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light2_UP"].Nom+=                          MV2c10_70_EventWeight_Light2_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light2_DOWN"].Nom+=                        MV2c10_70_EventWeight_Light2_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light3_UP"].Nom+=                          MV2c10_70_EventWeight_Light3_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light3_DOWN"].Nom+=                        MV2c10_70_EventWeight_Light3_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light4_UP"].Nom+=                          MV2c10_70_EventWeight_Light4_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light4_DOWN"].Nom+=                        MV2c10_70_EventWeight_Light4_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light5_UP"].Nom+=                          MV2c10_70_EventWeight_Light5_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light5_DOWN"].Nom+=                        MV2c10_70_EventWeight_Light5_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light6_UP"].Nom+=                          MV2c10_70_EventWeight_Light6_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light6_DOWN"].Nom+=                        MV2c10_70_EventWeight_Light6_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light7_UP"].Nom+=                          MV2c10_70_EventWeight_Light7_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light7_DOWN"].Nom+=                        MV2c10_70_EventWeight_Light7_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light8_UP"].Nom+=                          MV2c10_70_EventWeight_Light8_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light8_DOWN"].Nom+=                        MV2c10_70_EventWeight_Light8_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light9_UP"].Nom+=                          MV2c10_70_EventWeight_Light9_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light9_DOWN"].Nom+=                        MV2c10_70_EventWeight_Light9_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light10_UP"].Nom+=                         MV2c10_70_EventWeight_Light10_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light10_DOWN"].Nom+=                       MV2c10_70_EventWeight_Light10_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light11_UP"].Nom+=                         MV2c10_70_EventWeight_Light11_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light11_DOWN"].Nom+=                       MV2c10_70_EventWeight_Light11_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light12_UP"].Nom+=                         MV2c10_70_EventWeight_Light12_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light12_DOWN"].Nom+=                       MV2c10_70_EventWeight_Light12_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light13_UP"].Nom+=                         MV2c10_70_EventWeight_Light13_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light13_DOWN"].Nom+=                       MV2c10_70_EventWeight_Light13_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light14_UP"].Nom+=                         MV2c10_70_EventWeight_Light14_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light14_DOWN"].Nom+=                       MV2c10_70_EventWeight_Light14_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light15_UP"].Nom+=                         MV2c10_70_EventWeight_Light15_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_Light15_DOWN"].Nom+=                       MV2c10_70_EventWeight_Light15_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_extrapolation_UP"].Nom+=                   MV2c10_70_EventWeight_extrapolation_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_extrapolation_DOWN"].Nom+=                 MV2c10_70_EventWeight_extrapolation_down*weight;
                  yields[type+"_MV2c10_70_EventWeight_extrapolation_from_charm_UP"].Nom+=        MV2c10_70_EventWeight_extrapolation_from_charm_up*weight;
                  yields[type+"_MV2c10_70_EventWeight_extrapolation_from_charm_DOWN"].Nom+=      MV2c10_70_EventWeight_extrapolation_from_charm_down*weight;
                  yields[type+"_JVT_EventWeight_UP"].Nom+=                                       JVT_EventWeight_UP*weight;
                  yields[type+"_JVT_EventWeight_DOWN"].Nom+=                                     JVT_EventWeight_DOWN*weight;
                  yields[type+"_lepSFTrigTight_EL_SF_Trigger_UP"].Nom+=                          lepSFTrigTight_EL_SF_Trigger_UP*weight;
                  yields[type+"_lepSFTrigTight_EL_SF_Trigger_DOWN"].Nom+=                        lepSFTrigTight_EL_SF_Trigger_DOWN*weight;
                  yields[type+"_lepSFObjTight_EL_SF_Reco_UP"].Nom+=                              lepSFObjTight_EL_SF_Reco_UP*weight;
                  yields[type+"_lepSFObjTight_EL_SF_Reco_DOWN"].Nom+=                            lepSFObjTight_EL_SF_Reco_DOWN*weight;
                  yields[type+"_lepSFObjTight_EL_SF_ID_UP"].Nom+=                                lepSFObjTight_EL_SF_ID_UP*weight;
                  yields[type+"_lepSFObjTight_EL_SF_ID_DOWN"].Nom+=                              lepSFObjTight_EL_SF_ID_DOWN*weight;
                  yields[type+"_lepSFObjTight_EL_SF_Isol_UP"].Nom+=                              lepSFObjTight_EL_SF_Isol_UP*weight;
                  yields[type+"_lepSFObjTight_EL_SF_Isol_DOWN"].Nom+=                            lepSFObjTight_EL_SF_Isol_DOWN*weight;
                  yields[type+"_lepSFTrigTight_MU_SF_Trigger_STAT_UP"].Nom+=                     lepSFTrigTight_MU_SF_Trigger_STAT_UP*weight;
                  yields[type+"_lepSFTrigTight_MU_SF_Trigger_STAT_DOWN"].Nom+=                   lepSFTrigTight_MU_SF_Trigger_STAT_DOWN*weight;
                  yields[type+"_lepSFTrigTight_MU_SF_Trigger_SYST_UP"].Nom+=                     lepSFTrigTight_MU_SF_Trigger_SYST_UP*weight;
                  yields[type+"_lepSFTrigTight_MU_SF_Trigger_SYST_DOWN"].Nom+=                   lepSFTrigTight_MU_SF_Trigger_SYST_DOWN*weight;
                  yields[type+"_lepSFObjTight_MU_SF_ID_STAT_UP"].Nom+=                           lepSFObjTight_MU_SF_ID_STAT_UP*weight;
                  yields[type+"_lepSFObjTight_MU_SF_ID_STAT_DOWN"].Nom+=                         lepSFObjTight_MU_SF_ID_STAT_DOWN*weight;
                  yields[type+"_lepSFObjTight_MU_SF_ID_SYST_UP"].Nom+=                           lepSFObjTight_MU_SF_ID_SYST_UP*weight;
                  yields[type+"_lepSFObjTight_MU_SF_ID_SYST_DOWN"].Nom+=                         lepSFObjTight_MU_SF_ID_SYST_DOWN*weight;
                  yields[type+"_lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP"].Nom+=                     lepSFObjTight_MU_SF_ID_STAT_LOWPT_UP*weight;
                  yields[type+"_lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN"].Nom+=                   lepSFObjTight_MU_SF_ID_STAT_LOWPT_DOWN*weight;
                  yields[type+"_lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP"].Nom+=                     lepSFObjTight_MU_SF_ID_SYST_LOWPT_UP*weight;
                  yields[type+"_lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN"].Nom+=                   lepSFObjTight_MU_SF_ID_SYST_LOWPT_DOWN*weight;
                  yields[type+"_lepSFObjTight_MU_SF_Isol_STAT_UP"].Nom+=                         lepSFObjTight_MU_SF_Isol_STAT_UP*weight;
                  yields[type+"_lepSFObjTight_MU_SF_Isol_STAT_DOWN"].Nom+=                       lepSFObjTight_MU_SF_Isol_STAT_DOWN*weight;
                  yields[type+"_lepSFObjTight_MU_SF_Isol_SYST_UP"].Nom+=                         lepSFObjTight_MU_SF_Isol_SYST_UP*weight;
                  yields[type+"_lepSFObjTight_MU_SF_Isol_SYST_DOWN"].Nom+=                       lepSFObjTight_MU_SF_Isol_SYST_DOWN*weight;
                  yields[type+"_lepSFObjTight_MU_SF_TTVA_STAT_UP"].Nom+=                         lepSFObjTight_MU_SF_TTVA_STAT_UP*weight;
                  yields[type+"_lepSFObjTight_MU_SF_TTVA_STAT_DOWN"].Nom+=                       lepSFObjTight_MU_SF_TTVA_STAT_DOWN*weight;
                  yields[type+"_lepSFObjTight_MU_SF_TTVA_SYST_UP"].Nom+=                         lepSFObjTight_MU_SF_TTVA_SYST_UP*weight;
                  yields[type+"_lepSFObjTight_MU_SF_TTVA_SYST_DOWN"].Nom+=                       lepSFObjTight_MU_SF_TTVA_SYST_DOWN*weight;
               }//end of if SysSrc EventWeight
               if(SystematicType=="NonEventWeight"){
                  type=channels[j]+"_"+sample+"_"+SysSrc;
                  //double reweightSF=2.2/33.41;//blame Jason for the sf
                  yields[type].tag=2;
                //if(sample=="mH260"||sample=="mH300"||sample=="mH400"||sample=="mH500"||sample=="nonres")yields[type].Nom+=weight*reweightSF;
                  yields[type].Nom+=weight;
               }//end of if SysSrc NonEventWeight
               //begin save data-driven bkg syst.
               if(SystematicType=="Data-driven"){
                  if(sample=="QmisID") type=channels[j]+"_"+sample;
                  else switch(category) {
                       case 2 : {type=string("eantiide")+"_"+sample;}//number of fakes in ee
                         break;
                       case 12 : {type=string("muantiidmu")+"_"+sample;} //number of fakes in mumu
                         break;
                       case 22 : {type=string("antiidemu")+"_"+sample; addtype=string("emu")+"_"+sample;}//number of fakes from antiid e + mu
                         break;
                       case 23 : {type=string("eantiidmu")+"_"+sample; addtype=string("emu")+"_"+sample;}//number of fakes from e + antiid mu
                         break;
                       default : cout<<"Category not known!"<<endl;
                  }
                  yields[type].Nom+=weight;
                  yields[type].Err2+=weight*weight;
                  //emu fake
                  if(channel==3 && sample=="fake") yields[addtype].Nom+=weight;
               }//end of save Data-driven sytematic type
           }//end of if pass
       }//end of channel loop
   }//end of event loop
   cout<<sample<<" "<<yields.size()<<" kinds of syst. yields have been saved for "<<SystematicType<<" type"<<endl;
   //cout<<yields["ee_mH260"].Nom<<" "<<yields["ee_mH260"].Err2<<endl;
   //cout<<yields["emu_fake"].Nom<<" "<<yields["antiidemu_fake"].Nom<<" "<<yields["eantiidmu_fake"].Nom<<endl;
   return yields;      
}

void miniNtuple::makeTH1Fs(TH1F *hist_ee,TH1F *hist_mumu,TH1F *hist_emu,TH1F *hist_antiemu,TH1F *hist_eantimu,Float_t Nbins, Float_t xmin, Float_t xmax,TString var){
  //hist_ee=new TH1F("hist1","",Nbins,xmin,xmax); //ee
  //hist_mumu=new TH1F("hist2","",Nbins,xmin,xmax); //mumu
  //hist_emu=new TH1F("hist3","",Nbins,xmin,xmax); //emu
  //hists[3]=new TH1F("hist4","",Nbins,xmin,xmax); //emu
  if (fChain == 0) return ;
  string channels[]={"ee","mumu","emu"};
  Long64_t nentries = fChain->GetEntries();
  for(Long64_t jentry=0; jentry<nentries;jentry++) {
      fChain->GetEntry(jentry);
      for(int j=0;j<3;j++){//3 channels
          if( (((masspoint=="mH260"||masspoint=="mH300"||masspoint=="H280_S135"||masspoint=="H300_S135"||masspoint=="H320_S135")&&numOfjet>=2)||((masspoint=="mH400"||masspoint=="mH500"||masspoint=="H340_S135"||masspoint=="H340_S145"||masspoint=="H340_S155"||masspoint=="H340_S165"
                ||masspoint=="nonres")&&numOfjet>=3)) && //Njet division
               passOptCuts(masspoint,channels[j],mindR_l1j, mindR_l2j,m_ll,m_l1jj,m_all) && //pass Opt cuts
               channel==j+1) {
             if(var=="m_ll"){
                //hists[3]->Fill(m_ll,weight);
                if(j==0) hist_ee->Fill(m_ll,weight);
                if(j==1) hist_mumu->Fill(m_ll,weight);
                if(j==2) {
                   hist_emu->Fill(m_ll,weight);
                   if((*component)=="fake" && category==22) hist_antiemu->Fill(m_ll,weight);
                   if((*component)=="fake" && category==23) hist_eantimu->Fill(m_ll,weight);
                }
                
             }
             if(var=="mindR_l1j"){
                //hists[3]->Fill(mindR_l1j,weight);
                if(j==0) hist_ee->Fill(mindR_l1j,weight);
                if(j==1) hist_mumu->Fill(mindR_l1j,weight);
                if(j==2) {
                   hist_emu->Fill(mindR_l1j,weight);
                   if((*component)=="fake" && category==22) hist_antiemu->Fill(mindR_l1j,weight);
                   if((*component)=="fake" && category==23) hist_eantimu->Fill(mindR_l1j,weight);
                }
             }
             if(var=="mindR_l2j"){
                //hists[3]->Fill(mindR_l2j,weight);
                if(j==0) hist_ee->Fill(mindR_l2j,weight);
                if(j==1) hist_mumu->Fill(mindR_l2j,weight);
                if(j==2) {
                  hist_emu->Fill(mindR_l2j,weight);
                  if((*component)=="fake" && category==22) hist_antiemu->Fill(mindR_l2j,weight);
                  if((*component)=="fake" && category==23) hist_eantimu->Fill(mindR_l2j,weight);
                }
             }
             if(var=="m_l1jj"){
                //hists[3]->Fill(m_l1jj,weight);
                if(j==0) hist_ee->Fill(m_l1jj,weight);
                if(j==1) hist_mumu->Fill(m_l1jj,weight);
                if(j==2) {
                   hist_emu->Fill(m_l1jj,weight);
                   if((*component)=="fake" && category==22) hist_antiemu->Fill(m_l1jj,weight);
                   if((*component)=="fake" && category==23) hist_eantimu->Fill(m_l1jj,weight);
                }
             }
             if(var=="m_all"){
                //hists[3]->Fill(m_all,weight);
                if(j==0) hist_ee->Fill(m_all,weight);
                if(j==1) hist_mumu->Fill(m_all,weight);
                if(j==2) {
                   hist_emu->Fill(m_all,weight);
                   if((*component)=="fake" && category==22) hist_antiemu->Fill(m_all,weight);
                   if((*component)=="fake" && category==23) hist_eantimu->Fill(m_all,weight);
                }
             }
             //else cout<<"wrong input variable"<<endl;
          }
       
      }        
  }    
  return;
}
