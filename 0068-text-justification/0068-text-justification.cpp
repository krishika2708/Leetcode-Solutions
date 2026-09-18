// class Solution {
// public:
//     vector<string> fullJustify(vector<string>& words, int maxWidth) {
//         vector<string> ans;
//         int n = words.size();
//         int i = 0;
//         while (i < n) {
//             int j = i;
//             int totallength = 0;
//             while (j < n) {
//                 int newlen = totallength + words[j].size();
//                 if (j > i)
//                     newlen++;
//                 if (newlen > maxWidth)
//                     break;
//                 totallength += words[j].size();
//                 j++;
//             }
        
//         int numberofwords = j - i;
//         if (j == n || numberofwords == 1) {
//             string line = "";
//             for (int k = i; k < j; k++) {
//                 if (k > i)
//                     line += " ";
//                 line += words[k];
//             }
//             line += string(maxWidth -(int) line.size(), ' ');
//             ans.push_back(line);

//         } else {
//             int gaps = numberofwords - 1;
//             int extraspaces = maxWidth - totallength;
//              int spaceseach = extraspaces / gaps;
//             int extraone = extraspaces % gaps;
//             string line = "";
//             for (int k = i; k < j; k++) {
//                 line += words[k];
//                 if (k <j - 1) {
//                     int spaces = spaceseach;
//                     if (k - i < extraone)
//                         spaces++;
//                     line += string(spaces, ' ');
//                 }
//             }
//             ans.push_back(line);
//         }
//         i = j;
//     }
//     return ans;
// }
// }
// ;



class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            
            int j = i;
            int totalLength = 0;

            // Find words that can fit in this line
            while (j < n) {
                
                int wordLength = words[j].size();

                // If not the first word, we need 1 mandatory space
                int needed = totalLength + wordLength;

                if (j > i)
                    needed++;

                if (needed > maxWidth)
                    break;

                totalLength = needed;
                j++;
            }

            int wordCount = j - i;

            // LAST LINE
            if (j == n) {
                
                string line = "";

                for (int k = i; k < j; k++) {
                    
                    if (k > i)
                        line += " ";

                    line += words[k];
                }

                // Add remaining spaces at the end
                while (line.size() < maxWidth)
                    line += " ";

                ans.push_back(line);
            }

            // ONLY ONE WORD
            else if (wordCount == 1) {
                
                string line = words[i];

                while (line.size() < maxWidth)
                    line += " ";

                ans.push_back(line);
            }

            // NORMAL LINE
            else {
                
                // totalLength already contains minimum 1 space
                // between every pair of words
                int extraSpaces = maxWidth - totalLength;

                int gaps = wordCount - 1;

                int spacesEach = extraSpaces / gaps;
                int extra = extraSpaces % gaps;

                string line = "";

                for (int k = i; k < j; k++) {
                    
                    line += words[k];

                    if (k < j - 1) {
                        
                        // Minimum 1 space + extra spaces
                        int spaces = 1 + spacesEach;

                        // First 'extra' gaps get one more
                        if (k - i < extra)
                            spaces++;

                        for (int s = 0; s < spaces; s++)
                            line += " ";
                    }
                }

                ans.push_back(line);
            }

            i = j;
        }

        return ans;
    }
};