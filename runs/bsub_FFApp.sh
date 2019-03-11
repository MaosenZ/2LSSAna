export CWD=/afs/ihep.ac.cn/users/z/zhoums/work/2LSSAna
export outtemp=/scratchfs/atlas/zhoums/2LSSAna_output/temp

hep_sub $CWD/scripts/preselection/2jets/run_data_FFApp.sh   -o $outtemp/run_data_FFApp.out_2jets   -e $outtemp/run_data_FFApp.err_2jets
hep_sub $CWD/scripts/preselection/2jets/run_diboson_FFApp.sh   -o $outtemp/run_diboson_FFApp.out_2jets   -e $outtemp/run_diboson_FFApp.err_2jets 
hep_sub $CWD/scripts/preselection/2jets/run_ttV_FFApp.sh       -o $outtemp/run_ttV_FFApp.out_2jets       -e $outtemp/run_ttV_FFApp.err_2jets 
hep_sub $CWD/scripts/preselection/2jets/run_tV_FFApp.sh        -o $outtemp/run_tV_FFApp.out_2jets        -e $outtemp/run_tV_FFApp.err_2jets 
hep_sub $CWD/scripts/preselection/2jets/run_ttH_FFApp.sh       -o $outtemp/run_ttH_FFApp.out_2jets       -e $outtemp/run_ttH_FFApp.err_2jets 
hep_sub $CWD/scripts/preselection/2jets/run_VVV_FFApp.sh       -o $outtemp/run_VVV_FFApp.out_2jets       -e $outtemp/run_VVV_FFApp.err_2jets 
hep_sub $CWD/scripts/preselection/2jets/run_Vgam_FFApp.sh      -o $outtemp/run_Vgam_FFApp.out_2jets      -e $outtemp/run_Vgam_FFApp.err_2jets 
hep_sub $CWD/scripts/preselection/2jets/run_Wjets_FFApp.sh     -o $outtemp/run_Wjets_FFApp.out_2jets     -e $outtemp/run_Wjets_FFApp.err_2jets 
hep_sub $CWD/scripts/preselection/2jets/run_Zjets_FFApp.sh     -o $outtemp/run_Zjets_FFApp.out_2jets     -e $outtemp/run_Zjets_FFApp.err_2jets 
hep_sub $CWD/scripts/preselection/2jets/run_DY_FFApp.sh     -o $outtemp/run_DY_FFApp.out_2jets     -e $outtemp/run_DY_FFApp.err_2jets 
hep_sub $CWD/scripts/preselection/2jets/run_ttbar_FFApp.sh     -o $outtemp/run_ttbar_FFApp.out_2jets     -e $outtemp/run_ttbar_FFApp.err_2jets 
hep_sub $CWD/scripts/preselection/2jets/run_WW_FFApp.sh        -o $outtemp/run_WW_FFApp.out_2jets        -e $outtemp/run_WW_FFApp.err_2jets 
hep_sub $CWD/scripts/preselection/2jets/run_QmisID_FFApp.sh -o $outtemp/run_QmisID_FFApp.out_2jets -e $outtemp/run_QmisID_FFApp.err_2jets
hep_sub $CWD/scripts/preselection/2jets/run_data_FFQmis.sh -o $outtemp/run_data_FFQmis.out_2jets -e $outtemp/run_data_FFQmis.err_2jets

hep_sub $CWD/scripts/preselection/3jets/run_data_FFApp.sh   -o $outtemp/run_data_FFApp.out_3jets   -e $outtemp/run_data_FFApp.err_3jets
hep_sub $CWD/scripts/preselection/3jets/run_diboson_FFApp.sh   -o $outtemp/run_diboson_FFApp.out_3jets   -e $outtemp/run_diboson_FFApp.err_3jets
hep_sub $CWD/scripts/preselection/3jets/run_ttV_FFApp.sh       -o $outtemp/run_ttV_FFApp.out_3jets       -e $outtemp/run_ttV_FFApp.err_3jets
hep_sub $CWD/scripts/preselection/3jets/run_tV_FFApp.sh        -o $outtemp/run_tV_FFApp.out_3jets        -e $outtemp/run_tV_FFApp.err_3jets
hep_sub $CWD/scripts/preselection/3jets/run_ttH_FFApp.sh       -o $outtemp/run_ttH_FFApp.out_3jets       -e $outtemp/run_ttH_FFApp.err_3jets
hep_sub $CWD/scripts/preselection/3jets/run_VVV_FFApp.sh       -o $outtemp/run_VVV_FFApp.out_3jets       -e $outtemp/run_VVV_FFApp.err_3jets
hep_sub $CWD/scripts/preselection/3jets/run_Vgam_FFApp.sh      -o $outtemp/run_Vgam_FFApp.out_3jets      -e $outtemp/run_Vgam_FFApp.err_3jets
hep_sub $CWD/scripts/preselection/3jets/run_Wjets_FFApp.sh     -o $outtemp/run_Wjets_FFApp.out_3jets     -e $outtemp/run_Wjets_FFApp.err_3jets
hep_sub $CWD/scripts/preselection/3jets/run_Zjets_FFApp.sh     -o $outtemp/run_Zjets_FFApp.out_3jets     -e $outtemp/run_Zjets_FFApp.err_3jets
hep_sub $CWD/scripts/preselection/3jets/run_DY_FFApp.sh     -o $outtemp/run_DY_FFApp.out_3jets     -e $outtemp/run_DY_FFApp.err_3jets
hep_sub $CWD/scripts/preselection/3jets/run_ttbar_FFApp.sh     -o $outtemp/run_ttbar_FFApp.out_3jets     -e $outtemp/run_ttbar_FFApp.err_3jets
hep_sub $CWD/scripts/preselection/3jets/run_WW_FFApp.sh        -o $outtemp/run_WW_FFApp.out_3jets        -e $outtemp/run_WW_FFApp.err_3jets
hep_sub $CWD/scripts/preselection/3jets/run_QmisID_FFApp.sh -o $outtemp/run_QmisID_FFApp.out_3jets -e $outtemp/run_QmisID_FFApp.err_3jets
hep_sub $CWD/scripts/preselection/3jets/run_data_FFQmis.sh -o $outtemp/run_data_FFQmis.out_3jets -e $outtemp/run_data_FFQmis.err_3jets
