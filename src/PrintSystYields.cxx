#include "cmath"
#include <iostream>
#include <iomanip>

void PrintMCEventYields(map<string,NomErr2> yields,string masspoint,string sample){ 
   string channels[]={"ee","mumu","emu"}; 
   for(int i=0;i<3;i++) {//3 channels
       ofstream outfile;
       string outputFileName="/scratchfs/atlas/zhoums/2LSSAna_output/output/Systematics/"+masspoint+"/"+channels[i]+"_"+sample+".txt";
       outfile.open(outputFileName.c_str(),ios::trunc);
       string type=channels[i]+"_"+sample;
       map<string,NomErr2>::iterator it; 
       for(it=yields.begin();it!=yields.end();++it){
           string syst=it->first;
           size_t found=syst.find(type);
           if(syst==type) {//nominal value
              //outfile<<"#"<<sample<<endl;
              outfile<<"N_"<<channels[i]<<"_"<<sample<<" "<<it->second.Nom<<"\n";
              outfile<<"Stat_"<<channels[i]<<"_"<<sample<<"_UP "<<1+sqrt(yields[type].Err2)/it->second.Nom<<"\n";
              outfile<<"Stat_"<<channels[i]<<"_"<<sample<<"_DOWN "<<1-sqrt(yields[type].Err2)/it->second.Nom<<"\n";
           }
           if(found==0&&syst!=type&&it->second.tag!=2){//systematic variations
              if(syst==type+"_MV2c10_70_EventWeight_C0_UP")//set it to symmetry to down, as it is not correctly stored
                 outfile<<syst.substr(channels[i].length()+1)<<" "<<2.-yields[type+"_MV2c10_70_EventWeight_C0_DOWN"].Nom/yields[type].Nom<<"\n";
              else outfile<<syst.substr(channels[i].length()+1)<<" "<<it->second.Nom/yields[type].Nom<<"\n";
           }
           if(found==0&&syst!=type&&it->second.tag==2){//print NonEventWeightType systs
              TString checks=syst;
              string typex=channels[i]+"_"+sample+"_"+"nominal";
              if(!checks.Contains("nominal") && !checks.Contains("JET_JER_SINGLE_NP__1up") && !checks.Contains("MET_SoftTrk_ResoPara") && !checks.Contains("MET_SoftTrk_ResoPerp")) outfile<<syst.substr(channels[i].length()+1)<<" "<<it->second.Nom/yields[typex].Nom<<"\n";
              else outfile<<syst.substr(channels[i].length()+1)<<"__1up"<<" "<<it->second.Nom/yields[typex].Nom<<"\n"<<syst.substr(channels[i].length()+1)<<"__1down"<<" "<<(2-it->second.Nom/yields[typex].Nom)<<"\n";
           }
       }//end of iterator of yields
   }//end of 3 channels
      
}

void PrintMCEventYieldsTex(map<string,NomErr2> yields,string masspoint){ 
   string samples[]={masspoint,"promptSS","Vgam"};
   string channels[]={"ee","mumu","emu"}; 
   for(int i=0;i<3;i++) {//3 channels
       ofstream outfile;
       string outputFileName="/scratchfs/atlas/zhoums/2LSSAna_output/output/Systematics/"+masspoint+"/"+channels[i]+".tex";
       outfile.open(outputFileName.c_str(),ios::trunc);
       string type_signal=channels[i]+"_"+masspoint;
       string type_promptSS=channels[i]+"_promptSS";
       string type_Vgam=channels[i]+"_Vgam";
       map<string,NomErr2>::iterator it; 
       //set precision
       outfile.setf(ios::fixed, ios::floatfield);
       outfile.precision(2);       
       outfile<<"\\begin{table}[h]"<<"\n";
       outfile<<"\\scriptsize"<<"\n";
       outfile<<"\\begin{center}"<<"\n";
       outfile<<"\\begin{tabular}{l|ccccccccc}"<<"\n";
       outfile<<"\\hline"<<"\n";
       outfile<<"\\hline"<<"\n"; 
       if(i==1) outfile<<"Uncertainty source "<<"&Signal &promptSS \\\\"<<"\n";
       else outfile<<"Uncertainty source "<<"&Signal &promptSS &Vgam \\\\"<<"\n";
       ifstream ifile("/afs/ihep.ac.cn/users/z/zhoums/work/2LSSAna/inc/EventWeightSysSrcs",ifstream::in);
       if(!ifile) cout<<"not be able open "<<"EventWeightSysSrcs"<<endl;
       string line;
       while(getline(ifile,line)){
            char dsid[200];
            const char* readline=line.c_str();
            sscanf(readline,"%s",dsid);
            if(dsid[0]=='#') continue;
            string SysSrc(dsid);
            if(SysSrc=="MV2c10_70_EventWeight_C0"){
               yields[type_signal+"_"+SysSrc+"_UP"].Nom=2*yields[type_signal].Nom-yields[type_signal+"_"+SysSrc+"_DOWN"].Nom;
               yields[type_promptSS+"_"+SysSrc+"_UP"].Nom=2*yields[type_promptSS].Nom-yields[type_promptSS+"_"+SysSrc+"_DOWN"].Nom;
               yields[type_Vgam+"_"+SysSrc+"_UP"].Nom=2*yields[type_Vgam].Nom-yields[type_Vgam+"_"+SysSrc+"_DOWN"].Nom;
            }
            if(i==1) outfile<<SysSrc<<" &"<<100*(yields[type_signal+"_"+SysSrc+"_UP"].Nom-yields[type_signal].Nom)/yields[type_signal].Nom
                           <<"/"<<100*(yields[type_signal+"_"+SysSrc+"_DOWN"].Nom-yields[type_signal].Nom)/yields[type_signal].Nom
                          <<" &"<<100*(yields[type_promptSS+"_"+SysSrc+"_UP"].Nom-yields[type_promptSS].Nom)/yields[type_promptSS].Nom
                <<"/"<<100*(yields[type_promptSS+"_"+SysSrc+"_DOWN"].Nom-yields[type_promptSS].Nom)/yields[type_promptSS].Nom<<" \\\\"<<"\n";
            else outfile<<SysSrc<<" &"<<100*(yields[type_signal+"_"+SysSrc+"_UP"].Nom-yields[type_signal].Nom)/yields[type_signal].Nom
                           <<"/"<<100*(yields[type_signal+"_"+SysSrc+"_DOWN"].Nom-yields[type_signal].Nom)/yields[type_signal].Nom
                          <<" &"<<100*(yields[type_promptSS+"_"+SysSrc+"_UP"].Nom-yields[type_promptSS].Nom)/yields[type_promptSS].Nom
                       <<"/"<<100*(yields[type_promptSS+"_"+SysSrc+"_DOWN"].Nom-yields[type_promptSS].Nom)/yields[type_promptSS].Nom
                       <<" &"<<100*(yields[type_Vgam+"_"+SysSrc+"_UP"].Nom-yields[type_Vgam].Nom)/yields[type_Vgam].Nom
                   <<"/"<<100*(yields[type_Vgam+"_"+SysSrc+"_DOWN"].Nom-yields[type_Vgam].Nom)/yields[type_Vgam].Nom<<" \\\\"<<"\n";
       }
       
       ifstream ifile2("/afs/ihep.ac.cn/users/z/zhoums/work/2LSSAna/inc/NonEventWeightSysSrcs",ifstream::in);
       if(!ifile2) cout<<"not be able open "<<"NonEventWeightSysSrcs"<<endl;
       string line2;
       while(getline(ifile2,line2)){
            char dsid[200];
            const char* readline=line2.c_str();
            sscanf(readline,"%s",dsid);
            if(dsid[0]=='#') continue;
            string SysSrc(dsid);
            if(i==1) {
               outfile<<SysSrc<<" &"<<100*(yields[type_signal+"_"+SysSrc+"__1up"].Nom-yields[type_signal+"_nominal"].Nom)/yields[type_signal+"_nominal"].Nom
                           <<"/"<<100*(yields[type_signal+"_"+SysSrc+"__1down"].Nom-yields[type_signal+"_nominal"].Nom)/yields[type_signal+"_nominal"].Nom
                          <<" &"<<100*(yields[type_promptSS+"_"+SysSrc+"__1up"].Nom-yields[type_promptSS+"_nominal"].Nom)/yields[type_promptSS+"_nominal"].Nom
                <<"/"<<100*(yields[type_promptSS+"_"+SysSrc+"__1down"].Nom-yields[type_promptSS+"_nominal"].Nom)/yields[type_promptSS+"_nominal"].Nom<<" \\\\"<<"\n";
            }
            else {
              outfile<<SysSrc<<" &"<<100*(yields[type_signal+"_"+SysSrc+"__1up"].Nom-yields[type_signal+"_nominal"].Nom)/yields[type_signal+"_nominal"].Nom
                           <<"/"<<100*(yields[type_signal+"_"+SysSrc+"__1down"].Nom-yields[type_signal+"_nominal"].Nom)/yields[type_signal+"_nominal"].Nom
                          <<" &"<<100*(yields[type_promptSS+"_"+SysSrc+"__1up"].Nom-yields[type_promptSS+"_nominal"].Nom)/yields[type_promptSS+"_nominal"].Nom
                       <<"/"<<100*(yields[type_promptSS+"_"+SysSrc+"__1down"].Nom-yields[type_promptSS+"_nominal"].Nom)/yields[type_promptSS+"_nominal"].Nom
                       <<" &"<<100*(yields[type_Vgam+"_"+SysSrc+"__1up"].Nom-yields[type_Vgam+"_nominal"].Nom)/yields[type_Vgam+"_nominal"].Nom
                   <<"/"<<100*(yields[type_Vgam+"_"+SysSrc+"__1down"].Nom-yields[type_Vgam+"_nominal"].Nom)/yields[type_Vgam+"_nominal"].Nom<<" \\\\"<<"\n";
            }
       }
       //next, print some remaining special systs
       string specials[]={"JET_JER_SINGLE_NP","MET_SoftTrk_ResoPara","MET_SoftTrk_ResoPerp"};
       if(i==1){
          for(int k=0;k<3;k++){
                   string special=specials[k]; if(k==0)special="JET_JER_SINGLE_NP__1up";
                   outfile<<specials[k]<<" &"<<100*(yields[type_signal+"_"+special].Nom-yields[type_signal+"_nominal"].Nom)/yields[type_signal+"_nominal"].Nom<<"/"<<100*(yields[type_signal+"_nominal"].Nom-yields[type_signal+"_"+special].Nom)/yields[type_signal+"_nominal"].Nom<<" &"<<
                   100*(yields[type_promptSS+"_"+special].Nom-yields[type_promptSS+"_nominal"].Nom)/yields[type_promptSS+"_nominal"].Nom<<"/"<<100*(yields[type_promptSS+"_nominal"].Nom-yields[type_promptSS+"_"+special].Nom)/yields[type_promptSS+"_nominal"].Nom<<" \\\\"<<"\n";
          }
          //for MET_SoftTrk_Scale
          string SysSrc="MET_SoftTrk_Scale";
          outfile<<SysSrc<<" &"<<100*(yields[type_signal+"_"+SysSrc+"Up"].Nom-yields[type_signal+"_nominal"].Nom)/yields[type_signal+"_nominal"].Nom
                           <<"/"<<100*(yields[type_signal+"_"+SysSrc+"Down"].Nom-yields[type_signal+"_nominal"].Nom)/yields[type_signal+"_nominal"].Nom
                          <<" &"<<100*(yields[type_promptSS+"_"+SysSrc+"Up"].Nom-yields[type_promptSS+"_nominal"].Nom)/yields[type_promptSS+"_nominal"].Nom
                <<"/"<<100*(yields[type_promptSS+"_"+SysSrc+"Down"].Nom-yields[type_promptSS+"_nominal"].Nom)/yields[type_promptSS+"_nominal"].Nom<<" \\\\"<<"\n";
       }
       else {
         for(int k=0;k<3;k++){
                   string special=specials[k]; if(k==0)special="JET_JER_SINGLE_NP__1up";
                   outfile<<specials[k]<<" &"<<100*(yields[type_signal+"_"+special].Nom-yields[type_signal+"_nominal"].Nom)/yields[type_signal+"_nominal"].Nom<<"/"<<100*(yields[type_signal+"_nominal"].Nom-yields[type_signal+"_"+special].Nom)/yields[type_signal+"_nominal"].Nom<<" &"<<
                   100*(yields[type_promptSS+"_"+special].Nom-yields[type_promptSS+"_nominal"].Nom)/yields[type_promptSS+"_nominal"].Nom<<"/"<<100*(yields[type_promptSS+"_nominal"].Nom-yields[type_promptSS+"_"+special].Nom)/yields[type_promptSS+"_nominal"].Nom<<" &"<<
                   100*(yields[type_Vgam+"_"+special].Nom-yields[type_Vgam+"_nominal"].Nom)/yields[type_Vgam+"_nominal"].Nom<<"/"<<100*(yields[type_Vgam+"_nominal"].Nom-yields[type_Vgam+"_"+special].Nom)/yields[type_Vgam+"_nominal"].Nom<<" \\\\"<<"\n";
         }
         string SysSrc="MET_SoftTrk_Scale";
                  outfile<<SysSrc<<" &"<<100*(yields[type_signal+"_"+SysSrc+"Up"].Nom-yields[type_signal+"_nominal"].Nom)/yields[type_signal+"_nominal"].Nom
                           <<"/"<<100*(yields[type_signal+"_"+SysSrc+"Down"].Nom-yields[type_signal+"_nominal"].Nom)/yields[type_signal+"_nominal"].Nom
                          <<" &"<<100*(yields[type_promptSS+"_"+SysSrc+"Up"].Nom-yields[type_promptSS+"_nominal"].Nom)/yields[type_promptSS+"_nominal"].Nom
                <<"/"<<100*(yields[type_promptSS+"_"+SysSrc+"Down"].Nom-yields[type_promptSS+"_nominal"].Nom)/yields[type_promptSS+"_nominal"].Nom<<" &"<<
               100*(yields[type_Vgam+"_"+SysSrc+"Up"].Nom-yields[type_Vgam+"_nominal"].Nom)/yields[type_Vgam+"_nominal"].Nom
                <<"/"<<100*(yields[type_Vgam+"_"+SysSrc+"Down"].Nom-yields[type_Vgam+"_nominal"].Nom)/yields[type_Vgam+"_nominal"].Nom<<" \\\\"<<"\n";

       }
       outfile<<"\\hline"<<"\n";
       outfile<<"\\hline"<<"\n";
       outfile<<"\\end{tabular}"<<"\n";
       outfile<<"\\end{center}"<<"\n";
       outfile<<"\\end{table}"<<"\n"; 
   }//end of 3 channels
      
}
void PrintDatadrivenEventYields(map<string,NomErr2> yields,string masspoint,string sample){
  //first set down ff values and related syst.
  float           ff_ele;
  float           ff_mu;
  float           Stat_ff_ele;
  float           QmisID_ff_ele;
  float           Closure_ff_ele;
  float           Composition_ff_ele;
  float           Stat_ff_mu;
  float           Closure_ff_mu;
  float           Composition_ff_mu;
  float           QmisIDMC_ff_ele;
  float           ssWW_ff_ele;
  float           ssWW_ff_mu;
  float           WZ_ff_ele;
  float           WZ_ff_mu;
  float           Vgam_ff_ele;
  if(masspoint=="mH260" || masspoint=="mH300" || masspoint=="H280_S135" || masspoint=="H300_S135" || masspoint=="H320_S135"){
     ff_ele=0.5401; ff_mu=0.5033;
         Stat_ff_ele=0.0576; QmisID_ff_ele=0.33; Closure_ff_ele=0.388; Composition_ff_ele=0.3383;
         Stat_ff_mu=0.0999; Closure_ff_mu=0.388; Composition_ff_mu=0.3169;
         WZ_ff_ele=0.0893; ssWW_ff_ele=0.0122; ssWW_ff_mu=0.0606; WZ_ff_mu=0.3900;
         QmisIDMC_ff_ele=0.015;
         Vgam_ff_ele=0.1155;

  }
  else if(masspoint=="mH400" || masspoint=="mH500" || masspoint=="nonres" || masspoint=="H340_S135" || masspoint=="H340_S145"
               || masspoint=="H340_S155" || masspoint=="H340_S165"){
       ff_ele=0.5472; ff_mu=0.4544;
         Stat_ff_ele=0.0482; QmisID_ff_ele=0.30; Closure_ff_ele=0.388; Composition_ff_ele=0.462;
         Stat_ff_mu=0.077; Closure_ff_mu=0.388; Composition_ff_mu=0.485;
         WZ_ff_ele=0.0794; ssWW_ff_ele=0.0208; ssWW_ff_mu=0.1039; WZ_ff_mu=0.3364;
         QmisIDMC_ff_ele=0.02;
         Vgam_ff_ele=0.1228;

  }
  string channels[]={"ee","mumu","emu"};
  for(int i=0;i<3;i++) {//3 channels
      ofstream outfile;
      string outputFileName="/scratchfs/atlas/zhoums/2LSSAna_output/output/Systematics/"+masspoint+"/"+channels[i]+"_"+sample+".txt";
      outfile.open(outputFileName.c_str(),ios::trunc);
      map<string,NomErr2>::iterator it;
      for(it=yields.begin();it!=yields.end();++it){
          string syst=it->first;
          if(i==0&&syst=="ee_QmisID"){
             outfile<<"N_ee_QmisID "<<yields["ee_QmisID"].Nom<<"\n";
             outfile<<"Stat_ee_QmisID_UP "<<1+sqrt(yields["ee_QmisID"].Err2)/yields["ee_QmisID"].Nom<<"\n";
             outfile<<"Stat_ee_QmisID_DOWN "<<1-sqrt(yields["ee_QmisID"].Err2)/yields["ee_QmisID"].Nom<<"\n";
             outfile<<"Syst_ee_QmisID_UP "<<1+QmisID_ff_ele<<"\n";
             outfile<<"Syst_ee_QmisID_DOWN "<<1-QmisID_ff_ele<<"\n";
          }
          if(i==2 && syst=="emu_QmisID"){
             outfile<<"N_emu_QmisID "<<yields["emu_QmisID"].Nom<<"\n";
             outfile<<"Stat_emu_QmisID_UP "<<1+sqrt(yields["emu_QmisID"].Err2)/yields["emu_QmisID"].Nom<<"\n";
             outfile<<"Stat_emu_QmisID_DOWN "<<1-sqrt(yields["emu_QmisID"].Err2)/yields["emu_QmisID"].Nom<<"\n";
             outfile<<"Syst_emu_QmisID_UP "<<1+QmisID_ff_ele<<"\n";
             outfile<<"Syst_emu_QmisID_DOWN "<<1-QmisID_ff_ele<<"\n";
          }
          if(i==0&&syst=="eantiide_fake"){
             outfile<<"N_ee_fake "<<yields["eantiide_fake"].Nom<<"\n";
             outfile<<"Stat_ee_fake_UP "<<1+sqrt(ff_ele*yields["eantiide_fake"].Nom)/yields["eantiide_fake"].Nom<<"\n";//stat. error of fakes
             outfile<<"Stat_ee_fake_DOWN "<<1-sqrt(ff_ele*yields["eantiide_fake"].Nom)/yields["eantiide_fake"].Nom<<"\n";//stat. error of fakes
             outfile<<"Stat_ff_ele_UP "<<1+Stat_ff_ele<<"\n";//stat. error on fake factor itself
             outfile<<"Stat_ff_ele_DOWN "<<1-Stat_ff_ele<<"\n";//stat. error on fake factor itself
             outfile<<"QmisID_ff_ele_UP "<<1-QmisID_ff_ele<<"\n";
             outfile<<"QmisID_ff_ele_DOWN "<<1+QmisID_ff_ele<<"\n";
             outfile<<"Closure_ff_ele_UP "<<1+Closure_ff_ele<<"\n";
             outfile<<"Closure_ff_ele_DOWN "<<1-Closure_ff_ele<<"\n";
             outfile<<"Composition_ff_ele_UP "<<1+Composition_ff_ele<<"\n";
             outfile<<"Composition_ff_ele_DOWN "<<1-Composition_ff_ele<<"\n";
             outfile<<"ssWW_ff_UP "<<1-ssWW_ff_ele<<"\n";
             outfile<<"ssWW_ff_DOWN "<<1+ssWW_ff_ele<<"\n";
             outfile<<"WZ_ff_UP "<<1-WZ_ff_ele<<"\n";
             outfile<<"WZ_ff_DOWN "<<1+WZ_ff_ele<<"\n";
             outfile<<"Vgam_ff_UP "<<1-Vgam_ff_ele<<"\n";
             outfile<<"Vgam_ff_DOWN "<<1+Vgam_ff_ele<<"\n";
             outfile<<"QmisIDMC_ff_UP "<<1+QmisIDMC_ff_ele<<"\n";
             outfile<<"QmisIDMC_ff_DOWN "<<1-QmisIDMC_ff_ele<<"\n";
          }
          if(i==1 && syst=="muantiidmu_fake"){
             outfile<<"N_mumu_fake "<<yields["muantiidmu_fake"].Nom<<"\n";
             outfile<<"Stat_mumu_fake_UP "<<1+sqrt(ff_mu*yields["muantiidmu_fake"].Nom)/yields["muantiidmu_fake"].Nom<<"\n";//stat. error of fakes
             outfile<<"Stat_mumu_fake_DOWN "<<1-sqrt(ff_mu*yields["muantiidmu_fake"].Nom)/yields["muantiidmu_fake"].Nom<<"\n";//stat. error of fakes
             outfile<<"Stat_ff_mu_UP "<<1+Stat_ff_mu<<"\n";//stat. error on fake factor itself
             outfile<<"Stat_ff_mu_DOWN "<<1-Stat_ff_mu<<"\n";//stat. error on fake factor itself
             outfile<<"Closure_ff_mu_UP "<<1+Closure_ff_mu<<"\n";
             outfile<<"Closure_ff_mu_DOWN "<<1-Closure_ff_mu<<"\n";
             outfile<<"Composition_ff_mu_UP "<<1+Composition_ff_mu<<"\n";
             outfile<<"Composition_ff_mu_DOWN "<<1-Composition_ff_mu<<"\n";
             outfile<<"ssWW_ff_UP "<<1-ssWW_ff_mu<<"\n";
             outfile<<"ssWW_ff_DOWN "<<1+ssWW_ff_mu<<"\n";
             outfile<<"WZ_ff_UP "<<1-WZ_ff_mu<<"\n";
             outfile<<"WZ_ff_DOWN "<<1+WZ_ff_mu<<"\n";
          }
          if(i==2 && syst=="emu_fake"){
             outfile<<"N_emu_fake "<<yields["emu_fake"].Nom<<"\n";
             outfile<<"Stat_antiidemu_fake_UP "<<1+sqrt(ff_ele*yields["antiidemu_fake"].Nom)/yields["emu_fake"].Nom<<"\n";
             outfile<<"Stat_antiidemu_fake_DOWN "<<1-sqrt(ff_ele*yields["antiidemu_fake"].Nom)/yields["emu_fake"].Nom<<"\n";
             outfile<<"Stat_eantiidmu_fake_UP "<<1+sqrt(ff_ele*yields["eantiidmu_fake"].Nom)/yields["emu_fake"].Nom<<"\n";
             outfile<<"Stat_eantiidmu_fake_DOWN "<<1-sqrt(ff_ele*yields["eantiidmu_fake"].Nom)/yields["emu_fake"].Nom<<"\n";
             outfile<<"Stat_ff_ele_UP "<<1+Stat_ff_ele*yields["antiidemu_fake"].Nom/yields["emu_fake"].Nom<<"\n"; 
             outfile<<"Stat_ff_ele_DOWN "<<1-Stat_ff_ele*yields["antiidemu_fake"].Nom/yields["emu_fake"].Nom<<"\n"; 
             outfile<<"QmisID_ff_ele_UP "<<1-QmisID_ff_ele*yields["antiidemu_fake"].Nom/yields["emu_fake"].Nom<<"\n";
             outfile<<"QmisID_ff_ele_DOWN "<<1+QmisID_ff_ele*yields["antiidemu_fake"].Nom/yields["emu_fake"].Nom<<"\n";
             outfile<<"Closure_ff_ele_UP "<<1+Closure_ff_ele*yields["antiidemu_fake"].Nom/yields["emu_fake"].Nom<<"\n";
             outfile<<"Closure_ff_ele_DOWN "<<1-Closure_ff_ele*yields["antiidemu_fake"].Nom/yields["emu_fake"].Nom<<"\n";
             outfile<<"Composition_ff_ele_UP "<<1+Composition_ff_ele*yields["antiidemu_fake"].Nom/yields["emu_fake"].Nom<<"\n";
             outfile<<"Composition_ff_ele_DOWN "<<1-Composition_ff_ele*yields["antiidemu_fake"].Nom/yields["emu_fake"].Nom<<"\n";
             outfile<<"Stat_ff_mu_UP "<<1+Stat_ff_mu*yields["eantiidmu_fake"].Nom/yields["emu_fake"].Nom<<"\n";
             outfile<<"Stat_ff_mu_DOWN "<<1-Stat_ff_mu*yields["eantiidmu_fake"].Nom/yields["emu_fake"].Nom<<"\n";
             outfile<<"Closure_ff_mu_UP "<<1+Closure_ff_mu*yields["eantiidmu_fake"].Nom/yields["emu_fake"].Nom<<"\n";
             outfile<<"Closure_ff_mu_DOWN "<<1-Closure_ff_mu*yields["eantiidmu_fake"].Nom/yields["emu_fake"].Nom<<"\n";
             outfile<<"Composition_ff_mu_UP "<<1+Composition_ff_mu*yields["eantiidmu_fake"].Nom/yields["emu_fake"].Nom<<"\n";
             outfile<<"Composition_ff_mu_DOWN "<<1-Composition_ff_mu*yields["eantiidmu_fake"].Nom/yields["emu_fake"].Nom<<"\n";
             outfile<<"ssWW_ff_UP "<<1-(ssWW_ff_mu*yields["eantiidmu_fake"].Nom+ssWW_ff_ele*yields["antiidemu_fake"].Nom)/
                                         yields["emu_fake"].Nom<<"\n";
             outfile<<"ssWW_ff_DOWN "<<1+(ssWW_ff_mu*yields["eantiidmu_fake"].Nom+ssWW_ff_ele*yields["antiidemu_fake"].Nom)/                                         yields["emu_fake"].Nom<<"\n";
             outfile<<"WZ_ff_UP "<<1-(WZ_ff_mu*yields["eantiidmu_fake"].Nom+WZ_ff_ele*yields["antiidemu_fake"].Nom)/                                         yields["emu_fake"].Nom<<"\n";
             outfile<<"WZ_ff_DOWN "<<1+(WZ_ff_mu*yields["eantiidmu_fake"].Nom+WZ_ff_ele*yields["antiidemu_fake"].Nom)/                                         yields["emu_fake"].Nom<<"\n";
             outfile<<"Vgam_ff_UP "<<1-Vgam_ff_ele*yields["antiidemu_fake"].Nom/yields["emu_fake"].Nom<<"\n";
             outfile<<"Vgam_ff_DOWN "<<1+Vgam_ff_ele*yields["antiidemu_fake"].Nom/yields["emu_fake"].Nom<<"\n";
             outfile<<"QMisIDMC_ff_UP "<<1+QmisIDMC_ff_ele*yields["antiidemu_fake"].Nom/yields["emu_fake"].Nom<<"\n";
             outfile<<"QMisIDMC_ff_DOWN "<<1-QmisIDMC_ff_ele*yields["antiidemu_fake"].Nom/yields["emu_fake"].Nom<<"\n";
          }
      }//end of loop yields map
  }//end of writing 3 channels    
}
