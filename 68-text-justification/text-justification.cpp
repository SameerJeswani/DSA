class Solution {
public:
    int MAX_WIDTH;
    string findline(int i, int j, int eachgaddhespace, int extraspacegaddhe, vector<string>& words){
        string line;
        for(int k=i; k<j; k++){
            line += words[k];

            if(k==j-1){
                continue;
            }
            for(int z=1; z<=eachgaddhespace; z++){
                line += " ";
            }

            if(extraspacegaddhe>0){
                line += " ";
                extraspacegaddhe--;
            }
        }

        while(line.length() < MAX_WIDTH){
            line += " ";
        }
        return line;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();

        MAX_WIDTH = maxWidth;

        int i=0;
        while(i<n){
            int lettercount = words[i].length();
            int j=i+1;
            int gaddhe = 0;

            while(j<n && words[j].length() +1 +gaddhe +lettercount <= maxWidth){
                lettercount += words[j].length();
                gaddhe += 1;
                j++;
            }

            int remaininggaddhe = maxWidth-lettercount;
            int eachgaddhespace = gaddhe ==0 ? 0 : remaininggaddhe/gaddhe;
            int extraspacegaddhe = gaddhe ==0 ? 0 : remaininggaddhe%gaddhe;

            if(j==n){
                eachgaddhespace=1;
                extraspacegaddhe=0;
            }

            result.push_back(findline(i,j,eachgaddhespace, extraspacegaddhe, words));
            i=j;
        }
        return result;
    }
};