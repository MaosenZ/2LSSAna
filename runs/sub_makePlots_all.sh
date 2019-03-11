export outputdir=/scratchfs/atlas/zhoums/2LSSAna_output/output
hep_sub sub_makePlots_mH260.sh -o $outputdir/makePlots_mH260.out -e $outputdir/makePlots_mH260.err
hep_sub sub_makePlots_mH300.sh -o $outputdir/makePlots_mH300.out -e $outputdir/makePlots_mH300.err
hep_sub sub_makePlots_mH400.sh -o $outputdir/makePlots_mH400.out -e $outputdir/makePlots_mH400.err
hep_sub sub_makePlots_mH500.sh -o $outputdir/makePlots_mH500.out -e $outputdir/makePlots_mH500.err
hep_sub sub_makePlots_nonres.sh -o $outputdir/makePlots_nonres.out -e $outputdir/makePlots_nonres.err

hep_sub sub_makePlots_H280_S135.sh -o $outputdir/makePlots_H280_S135.out -e $outputdir/makePlots_H280_S135.err
hep_sub sub_makePlots_H300_S135.sh -o $outputdir/makePlots_H300_S135.out -e $outputdir/makePlots_H300_S135.err
hep_sub sub_makePlots_H320_S135.sh -o $outputdir/makePlots_H320_S135.out -e $outputdir/makePlots_H320_S135.err
hep_sub sub_makePlots_H340_S135.sh -o $outputdir/makePlots_H340_S135.out -e $outputdir/makePlots_H340_S135.err
hep_sub sub_makePlots_H340_S145.sh -o $outputdir/makePlots_H340_S145.out -e $outputdir/makePlots_H340_S145.err
hep_sub sub_makePlots_H340_S155.sh -o $outputdir/makePlots_H340_S155.out -e $outputdir/makePlots_H340_S155.err
hep_sub sub_makePlots_H340_S165.sh -o $outputdir/makePlots_H340_S165.out -e $outputdir/makePlots_H340_S165.err
