{
  const int nm = 16;

  float mass[nm] = {40, 50, 60, 70, 80, 90, 100, 125, 150, 175, 200, 250, 300, 350, 400, 500};
  float k_factor = 1.34;
  float xsec_alp[] = {1516, 1071.1, 607.7, 211.96, 19.07, 7.1047, 3.5618, 1.0767, 0.4594, 0.23266, 0.13127, 0.050928, 0.023214, 0.011705, 0.006332, 0.002154};
  
  float obs_mm[nm] = {0.0425758, 0.0370795, 0.0509001, 0.111657, 0.0262207, 0.0488669,
                   0.011495, 0.00263166, 0.00212999, 0.00260005, 0.00221507,
                   0.00140472, 0.00125629, 0.00118361, 0.00128623, 0.00152084};
    
  float obs_em[nm] = {0.269913, 0.228505, 0.279637, 0.771711, 0.171265, 0.163916, 0.0463834, 0.0140186, 0.00644153, 0.00476088, 0.00326979, 0.0028114, 0.0022835, 0.00224634, 0.00224528, 0.00262692};


  float obs_ee[nm] = {0.310856,0.228104,0.268764, 0.682266, 0.187104, 0.209065, 0.0521459, 0.0113648, 0.00491012, 0.00354478, 0.00278916, 0.00285184, 0.00252027, 0.00218728, 0.00201853, 0.00208477};




  for(int i=0;i<nm;i++) {
    obs_mm[i];
    obs_em[i];
    obs_ee[i];

  }


  TGraph* graphs[14];
  graphs[0] = new TGraph(nm, mass, obs_mm);
  graphs[1] = new TGraph(nm, mass, obs_ee);
  graphs[2] = new TGraph(nm, mass, obs_em);


  graphs[0]->SetNameTitle("observedmm", "observedmm");
  graphs[1]->SetNameTitle("observedee", "observedee");
  graphs[2]->SetNameTitle("observedem", "observedem");

  TColor::CreateColorWheel();
  graphs[0]->SetLineColor(kBlack);
  graphs[0]->SetLineStyle(9);
  graphs[1]->SetLineColor(kBlack);
  graphs[1]->SetMarkerStyle(20);
  graphs[1]->SetMarkerSize(1);
  graphs[1]->SetMarkerColor(kBlack);
  graphs[0]->SetLineColor(kCyan-4);
  graphs[1]->SetLineStyle(3);
  graphs[1]->SetLineColor(kPink);
  graphs[2]->SetLineStyle(6);
  graphs[2]->SetLineColor(kAzure);

  graphs[0]->SetLineWidth(3);
  graphs[1]->SetLineWidth(3);
  graphs[2]->SetLineWidth(3);

  graphs[0]->SetFillColor(kWhite);
  graphs[1]->SetFillColor(kWhite);
  graphs[2]->SetFillColor(kWhite);

    
  int W = 800;
  int H = 600;
  TCanvas* c1 = new TCanvas("c1", "c1",10,10,W,H);
  int H_ref = 600;
  int W_ref = 800;
    
  // references for T, B, L, R
  float T = 0.08*H_ref;
  float B = 0.15*H_ref;
  float L = 0.17*W_ref;
  float R = 0.04*W_ref;
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetFrameFillStyle(0);
  c1->SetFrameBorderMode(0);
  c1->SetLeftMargin( L/W );
  c1->SetRightMargin( R/W );
  c1->SetTopMargin( T/H );
  c1->SetBottomMargin( B/H );
  //  c1->SetGridx();
  //c1->SetGridy();
  c1->SetTickx(1);
  c1->SetTicky(1);
    
  gROOT->LoadMacro("tdrstyle.C");
  setTDRStyle();
    
  gROOT->LoadMacro("CMS_lumi.C");
 // CMS_lumi( c1, 2, 0 );


  TH1 *frame = new TH1F("frame","",1000,40,600);
  frame->SetMinimum(1e-5);
  frame->SetMaximum(10);
  frame->SetDirectory(0);
  frame->SetStats(0);
  frame->GetXaxis()->SetTitle("m_{N} (GeV)");
  frame->GetXaxis()->SetTitleSize(0.05);
  frame->GetXaxis()->SetTitleOffset(1.05);
  //frame->GetXaxis()->SetTickLength(0.02);
  //frame->GetXaxis()->SetLabelSize(0.04);
  frame->GetXaxis()->SetRangeUser(40, 500);
  frame->GetYaxis()->SetTitle("#sigma #times #bf{#it{#Beta}} (pb)");


  frame->GetYaxis()->SetTitleSize(0.05);
  //frame->GetYaxis()->SetTitleOffset(0.95);
  //frame->GetYaxis()->SetLabelSize(0.04);
  frame->GetYaxis()->SetRangeUser(0.0002,5.0);
  frame->Draw(" ");
  c1->SetLogy();

  graphs[0]->Draw("same");
  graphs[1]->Draw("same");
  graphs[2]->Draw("same");


  TLegend* leg = new TLegend(0.6, .20, .95, 0.5);
  leg->AddEntry(graphs[1], "Observed ee", "l");
  leg->AddEntry(graphs[2], "Observed e#mu", "l");
  leg->AddEntry(graphs[0], "Observed  #mu#mu", "l");

  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.03);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);

  
  leg->Draw();
  //TLatex title(70, 3, "#font[41]{CMS 2012 #sqrt{s} = 8 TeV #it{Ldt} = 19.7 fb^{-1}}");
  //title.Draw();
  TLatex title(210.3251,2., "#font[41]{95% CL upper limit}");
  title.SetTextSize(0.04);
  title.SetLineWidth(2);
  title.Draw();


  TLatex title2(210.3251,1., "#font[41]{pp #rightarrow N  l_{1}^{#pm}/l_{2}^{#pm} #rightarrow l_{1}^{#pm}l_{2}^{#pm} q#bar{q'}}");
  title2.SetTextSize(0.04);
  title2.SetLineWidth(2);
  title2.Draw();


  CMS_lumi( c1, 2, 11 );
  c1->Update();
  c1->RedrawAxis();
 // c1->GetFrame()->Draw();
  
  c1->SaveAs("excl_xsec_limit_combined.pdf");
}
