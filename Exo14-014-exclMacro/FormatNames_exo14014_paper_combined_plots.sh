if [[ -z combined_limits/CombinedLimitPlots$1 ]];
    then
    echo "Error in tag for version of plots: source FormatNames_exo14014_paper.sh <tag>"
    return
fi
    
paper_dir=jalmond@lxplus.cern.ch:~/POSTDOC/Documention/CMS/Paper/paper/papers/EXO-14-014/trunk/
rm combined_limits/CombinedLimitPlots/*
mv combined_limits/excl_limit_combined.pdf combined_limits/CombinedLimitPlots/limit_comparison.pdf
mv combined_limits/excl_xsec_limit_combined.pdf combined_limits/CombinedLimitPlots/xs_limit_comparison.pdf

cp -r combined_limits/CombinedLimitPlots/ combined_limits/CombinedLimitPlots$1
scp -r combined_limits/CombinedLimitPlots$1/limit_comparison.pdf $paper_dir
scp -r combined_limits/CombinedLimitPlots$1/xs_limit_comparison.pdf $paper_dir


 

