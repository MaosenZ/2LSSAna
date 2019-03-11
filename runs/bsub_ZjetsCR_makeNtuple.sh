export CWD=/afs/ihep.ac.cn/users/z/zhoums/work/2LSSAna
export outZjetsCR=/scratchfs/atlas/zhoums/2LSSAna_output/output/ZjetsCR

hep_sub  $CWD/scripts/ZjetsCR/run_data_nominal_makeNtuple.sh -o $outZjetsCR/run_data_nominal_makeNtuple.out -e $outZjetsCR/run_data_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ZjetsCR/run_nonres_nominal_makeNtuple.sh -o $outZjetsCR/run_nonres_nominal_makeNtuple.out -e $outZjetsCR/run_nonres_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ZjetsCR/run_mH260_nominal_makeNtuple.sh     -o $outZjetsCR/run_mH260_nominal_makeNtuple.out     -e $outZjetsCR/run_mH260_nominal_makeNtuple.err    
hep_sub $CWD/scripts/ZjetsCR/run_mH300_nominal_makeNtuple.sh     -o $outZjetsCR/run_mH300_nominal_makeNtuple.out     -e $outZjetsCR/run_mH300_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ZjetsCR/run_mH400_nominal_makeNtuple.sh     -o $outZjetsCR/run_mH400_nominal_makeNtuple.out     -e $outZjetsCR/run_mH400_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ZjetsCR/run_mH500_nominal_makeNtuple.sh     -o $outZjetsCR/run_mH500_nominal_makeNtuple.out     -e $outZjetsCR/run_mH500_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ZjetsCR/run_diboson_nominal_makeNtuple.sh   -o $outZjetsCR/run_diboson_nominal_makeNtuple.out   -e $outZjetsCR/run_diboson_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ZjetsCR/run_ttV_nominal_makeNtuple.sh       -o $outZjetsCR/run_ttV_nominal_makeNtuple.out       -e $outZjetsCR/run_ttV_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ZjetsCR/run_tV_nominal_makeNtuple.sh        -o $outZjetsCR/run_tV_nominal_makeNtuple.out        -e $outZjetsCR/run_tV_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ZjetsCR/run_ttH_nominal_makeNtuple.sh       -o $outZjetsCR/run_ttH_nominal_makeNtuple.out       -e $outZjetsCR/run_ttH_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ZjetsCR/run_VVV_nominal_makeNtuple.sh       -o $outZjetsCR/run_VVV_nominal_makeNtuple.out       -e $outZjetsCR/run_VVV_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ZjetsCR/run_Vgam_nominal_makeNtuple.sh      -o $outZjetsCR/run_Vgam_nominal_makeNtuple.out      -e $outZjetsCR/run_Vgam_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ZjetsCR/run_Wjets_nominal_makeNtuple.sh     -o $outZjetsCR/run_Wjets_nominal_makeNtuple.out     -e $outZjetsCR/run_Wjets_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ZjetsCR/run_Zjets_nominal_makeNtuple.sh     -o $outZjetsCR/run_Zjets_nominal_makeNtuple.out     -e $outZjetsCR/run_Zjets_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ZjetsCR/run_DY_nominal_makeNtuple.sh     -o $outZjetsCR/run_DY_nominal_makeNtuple.out     -e $outZjetsCR/run_DY_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ZjetsCR/run_ttbar_nominal_makeNtuple.sh     -o $outZjetsCR/run_ttbar_nominal_makeNtuple.out     -e $outZjetsCR/run_ttbar_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ZjetsCR/run_WW_nominal_makeNtuple.sh        -o $outZjetsCR/run_WW_nominal_makeNtuple.out        -e $outZjetsCR/run_WW_nominal_makeNtuple.err 
