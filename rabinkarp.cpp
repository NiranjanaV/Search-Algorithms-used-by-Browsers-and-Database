#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define d 256
void search(char *pat, char *txt, int q)
{
int c=0;
int M = strlen(pat);
int N = strlen(txt);
int i, j;
int p = 0;
int t = 0;
int h = 1;
for (i = 0; i < M - 1;
i++) h = (h * d) % q;
for (i = 0; i < M; i++)
{
p = (d *p + pat[i]) % q;
t = (d * t + txt[i]) % q;
}
for (i = 0; i <= N - M; i++)
{
if (p == t)
{
for (j = 0; j < M; j++)
{
if (txt[i + j] !=
pat[j]) break;
}
if (j == M)
{
c=1;
cout<<"Word found at index: "<<i<<endl;
}
}
if (i < N - M)
{
t = (d * (t - txt[i] * h) + txt[i + M]) % q;
if (t < 0)
t = (t + q);
}
}
if(c==0)
cout<<"\nWord not found\n";
}
int main()
{
char txt[]="In molecular genetics, the three prime untranslated region (3'-UTR) is the section of
messenger RNA (mRNA) that immediately follows the translation termination codon. An mRNA
molecule is transcribed from the DNA sequence and is later translated into protein. Several regions of
the mRNA molecule are not translated into protein including the 5' cap, 5' untranslated region, 3'
untranslated region, and the poly(A) tail. The 3'-UTR often contains regulatory regions that posttranscriptionally
influence gene expression. mRNA structure, approximately to scale for a human
mRNA, where the median length of 3'UTR is 700 nucleotides Regulatory regions within the 3'-
untranslated region can influence polyadenylation, translation efficiency, localization, and stability of
the mRNA.[1][2] The 3'-UTR contains both binding sites for regulatory proteins as well as
microRNAs (miRNAs). By binding to specific sites within the 3'-UTR, miRNAs can decrease gene
expression of various mRNAs by either inhibiting translation or directly causing degradation of the
transcript. The 3'-UTR also has silencer regions which bind to repressor proteins and will inhibit the
expression of the mRNA. Many 3'-UTRs also contain AU-rich elements (AREs). Proteins bind AREs
to affect the stability or decay rate of transcripts in a localized manner or affect translation initiation.
Furthermore, the 3'-UTR contains the sequence AAUAAA that directs addition of several hundred
adenine residues called the poly(A) tail to the end of the mRNA transcript. Poly(A) binding protein
(PABP) binds to this tail, contributing to regulation of mRNA translation, stability, and export. For
example, poly (A) tail bound PABP interacts with proteins associated with the 5' end of the
transcript, causing a circularization of the mRNA that promotes translation. The 3'-UTR can also
contain sequences that attract proteins to associate the mRNA with the cytoskeleton, transport it to or
from the cell nucleus, or perform other types of localization. In addition to sequences within the 3'-
UTR, the physical characteristics of the region, including its length and secondary structure,
contribute to translation regulation. These diverse mechanisms of gene regulation ensure that the
correct genes are expressed in the correct cells at the appropriate times.";
char pat[100];
cout<<"\nEnter the word to search
for\n"; cin>>pat;
int q = 100000;
search(pat, txt,
q); return 0;
}