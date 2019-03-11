#define MiniTruth_cxx
#include "../inc/MiniTruth.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "passOptCuts.cxx"

void MiniTruth::getSumwgts(Float_t numOfevts[6],TString config)
{
   if (fChain == 0) return;
   for(int xx=0;xx<6;xx++)numOfevts[xx]=0;
   Long64_t nentries = fChain->GetEntries();
   //cout<<nentries<<endl;
   //cout<<masspoint<<endl;
   TString channels[]={"ee","mumu","emu"};
   //numOfevts[6]={0,0,0,0,0,0};
   //Float_t scale_numOfevts[]={0,0,0};
   for(Long64_t jentry=0; jentry<nentries;jentry++) {
      fChain->GetEntry(jentry);
      for(Int_t j=0;j<3;j++){ 
          //if( (((masspoint=="mH260"||masspoint=="mH300"||masspoint=="H280_S135"||masspoint=="H300_S135"||masspoint=="H320_S135")&&numOfjet>=2)||((masspoint=="mH400"||masspoint=="mH500"||masspoint=="H340_S135"||masspoint=="H340_S145"||masspoint=="H340_S155"||masspoint=="H340_S165"
          if( (((masspoint=="mH400"||masspoint=="mH260"||masspoint=="mH300"||masspoint=="H280_S135"||masspoint=="H300_S135"||masspoint=="H320_S135")&&numOfjet>=2)||((masspoint=="mH500"||masspoint=="H340_S135"||masspoint=="H340_S145"||masspoint=="H340_S155"||masspoint=="H340_S165" //for interpolations
                ||masspoint=="nonres")&&numOfjet>=3)) && //Njet division
               passOptCuts(masspoint,channels[j],mindR_l1j, mindR_l2j,m_ll,m_l1jj,m_all) && //pass Opt cuts
               channel==j+1) {
             if(config=="nominal")  numOfevts[j]++;
             if(config=="non-nominal" && variation=="Pythia8"){
                float w0=(*weights)[0];
                float wmax=(*weights)[1];
                float tmp=fabs(wmax-w0);
                //cout<<weights->size()<<endl;
                for(unsigned int i=0;i<weights->size();i++){
                    //if(i==4 || i==8) continue;
                    if(fabs((*weights)[i]-w0)>tmp ) {tmp=fabs((*weights)[i]-w0); wmax=(*weights)[i];}
                    //cout<<(*weights)[i]<<endl;
                }
                numOfevts[j] +=w0/sumw0 ;//compare eff.
                numOfevts[j+3] += wmax/sumwmax;//cout<<wmax/w0<<endl;
             }//end of Pythia8
         }//end of pass cuts
      }//end of channel loop
   }//end of entry loop
   return;
}
