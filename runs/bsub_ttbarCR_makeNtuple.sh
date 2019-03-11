export CWD=/afs/ihep.ac.cn/users/z/zhoums/work/2LSSAna
export outttbarCR=/scratchfs/atlas/zhoums/2LSSAna_output/output/ttbarCR/

hep_sub  $CWD/scripts/ttbarCR/run_data_nominal_makeNtuple.sh -o $outttbarCR/run_data_nominal_makeNtuple.out -e $outttbarCR/run_data_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ttbarCR/run_nonres_nominal_makeNtuple.sh -o $outttbarCR/run_nonres_nominal_makeNtuple.out -e $outttbarCR/run_nonres_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ttbarCR/run_mH260_nominal_makeNtuple.sh     -o $outttbarCR/run_mH260_nominal_makeNtuple.out     -e $outttbarCR/run_mH260_nominal_makeNtuple.err    
hep_sub $CWD/scripts/ttbarCR/run_mH300_nominal_makeNtuple.sh     -o $outttbarCR/run_mH300_nominal_makeNtuple.out     -e $outttbarCR/run_mH300_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ttbarCR/run_mH400_nominal_makeNtuple.sh     -o $outttbarCR/run_mH400_nominal_makeNtuple.out     -e $outttbarCR/run_mH400_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ttbarCR/run_mH500_nominal_makeNtuple.sh     -o $outttbarCR/run_mH500_nominal_makeNtuple.out     -e $outttbarCR/run_mH500_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ttbarCR/run_diboson_nominal_makeNtuple.sh   -o $outttbarCR/run_diboson_nominal_makeNtuple.out   -e $outttbarCR/run_diboson_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ttbarCR/run_ttV_nominal_makeNtuple.sh       -o $outttbarCR/run_ttV_nominal_makeNtuple.out       -e $outttbarCR/run_ttV_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ttbarCR/run_tV_nominal_makeNtuple.sh        -o $outttbarCR/run_tV_nominal_makeNtuple.out        -e $outttbarCR/run_tV_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ttbarCR/run_ttH_nominal_makeNtuple.sh       -o $outttbarCR/run_ttH_nominal_makeNtuple.out       -e $outttbarCR/run_ttH_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ttbarCR/run_VVV_nominal_makeNtuple.sh       -o $outttbarCR/run_VVV_nominal_makeNtuple.out       -e $outttbarCR/run_VVV_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ttbarCR/run_Vgam_nominal_makeNtuple.sh      -o $outttbarCR/run_Vgam_nominal_makeNtuple.out      -e $outttbarCR/run_Vgam_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ttbarCR/run_Wjets_nominal_makeNtuple.sh     -o $outttbarCR/run_Wjets_nominal_makeNtuple.out     -e $outttbarCR/run_Wjets_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ttbarCR/run_Zjets_nominal_makeNtuple.sh     -o $outttbarCR/run_Zjets_nominal_makeNtuple.out     -e $outttbarCR/run_Zjets_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ttbarCR/run_DY_nominal_makeNtuple.sh     -o $outttbarCR/run_DY_nominal_makeNtuple.out     -e $outttbarCR/run_DY_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ttbarCR/run_ttbar_nominal_makeNtuple.sh     -o $outttbarCR/run_ttbar_nominal_makeNtuple.out     -e $outttbarCR/run_ttbar_nominal_makeNtuple.err 
hep_sub $CWD/scripts/ttbarCR/run_WW_nominal_makeNtuple.sh        -o $outttbarCR/run_WW_nominal_makeNtuple.out        -e $outttbarCR/run_WW_nominal_makeNtuple.err 
