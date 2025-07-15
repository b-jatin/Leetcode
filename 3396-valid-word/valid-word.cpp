class Solution {
public:
    bool isValid(string word) {
        int len=word.length();
        if(len<3)
        return false;
        bool vowel=false;
        bool consonant=false;
        for(int i=0;i<len;i++){
        if(!isalnum(word[i]))
        return false;
        char ch= (char)tolower(word[i]);
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            vowel=true;
        else if(ch-'a'<26 && ch-'a'>=0)
            consonant=true;
        }

        return vowel && consonant;
    }
};