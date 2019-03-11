#include "../inc/MiniTruth.h"
#include <iomanip>
#include <fstream>

int main(){
  TString hh_samps[]={"nonres","mH260","mH300","mH400","mH500"};
  TString SS_samps[]={"H280_S135","H300_S135","H320_S135","H340_S135","H340_S145","H340_S155","H340_S165"};
  TString variations_up[]={"Var1Up","Var2Up","Var3aUp","Var3bUp","Var3cUp"};
  TString variations_dw[]={"Var1Dw","Var2Dw","Var3aDw","Var3bDw","Var3cDw"};
  TString hhs[]={"nonres","m260","m300","m400","m500"};
  TString channels[]={"ee","mumu","emu"};
  cout<<"$$$$$$$$$$-HH signal theroetical uncertainty-$$$$$$$$$$$"<<endl;
  for(int i=1;i<5;i++){
     //parton showering uncertainty
     cout<<hh_samps[i]<<" parton showering uncer."<<endl;

     MiniTruth samp_hwg(hhs[i],"Herwig");
     MiniTruth samp_py8(hhs[i],"Pythia8");
     Float_t *evts_hwg=new Float_t[6];
     Float_t *evts_py8=new Float_t[6];
     samp_hwg.getSumwgts(evts_hwg,"nominal"); 
     samp_py8.getSumwgts(evts_py8,"nominal");
     //scale uncer.
     Float_t *evts_py8_scale=new Float_t[6];
     samp_py8.getSumwgts(evts_py8_scale,"non-nominal");
     for(int j=0;j<3;j++){
         ofstream outfile;
         TString outputFileName="/scratchfs/atlas/zhoums/2LSSAna_output/output/Systematics/"+hh_samps[i]+"/"+channels[j]+"_sigtheory.txt";
         cout<<outputFileName.Data()<<endl;
         outfile.open(outputFileName.Data(),ios::trunc); 
         outfile<<"SIG_THEORY_PARTONSHOWER_UP "<<1+fabs((evts_hwg[j]-evts_py8[j])/evts_hwg[j])<<"\n";
         outfile<<"SIG_THEORY_PARTONSHOWER_DOWN "<<1-fabs((evts_hwg[j]-evts_py8[j])/evts_hwg[j])<<"\n";
         outfile<<"SIG_THEORY_SCALE_UP "<<1+fabs((evts_py8_scale[j]-evts_py8_scale[j+3])/evts_py8_scale[j])<<"\n";
         outfile<<"SIG_THEORY_SCALE_DOWN "<<1-fabs((evts_py8_scale[j]-evts_py8_scale[j+3])/evts_py8_scale[j])<<"\n";
     }
  }
  //SS samples
  cout<<"$$$$$$$$$$-SS signal theroetical uncertainty-$$$$$$$$$$$"<<endl;
  //for(int i=0;i<7;i++){
      //parton showering
      /*cout<<SS_samps[i]<<" parton showering uncer."<<endl;     
      ofstream outfile; 
      MiniTruth samp_nom(SS_samps[i],"Nom");
      Float_t *evts_nom=new Float_t[6];
      samp_nom.getSumwgts(evts_nom,"nominal");
      Float_t **evts_up=new Float_t *[5];
      Float_t **evts_dw=new Float_t *[5];
      for(int yy=0;yy<5;yy++) {
          evts_up[yy] = new Float_t[6];
          evts_dw[yy] = new Float_t[6];
      }
      for(int j=0;j<5;j++){
          MiniTruth samp_up(SS_samps[i],variations_up[j]);
          MiniTruth samp_dw(SS_samps[i],variations_dw[j]);
          Float_t *tmp_evts_up=new Float_t[6];
          samp_up.getSumwgts(tmp_evts_up,"nominal");
          Float_t *tmp_evts_dw=new Float_t[6];
          samp_dw.getSumwgts(tmp_evts_dw,"nominal");
          evts_up[j]=tmp_evts_up;
          evts_dw[j]=tmp_evts_dw;
      }*/
      //scale need run separately
      /*Float_t *evts_scale=new Float_t[6];
      MiniTruth samp_scale(SS_samps[i],"Pythia8");
      samp_scale.getSumwgts(evts_scale,"non-nominal");
      for(int k=0;k<3;k++){
          ofstream outfile;
          TString outputFileName="/scratchfs/atlas/zhoums/2LSSAna_output/output/Systematics/"+SS_samps[i]+"/"+channels[k]+"_sigtheory.txt";
          outfile.open(outputFileName.Data(),ios::app);
          //outfile<<"SIG_THEORY_PARTONSHOWER_UP "<<1+sqrt( pow(evts_up[0][k]-evts_nom[k],2)+pow(evts_up[1][k]-evts_nom[k],2)+pow(evts_up[2][k]-evts_nom[k],2)+pow(evts_up[3][k]-evts_nom[k],2)+pow(evts_up[4][k]-evts_nom[k],2) )/evts_nom[k]<<"\n";
         //outfile<<"SIG_THEORY_PARTONSHOWER_DOWN "<<1-sqrt( pow(evts_dw[0][k]-evts_nom[k],2)+pow(evts_dw[1][k]-evts_nom[k],2)+pow(evts_dw[2][k]-evts_nom[k],2)+pow(evts_dw[3][k]-evts_nom[k],2)+pow(evts_dw[4][k]-evts_nom[k],2) )/evts_nom[k];
         outfile<<"\n";
         outfile<<"SIG_THEORY_SCALE_UP "<<1+fabs((evts_scale[k]-evts_scale[k+3])/evts_scale[k])<<"\n";
         outfile<<"SIG_THEORY_SCALE_DOWN "<<1-fabs((evts_scale[k]-evts_scale[k+3])/evts_scale[k])<<"\n";
      }
  }*/
  return 0;
}
