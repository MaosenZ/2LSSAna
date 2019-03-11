#include "../inc/Lepton.h"
#include <cmath>
//----------------------------------------------------
//This tool is to judge id or anti-id leptons, the definitions of id and anti-di could be changed here.
//NOTE: 1 means id, 2 anti-id
//----------------------------------------------------

Int_t LeptonClassifier(Int_t datasetType,Lepton *lepton){
  //datasetType 1/2 nominal ones, 3 DY, Zjets, WW and ttbar
  if(fabs(lepton->ID)==11 && lepton->isoLoose){
     if((datasetType==1||datasetType==2) && lepton->ChargeID>0.0670415 ){
        if(lepton->isTightLH && lepton->isoTight && fabs(lepton->sigd0PV)<5 && fabs(lepton->z0SinTheta)<0.5)
           return 1;
        if(!lepton->isTightLH)
           return 2;
     }
     if((datasetType==3||datasetType==4)  && lepton->ChargeID>0.0670415 &&lepton->truthMatched){
        if(lepton->isTightLH && lepton->isoTight && fabs(lepton->sigd0PV)<5 &&fabs(lepton->z0SinTheta)<0.5)
        //if(lepton->isTightLH && lepton->isoLoose && lepton->PromptTagWeight<-0.5)
           return 1;             
        if(!lepton->isTightLH)
           return 2;
     }
  }
  if(fabs(lepton->ID)==13&&(datasetType==1||datasetType==2) && lepton->isoLoose){

     if(lepton->isTight && lepton->isoTightTrackOnly && fabs(lepton->sigd0PV)<3 && fabs(lepton->z0SinTheta)<0.5)
     //if(lepton->PromptTagWeight<-0.5 && lepton->isoLoose)
        return 1;
     //if((!lepton->isoTightTrackOnly)&&lepton->topoetcone20/lepton->pt<1&&lepton->ptvarcone20/lepton->pt<1)
     if(!lepton->isoTightTrackOnly)
        return 2;
  }
 
  if(fabs(lepton->ID)==13&&(datasetType==3||datasetType==4)&&lepton->truthMatched && lepton->isoLoose){

     if(lepton->isTight && lepton->isoTightTrackOnly && fabs(lepton->sigd0PV)<3 && fabs(lepton->z0SinTheta)<0.5)
     //if(lepton->PromptTagWeight<-0.5 && lepton->isoLoose)
        return 1;
     //if((!lepton->isoTightTrackOnly)&&lepton->topoetcone20/lepton->pt<1&&lepton->ptvarcone20/lepton->pt<1)
     if(!lepton->isoTightTrackOnly) 
        return 2;
  }
}
