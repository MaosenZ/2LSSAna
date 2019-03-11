//sort pair based on second value
struct pairSortFun: public binary_function<pair<int,float> &,pair<int,float> &,bool>{
       bool operator()(const pair<int,float>&elemx,const pair<int,float>&elemy){
              return ((elemx.second) < (elemy.second));
       }
};

struct pairSortFun_float: public binary_function<pair<float,float> &,pair<float,float> &,bool>{
       bool operator()(const pair<float,float>&elemx,const pair<float,float>&elemy){
              return ((elemx.second) < (elemy.second));
       }
};
//get root mean squares of a vector value
Float_t getRMS(vector<float> *values){
  float sum_squares=0;
  unsigned int entries=values->size();
  for(unsigned int i=0;i<entries;i++){
      sum_squares+=((*values)[i])*((*values)[i]);
  }
  return sqrt(sum_squares/(float)entries);
}
//invariant mass of all jets
Float_t f_m_jj(vector<TLorentzVector> *jet){
  float mass;
  TLorentzVector tmp_jet; tmp_jet.SetPtEtaPhiE(0,0,0,0);
  for(unsigned int i=0;i<jet->size();i++)tmp_jet+=(*jet)[i];
  mass=tmp_jet.M();
  return mass;
}
//invariant mass of j1 j2
Float_t f_m_j1j2(vector<TLorentzVector> *jet){
  float mass;
  TLorentzVector tmp_jet; tmp_jet.SetPtEtaPhiE(0,0,0,0);
  for(unsigned int i=0;i<2;i++)tmp_jet+=(*jet)[i];
  mass=tmp_jet.M();
  return mass;
}

//invariant mass of j1 j3
Float_t f_m_j1j3(vector<TLorentzVector> *jet){
  float mass=((*jet)[0] + (*jet)[2]).M();
  
  return mass;
}

//invariant mass of j2 j3
Float_t f_m_j2j3(vector<TLorentzVector> *jet){
  float mass=((*jet)[1] + (*jet)[2]).M();
  
  return mass;
}

//invariant mass of two closet jets
Float_t f_m_jj_w(vector<TLorentzVector> *lepton,vector<TLorentzVector> *jet){
  float *m_jj_w=new float[2];
  vector<pair<int,float> >vecpairdRjj;
  vector<float>m_jj;vector<float>dR_jj;int index=0;
  for(unsigned int i=0;i<jet->size()-1;i++){
      for(unsigned int j=i+1;j<jet->size();j++){
          float tmp_m_jj=((*jet)[i] + (*jet)[j]).M();
          float tmp_dR_jj=(*jet)[i].DeltaR((*jet)[j]);
          m_jj.push_back(tmp_m_jj);
          dR_jj.push_back(tmp_dR_jj);
          pair<int,float>pp(index,tmp_dR_jj);vecpairdRjj.push_back(pp);
          index++;
      }
  }
  sort(vecpairdRjj.begin(),vecpairdRjj.end(),pairSortFun());
  for(int j=0;j<index;j++){
      if(vecpairdRjj[0].first==j){
         m_jj_w[0]=m_jj[j];
      }
  }
  return m_jj_w[0];
}
//invariant mass of all selected objects, except met
Float_t f_m_all(vector<TLorentzVector> *lepton, vector<TLorentzVector> *jet,TLorentzVector *metVec){
  Float_t m_all;
  TLorentzVector tmp_jet; tmp_jet.SetPtEtaPhiE(0,0,0,0);
  for(unsigned int i=0;i<jet->size();i++) tmp_jet += (*jet)[i];
  m_all=((*lepton)[0] + (*lepton)[1] + tmp_jet + *metVec).M();
  return m_all;
}
//pt of vector sum of all selected objects, excluding met
Float_t f_pt_vecsum(vector<TLorentzVector> *lepton, vector<TLorentzVector> *jet,TLorentzVector *metVec){
  Float_t pt_sum;
  TLorentzVector tmp_jet; tmp_jet.SetPtEtaPhiE(0,0,0,0);
  for(unsigned int i=0;i<jet->size();i++) tmp_jet += (*jet)[i];
  pt_sum=((*lepton)[0] + (*lepton)[1] + tmp_jet + *metVec).Pt();
  return pt_sum;
};
//linear sum of pt
Float_t f_pt_sum(vector<TLorentzVector> *lepton, vector<TLorentzVector> *jet, TLorentzVector *metVec){
  Float_t pt_sum;
  TLorentzVector tmp_jet; tmp_jet.SetPtEtaPhiE(0,0,0,0);
  for(unsigned int i=0;i<jet->size();i++) tmp_jet += (*jet)[i];
  pt_sum=(*lepton)[0].Pt() + (*lepton)[1].Pt() + tmp_jet.Pt() + (*metVec).Pt();
  return pt_sum;
};
//invariant mass of leading lepton and two closet jets
Float_t f_m_l1jj(vector<TLorentzVector> *lepton, vector<TLorentzVector> *jet){
  vector<pair<int,float> >vecpairdRl1j;
  for(Int_t i=0;i<jet->size();i++){
      pair<int,float>pp(i,(*jet)[i].DeltaR((*lepton)[0]));vecpairdRl1j.push_back(pp);
  }
  Float_t m_l1jj;
  sort(vecpairdRl1j.begin(),vecpairdRl1j.end(),pairSortFun());
  for(unsigned int i=0;i<vecpairdRl1j.size();i++){
      for(unsigned int j=0;j<vecpairdRl1j.size();j++){
          if((*(vecpairdRl1j.begin())).first==i &&((vecpairdRl1j[1])).first==j)
               m_l1jj=((*lepton)[0] + (*jet)[i] + (*jet)[j]).M();
      }
  }
  return m_l1jj;
}
//distance in R-phi between leading lepton and closet jet
Float_t f_mindR_l1j(vector<TLorentzVector> *lepton, vector<TLorentzVector> *jet){
  vector<pair<int,float> >vecpairdRl1j;
  for(unsigned int i=0;i<jet->size();i++){
      pair<int,float>pp(i,(*jet)[i].DeltaR((*lepton)[0]));vecpairdRl1j.push_back(pp);
  }
  sort(vecpairdRl1j.begin(),vecpairdRl1j.end(),pairSortFun());
  Float_t mindR_l1j=(*(vecpairdRl1j.begin())).second;
  return mindR_l1j;
}
//invariant mass of leading lepton and closet jet
Float_t f_m_l1j(vector<TLorentzVector> *lepton, vector<TLorentzVector> *jet){
  vector<pair<float,float> >vecpairdRl1j;
  for(Int_t i=0;i<jet->size();i++){
      pair<float,float>pp(((*jet)[i] + (*lepton)[0]).M(),(*jet)[i].DeltaR((*lepton)[0]));vecpairdRl1j.push_back(pp);
  }
  sort(vecpairdRl1j.begin(),vecpairdRl1j.end(),pairSortFun_float());
  Float_t m_l1j=(*(vecpairdRl1j.begin())).first;
  return m_l1j;
}
//distance in R-phi between sub leading lepton and closet jet
Float_t f_mindR_l2j(vector<TLorentzVector> *lepton, vector<TLorentzVector> *jet){
  vector<pair<int,float> >vecpairdRl2j;
  for(Int_t i=0;i<jet->size();i++){
      pair<int,float>pp(i,(*jet)[i].DeltaR((*lepton)[1]));vecpairdRl2j.push_back(pp);
  }
  sort(vecpairdRl2j.begin(),vecpairdRl2j.end(),pairSortFun());
  Float_t mindR_l2j=(*(vecpairdRl2j.begin())).second;
  return mindR_l2j;
}
//invariant mass of sub leading lepton and closet jet
Float_t f_m_l2j(vector<TLorentzVector> *lepton, vector<TLorentzVector> *jet){
  vector<pair<float,float> >vecpairdRl1j;
  for(Int_t i=0;i<jet->size();i++){
      pair<float,float>pp(((*jet)[i] + (*lepton)[1]).M(),(*jet)[i].DeltaR((*lepton)[1]));vecpairdRl1j.push_back(pp);
  }
  sort(vecpairdRl1j.begin(),vecpairdRl1j.end(),pairSortFun_float());
  Float_t m_l2j=(*(vecpairdRl1j.begin())).first;
  return m_l2j;
}
//Transverse mass of all selected objects
Float_t f_Mt(vector<TLorentzVector> *lepton, vector<TLorentzVector> *jet, TLorentzVector *met){
 float Mt;
 TLorentzVector tmp_jet; tmp_jet.SetPtEtaPhiE(0,0,0,0);
 for(unsigned int i=0;i<jet->size();i++) tmp_jet += (*jet)[i];
 Mt=((*lepton)[0] + (*lepton)[1] + tmp_jet + *met).Mt();
 return Mt;
}
//root mean squres
Float_t f_RMS(vector<TLorentzVector> *lepton,vector<TLorentzVector> *jet, TLorentzVector *met){
  float RMS;
  vector<float> phi_leptons; vector<float> phi_jets; vector<float>phi_all;
  for(unsigned int i=0;i<lepton->size();i++){
      phi_leptons.push_back((*lepton)[i].Phi());
      phi_all.push_back((*lepton)[i].Phi());
  }
  for(unsigned int i=0;i<jet->size();i++){
      phi_jets.push_back((*jet)[i].Phi());
      phi_all.push_back((*jet)[i].Phi());
  }
  phi_leptons.push_back(met->Phi());
  phi_all.push_back(met->Phi());
  RMS=getRMS(&phi_jets)*getRMS(&phi_leptons)/getRMS(&phi_all);
  return RMS;
}
