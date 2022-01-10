/* Program for Bad Character Heuristic of Boyer Moore String Matching Algorithm */
# include <limits.h>
# include <string.h>
# include <stdio.h>
# define NO_OF_CHARS 256
// A utility function to get maximum of two integers
int max(int a, int b)
{
return (a > b) ? a : b;
}
// The preprocessing function for Boyer Moore's bad character heuristic
void badCharHeuristic(char *str, int size, int badchar[NO_OF_CHARS])
{
int i;
// Initialize all occurrences as -1
for (i = 0; i < NO_OF_CHARS;
i++) badchar[i] = -1;
// Fill the actual value of last occurrence of a character
for (i = 0; i < size; i++)
badchar[(int) str[i]] = i;
}
void search(char *txt, char *pat)
{
int c=0;
int m = strlen(pat);
int n = strlen(txt);
int badchar[NO_OF_CHARS];
badCharHeuristic(pat, m, badchar);
int s = 0; // s is shift of the pattern with respect to text
while (s <= (n - m))
{
int j = m - 1;
while (j >= 0 && pat[j] == txt[s +
j]) j--;
if (j < 0)
{
c=1;
printf("\n pattern occurs at shift = %d", s);
s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
}
else
s += max(1, j - badchar[txt[s + j]]);
}
if(c==0)
printf("\nWord not found");
}
/* Driver program to test above funtion */
int main()
{
char pat[100];
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
printf("\nEnter the string to
find\n"); scanf("%s",&pat);
search(txt,
pat); return 0;
}