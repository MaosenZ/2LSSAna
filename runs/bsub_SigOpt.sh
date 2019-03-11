export CWD=/afs/ihep.ac.cn/users/z/zhoums/work/2LSSAna
export out=/scratchfs/atlas/zhoums/2LSSAna_output/output

hep_sub $CWD/scripts/SigOpt/HSS_SigOpt.sh -o $out/SigOpt/HSS_SigOpt.out -e $out/SigOpt/HSS_SigOpt.err
