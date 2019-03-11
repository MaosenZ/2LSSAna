//-------------------------------------------------------------------------------------------
// This script is to define cut-flow of hh->WWWW, using ntuples after hh4Wanalysis.C.
// Also can be used to draw plots
// Author: Maosen Zhou (maosen.zhou@cern.ch)
// Date: 25/Sep/2016
// --to scan different cuts to define best cuts
//   vars to be used: m_ll, mindR_l1j, mindR_l2j 
//-------------------------------------------------------------------------------------------

#include "TCanvas.h"
#include "TH1.h"
#include "TFile.h"
#include "TTree.h"
#include "TStyle.h"
#include <iostream>
#include "TString.h"
#include <vector>
#include "lumi.cxx"
#include "inc/ApplyCuts.h"
using namespace std;
using namespace TMath;
void calsig(){
  Float_t ff_ele=0.61, ff_mu=0.34, sys_ele=0.436, sys_mu=0.635;
  //cuts defined
  //TCut cutsused= "channel==3 && numOfjet>=2&&fabs(m_ll-91.2)>10 && MET > 10 && mindR_l1j < 9999 && mindR_l2j < 1.8 &&m_l1jj<160"; 
  TCut cutsused[]= {"channel==1",
                    "channel==1 &&MET>45",
                    "channel==1 &&MET>45&&m_ll>50",
                    "channel==1 &&MET>45&&m_ll>50&&mindR_l2j<1.9",
                    "channel==1 &&MET>45&&m_ll>50&&mindR_l2j<1.9&&mindR_l1j<0.7",
                    "channel==1 &&MET>45&&m_ll>50&&mindR_l2j<1.9&&mindR_l1j<0.7&&m_l1jj<300",
                    "channel==1 &&MET>45&&m_ll>50&&mindR_l2j<1.9&&mindR_l1j<0.7&&m_l1jj<300&&m_all<1000 "}; 
  //cuts already performed in constructing
  for(Int_t index=1;index<=6;index++)
  ApplyCuts signal("mH500",cutsused[index]); 
  ApplyCuts FFApp_data("FFApp_datacombined",cutsused[index]);
  ApplyCuts data("datacombined",cutsused[index]);
  ApplyCuts FFQmis("FFQmis_datacombined",cutsused[index]);
  ApplyCuts FFApp_subtractions_QmisID("FFApp_subtractions_QmisID",cutsused[index]);
  ApplyCuts FFApp_subtractions_promptSS("FFApp_subtractions_promptSS",cutsused[index]);
  ApplyCuts promptSS("promptSS",cutsused[index]);
  ApplyCuts Vgam("Vgam",cutsused[index]);
  ApplyCuts QmisID("QmisID_datacombined",cutsused[index]);
  //
  signal.Loop();
  FFApp_data.Loop();
  data.Loop();
  FFQmis.Loop();
  FFApp_subtractions_QmisID.Loop();
  FFApp_subtractions_promptSS.Loop();
  promptSS.Loop();
  Vgam.Loop();
  QmisID.Loop();
  Int_t numOfsignal=signal.raw_number,
        numOfpromptSS=promptSS.raw_number,
        numOfVgam=Vgam.raw_number, 
        numOfQmisID=QmisID.raw_number,
        numOfFFQmis=FFQmis.raw_number,
        numOfFFApp_subtractions_QmisID=FFApp_subtractions_QmisID.raw_number,
        numOfFFApp_subtractions_promptSS=FFApp_subtractions_promptSS.raw_number,
        numOfFFApp_data=FFApp_data.raw_number;
        numOfdata=data.raw_number;
  Double_t numOfwgtsignal=signal.weighted_number*lumi(),
           numOfwgtpromptSS=promptSS.weighted_number*lumi(), 
           numOfwgtVgam=Vgam.weighted_number*lumi(), 
           numOfwgtQmisID=QmisID.weighted_number,
           //eantimu
           numOfwgtFFQmis_eantimu=FFQmis.weighted_number_eantimu,
           numOfwgtFFApp_subtractions_promptSS_eantimu=FFApp_subtractions_promptSS.weighted_number_eantimu*lumi(),
           numOfwgtFFApp_subtractions_QmisID_eantimu=FFApp_subtractions_QmisID.weighted_number_eantimu*lumi(),
           numOfwgtFFApp_data_eantimu=FFApp_data.weighted_number_eantimu,
           numOfwgtfake_eantimu=numOfwgtFFApp_data_eantimu-numOfwgtFFApp_subtractions_QmisID_eantimu-
            numOfwgtFFApp_subtractions_promptSS_eantimu-numOfwgtFFQmis_eantimu,
           //antiemu
           numOfwgtFFApp_subtractions_promptSS_antiemu=FFApp_subtractions_promptSS.weighted_number_antiemu*lumi(),
           numOfwgtFFApp_subtractions_QmisID_antiemu=FFApp_subtractions_QmisID.weighted_number_antiemu*lumi(),
           numOfwgtFFApp_data_antiemu=FFApp_data.weighted_number_antiemu,
           numOfwgtfake_antiemu=numOfwgtFFApp_data_antiemu-numOfwgtFFApp_subtractions_QmisID_antiemu-
            numOfwgtFFApp_subtractions_promptSS_antiemu-numOfwgtFFQmis_antiemu;
  Double_t errOfwgtsignal=signal.error_statistics*lumi(),
           errOfwgtpromptSS=promptSS.error_statistics*lumi(), 
           errOfwgtVgam=Vgam.error_statistics*lumi(), 
           errOfwgtQmisID=QmisID.error_statistics,
           errOffake=sqrt(pow(sys_ele*numOfwgtfake_antiemu,2)+ff_ele*numOfwgtfake_antiemu +
                          pow(sys_mu*numOfwgtfake_eantimu,2)+ff_mu*numOfwgtfake_eantimu);
  //
  Double_t totalbkg=numOfwgtfake_eantimu+numOfwgtfake_antiemu+ numOfwgtQmisID + numOfwgtpromptSS + numOfwgtVgam;
  Double_t sig=numOfwgtsignal/sqrt(totalbkg);
  Double_t sigpur=numOfwgtsignal/(totalbkg+numOfwgtsignal);
  Double_t sig_Z0=sqrt(2*((numOfwgtsignal+totalbkg)*log((numOfwgtsignal+totalbkg)/totalbkg)-numOfwgtsignal));
  Double_t errOftotalbkg=sqrt(errOfwgtpromptSS*errOfwgtpromptSS + errOfwgtVgam*errOfwgtVgam + errOfwgtQmisID*errOfwgtQmisID +
                              errOffake*errOffake);
  Double_t predicted=totalbkg+numOfwgtsignal;
  Double_t errOfpredicted=sqrt(errOftotalbkg*errOftotalbkg+errOfwgtsignal*errOfwgtsignal);
  /*cout<<"-------------------------------------------------------------------"<<endl;
  cout<<"signal: "<<setw(5)<<numOfwgtsignal<<"$\\pm$"<<errOfwgtsignal<<setw(10)<<numOfsignal<<endl;
  cout<<"promptSS: "<<setw(5)<<numOfwgtpromptSS<<"$\\pm$"<<errOfwgtpromptSS<<setw(10)<<numOfpromptSS<<endl;
  cout<<"Vgam: "<<setw(5)<<numOfwgtVgam<<"$\\pm$"<<errOfwgtVgam<<setw(10)<<numOfVgam<<endl;
  cout<<"QmisID: "<<setw(5)<<numOfwgtQmisID<<"$\\pm$"<<errOfwgtQmisID<<setw(10)<<numOfQmisID<<endl;
  cout<<"Fakes: "<<setw(5)<<(numOfwgtFFApp_data-numOfwgtFFApp_subtractions_QmisID-numOfwgtFFApp_subtractions_promptSS-numOfwgtFFQmis)<<"$\\pm$"
                  <<errOffake<<setw(10)<<numOfFFApp_data<<"-"<<numOfFFApp_subtractions_QmisID<<"-"<<numOfFFApp_subtractions_promptSS<<"-"<<
                  numOfFFQmis<<endl;
  cout<<"Error component of fakes "<<"errOfwgtFFQmis errOfwgtFFApp_subtractions_QmisID errOfwgtFFApp_subtractions_promptSS == "<<
                                   errOfwgtFFQmis<<" "<<errOfwgtFFApp_subtractions_QmisID<<" "<<errOfwgtFFApp_subtractions_promptSS<<endl;
  cout<<"total bkg: "<<setw(5)<<totalbkg<<"$\\pm$"<<errOftotalbkg<<endl;
  cout<<"predicted: "<<setw(5)<<predicted<<"$\\pm$"<<errOfpredicted<<endl;
  cout<<"s/sqrt(B): "<<setw(5)<<sig<<endl;
  cout<<"Z0: "<<setw(5)<<sig_Z0<<endl;
  cout<<"s/B: "<<setw(5)<<sigpur<<endl;*/
  cout<<vars[index]<<setw(5)<<"&"<<numOfwgtpromptSS<<"$\\pm$"<<errOfwgtpromptSS<<setw(5)<<
//end of manin func
}
