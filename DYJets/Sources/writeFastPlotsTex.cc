#include <iostream>
#include <fstream>
#include <sstream>
#include "writeFastPlotsTex.h"

using namespace std;

void myReplace(string& str, const string& oldStr, const string& newStr)
{
   size_t pos = 0;
   while((pos = str.find(oldStr, pos)) != string::npos)
   {
      str.replace(pos, oldStr.length(), newStr);
      pos += newStr.length();
   }
}

void writeHeaderPage(ofstream& texFile, string leptonFlavor, string variable)
{
   if (leptonFlavor == "Muons" || leptonFlavor == "DMu") leptonFlavor = "DMu_";
   else if (leptonFlavor == "Electrons" || leptonFlavor == "DE") leptonFlavor = "DE_";

   string txtLeptonFlavor = leptonFlavor; myReplace(txtLeptonFlavor, "_", "\\_");
   string txtVariable = variable; myReplace(txtVariable, "_", "\\_");

   texFile << "\n";
   texFile << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
   texFile << "\\begin{frame}\n\n";
   texFile << "   \\begin{LARGE}\n";
   texFile << "      " << txtLeptonFlavor << txtVariable <<"\n";
   texFile << "   \\end{LARGE}\n";
   texFile << "\n\\end{frame}\n";
   texFile << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
   texFile << "\n";
}

void writeComparisonPage(ofstream& texFile, string leptonFlavor, string variable, string energy, int jetPtMin, bool doFlat, bool log, bool closureTest, bool doVarWidth)
{
   ostringstream JetPtMinStr;  JetPtMinStr << jetPtMin;
   string JetPtMin = JetPtMinStr.str();

   if (leptonFlavor == "Muons" || leptonFlavor == "DMu") leptonFlavor = "DMu_";
   else if (leptonFlavor == "Electrons" || leptonFlavor == "DE") leptonFlavor = "DE_";

   string txtLeptonFlavor = leptonFlavor; myReplace(txtLeptonFlavor, "_", "\\_");
   string txtVariable = variable; myReplace(txtVariable, "_", "\\_");
   string year = "2012";
   if (energy == "7TeV") year = "2011";
   string CT = "", scaleSmall = "0.18", scaleBig = "0.28";
   if (closureTest) {
      CT = "_CT";
      scaleSmall = "0.24";
      scaleBig = "0.4";
   }
   string varwidth = "";
   if (doVarWidth) varwidth = "_VarWidth";

   texFile << "\n";
   texFile << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
   texFile << "\\begin{frame}";
   texFile << "{Comparison of unfolding methods for " << txtLeptonFlavor << txtVariable;
   if (closureTest) texFile << " Closure Test"; 
   texFile <<"}\n\n";
   texFile << "   \\begin{columns}\n";
   texFile << "   \\column{0.25\\textwidth}\n";
   texFile << "   \\includegraphics[scale=" << scaleSmall << "]{../Analysis" << year << "/PNGFiles/FastPlots_" << JetPtMin << varwidth << "/";
   texFile <<     leptonFlavor << energy << "_" << variable << "_ResponseMatrix.png} \\\\ \n";
   texFile << "   \\includegraphics[scale=" << scaleSmall << "]{../Analysis" << year << "/PNGFiles/FastPlots_" << JetPtMin << varwidth << "/";
   texFile <<     leptonFlavor << energy << "_" << variable << "_SV.png} \\\\ \n";
   texFile << "   \\column{0.75\\textwidth}\n";
   texFile << "      \\begin{center}\n";
   texFile << "         \\includegraphics[scale=" << scaleBig << "]{../Analysis" << year << "/PNGFiles/FastPlots_" << JetPtMin << varwidth << "/";
   texFile <<           leptonFlavor << energy << "_" << variable << "_Unfolding_Comparison" << CT << ".png}\n";
   if (!closureTest){
      texFile << "         \\includegraphics[scale=" << scaleBig << "]{../Analysis" << year << "/PNGFiles/Comparison_";
      if (leptonFlavor == "DE_")  texFile << "Electrons_";
      if (leptonFlavor == "DMu_") texFile << "Muons_";
      texFile <<           energy + "_Data_All_MC_MadGraph_JetPtMin_" << JetPtMin;
      if (doFlat) texFile << "_Flat";
      texFile <<  varwidth << "/" << variable;
      if (!log) texFile << "_Lin";
      texFile <<           ".png}\n"; 
   }
   texFile << "      \\end{center}\n";
   texFile << "   \\end{columns}\n"; 
   texFile << "\n\\end{frame}\n";
   texFile << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
   texFile << "\n";
}

void writeMethodPage(ofstream& texFile, string leptonFlavor, string variable, string energy, int jetPtMin, string method, bool closureTest, bool doVarWidth)
{
   ostringstream JetPtMinStr;  JetPtMinStr << jetPtMin;
   string JetPtMin = JetPtMinStr.str();

   if (leptonFlavor == "Muons" || leptonFlavor == "DMu") leptonFlavor = "DMu_";
   else if (leptonFlavor == "Electrons" || leptonFlavor == "DE") leptonFlavor = "DE_";

   string txtLeptonFlavor = leptonFlavor; myReplace(txtLeptonFlavor, "_", "\\_");
   string txtVariable = variable; myReplace(txtVariable, "_", "\\_");
   string year = "2012";
   if (energy == "7TeV") year = "2011";
   string CT = "";
   if (closureTest) CT = "_CT";
   string varwidth = "";
   if (doVarWidth) varwidth = "_VarWidth";

   texFile << "\n";
   texFile << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
   texFile << "\\begin{frame}";
   texFile << "{Unfolding procedure for " << txtLeptonFlavor << txtVariable <<" (" << method << ")";
   if (closureTest) texFile << " Closure Test"; 
   texFile << "}\n\n";
   texFile << "   \\begin{columns}\n";
   texFile << "   \\column{0.3\\textwidth}\n";
   texFile << "   \\includegraphics[scale=0.24]{../Analysis" << year << "/PNGFiles/FastPlots_" << JetPtMin << varwidth << "/";
   texFile <<     leptonFlavor << energy << "_" << variable;
   if (method == "SVD")   texFile << "_D.png} \\\\ \n";
   if (method == "Bayes") texFile << "_Chi2.png} \\\\ \n";
   texFile << "   \\includegraphics[scale=0.24]{../Analysis" << year << "/PNGFiles/FastPlots_" << JetPtMin << varwidth << "/";
   texFile <<     leptonFlavor << energy << "_" << variable << "_Unfolded_Distributions_" << method << CT << ".png} \\\\ \n";
   texFile << "   \\column{0.7\\textwidth}\n";
   texFile << "      \\begin{center}\n";
   texFile << "         \\includegraphics[scale=0.4]{../Analysis" << year << "/PNGFiles/FastPlots_" << JetPtMin << varwidth << "/";
   texFile <<           leptonFlavor << energy << "_" << variable << "_Unfolded_Distribution_" << method << CT << ".png}\n";
   texFile << "      \\end{center}\n";
   texFile << "   \\end{columns}\n"; 
   texFile << "\n\\end{frame}\n";
   texFile << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
   texFile << "\n";

}

void writeSystematicsTexFile(string leptonFlavor, string energy, int jetPtMin, string variable, ofstream& texFile)
{
   ostringstream JetPtMinStr;  JetPtMinStr << jetPtMin;
   string JetPtMin = JetPtMinStr.str();

   if (leptonFlavor == "Muons" || leptonFlavor == "DMu") leptonFlavor = "DMu_";
   else if (leptonFlavor == "Electrons" || leptonFlavor == "DE") leptonFlavor = "DE_";

   string txtLeptonFlavor = leptonFlavor; myReplace(txtLeptonFlavor, "_", "\\_");
   string txtVariable = variable; myReplace(txtVariable, "_", "\\_");
   string year = "2012";
   if (energy == "7TeV") year = "2011";

   texFile << "\n";
   texFile << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
   texFile << "\\begin{frame}{Systematics for " << txtLeptonFlavor << txtVariable << "}\n\n";
   texFile << "\\begin{columns}\n";
   texFile << "\\column{0.33\\textwidth}\\centering\n";
   texFile << "   \\underline{Jet Energy Scale}\n";
   texFile << "\\column{0.34\\textwidth}\\centering\n";
   texFile << "   \\underline{Pile-Up Variation}\n";
   texFile << "\\column{0.33\\textwidth}\\centering\n";
   texFile << "   \\underline{Bkg. Cross Section}\n";
   texFile << "\\end{columns}\n";
   texFile << "\\vspace*{0.5cm}\n\n";

   texFile << "\\includegraphics[scale=0.25]{../Analysis" << year << "/PNGFiles/SystematicsPlots/";
   texFile << leptonFlavor << energy << "_" << variable << "_JEC.png}\n";
   texFile << "\\includegraphics[scale=0.25]{../Analysis" << year << "/PNGFiles/SystematicsPlots/";
   texFile << leptonFlavor << energy << "_" << variable << "_PU.png}\n";
   texFile << "\\includegraphics[scale=0.25]{../Analysis" << year << "/PNGFiles/SystematicsPlots/";
   texFile << leptonFlavor << energy << "_" << variable << "_XS.png}\n";
   texFile << "\n\\end{frame}\n";
   texFile << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
   texFile << "\n";
}

