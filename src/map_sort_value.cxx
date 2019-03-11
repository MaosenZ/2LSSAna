Float_t map_sort_value(map<Float_t,Float_t> numbers){

  map<Float_t,Float_t>::iterator it;
  Float_t tmp=-1, key;
  for(it=numbers.begin();it!=numbers.end();++it){
      if(it->second > tmp) {tmp=it->second;  key=it->first;}
  }
  return key;
}
