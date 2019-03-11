export CWD=/afs/ihep.ac.cn/users/z/zhoums/work/2LSSAna
export outpresel=/scratchfs/atlas/zhoums/2LSSAna_output/output/preselection

#hep_sub  $CWD/scripts/preselection/2jets/run_data_nominal_makeNtuple.sh -o $outpresel/run_data_nominal_makeNtuple.out -e $outpresel/run_data_nominal_makeNtuple.err 
#hep_sub $CWD/scripts/preselection/2jets/run_nonres_nominal_makeNtuple.sh -o $outpresel/run_nonres_nominal_makeNtuple.out -e $outpresel/run_nonres_nominal_makeNtuple.err 
#hep_sub $CWD/scripts/preselection/2jets/run_mH260_nominal_makeNtuple.sh     -o $outpresel/run_mH260_nominal_makeNtuple.out     -e $outpresel/run_mH260_nominal_makeNtuple.err    
#hep_sub $CWD/scripts/preselection/2jets/run_mH300_nominal_makeNtuple.sh     -o $outpresel/run_mH300_nominal_makeNtuple.out     -e $outpresel/run_mH300_nominal_makeNtuple.err 
#hep_sub $CWD/scripts/preselection/2jets/run_mH400_nominal_makeNtuple.sh     -o $outpresel/run_mH400_nominal_makeNtuple.out     -e $outpresel/run_mH400_nominal_makeNtuple.err 
#hep_sub $CWD/scripts/preselection/2jets/run_mH500_nominal_makeNtuple.sh     -o $outpresel/run_mH500_nominal_makeNtuple.out     -e $outpresel/run_mH500_nominal_makeNtuple.err 
hep_sub $CWD/scripts/preselection/2jets/run_diboson_nominal_makeNtuple.sh   -o $outpresel/run_diboson_nominal_makeNtuple.out   -e $outpresel/run_diboson_nominal_makeNtuple.err 
hep_sub $CWD/scripts/preselection/2jets/run_ttV_nominal_makeNtuple.sh       -o $outpresel/run_ttV_nominal_makeNtuple.out       -e $outpresel/run_ttV_nominal_makeNtuple.err 
hep_sub $CWD/scripts/preselection/2jets/run_tV_nominal_makeNtuple.sh        -o $outpresel/run_tV_nominal_makeNtuple.out        -e $outpresel/run_tV_nominal_makeNtuple.err 
hep_sub $CWD/scripts/preselection/2jets/run_ttH_nominal_makeNtuple.sh       -o $outpresel/run_ttH_nominal_makeNtuple.out       -e $outpresel/run_ttH_nominal_makeNtuple.err 
hep_sub $CWD/scripts/preselection/2jets/run_VVV_nominal_makeNtuple.sh       -o $outpresel/run_VVV_nominal_makeNtuple.out       -e $outpresel/run_VVV_nominal_makeNtuple.err 
hep_sub $CWD/scripts/preselection/2jets/run_Vgam_nominal_makeNtuple.sh      -o $outpresel/run_Vgam_nominal_makeNtuple.out      -e $outpresel/run_Vgam_nominal_makeNtuple.err 
hep_sub $CWD/scripts/preselection/2jets/run_Wjets_nominal_makeNtuple.sh     -o $outpresel/run_Wjets_nominal_makeNtuple.out     -e $outpresel/run_Wjets_nominal_makeNtuple.err 
hep_sub $CWD/scripts/preselection/2jets/run_Zjets_nominal_makeNtuple.sh     -o $outpresel/run_Zjets_nominal_makeNtuple.out     -e $outpresel/run_Zjets_nominal_makeNtuple.err 
hep_sub $CWD/scripts/preselection/2jets/run_DY_nominal_makeNtuple.sh     -o $outpresel/run_DY_nominal_makeNtuple.out     -e $outpresel/run_DY_nominal_makeNtuple.err 
hep_sub $CWD/scripts/preselection/2jets/run_ttbar_nominal_makeNtuple.sh     -o $outpresel/run_ttbar_nominal_makeNtuple.out     -e $outpresel/run_ttbar_nominal_makeNtuple.err 
hep_sub $CWD/scripts/preselection/2jets/run_WW_nominal_makeNtuple.sh        -o $outpresel/run_WW_nominal_makeNtuple.out        -e $outpresel/run_WW_nominal_makeNtuple.err 
