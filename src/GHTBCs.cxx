#ifndef GHTBCs_cxx
#define GHTBCs_cxx

#include "TH1.h"
#include "THStack.h"
#include "TH1F.h"
#include "TH2.h"
#include "TH2F.h"
Float_t GHTBCs(TH1* hist){//GetHistsTotalBinContents

  Int_t Nbins=hist->GetNbinsX();
  Float_t totalbincontents=0;
  /*for(Int_t i=1;i<=Nbins;i++){
      totalbincontents += hist->GetBinContent(i);
  }*/
  totalbincontents=hist->Integral(0,Nbins+1);
  return totalbincontents;
}

Float_t GHTBCs(TH2* hist){//GetHistsTotalBinContents

  Int_t NbinsX=hist->GetNbinsX();
  Int_t NbinsY=hist->GetNbinsY();
  Float_t totalbincontents=0;
  /*for(Int_t i=1;i<=NbinsX;i++){
      for(Int_t j=1;j<=NbinsY;j++){
          totalbincontents += hist->GetBinContent(i,j);
      }
  }*/
  totalbincontents=hist->Integral(0,NbinsX+1,0,NbinsY+1);
  return totalbincontents;
}

Float_t GetMaxBinContent(TH1 *hist){
  vector<float>bincontents;
  for(Int_t i=1;i<hist->GetNbinsX();i++){
      bincontents.push_back(hist->GetBinContent(i));
  }
  for(Int_t i=0;i<bincontents.size()-1;i++){
      Float_t tmp;
      for(Int_t j=i+1;j>0;j--){
          if(bincontents[j]>bincontents[j-1]){tmp=bincontents[j-1];bincontents[j-1]=bincontents[j];bincontents[j]=tmp;}
      }
  }
  return bincontents[0];
}
Float_t GetMaxBinContent(THStack *hs){
  vector<float>bincontents;
  Int_t Nbins=((TH1*)(hs->GetStack()->Last()))->GetNbinsX();
  for(Int_t i=1;i<=Nbins;i++){
      bincontents.push_back(((TH1*)(hs->GetStack()->Last()))->GetBinContent(i));
  }
  for(Int_t i=0;i<bincontents.size()-1;i++){
      Float_t tmp;
      for(Int_t j=i+1;j>0;j--){
          if(bincontents[j]>bincontents[j-1]){tmp=bincontents[j-1];bincontents[j-1]=bincontents[j];bincontents[j]=tmp;}
      }
  }
  return bincontents[0];
}

Float_t statistic_error(TH1 *hist){
  Int_t Nbins=hist->GetNbinsX();
  Float_t error=0;
  for(Int_t i=1;i<=Nbins;i++){
      error += hist->GetBinError(i)*hist->GetBinError(i);
  }
  return sqrt(error);
}
#endif 
