if [[ -z ee_limits_withLEP2/LimitPlots$1 ]];
    then
    echo "Error in tag for version of plots: source FormatNames_exo14014_paper.sh <tag>"
    return
fi
    
paper_dir=jalmond@lxplus.cern.ch:~/POSTDOC/Documention/CMS/Paper/paper/papers/EXO-14-014/trunk/
rm ee_limits_withLEP2/LimitPlots/*
mv ee_limits_withLEP2/*.pdf ee_limits_withLEP2/LimitPlots/

cp -r ee_limits_withLEP2/LimitPlots/ ee_limits_withLEP2/LimitPlots$1
scp ee_limits_withLEP2/LimitPlots$1/*  $paper_dir



 

