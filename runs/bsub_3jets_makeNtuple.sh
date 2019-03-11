export CWD=/afs/ihep.ac.cn/users/z/zhoums/work/2LSSAna
export outpresel_2jets=/scratchfs/atlas/zhoums/2LSSAna_output/output/preselection/2jets

hep_sub  $CWD/scripts/preselection/2jets/run_data_nominal_makeNtuple.sh -o $outpresel_2jets/run_data_nominal_makeNtuple.out -e $outpresel_2jets/run_data_nominal_makeNtuple.err 
hep_sub $CWD/scripts/preselection/2jets/run_nonres_nominal_makeNtuple.sh -o $outpresel_2jets/run_nonres_nominal_makeNtuple.out -e $outpresel_2jets/run_nonres_nominal_makeNtuple.err
hep_sub $CWD/scripts/preselection/2jets/run_mH260_nominal_makeNtuple.sh -o $outpresel_2jets/run_mH260_nominal_makeNtuple.out -e $outpresel_2jets/run_mH260_nominal_makeNtuple.err
hep_sub $CWD/scripts/preselection/2jets/run_mH300_nominal_makeNtuple.sh      -o $outpresel_2jets/run_mH300_nominal_makeNtuple.out -e $outpresel_2jets/run_mH300_nominal_makeNtuple.err
hep_sub $CWD/scripts/preselection/2jets/run_mH400_nominal_makeNtuple.sh      -o $outpresel_2jets/run_mH400_nominal_makeNtuple.out     -e $outpresel_2jets/run_mH400_nominal_makeNtuple.err
hep_sub $CWD/scripts/preselection/2jets/run_mH500_nominal_makeNtuple.sh      -o $outpresel_2jets/run_mH500_nominal_makeNtuple.out     -e $outpresel_2jets/run_mH500_nominal_makeNtuple.err
hep_sub $CWD/scripts/preselection/2jets/run_diboson_nominal_makeNtuple.sh    -o $outpresel_2jets/run_diboson_nominal_makeNtuple.out   -e $outpresel_2jets/run_diboson_nominal_makeNtuple.err 
hep_sub $CWD/scripts/preselection/2jets/run_ttV_nominal_makeNtuple.sh        -o $outpresel_2jets/run_ttV_nominal_makeNtuple.out       -e $outpresel_2jets/run_ttV_nominal_makeNtuple.err
hep_sub $CWD/scripts/preselection/2jets/run_tV_nominal_makeNtuple.sh         -o $outpresel_2jets/run_tV_nominal_makeNtuple.out        -e $outpresel_2jets/run_tV_nominal_makeNtuple.err
hep_sub $CWD/scripts/preselection/2jets/run_ttH_nominal_makeNtuple.sh        -o $outpresel_2jets/run_ttH_nominal_makeNtuple.out       -e $outpresel_2jets/run_ttH_nominal_makeNtuple.err
hep_sub $CWD/scripts/preselection/2jets/run_VVV_nominal_makeNtuple.sh        -o $outpresel_2jets/run_VVV_nominal_makeNtuple.out       -e $outpresel_2jets/run_VVV_nominal_makeNtuple.err
hep_sub $CWD/scripts/preselection/2jets/run_Vgam_nominal_makeNtuple.sh       -o $outpresel_2jets/run_Vgam_nominal_makeNtuple.out      -e $outpresel_2jets/run_Vgam_nominal_makeNtuple.err
 
hep_sub  $CWD/scripts/preselection/2jets/run_QmisID_makeNtuple.sh            -o $outpresel_2jets/run_QmisID_makeNtuple.out            -e $outpresel_2jets/run_QmisID_makeNtuple.err
hep_sub  $CWD/scripts/preselection/2jets/run_FFQmis_makeNtuple.sh            -o $outpresel_2jets/run_FFQmis_makeNtuple.out            -e $outpresel_2jets/run_FFQmis_makeNtuple.err
#
hep_sub  $CWD/scripts/preselection/2jets/run_data_FFApp_makeNtuple.sh        -o $outpresel_2jets/run_data_FFApp_makeNtuple.out        -e $outpresel_2jets/run_data_FFApp_makeNtuple.err
hep_sub $CWD/scripts/preselection/2jets/run_diboson_FFApp_makeNtuple.sh      -o $outpresel_2jets/run_diboson_FFApp_makeNtuple.out     -e $outpresel_2jets/run_diboson_FFApp_makeNtuple.err
hep_sub $CWD/scripts/preselection/2jets/run_ttV_FFApp_makeNtuple.sh          -o $outpresel_2jets/run_ttV_FFApp_makeNtuple.out         -e $outpresel_2jets/run_ttV_FFApp_makeNtuple.err
hep_sub $CWD/scripts/preselection/2jets/run_tV_FFApp_makeNtuple.sh           -o $outpresel_2jets/run_tV_FFApp_makeNtuple.out          -e $outpresel_2jets/run_tV_FFApp_makeNtuple.err
hep_sub $CWD/scripts/preselection/2jets/run_ttH_FFApp_makeNtuple.sh          -o $outpresel_2jets/run_ttH_FFApp_makeNtuple.out         -e $outpresel_2jets/run_ttH_FFApp_makeNtuple.err
hep_sub $CWD/scripts/preselection/2jets/run_VVV_FFApp_makeNtuple.sh          -o $outpresel_2jets/run_VVV_FFApp_makeNtuple.out         -e $outpresel_2jets/run_VVV_FFApp_makeNtuple.err
hep_sub $CWD/scripts/preselection/2jets/run_Vgam_FFApp_makeNtuple.sh         -o $outpresel_2jets/run_Vgam_FFApp_makeNtuple.out        -e $outpresel_2jets/run_Vgam_FFApp_makeNtuple.err
hep_sub  $CWD/scripts/preselection/2jets/run_Zjets_FFApp_makeNtuple.sh       -o $outpresel_2jets/run_Zjets_FFApp_makeNtuple.out      -e $outpresel_2jets/run_Zjets_FFApp_makeNtuple.err
hep_sub $CWD/scripts/preselection/2jets/run_ttbar_FFApp_makeNtuple.sh        -o $outpresel_2jets/run_ttbar_FFApp_makeNtuple.out       -e $outpresel_2jets/run_ttbar_FFApp_makeNtuple.err
hep_sub $CWD/scripts/preselection/2jets/run_DY_FFApp_makeNtuple.sh           -o $outpresel_2jets/run_DY_FFApp_makeNtuple.out          -e $outpresel_2jets/run_DY_FFApp_makeNtuple.err
hep_sub $CWD/scripts/preselection/2jets/run_WW_FFApp_makeNtuple.sh           -o $outpresel_2jets/run_WW_FFApp_makeNtuple.out          -e $outpresel_2jets/run_WW_FFApp_makeNtuple.err
