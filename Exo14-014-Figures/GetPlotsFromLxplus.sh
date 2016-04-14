###
###   Settings for Final Paper Plots  
###

####  make_png=True when plots are needed for twiki 
make_png=False


declare -a list_of_plots_lxplus=("c_h_e2jjmass" "c_h_eejjmass" "c_h_leadingElectronPt")
declare -a list_of_plots_paper=("h_l2jjmass" "h_lljjmass" "h_leadleppt")


ee_webplot_path_lowmass_pdf="HNDiElectron_unblinded_noteversion_pas_approval_twiki_final/histograms/LQMarch14/"
ee_webplot_path_lowmass_png=""
ee_webplot_path_highmass_pdf="HNDiElectron_ssplots_midmass_june_note_unblinded_noteversion_pas_approval_twiki_final/histograms/LQMarch14/"
ee_webplot_path_highmass_png=""

emu_webplot_path_lowmass_pdf="HNEMu_ssplots_presel_jan_combined_emusig_Aug_twiki_final/histograms/LQMarch14/"
emu_webplot_path_lowmass_png=""
emu_webplot_path_highmass_pdf="HNEMu_ssplots_presel_jan_combined_emusig_highmass_aug_app_twiki_final/histograms/LQMarch14/"
emu_webplot_path_highmass_png=""

declare -a list_of_cuts_paper=("low_mass" "medium_mass" "low_mass_em" "medium_mass_em")
declare -a list_of_cuts_lxplus=("LowMassRegion" "MediumMassRegion" "SS_lowmass" "SS_highmass1")
declare -a list_of_paths_paper=($ee_webplot_path_lowmass_pdf $ee_webplot_path_highmass_pdf $ee_webplot_path_lowmass_pdf $ee_webplot_path_highmass_pdf)


if [ ! -z pdf/ ]; then
    mkdir pdf
fi

if [ $make_png == "True" ];then
    if [ ! -z png/ ]; then
	mkdir png
	ee_webplot_path_lowmass_png=""
	ee_webplot_path_highmass_png=""
	emu_webplot_path_lowmass_png=""
	emu_webplot_path_highmass_png=""
	
    fi
fi
    

#############   EE channel low mass
declare -a  plot_format=("pdf")

if [ $make_png == "True" ];then
    plot_format+=("png")
fi

it_plot=0

for iplot in  ${list_of_plots_lxplus[@]};
  do
    ee_webplot_path=$ee_webplot_path_pdf
    for iformat in  ${plot_format[@]};
    do
	if [ $iformat == "png" ]; then
	    ee_webplot_path=$ee_webplot_path_png
	fi
	ncut=0
	for icut in  ${list_of_cuts_paper[@]};
	do
	    mkdir pdf/$icut
    	    cuttag=""
	    if [[ $icut == "low_mass_em" ]]; then
		cuttag="_em"
	    elif [[ $icut == "low_mass" ]]; then
		cuttag="_ee"
	    elif [[ $icut == "medium_mass_em" ]]; then
		cuttag="_em"
	    else 
		cuttag="_ee"
	    fi
	    scp  pdf/$list_of_plots_paper[it_plot]$cuttag.${iformat} $paper_path/$icut"/"
	    curl -o ${list_of_plots_paper[it_plot]}$cuttag.${iformat} https://jalmond.web.cern.ch/jalmond/SNU/WebPlots/${ee_webplot_path}/${iplot}_${list_of_cuts_lxplus[ncut]}.${iformat}
	    mv ${list_of_plots_paper[it_plot]}$cuttag.${iformat}    pdf/$icut/${list_of_plots_paper[it_plot]}$cuttag.${iformat}  
	    echo "  mv ${list_of_plots_paper[it_plot]}$cuttag.${iformat}    pdf/$icut/${list_of_plots_paper[it_plot]}$cuttag.${iformat}"


	    ncut=$((ncut+1))
	    echo $ncut
	done
    done
    it_plot=$((it_plot+1))
    echo "SSS "$it_plot
done

