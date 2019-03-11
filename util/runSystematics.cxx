#include "../inc/miniNtuple.h"
#include "../src/PrintSystYields.cxx"

int main(int argc, char *argv[])
{
  //MC: mH*, promptSS, Vgam; Data-drien: QmisID and fake
  //string masspoints[]={"mH260","mH300","mH400","mH500","nonres"};
  string masspoint=argv[1];
  string bkgsamples[]={"promptSS","Vgam","QmisID","fake"};
  //string bkgsamples[]={"diboson","ttV","tV","singletop","ttH","Vgam","QmisID","fake"};
  //------------------------------------------------------------------
  // First print MC related systs.
  //------------------------------------------------------------------
  map<string,NomErr2> merge_yields;
   //get signal EventWeight yields
  miniNtuple signal_EventWeight(masspoint,masspoint,"EventWeight");
  map<string,NomErr2> signal_EventWeight_yields;
  signal_EventWeight_yields=signal_EventWeight.GetSysts();
   //get signal NonEventWeight yields
  miniNtuple signal_NonEventWeight(masspoint,masspoint,"NonEventWeight");
  map<string,NomErr2> signal_NonEventWeight_yields;
  signal_NonEventWeight_yields=signal_NonEventWeight.GetSysts();
   //merge, print
  signal_EventWeight_yields.insert(signal_NonEventWeight_yields.begin(),signal_NonEventWeight_yields.end());
  PrintMCEventYields(signal_EventWeight_yields,masspoint,masspoint);
  merge_yields.insert(signal_EventWeight_yields.begin(),signal_EventWeight_yields.end());
  for(int j=0;j<2;j++){//2 bkg MC samples
       //gett bkg EventWeight yields
      miniNtuple bkg_EventWeight(masspoint,bkgsamples[j],"EventWeight"); 
      map<string,NomErr2> bkg_EventWeight_yields;
      bkg_EventWeight_yields=bkg_EventWeight.GetSysts();
       //get bkg NonEventWeight yields
      miniNtuple bkg_NonEventWeight(masspoint,bkgsamples[j],"NonEventWeight");
      map<string,NomErr2> bkg_NonEventWeight_yields;
      bkg_NonEventWeight_yields=bkg_NonEventWeight.GetSysts();
       //merge, print
      bkg_EventWeight_yields.insert(bkg_NonEventWeight_yields.begin(),bkg_NonEventWeight_yields.end());
      PrintMCEventYields(bkg_EventWeight_yields,masspoint,bkgsamples[j]);
      merge_yields.insert(bkg_EventWeight_yields.begin(),bkg_EventWeight_yields.end());
  }
  PrintMCEventYieldsTex(merge_yields,masspoint);
  //---------------------------------------------------------------
  // Then data-driven systs.
  //---------------------------------------------------------------
  for(int j=2;j<4;j++){//2 data-driven samples
      miniNtuple someone3(masspoint,bkgsamples[j],"Data-driven");
      map<string,NomErr2> yields3;
      yields3=someone3.GetSysts();
      PrintDatadrivenEventYields(yields3,masspoint,bkgsamples[j]);
  }
  return 0;
}
