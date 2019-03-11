#ifndef Lepton_h
#define Lepton_h
#include "TString.h"

class Lepton{
public:
  Lepton(Float_t inID,Float_t inpt,Float_t ineta,Float_t inphi,Char_t inisTightLH,Char_t inisTight,Char_t inisoTight,
         Char_t inisoTightTrackOnly,Char_t inmatchedTrigger,Int_t intruthOrigin,Int_t intruthType,Char_t intruthMatched,Char_t inisQmisID,
         Float_t insigd0PV,Float_t inz0SinTheta, Float_t intopoetcone20,Float_t inptvarcone20,Char_t inisoLoose,
         Float_t inChargeID,Float_t inPromptTagWeight,Char_t inisoLooseTrackOnly);
//  Lepton(Lepton &lepton);
  ~Lepton(){}
  Float_t pt ;
  Float_t eta ;
  Float_t phi ;
  Float_t ID ;
  Char_t isTightLH;
  Char_t isTight ;
  Char_t isoTight ;
  Char_t isoTightTrackOnly ;
  Char_t matched_Trigger ;
  Int_t truthOrigin ;
  Int_t truthType ;
  Char_t truthMatched;
  Char_t isQmisID;
  Float_t sigd0PV ;
  Float_t z0SinTheta ;
  Float_t topoetcone20;
  Float_t ptvarcone20;
  Char_t isoLoose;
  Float_t ChargeID;
  Float_t PromptTagWeight;
  Char_t isoLooseTrackOnly;
};

//construtor
Lepton::Lepton(Float_t inID,Float_t inpt,Float_t ineta,Float_t inphi,Char_t inisTightLH,Char_t inisTight,Char_t inisoTight,
               Char_t inisoTightTrackOnly,Char_t inmatchedTrigger,Int_t intruthOrigin,Int_t intruthType,Char_t intruthMatched,
               Char_t inisQmisID,Float_t insigd0PV,Float_t inz0SinTheta, Float_t intopoetcone20,Float_t inptvarcone20,
               Char_t inisoLoose, Float_t inChargeID,Float_t inPromptTagWeight ,Char_t inisoLooseTrackOnly){ 

  pt             = inpt;
  eta            = ineta;
  phi            = inphi;
  ID             = inID;
  isTightLH      = inisTightLH;
  isTight        = inisTight;
  isoTight       = inisoTight;
  isoTightTrackOnly       = inisoTightTrackOnly;
  matched_Trigger=inmatchedTrigger;
  truthOrigin    =intruthOrigin;
  truthType      =intruthType;
  truthMatched   =intruthMatched;
  isQmisID       =inisQmisID;
  sigd0PV        =insigd0PV;
  z0SinTheta     =inz0SinTheta;
  topoetcone20   =intopoetcone20;
  ptvarcone20    =inptvarcone20;
  isoLoose       =inisoLoose;
  ChargeID       =inChargeID;
  PromptTagWeight=inPromptTagWeight; 
  isoLooseTrackOnly=inisoLooseTrackOnly;
}
//copy constructor
/*Lepton::Lepton(Lepton &lepton){
 
  flavor         =lepton.flavor         ;
  pt             =lepton.pt             ; 
  eta            =lepton.eta            ;
  phi            =lepton.phi            ;
  ID             =lepton.ID             ;
  isTight        =lepton.isTight        ;
  isoTight       =lepton.isoTight       ;
  matched_Trigger=lepton.matched_Trigger;
  truthOrigin    =lepton.truthOrigin    ;
  truthType      =lepton.truthType      ;
  sigd0PV        =lepton.sigd0PV        ;
  z0SinTheta     =lepton.z0SinTheta     ;
}*/
#endif
