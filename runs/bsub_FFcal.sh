export CWD=/afs/ihep.ac.cn/users/z/zhoums/work/2LSSAna
export outtemp=/scratchfs/atlas/zhoums/2LSSAna_output/temp
#hep_sub "cd $CWD; ./bin/runFFcalculator datacombined FFcal_1jets"
#hep_sub "cd $CWD; ./bin/runFFcalculator diboson FFcal_1jets"
#hep_sub "cd $CWD; ./bin/runFFcalculator tV FFcal_1jets"
#hep_sub "cd $CWD; ./bin/runFFcalculator ttV FFcal_1jets"
#hep_sub "cd $CWD; ./bin/runFFcalculator ttH FFcal_1jets"
#hep_sub "cd $CWD; ./bin/runFFcalculator Vgam FFcal_1jets"
#
#hep_sub "cd $CWD; ./bin/runFFcalculator datacombined FFcal_QmisID_1jets"
#hep_sub "cd $CWD; ./bin/runFFcalculator Zjets FFcal_1jets"
#hep_sub "cd $CWD; ./bin/runFFcalculator DY FFcal_1jets"
#hep_sub "cd $CWD; ./bin/runFFcalculator ttbar FFcal_1jets"
#hep_sub "cd $CWD; ./bin/runFFcalculator WW FFcal_1jets"
#
#
#hep_sub "cd $CWD; ./bin/runFFcalculator datacombined FFcal_2jets"
#hep_sub "cd $CWD; ./bin/runFFcalculator diboson FFcal_2jets"
#hep_sub "cd $CWD; ./bin/runFFcalculator tV FFcal_2jets"
#hep_sub "cd $CWD; ./bin/runFFcalculator ttV FFcal_2jets"
#hep_sub "cd $CWD; ./bin/runFFcalculator ttH FFcal_2jets"
#hep_sub "cd $CWD; ./bin/runFFcalculator Vgam FFcal_2jets"
#
#hep_sub "cd $CWD; ./bin/runFFcalculator datacombined FFcal_QmisID_2jets"
#hep_sub "cd $CWD; ./bin/runFFcalculator Zjets FFcal_2jets"
#hep_sub "cd $CWD; ./bin/runFFcalculator DY FFcal_2jets"
#hep_sub "cd $CWD; ./bin/runFFcalculator ttbar FFcal_2jets"
#hep_sub "cd $CWD; ./bin/runFFcalculator WW FFcal_2jets"

#hep_sub $CWD/scripts/preselection/2jets/run_data_FFcal.sh -o $outtemp/run_data_FFcal_2jets.out -e $outtemp/run_data_FFcal_2jets.err
hep_sub $CWD/scripts/preselection/2jets/run_diboson_FFcal.sh -o $outtemp/run_diboson_FFcal_2jets.out -e $outtemp/run_diboson_FFcal_2jets.err
hep_sub $CWD/scripts/preselection/2jets/run_tV_FFcal.sh -o $outtemp/run_tV_FFcal_2jets.out -e $outtemp/run_tV_FFcal_2jets.err
hep_sub $CWD/scripts/preselection/2jets/run_ttV_FFcal.sh -o $outtemp/run_ttV_FFcal_2jets.out -e $outtemp/run_ttV_FFcal_2jets.err
hep_sub $CWD/scripts/preselection/2jets/run_ttH_FFcal.sh -o $outtemp/run_ttH_FFcal_2jets.out -e $outtemp/run_ttH_FFcal_2jets.err
hep_sub $CWD/scripts/preselection/2jets/run_Vgam_FFcal.sh -o $outtemp/run_Vgam_FFcal_2jets.out -e $outtemp/run_Vgam_FFcal_2jets.err
 
#hep_sub $CWD/scripts/preselection/2jets/run_QmisID_FFcal.sh -o $outtemp/run_QmisID_FFcal_2jets.out -e $outtemp/run_QmisID_FFcal_2jets.err
hep_sub $CWD/scripts/preselection/2jets/run_Zjets_FFcal.sh -o $outtemp/run_Zjets_FFcal_2jets.out -e $outtemp/run_Zjets_FFcal_2jets.err
hep_sub $CWD/scripts/preselection/2jets/run_DY_FFcal.sh -o $outtemp/run_DY_FFcal_2jets.out -e $outtemp/run_DY_FFcal_2jets.err
hep_sub $CWD/scripts/preselection/2jets/run_ttbar_FFcal.sh -o $outtemp/run_ttbar_FFcal_2jets.out -e $outtemp/run_ttbar_FFcal_2jets.err
hep_sub $CWD/scripts/preselection/2jets/run_WW_FFcal.sh -o $outtemp/run_WW_FFcal_2jets.out -e $outtemp/run_WW_FFcal_2jets.err

#hep_sub $CWD/scripts/preselection/3jets/run_data_FFcal.sh -o $outtemp/run_data_FFcal_3jets.out -e $outtemp/run_data_FFcal_3jets.err
hep_sub $CWD/scripts/preselection/3jets/run_diboson_FFcal.sh -o $outtemp/run_diboson_FFcal_3jets.out -e $outtemp/run_diboson_FFcal_3jets.err
hep_sub $CWD/scripts/preselection/3jets/run_tV_FFcal.sh -o $outtemp/run_tV_FFcal_3jets.out -e $outtemp/run_tV_FFcal_3jets.err
hep_sub $CWD/scripts/preselection/3jets/run_ttV_FFcal.sh -o $outtemp/run_ttV_FFcal_3jets.out -e $outtemp/run_ttV_FFcal_3jets.err
hep_sub $CWD/scripts/preselection/3jets/run_ttH_FFcal.sh -o $outtemp/run_ttH_FFcal_3jets.out -e $outtemp/run_ttH_FFcal_3jets.err
hep_sub $CWD/scripts/preselection/3jets/run_Vgam_FFcal.sh -o $outtemp/run_Vgam_FFcal_3jets.out -e $outtemp/run_Vgam_FFcal_3jets.err

#hep_sub $CWD/scripts/preselection/3jets/run_QmisID_FFcal.sh -o $outtemp/run_QmisID_FFcal_3jets.out -e $outtemp/run_QmisID_FFcal_3jets.err
hep_sub $CWD/scripts/preselection/3jets/run_Zjets_FFcal.sh -o $outtemp/run_Zjets_FFcal_3jets.out -e $outtemp/run_Zjets_FFcal_3jets.err
hep_sub $CWD/scripts/preselection/3jets/run_DY_FFcal.sh -o $outtemp/run_DY_FFcal_3jets.out -e $outtemp/run_DY_FFcal_3jets.err
hep_sub $CWD/scripts/preselection/3jets/run_ttbar_FFcal.sh -o $outtemp/run_ttbar_FFcal_3jets.out -e $outtemp/run_ttbar_FFcal_3jets.err
hep_sub $CWD/scripts/preselection/3jets/run_WW_FFcal.sh -o $outtemp/run_WW_FFcal_3jets.out -e $outtemp/run_WW_FFcal_3jets.err
