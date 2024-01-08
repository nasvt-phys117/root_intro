void ph_simple()
{
    //TFile ff("histograms.root");

	TFile *ff = TFile::Open("histograms.root", "READ");

    TH1F *hh0 = (TH1F *)ff->Get("h_mn_px");
	TH1F *hh1 = (TH1F *)ff->Get("h_mn_py");
	TH1F *hh2 = (TH1F *)ff->Get("h_mn_pz");
	int input =0;
	if (ff)
	{
		TCanvas *c0 = new TCanvas();
		c0->Divide(3,1);
		c0->cd(1);
		hh0->Draw();

		c0->cd(2);
		hh1->Draw();

		c0->cd(3);
		hh2->Draw();
	}
}
