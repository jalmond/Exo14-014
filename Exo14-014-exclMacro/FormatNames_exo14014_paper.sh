if [[ -z emu_limits/LimitPlots$1 ]];
    then
    echo "Error in tag for version of plots: source FormatNames_exo14014_paper.sh <tag>"
    return
fi
    
paper_dir=jalmond@lxplus.cern.ch:~/POSTDOC/Documention/CMS/Paper/paper/papers/EXO-14-014/trunk/
rm emu_limits/LimitPlots/*
mv emu_limits/*.pdf emu_limits/LimitPlots/

cp -r emu_limits/LimitPlots/ emu_limits/LimitPlots$1
scp emu_limits/LimitPlots$1/*  $paper_dir



 

