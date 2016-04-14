{
  const int nm = 16;

  float mass[nm] = {40, 50, 60, 70, 80, 90, 100, 125, 150, 175, 200, 250, 300, 350, 400, 500};
  float k_factor = 1.34;
  float xsec_alp[] = {1516, 1071.1, 607.7, 211.96, 19.07, 7.1047, 3.5618, 1.0767, 0.4594, 0.23266, 0.13127, 0.050928, 0.023214, 0.011705, 0.006332, 0.002154};
  

  float exp_mm[nm] = {0.0574156, 0.0529912, 0.0694351, 0.175697, 0.0380223, 0.0555941,
                      0.0123044, 0.00419174, 0.00276877, 0.00225111, 0.00191277,
                      0.00132662, 0.00124522, 0.0011111, 0.0012705, 0.00143492};



  float exp_em[nm] = {0.270911, 0.229688, 0.278787, 0.771095, 0.147626, 0.133925, 0.0327043, 0.00959089, 0.00551888, 0.00407575, 0.00279852, 0.00222304, 0.00154023, 0.00146327, 0.00143876, 0.0016471};


  float exp_ee[nm] = {0.238636,0.171337,0.204524,0.525581,0.142802,0.15618,0.0365141,0.0110612,0.00617064,0.004475,0.00355606,0.00283105,0.00215555,0.00175336,0.00163501,0.00168907};







  for(int i=0;i<nm;i++) {
    exp_mm[i] /= (xsec_alp[i]*k_factor);
    exp_em[i] /= (xsec_alp[i]*k_factor*2.);
    exp_ee[i] /= (xsec_alp[i]*k_factor);

  }


  TGraph* graphs[14];
  graphs[0] = new TGraph(nm, mass, exp_mm);
  graphs[1] = new TGraph(nm, mass, exp_ee);
  graphs[2] = new TGraph(nm, mass, exp_em);


  graphs[0]->SetNameTitle("expervedmm", "expervedmm");
  graphs[1]->SetNameTitle("expervedee", "expervedee");
  graphs[2]->SetNameTitle("expervedem", "expervedem");

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
  frame->GetYaxis()->SetTitle("Mixing");

  frame->GetYaxis()->SetTitleSize(0.05);
  //frame->GetYaxis()->SetTitleOffset(0.95);
  //frame->GetYaxis()->SetLabelSize(0.04);
  frame->GetYaxis()->SetRangeUser(0.00001,1.0);
  frame->Draw(" ");
  c1->SetLogy();

  graphs[0]->Draw("same");
  graphs[1]->Draw("same");
  graphs[2]->Draw("same");


  TLegend* leg = new TLegend(0.6, .20, .95, 0.5);
  leg->AddEntry(graphs[1], "Expected  #||{V_{eN}}^{2}", "l");
  leg->AddEntry(graphs[2], "Expected  #frac{#||{V_{eN}V*_{#muN}}^{2}}{#||{V_{eN}}^{2} + #||{V_{#muN}}^{2}}", "l");
  leg->AddEntry(graphs[0], "Expected  #||{V_{#muN}}^{2}", "l");

  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.03);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);

  
  leg->Draw();


  TLatex title(320.3251,0.005, "#font[41]{95% CL upper limit}");
  title.SetTextSize(0.04);
  title.SetLineWidth(2);
  title.Draw();
  //TLatex title(70, 3, "#font[41]{CMS 2012 #sqrt{s} = 8 TeV #it{Ldt} = 19.7 fb^{-1}}");
  //title.Draw();
  CMS_lumi( c1, 2, 11 );
  c1->Update();
  c1->RedrawAxis();
 // c1->GetFrame()->Draw();
  
  c1->SaveAs("excl_explimit_combined.pdf");
}
