#include <cstdlib>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <typeinfo>

#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TSystem.h"
#include "TObject.h"
#include "TTimeStamp.h"
#include "TLeaf.h"
#include "TH1.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TMath.h"
#include "TEfficiency.h"

#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TArrow.h"
#include "TLatex.h"
#include "TRandom.h"
#include "TPaveText.h"

#include "TApplication.h"

#include "TKey.h"
#include "TBranchRef.h"
#include "TMemFile.h"

#include "tabulate.hpp"

using namespace std;


Long64_t GetTotalSize(TBranch *b, bool ondisk, bool inclusive);
Long64_t GetBasketSize(TBranch *b, bool ondisk, bool inclusive);
Long64_t sizeOnDisk(TBranch *branch, bool inclusive);
Long64_t sizeOnDisk(TTree *t);

float get_block_size(string prfix, TTree *ttree);

int get_block_size_per_event(string prfix, TTree *ttree, int num_of_events);
string get_highest_consumer(string prfix, TTree * ttree);

int main(int argc, char *argv[])
{
    string in_file_name = argv[1];

    TFile *ff = TFile::Open(in_file_name.c_str(), "READ");

    cout << "Opened " << in_file_name << endl;

    TTree *tt = (TTree *)ff->Get("mainNtuplizer/data;1");
    int num_of_events = tt->GetEntries();

    stringstream st_size;
    st_size << fixed << setprecision(2) << sizeOnDisk(tt)/1024.0/1024.0;

    string s_size;
    s_size = st_size.str();

    // Table constructor
    tabulate::Table size_table;
    size_table.format().font_align(tabulate::FontAlign::center);

    size_table.add_row({ " -- ",in_file_name, " -- "});
    size_table.add_row({"TTree data;1" , "Size: " + s_size + "MB", "Number of Evts: " + to_string(num_of_events) });

    size_table.add_row({"Block", "Size in MB", "Size/Evt in B"});
    //cout << "The TTree \"" << tt->GetName() << "\" is " << sizeOnDisk(tt) / 1024.0 << " kB.\n";

    // The prefix of the required branches. We can add more later.
    
    int size_of_arr = 8;
    string prefix[size_of_arr] = {"en", "mn", "jet", "mc","fjet","sv", "met", "imet"};


    for (int i = 0; i < size_of_arr; i++)
    {
        stringstream st1;
        st1 << fixed << setprecision(2) << get_block_size(prefix[i],tt);

        string s1;
        s1 = st1.str(); 
        size_table.add_row({prefix[i], s1, to_string(get_block_size_per_event(prefix[i],tt, num_of_events))});

        get_highest_consumer(prefix[i], tt);
    }

    //Export to MD
    tabulate::MarkdownExporter exporter;
    auto markdown1 = exporter.dump(size_table);
    //create a file
    ofstream size_of_br("size.md");

    //print table contents
    cout << size_table << endl;
    size_of_br << markdown1 << endl;
    

    for (int i = 0; i < size_of_arr; i++)
    {
        get_highest_consumer(prefix[i], tt);
    }

    tabulate::Table h_consumer;
    h_consumer.format().font_align(tabulate::FontAlign::center);

    h_consumer.add_row({" ", " Highest consumers "});
    for (int i = 0; i < size_of_arr; i++)
    {   
        h_consumer.add_row({prefix[i],get_highest_consumer(prefix[i],tt) });
    }
    cout << h_consumer<< endl;

    auto markdown2 = exporter.dump(h_consumer);

    size_of_br << markdown2 << endl;

    size_of_br.close();
    return 0;
}

string get_highest_consumer(string prfix, TTree *ttree)
{
    string return_str;
    size_t num_of_entries = ttree->GetListOfBranches()->GetEntries(); //num of branches in tree

    int str_len = prfix.length();
    vector< pair< int , string> > lst_branches_sizes;
    
    for (size_t j = 0; j < num_of_entries; j++)
    {
        TBranch *br = dynamic_cast<TBranch *>(ttree->GetListOfBranches()->At(j));
        string name_of_branch = br->GetName();
    
        if (name_of_branch.substr(0, str_len) == prfix)
        {
            lst_branches_sizes.push_back(pair(sizeOnDisk(br, true)/1024,name_of_branch ));
        }
    }

    sort(lst_branches_sizes.rbegin(), lst_branches_sizes.rend());
    if ( lst_branches_sizes.size() >= 4)
    {
        for (size_t j = 0; j < 4; j++)
        {
            return_str += lst_branches_sizes[j].second+ " - " + to_string(lst_branches_sizes[j].first) + " kB" + "\n";
        }
    }
    else
    {
        for (size_t j = 0; j < lst_branches_sizes.size(); j++)
        {
            return_str += lst_branches_sizes[j].second+ " - " + to_string(lst_branches_sizes[j].first) + " kB" + "\n";
        }
    }
    return return_str;
}

float get_block_size(string prfix, TTree *ttree)
{
    size_t num_of_entries = ttree->GetListOfBranches()->GetEntries(); //num of branches in tree
    
    Long64_t size_of_block = 0;

    int str_len = prfix.length();

    for (size_t i = 0; i < num_of_entries; i++)
    {
        TBranch *br = dynamic_cast<TBranch *>(ttree->GetListOfBranches()->At(i));
        string name_of_branch = br->GetName();

        if (name_of_branch.substr(0, str_len) == prfix)
        {
            size_of_block += sizeOnDisk(br, true);
        }
    }
    float size_of_block_in_MB = size_of_block/1024.0/1024.0;

    return size_of_block_in_MB;
}

int get_block_size_per_event(string prfix, TTree *ttree, int num_of_events)
{
    size_t num_of_entries = ttree->GetListOfBranches()->GetEntries();
    Long64_t size_of_block_per_event = 0;

    int str_len = prfix.length();

    for (size_t i = 0; i < num_of_entries; i++)
    {
        TBranch *br = dynamic_cast<TBranch *>(ttree->GetListOfBranches()->At(i));
        string name_of_branch = br->GetName();

        int num_of_events = br->GetEntries();

        if (name_of_branch.substr(0, str_len) == prfix)
        {
            size_of_block_per_event += sizeOnDisk(br, true);
        }
    }
    int size_of_block_per_event_in_B = size_of_block_per_event/num_of_events;

    return size_of_block_per_event_in_B;
}


Long64_t GetBasketSize(TObjArray *branches, bool ondisk, bool inclusive)
{
    Long64_t result = 0;
    size_t n = branches->GetEntries();
    for (size_t i = 0; i < n; ++i)
    {
        result += GetBasketSize(dynamic_cast<TBranch *>(branches->At(i)), ondisk, inclusive);
    }
    return result;
}

Long64_t GetBasketSize(TBranch *b, bool ondisk, bool inclusive)
{
    Long64_t result = 0;
    if (b)
    {
        if (ondisk && b->GetZipBytes() > 0)
        {
            result = b->GetZipBytes();
        }
        else
        {
            result = b->GetTotBytes();
        }
        if (inclusive)
        {
            result += GetBasketSize(b->GetListOfBranches(), ondisk, true);
        }
        return result;
    }
    return result;
}

Long64_t GetTotalSize(TBranch *br, bool ondisk, bool inclusive)
{
    TMemFile f("buffer", "CREATE");
    if (br->GetTree()->GetCurrentFile())
    {
        f.SetCompressionSettings(br->GetTree()->GetCurrentFile()->GetCompressionSettings());
    }
    f.WriteObject(br, "thisbranch");
    TKey *key = f.GetKey("thisbranch");
    Long64_t size;
    if (ondisk)
        size = key->GetNbytes();
    else
        size = key->GetObjlen();
    return GetBasketSize(br, ondisk, inclusive) + size;
}

Long64_t GetTotalSize(TObjArray *branches, bool ondisk)
{
    Long64_t result = 0;
    size_t n = branches->GetEntries();
    for (size_t i = 0; i < n; ++i)
    {
        result += GetTotalSize(dynamic_cast<TBranch *>(branches->At(i)), ondisk, true);
        cerr << "After " << branches->At(i)->GetName() << " " << result << endl;
    }
    return result;
}

Long64_t GetTotalSize(TTree *t, bool ondisk)
{
    TKey *key = 0;
    if (t->GetDirectory())
    {
        key = t->GetDirectory()->GetKey(t->GetName());
    }
    Long64_t ondiskSize = 0;
    Long64_t totalSize = 0;
    if (key)
    {
        ondiskSize = key->GetNbytes();
        totalSize = key->GetObjlen();
    }
    else
    {
        TMemFile f("buffer", "CREATE");
        if (t->GetCurrentFile())
        {
            f.SetCompressionSettings(t->GetCurrentFile()->GetCompressionSettings());
        }
        f.WriteTObject(t);
        key = f.GetKey(t->GetName());
        ondiskSize = key->GetNbytes();
        totalSize = key->GetObjlen();
    }
    if (t->GetBranchRef())
    {
        if (ondisk)
        {
            ondiskSize += GetBasketSize(t->GetBranchRef(), true, true);
        }
        else
        {
            totalSize += GetBasketSize(t->GetBranchRef(), false, true);
        }
    }
    if (ondisk)
    {
        return ondiskSize + GetBasketSize(t->GetListOfBranches(), /* ondisk */ true, /* inclusive */ true);
    }
    else
    {
        return totalSize + GetBasketSize(t->GetListOfBranches(), /* ondisk */ false, /* inclusive */ true);
    }
}

Long64_t sizeOnDisk(TTree *t)
{
    // Return the size on disk on this TTree.

    return GetTotalSize(t, true);
}

Long64_t sizeOnDisk(TBranch *branch, bool inclusive)
{
    // Return the size on disk on this branch.
    // If 'inclusive' is true, include also the size
    // of all its sub-branches.

    return GetTotalSize(branch, true, inclusive);
}
