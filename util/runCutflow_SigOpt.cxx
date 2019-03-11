#include "../src/cutflow_lowmass.C"
#include "../src/cutflow_highmass.C"
#include "../src/cutflow_HSS.C"
int main(){
  string lowmasses_hh[]={"mH260","mH300"};
  string highmasses_hh[]={"mH400","mH500","nonres"};
  string masses_SS[]={"H280_S135","H300_S135","H320_S135","H340_S135","H340_S145","H340_S155","H340_S165"};
  int channels[]={1,2,3};
  //hh
  /*for(int i=0;i<3;i++){
      for(int j=0;j<3;j++)
      cutflow_lowmass(lowmasses_hh[j],channels[i]); 
  }*/
  
  for(int i=0;i<3;i++){
      for(int j=0;j<2;j++)
      cutflow_highmass(highmasses_hh[j],channels[i]);
  }
  //SS
  //for(int i=0;i<3;i++){
  //    for(int j=0;j<7;j++)
  //    cutflow_HSS(masses_SS[j],channels[i]);
  //}

  //return 0;
}
